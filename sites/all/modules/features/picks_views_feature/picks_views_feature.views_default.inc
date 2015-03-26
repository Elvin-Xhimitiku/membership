<?php
/**
 * @file
 * picks_views_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function picks_views_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'picks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Picks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User picks';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_pick_category' => 'field_pick_category',
    'field_pick_plan' => 'field_pick_plan',
    'field_buy_separately' => 'field_buy_separately',
    'field_price' => 'field_price',
    'views_conditional' => 'views_conditional',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pick_category' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pick_plan' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_buy_separately' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_conditional' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'List is empty';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Pick category */
  $handler->display->display_options['fields']['field_pick_category']['id'] = 'field_pick_category';
  $handler->display->display_options['fields']['field_pick_category']['table'] = 'field_data_field_pick_category';
  $handler->display->display_options['fields']['field_pick_category']['field'] = 'field_pick_category';
  $handler->display->display_options['fields']['field_pick_category']['label'] = 'Category';
  $handler->display->display_options['fields']['field_pick_category']['empty'] = '-';
  $handler->display->display_options['fields']['field_pick_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_pick_category']['delta_offset'] = '0';
  /* Field: Content: Pick plan */
  $handler->display->display_options['fields']['field_pick_plan']['id'] = 'field_pick_plan';
  $handler->display->display_options['fields']['field_pick_plan']['table'] = 'field_data_field_pick_plan';
  $handler->display->display_options['fields']['field_pick_plan']['field'] = 'field_pick_plan';
  $handler->display->display_options['fields']['field_pick_plan']['label'] = 'Plan(s)';
  $handler->display->display_options['fields']['field_pick_plan']['empty'] = '-';
  $handler->display->display_options['fields']['field_pick_plan']['delta_offset'] = '0';
  /* Field: Content: Buy separately */
  $handler->display->display_options['fields']['field_buy_separately']['id'] = 'field_buy_separately';
  $handler->display->display_options['fields']['field_buy_separately']['table'] = 'field_data_field_buy_separately';
  $handler->display->display_options['fields']['field_buy_separately']['field'] = 'field_buy_separately';
  $handler->display->display_options['fields']['field_buy_separately']['label'] = '';
  $handler->display->display_options['fields']['field_buy_separately']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_buy_separately']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_buy_separately']['empty'] = '-';
  $handler->display->display_options['fields']['field_buy_separately']['type'] = 'list_key';
  /* Field: Content: Price */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['label'] = '';
  $handler->display->display_options['fields']['field_price']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'calculation' => FALSE,
  );
  $handler->display->display_options['fields']['field_price']['group_column'] = 'data';
  /* Field: Buy separatly field */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['ui_name'] = 'Buy separatly field';
  $handler->display->display_options['fields']['views_conditional']['label'] = 'Buy separately';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_buy_separately';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = '1';
  $handler->display->display_options['fields']['views_conditional']['then'] = 'yes ([field_price])';
  $handler->display->display_options['fields']['views_conditional']['or'] = 'no';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'pick' => 'pick',
  );
  /* Filter criterion: Content: Pick category (field_pick_category) */
  $handler->display->display_options['filters']['field_pick_category_tid']['id'] = 'field_pick_category_tid';
  $handler->display->display_options['filters']['field_pick_category_tid']['table'] = 'field_data_field_pick_category';
  $handler->display->display_options['filters']['field_pick_category_tid']['field'] = 'field_pick_category_tid';
  $handler->display->display_options['filters']['field_pick_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pick_category_tid']['expose']['operator_id'] = 'field_pick_category_tid_op';
  $handler->display->display_options['filters']['field_pick_category_tid']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_pick_category_tid']['expose']['operator'] = 'field_pick_category_tid_op';
  $handler->display->display_options['filters']['field_pick_category_tid']['expose']['identifier'] = 'field_pick_category_tid';
  $handler->display->display_options['filters']['field_pick_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_pick_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_pick_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_pick_category_tid']['vocabulary'] = 'pick_category';
  /* Filter criterion: Content: Pick plan (field_pick_plan) */
  $handler->display->display_options['filters']['field_pick_plan_value']['id'] = 'field_pick_plan_value';
  $handler->display->display_options['filters']['field_pick_plan_value']['table'] = 'field_data_field_pick_plan';
  $handler->display->display_options['filters']['field_pick_plan_value']['field'] = 'field_pick_plan_value';
  $handler->display->display_options['filters']['field_pick_plan_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pick_plan_value']['expose']['operator_id'] = 'field_pick_plan_value_op';
  $handler->display->display_options['filters']['field_pick_plan_value']['expose']['label'] = 'Plan';
  $handler->display->display_options['filters']['field_pick_plan_value']['expose']['operator'] = 'field_pick_plan_value_op';
  $handler->display->display_options['filters']['field_pick_plan_value']['expose']['identifier'] = 'field_pick_plan_value';
  $handler->display->display_options['filters']['field_pick_plan_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_pick_plan_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Buy separately (field_buy_separately) */
  $handler->display->display_options['filters']['field_buy_separately_value']['id'] = 'field_buy_separately_value';
  $handler->display->display_options['filters']['field_buy_separately_value']['table'] = 'field_data_field_buy_separately';
  $handler->display->display_options['filters']['field_buy_separately_value']['field'] = 'field_buy_separately_value';
  $handler->display->display_options['filters']['field_buy_separately_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_buy_separately_value']['expose']['operator_id'] = 'field_buy_separately_value_op';
  $handler->display->display_options['filters']['field_buy_separately_value']['expose']['label'] = 'Users can buy this pick separately?';
  $handler->display->display_options['filters']['field_buy_separately_value']['expose']['operator'] = 'field_buy_separately_value_op';
  $handler->display->display_options['filters']['field_buy_separately_value']['expose']['identifier'] = 'field_buy_separately_value';
  $handler->display->display_options['filters']['field_buy_separately_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'admin_page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['path'] = 'admin/structure/picks';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Picks';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'Picks';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: User picks */
  $handler = $view->new_display('page', 'User picks', 'page_user_picks');
  $handler->display->display_options['display_description'] = 'All picks available to user';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own commerce_order entities';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['path'] = 'user/%/picks';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Picks';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'Picks';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $export['picks'] = $view;

  return $export;
}
