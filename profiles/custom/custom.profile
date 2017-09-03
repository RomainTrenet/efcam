<?php

function custom_profile_details(){
	$details['language'] = "fr";
	return $details;
}

/**
 * Implements hook_install_tasks().
 *
 * Displays help and module information.
 *
 * @param $install_state
 */
function custom_install_tasks(&$install_state)
{
	return array(
		'set_site_slogan' => array(
			'display_name' => t('Set Custom site slogan'),
			'display' => TRUE,
			'type' => 'normal',
			'run' => 'INSTALL_TASK_RUN_IF_REACHED',
			'function' => 'custom_set_site_slogan',
		),
	);
	/*$tasks['set_site_slogan'] = array(
		'display_name' => t('Set Custom site slogan'),
		'display' => TRUE,
		'type' => 'normal',
		'run' => 'INSTALL_TASK_RUN_IF_REACHED',
		'function' => 'custom_set_site_slogan',
	);
	return $tasks;*/
}

/**
 * Implements hook_install_tasks_alter().
 *
 * Displays help and module information.
 *
 * @param $install_state
 */
function custom_install_tasks_alter(&$tasks, $install_state)
{
	$tasks['install_select_locale']['function'] = '_custom_locale_selection';
}

// local callback function
function _custom_locale_selection(&$install_state){
	$install_state['parameters']['locale'] = 'fr';
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function custom_form_install_configure_form_alter(&$form, $form_state) {
	// Pre-populate the site name
	
	$form['site_information']['site_name']['#default_value'] = 'Phoenix - EFCAM';
	$form['site_information']['site_mail']['#default_value'] = 'am@gmail.com';
	
	$form['admin_account']['account']['name']['#default_value'] = 'admin';
	$form['admin_account']['account']['mail']['#default_value'] = 'romain.trenet@gmail.com';
	
	$form['server_settings']['site_default_country']['#default_value'] = 'FR';
	$form['server_settings']['date_default_timezone']['#default_value'] = 'Europe/Paris';
	unset($form['server_settings']['date_default_timezone']['#attributes']);
}

/**
 * Custom function to automatically set site slogan to our profile
 */
function custom_set_site_slogan()
{
	variable_set('site_slogan', 'Thérapie traditionnelle manuelle');
}