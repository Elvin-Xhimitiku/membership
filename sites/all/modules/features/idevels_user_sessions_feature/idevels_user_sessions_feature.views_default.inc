<?php
/**
 * @file
 * idevels_user_sessions_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function idevels_user_sessions_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'user_sessions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'id_user_sessions';
  $view->human_name = 'User sessions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User sessions';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'uid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'time' => array(
      'bef_format' => 'bef_datepicker',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'time' => 'time',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Display users with last activity date.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'List is empty';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Idevels user sessions: User sessions account */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'id_user_sessions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'User';
  /* Relationship: User: Subscription access */
  $handler->display->display_options['relationships']['subscription_access']['id'] = 'subscription_access';
  $handler->display->display_options['relationships']['subscription_access']['table'] = 'users';
  $handler->display->display_options['relationships']['subscription_access']['field'] = 'subscription_access';
  $handler->display->display_options['relationships']['subscription_access']['relationship'] = 'uid';
  /* Relationship: Subscription access: Subscription entity */
  $handler->display->display_options['relationships']['sid']['id'] = 'sid';
  $handler->display->display_options['relationships']['sid']['table'] = 'subscription_access';
  $handler->display->display_options['relationships']['sid']['field'] = 'sid';
  $handler->display->display_options['relationships']['sid']['relationship'] = 'subscription_access';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'User name';
  $handler->display->display_options['fields']['name']['empty'] = 'unknown';
  /* Field: Idevels user sessions: Time */
  $handler->display->display_options['fields']['time']['id'] = 'time';
  $handler->display->display_options['fields']['time']['table'] = 'id_user_sessions';
  $handler->display->display_options['fields']['time']['field'] = 'time';
  $handler->display->display_options['fields']['time']['empty'] = 'unknown';
  $handler->display->display_options['fields']['time']['date_format'] = 'short';
  $handler->display->display_options['fields']['time']['second_date_format'] = 'long';
  /* Field: User: User plans */
  $handler->display->display_options['fields']['user_plans']['id'] = 'user_plans';
  $handler->display->display_options['fields']['user_plans']['table'] = 'users';
  $handler->display->display_options['fields']['user_plans']['field'] = 'user_plans';
  $handler->display->display_options['fields']['user_plans']['relationship'] = 'uid';
  $handler->display->display_options['fields']['user_plans']['empty'] = '-';
  /* Sort criterion: Idevels user sessions: Time */
  $handler->display->display_options['sorts']['time']['id'] = 'time';
  $handler->display->display_options['sorts']['time']['table'] = 'id_user_sessions';
  $handler->display->display_options['sorts']['time']['field'] = 'time';
  $handler->display->display_options['sorts']['time']['order'] = 'DESC';
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
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
  /* Filter criterion: Idevels user sessions: Time */
  $handler->display->display_options['filters']['time']['id'] = 'time';
  $handler->display->display_options['filters']['time']['table'] = 'id_user_sessions';
  $handler->display->display_options['filters']['time']['field'] = 'time';
  $handler->display->display_options['filters']['time']['operator'] = 'between';
  $handler->display->display_options['filters']['time']['exposed'] = TRUE;
  $handler->display->display_options['filters']['time']['expose']['operator_id'] = 'time_op';
  $handler->display->display_options['filters']['time']['expose']['label'] = 'Time between';
  $handler->display->display_options['filters']['time']['expose']['operator'] = 'time_op';
  $handler->display->display_options['filters']['time']['expose']['identifier'] = 'time';
  $handler->display->display_options['filters']['time']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['name_select']['expose']['label'] = 'Subscription';
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
  $handler->display->display_options['path'] = 'admin/structure/reports/user-sessions';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'User sessions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 1;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'user sessions';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['user_sessions'] = $view;

  return $export;
}
