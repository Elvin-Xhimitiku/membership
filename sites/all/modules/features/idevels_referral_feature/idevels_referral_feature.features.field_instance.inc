<?php
/**
 * @file
 * idevels_referral_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function idevels_referral_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_referral_users'
  $field_instances['user-user-field_referral_users'] = array(
    'bundle' => 'user',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_referral_users',
    'label' => 'Referral users',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 51,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Referral users');

  return $field_instances;
}
