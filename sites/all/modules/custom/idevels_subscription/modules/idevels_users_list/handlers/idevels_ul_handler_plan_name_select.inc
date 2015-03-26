<?php
/**
 * @file
 * Definition of idevels_ul_handler_plan_name_select class.
 */

/**
 * Custom filter handler to make filter by plans as selectlist.
 */
class idevels_ul_handler_plan_name_select extends views_handler_filter_string {

  /**
   * Overloading value_form function only.
   */
  public function value_form(&$form, &$form_state) {

    $which = 'all';
    if (!empty($form['operator'])) {
      $source = ($form['operator']['#type'] == 'radios') ? 'radio:options[operator]' : 'edit-options-operator';
    }
    if (!empty($form_state['exposed'])) {
      $identifier = $this->options['expose']['identifier'];

      if (empty($this->options['expose']['use_operator']) || empty($this->options['expose']['operator_id'])) {
        // Exposed and locked.
        $which = in_array($this->operator, $this->operator_values(1)) ? 'value' : 'none';
      }
      else {
        $source = 'edit-' . drupal_html_id($this->options['expose']['operator_id']);
      }
    }

    if ($which == 'all' || $which == 'value') {
      $options = idevels_ul_get_subscription_names();
      $form['value'] = array(
        '#type' => 'select',
        '#title' => t('Value'),
        '#size' => 1,
        '#empty_option' => t('- All -'),
        '#empty_value' => 'All',
        '#default_value' => 'All',
        '#options' => $options,
      );
      if (!empty($form_state['exposed']) && !isset($form_state['input'][$identifier])) {
        $form_state['input'][$identifier] = $this->value;
      }

      if ($which == 'all') {
        $form['value'] += array(
          '#dependency' => array($source => $this->operator_values(1)),
        );
      }
    }

    if (!isset($form['value'])) {
      // Ensure there is something in the 'value'.
      $form['value'] = array(
        '#type' => 'value',
        '#value' => NULL,
      );
    }
  }
}
