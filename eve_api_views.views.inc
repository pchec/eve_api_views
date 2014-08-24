<?php
/**
 * @file
 * All view hooks.
 */

function eve_api_views_views_data() {
	$data = array();
	$data['eve_api_characters']['table']['group'] = 'EVE API';
	$data['eve_api_characters']['table']['base'] = array(
		'field' => 'characterID',
		'title' => t('Character'),
		'help' => t('Characters available in EVE API.'),
		'weight' => -10,
	);
	$data['eve_api_characters']['table']['join']['user'] = array (
		'left_field' => 'uid',
		'field' => 'uid',
	);
	$data['eve_api_characters']['characterID'] = array(
		'title' => t('Character ID'),
		'help' => t('ID of the character in EVE Online.'),
		'field' => array(
			'handler' => 'views_handler_field',
		),
		'filter' => array(
			'handler' => 'views_handler_filter',
		),
		'sort' => array(
			'handler' => 'views_handler_sort',
		),
		'argument' => array(
			'handler' => 'views_handler_argument',
		),
	);
	$data['eve_api_characters']['uid'] = array(
		'title' => t('User ID'),
		'help' => t('User ID.'),
		'field' => array(
			'handler' => 'views_handler_field_user_name',
		),
		'filter' => array(
			'handler' => 'views_handler_filter',
		),
		'sort' => array(
			'handler' => 'views_handler_sort',
		),
		'argument' => array(
			'handler' => 'views_handler_argument_user_uid',
			'name field' => 'name'
		),
		'relationship' => array(
			'label' => t('User'),
			'base' => 'users',
			'base field' => 'uid',
		),
	);
	$data['eve_api_characters']['apiID'] = array(
		'title' => t('API ID'),
		'help' => t('API ID associated with the character.'),
		'field' => array(
			'handler' => 'views_handler_field',
		),
		'filter' => array(
			'handler' => 'views_handler_filter',
		),
		'sort' => array(
			'handler' => 'views_handler_sort',
		),
		'argument' => array(
			'handler' => 'views_handler_argument',
		),
	);
	$data['eve_api_characters']['characterName'] = array(
		'title' => t('Character Name'),
		'help' => t('Character name.'),
		'field' => array(
			'handler' => 'views_handler_field',
			'click sortable' => TRUE,
		),
		'filter' => array(
			'handler' => 'views_handler_filter_string',
		),
		'sort' => array(
			'handler' => 'views_handler_sort',
		),
		'argument' => array(
			'handler' => 'views_handler_argument_string',
		),
	);

	return $data;
}