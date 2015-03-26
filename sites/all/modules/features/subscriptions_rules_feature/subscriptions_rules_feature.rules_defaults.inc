<?php
/**
 * @file
 * subscriptions_rules_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function subscriptions_rules_feature_default_rules_configuration() {
  $items = array();
  $items['rules_idevels_set_free_subscription'] = entity_import('rules_config', '{ "rules_idevels_set_free_subscription" : {
      "LABEL" : "Idevels set free subscription",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "idevels_subscription_access" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "NOT user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } }
      ],
      "DO" : [ { "idevels_sub_acs_free_action" : { "account" : [ "account" ] } } ]
    }
  }');
  return $items;
}
