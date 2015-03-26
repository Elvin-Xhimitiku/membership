<?php
/**
 * @file
 * pick_content_type_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pick_content_type_feature_taxonomy_default_vocabularies() {
  return array(
    'pick_category' => array(
      'name' => 'Pick category',
      'machine_name' => 'pick_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
