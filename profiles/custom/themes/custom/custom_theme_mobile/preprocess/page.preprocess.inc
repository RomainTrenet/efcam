<?php

/**
 * Implements hook_preprocess_page().
 */
function custom_theme_mobile_preprocess_page(&$vars) {
	
	// You can use preprocess hooks to modify the variables before they are passed
	// to the theme function or template file.
	
	$global_theme_path = drupal_get_path('theme', 'custom_theme_global');
	$current_path = current_path();
	
	drupal_add_css($global_theme_path . '/css/components/layout_mobile.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => custom_theme_global_is_develop_mode(),
		'weight' => 0,
	));
	drupal_add_css($global_theme_path . '/css/global_mobile.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => TRUE,//Always cache
		'weight' => 0,
	));
	drupal_add_css($global_theme_path . '/css/components/form_element_mobile.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => custom_theme_global_is_develop_mode(),
		'weight' => 0,
	));
	drupal_add_css($global_theme_path . '/css/components/header_mobile.css', array(
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
			drupal_add_css($global_theme_path . '/css/pages/pro_mobile.css', array(
				'type' => 'file',
				'group' => CSS_THEME,
				'preprocess' => custom_theme_global_is_develop_mode(),
				'weight' => 10,
			));
			break;
		case 'patient' :
			drupal_add_css($global_theme_path . '/css/pages/patient_mobile.css', array(
				'type' => 'file',
				'group' => CSS_THEME,
				'preprocess' => custom_theme_global_is_develop_mode(),
				'weight' => 10,
			));
			break;
	}
	
}