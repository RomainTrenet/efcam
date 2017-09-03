<?php

/**
 * Implements hook_preprocess_page().
 */
function custom_theme_global_preprocess_page(&$vars) {
	
  // You can use preprocess hooks to modify the variables before they are passed
  // to the theme function or template file.
	
	$global_theme_path = drupal_get_path('theme', 'custom_theme_global');
	$current_path = current_path();
	
	//Reset, libraries, fonts
	drupal_add_css($global_theme_path . '/css/reset.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => TRUE,//Always cache
		'weight' => 0,
	));
	drupal_add_css($global_theme_path . '/css/components/grid.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => TRUE,//Always cache
		'weight' => 0,
	));
	drupal_add_css($global_theme_path . '/fonts/roboto-slab-fontface-bower-master/roboto-slab-fontface.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => TRUE,//Always cache
		'weight' => 0,
	));
	drupal_add_css($global_theme_path . '/fonts/fontello/css/fontello.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => TRUE,//Always cache
		'weight' => 0,
	));
	drupal_add_css($global_theme_path . '/fonts/fontello/css/animation.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => TRUE,//Always cache
		'weight' => 0,
	));
	drupal_add_css($global_theme_path . '/css/abstractions/helpers.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => custom_theme_global_is_develop_mode(),
		'weight' => 0,
	));
	
	//CSS global files for mobile and desktop
	drupal_add_css($global_theme_path . '/css/components/layout_global.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => custom_theme_global_is_develop_mode(),
		'weight' => 0,
	));
	drupal_add_css($global_theme_path . '/css/global_global.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => TRUE,//Always cache
		'weight' => 0,
	));
	drupal_add_css($global_theme_path . '/css/components/form_element_global.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => custom_theme_global_is_develop_mode(),
		'weight' => 0,
	));
	drupal_add_css($global_theme_path . '/css/components/header_global.css', array(
		'type' => 'file',
		'group' => CSS_THEME,
		'preprocess' => custom_theme_global_is_develop_mode(),
		'weight' => 0,
	));
	
	/**
	 * Js for all page
	 */
	drupal_add_js($global_theme_path . '/libraries/jquery.sticky-kit/jquery.sticky-kit.min.js', array(
		'type' => 'file',
		'group' => JS_LIBRARY,
		'scope' => 'footer',
		'cache' => TRUE,
		'weight' => 0,
	));
	/*
	drupal_add_js(libraries_get_path('sticky') . '/jquery.sticky.js',
	array('type' => 'file', 'scope' => 'footer', 'weight' => 0)
	);
	drupal_add_js($global_theme_path . '/scripts/as_global.js',
	array('type' => 'file', 'scope' => 'footer', 'weight' => 1)
	);
	
	if (drupal_is_front_page()) {
	drupal_add_css($global_theme_path . '/css/pages/home_desktop.css', array(
	'type' => 'file',
	'group' => CSS_THEME,
	'preprocess' => custom_theme_global_is_develop_mode(),
	'every_page' => FALSE,
	'weight' => 10,
	));
	}
	 */
	
	switch ($current_path) {
		case 'pro' :
			drupal_add_css($global_theme_path . '/css/pages/pro_global.css', array(
				'type' => 'file',
				'group' => CSS_THEME,
				'preprocess' => custom_theme_global_is_develop_mode(),
				'weight' => 10,
			));
			break;
		case 'patient' :
			drupal_add_css($global_theme_path . '/css/pages/patient_global.css', array(
				'type' => 'file',
				'group' => CSS_THEME,
				'preprocess' => custom_theme_global_is_develop_mode(),
				'weight' => 10,
			));
			break;
	}
	
}
