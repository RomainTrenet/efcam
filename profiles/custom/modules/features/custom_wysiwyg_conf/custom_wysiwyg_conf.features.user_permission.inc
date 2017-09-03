<?php
/**
 * @file
 * custom_wysiwyg_conf.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function custom_wysiwyg_conf_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer imce'.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(),
    'module' => 'imce',
  );

  // Exported permission: 'use media wysiwyg'.
  $permissions['use media wysiwyg'] = array(
    'name' => 'use media wysiwyg',
    'roles' => array(),
    'module' => 'media_wysiwyg',
  );

  return $permissions;
}
