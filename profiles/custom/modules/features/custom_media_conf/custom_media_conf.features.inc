<?php
/**
 * @file
 * custom_media_conf.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function custom_media_conf_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
