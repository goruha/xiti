<?php

function xiti_settings_form($form) {
  $form['xiti_xtsd'] = array(
    '#type' => 'textfield',
    '#title' => t('Statistics server'),
    '#maxlength' => 255,
    '#default_value' => variable_get('xiti_xtsd', ''),
    '#required' => TRUE,
    '#description' => t('Enter the statistic server URL. For example : http://logp')
  );

  $form['xiti_xtsite'] = array(
    '#type' => 'textfield',
    '#title' => t('Site ID'),
    '#maxlength' => 255,
    '#default_value' => variable_get('xiti_xtsite', ''),
    '#required' => TRUE,
    '#description' => t('Enter the XiTi site ID')
  );

  $form['xiti_js_script'] = array(
    '#type' => 'textfield',
    '#title' => t('XiTi JS Engine'),
    '#maxlength' => 255,
    '#default_value' => variable_get('xiti_js_script', ''),
    '#required' => TRUE,
    '#description' => t('Enter the XiTi javascript file URL: For example : path to xtcore.js)')
  );

  $form['xiti_noscr_image'] = array(
    '#type' => 'textfield',
    '#title' => t('NOSCRIPT image'),
    '#maxlength' => 255,
    '#default_value' => variable_get('xiti_noscr_image', ''),
    '#required' => TRUE,
    '#description' => t('Enter the 1x1 px image URL for noscript tagging. For example : http://logp.xiti.com/hit.xiti')
  );

  $form['xiti_default'] = array(
    '#type' => 'fieldset',
    '#title' => t('Default'),
  	'#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['xiti_default']['xiti_tagging_plan'] = array(
    '#type' => 'checkbox',
    '#title' => t('Generate xiti tags in all pages'),
    '#default_value' => variable_get('xiti_tagging_plan', 0),
    '#description' => t('Check this if you want to insert default XiTi tags for undefined  pages (not defined in "list" tab')
  );

  $form['xiti_default']['xiti_default_xtn2'] = array(
    '#type' => 'textfield',
    '#title' => t('Default xtn2'),
    '#maxlength' => 10,
    '#default_value' => variable_get('xiti_default_xtn2', ''),
    '#description' => t('Xiti xtn2 default tag value')
  );

  $form['xiti_default']['xiti_default_xtdi'] = array(
    '#type' => 'select',
    '#title' => t('Default xtdi'),
    '#default_value' => variable_get('xiti_default_xtdi', 0),
    '#options' => range(0, 5),
    '#description' => t('Xiti xtdi default tag value')
  );

  drupal_add_js(drupal_get_path('module', 'xiti') . '/xiti.js');

  return system_settings_form($form);
}
