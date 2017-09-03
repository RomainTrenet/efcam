<?php
/**
 * @file
 * custom_system_conf.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function custom_system_conf_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
