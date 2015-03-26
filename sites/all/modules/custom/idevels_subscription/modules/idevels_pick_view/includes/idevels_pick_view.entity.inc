<?php
/**
 * @file
 * Contain PickView class.
 */

class PickView extends Entity {
  public function __construct(array $values = array()) {
    parent::__construct($values, 'pick_view');
  }
}
