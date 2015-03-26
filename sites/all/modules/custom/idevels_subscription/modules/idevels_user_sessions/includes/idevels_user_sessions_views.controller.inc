<?php
/**
 * @file
 * Views controller class for user_sessions entity.
 */

/**
 * IdUserSessionsViewsController class.
 */
class IdUserSessionsViewsController extends EntityDefaultViewsController {

  public function views_data() {
    $data = parent::views_data();
    $fields = &$data['id_user_sessions'];

    // Adding handlers for uid field.
    $fields['uid']['field']['handler'] = 'views_handler_field_user';
    $fields['uid']['filter']['handler'] = 'views_handler_filter_user_name';
    $fields['uid']['argument']['handler'] = 'views_handler_argument_numeric';
    $fields['uid']['relationship'] = array(
      'title' => t('User sessions account'),
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('Logging out user'),
    );

    // Adding handlers for a time field.
    $fields['time']['title'] = t('Time');
    $fields['time']['help'] = t('Time of entity creation');
    $fields['time']['field']['handler'] = 'views_handler_field_date';
    $fields['time']['field']['click sortable'] = TRUE;
    $fields['time']['sort']['handler'] = 'views_handler_sort_date';
    $fields['time']['filter']['handler'] = 'views_handler_filter_date';

    return $data;
  }
}
