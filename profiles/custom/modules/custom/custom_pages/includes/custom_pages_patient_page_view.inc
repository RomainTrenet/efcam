<?php

/**
 * Patient page view
 */
function _custom_pages_patient_page_view() {
	
	//Section highlight
	$section_highlight_vars_name = array('title', 'body', 'link_title');
	$var_name_prefix = 'custom_pages_patient_page_highlight_section_';
	$section_highlight = [];
	foreach ($section_highlight_vars_name as $key => $var_name) {
		$section_highlight[$var_name] =  variable_get($var_name_prefix . $var_name);
	}
	
	//First section
	$first_section_vars_name = array('title', 'body', 'link_title');
	$var_name_prefix = 'custom_pages_patient_page_first_section_';
	$first_section = [];
	foreach ($first_section_vars_name as $key => $var_name) {
		$first_section[$var_name] =  variable_get($var_name_prefix . $var_name);
	}
	//Image
	$fid = variable_get('custom_pages_patient_page_first_section_image');
	if (!empty($fid)) {
		$first_section['image'] = file_load($fid);
	}
	
	//Second section
	$second_section_vars_name = array('image', 'title', 'body', 'link_title');
	$var_name_prefix = 'custom_pages_patient_page_second_section_';
	$second_section = [];
	foreach ($second_section_vars_name as $key => $var_name) {
		$second_section[$var_name] =  variable_get($var_name_prefix . $var_name);
	}
	//Image
	$fid = variable_get('custom_pages_patient_page_second_section_image');
	if (!empty($fid)) {
		$second_section['image'] = file_load($fid);
	}
	
	//third section
	$third_section_vars_name = array('image', 'title', 'body', 'link_title');
	$var_name_prefix = 'custom_pages_patient_page_third_section_';
	$third_section = [];
	foreach ($third_section_vars_name as $key => $var_name) {
		$third_section[$var_name] =  variable_get($var_name_prefix . $var_name);
	}
	//Image
	$fid = variable_get('custom_pages_patient_page_third_section_first_image');
	if (!empty($fid)) {
		$third_section['first_image'] = file_load($fid);
	}
	$fid = variable_get('custom_pages_patient_page_third_section_second_image');
	if (!empty($fid)) {
		$third_section['second_image'] = file_load($fid);
	}
	
	//fourth section
	$fourth_section_vars_name = array('title', 'body');
	$var_name_prefix = 'custom_pages_patient_page_fourth_section_';
	$fourth_section = [];
	foreach ($fourth_section_vars_name as $key => $var_name) {
		$fourth_section[$var_name] =  variable_get($var_name_prefix . $var_name);
	}
	
	// Address & phone.
	$address = variable_get('efcam_settings_address');
	$phone = variable_get('efcam_settings_contact_phone');
	
	$content = array(
		'section_highlight' => $section_highlight,
		'first_section' => $first_section,
		'second_section' => $second_section,
		'third_section' => $third_section,
		'fourth_section' => $fourth_section,
		'thoroughfare' => $address['thoroughfare'],
		'postal_code' => $address['postal_code'],
		'locality' =>  $address['locality'],
		'country' =>  $address['country'],
		'phone' => $phone,
	);
	if(!empty($address['premise'])) {
		$content['premise'] = $address['premise'];
	}
	
	//Return theme with vars
	return theme('custom_pages_patient_page_theme', $content);
}