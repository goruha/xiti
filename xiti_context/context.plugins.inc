<?php

/**
 * Context registry.
 */
function _xiti_context_context_registry() {
  $registry = array();
  $registry['reactions'] = array(
    'xiti' => array(
      'title' => t('Xiti'),
      'description' => t('Add xiti code on page.'),
      'plugin' => 'context_reaction_xiti',
    ),
  );
  return $registry;
}

/**
 * Context plugins.
 */
function _xiti_context_context_plugins() {
  $plugins = array();

  $plugins['context_reaction_xiti'] = array(
    'handler' => array(
      'path' => drupal_get_path('module', 'xiti_context') . '/plugins',
      'file' => 'context_reaction_xiti.inc',
      'class' => 'contextReactionXiti',
      'parent' => 'context_reaction',
    ),
  );
  return $plugins;
}

