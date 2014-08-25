<?php
/**
 * @file
 * All view hooks.
 */

/**
 * Implements hook_views_data()
 */ 
function eve_api_views_views_data() {
	$data = array();
	
	// Standard handlers
	$id_handlers = array(
		'field' => array('handler' => 'views_handler_field'),
		'filter' => array('handler' => 'views_handler_filter_numeric'),
		'sort' => array('handler' => 'views_handler_sort'),
		'argument' => array('handler' => 'views_handler_argument'),
	);
	$decimal_handlers = array(
		'field' => array('handler' => 'views_handler_field_numeric'),
		'filter' => array('handler' => 'views_handler_filter_numeric'),
		'sort' => array('handler' => 'views_handler_sort'),
		'argument' => array('handler' => 'views_handler_argument'),
	);
	$float_handlers = array(
		'field' => array(
			'handler' => 'views_handler_field_numeric',
			'float' => TRUE,
		),
		'filter' => array('handler' => 'views_handler_filter_numeric'),
		'sort' => array('handler' => 'views_handler_sort'),
		'argument' => array('handler' => 'views_handler_argument'),
	);
	$string_handlers = array(
		'field' => array(
			'handler' => 'views_handler_field',
			'click sortable' => TRUE,
		),
		'filter' => array('handler' => 'views_handler_filter_string'),
		'sort' => array('handler' => 'views_handler_sort'),
		'argument' => array('handler' => 'views_handler_argument_string'),
	);
	$date_handlers = array(
		'field' => array('handler' => 'views_handler_field'),
		'filter' => array('handler' => 'views_handler_filter_date'),
		'sort' => array('handler' => 'views_handler_sort_date'),
		'argument' => array('handler' => 'views_handler_argument_date'),
	);
	
	// *** eve_api_characters table ***
	$data['eve_api_characters']['table']['group'] = t('EVE API');
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
	$field_data = array(
		'title' => t('Character ID'),
		'help' => t('Unique ID of EVE Online character.'),
	);
	$data['eve_api_characters']['characterID'] = array_merge($id_handlers, $field_data);
	$data['eve_api_characters']['uid'] = array(
		'title' => t('User'),
		'help' => t('Drupal user associated with the character.'),
		'relationship' => array(
			'label' => t('Character'),
			'base' => 'users',
			'base field' => 'uid',
		),
	);
	$data['eve_api_characters']['apiID'] = array(
		'title' => t('API Key'),
		'help' => t('API key associated with the character.'),
		'relationship' => array(
			'label' => t('API Key Info'),
			'base' => 'eve_api_keys',
			'base field' => 'apiID',
		),
	);

	$field_data = array(
		'title' => t('Character Name'),
		'help' => t('EVE Online character name.'),
	);
	$data['eve_api_characters']['characterName'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Corporation ID'),
		'help' => t('ID of the corporation to which the character belongs.'),
	);
	$data['eve_api_characters']['corporationID'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Corporation Name'),
		'help' => t('Name of the corporation to which the character belongs.'),
	);
	$data['eve_api_characters']['corporationName'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Corporation Ticker'),
		'help' => t('Ticker of the corporation to which the character belongs.'),
	);
	$data['eve_api_characters']['corporationTicker'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Alliance ID'),
		'help' => t('ID of the alliance to which the character belongs.'),
		$id_handlers,
	);
	$data['eve_api_characters']['allianceID'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Alliance Name'),
		'help' => t('Name of the aliance to which the character belongs.'),
	);
	$data['eve_api_characters']['allianceName'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Alliance Ticker'),
		'help' => t('Ticker of the alliance to which the character belongs.'),
	);
	$data['eve_api_characters']['allianceTicker'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Access Mask'),
		'help' => t('API key access mask retreived from the last API pull.'),
	);
	$data['eve_api_characters']['accessMask'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('API Key Info Error Code'),
		'help' => t('Status of the last pull of /account/APIKeyInfo.xml.aspx.'),
		'group' => t('EVE API Errors'),
	);
	$data['eve_api_characters']['errorCode'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('API Key Info Error Text'),
		'help' => t('Error message returned during last pull of /account/APIKeyInfo.xml.aspx.'),
		'group' => t('EVE API Errors'),
	);
	$data['eve_api_characters']['errorText'] = array_merge($string_handlers, $field_data);

	$data['eve_api_characters']['deleted'] = array(
		'title' => t('Deleted'),
		'help' => t('Indicates that the character was no longer available during the last API pull.'),
		'field' => array('handler' => 'views_handler_field_boolean'),
		'filter' => array(
			'handler' => 'views_handler_filter_boolean_operator',
			'label' => 'Deleted',
		),
		'sort' => array('handler' => 'views_handler_sort'),
		'argument' => array('handler' => 'views_handler_argument'),
	);

	// *** eve_api_keys table ***
	$data['eve_api_keys']['table']['group'] = t('EVE API');
	$data['eve_api_keys']['table']['join']['user'] = array (
		'left_field' => 'uid',
		'field' => 'uid',
	);
	$data['eve_api_characters']['uid'] = array(
		'title' => t('User'),
		'help' => t('Drupal user associated with the API key.'),
		'relationship' => array(
			'label' => t('API Key'),
			'base' => 'users',
			'base field' => 'uid',
		),
	);

	$field_data = array(
		'title' => t('API Key ID'),
		'help' => t('Character API key ID.'),
	);
	$data['eve_api_keys']['keyID'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Verification Code'),
		'help' => t('API key verification code.'),
	);
	$data['eve_api_keys']['vCode'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Last Error Code'),
		'help' => t('Error code indicating status of the last API pull.'),
		'group' => t('EVE API Errors'),
	);
	$data['eve_api_keys']['errorCode'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Last Error Text'),
		'help' => t('Error message returned with the error code on from the last API pull.'),
		'group' => t('EVE API Errors'),
	);
	$data['eve_api_keys']['errorText'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('API Updated Date'),
		'help' => t('When API data was last updated.'),
	);
	$data['eve_api_keys']['updated'] = array_merge($date_handlers, $field_data);
	
	$field_data = array(
		'title' => t('API Created Date'),
		'help' => t('When the API was created.'),
	);
	$data['eve_api_keys']['created'] = array_merge($date_handlers, $field_data);

	// *** eve_api_character_info table ***
	$data['eve_api_character_info']['table']['group'] = t('EVE API');
	$data['eve_api_character_info']['table']['join']['eve_api_characters'] = array (
		'left_field' => 'characterID',
		'field' => 'characterID',
	);
	// Skipping the following fields as they are obtained from /account/APIKeyInfo.xml.aspx:
	// characterID, characterName, corporationID, corporation, allianceID, alliance
	$data['eve_api_character_info']['characterID'] = array(
		'title' => t('Character Info'),
		'help' => t('Character attributes from Character Info API.'),
		'relationship' => array(
			'label' => t('Character Info'),
			'base' => 'eve_api_characters',
			'base field' => 'characterID',
		),
	);
	$field_data = array(
		'title' => t('Race'),
		'help' => t('Race of the characer.'),
	);
	$data['eve_api_character_info']['race'] = array_merge($string_handlers, $field_data);
	
	$field_data = array(
		'title' => t('Bloodline'),
		'help' => t('Bloodline of the characer.'),
	);
	$data['eve_api_character_info']['bloodLine'] = array_merge($string_handlers, $field_data);
	
	$field_data = array(
		'title' => t('Account Balance'),
		'help' => t('ISK account balance of the character.'),
	);
	$data['eve_api_character_info']['accountBalance'] = array_merge($decimal_handlers, $field_data);

	$field_data = array(
		'title' => t('Skill Points'),
		'help' => t('Total skill points of the character.'),
	);
	$data['eve_api_character_info']['skillPoints'] = array_merge($decimal_handlers, $field_data);

	$field_data = array(
		'title' => t('Next Training Ends'),
		'help' => t('Date when the training ends.'),
	);
	$data['eve_api_character_info']['nextTrainingEnds'] = array_merge($date_handlers, $field_data);
	
	$field_data = array(
		'title' => t('Ship Name'),
		'help' => t('Name of the current ship.'),
	);
	$data['eve_api_character_info']['shipName'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Ship Type ID'),
		'help' => t('EVE type ID of the current ship.'),
	);
	$data['eve_api_character_info']['shipTypeID'] = array_merge($id_handlers, $field_data);
	
	$field_data = array(
		'title' => t('Ship Type Name'),
		'help' => t('Type name of the current ship.'),
	);
	$data['eve_api_character_info']['shipTypeName'] = array_merge($string_handlers, $field_data);
	
	$field_data = array(
		'title' => t('Corporation Join Date'),
		'help' => t('When the character joined the corporation.'),
	);
	$data['eve_api_character_info']['corporationDate'] = array_merge($date_handlers, $field_data);
	
	$field_data = array(
		'title' => t('Last Known Location'),
		'help' => t('Last known location of the character.'),
	);
	$data['eve_api_character_info']['lastKnownLocation'] = array_merge($string_handlers, $field_data);
	
	$field_data = array(
		'title' => t('Security Status'),
		'help' => t('Security status of the character.'),
	);
	$data['eve_api_character_info']['securityStatus'] = array_merge($float_handlers, $field_data);

	$field_data = array(
		'title' => t('Character Info Error Code'),
		'help' => t('Status of the last pull of /eve/CharacterInfo.xml.aspx.'),
		'group' => t('EVE API Errors'),
	);
	$data['eve_api_character_info']['errorCode'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Character Info Error Text'),
		'help' => t('Error message returned during last pull of /eve/CharacterInfo.xml.aspx.'),
		'group' => t('EVE API Errors'),
	);
	$data['eve_api_character_info']['errorText'] = array_merge($string_handlers, $field_data);
	
	return $data;
}
