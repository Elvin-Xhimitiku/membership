<?php
/**
 * @file
 * Views controller class for subscription entity.
 */

class IdevelsSubscriptionAccessViewsController extends EntityDefaultViewsController {

  /**
   * Edit or add extra fields to views_data().
   */
  public function views_data() {
    $data = parent::views_data();

    $fields = &$data['subscription_access'];

    // Adding handlers for uid field.
    $fields['uid']['field']['handler'] = 'views_handler_field_user';
    $fields['uid']['filter']['handler'] = 'views_handler_filter_user_name';
    $fields['uid']['argument']['handler'] = 'views_handler_argument_numeric';
    $fields['uid']['relationship'] = array(
      'title' => t('Subscription access account'),
      'help' => t('Relate content to the user who has subscription access.'),
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('Subscription access user'),
    );

    // Add if relationship for sid field.
    $fields['sid']['relationship'] = array(
      'title' => t('Subscription entity'),
      'help' => t('Reference to subscription entity.'),
      'handler' => 'views_handler_relationship',
      'base' => 'subscription',
      'field' => 'sid',
      'label' => t('Subscription entity'),
    );

    // Adding handlers for date fields.
    $date_fields = array('start_date', 'end_date');
    foreach ($date_fields as $key => $field_name) {
      $fields[$field_name]['field']['handler'] = 'views_handler_field_date';
      $fields[$field_name]['sort']['handler'] = 'views_handler_sort_date';
      $fields[$field_name]['filter']['handler'] = 'views_handler_filter_date';
    }

    // Filter handler for status.
    $fields['status']['filter'] = array(
      'handler' => 'idevels_subscription_access_handler_filter_boolean_operator',
      'label' => t('Subscription access status'),
      'type' => 'active-inactive',
      'use equal' => TRUE,
      // Use status = 1 instead of status <> 0 in WHERE statment.
    );
    $fields['status']['field']['handler'] = 'idevels_subscription_access_status_handler_field';

    return $data;
  }
}
