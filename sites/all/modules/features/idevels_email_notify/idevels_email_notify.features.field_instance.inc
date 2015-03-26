<?php
/**
 * @file
 * idevels_email_notify.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function idevels_email_notify_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_enable_e_mails'
  $field_instances['user-user-field_enable_e_mails'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_enable_e_mails',
    'label' => 'Enable e-mails',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 52,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Enable e-mails');

  return $field_instances;
}
