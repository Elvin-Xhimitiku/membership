<?php
/**
 * @file
 * idevels_commerce_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function idevels_commerce_feature_default_rules_configuration() {
  $items = array();
  $items['rules_idevels_clear_the_cart'] = entity_import('rules_config', '{ "rules_idevels_clear_the_cart" : {
      "LABEL" : "Idevels clear the cart",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_cart" ],
      "ON" : { "commerce_cart_product_prepare" : [] },
      "DO" : [
        { "commerce_cart_empty" : { "commerce_order" : [ "commerce_order" ] } }
      ]
    }
  }');
  $items['rules_idevels_new_subscription_plan_created'] = entity_import('rules_config', '{ "rules_idevels_new_subscription_plan_created" : {
      "LABEL" : "Idevels new subscription plan created",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "idevels_subscription_commerce", "idevels_subscription" ],
      "ON" : { "subscription_insert" : [] },
      "DO" : [
        { "idevels_sc_create_product_for_subs_action" : { "subscription" : [ "subscription:sid" ] } }
      ]
    }
  }');
  $items['rules_idevels_redirect_to_checkout'] = entity_import('rules_config', '{ "rules_idevels_redirect_to_checkout" : {
      "LABEL" : "Idevels redirect to checkout",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_cart" ],
      "ON" : { "commerce_cart_product_add" : [] },
      "DO" : [ { "redirect" : { "url" : "checkout\\/[commerce-order:order-id]" } } ]
    }
  }');
  $items['rules_idevels_user_bought_a_plan'] = entity_import('rules_config', '{ "rules_idevels_user_bought_a_plan" : {
      "LABEL" : "Idevels user bought a plan",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "idevels_subscription_commerce", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "commerce-order:commerce-line-items:0:type" ],
            "value" : "product"
          }
        },
        { "text_matches" : {
            "text" : [ "commerce-order:commerce-line-items:0:commerce-product:sku" ],
            "match" : "^subscription\\\\-\\\\d+$",
            "operation" : "regex"
          }
        }
      ],
      "DO" : [
        { "idevels_sc_create_plan_action" : { "account" : [ "commerce-order:owner" ], "order" : [ "commerce-order" ] } }
      ]
    }
  }');
  $items['rules_idevels_user_has_been_deleted'] = entity_import('rules_config', '{ "rules_idevels_user_has_been_deleted" : {
      "LABEL" : "Idevels user has been deleted",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "idevels_subscription_commerce", "rules" ],
      "ON" : { "user_delete" : [] },
      "DO" : [
        { "idevels_sc_delete_user_subscriptions" : { "account" : [ "account" ] } }
      ]
    }
  }');
  return $items;
}
