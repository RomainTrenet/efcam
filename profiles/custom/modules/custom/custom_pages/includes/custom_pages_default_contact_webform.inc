<?php

/**
 * @file
 * User default webforms.
 */

// @codingStandardsIgnoreStart
/**
 * Create default "become partner" webform.
 */
function custom_pages_create_contact_webform() {
  $node = new stdClass();
  $node->type = 'webform';
  node_object_prepare($node);
  $node->title = 'Prendre contact';
  $node->language = 'fr';
  $node->body[LANGUAGE_NONE][0]['value']   = '';
  $node->body[LANGUAGE_NONE][0]['format']  = 'full_html';
  $node->promote = 0;
  $node->comment = 0;
	
	// Create the webform components.
	$components = array(
		array(
			'weight' => 1,
			'cid'=> 2,
			'pid' => 0,
			'form_key' => 'surname',
			'name' => 'Prénom',
			'type' => 'textfield',
			'value' => '[current-user:field_first_name]',
			'required' => 1,
			'page_num' => 1,
			'extra' => array(
				'title_display' => 'none',
				'description_above' => 0,
				'private' => 0,
				'wrapper_classes' => '',
				'css_classes' => '',
				'placeholder' => 'Prénom',
				'maxlength' => 50,
				'width' => '',
				'field_prefix' => '',
				'field_suffix' => '',
				'disabled' => 0,
				'unique' => 0,
				'description' => '',
				'attributes' => array(),
				'analysis' => FALSE,
			),
		),
		array(
			'weight' => 2,
			'cid'=> 3,
			'pid' => 0,
			'form_key' => 'name',
			'name' => 'Nom',
			'type' => 'textfield',
			'value' => '[current-user:name]',
			'required' => 1,
			'page_num' => 1,
			'extra' => array(
				'title_display' => 'none',
				'description_above' => 0,
				'private' => 0,
				'wrapper_classes' => '',
				'css_classes' => '',
				'placeholder' => 'Votre nom',
				'maxlength' => 50,
				'width' => '',
				'field_prefix' => '',
				'field_suffix' => '',
				'disabled' => 0,
				'unique' => 0,
				'description' => '',
				'attributes' => array(),
				'analysis' => FALSE,
			),
		),
		array(
			'weight' => 3,
			'cid'=> 4,
			'pid' => 0,
			'form_key' => 'courriel',
			'name' => 'E-mail',
			'type' => 'email',
			'value' => '[current-user:mail]',
			'required' => 1,
			'page_num' => 1,
			'extra' => array(
				'title_display' => 'none',
				'description_above' => 0,
				'private' => 0,
				'wrapper_classes' => '',
				'css_classes' => '',
				'placeholder' => 'Mail',
				'multiple' => 0,
				'format' => 'short',
				'width' => '',
				'unique' => 0,
				'disabled' => 0,
				'description' => '',
				'attributes' => array(),
				'analysis' => FALSE,
			),
		),
		array(
			'weight' => 4,
			'cid'=> 5,
			'pid' => 0,
			'form_key' => 'contact_cv_file',
			'name' => 'Inserez votre CV pour une demande de formation',
			'type' => 'file',
			'value' => '',
			'required' => 0,
			'page_num' => 1,
			'extra' => array(
				'directory' => 'files',
				'title_display' => 'inline',
				'description_above' => 0,
				'private' => 0,
				'wrapper_classes' => '',
				'css_classes' => '',
				'filtering' => array(
					'size' => '3 MB',
					'types' => array(
						0 => 'txt',
						1 => 'rtf',
						2 => 'pdf',
						3 => 'doc',
						4 => 'docx',
					),
					'addextensions' => '',
				),
				'rename' => '',
				'scheme' => 'public',
				'progress_indicator' => 'throbber',
				'description' => '',
				'attributes' => array(),
				'analysis' => FALSE,
			),
		),
		array(
			'weight' => 5,
			'cid'=> 6,
			'pid' => 0,
			'form_key' => 'message',
			'name' => 'Votre message',
			'type' => 'textarea',
			'value' => '',
			'required' => 1,
			'page_num' => 1,
			'extra' => array(
				'title_display' => 'none',
				'description_above' => 0,
				'private' => 0,
				'wrapper_classes' => '',
				'css_classes' => '',
				'placeholder' => 'Votre question, souci, message ...',
				'cols' => '',
				'rows' => '',
				'resizable' => 1,
				'disabled' => 0,
				'description' => '',
				'attributes' => array(),
				'analysis' => FALSE,
			),
		),
		/*array(
			'weight' => 6,
			'cid'=> 7,
			'pid' => 0,
			'form_key' => 'send_copy',
			'name' => 'Copie email',
			'type' => 'select',
			'value' => '',
			'required' => 0,
			'page_num' => 1,
			'extra' => array(
				'items' => 'send_copy|Envoyez-moi une copie par e-mail',
				'multiple' => 1,
				'title_display' => 'none',
				'description_above' => 0,
				'private' => 0,
				'wrapper_classes' => '',
				'css_classes' => '',
				'aslist' => 0,
				'empty_option' => '',
				'optrand' => 0,
				'other_option' => NULL,
				'other_text' => 'Other...',
				'description' => '',
				'custom_keys' => FALSE,
				'options_source' => '',
				'analysis' => TRUE,
			),
		),*/
	);
	// EO components.
	
	// Setup notification email.
	$emails = array(
		array(
			'email' => '[site:mail]',
			'subject' => 'Contact',
			'from_name' => 3,
			'from_address' => 4,
			'template' => 'default',
			'excluded_components' => array(),
			'html' => 0,
			'attachments' => 0,
			'exclude_empty' => 0,
			'extra' => FALSE,
			'status' => 1,
		),
	);
	
	// Attach the webform to the node.
	$node->webform = array(
		'confirmation' => '<p>Merci de nous avoir contactés !<br>Notre équipe fait le nécéssaire pour vous répondre dans les meilleurs délais.</p>',
		'confirmation_format' => 'full_html',
		'redirect_url' => '<none>',
		'status' => 1,
		'block' => 0,
		'allow_draft' => 0,
		'auto_save' => 0,
		'submit_notice' => 1,
		'confidential' => 0,
		'submit_text' => 'Envoyer',
		'submit_limit' => -1,
		'submit_interval' => -1,
		'total_submit_limit' => -1,
		'total_submit_interval' => -1,
		'progressbar_bar' => 1,
		'progressbar_page_number' => 0,
		'progressbar_percent' => 0,
		'progressbar_pagebreak_labels' => 1,
		'progressbar_include_confirmation' => 1,
		'progressbar_label_first' => 'Start',
		'progressbar_label_confirmation' => 'Complete',
		'preview' => 0,
		'preview_next_button_label' => '',
		'preview_prev_button_label' => '',
		'preview_title' => '',
		'preview_message' => '',
		'preview_message_format' => 'full_html',
		'preview_excluded_components' => array(),
		'record_exists' => TRUE,
		'roles' => array(
			0 => 1,
			1 => 2,
		),
		
		'emails' => $emails,
		'components' => $components,
	);

  // Save the node.
  node_save($node);
  variable_set('ec_contact_webform_id', $node->nid);
}
