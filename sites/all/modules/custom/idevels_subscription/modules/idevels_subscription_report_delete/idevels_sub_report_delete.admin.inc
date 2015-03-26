<?php
/**
 * @file
 * Contain page callback for admin config page.
 */

/**
 * Page callback for admin settings form.
 */
function idevels_sub_report_delete_config_form($form, $form_state) {
  $form = array();
  $options = array();
  for ($i = 1; $i <= 12; $i++) {
    $options[$i] = t('@n month', array('@n' => $i));
  }
  $form['idevels_sub_report_delete_month'] = array(
    '#title' => t('Delete reports older then:'),
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => variable_get('idevels_sub_report_delete_month', 3),
    '#description' => t('Delete "Pick view" and "User sesstion" reports.'),
  );
  return system_settings_form($form);
}
