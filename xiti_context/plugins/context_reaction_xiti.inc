<?php
/**
 * Expose themes as context reactions.
 */
class contextReactionXiti extends context_reaction {

  function options_form($context) {
    $xiti = $this->fetch_from_context($context);
    if (empty($xiti)) {
      $xiti = array(
        'xiti_xtpage' => '',
        'xiti_xtn2' => '',
        'xiti_xtdi' => '',
      );
    }
    $form['xiti_xtpage'] = array(
      '#type' => 'textfield',
      '#title' => t('xtpage'),
      '#maxlength' => 255,
      '#default_value' => $xiti['xiti_xtpage'],
      '#description' => t('Xiti xtpage tag value'),
    );

    $form['xiti_xtn2'] = array(
      '#type' => 'textfield',
      '#title' => t('xtn2'),
      '#maxlength' => 10,
      '#default_value' => $xiti['xiti_xtn2'],
      '#description' => t('Xiti xtn2 tag value'),
    );

    $form['xiti_xtdi'] = array(
      '#type' => 'select',
      '#title' => t('xtdi'),
      '#default_value' => $xiti['xiti_xtdi'],
      '#options' => array('' => '') + range(0, 5),
      '#description' => t('Xiti xtdi tag value'),
    );

    $form['token'] = array(
      '#type' => 'fieldset',
      '#title' => t('Token browser'),
      '#weight' => 10,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['token']['browser'] = array(
      '#theme' => 'token_tree',
      '#token_types' => 'all',
      '#weight' => 10,
    );

    return $form;
  }

  function execute(&$page) {
    $contexts = $this->get_contexts();
    $xiti = xiti_get_default();
    $args = array();
    foreach ($contexts as $context) {
      $context_xiti = $this->fetch_from_context($context);
      $context_xiti = array_filter($context_xiti);
      $xiti = array_merge($xiti, $context_xiti);
      $args = array_merge($context->arguments, $args);
    }
    $xiti = array_filter($xiti);
    foreach ($xiti as &$value) {
      $value = token_replace($value, $args);
    }
    if (!empty($xiti)) {
      $page['page_bottom']['xiti'] = array(
        '#type' => 'markup',
        '#markup' => xiti_generate_snippet($xiti),
      );
    }
  }

  /**
   * Retrieve active contexts that have values for this reaction.
   */
  function get_contexts() {
    $contexts = array();
    foreach (context_weight_context_active_contexts_by_weight() as $context) {
      if ($this->fetch_from_context($context)) {
        $contexts[$context->name] = $context;
      }
    }
    return $contexts;
  }
}
