<?php

/**
 * Callback to show any fields attached to the user
 */
function profile_page_openid_settings_form($account) {	
	include_once(drupal_get_path("module", "openid") . "/openid.pages.inc");
	return openid_user_identities($account);
}

