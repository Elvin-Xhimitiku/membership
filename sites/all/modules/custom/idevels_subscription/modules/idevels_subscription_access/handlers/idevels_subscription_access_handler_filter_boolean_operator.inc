<?php
/**
 * @file
 * Contain idevels_subscription_access_handler_filter_boolean_operator class.
 */


/**
 * idevels_subscription_access_handler_filter_boolean_operator handler.
 */
class idevels_subscription_access_handler_filter_boolean_operator extends views_handler_filter_boolean_operator {

  public function get_value_options() {
    if (isset($this->definition['type'])) {
      if ($this->definition['type'] == 'active-inactive') {
        $this->value_options = array(
          1 => t('Active'),
          0 => t('Inactive'),
        );
      }
      else {
        parent::get_value_options();
      }
    }
  }
}
