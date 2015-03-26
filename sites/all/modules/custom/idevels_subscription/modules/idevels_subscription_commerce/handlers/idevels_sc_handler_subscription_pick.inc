<?php

/**
 * @file
 * Contains idevels_sc_handler_subscription_pick class.
 */

/**
 * idevels_sc_handler_subscription_pick handler.
 */
class idevels_sc_handler_subscription_pick extends views_handler_field {

  /**
   * Render function.
   */
  public function render($values) {
    $sid = $values->subscription_access_sid;
    if ($sid == IDEVELS_SUBSCRIPTION_NODE_TYPE_SID && $values->node_subscription_access_nid) {
      $node = node_load($values->node_subscription_access_nid);
      return t('Pick: !node_title', array('!node_title' => l(($node->title), 'node/' . $node->nid)));
    }
    elseif ($sid != IDEVELS_SUBSCRIPTION_NODE_TYPE_SID) {
      return $values->subscription_subscription_access_name;
    }
    return '';
  }
}
