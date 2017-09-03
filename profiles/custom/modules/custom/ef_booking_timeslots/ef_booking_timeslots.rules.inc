<?php

/**
 * Implements hook_rules_event_info().
 */
function ef_booking_timeslots_rules_event_info() {
	$items = array(
		'ef_booking_timeslots_created' => array(
			'label' => t('After EFCAM Booking created'),
			'group' => t('EFCAM'),
			'variables' => rules_events_node_variables(t('created booking')),
			'arguments' => array(
				'userA' => array('type' => 'user', 'label' => t('UserA, which adds userB.')),
				'userB' => array('type' => 'user', 'label' => t('UserB, which is added to UserA\'s list.')),
			),
		),
	);
	return $items;
}
