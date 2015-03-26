<?php
/**
 * @file
 * pick_content_type_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function pick_content_type_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_buy_separately|node|pick|form';
  $field_group->group_name = 'group_buy_separately';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pick';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Buy separately',
    'weight' => '4',
    'children' => array(
      0 => 'field_buy_separately',
      1 => 'field_price',
      2 => 'field_pick_product',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Buy separately',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-buy-separately field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_buy_separately|node|pick|form'] = $field_group;

  return $export;
}
