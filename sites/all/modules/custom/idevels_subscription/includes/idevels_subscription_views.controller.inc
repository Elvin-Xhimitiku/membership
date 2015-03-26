<?php
/**
 * @file
 * Views controller class for subscription entity.
 */

class IdevelsSubscriptionViewsController extends EntityDefaultViewsController {

  /**
   * Edit or add extra fields to views_data().
   */
  public function views_data() {
    $data = parent::views_data();

    $data['subscription']['category']['field']['handler'] = 'idevels_subscription_category_handler_field';
    return $data;
  }
}
