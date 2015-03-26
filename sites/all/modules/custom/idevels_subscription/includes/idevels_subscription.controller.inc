<?php
/**
 * @file
 * Contain SubscriptionController class.
 */

class SubscriptionController extends EntityAPIController {

  /**
   * Reload of contstruct method.
   */
  public function __construct() {
    parent::__construct('subscription');
  }

  /**
   * Create clear subscription entry.
   */
  public function create(array $values = array()) {
    $clear_values = array(
      'name' => NULL,
      'price' => NULL,
      'updated' => NULL,
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
