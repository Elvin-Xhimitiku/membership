<?php
/**
 * @file
 * idevels_user_sessions_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function idevels_user_sessions_feature_default_rules_configuration() {
  $items = array();
  $items['rules_idevels_user_last_access'] = entity_import('rules_config', '{ "rules_idevels_user_last_access" : {
      "LABEL" : "Idevels user last access",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "init" : [] },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1", "3" : "3", "4" : "4" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : { "type" : "id_user_sessions", "param_uid" : [ "site:current-user:uid" ] },
            "PROVIDE" : { "entity_created" : { "entity_user_session" : "User session" } }
          }
        }
      ]
    }
  }');
  return $items;
}
