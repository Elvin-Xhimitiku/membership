<?php
/**
 * @file
 * pick_view_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function pick_view_feature_default_rules_configuration() {
  $items = array();
  $items['rules_idevels_pick_view'] = entity_import('rules_config', '{ "rules_idevels_pick_view" : {
      "LABEL" : "Idevels pick view",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "pick_view" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_view--pick" : { "bundle" : "pick" } },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "2" : "2" } }
          }
        },
        { "NOT user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "3" : "3", "4" : "4" } }
          }
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "pick_view",
              "param_nid" : [ "node:nid" ],
              "param_uid" : [ "site:current-user:uid" ],
              "param_access" : "1"
            },
            "PROVIDE" : { "entity_created" : { "pick_view" : "Pick view" } }
          }
        },
        { "entity_save" : { "data" : [ "pick-view" ], "immediate" : "1" } }
      ]
    }
  }');
  return $items;
}
