<?php
/**
 * @file
 * idevels_referral_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function idevels_referral_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_referral_users'.
  $permissions['create field_referral_users'] = array(
    'name' => 'create field_referral_users',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_referral_users'.
  $permissions['edit field_referral_users'] = array(
    'name' => 'edit field_referral_users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_referral_users'.
  $permissions['edit own field_referral_users'] = array(
    'name' => 'edit own field_referral_users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_referral_users'.
  $permissions['view field_referral_users'] = array(
    'name' => 'view field_referral_users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_referral_users'.
  $permissions['view own field_referral_users'] = array(
    'name' => 'view own field_referral_users',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
