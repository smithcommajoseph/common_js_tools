<?php
// $Id: common_js_tools.lib.inc $

/**
 * Check our chosen Directories for js Libs 
 */
function _common_js_tools_path($lib) {
  $jspath = FALSE;
  $module_path = drupal_get_path('module', 'common_js_tools');
  
  //check module /js dir for libs
  if (file_exists($module_path . '/js/'.$lib.'.js')) {
    $jspath = $module_path.'/js';
  }
  //check libraries for libs
  elseif (file_exists('sites/all/libraries/common_js_tools/'.$lib.'.js')) {
    $jspath = 'sites/all/libraries/common_js_tools';
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