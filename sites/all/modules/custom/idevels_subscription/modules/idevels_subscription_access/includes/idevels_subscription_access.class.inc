<?php
/**
 * @file
 * Contain SubscriptionAccess class and interfaces.
 */

class SubscriptionAccessClass implements
MainSubscriptionAccessInterface,
NodeSubscriptionAccessInterface,
AccountSubscriptionAccessInterface,
TimeSubscriptionAccessInterface {

  private $account;

  /**
   * Define a user account.
   */
  public function __construct($account) {
    $this->setAccount($account);
  }

  /**
   * Setter for $account.
   */
  public function setAccount($account) {
    $this->account = $account;
  }

  /**
   * Getter for $account.
   */
  public function getAccount() {
    return $this->account;
  }

  /**
   * Method for preapra FieldEntityQuery.
   */
  public function prepareFieldEntityQuery() {
    $query = new EntityFieldQuery();
    return $query->entityCondition('entity_type', 'subscription_access');
  }

  /**
   * Method for return result from FieldEntityQuery.
   */
  public function resultFieldEntityQuery($query) {
    $result = $query->execute();
    if (isset($result['subscription_access'])) {
      $ids = array_keys($result['subscription_access']);
      return entity_load('subscription_access', $ids);
    }
    return NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function getFreeSubscription() {
    $query = $this->prepareFieldEntityQuery()
    ->propertyCondition('uid', $this->account->uid)
    ->propertyCondition('sid', IDEVELS_SUBSCRIPTION_FREE_SID);
    return $this->resultFieldEntityQuery($query);
  }

  /**
   * {@inheritdoc}
   */
  public function getSubscriptionById($said) {
    $query = $this->prepareFieldEntityQuery()
    ->propertyCondition('uid', $this->account->uid)
    ->propertyCondition('said', $said);
    return $this->resultFieldEntityQuery($query);
  }

  /**
   * {@inheritdoc}
   */
  public function getSubscriptionByOrderId($order_id) {
    $query = $this->prepareFieldEntityQuery()
    ->propertyCondition('uid', $this->account->uid)
    ->propertyCondition('order_id', $said);
    return $this->resultFieldEntityQuery($query);
  }

  /**
   * {@inheritdoc}
   */
  public function getSubscriptions($status = NULL) {
    $query = $this->prepareFieldEntityQuery()
    ->propertyCondition('uid', $this->account->uid);
    if (isset($status)) {
      $query->propertyCondition('status', $status);
    }
    return $this->resultFieldEntityQuery($query);
  }

  /**
   * {@inheritdoc}
   */
  public function isSubscriptionActive(SubscriptionAccess $subscription) {
    return (bool) $subscription->status;
  }


  /**
   * {@inheritdoc}
   */
  public function getSubscriptionByNode($node_nid) {
    $query = new EntityFieldQuery();
    $query
    ->entityCondition('entity_type', 'subscription_access')
    ->propertyCondition('uid', $this->account->uid)
    ->propertyCondition('nid', $node_nid);
    $result = $query->execute();
    if (isset($result['subscription_access'])) {
      $ids = array_keys($result['subscription_access']);
      return entity_load('subscription_access', $ids);
    }
    return NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function setFreePlan() {
    $controller = entity_get_controller('subscription_access');
    $subscription_access = $controller->create(array(
      'sid' => IDEVELS_SUBSCRIPTION_FREE_SID,
      'uid' => $this->account->uid,
      'status' => IDEVELS_SUBSCRIPTION_ACCESS_ACTIVE,
      'start_date' => REQUEST_TIME,
      'end_date' => $this->getDatePlusMonth(REQUEST_TIME),
    ));
    if ($status = $controller->save($subscription_access)) {
      return TRUE;
    }
    else {
      throw new Exception('Unable to set free plan.');

    }
  }

  /**
   * {@inheritdoc}
   */
  public function getDatePlusMonth($time) {
    return strtotime('+1 month', $time);
  }

}


interface NodeSubscriptionAccessInterface {

  /**
   * Returns subscription access by node id.
   */
  public function getSubscriptionByNode($node_id);

}

interface MainSubscriptionAccessInterface {

  /**
   * Returns account free subscription access.
   */
  public function getFreeSubscription();

  /**
   * Return subscription by Subscription Access ID.
   */
  public function getSubscriptionById($said);

  /**
   * Return subscription by Order ID (commere).
   */
  public function getSubscriptionByOrderId($order_id);

  /**
   * Return subscription by status.
   *
   * @param mixed $status
   *   Status of subscription.
   *   1 - active, 0 - unactive or NULL for return all subscriptions.
   */
  public function getSubscriptions($status = NULL);

  /**
   * Check subscription is active.
   */
  public function isSubscriptionActive(SubscriptionAccess $subscription);

}

interface AccountSubscriptionAccessInterface {

  /**
   * Method for set free plan for user.
   */
  public function setFreePlan();

}

interface TimeSubscriptionAccessInterface {

  /**
   * Method for return unix timestamp with + 1 month.
   *
   * @param int $time
   *   Unix timestamp.
   */
  public function getDatePlusMonth($time);

}
