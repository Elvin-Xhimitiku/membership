<?php
/**
 * @file
 * Contains IdUserSessions class.
 */

/**
 * IdUserSessions class.
 */
class IdUserSessions extends Entity {

  /**
   * Constructor.
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'id_user_sessions');
  }
}
