<?php
/**
 * @file
 * pick_view_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pick_view_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'pick_view_reports';
  $view->description = 'Shows all reports when users review picks';
  $view->tag = 'default';
  $view->base_table = 'pick_view';
  $view->human_name = 'Pick view reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Pick view reports';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'title' => array(
      'bef_format' => 'default',
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
    'field_pick_plan_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
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
    'title' => 'title',
    'name' => 'name',
    'field_pick_plan' => 'field_pick_plan',
    'time' => 'time',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pick_plan' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'time' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'List is empty';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Idevels pick view: Subscription access account */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'pick_view';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Subscription access node';
  /* Relationship: Idevels pick view: Subscription access account */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'pick_view';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Node';
  $handler->display->display_options['fields']['title']['empty'] = '-';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['empty'] = '-';
  /* Field: Content: Pick plan */
  $handler->display->display_options['fields']['field_pick_plan']['id'] = 'field_pick_plan';
  $handler->display->display_options['fields']['field_pick_plan']['table'] = 'field_data_field_pick_plan';
  $handler->display->display_options['fields']['field_pick_plan']['field'] = 'field_pick_plan';
  $handler->display->display_options['fields']['field_pick_plan']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_pick_plan']['empty'] = '-';
  $handler->display->display_options['fields']['field_pick_plan']['delta_offset'] = '0';
  /* Field: Idevels pick view: Date */
  $handler->display->display_options['fields']['time']['id'] = 'time';
  $handler->display->display_options['fields']['time']['table'] = 'pick_view';
  $handler->display->display_options['fields']['time']['field'] = 'time';
  $handler->display->display_options['fields']['time']['empty'] = 'unknown';
  $handler->display->display_options['fields']['time']['date_format'] = 'short';
  $handler->display->display_options['fields']['time']['second_date_format'] = 'long';
  /* Sort criterion: Idevels pick view: Date */
  $handler->display->display_options['sorts']['time']['id'] = 'time';
  $handler->display->display_options['sorts']['time']['table'] = 'pick_view';
  $handler->display->display_options['sorts']['time']['field'] = 'time';
  $handler->display->display_options['sorts']['time']['order'] = 'DESC';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'nid';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Pick plan (field_pick_plan) */
  $handler->display->display_options['filters']['field_pick_plan_value']['id'] = 'field_pick_plan_value';
  $handler->display->display_options['filters']['field_pick_plan_value']['table'] = 'field_data_field_pick_plan';
  $handler->display->display_options['filters']['field_pick_plan_value']['field'] = 'field_pick_plan_value';
  $handler->display->display_options['filters']['field_pick_plan_value']['relationship'] = 'nid';
  $handler->display->display_options['filters']['field_pick_plan_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pick_plan_value']['expose']['operator_id'] = 'field_pick_plan_value_op';
  $handler->display->display_options['filters']['field_pick_plan_value']['expose']['label'] = 'Pick plan';
  $handler->display->display_options['filters']['field_pick_plan_value']['expose']['operator'] = 'field_pick_plan_value_op';
  $handler->display->display_options['filters']['field_pick_plan_value']['expose']['identifier'] = 'field_pick_plan_value';
  $handler->display->display_options['filters']['field_pick_plan_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_pick_plan_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_pick_plan_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Idevels pick view: Date */
  $handler->display->display_options['filters']['time']['id'] = 'time';
  $handler->display->display_options['filters']['time']['table'] = 'pick_view';
  $handler->display->display_options['filters']['time']['field'] = 'time';
  $handler->display->display_options['filters']['time']['operator'] = 'between';
  $handler->display->display_options['filters']['time']['exposed'] = TRUE;
  $handler->display->display_options['filters']['time']['expose']['operator_id'] = 'time_op';
  $handler->display->display_options['filters']['time']['expose']['label'] = 'Date between';
  $handler->display->display_options['filters']['time']['expose']['operator'] = 'time_op';
  $handler->display->display_options['filters']['time']['expose']['identifier'] = 'time';
  $handler->display->display_options['filters']['time']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/structure/reports/admin-reports';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Pick view reports';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Admin reports';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['pick_view_reports'] = $view;

  return $export;
}
