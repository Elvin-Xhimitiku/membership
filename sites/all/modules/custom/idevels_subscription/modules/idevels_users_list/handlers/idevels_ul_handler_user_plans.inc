<?php
/**
 * @file
 * Custom handler fir view.
 */

/**
 * idevels_ul_handler_user_plans handler.
 */
class idevels_ul_handler_user_plans extends views_handler_field {

  /**
   * Render function.
   */
  public function render($values) {
    $value = $this->get_value($values);
    if (empty($value)) {
      return '';
    }
    $usr = user_load($value);
    $access = new SubscriptionAccessClass($usr);
    $subs_accesses = $access->getSubscriptions(IDEVELS_SUBSCRIPTION_ACCESS_ACTIVE);
    if (empty($subs_accesses)) {
      return '';
    }
    $user_plans = array();
    foreach ($subs_accesses as $sub_access) {
      $subscription = entity_load('subscription', array($sub_access->sid));
      foreach ($subscription as $sub) {
        // Do not render links to nodes.
        if ($sub->sid == IDEVELS_SUBSCRIPTION_NODE_TYPE_SID) {
          $user_plans[$sub->sid] = $sub->name;
          continue;
        }
        $user_plans[$sub->sid] = l($sub->name, "subscription/{$sub->sid}");
      }
    }
    return implode(', ', $user_plans);
  }
}
