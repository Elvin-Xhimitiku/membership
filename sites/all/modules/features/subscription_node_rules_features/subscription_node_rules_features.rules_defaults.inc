<?php
/**
 * @file
 * subscription_node_rules_features.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function subscription_node_rules_features_default_rules_configuration() {
  $items = array();
  $items['rules_idevels_buy_pick_node_access'] = entity_import('rules_config', '{ "rules_idevels_buy_pick_node_access" : {
      "LABEL" : "Idevels buy pick node access",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "idevels_subscription_pick" ],
      "REQUIRES" : [ "rules", "idevels_subscription_node", "commerce_checkout" ],
      "ON" : { "commerce_checkout_complete" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "commerce-order:commerce-line-items:0:type" ],
            "value" : "product"
          }
        },
        { "text_matches" : {
            "text" : [ "commerce-order:commerce-line-items:0:commerce-product:sku" ],
            "match" : "^pick\\\\-\\\\d+$",
            "operation" : "regex"
          }
        }
      ],
      "DO" : [
        { "idevels_subscription_node_buy_action" : {
            "commerce_order" : [ "commerce_order" ],
            "product_sku" : [ "commerce-order:commerce-line-items:0:commerce-product:sku" ]
          }
        }
      ]
    }
  }');
  $items['rules_idevels_create_pick_product'] = entity_import('rules_config', '{ "rules_idevels_create_pick_product" : {
      "LABEL" : "Idevels create pick product",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "idevels_subscription_pick" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--pick" : { "bundle" : "pick" } },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "pick" : "pick" } } } },
        { "NOT data_is_empty" : { "data" : [ "node:field-price" ] } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "commerce_product",
              "param_sku" : "pick-[node:nid]",
              "param_type" : "product",
              "param_title" : "Pick: [node:title]",
              "param_creator" : [ "site:current-user" ],
              "param_commerce_price" : [ "node:field-price" ]
            },
            "PROVIDE" : { "entity_created" : { "commerce_product" : "Commerce product" } }
          }
        },
        { "entity_save" : { "data" : [ "commerce-product" ], "immediate" : "1" } },
        { "data_set" : {
            "data" : [ "node:field-pick-product" ],
            "value" : [ "commerce-product" ]
          }
        }
      ]
    }
  }');
  $items['rules_idevels_disable_product_after_delete_node'] = entity_import('rules_config', '{ "rules_idevels_disable_product_after_delete_node" : {
      "LABEL" : "Idevels disable product after delete node",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "idevels_subscription_pick" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_delete--pick" : { "bundle" : "pick" } },
      "IF" : [ { "NOT data_is_empty" : { "data" : [ "node:field-pick-product" ] } } ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : {
              "type" : "commerce_product",
              "id" : [ "node:field-pick-product:product-id" ],
              "revision_id" : [ "" ]
            },
            "PROVIDE" : { "entity_fetched" : { "commerce_product" : "Commerce product" } }
          }
        },
        { "data_set" : { "data" : [ "commerce-product:status" ], "value" : "0" } }
      ]
    }
  }');
  $items['rules_idevels_edit_disable_pick_product'] = entity_import('rules_config', '{ "rules_idevels_edit_disable_pick_product" : {
      "LABEL" : "Idevels edit disable pick product",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "idevels_subscription_pick" ],
      "REQUIRES" : [ "rules", "commerce" ],
      "ON" : { "node_update--pick" : { "bundle" : "pick" } },
      "IF" : [
        { "data_is_empty" : { "data" : [ "node:field-buy-separately" ] } },
        { "entity_exists" : {
            "type" : "commerce_product",
            "property" : "product_id",
            "value" : [ "node:field-pick-product:product-id" ]
          }
        }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_product",
              "property" : "product_id",
              "value" : [ "node:field-pick-product:product-id" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "commerce_product" : "Commerce product" } }
          }
        },
        { "data_set" : { "data" : [ "commerce-product:0:status" ], "value" : "0" } },
        { "entity_save" : { "data" : [ "commerce-product:0" ], "immediate" : "1" } }
      ]
    }
  }');
  $items['rules_idevels_edit_enable_pick_product'] = entity_import('rules_config', '{ "rules_idevels_edit_enable_pick_product" : {
      "LABEL" : "Idevels edit enable pick product",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "idevels_subscription_pick" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--pick" : { "bundle" : "pick" } },
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "node:field-buy-separately" ] } },
        { "data_is_empty" : { "data" : [ "node-unchanged:field-buy-separately" ] } }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : {
              "type" : "commerce_product",
              "id" : [ "node:field-pick-product:product-id" ]
            },
            "PROVIDE" : { "entity_fetched" : { "commerce_product" : "Commerce product" } }
          }
        },
        { "data_set" : { "data" : [ "commerce-product:status" ], "value" : "1" } }
      ]
    }
  }');
  $items['rules_idevels_edit_pick_create_product'] = entity_import('rules_config', '{ "rules_idevels_edit_pick_create_product" : {
      "LABEL" : "Idevels edit pick create product",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "idevels_subscription_pick" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--pick" : { "bundle" : "pick" } },
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "node:field-buy-separately" ] } },
        { "NOT data_is_empty" : { "data" : [ "node:field-price:amount" ] } },
        { "data_is_empty" : { "data" : [ "node:field-pick-product" ] } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "commerce_product",
              "param_sku" : "pick-[node:nid]",
              "param_type" : "product",
              "param_title" : "Pick: [node:title]",
              "param_creator" : [ "node:author" ],
              "param_commerce_price" : [ "node:field-price" ]
            },
            "PROVIDE" : { "entity_created" : { "commerce_product" : "Commerce product" } }
          }
        },
        { "entity_save" : { "data" : [ "commerce-product" ], "immediate" : "1" } },
        { "data_set" : {
            "data" : [ "node:field-pick-product" ],
            "value" : [ "commerce-product" ]
          }
        }
      ]
    }
  }');
  $items['rules_idevels_edit_pick_product'] = entity_import('rules_config', '{ "rules_idevels_edit_pick_product" : {
      "LABEL" : "Idevels edit price pick product",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "idevels_subscription_pick" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--pick" : { "bundle" : "pick" } },
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "node:field-price" ],
            "value" : [ "node:field-pick-product:commerce-price" ]
          }
        }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : {
              "type" : "commerce_product",
              "id" : [ "node:field-pick-product:product-id" ]
            },
            "PROVIDE" : { "entity_fetched" : { "commerce_product" : "Commerce product" } }
          }
        },
        { "data_set" : {
            "data" : [ "commerce-product:commerce-price:amount" ],
            "value" : [ "node:field-price:amount" ]
          }
        },
        { "entity_save" : { "data" : [ "commerce-product" ], "immediate" : "1" } }
      ]
    }
  }');
  return $items;
}
