<?php

/**
 * @file
 * Providing extra functionality for the Model UI via views.
 */


/**
 * Implements hook_views_data()
 */
function model_views_data_alter(&$data) { 
  $data['model']['link_model'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the model.'),
      'handler' => 'model_handler_link_field',
    ),
  );
  $data['model']['edit_model'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the model.'),
      'handler' => 'model_handler_edit_link_field',
    ),
  );
  $data['model']['delete_model'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the model.'),
      'handler' => 'model_handler_delete_link_field',
    ),
  );
  // This content of this field are decided based on the menu structure that
  // follows models/model/%model_id/op
  $data['model']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this model.'),
      'handler' => 'model_handler_model_operations_field',
    ),
  );
}


/**
 * Implements hook_views_default_views().
 */
function model_views_default_views() {
  $view = new view();
  $view->name = 'models';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'model';
  $view->human_name = 'Models';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'model_id' => 'model_id',
    'name' => 'name',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'model_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Model: Model ID */
  $handler->display->display_options['fields']['model_id']['id'] = 'model_id';
  $handler->display->display_options['fields']['model_id']['table'] = 'model';
  $handler->display->display_options['fields']['model_id']['field'] = 'model_id';
  /* Field: Model: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'model';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Model: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'model';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'models_view_page');
  $handler->display->display_options['path'] = 'admin/content/models/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Models';
  $handler->display->display_options['menu']['description'] = 'Manage Models';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Models';
  $handler->display->display_options['tab_options']['description'] = 'Manage models';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $views[$view->name] = $view;
  return $views;

}
