<?php
/**
 * @file
 * pick_content_type_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pick_content_type_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function pick_content_type_feature_node_info() {
  $items = array(
    'pick' => array(
      'name' => t('Pick'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
