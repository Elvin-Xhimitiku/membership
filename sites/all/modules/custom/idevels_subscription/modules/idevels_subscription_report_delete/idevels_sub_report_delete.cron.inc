<?php
/**
 * @file
 * Contain cron callbacks.
 */

/**
 * Cron callback for add items to queue.
 */
function idevels_sub_report_delete_add_items_cron_callback() {
  $items = array();
  $old_time = idevels_sub_report_get_old_time();

  $entities = array('pick_view', 'id_user_sessions');

  foreach ($entities as $key => $entity) {
    $query = new EntityFieldQuery();
    $query
      ->entityCondition('entity_type', $entity)
      ->propertyCondition('time', $old_time, '<=');
    $result = $query->execute();
    if (isset($result[$entity])) {
      $items[$entity] = array();
      foreach ($result[$entity] as $data) {
        $items[$entity][] = $data->rid;
      }
    }
  }
  if (!empty($items)) {
    $queue = DrupalQueue::get('idevelsSubReportsRemove');
    $queue->createQueue();
    $queue->createItem($items);
  }
}
