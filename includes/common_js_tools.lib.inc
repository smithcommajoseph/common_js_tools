<?php

function _common_js_tools_path($lib) {
  $jspath = FALSE;
  $module_path=drupal_get_path('module', 'common_js_tools');

  if (file_exists($module_path . '/js/'.$lib.'.js')) {
    $jspath='%m/js';
  }
  elseif (file_exists('sites/all/libraries/common_js_tools/'.$lib.'.js')) {
    $jspath='sites/all/libraries/common_js_tools';
  }
  return $jspath;
}

/**
 * Drupal's drupal_json() seems to douche this conversion, here's an alternative.
 */
function _common_js_tools_json($var = NULL) {
  // We are returning JavaScript, so tell the browser.
  drupal_set_header('Content-Type: text/javascript; charset=utf-8');
  if (isset($var)) {
    echo json_encode($var);
  }
}

function returnhi(){
  return 'hi';
}