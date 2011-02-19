<?php
// $Id: common_js_tools.admin.inc $

/**
 * Administration page callbacks for the Common JS Tools module.
 */
include_once('./'. drupal_get_path('module', 'common_js_tools') .'/includes/common_js_tools.lib.inc');

/**
 * Menu callback.
 */
function common_js_tools_admin_settings() {
  $libs = common_js_tools_libs();
  
  $form['common_js_tools_use_min'] = array( 
    '#type' => 'radios', 
    '#title' => t('Which version of the library should we use?'), 
    '#options' => array(t('Development'), t('Minified')),
    '#default_value' => variable_get('common_js_tools_use_min', 0), 
    '#description' => t('Note: If you select Minified, Development will be used by default if no Minified version is available.')
  );  
  $form['libraries']['pre'] = array(
    '#value' => t('<div class="form-item"><label>Select the libraries you want to load. </label><table><thead><tr><th></th><th>Lib</th><th>Development</th><th>Minified</th></tr></thead><tbody>')
  );
  foreach($libs as $k => $v){
    $field_tmp = 'common_js_tools_'.str_replace('.','_',$k);
    $form['libraries'][$field_tmp] = array(
      '#prefix' => '<tr><td>',
      '#type' => 'checkbox', 
      '#default_value' => variable_get($field_tmp, 0),
      '#title' => t('</td><td>'.$v.'</td>'),
      '#suffix' => t('<td>'.(_common_js_tools_path($k) ? '<span style=\'color:green\'>available' : '<span style=\'color:red\'>not available').'</span></td><td>'.(_common_js_tools_path($k.'.min') ? '<span style=\'color:green\'>available' : '<span style=\'color:red\'>not available').'</span></td></tr>')
    );
  }
  $form['libraries']['post'] = array(
    '#value' => '</tbody></table></div>',
  );
  return system_settings_form($form);
}
