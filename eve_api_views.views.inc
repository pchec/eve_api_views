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
		'title' => t('Character API Key Info'),
		'help' => t('Characters available on registered API keys.'),
		'weight' => -10,
	);
	$data['eve_api_characters']['table']['join']['user'] = array (
		'left_field' => 'uid',
		'field' => 'uid',
	);
	$data['eve_api_characters']['table']['join']['eve_api_keys'] = array (
		'left_field' => 'apiID',
		'field' => 'apiID',
	);
	$data['eve_api_characters']['characterID'] = array(
		'title' => t('Character ID'),
		'help' => t('Unique ID of EVE Online character.'),
		'field' => array(
			'handler' => 'views_handler_field',
		),
		'filter' => array(
			'handler' => 'views_handler_filter_numeric',
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
		'help' => t('Drupal user ID.'),
		'field' => array(
			'handler' => 'views_handler_field_user_name',
		),
		'filter' => array(
			'handler' => 'views_handler_filter_equality',
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
			'handler' => 'views_handler_filter_numeric',
		),
		'sort' => array(
			'handler' => 'views_handler_sort',
		),
		'argument' => array(
			'handler' => 'views_handler_argument',
		),
		'relationship' => array(
			'label' => t('API Key'),
			'base' => 'eve_api_keys',
			'base field' => 'apiID',
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
	$data['eve_api_characters']['corporationID'] = array(
		'title' => t('Corporation ID'),
		'help' => t('ID of the corporation to which the character belongs.'),
		'field' => array(
			'handler' => 'views_handler_field',
		),
		'filter' => array(
			'handler' => 'views_handler_filter_numeric',
		),
		'sort' => array(
			'handler' => 'views_handler_sort',
		),
		'argument' => array(
			'handler' => 'views_handler_argument',
		),
	);
	$data['eve_api_characters']['corporationName'] = array(
		'title' => t('Corporation Name'),
		'help' => t('Name of the corporation to which the character belongs.'),
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
	$data['eve_api_characters']['corporationTicker'] = array(
		'title' => t('Corporation Ticker'),
		'help' => t('Ticker of the corporation to which the character belongs.'),
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
	$data['eve_api_characters']['allianceID'] = array(
		'title' => t('Alliance ID'),
		'help' => t('ID of the alliance to which the character belongs.'),
		'field' => array(
			'handler' => 'views_handler_field',
		),
		'filter' => array(
			'handler' => 'views_handler_filter_numeric',
		),
		'sort' => array(
			'handler' => 'views_handler_sort',
		),
		'argument' => array(
			'handler' => 'views_handler_argument',
		),
	);
	$data['eve_api_characters']['allianceName'] = array(
		'title' => t('Alliance Name'),
		'help' => t('Name of the aliance to which the character belongs.'),
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
	$data['eve_api_characters']['allianceTicker'] = array(
		'title' => t('Alliance Ticker'),
		'help' => t('Ticker of the alliance to which the character belongs.'),
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
	$data['eve_api_characters']['accessMask'] = array(
		'title' => t('Access Mask'),
		'help' => t('API key access mask retreived from the last API pull.'),
		'field' => array(
			'handler' => 'views_handler_field',
		),
		'filter' => array(
			'handler' => 'views_handler_filter_numeric',
		),
		'sort' => array(
			'handler' => 'views_handler_sort',
		),
		'argument' => array(
			'handler' => 'views_handler_argument',
		),
	);
	$data['eve_api_characters']['errorCode'] = array(
		'title' => t('Error Code'),
		'help' => t('Error code indicating status of the last API pull.'),
		'field' => array(
			'handler' => 'views_handler_field',
		),
		'filter' => array(
			'handler' => 'views_handler_filter_numeric',
		),
		'sort' => array(
			'handler' => 'views_handler_sort',
		),
		'argument' => array(
			'handler' => 'views_handler_argument',
		),
	);
	$data['eve_api_characters']['errorText'] = array(
		'title' => t('Error Text'),
		'help' => t('Error message returned with the error code on from the last API pull.'),
		'field' => array(
			'handler' => 'views_handler_field',
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
	$data['eve_api_characters']['deleted'] = array(
		'title' => t('Deleted'),
		'help' => t('Indicates that the character was no longer available during the last API pull.'),
		'field' => array(
			'handler' => 'views_handler_field_boolean',
		),
		'filter' => array(
			'handler' => 'views_handler_filter_boolean_operator',
			'label' => 'Deleted',
		),
		'sort' => array(
			'handler' => 'views_handler_sort',
		),
		'argument' => array(
			'handler' => 'views_handler_argument',
		),
	);

	return $data;
}