<?php

/**
 * @file handler to view.
 */

/**
 * Base class for area handlers.
 */
class views_subscription_ref_handler_area_referral extends views_handler_area {

  /**
   * Form of handler.
   */
  function options_form(&$form, &$form_state) {
    $form['referral_url'] = array(
      '#type' => 'markup',
      '#markup' => t('Here will be shown user\'s referral url'),
    );
  }

  /**
   * Rendering a result.
   */
  function render($empty = FALSE) {
    global $base_url;
    if (arg(0) == 'user' && is_numeric(arg(1))) {
      $current_user = user_load(arg(1));
    }
    $ref_url = $base_url . '/referral/' . idevels_sr_uid2ref($current_user->uid);
    $output = array(
      'label' => array(
        '#type' => 'markup',
        '#markup' => t('Your referral url:'),
      ),
      'referral_url' => array(
        '#type' => 'textarea',
        '#value' => $ref_url,
        '#rows' => 1,
        '#resizable' => FALSE,
        '#attributes' => array(
          'readonly' => 'readonly',
          'class' => array('referral-url-textarea'),
          'onclick' => 'this.focus();this.select()',
        ),
      ),
    );
    return drupal_render($output);
  }
}
