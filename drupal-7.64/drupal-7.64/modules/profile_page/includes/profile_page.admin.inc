<?php

function profile_page_settings() {
	return drupal_get_form('profile_page_settings_form');
}

function profile_page_settings_form($form, &$form_state) {
	$form['somemarkup'] = array(
		'#markup' => t("Nothing here yet"),
	);
	
	return system_settings_form($form);
}

function profile_page_settings_form_submit($form, &$form_state) {

}