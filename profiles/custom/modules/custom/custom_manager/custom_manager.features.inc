<?php
/**
 * @file
 * custom_manager.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function custom_manager_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
