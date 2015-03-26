<?php
/**
 * @file
 * idevels_email_notify.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function idevels_email_notify_default_rules_configuration() {
  $items = array();
  $items['rules_idevels_send_e_mail_when_users_plan_expires'] = entity_import('rules_config', '{ "rules_idevels_send_e_mail_when_users_plan_expires" : {
      "LABEL" : "Idevels send e-mail when users plan expires",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "mimemail", "idevels_subscription_access" ],
      "ON" : { "idevels_sub_acs_subscr_became_inactive" : [] },
      "DO" : [
        { "mimemail" : {
            "key" : [ "users-plan:said" ],
            "to" : "[author:mail]",
            "subject" : "Membership subscription in expired",
            "body" : "\\u003Ch2\\u003EYour membership subscription is expired\\u003C\\/h2\\u003E",
            "plaintext" : "Your membership subscription is expired",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_new_pick_notification'] = entity_import('rules_config', '{ "rules_new_pick_notification" : {
      "LABEL" : "New pick notification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Email Notification" ],
      "REQUIRES" : [
        "rules",
        "rules_conditional",
        "mimemail",
        "idevels_subscription_access"
      ],
      "ON" : { "node_insert--pick" : { "bundle" : "pick" } },
      "IF" : [ { "node_is_published" : { "node" : [ "node" ] } } ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "user",
              "property" : "status",
              "value" : "1",
              "limit" : [ "" ]
            },
            "PROVIDE" : { "entity_fetched" : { "users_list_1" : "Users list" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "users-list-1" ] },
            "ITEM" : { "user_item" : "User item" },
            "DO" : [
              { "CONDITIONAL" : [
                  {
                    "IF" : { "NOT user_has_role" : {
                        "account" : [ "user-item" ],
                        "roles" : { "value" : { "1" : "1", "3" : "3", "4" : "4" } },
                        "operation" : "OR"
                      }
                    },
                    "DO" : [
                      { "CONDITIONAL" : [
                          {
                            "IF" : { "data_is" : { "data" : [ "user-item:field-enable-e-mails" ], "value" : "1" } },
                            "DO" : [
                              { "CONDITIONAL" : [
                                  {
                                    "IF" : { "idevels_sub_acs_has_access_pick" : { "pick" : [ "node" ], "account" : [ "user-item" ] } },
                                    "DO" : [
                                      { "mimemail" : {
                                          "key" : "e-mail-[node:nid]",
                                          "to" : "[user-item:mail]",
                                          "from_mail" : "[site:mail]",
                                          "subject" : "New pick was posted on [site:name]",
                                          "body" : "\\u003Ch3\\u003ENew pick was posted on [site:url]:\\u003C\\/h3\\u003E\\r\\n\\u003Ci\\u003E[node:url]\\u003C\\/i\\u003E\\r\\nPlease visit our site.",
                                          "plaintext" : "New pick was posted on [site:url]:\\r\\n[node:url]\\r\\nPlease visit our site.",
                                          "language" : [ "" ]
                                        }
                                      }
                                    ]
                                  }
                                ]
                              }
                            ]
                          }
                        ]
                      }
                    ]
                  }
                ]
              }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
