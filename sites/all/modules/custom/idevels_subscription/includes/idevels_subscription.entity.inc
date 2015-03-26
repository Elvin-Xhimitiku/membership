<?php
/**
 * @file
 * Contain Subscription class.
 */

class Subscription extends Entity {
  public function __construct(array $values = array()) {
    parent::__construct($values, 'subscription');
  }

  public function setName($name) {
    $this->name = $name;
  }
}
