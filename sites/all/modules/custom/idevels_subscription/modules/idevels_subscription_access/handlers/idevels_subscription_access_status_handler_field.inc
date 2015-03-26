<?php
/**
 * @file
 * Contain idevels_subscription_access_status_handler_field class.
 */

/**
 * idevels_subscription_access_status_handler_field handler.
 */
class idevels_subscription_access_status_handler_field extends views_handler_field {

  function render($values) {
    $status = $this->get_value($values);
    if (!empty($status)) {
      return t('Active');
    }
    return t('Inactive');
  }

}
