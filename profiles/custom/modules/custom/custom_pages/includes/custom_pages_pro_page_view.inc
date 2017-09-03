<?php

/**
 * Pro page view
 */
function _custom_pages_pro_page_view() {
	
	/*node_delete(variable_get('ec_contact_webform_id'));
	
	// AS user create default webform.
	module_load_include('inc', 'custom_pages', 'includes/custom_pages_default_contact_webform');
	custom_pages_create_contact_webform();*/
		
	//Section highlight
	$section_highlight_vars_name = array('title', 'body', 'link_title');
	$var_name_prefix = 'custom_pages_pro_page_highlight_section_';
	$section_highlight = [];
	foreach ($section_highlight_vars_name as $key => $var_name) {
		$section_highlight[$var_name] =  variable_get($var_name_prefix . $var_name);
	}
	
	//First section
	$first_section_vars_name = array('title', 'body', 'link_title');
	$var_name_prefix = 'custom_pages_pro_page_first_section_';
	$first_section = [];
	foreach ($first_section_vars_name as $key => $var_name) {
		$first_section[$var_name] =  variable_get($var_name_prefix . $var_name);
	}
	//Image
	$fid = variable_get('custom_pages_pro_page_first_section_image');
	if (!empty($fid)) {
		$first_section['image'] = file_load($fid);
	}
	
	//Second section
	$second_section_vars_name = array('image', 'title', 'body', 'link_title');
	$var_name_prefix = 'custom_pages_pro_page_second_section_';
	$second_section = [];
	foreach ($second_section_vars_name as $key => $var_name) {
		$second_section[$var_name] =  variable_get($var_name_prefix . $var_name);
	}
	$fid = variable_get('custom_pages_pro_page_second_section_first_image');
	if (!empty($fid)) {
		$second_section['first_image'] = file_load($fid);
	}
	$fid = variable_get('custom_pages_pro_page_second_section_second_image');
	if (!empty($fid)) {
		$second_section['second_image'] = file_load($fid);
	}
	
	
	//third section
	$third_section_vars_name = array('image', 'title', 'body', 'link_title');
	$var_name_prefix = 'custom_pages_pro_page_third_section_';
	$third_section = [];
	foreach ($third_section_vars_name as $key => $var_name) {
		$third_section[$var_name] =  variable_get($var_name_prefix . $var_name);
	}
	//Image
	$fid = variable_get('custom_pages_pro_page_third_section_image');
	if (!empty($fid)) {
		$third_section['image'] = file_load($fid);
	}
	
	//fourth section
	$fourth_section_vars_name = array('title', 'body');
	$var_name_prefix = 'custom_pages_pro_page_fourth_section_';
	$fourth_section = [];
	foreach ($fourth_section_vars_name as $key => $var_name) {
		$fourth_section[$var_name] =  variable_get($var_name_prefix . $var_name);
	}
	
	$content = [
		'section_highlight' => $section_highlight,
		'first_section' => $first_section,
		'second_section' => $second_section,
		'third_section' => $third_section,
		'fourth_section' => $fourth_section
	];
	
	// Webform.
	$webform_node = node_load(variable_get('ec_contact_webform_id'));
	if (!empty($webform_node)) {
		$webform_node->title = NULL;
		$webform_node_view = node_view($webform_node);
		$content['webform'] = drupal_render($webform_node_view);
	}
	
	return theme('custom_pages_pro_page_theme', $content);
}