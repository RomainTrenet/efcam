<?php

/**
 * TODO COmment
 * Get header conf, to auto generate header at installation
 * @return configuration array
 */
function _custom_pages_patient_page_get_highlight_conf() {
	$conf = array(
		'module_name' => 'custom_pages',
		'context' => 'patient_page_highlight_section',
	);
	return $conf;
}

/**
 * TODO COmment
 * Get header conf, to auto generate header at installation
 * @return configuration array
 */
function _custom_pages_patient_page_get_above_header_conf() {
	$conf = array(
		'module_name' => 'custom_pages',
		'context' => 'patient_page_above_header',
	);
	return $conf;
}

/**
 * TODO COmment and correct 'get' name
 * Get header conf, to auto generate header at installation
 * @return configuration array
 */


function _custom_pages_patient_page_get_first_section_conf() {
	$conf = array(
		'module_name' => 'custom_pages',
		'context' => 'patient_page_first_section',
	);
	return $conf;
}
/**
 *
 */
function _custom_pages_patient_page_get_first_section_image_conf() {
	return array(
		'module_name' => 'custom_pages',
		'context' => 'patient_page_first_section',
		'image' => array(
			'var_name' => 'image',
			'source_folder' => 'images',
			'file_name' => 'patient_first_section_picture.jpg',
			'alt' => 'Les thérapies traditionnelles manuelles',
			'title' => 'Les thérapies traditionnelles manuelles',
			'destitation_folder' => 'pages',
		),
	);
}
function _custom_pages_patient_page_get_second_section_conf() {
	$conf = array(
		'module_name' => 'custom_pages',
		'context' => 'patient_page_second_section',
	);
	return $conf;
}
function _custom_pages_patient_page_get_second_section_image_conf() {
	return array(
		'module_name' => 'custom_pages',
		'context' => 'patient_page_second_section',
		'image' => array(
			'var_name' => 'image',
			'source_folder' => 'images',
			'file_name' => 'patient_second_section_first_picture.jpg',
			'alt' => 'Le déroulé d’une séance',
			'title' => 'Le déroulé d’une séance',
			'destitation_folder' => 'pages',
		),
	);
}
function _custom_pages_patient_page_get_third_section_conf() {
	$conf = array(
		'module_name' => 'custom_pages',
		'context' => 'patient_page_third_section',
	);
	return $conf;
}
function _custom_pages_patient_page_get_third_section_first_image_conf() {
	return array(
		'module_name' => 'custom_pages',
		'context' => 'patient_page_third_section',
		'image' => array(
			'var_name' => 'first_image',
			'source_folder' => 'images',
			'file_name' => 'patient_third_section_first_picture.jpg',
			'alt' => 'Le groupe de thérapeutes',
			'title' => 'Le groupe de thérapeutes',
			'destitation_folder' => 'pages',
		),
	);
}
function _custom_pages_patient_page_get_third_section_second_image_conf() {
	return array(
		'module_name' => 'custom_pages',
		'context' => 'patient_page_third_section',
		'image' => array(
			'var_name' => 'second_image',
			'source_folder' => 'images',
			'file_name' => 'patient_third_section_second_picture.jpg',
			'alt' => 'Le groupe de thérapeutes',
			'title' => 'Le groupe de thérapeutes',
			'destitation_folder' => 'pages',
		),
	);
}

function _custom_pages_patient_page_get_fourth_section_conf() {
	$conf = array(
		'module_name' => 'custom_pages',
		'context' => 'patient_page_fourth_section',
	);
	return $conf;
}