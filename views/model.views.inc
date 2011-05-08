<?php

/**
 * Views for the default models UI.
 */


/**
 * Implements hook_views_default_views().
 */
function model_views_default_views() {
  $views = array();
  
  $view = new view;
  $view->name = 'models';
  $view->description = 'A list of all models';
  $view->tag = 'models';
  $view->base_table = 'model';
  $view->human_name = 'Models';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Models';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create any model type';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'model_id' => 'model_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'model_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty ';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No models have been created yet';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'model';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['model_id']['id'] = 'model_id';
  $handler->display->display_options['fields']['model_id']['table'] = 'model';
  $handler->display->display_options['fields']['model_id']['field'] = 'model_id';
  $handler->display->display_options['fields']['model_id']['label'] = 'Model ID';
  $handler->display->display_options['fields']['model_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['model_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['model_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['model_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['model_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['model_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['model_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['model_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['model_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['model_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['model_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['model_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['model_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['model_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['model_id']['empty_zero'] = 0;
  /* Field: : field_test */
  $handler->display->display_options['fields']['field_test']['id'] = 'field_test';
  $handler->display->display_options['fields']['field_test']['table'] = 'field_data_field_test';
  $handler->display->display_options['fields']['field_test']['field'] = 'field_test';
  $handler->display->display_options['fields']['field_test']['label'] = 'Test';
  $handler->display->display_options['fields']['field_test']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_test']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_test']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_test']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_test']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_test']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_test']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_test']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_test']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_test']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_test']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_test']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_test']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_test']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_test']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_test']['field_api_classes'] = 0;
  
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'models_admin_page');
  $handler->display->display_options['path'] = 'admin/content/models/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Models';
  $handler->display->display_options['tab_options']['description'] = 'Manage models';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['models'] = array(
    t('Master'),
    t('Models'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Empty'),
    t('No models have been created yet'),
    t('Name'),
    t('Model ID'),
    t('Test'),
    t('Page'),
  );

  $views[$view->name] = $view;

  return $views;

}
