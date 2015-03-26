<?php
/**
 * @file
 * idevels_email_notify.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function idevels_email_notify_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_enable_e_mails'.
  $permissions['create field_enable_e_mails'] = array(
    'name' => 'create field_enable_e_mails',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_enable_e_mails'.
  $permissions['edit field_enable_e_mails'] = array(
    'name' => 'edit field_enable_e_mails',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_enable_e_mails'.
  $permissions['edit own field_enable_e_mails'] = array(
    'name' => 'edit own field_enable_e_mails',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_enable_e_mails'.
  $permissions['view field_enable_e_mails'] = array(
    'name' => 'view field_enable_e_mails',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_enable_e_mails'.
  $permissions['view own field_enable_e_mails'] = array(
    'name' => 'view own field_enable_e_mails',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
