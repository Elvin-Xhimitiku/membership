<?php
/**
 * @file
 * Contain rules hooks.
 */

/**
 * Implements hook_rules_event_info().
 */
function idevels_subscription_access_rules_event_info() {
  $events = array(
    'idevels_sub_acs_subscr_became_inactive' => array(
      'label' => t('User subscription became inactive'),
      'group' => t('Idevels events'),
      'variables' => array(
        'users_plan' => array(
          'type' => 'subscription_access',
          'label' => t('Users plan'),
        ),
        'author' => array(
          'type' => 'user',
          'label' => t('Buyer of the plan'),
        ),
      ),
    ),
  );
  return $events;
}

/**
 * Imlements hook_rules_action_info().
 */
function idevels_subscription_access_rules_action_info() {
  $actions = array(
    'idevels_sub_acs_free_action' => array(
      'label' => t('Set free plan to user'),
      'group' => t('IDevels'),
      'parameter' => array(
        'account' => array(
          'type' => 'user',
          'label' => t('User'),
          'description' => t('The user whose free plan should be set.'),
          'save' => TRUE,
        ),
      ),
    ),
  );
  return $actions;
}

/**
 * Action callback for set free subscription after registration.
 */
function idevels_sub_acs_free_action($account) {
  $class = new SubscriptionAccessClass($account);
  $free_sub = $class->getFreeSubscription();
  if (empty($free_sub)) {
    $class->setFreePlan();
  }
}

/**
 * Implements hook_rules_condition_info().
 */
function idevels_subscription_access_rules_condition_info() {
  return array(
    'idevels_sub_acs_has_access_pick' => array(
      'label' => t('User has access to pick'),
      'group' => t('Node'),
      'parameter' => array(
        'pick' => array('type' => 'node', 'label' => t('Node Pick')),
        'account' => array('type' => 'user', 'label' => t('User')),
      ),
    ),
  );
}

/**
 * Access callback for 'idevels_sub_acs_has_access_pick' rule condition.
 */
function idevels_sub_acs_has_access_pick($pick, $account) {
  return idevels_sa_pick_check($pick, $account);
}
