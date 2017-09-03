<?php
/**
 * @file as_homepage.admin.inc
 * Module to manage display on homepage.
 */


/**
 * Page homepage admin view.
 */
function _custom_pages_patient_page_admin_view() {
	
	// Get confs.
	module_load_include('inc', 'custom_pages', 'includes/custom_pages_patient_conf');
	$above_header_conf = _custom_pages_patient_page_get_above_header_conf();
	$highlight_conf = _custom_pages_patient_page_get_highlight_conf();
	$first_section_conf = _custom_pages_patient_page_get_first_section_conf();
	$second_section_conf = _custom_pages_patient_page_get_second_section_conf();
	$third_section_conf = _custom_pages_patient_page_get_third_section_conf();
	$fourth_section_conf = _custom_pages_patient_page_get_fourth_section_conf();
	
	//Above header
	module_load_include('inc', 'custom_base', 'custom_base.admin');
	$above_header_form = drupal_get_form('custom_base_generic_title_subtitle_form', $above_header_conf);
	$above_header_form['section']['#title'] = t('Abode header disc');
	
	//Highlight section
	module_load_include('inc', 'custom_base', 'custom_base.admin');
	$highlight_form = drupal_get_form('custom_base_generic_section_title_body_link_form', $highlight_conf);
	$highlight_form['section']['#title'] = t('Highlight section');
	
	//First section
	//module_load_include('inc', 'custom_base', 'custom_base.admin');
	$first_section = $first_section_conf['module_name'] . '_' .$first_section_conf['context'];
	$original_fom_id = 'custom_base_generic_section_image_title_body_link_form';
	$first_section_form = drupal_get_form($original_fom_id, $first_section_conf);
	//$first_section_form = drupal_get_form($original_fom_id . '_' . $first_section, $original_fom_id, $first_section_conf);
	$first_section_form['section']['#title'] = t('First section');
	
	//Second section
	$second_section_form = drupal_get_form('custom_base_generic_section_image_title_body_link_form', $second_section_conf);
	$second_section_form['section']['#title'] = t('Second section');
	
	//Third section
	$third_section_form = drupal_get_form('custom_base_generic_section_double_image_title_body_form', $third_section_conf);
	$third_section_form['section']['#title'] = t('Third section');
	
	//Fourth section
	$fourth_section_form = drupal_get_form('custom_base_generic_section_title_body_form', $fourth_section_conf);
	$fourth_section_form['section']['#title'] = t('Fourth section');
	
	return render($above_header_form) . render($highlight_form) . render($first_section_form) . render($second_section_form) . render($third_section_form) . render($fourth_section_form);
}

/**
 * Page homepage admin view.
 */
function _custom_pages_pro_page_admin_view() {
	
	//Get confs
	module_load_include('inc', 'custom_pages', 'includes/custom_pages_pro_conf');
	$highlight_conf = _custom_pages_pro_page_get_highlight_conf();
	$above_header_conf = _custom_pages_pro_page_get_above_header_conf();
	$first_section_conf = _custom_pages_pro_page_get_first_section_conf();
	$second_section_conf = _custom_pages_pro_page_get_second_section_conf();
	$third_section_conf = _custom_pages_pro_page_get_third_section_conf();
	$fourth_section_conf = _custom_pages_pro_page_get_fourth_section_conf();
	
	//Above header
	module_load_include('inc', 'custom_base', 'custom_base.admin');
	$above_header_form = drupal_get_form('custom_base_generic_title_subtitle_form', $above_header_conf);
	$above_header_form['section']['#title'] = t('Abode header disc');
	
	//Highlight section
	module_load_include('inc', 'custom_base', 'custom_base.admin');
	$highlight_form = drupal_get_form('custom_base_generic_section_title_body_link_form', $highlight_conf);
	$highlight_form['section']['#title'] = t('Highlight section');
	
	//First section
	//module_load_include('inc', 'custom_base', 'custom_base.admin');
	$first_section_form = drupal_get_form('custom_base_generic_section_image_title_body_link_form', $first_section_conf);
	$first_section_form['section']['#title'] = t('First section');
	
	//Second section
	$second_section_form = drupal_get_form('custom_base_generic_section_image_title_body_link_form', $second_section_conf);
	$second_section_form['section']['#title'] = t('Second section');
	
	//Third section
	$third_section_form = drupal_get_form('custom_base_generic_section_double_image_title_body_form', $third_section_conf);
	$third_section_form['section']['#title'] = t('Third section');
	
	//Fourth section
	$fourth_section_form = drupal_get_form('custom_base_generic_section_title_body_form', $fourth_section_conf);
	$fourth_section_form['section']['#title'] = t('Fourth section');
	
	return render($above_header_form) . render($highlight_form) . render($first_section_form) . render($second_section_form) . render($third_section_form) . render($fourth_section_form);
}