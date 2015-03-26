<?php
/**
 * @file
 * Contains cron callback functions.
 */

/**
 * Callback function for deactivate free subscriptions.
 */
function idevels_sub_acs_check_all_cron_callback() {
  $query = new EntityFieldQuery();
  $query
    ->entityCondition('entity_type', 'subscription_access')
    ->propertyCondition('sid', IDEVELS_SUBSCRIPTION_NODE_TYPE_SID, '<>')
    ->propertyCondition('status', IDEVELS_SUBSCRIPTION_ACCESS_ACTIVE)
    ->propertyCondition('end_date', REQUEST_TIME, '<=');
  $result = $query->execute();
  if (isset($result['subscription_access'])) {
    $ids = array_keys($result['subscription_access']);
    $subscriptions_access = entity_load('subscription_access', $ids);
    foreach ($subscriptions_access as $said => $subscription_access) {
      $subscription_access->setInactive();
      $recipient = user_load($subscription_access->uid);
      rules_invoke_event('idevels_sub_acs_subscr_became_inactive', $subscription_access, $recipient);
    }
  }
}
