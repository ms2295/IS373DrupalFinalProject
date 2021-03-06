<?php

/**
 * Callback to show any fields attached to the user
 */
function profile_page_profile_settings_form($form, $form_state, $account) {
	global $user;
	// Call some default variables we need everytime
  profile_page_default_settings($form, $form_state, $account);
	
	// Picture/avatar.
  $form['picture'] = array(
    '#prefix' => '<div id="profile-page-settings-profile-picture">',
		'#suffix' => '</div>',
    '#weight' => 1, 
    '#access' => (variable_get('user_pictures', 0)),
  );
  $form['picture']['picture'] = array(
    '#type' => 'value', 
    '#value' => isset($account->picture) ? $account->picture : NULL,
  );
  $form['picture']['picture_current'] = array(
    '#markup' => theme('user_picture', array('account' => $account)),
  );
  $form['picture']['picture_delete'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Delete picture'), 
    '#access' => !empty($account->picture->fid), 
    '#description' => t('Check this box to delete your current picture.'),
  );
  $form['picture']['picture_upload'] = array(
    '#type' => 'file', 
    '#title' => t('Upload picture'), 
    '#size' => 48, 
    '#description' => t('Your virtual face or picture. Pictures larger than @dimensions pixels will be scaled down.', array('@dimensions' => variable_get('user_picture_dimensions', '85x85'))) . ' ' . filter_xss_admin(variable_get('user_picture_guidelines', '')),
  );
  $form['#validate'][] = 'user_validate_picture';

	field_attach_form('user', $account, $form, $form_state);
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t("Save changes"),
		'#weight' => 100,
	);
	
	$form['#submit'][] = 'profile_page_default_settings_submit';

	return $form;
}

