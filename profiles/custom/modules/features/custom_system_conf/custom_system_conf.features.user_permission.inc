<?php
/**
 * @file
 * custom_system_conf.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function custom_system_conf_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer browscap'.
  $permissions['administer browscap'] = array(
    'name' => 'administer browscap',
    'roles' => array(),
    'module' => 'browscap',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(),
    'module' => 'locale',
  );

  return $permissions;
}
