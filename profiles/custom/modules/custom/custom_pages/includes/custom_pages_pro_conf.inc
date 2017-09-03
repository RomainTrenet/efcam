<?php

/**
 * TODO COmment
 * Get header conf, to auto generate header at installation
 * @return configuration array
 */
function _custom_pages_pro_page_get_highlight_conf() {
	$conf = array(
		'module_name' => 'custom_pages',
		'context' => 'pro_page_highlight_section',
	);
	return $conf;
}

/**
 * TODO COmment
 * Get header conf, to auto generate header at installation
 * @return configuration array
 */
function _custom_pages_pro_page_get_above_header_conf() {
	$conf = array(
		'module_name' => 'custom_pages',
		'context' => 'pro_page_above_header',
	);
	return $conf;
}

/**
 * TODO COmment and correct 'get' name
 * Get header conf, to auto generate header at installation
 * @return configuration array
 */


function _custom_pages_pro_page_get_first_section_conf() {
	$conf = array(
		'module_name' => 'custom_pages',
		'context' => 'pro_page_first_section',
	);
	return $conf;
}
/**
 *
 */
function _custom_pages_pro_page_get_first_section_image_conf() {
	return array(
		'module_name' => 'custom_pages',
		'context' => 'pro_page_first_section',
		'image' => array(
			'var_name' => 'image',
			'source_folder' => 'images',
			'file_name' => 'pro_first_section_picture.jpg',
			'alt' => 'Contenu de la formation',
			'title' => 'Contenu de la formation',
			'destitation_folder' => 'pages',
		),
	);
}

function _custom_pages_pro_page_get_second_section_conf() {
	$conf = array(
		'module_name' => 'custom_pages',
		'context' => 'pro_page_second_section',
	);
	return $conf;
}
function _custom_pages_pro_page_get_second_section_first_image_conf() {
	return array(
		'module_name' => 'custom_pages',
		'context' => 'pro_page_second_section',
		'image' => array(
			'var_name' => 'first_image',
			'source_folder' => 'images',
			'file_name' => 'pro_second_section_first_picture.jpg',
			'alt' => 'Le déroulé de la formation théorie et pratique',
			'title' => 'Le déroulé de la formation théorie et pratique',
			'destitation_folder' => 'pages',
		),
	);
}function _custom_pages_pro_page_get_second_section_second_image_conf() {
	return array(
		'module_name' => 'custom_pages',
		'context' => 'pro_page_second_section',
		'image' => array(
			'var_name' => 'second_image',
			'source_folder' => 'images',
			'file_name' => 'pro_second_section_second_picture.jpg',
			'alt' => 'Le déroulé de la formation théorie et pratique',
			'title' => 'Le déroulé de la formation théorie et pratique',
			'destitation_folder' => 'pages',
		),
	);
}

function _custom_pages_pro_page_get_third_section_conf() {
	$conf = array(
		'module_name' => 'custom_pages',
		'context' => 'pro_page_third_section',
	);
	return $conf;
}
function _custom_pages_pro_page_get_third_section_image_conf() {
	return array(
		'module_name' => 'custom_pages',
		'context' => 'pro_page_third_section',
		'image' => array(
			'var_name' => 'image',
			'source_folder' => 'images',
			'file_name' => 'pro_third_section_picture.jpg',
			'alt' => 'Programme de la formation',
			'title' => 'Programme de la formation',
			'destitation_folder' => 'pages',
		),
	);
}

function _custom_pages_pro_page_get_fourth_section_conf() {
	$conf = array(
		'module_name' => 'custom_pages',
		'context' => 'pro_page_fourth_section',
	);
	return $conf;
}