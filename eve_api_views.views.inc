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
		'field' => array(
			'handler' => 'views_handler_field',
			'click sortable' => TRUE,
		),
		'filter' => array('handler' => 'views_handler_filter_numeric'),
		'sort' => array('handler' => 'views_handler_sort'),
		'argument' => array('handler' => 'views_handler_argument_numeric'),
	);
	$decimal_handlers = array(
		'field' => array(
			'handler' => 'views_handler_field_numeric',
			'click sortable' => TRUE,
		),
		'filter' => array('handler' => 'views_handler_filter_numeric'),
		'sort' => array('handler' => 'views_handler_sort'),
		'argument' => array('handler' => 'views_handler_argument_numeric'),
	);
	$float_handlers = array(
		'field' => array(
			'handler' => 'views_handler_field_numeric',
			'float' => TRUE,
			'click sortable' => TRUE,
		),
		'filter' => array('handler' => 'views_handler_filter_numeric'),
		'sort' => array('handler' => 'views_handler_sort'),
		'argument' => array('handler' => 'views_handler_argument_numeric'),
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
		'field' => array(
			'handler' => 'eve_api_views_handler_field_datetime',
			'click sortable' => TRUE,
		),
		'filter' => array('handler' => 'eve_api_views_handler_filter_datetime'),
		'sort' => array('handler' => 'views_handler_sort'),
		'argument' => array('handler' => 'views_handler_argument'),
	);
	$bool_handlers = array(
		'field' => array(
			'handler' => 'views_handler_field_boolean',
			'click sortable' => TRUE,
		),
		'filter' => array(
			'handler' => 'views_handler_filter_boolean_operator',
		//	'label' => '', The label needs to be defined in each field separately.
			'accept null' => TRUE,
			'use equal' => TRUE,
		),
		'sort' => array('handler' => 'views_handler_sort'),
		'argument' => array('handler' => 'views_handler_argument'),
	);

	$character_group = t('EVE API Character');
	
	// *** eve_api_skill_tree_groups table ***
	$data['eve_api_skill_tree_groups']['table']['group'] = t('EVE API Skills');

	$field_data = array(
		'title' => t('Skill Group ID'),
		'help' => t('Unique ID of the skill group.'),
	);
	$data['eve_api_skill_tree_groups']['groupID'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Skill Group Name'),
		'help' => t('Name of the skill group.'),
	);
	$data['eve_api_skill_tree_groups']['groupName'] = array_merge($string_handlers, $field_data);

	// *** eve_api_skill_tree table ***
	$data['eve_api_skill_tree']['table']['group'] = t('EVE API Skills');

	$field_data = array(
		'title' => t('Skill Type ID'),
		'help' => t('Unique ID of the skill.'),
	);
	$data['eve_api_skill_tree']['typeID'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Skill Name'),
		'help' => t('Type name of the skill.'),
	);
	$data['eve_api_skill_tree']['typeName'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Skill Group'),
		'help' => t('Group to which the skill belongs.'),
		'relationship' => array(
			'handler' => 'views_handler_relationship',
			'label' => t('Skill Group'),
			'base' => 'eve_api_skill_tree_groups',
			'base field' => 'groupID',
		),
	);
	$data['eve_api_skill_tree']['groupID'] = $field_data;
	
	// *** eve_api_characters table ***
	$data['eve_api_characters']['table']['group'] = $character_group;
	$data['eve_api_characters']['table']['base'] = array(
		'field' => 'characterID',
		'title' => t('EVE Characters'),
		'help' => t('EVE Online characters.'),
		'weight' => 10,
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
			'label' => t('User'),
			'base' => 'users',
			'base field' => 'uid',
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

	$field_data = array(
		'title' => t('Deleted'),
		'help' => t('Indicates that the character was no longer available during the last API pull.'),
	);
	$data['eve_api_characters']['deleted'] = array_merge($bool_handlers, $field_data);
	$data['eve_api_characters']['deleted']['filter']['label'] = t('Deleted');

	// *** eve_api_keys table ***
	$data['eve_api_keys']['table']['group'] = t('EVE API');
	$data['eve_api_keys']['table']['join']['user'] = array (
		'left_field' => 'uid',
		'field' => 'uid',
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
	$data['eve_api_character_info']['table']['group'] = $character_group;
	$data['eve_api_character_info']['table']['join']['eve_api_characters'] = array (
		'left_field' => 'characterID',
		'field' => 'characterID',
	);
	// Skipping the following fields as they are obtained from /account/APIKeyInfo.xml.aspx:
	// characterID, characterName, corporationID, corporation, allianceID, alliance

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
	$data['eve_api_character_info']['accountBalance'] = array_merge($float_handlers, $field_data);

	$field_data = array(
		'title' => t('Total Skill Points'),
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
	
	// *** eve_api_character_info_corporation_history table ***
	$data['eve_api_character_info_corporation_history']['table']['group'] = t('EVE API Employment History');
	$data['eve_api_character_info_corporation_history']['table']['join']['eve_api_characters'] = array (
		'left_field' => 'characterID',
		'field' => 'characterID',
	);
/*
	$data['eve_api_character_info_corporation_history']['table']['base'] = array(
		'field' => 'characterID',
		'title' => t('EVE Character Employment History'),
		'help' => t('Employment history of EVE Online characters.'),
		'weight' => 10,
	);
	$field_data = array(
		'title' => t('Character'),
		'help' => t('Unique ID of EVE Online character.'),
		'relationship' => array(
			'handler' => 'views_handler_relationship',
			'label' => t('Character'),
			'base' => 'eve_api_characters',
			'base field' => 'characterID',
		),
	);
	$data['eve_api_character_info_corporation_history']['characterID'] = array_merge($id_handlers, $field_data);
*/
	$field_data = array(
		'title' => t('Corporation ID'),
		'help' => t('ID of the corporation to which the character belonged at certain point.'),
	);
	$data['eve_api_character_info_corporation_history']['corporationID'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Corporation Join Date'),
		'help' => t('Date when the character joined each corporation.'),
	);
	$data['eve_api_character_info_corporation_history']['startDate'] = array_merge($date_handlers, $field_data);

		// *** eve_api_character_sheet table ***
	$data['eve_api_character_sheet']['table']['group'] = $character_group;
	$data['eve_api_character_sheet']['table']['join']['eve_api_characters'] = array (
		'left_field' => 'characterID',
		'field' => 'characterID',
	);
	// Skipping the following fields as they are obtained from other tables:
	// characterID, name, corporationID, corporationName, allianceID, allianceName, race, bloodLine, balance

	$field_data = array(
		'title' => t('Date of Birth'),
		'help' => t('When the character was created.'),
	);
	$data['eve_api_character_sheet']['DoB'] = array_merge($date_handlers, $field_data);

	$field_data = array(
		'title' => t('Ancestry'),
		'help' => t('Ancestry of the character.'),
	);
	$data['eve_api_character_sheet']['ancestry'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Gender'),
		'help' => t('Gender of the character.'),
	);
	$data['eve_api_character_sheet']['gender'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Faction ID'),
		'help' => t('ID of the faction to which the character belongs.'),
	);
	$data['eve_api_character_sheet']['factionID'] = array_merge($id_handlers, $field_data);
	
	$field_data = array(
		'title' => t('Faction Name'),
		'help' => t('Name of the faction to which the character belongs.'),
	);
	$data['eve_api_character_sheet']['factionName'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Clone Name'),
		'help' => t('Grade of the clone of the character.'),
	);
	$data['eve_api_character_sheet']['cloneName'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Clone Skill Points'),
		'help' => t('Number of skill points the current clone can hold.'),
	);
	$data['eve_api_character_sheet']['cloneSkillPoints'] = array_merge($decimal_handlers, $field_data);

	$field_data = array(
		'title' => t('Intelligence'),
		'help' => t('Current value of the attribute.'),
	);
	$data['eve_api_character_sheet']['intelligence'] = array_merge($decimal_handlers, $field_data);

	$field_data = array(
		'title' => t('Memory'),
		'help' => t('Current value of the attribute.'),
	);
	$data['eve_api_character_sheet']['memory'] = array_merge($decimal_handlers, $field_data);

	$field_data = array(
		'title' => t('Charisma'),
		'help' => t('Current value of the attribute.'),
	);
	$data['eve_api_character_sheet']['charisma'] = array_merge($decimal_handlers, $field_data);

	$field_data = array(
		'title' => t('Perception'),
		'help' => t('Current value of the attribute.'),
	);
	$data['eve_api_character_sheet']['perception'] = array_merge($decimal_handlers, $field_data);

	$field_data = array(
		'title' => t('Willpower'),
		'help' => t('Current value of the attribute.'),
	);
	$data['eve_api_character_sheet']['willpower'] = array_merge($decimal_handlers, $field_data);

	$field_data = array(
		'title' => t('Character Sheet Error Code'),
		'help' => t('Status of the last pull of /char/CharacterSheet.xml.aspx.'),
		'group' => t('EVE API Errors'),
	);
	$data['eve_api_character_sheet']['errorCode'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Character Sheet Error Text'),
		'help' => t('Error message returned during last pull of /char/CharacterSheet.xml.aspx.'),
		'group' => t('EVE API Errors'),
	);
	$data['eve_api_character_sheet']['errorText'] = array_merge($string_handlers, $field_data);

		// *** eve_api_character_sheet_attribute_enhancers table ***
	$data['eve_api_character_sheet_attribute_enhancers']['table']['group'] = t('EVE API Character Implants');
	$data['eve_api_character_sheet_attribute_enhancers']['table']['join']['eve_api_characters'] = array (
		'left_field' => 'characterID',
		'field' => 'characterID',
	);

	$field_data = array(
		'title' => t('Bonus Name'),
		'help' => t('Name of the attribute receiving the implant bonus.'),
	);
	$data['eve_api_character_sheet_attribute_enhancers']['bonusName'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Augmentator Name'),
		'help' => t('Name of the implant or booster giving the bonus.'),
	);
	$data['eve_api_character_sheet_attribute_enhancers']['augmentatorName'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Augmentator Value'),
		'help' => t('Value of the implant or booster bonus.'),
	);
	$data['eve_api_character_sheet_attribute_enhancers']['augmentatorValue'] = array_merge($decimal_handlers, $field_data);

		// *** eve_api_character_sheet_roles table ***
	$data['eve_api_character_sheet_roles']['table']['group'] = t('EVE API Character Roles');
	$data['eve_api_character_sheet_roles']['table']['join']['eve_api_characters'] = array (
		'left_field' => 'characterID',
		'field' => 'characterID',
	);

	$field_data = array(
		'title' => t('Role Type'),
		'help' => t('Type of role granted to the character.'),
	);
	$data['eve_api_character_sheet_roles']['type'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Role ID'),
		'help' => t('ID of role granted to the character.'),
	);
	$data['eve_api_character_sheet_roles']['roleID'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Role Name'),
		'help' => t('Name of role granted to the character.'),
	);
	$data['eve_api_character_sheet_roles']['roleName'] = array_merge($string_handlers, $field_data);

		// *** eve_api_character_sheet_skills table ***
	$data['eve_api_character_sheet_skills']['table']['group'] = t('EVE API Skills');
	$data['eve_api_character_sheet_skills']['table']['base'] = array(
		'field' => 'characterID',
		'title' => t('EVE Character Skills'),
		'help' => t('Skills learned by EVE Online characters.'),
		'weight' => 10,
	);

	$field_data = array(
		'title' => t('Character'),
		'help' => t('EVE Online character.'),
		'relationship' => array(
			'handler' => 'views_handler_relationship',
			'label' => t('Character'),
			'base' => 'eve_api_characters',
			'base field' => 'characterID',
		),
	);
	$data['eve_api_character_sheet_skills']['characterID'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Skill'),
		'help' => t('Skill the character has trained.'),
		'relationship' => array(
			'handler' => 'views_handler_relationship',
			'label' => t('Skill'),
			'base' => 'eve_api_skill_tree',
			'base field' => 'typeID',
		),
	);
	$data['eve_api_character_sheet_skills']['typeID'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Skill Points'),
		'help' => t('Total skill points put into this skill by the character.'),
	);
	$data['eve_api_character_sheet_skills']['skillpoints'] = array_merge($decimal_handlers, $field_data);

	$field_data = array(
		'title' => t('Skill Level'),
		'help' => t('Level of the skill attained by the character.'),
	);
	$data['eve_api_character_sheet_skills']['level'] = array_merge($decimal_handlers, $field_data);

	$field_data = array(
		'title' => t('Skill Published'),
		'help' => t('If the skill is published or not.'),
	);
	$data['eve_api_character_sheet_skills']['published'] = array_merge($bool_handlers, $field_data);

	// *** eve_api_character_sheet_titles table ***
	$data['eve_api_character_sheet_titles']['table']['group'] = t('EVE API Character Titles');
	$data['eve_api_character_sheet_titles']['table']['join']['eve_api_characters'] = array (
		'left_field' => 'characterID',
		'field' => 'characterID',
	);

	$field_data = array(
		'title' => t('Title ID'),
		'help' => t('ID of the title.'),
	);
	$data['eve_api_skill_titles']['titleID'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Title Name'),
		'help' => t('Name of the title given to the character.'),
	);
	$data['eve_api_skill_titles']['titleName'] = array_merge($string_handlers, $field_data);

	// *** eve_api_skill_in_training table ***
	$data['eve_api_skill_in_training']['table']['group'] = t('EVE API Skill Training');
	$data['eve_api_skill_in_training']['table']['join']['eve_api_characters'] = array (
		'left_field' => 'characterID',
		'field' => 'characterID',
	);

	$field_data = array(
		'title' => t('Tranquility Time'),
		'help' => t('Time of the skill in training data refresh.'),
	);
	$data['eve_api_skill_in_training']['currentTQTime'] = array_merge($date_handlers, $field_data);

	$field_data = array(
		'title' => t('Training End Time'),
		'help' => t('Date and time when the training will be completed.'),
	);
	$data['eve_api_skill_in_training']['trainingEndTime'] = array_merge($date_handlers, $field_data);

	$field_data = array(
		'title' => t('Training Start Time'),
		'help' => t('Date and time when the training was started.'),
	);
	$data['eve_api_skill_in_training']['trainingStartTime'] = array_merge($date_handlers, $field_data);

	$field_data = array(
		'title' => t('Skill in Training'),
		'help' => t('Skill the character is training.'),
		'relationship' => array(
			'handler' => 'views_handler_relationship',
			'label' => t('Training'),
			'base' => 'eve_api_skill_tree',
			'base field' => 'typeID',
		),
	);
	$data['eve_api_skill_in_training']['trainingTypeID'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Training Start SP'),
		'help' => t('Skill points of the skill when the training started.'),
	);
	$data['eve_api_skill_in_training']['trainingStartSP'] = array_merge($decimal_handlers, $field_data);

	$field_data = array(
		'title' => t('Training Destination SP'),
		'help' => t('Skill points of the skill when the training ends.'),
	);
	$data['eve_api_skill_in_training']['trainingDestinationSP'] = array_merge($decimal_handlers, $field_data);

	$field_data = array(
		'title' => t('Training To Level'),
		'help' => t('Level of the skill being trained.'),
	);
	$data['eve_api_skill_in_training']['trainingToLevel'] = array_merge($decimal_handlers, $field_data);

	$field_data = array(
		'title' => t('Is Training'),
		'help' => t('Indicates if the character is training.'),
	);
	$data['eve_api_skill_in_training']['skillInTraining'] = array_merge($bool_handlers, $field_data);

	$field_data = array(
		'title' => t('Skill in Training Error Code'),
		'help' => t('Status of the last pull of /char/SkillInTraining.xml.aspx.'),
		'group' => t('EVE API Errors'),
	);
	$data['eve_api_character_sheet']['errorCode'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Skill in Training Error Text'),
		'help' => t('Error message returned during last pull of /char/SkillInTraining.xml.aspx.'),
		'group' => t('EVE API Errors'),
	);
	$data['eve_api_character_sheet']['errorText'] = array_merge($string_handlers, $field_data);

	// *** eve_api_mail_messages table ***
	$data['eve_api_mail_messages']['table']['group'] = t('EVE API Mail');
	$data['eve_api_mail_messages']['table']['base'] = array(
		'field' => 'messageID',
		'title' => t('EVE Mail Messages'),
		'help' => t('EVE mail messages available in registered API keys.'),
		'weight' => 10,
	);

	$field_data = array(
		'title' => t('Recipient'),
		'help' => t('Character receiving the mails.'),
		'relationship' => array(
			'handler' => 'views_handler_relationship',
			'label' => t('Recipient'),
			'base' => 'eve_api_characters',
			'base field' => 'characterID',
		),
	);
	$data['eve_api_mail_messages']['characterID'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Sender ID'),
		'help' => t('Character ID or mailing list ID of the message originator.'),
	);
	$data['eve_api_mail_messages']['senderID'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('Sender Name'),
		'help' => t('Name of the sender.'),
	);
	$data['eve_api_mail_messages']['senderName'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Sent Date'),
		'help' => t('Date the message was sent.'),
	);
	$data['eve_api_mail_messages']['sentDate'] = array_merge($date_handlers, $field_data);

	$field_data = array(
		'title' => t('Title'),
		'help' => t('Title of the message.'),
	);
	$data['eve_api_mail_messages']['title'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('To Corp or Alliance ID'),
		'help' => t('ID of the corporation or alliance receiving the message.'),
	);
	$data['eve_api_mail_messages']['toCorpOrAllianceID'] = array_merge($id_handlers, $field_data);

	$field_data = array(
		'title' => t('To Character ID'),
		'help' => t('Comma-separated list of character IDs receiving the message.'),
	);
	$data['eve_api_mail_messages']['toCharacterIDs'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('To List ID'),
		'help' => t('Comma-separated list of mailing list IDs receiving the message.'),
	);
	$data['eve_api_mail_messages']['toListID'] = array_merge($string_handlers, $field_data);

	$field_data = array(
		'title' => t('Sender Type ID'),
		'help' => t('Type ID of the character or mailing list sending the message.'),
	);
	$data['eve_api_mail_messages']['senderTypeID'] = array_merge($string_handlers, $field_data);

	// *** eve_api_mail_message_bodies table ***
	$data['eve_api_mail_bodies']['table']['group'] = t('EVE API Mail');
	$data['eve_api_mail_bodies']['table']['join']['eve_api_mail_messages'] = array (
		'left_field' => 'messageID',
		'field' => 'messageID',
	);

	$field_data = array(
		'title' => t('Message'),
		'help' => t('Contents of the message.'),
	);
	$data['eve_api_mail_bodies']['message'] = array_merge($string_handlers, $field_data);

	return $data;
}
