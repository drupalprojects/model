<?php

/**
 * @file
 * Model editing UI.
 */

/**
 * UI controller.
 */
class ModelUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    
    $items[$this->path]['description'] = 'Manage models.';
    
    // Change the overview menu type for the list of models.
    $items[$this->basePath()]['type'] = MENU_LOCAL_TASK;
    
    // Change the add page menu to handle more types of entities
    $items[$this->basePath() . '/add']['title'] = 'Add a model';
    $items[$this->basePath() . '/add']['description'] = 'Add a new model';
    $items[$this->basePath() . '/add']['page callback']  = 'model_add_page';
    $items[$this->basePath() . '/add']['access callback']  = 'model_access';
    $items[$this->basePath() . '/add']['access arguments'] = array('edit');
    $items[$this->basePath() . '/add']['type'] = MENU_NORMAL_ITEM;
    $items[$this->basePath() . '/add']['weight'] = 20;
    unset($items[$this->basePath() . '/add']['title callback']);
    unset($items[$this->basePath() . '/add']['title arguments']);
    
    // Add menu items for each type of entity.
    foreach (model_get_types() as $type) {
      $items[$this->basePath() . '/add/' . $type->type] = array(
        'title' => 'Add ' . $type->type,
        'page callback' => 'model_form_wrapper',
        'page arguments' => array(model_create(array('type' => $type->type))),
        'access callback' => 'model_access',
        'access arguments' => array('edit', 'edit ' . $type->type),
        'file' => 'model.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module'])
      );
    }
    return $items;
  }
  
  /**
   * Gives us the base path on which to "hang" the entity functionality
   */ 
  protected function basePath() {
    return 'admin/content/models';
  }
  
  /**
   * Create the markup for the add Model Entities page within the class
   * so it can easily be extended/overriden.
   */ 
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }    
        
    return theme('model_add_list', array('content' => $content));
  }
  
}


/**
 * Form callback wrapper: create or edit a model.
 *
 * @param $model
 *   The model object being edited by this form.
 *
 * @see model_edit_form()
 */
function model_form_wrapper($model) {
  // Add the breadcrumb for the form's location.
  model_set_breadcrumb();

  return drupal_get_form('model_edit_form', $model);
}


/**
 * Form callback: create or edit a model.
 *
 * @param $model
 *   The model object to edit or for a create form an empty model object
 *     with only a model type defined.
 */
function model_edit_form($form, &$form_state, $model) {
  // Add the default field elements.
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Model Name'),
    //'#default_value' => $model->title,
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );
  
  $form['data']['#tree'] = TRUE;
  $form['data']['sample_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('An interesting model switch'),
    '#default_value' => 1,
  );

  // Add the field related form elements.
  $form_state['model'] = $model;
  field_attach_form('model', $model, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save model'),
    '#submit' => $submit + array('model_edit_form_submit'),
  );

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'model_edit_form_validate';
  return $form;
}

/**
 * Form API validate callback for the model form
 */
function model_edit_form_validate(&$form, &$form_state) {
  $model = $form_state['model'];
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('model', $model, $form, $form_state);
}

/**
 * Form API submit callback for the model form.
 */
function model_edit_form_submit(&$form, &$form_state) {
  
  $model = entity_ui_controller('model')->entityFormSubmitBuildEntity($form, $form_state);
  // Save and go back.
  $model->save();
  $form_state['redirect'] = 'admin/content/models';
}

/**
 * Form API submit callback for the delete button.
 */
function model_edit_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/models/manage/' . $form_state['model']->type . '/delete';
}


/**
 * Page to add Model Entities.
 *
 * @todo Pass this through a proper theme function
 */
function model_add_page() {
  $controller = entity_ui_controller('model');
  return $controller->addPage();
}


/**
 * Displays the list of available model types for model creation.
 *
 * @ingroup themeable
 */
function theme_model_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="model-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer model types')) {
      $output = '<p>' . t('You have not created any model types yet. Go to the <a href="@create-model-type">model type creation page</a> to add a new model type.', array('@create-model-type' => url('admin/structure/model_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No model types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}





/**
 * Sets the breadcrumb for administrative model pages.
 */
function model_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Models'), 'admin/content/models'),
  );

  drupal_set_breadcrumb($breadcrumb);
}



