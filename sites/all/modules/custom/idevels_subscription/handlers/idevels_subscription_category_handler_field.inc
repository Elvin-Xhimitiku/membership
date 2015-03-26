<?php
/**
 * @file
 * Contain idevels_subscription_category_handler_field class.
 */

/**
 * idevels_subscription_category_handler_field handler.
 */
class idevels_subscription_category_handler_field extends views_handler_field {

  function render($values) {
    $tid = $this->get_value($values);
    if (empty($tid)) {
      return NULL;
    }
    $term = taxonomy_term_load($tid);
    return $term->name;
  }
}
