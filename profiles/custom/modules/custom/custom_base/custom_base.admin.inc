<?php

/**
 * Administration settings form.
 *
 * @return
 *   The completed form definition.
 */
function _custom_base_global_admin_view() {
	
	//Global admin form
	$global_settings_admin_form = drupal_get_form('custom_base_global_settings_admin_form');
	
	return render($global_settings_admin_form);
}

/**
 * Return a form for managing AS base settings.
 */
function custom_base_global_settings_admin_form() {
	$form = array();
	
	// Contact page settings.
	$form['efcam_settings'] = array(
		'#type' => 'fieldset',
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
		'#title' => t('Informations for EFCAM'),
	);
	$form['efcam_settings']['contact_email_address'] = array(
		'#type' => 'textfield',
		'#title' => t('Contact mail address'),
		'#required' => TRUE,
		'#default_value' => variable_get('efcam_settings_contact_email_address'),
	);
	
	// Construct addressfield.
	$address = variable_get('efcam_settings_address', array(
		'thoroughfare' => '',
		'premise' => '',
		'locality' => '',
		'administrative_area' => '',
		'postal_code' => '',
		'country' => 'FR',
	));
	$handlers = array('address' => 'address');
	$context = array('mode' => 'form');
	$form['efcam_settings']['address'] = addressfield_generate($address, $handlers, $context);
	
	$form['efcam_settings']['contact_phone'] = array(
		'#type' => 'textfield',
		'#title' => t('Phone'),
		'#required' => TRUE,
		'#default_value' => variable_get('efcam_settings_contact_phone'),
	);
	
	//Form Submit
	$form['efcam_settings']['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save settings'),
	);
	return $form;
}

/**
 * Hook_submit.
 * Save settings after form submit.
 */
function custom_base_global_settings_admin_form_submit($form, &$form_state) {
	
	// Contact page settings.
	variable_set('efcam_settings_contact_email_address', $form_state['values']['contact_email_address']);
	variable_set('efcam_settings_address', array(
		'thoroughfare' => $form_state['values']['thoroughfare'],
		'premise' => $form_state['values']['premise'],
		'locality' => $form_state['values']['locality'],
		'administrative_area' => $form_state['values']['administrative_area'],
		'postal_code' => $form_state['values']['postal_code'],
		'country' => $form_state['values']['country'],
	));
	
	drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Custom Generic section form with title, body and link title.
 */
function custom_base_generic_section_title_body_form($form, &$form_state, $conf) {
	
	// Forms variable suffix.
	$conf['form_vars_suffix'] = '_' . $conf['module_name'] . '_' . $conf['context'];
	
	// Create contextual var name.
	$vars_name = array('title', 'body');
	$var_name_prefix = $conf['module_name'] . '_' . $conf['context'] . '_';
	foreach ($vars_name as $key => $var_name) {
		$conf[$var_name.'_var_name'] =  $var_name_prefix . $var_name;
	}
	
	// And bring it to the form.
	$form = array();
	$form['conf'] = array(
		'#type' => 'value',
		'#value' => $conf,
	);
	
	/**
	 * Generate form
	 */
	$form['section'] = array(
		'#type' => 'fieldset',
		'#collapsible' => TRUE,
		'#collapsed' => TRUE,
		'#title' => t('Generic section form with title, body and link title'),
	);
	
	$form['section']['title' . '_' . $conf['form_vars_suffix']] = array(
		'#type' => 'textfield',
		'#title' => t('Title'),
		'#required' => TRUE,
		'#default_value' => variable_get($conf['title_var_name']),
	);
	$form['section']['body' . '_' . $conf['form_vars_suffix']] = array(
		'#type' => 'text_format',
		'#format' => 'full_html',
		'#title' => t('Body'),
		'#required' => TRUE,
		'#prefix' => _custom_base_get_generic_wysiwyg_prefix(),
		'#default_value' => variable_get($conf['body_var_name']),
	);
	$form['section']['actions']['submit'] = array(
		'#type' => 'submit',
		'#access' => TRUE,
		'#value' => t('Save settings'),
	);
	
	return $form;
}

/**
 * Submit for Custom Generic section form with title, body and link title.
 */
function custom_base_generic_section_title_body_form_submit($form, &$form_state) {
	$conf = $form['conf']['#value'];
	variable_set($conf['title_var_name'], $form_state['values']['title']);
	variable_set($conf['body_var_name'], $form_state['values']['body']['value']);
	
	drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Custom Generic section form with title, body and link title.
 */
function custom_base_generic_section_title_body_link_form($form, &$form_state, $conf) {
	
	// Forms variable suffix.
	$conf['form_vars_suffix'] = '_' . $conf['module_name'] . '_' . $conf['context'];
	
	// Create contextual var name.
	$vars_name = array('title', 'body', 'link_title');
	$var_name_prefix = $conf['module_name'] . '_' . $conf['context'] . '_';
	foreach ($vars_name as $key => $var_name) {
		$conf[$var_name.'_var_name'] =  $var_name_prefix . $var_name;
	}
	
	// And bring it to the form.
	$form = array();
	$form['conf'] = array(
		'#type' => 'value',
		'#value' => $conf,
	);
	
	/**
	 * Generate form.
	 */
	//$section = $conf['module_name'] . '_' .$conf['context'] . '_';
	$form['section'] = array(
		'#type' => 'fieldset',
		'#collapsible' => TRUE,
		'#collapsed' => TRUE,
		'#title' => t('Generic section form with title, body and link title'),
	);
	
	$form['section']['title' . '_' . $conf['form_vars_suffix']] = array(
		'#type' => 'textfield',
		'#title' => t('Title'),
		'#required' => TRUE,
		'#default_value' => variable_get($conf['title_var_name']),
	);
	$form['section']['body' . '_' . $conf['form_vars_suffix']] = array(
		'#type' => 'text_format',
		'#format' => 'full_html',
		'#title' => t('Body'),
		'#required' => TRUE,
		'#prefix' => _custom_base_get_generic_wysiwyg_prefix(),
		'#default_value' => variable_get($conf['body_var_name']),
	);
	$form['section']['link_title' . '_' . $conf['form_vars_suffix']] = array(
		'#type' => 'textfield',
		'#title' => t('Link title'),
		'#required' => TRUE,
		'#default_value' => variable_get($conf['link_title_var_name']),
	);
	$form['section']['actions']['submit'] = array(
		'#type' => 'submit',
		'#access' => TRUE,
		'#value' => t('Save settings'),
	);
	
	return $form;
}
/**
 * Submit for Custom Generic section form with title, body and link title.
 */
function custom_base_generic_section_title_body_link_form_submit($form, &$form_state) {
	$conf = $form['conf']['#value'];
	variable_set($conf['title_var_name'], $form_state['values']['title']);
	variable_set($conf['body_var_name'], $form_state['values']['body']['value']);
	variable_set($conf['link_title_var_name'], $form_state['values']['link_title']);
	
	drupal_set_message(t('The configuration options have been saved.'));
}


/**
 * Custom Generic section form with image title, body and link title.
 */
function custom_base_generic_section_image_title_body_link_form($form, &$form_state, $conf) {
	
	// Forms variable suffix.
	$conf['form_vars_suffix'] = '_' . $conf['module_name'] . '_' . $conf['context'];
	
	// Create contextual var name.
	$vars_name = array('image', 'title', 'body', 'link_title');
	$var_name_prefix = $conf['module_name'] . '_' . $conf['context'] . '_';
	foreach ($vars_name as $key => $var_name) {
		$conf[$var_name.'_var_name'] =  $var_name_prefix . $var_name;
	}
	
	// And bring it to the form.
	$form = array();
	$form['conf'] = array(
		'#type' => 'value',
		'#value' => $conf,
	);
	
	/**
	 * Generate form.
	 */
	$form['section'] = array(
		'#type' => 'fieldset',
		'#collapsible' => TRUE,
		'#collapsed' => TRUE,
		'#title' => t('Generic section form with title, body and link title'),
	);
	
	$form['section']['title' . '_' . $conf['form_vars_suffix']] = array(
		'#type' => 'textfield',
		'#title' => t('Title'),
		'#required' => TRUE,
		'#default_value' => variable_get($conf['title_var_name']),
	);
	//$form['section']['image' . '_' . $conf['form_vars_suffix']] = array(
	$form['section']['image'] = array(
		'#type' => 'media',
		'#theme' => 'media_widget',
		'#title' => t('Image'),
		'#description' => t('Choose an image'),
		'#default_value' => variable_get($conf['image_var_name']),
		'#media_options' => array(
			'global' => array(
				'types' => array('image'),
				'enabledPlugins' => array(
					'upload',
					'media_default--media_browser_my_files'
				),
				'schemes' => array(
					'public' => 'public',
				),
				'file_directory' => 'pages',
				'file_extensions' => 'png gif jpg jpeg',
				'max_filesize' => EC_DEFAULT_MAX_FILESIZE,
				'uri_scheme' => 'public',
			),
		),
	);
	$form['section']['body' . '_' . $conf['form_vars_suffix']] = array(
		'#type' => 'text_format',
		'#format' => 'full_html',
		'#title' => t('Body'),
		'#required' => TRUE,
		'#prefix' => _custom_base_get_generic_wysiwyg_prefix(),
		'#default_value' => variable_get($conf['body_var_name']),
	);
	$form['section']['link_title' . '_' . $conf['form_vars_suffix']] = array(
		'#type' => 'textfield',
		'#title' => t('Link title'),
		'#required' => TRUE,
		'#default_value' => variable_get($conf['link_title_var_name']),
	);
	$form['section']['actions']['submit'] = array(
		'#type' => 'submit',
		'#access' => TRUE,
		'#value' => t('Save settings'),
	);
	
	return $form;
}
/**
 * Submit for Custom Generic section form with title, body and link title
 */
function custom_base_generic_section_image_title_body_link_form_submit($form, &$form_state) {
	dpm($form['conf']);
	$conf = $form['conf']['#value'];
	dpm($form_state['values']);
	dpm($conf);
	//$section = $conf['module_name'] . '_' .$conf['context'];
	// TODO probleme image.
	
	variable_set($conf['title_var_name'], $form_state['values']['title' . '_' . $conf['form_vars_suffix']]);
	//variable_set($conf['image_var_name'], $form_state['values']['image' . '_' . $conf['form_vars_suffix']]);
	variable_set($conf['image_var_name'], $form_state['values']['image' . '_' . $conf['form_vars_suffix']]);
	variable_set($conf['body_var_name'], $form_state['values']['body' . '_' . $conf['form_vars_suffix']]['value']);
	variable_set($conf['link_title_var_name'], $form_state['values']['link_title' . '_' . $conf['form_vars_suffix']]);
	
	drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Custom Generic section form with image title, body and link title.
 */
function custom_base_generic_section_double_image_title_body_form($form, &$form_state, $conf) {
	
	// Forms variable suffix.
	$conf['form_vars_suffix'] = '_' . $conf['module_name'] . '_' . $conf['context'];
	
	// Create contextual var name.
	$vars_name = array('first_image', 'second_image', 'title', 'body');
	$var_name_prefix = $conf['module_name'] . '_' . $conf['context'] . '_';
	foreach ($vars_name as $key => $var_name) {
		$conf[$var_name.'_var_name'] =  $var_name_prefix . $var_name;
	}
	
	// And bring it to the form.
	$form = array();
	$form['conf'] = array(
		'#type' => 'value',
		'#value' => $conf,
	);
	
	/**
	 * Generate form.
	 */
	$form['section'] = array(
		'#type' => 'fieldset',
		'#collapsible' => TRUE,
		'#collapsed' => TRUE,
		'#title' => t('Generic section form with title, body and link title'),
	);
	
	$form['section']['title' . '_' . $conf['form_vars_suffix']] = array(
		'#type' => 'textfield',
		'#title' => t('Title'),
		'#required' => TRUE,
		'#default_value' => variable_get($conf['title_var_name']),
	);
	$form['section']['first_image' . '_' . $conf['form_vars_suffix']] = array(
		'#type' => 'media',
		'#theme' => 'media_widget',
		'#title' => t('Main image'),
		'#description' => t('Choose an image'),
		'#default_value' => variable_get($conf['first_image_var_name']),
		'#media_options' => array(
			'global' => array(
				'types' => array('image'),
				'enabledPlugins' => array(
					'upload',
					'media_default--media_browser_my_files'
				),
				'schemes' => array(
					'public' => 'public',
				),
				'file_directory' => 'pages',
				'file_extensions' => 'png gif jpg jpeg',
				'max_filesize' => EC_DEFAULT_MAX_FILESIZE,
				'uri_scheme' => 'public',
			),
		),
	);
	$form['section']['second_image' . '_' . $conf['form_vars_suffix']] = array(
		'#type' => 'media',
		'#theme' => 'media_widget',
		'#title' => t('Second image'),
		'#description' => t('Choose an image'),
		'#default_value' => variable_get($conf['second_image_var_name']),
		'#media_options' => array(
			'global' => array(
				'types' => array('image'),
				'enabledPlugins' => array(
					'upload',
					'media_default--media_browser_my_files'
				),
				'schemes' => array(
					'public' => 'public',
				),
				'file_directory' => 'pages',
				'file_extensions' => 'png gif jpg jpeg',
				'max_filesize' => EC_DEFAULT_MAX_FILESIZE,
				'uri_scheme' => 'public',
			),
		),
	);
	$form['section']['body' . '_' . $conf['form_vars_suffix']] = array(
		'#type' => 'text_format',
		'#format' => 'full_html',
		'#title' => t('Body'),
		'#required' => TRUE,
		'#prefix' => _custom_base_get_generic_wysiwyg_prefix(),
		'#default_value' => variable_get($conf['body_var_name']),
	);
	$form['section']['actions']['submit'] = array(
		'#type' => 'submit',
		'#access' => TRUE,
		'#value' => t('Save settings'),
	);
	
	return $form;
}
/**
 * Submit for Custom Generic section form with title, body and link title
 */
function custom_base_generic_section_double_image_title_body_form_submit($form, &$form_state) {
	$conf = $form['conf']['#value'];
	variable_set($conf['title_var_name'], $form_state['values']['title']);
	variable_set($conf['first_image_var_name'], $form_state['values']['image']);
	variable_set($conf['second_image_var_name'], $form_state['values']['image']);
	variable_set($conf['body_var_name'], $form_state['values']['body']['value']);
	
	drupal_set_message(t('The configuration options have been saved.'));
}


/**
 * Custom Generic double body form.
 */
function custom_base_generic_title_subtitle_form($form, &$form_state, $conf) {
	
	// Forms variable suffix.
	$conf['form_vars_suffix'] = '_' . $conf['module_name'] . '_' . $conf['context'];
	
	// Create contextual var name.
	$vars_name = array('title', 'subtitle');
	$var_name_prefix = $conf['module_name'] . '_' . $conf['context'] . '_';
	foreach ($vars_name as $key => $var_name) {
		$conf[$var_name.'_var_name'] =  $var_name_prefix . $var_name;
	}
	
	// And bring it to the form.
	$form = array();
	$form['conf'] = array(
		'#type' => 'value',
		'#value' => $conf,
	);
	
	/**
	 * Generate form.
	 */
	$form['section'] = array(
		'#type' => 'fieldset',
		'#collapsible' => TRUE,
		'#collapsed' => TRUE,
		'#title' => t('Generic section form with title, body and link title'),
	);
	$form['section']['title' . '_' . $conf['form_vars_suffix']] = array(
		'#type' => 'text_format',
		'#format' => 'filtered_html',
		'#title' => t('Title'),
		'#required' => TRUE,
		'#prefix' => _custom_base_get_generic_wysiwyg_prefix(),
		'#default_value' => variable_get($conf['title_var_name']),
	);
	$form['section']['subtitle' . '_' . $conf['form_vars_suffix']] = array(
		'#type' => 'text_format',
		'#format' => 'filtered_html',
		'#title' => t('Subtitle'),
		'#required' => TRUE,
		'#prefix' => _custom_base_get_generic_wysiwyg_prefix(),
		'#default_value' => variable_get($conf['subtitle_var_name']),
	);
	$form['section']['actions']['submit'] = array(
		'#type' => 'submit',
		'#access' => TRUE,
		'#value' => t('Save settings'),
	);
	
	return $form;
}

/**
 * Submit for Custom Generic section form with title, body and link title.
 */
function custom_base_generic_title_subtitle_form_submit($form, &$form_state) {
	$conf = $form['conf']['#value'];
	variable_set($conf['title_var_name'], $form_state['values']['title']['value']);
	variable_set($conf['subtitle_var_name'], $form_state['values']['subtitle']['value']);
	
	drupal_set_message(t('The configuration options have been saved.'));
}





/***********************************************/
//Form example TODO delete

/**
 * Generic header admin form.
 * See as_contact for example. Create a conf function (for example : _as_contact_contact_page_get_header_conf()).
 * And call form with it.
 */
function custom_base_generic_custom_title_admin_settings_form($form, &$form_state, $conf) {
	$title_var_name = $conf['module_name'] . '_' . $conf['context'] . '_header_title';
	
	$conf['title_var_name'] = $title_var_name;
	
	$form = array();
	$form['conf'] = array(
		'#type' => 'value',
		'#value' => $conf,
	);
	
	/**
	 * Main content header
	 */
	$form['header_title'] = array(
		'#type' => 'fieldset',
		'#collapsible' => TRUE,
		'#collapsed' => TRUE,
		'#title' => t('Header title'),
	);
	$form['header_title'][$title_var_name] = array(
		'#type' => 'text_format',
		'#format' => 'plain_text',
		'#title' => t('Custom header title'),
		'#required' => FALSE,
		'#default_value' => variable_get($title_var_name),
		'#prefix' => _custom_base_get_generic_wysiwyg_prefix(),
	);
	
	//Form Submit
	//$form['header_title']['actions']['submit']['#submit'][] = 'custom_base_generic_custom_title_admin_settings_form_submit';
	$form['header_title']['actions']['submit'] = array(
		'#type' => 'submit',
		'#access' => TRUE,
		'#value' => t('Save settings'),
	);
	
	return $form;
}

/**
 * Generic header admin form submit.
 */
function custom_base_generic_custom_title_admin_settings_form_submit($form, &$form_state)
{
	$conf = $form['conf']['#value'];
	variable_set($conf['title_var_name'], $form_state['values'][$conf['title_var_name']]['value']);
	
	drupal_set_message(t('The configuration options have been saved.'));
}