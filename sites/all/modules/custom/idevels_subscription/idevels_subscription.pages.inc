<?php
/**
 * @file
 * Contain functions.
 */

/**
 * Function for subscription view page.
 */
function idevels_subscription_view_page($subscription) {
  $output = array();

  // Price section.
  $output['price'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('subsription-price-wrapp'),
    ),
  );
  $output['price']['label'] = array(
    '#theme' => 'html_tag',
    '#tag' => 'span',
    '#value' => t('Price'),
    '#attributes' => array(
      'class' => array('subsription-field-label'),
    ),
  );
  $output['price']['value'] = array(
    '#theme' => 'html_tag',
    '#tag' => 'span',
    '#value' => (int) $subscription->price,
    '#attributes' => array(
      'class' => array('subsription-field-value'),
    ),
  );
  $output['price']['currency'] = array(
    '#theme' => 'html_tag',
    '#tag' => 'span',
    '#value' => commerce_default_currency(),
    '#attributes' => array(
      'class' => array('subsription-field-currency'),
    ),
  );

  // Description secion.
  $output['description'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('description-buy-wrapp'),
    ),
  );
  $output['description']['value']['#markup'] = nl2br($subscription->description);

  // Buy section.
  $output['buy'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('subsription-buy-wrapp'),
    ),
  );
  $output['buy']['link_button'] = array(
    '#theme' => 'link',
    '#text' => t('Buy this plan'),
    '#path' => '<front>',
    '#options' => array(
      'html' => FALSE,
      'attributes' => array(),
    ),
  );
  return $output;
}

/**
 * Subscription create page.
 */
function idevels_subscription_create_page_form($form, &$form_state) {
  $form = array();

  $form['type'] = array(
    '#type' => 'select',
    '#title' => t('Plan type'),
    '#options' => array(
      IDEVELS_SUBSCRIPTION_REGULAR => t('Regular'),
      IDEVELS_SUBSCRIPTION_STANDART => t('Standart'),
      IDEVELS_SUBSCRIPTION_PREMIUM => t('Premium'),
    ),
    '#required' => TRUE,
  );

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#required' => TRUE,
    '#description' => t('For example, you can write "Regular"'),
  );

  $categories = idevels_subscription_get_categories();
  $options = array();
  foreach ($categories as $term) {
    $options[$term->tid] = $term->name;
  }
  $form['category'] = array(
    '#type' => 'select',
    '#title' => t('Category'),
    '#options' => $options,
    '#required' => TRUE,
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#rows' => 4,
    '#title' => t('Description'),
  );
  $form['price'] = array(
    '#type' => 'textfield',
    '#title' => t('Price'),
    '#required' => TRUE,
    '#suffix' => '<span>' . commerce_default_currency() . '</span>',
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => 'admin/structure/plans',
  );

  return $form;
}

/**
 * Validation for create subscription form.
 */
function idevels_subscription_create_page_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  $type = $values['type'];
  if (!ctype_digit($values['price'])) {
    form_set_error('price', t('Price shoud be a numeric.'));
  }
  elseif ($values['price'] < 1) {
    form_set_error('price', t('Price value should be by positive number.'));
  }
  elseif ($sid = idevels_subscription_check_subscription($type, $values['category'])) {
    $sub = subscription_load($sid);
    form_set_error('', t('We already have a plan with this category. (Plan: !subscription)', array(
      '!subscription' => l($sub->name, "subscription/{$sub->sid}"),
    )));
  }
}

/**
 * Submit for create subscription form.
 */
function idevels_subscription_create_page_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $controller = entity_get_controller('subscription');
  $subscription = $controller->create(array(
    'name' => check_plain($values['name']),
    'price' => (int) $values['price'],
    'updated' => REQUEST_TIME,
    'category' => (int) $values['category'],
    'type' => (int) $values['type'],
  ));
  if ($status = $controller->save($subscription)) {
    $form_state['storage']['#subscription'] = $subscription;
    drupal_set_message(t('New plan was created.'));
    $form_state['redirect'] = "subscription/{$subscription->sid}";
  }
  else {
    drupal_set_message(t('An illegal choice has been detected. Please contact the site administrator.'), 'error');
  }
}

/**
 * Subscription edit page.
 */
function idevels_subscription_edit_page_form($form, &$form_state, $subscription) {
  $form = array();

  drupal_set_title(idevels_subscription_title_callback($subscription, 'edit'));

  $form['#subscription'] = $subscription;

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#required' => TRUE,
    '#default_value' => check_plain($subscription->name),
  );

  $categories = idevels_subscription_get_categories();
  $options = array();
  foreach ($categories as $term) {
    $options[$term->tid] = $term->name;
  }
  $form['category'] = array(
    '#type' => 'select',
    '#title' => t('Category'),
    '#options' => $options,
    '#required' => TRUE,
    '#default_value' => $subscription->category,
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#rows' => 4,
    '#title' => t('Description'),
    '#default_value' => check_plain($subscription->description),
  );
  $form['price'] = array(
    '#type' => 'textfield',
    '#title' => t('Price'),
    '#required' => TRUE,
    '#default_value' => check_plain($subscription->price),
    '#suffix' => '<span>' . commerce_default_currency() . '</span>',
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => "subscription/{$subscription->sid}",
  );

  return $form;
}

/**
 * Validate for edit subscription form.
 */
function idevels_subscription_edit_page_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  $subscription = $form['#subscription'];
  if (!ctype_digit($values['price'])) {
    form_set_error('price', t('Price shoud be a numeric.'));
  }
  elseif ($values['price'] < 1) {
    form_set_error('price', t('Price value should be by positive number.'));
  }
  elseif ($sid = idevels_subscription_check_subscription($subscription->type, $values['category'])) {
    $sub = subscription_load($sid);
    form_set_error('', t('We already have a plan with this category. (Plan: !subscription)', array(
      '!subscription' => l($sub->name, "subscription/{$sub->sid}"),
    )));
  }
}

/**
 * Submit for edit subscription form.
 */
function idevels_subscription_edit_page_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $subscription = $form['#subscription'];
  $wrapper = entity_metadata_wrapper('subscription', $subscription);
  $fields = array('name', 'description', 'price', 'category');
  foreach ($fields as $field) {
    $wrapper->{$field} = check_plain($values[$field]);
  }
  if ($wrapper->save()) {
    $form_state['redirect'] = "subscription/{$subscription->sid}";
    drupal_set_message(t('Subscription has been saved.'));
  }
}
