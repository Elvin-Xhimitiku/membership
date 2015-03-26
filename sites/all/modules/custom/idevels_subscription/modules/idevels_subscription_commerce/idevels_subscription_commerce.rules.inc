<?php
/**
 * @file
 * Contains rules hooks.
 */

/**
 * Imlements hook_rules_action_info().
 */
function idevels_subscription_commerce_rules_action_info() {
  $actions = array(
    'idevels_sc_create_plan_action' => array(
      'label' => t('Set bought plan to user'),
      'group' => t('IDevels'),
      'parameter' => array(
        'account' => array(
          'type' => 'user',
          'label' => t('User'),
          'description' => t('The user whose free plan should be set'),
          'save' => TRUE,
        ),
        'order' => array(
          'type' => 'commerce_order',
          'label' => t('Order'),
          'description' => t('Commerce order with bought subscription'),
        ),
      ),
    ),
    'idevels_sc_create_product_for_subs_action' => array(
      'label' => t('Create product for subscription plan and add to it'),
      'group' => t('IDevels'),
      'parameter' => array(
        'subscription' => array(
          'type' => 'integer',
          'label' => t('Subscription id'),
          'description' => t('The id of subscription creating'),
        ),
      ),
    ),
    'idevels_sc_delete_user_subscriptions' => array(
      'label' => t('Delete user subscriptions'),
      'group' => 'IDevels',
      'parameter' => array(
        'account' => array(
          'type' => 'user',
          'label' => t('User'),
          'description' => t('User who has these subscriptions'),
        ),
      ),
    ),
  );
  return $actions;
}

/**
 * Action callback for creation user's subscription.
 */
function idevels_sc_create_plan_action($account, $order) {
  $lang = field_language('commerce_order', $order, 'commerce_line_items');
  if (empty($order->commerce_line_items)) {
    return;
  }
  $line_item = commerce_line_item_load($order->commerce_line_items[$lang][0]['line_item_id']);
  $product = commerce_product_load($line_item->commerce_product[$lang][0]['product_id']);
  preg_match('/^subscription\-(\d+)$/', $product->sku, $sku);
  if (empty($sku[1]) || !ctype_digit($sku[1])) {
    drupal_set_message(t('An illegal choice has been detected. Please contact the site administrator.'), 'error');
    return;
  }
  $sid = $sku[1];
  $subscription = entity_load('subscription', array($sid));
  $controller = entity_get_controller('subscription_access');
  $subscription_access = $controller->create(array(
    'sid' => $subscription[$sid]->sid,
    'uid' => $account->uid,
    'status' => IDEVELS_SUBSCRIPTION_ACCESS_ACTIVE,
    'start_date' => REQUEST_TIME,
    'end_date' => idevels_sa_get_date_plus_month(REQUEST_TIME),
  ));
  if ($status = $controller->save($subscription_access)) {
    return TRUE;
  }
  else {
    throw new Exception('Unable to create new plan.');
  }
}

/**
 * Action callback for creating product after saving new subcription.
 */
function idevels_sc_create_product_for_subs_action($subscription_id) {
  $subscription = entity_load('subscription', array($subscription_id));
  idevels_sc_create_product($subscription[$subscription_id]);
}

/**
 * Action callback for deleting user's subscriptions after deleteing the user.
 */
function idevels_sc_delete_user_subscriptions($account) {
  $access = new SubscriptionAccessClass($account);
  $subs_accesses = $access->getSubscriptions();
  $saids = array();
  if (!empty($subs_accesses)) {
    foreach ($subs_accesses as $subs_access) {
      $saids[] = $subs_access->said;
    }
  }
  entity_delete_multiple('subscription_access', $saids);
}
