<?php
/**
 * @file
 * custom_media_conf.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function custom_media_conf_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media_icon_base_directory';
  $strongarm->value = 'public://media-icons';
  $export['media_icon_base_directory'] = $strongarm;

  return $export;
}
