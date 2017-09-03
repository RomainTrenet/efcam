<?php
/**
 * @file
 * custom_themes_configuration.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function custom_themes_configuration_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(),
    'module' => 'system',
  );

  return $permissions;
}
