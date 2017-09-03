<?php
/**
 * @file
 * custom_media_conf.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function custom_media_conf_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(),
    'module' => 'media',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(),
    'module' => 'media',
  );

  return $permissions;
}
