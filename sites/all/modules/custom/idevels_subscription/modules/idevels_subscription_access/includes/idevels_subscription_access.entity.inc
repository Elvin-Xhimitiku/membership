<?php
/**
 * @file
 * Contain Subscription class.
 */

class SubscriptionAccess extends Entity {

  /**
   * Construct for entity.
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'subscription_access');
  }

  /**
   * Method for unactivate subscription access.
   */
  public function setInactive() {
    $this->status = IDEVELS_SUBSCRIPTION_ACCESS_UNACTIVE;
    $this->save();
  }

}
