<?php
/**
 * Custom filter handler for views, that handles DATETIME
 */
class eve_api_views_handler_filter_datetime extends views_handler_filter_date {
  
  function op_between($field) {
    $a = $this->value['min'];
    $b = $this->value['max'];

    if ($this->value['type'] == 'offset') {
      $a = intval(strtotime($this->value['min'], 0));
      $b = intval(strtotime($this->value['max'], 0));
      $a = (integer)time() + (integer)sprintf('%+d', $a); // keep sign
      $b = (integer)time() + (integer)sprintf('%+d', $b); // keep sign
      $a = date("Y-m-d H:i:s", $a);
      $b = date("Y-m-d H:i:s", $b);
    }
    $operator = strtoupper($this->operator);
    $this->query->add_where_expression($this->options['group'], "$field $operator '$a' AND '$b'");
  }
 
  function op_simple($field) {
    $value = $this->value['value'];
    if (!empty($this->value['type']) && $this->value['type'] == 'offset') {
      $value = intval(strtotime($this->value['value'], 0));
      var_dump($value."\n");
      $value = (integer)time() + (integer)sprintf('%+d', $value); // keep sign
      var_dump($value."\n");
      $value = date("Y-m-d H:i:s", $value);
      var_dump($value."\n");
    }
    $this->query->add_where_expression($this->options['group'], "$field $this->operator '$value'");
  }
}
