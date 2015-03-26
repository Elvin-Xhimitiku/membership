<?php
/**
 * @file
 * Contains IdUserSessionsController class.
 */

/**
 * IdUserSessionsController class.
 */
class IdUserSessionsController extends EntityApiController {

  /**
   * Reload of contstruct method.
   */
  public function __construct() {
    parent::__construct('id_user_sessions');
  }

  /**
   * Create clear id_user_sessions entry.
   */
  public function create(array $values = array()) {
    $clear_values = array(
      'uid' => NULL,
      'time' => REQUEST_TIME,
    );
    return parent::create(array_merge($clear_values, $values));
  }

  /**
   * Method to save entry.
   */
  public function save($entity) {
    try {
      db_merge('id_user_sessions')
        ->key(array('uid' => $entity->uid))
        ->fields(array(
          'uid' => $entity->uid,
          'time' => $entity->time,
        ))
        ->execute();
    }
    catch (Ecxeption $e) {
      throw new Exception('Unable to write log of');
    }
  }
}
