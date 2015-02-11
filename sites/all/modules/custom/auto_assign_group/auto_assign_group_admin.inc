<?php

/**
 * Setting form for Auto Assign Group.
 */
function auto_assign_config_form() {
  $groups = og_get_all_group();
  $options = array();
  foreach ($groups as $nid) {
    $group_name = node_load($nid)->title;
    $options[$nid] = $group_name;
  }

  $default_value = variable_get('default_groups');
  $form['default_groups'] = array(
    '#title' => t('All groups'),
    '#description' => t('Select groups user will be assigned into on registration.'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => isset($default_value) ? $default_value : '',
  );

  return system_settings_form($form);
}
