<?php
/**
 * @file
 * custom_features_conf.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function custom_features_conf_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: management.
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => 'Le menu <em>Gestion</em> contient les liens des tâches administratives',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Le menu <em>Gestion</em> contient les liens des tâches administratives');
  t('Management');

  return $menus;
}
