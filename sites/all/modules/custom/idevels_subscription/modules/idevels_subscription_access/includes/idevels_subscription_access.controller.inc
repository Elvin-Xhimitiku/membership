<?php
/**
 * @file
 * Contain SubscriptionController class.
 */

class SubscriptionAccessController extends EntityAPIController {

  /**
   * Reload of contstruct method.
   */
  public function __construct() {
    parent::__construct('subscription_access');
  }

  /**
   * Create clear subscription entry.
   */
  public function create(array $values = array()) {
    // @todo.
    $clear_values = array(
      'sid' => NULL,
      'uid' => NULL,
      'status' => 1,
      'start_date' => REQUEST_TIME,
      'end_date' => REQUEST_TIME,
      'order_id' => NULL,
      'nid' => NULL,
    );
    return parent::create(array_merge($clear_values, $values));
  }

  /**
   * Method to save entry.
   */
  public function save($sub) {
    return parent::save($sub);
  }
}
