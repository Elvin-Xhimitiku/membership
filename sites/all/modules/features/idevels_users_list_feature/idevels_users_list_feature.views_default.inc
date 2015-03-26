<?php
/**
 * @file
 * idevels_users_list_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function idevels_users_list_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'idevels_users_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Users list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Users list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'List is empty';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: User: Subscription access */
  $handler->display->display_options['relationships']['subscription_access']['id'] = 'subscription_access';
  $handler->display->display_options['relationships']['subscription_access']['table'] = 'users';
  $handler->display->display_options['relationships']['subscription_access']['field'] = 'subscription_access';
  /* Relationship: Subscription access: Subscription entity */
  $handler->display->display_options['relationships']['sid']['id'] = 'sid';
  $handler->display->display_options['relationships']['sid']['table'] = 'subscription_access';
  $handler->display->display_options['relationships']['sid']['field'] = 'sid';
  $handler->display->display_options['relationships']['sid']['relationship'] = 'subscription_access';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'User name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['empty'] = 'unknown';
  /* Field: User: User plans */
  $handler->display->display_options['fields']['user_plans']['id'] = 'user_plans';
  $handler->display->display_options['fields']['user_plans']['table'] = 'users';
  $handler->display->display_options['fields']['user_plans']['field'] = 'user_plans';
  $handler->display->display_options['fields']['user_plans']['empty'] = 'no plans';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'User name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Subscription plan: User plans select */
  $handler->display->display_options['filters']['name_select']['id'] = 'name_select';
  $handler->display->display_options['filters']['name_select']['table'] = 'subscription';
  $handler->display->display_options['filters']['name_select']['field'] = 'name_select';
  $handler->display->display_options['filters']['name_select']['relationship'] = 'sid';
  $handler->display->display_options['filters']['name_select']['value'] = 'All';
  $handler->display->display_options['filters']['name_select']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name_select']['expose']['operator_id'] = 'name_select_op';
  $handler->display->display_options['filters']['name_select']['expose']['label'] = 'User plans select';
  $handler->display->display_options['filters']['name_select']['expose']['operator'] = 'name_select_op';
  $handler->display->display_options['filters']['name_select']['expose']['identifier'] = 'name_select';
  $handler->display->display_options['filters']['name_select']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/structure/reports/users-list';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Users list';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['idevels_users_list'] = $view;

  return $export;
}
