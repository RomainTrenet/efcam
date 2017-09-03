<?php

/**
 * Get main header conf, to auto generate header at installation
 * @return configuration array
 */
function _custom_pages_default_page_get_header_conf() {
	$conf = array(
		'module_name' => 'custom_pages',
		'context' => 'default_page',
		'image' => array(
			'var_name' => 'main_content_header_image',
			'source_folder' => 'images',
			'file_name' => 'default_header.jpg',
			'alt' => t('EFCAM'),
			'title' => t('EFCAM'),
			'destitation_folder' => 'banners',
		),
	);
	return $conf;
}

/**
 * Get header conf, to auto generate header at installation
 * @return configuration array
 */
function _custom_pages_pro_page_get_header_conf()
{
	$conf = array(
		'module_name' => 'custom_pages',
		'context' => 'pro_page',
		'image' => array(
			'var_name' => 'main_content_header_image',
			'source_folder' => 'images',
			'file_name' => 'pro_default_header.jpg',
			'alt' => t('Getting started'),
			'title' => t('Getting started'),
			'destitation_folder' => 'banners',
		),
		'content' => NULL,
	);
	return $conf;
}

/**
 * Get header conf, to auto generate header at installation
 * @return configuration array
 */
function _custom_pages_patient_page_get_header_conf() {
	$conf = array(
		'module_name' => 'custom_pages',
		'context' => 'patient_page',
		'image' => array(
			'var_name' => 'main_content_header_image',
			'source_folder' => 'images',
			'file_name' => 'patient_default_header.jpg',
			'alt' => t('Patient'),
			'title' => t('Patient'),
			'destitation_folder' => 'banners',
		),
		'content' => NULL,
	);
	return $conf;
}