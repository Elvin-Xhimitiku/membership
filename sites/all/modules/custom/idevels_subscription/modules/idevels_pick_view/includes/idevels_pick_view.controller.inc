<?php
/**
 * @file
 * Contain PickViewController class.
 */

class PickViewController extends EntityAPIController {

  /**
   * Reload of contstruct method.
   */
  public function __construct() {
    parent::__construct('pick_view');
  }

  /**
   * Create clear pick_view entry.
   */
  public function create(array $values = array()) {
    $clear_values = array(
      'nid' => NULL,
      'uid' => NULL,
      'access' => NULL,
      'time' => REQUEST_TIME,
    );
    return parent::create(array_merge($clear_values, $values));
  }

  /**
   * Method to save entry.
   */
  public function save($entity) {
    return parent::save($entity);
  }
}
