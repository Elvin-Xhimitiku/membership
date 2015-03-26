<?php

/**
 * @file
 * Contains idevels_sc_handler_order_product_node class.
 */

/**
 * idevels_sc_handler_order_product_node handler.
 */
class idevels_sc_handler_order_product_node extends views_handler_field {

  /**
   * Render function.
   */
  public function render($values) {
    $line_item = field_get_items('commerce_order', $values->_field_data['order_id']['entity'], 'commerce_line_items');
    $item = commerce_line_item_load($line_item[0]['line_item_id']);
    if (isset($item->data['context']['entity']) && !empty($item->data['context']['entity'])) {
      $order_entity = $item->data['context']['entity'];
      if ($order_entity['entity_type'] == 'node') {
        $node = node_load($order_entity['entity_id']);
        return t('Pick: !node_title', array('!node_title' => l(($node->title), 'node/' . $node->nid)));
      }
    }
    if (!empty($item->data['context']['product_ids'])) {
      $product = commerce_product_load($item->data['context']['product_ids'][0]);
      return $product->title;
    }
    return '';
  }
}
