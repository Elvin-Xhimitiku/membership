<?php
/**
 * @file
 * idevels_email_notify.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function idevels_email_notify_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_enable_e_mails'
  $field_bases['field_enable_e_mails'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_enable_e_mails',
    'field_permissions' => array(
      'type' => 2,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
