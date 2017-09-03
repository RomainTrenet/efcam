<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * Custom Theme Global theme.
 */

function custom_theme_global_css_alter(&$css) {
	$path = drupal_get_path('module', 'booking_timeslots') . '/css/booking_timeslots.css';
	if (isset($css[$path])) {
		unset($css[$path]);
	}
}

/**
 * Override or insert variables for the page templates.
 */
function custom_theme_global_is_develop_mode()
{
	return variable_get('preprocess_css') == 1 ? FALSE : TRUE;
}

/**
 * Implements hook_form_alter().
 */
function custom_theme_global_form_alter(&$form, &$form_state, $form_id) {
	// Set as-form class to all webform.
	if (isset($form['#node']->type)) {
		if ($form['#node']->type == 'webform') {
			$form['#attributes']['class'][] = 'ec-form';
		}
	}
}

/**
 * Implements hook_form_alter().
 */
function custom_theme_global_form_user_login_alter(&$form, &$form_state, $form_id) {
	// Set
	custom_theme_global_add_style_to_form_page($form, 'style-1');
}

/**
 * Implements hook_form_alter().
 */
function custom_theme_global_form_user_pass_alter(&$form, &$form_state, $form_id) {
	// Set
	custom_theme_global_add_style_to_form_page($form, 'style-1');
}

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function custom_theme_global_form_booking_timeslots_booking_form_alter(&$form, &$form_state, $form_id) {
	custom_theme_global_add_style_to_form_page($form, 'style-1');
	//dpm($form);
}

function custom_theme_global_add_style_to_form_page(&$form, $style) {
	// CLasses.
	$form['#attributes'] = array(
		'class' => array(
			'ec-form',
			'clearfix',
		),
	);
	
	// Wrappers.
	$form['#prefix'] = '<div class="container-fluid section-' . $style . '"><div class="container-inner"><div class="row"><div class="col-xs-12 col-sm-push-1 col-sm-10 col-md-push-2 col-md-8 col-lg-push-2 col-lg-8">';
	$form['#suffix'] = '</div></div></div></div>';
	return $form;
}

/**
 * Themes buttons input
 * @param $variables
 * @return string
 */
function custom_theme_global_button($vars) {
	$vars['element']['#attributes']['class'][] = 'btn third-btn';
	return theme_button($vars);
}

/**
 * Themes files input
 */
function custom_theme_global_file($vars) {
	//$vars['element']['#attributes']['class'][] = 'bt1';
	//return theme_file($vars);
	
	// Test custom input file.
	$element = $vars['element'];
	$element['#attributes']['type'] = 'file';
	$element['#attributes']['class'][] = 'ec-inputfile';
	$element['#attributes']['class'][] = 'ec-inputfile-1';
	
	element_set_attributes($element, array('id', 'name', 'size'));
	_form_set_class($element, array('form-file'));
	
	$input = '<input' . drupal_attributes($element['#attributes']) . ' />';
	$input .= '<label class="btn scnd-btn" for="' . $element['#attributes']['id'] . '">';
	$input .= '<span>' . t('Select') . '</span></label>';//$element['#title']
	
	return $input;
}

/**
 * Returns HTML for a link to a file.
 *
 * @param $variables
 *   An associative array containing:
 *   - file: A file object to which the link will be created.
 *   - icon_directory: (optional) A path to a directory of icons to be used for
 *     files. Defaults to the value of the "file_icon_directory" variable.
 *
 * @ingroup themeable
 */
function custom_theme_global_file_link($variables) {
	$file = $variables['file'];
	$icon_directory = $variables['icon_directory'];
	
	$url = file_create_url($file->uri);
	
	// Human-readable names, for use as text-alternatives to icons.
	$mime_name = array(
		'application/msword' => t('Microsoft Office document icon'),
		'application/vnd.ms-excel' => t('Office spreadsheet icon'),
		'application/vnd.ms-powerpoint' => t('Office presentation icon'),
		'application/pdf' => t('PDF icon'),
		'video/quicktime' => t('Movie icon'),
		'audio/mpeg' => t('Audio icon'),
		'audio/wav' => t('Audio icon'),
		'image/jpeg' => t('Image icon'),
		'image/png' => t('Image icon'),
		'image/gif' => t('Image icon'),
		'application/zip' => t('Package icon'),
		'text/html' => t('HTML icon'),
		'text/plain' => t('Plain text icon'),
		'application/octet-stream' => t('Binary Data'),
	);
	
	$mimetype = file_get_mimetype($file->uri);
	
	$icon = theme('file_icon', array(
		'file' => $file,
		'icon_directory' => $icon_directory,
		'alt' => !empty($mime_name[$mimetype]) ? $mime_name[$mimetype] : t('File'),
	));
	
	// Set options as per anchor format described at
	// http://microformats.org/wiki/file-format-examples
	$options = array(
		'attributes' => array(
			'type' => $file->filemime . '; length=' . $file->filesize,
			/*'class' => array(
				'as-file'
			),*/
		),
		'html' => TRUE,
	);
	
	$link_text = '<span class="icon-check"></span><span class="file-name">';
	
	// Use the description as the link text if available.
	if (empty($file->description)) {
		$link_text .= $file->filename;
	}
	else {
		$link_text .= $file->description;
		$options['attributes']['title'] = check_plain($file->filename);
	}
	
	$link_text .= '</span>';
	
	//return '<span class="file">' . $icon . ' ' . l($link_text, $url, $options) . '</span>';
	return '<span class="file ec-file">' . l($link_text, $url, $options) . '</span>';
	//return l($link_text, $url, $options);
	//file_ajax_upload();
}

/**
 * ADD Help span to password form item to have a tooltip
 * @param $vars
 * @return string
 */
function custom_theme_global_form_element($vars) {
	if (isset($vars['element']['#id'])) {
		switch ($vars['element']['#id']) {
			case 'edit-pass-pass1':
				$vars['element']['#field_suffix'] = '<span class="help"></span>';
				// Add tooltip library to all user/register forms.
				drupal_add_library('system', 'ui.tooltip');
				break;
			default:
				break;
		}
	}
	
	return theme_form_element($vars);
}


/**
 * Themes container
 */
function custom_theme_global_container($vars) {
	if($vars['element']['#id'] == 'edit-picture'){
		$element = $vars['element'];
		// Ensure #attributes is set.
		$element += array('#attributes' => array());
		
		// Special handling for form elements.
		if (isset($element['#array_parents'])) {
			// Assign an html ID.
			if (!isset($element['#attributes']['id'])) {
				$element['#attributes']['id'] = $element['#id'];
			}
			// Add the 'form-wrapper' class.
			$element['#attributes']['class'][] = 'form-wrapper';
		}
		
		return '<div class="form-item clearfix"><div' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</div></div>';
	}
	
	//Else, normal theme
	return theme_container($vars);
}
