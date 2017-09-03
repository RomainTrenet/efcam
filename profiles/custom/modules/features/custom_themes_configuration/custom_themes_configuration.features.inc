<?php
/**
 * @file
 * custom_themes_configuration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function custom_themes_configuration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function custom_themes_configuration_image_default_styles() {
  $styles = array();

  // Exported image style: compress.
  $styles['compress'] = array(
    'label' => 'compress',
    'effects' => array(),
  );

  return $styles;
}
