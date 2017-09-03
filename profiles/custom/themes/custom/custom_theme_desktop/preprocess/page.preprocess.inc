<?php

/**
 * Implements hook_preprocess_page().
 */
function custom_theme_desktop_preprocess_page(&$variables) {
	
  // You can use preprocess hooks to modify the variables before they are passed
  // to the theme function or template file.
	
	$global_theme_path = drupal_get_path('theme', 'custom_theme_global');
	$current_path = current_path();
	
	drupal_add_css($global_theme_path . '/css/components/layout_desktop.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => custom_theme_global_is_develop_mode(),
		'weight' => 0,
	));
	drupal_add_css($global_theme_path . '/css/global_desktop.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => TRUE,//Always cache
		'weight' => 0,
	));
	drupal_add_css($global_theme_path . '/css/components/form_element_desktop.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => custom_theme_global_is_develop_mode(),
		'weight' => 0,
	));
	drupal_add_css($global_theme_path . '/css/components/header_desktop.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => custom_theme_global_is_develop_mode(),
		'weight' => 0,
	));
	/*
	drupal_add_css($global_theme_path . '/css/as_global.css.less', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => TRUE,//Always cache
		'weight' => 0,
	));
	drupal_add_css($global_theme_path . '/css/global.styles.css.less', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => apistore_is_develop_mode(),
		'weight' => 0,
	));*/
	
	switch ($current_path) {
		case 'pro' :
			drupal_add_css($global_theme_path . '/css/pages/pro_desktop.css', array(
				'type' => 'file',
				'group' => CSS_THEME,
				'preprocess' => custom_theme_global_is_develop_mode(),
				'weight' => 10,
			));
			break;
		case 'patient' :
			drupal_add_css($global_theme_path . '/css/pages/patient_desktop.css', array(
				'type' => 'file',
				'group' => CSS_THEME,
				'preprocess' => custom_theme_global_is_develop_mode(),
				'weight' => 10,
			));
			break;
	}
	
	if (drupal_match_path($current_path, 'node/*/day') || drupal_match_path($current_path, 'node/*/week') || drupal_match_path($current_path, 'node/*/month') || drupal_match_path($current_path, 'node/*/year')){
		drupal_add_css($global_theme_path . '/css/components/ef_booking_timeslots.css', array(
			'type' => 'file',
			'group' => CSS_THEME,
			'preprocess' => custom_theme_global_is_develop_mode(),
			'every_page' => FALSE,
			'weight' => 10,
		));
	}
	
}