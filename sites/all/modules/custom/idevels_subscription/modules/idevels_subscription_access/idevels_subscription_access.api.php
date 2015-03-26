<?php
/**
 * @file
 * Contain api of module.
 */

/**
 * Hook for provide custom access to pick.
 */
function hook_idevels_subscription_access_list() {
  return array(
    'access_name' => array(
      'title' => t('Access title'),
      'check callback' => 'check_function',
    ),
  );
}
