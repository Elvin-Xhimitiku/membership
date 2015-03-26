<?php
/**
 * @file
 * Views controller class for subscription entity.
 */

class PickViewViewsController extends EntityDefaultViewsController {

  /**
   * Edit or add extra fields to views_data().
   */
  public function views_data() {
    $data = parent::views_data();

    $fields = &$data['pick_view'];

    // Adding handlers for uid field.
    $fields['uid']['field']['handler'] = 'views_handler_field_user';
    $fields['uid']['filter']['handler'] = 'views_handler_filter_user_name';
    $fields['uid']['argument']['handler'] = 'views_handler_argument_numeric';
    $fields['uid']['relationship'] = array(
      'title' => t('Subscription access account'),
      // 'help' => t('Relate content to the user who has subscription access.'),
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('Subscription access user'),
    );

    // Adding handlers for nid field.
    $fields['nid']['field']['handler'] = 'views_handler_field_node';
    $fields['nid']['filter']['handler'] = 'views_handler_filter_numeric';
    $fields['nid']['argument']['handler'] = 'views_handler_argument_numeric';
    $fields['nid']['relationship'] = array(
      'title' => t('Subscription access account'),
      // 'help' => t('Relate content to the user who has subscription access.'),
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'field' => 'nid',
      'label' => t('Subscription access user'),
    );

    // Adding handlers for a time field.
    $fields['time']['title'] = t('Date');
    $fields['time']['help'] = t('Date of entity creation');
    $fields['time']['field']['handler'] = 'views_handler_field_date';
    $fields['time']['field']['click sortable'] = TRUE;
    $fields['time']['sort']['handler'] = 'views_handler_sort_date';
    $fields['time']['filter']['handler'] = 'views_handler_filter_date';

    return $data;
  }
}
