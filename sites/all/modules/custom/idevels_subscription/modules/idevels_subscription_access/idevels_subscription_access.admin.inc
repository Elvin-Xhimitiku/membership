<?php
/**
 * @file
 * Contain admin functions.
 */

/**
 * Callback for admin config page.
 */
function idevels_subscription_access_access_config_page($form, &$form_state) {
  $form = array();
  $instances = field_info_instances('node', IDEVELS_SUBSCRIPTION_CONTENT_TYPE);
  foreach ($instances as $key => $value) {
    $options[$key] = $value['label'];
  }
  $form['idevels_sub_access_fields_view'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Pick fields accesses'),
    '#options' => $options,
    '#default_value' => variable_get('idevels_sub_access_fields_view', array()),
    '#description' => t('Please, select fields which will open after pay.'),
  );
  return system_settings_form($form);
}
