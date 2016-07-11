<?php

/**
 * @file
 * CSE shipping settings form
 */

function commerce_cse_settings_form() {
  $form = array();

  $form['api'] = array(
    '#type' => 'fieldset',
    '#title' => t('CSE API credentials'),
    '#collapsible' => true,
    '#description' => t('In order to obtain shipping rate estimates, you must have an account with CSE.'),
  );

  $form['api']['commerce_cse_account_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Account ID'),
    '#default_value' => variable_get('commerce_cse_account_id'),
    '#required' => true,
  );

  $form['api']['commerce_cse_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#default_value' => variable_get('commerce_cse_password'),
    '#required' => true,
  );

  $form['api']['commerce_cse_urgencie_code'] = array(
  '#type' => 'textfield',
    '#title' => t('Urgencie Code'),
    '#default_value' => variable_get('commerce_cse_urgencie_code'),
    '#required' => true,
  );

  $form['api']['commerce_cse_type_of_cargo_code'] = array(
  '#type' => 'textfield',
    '#title' => t('Type Of Cargo Code'),
    '#default_value' => variable_get('commerce_cse_type_of_cargo_code'),
    '#required' => true,
  );

  $form['api']['commerce_cse_service_region_delivery'] = array(
  '#type' => 'textfield',
    '#title' => t('Region delivery code'),
    '#default_value' => variable_get('commerce_cse_service_region_delivery'),
    '#required' => true,
  );

  $form['api']['commerce_cse_service_country_delivery'] = array(
  '#type' => 'textfield',
    '#title' => t('Country delivery code'),
    '#default_value' => variable_get('commerce_cse_service_country_delivery'),
    '#required' => true,
  );

  $form['api']['commerce_cse_local_delivery_code'] = array(
  '#type' => 'textfield',
    '#title' => t('Local Delivery Code'),
    '#default_value' => variable_get('commerce_cse_local_delivery_code'),
    '#required' => true,
  );

  $form['origin'] = array(
    '#type' => 'fieldset',
    '#title' => t('Ship From Address'),
    '#collapsible' => true,
  );

  $form['origin']['commerce_cse_store_region_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Region code'),
    '#default_value' => variable_get('commerce_cse_store_region_code'),
  );

  $form['origin']['commerce_cse_store_city_code'] = array(
    '#type' => 'textfield',
    '#title' => t('City code'),
    '#default_value' => variable_get('commerce_cse_store_city_code'),
  );

  $form['commerce_cse_extra_charge_type'] = array(
    '#type' => 'select',
    '#options' => array('percent'=>'percent', 'fixed'=>'fixed'),
    '#title' => t('Extra charge type'),
    '#default_value' => variable_get('commerce_cse_extra_charge_type', 'percent'),
    '#description' => t('Adds extra amount to calculated shipping price'),
  );

  $form['commerce_cse_extra_charge'] = array(
    '#type' => 'textfield',
    '#title' => t('Extra charge amount'),
    '#description' => t('Numeric value, without "%" and other symbols. Leave 0 to disable extra charges.'),
    '#default_value' => variable_get('commerce_cse_extra_charge', 0),
    '#size' => 15,
    '#field_suffix' =>
      variable_get('commerce_cse_extra_charge_type', 'percent') == 'percent' ? '%' : 'р.',
  );
  $form['commerce_cse_fixed_price'] = array(
    '#type' => 'textfield',
    '#title' => t('Fixed delivery price'),
    '#default_value' => variable_get('commerce_cse_fixed_price', 600),
    '#description' => t('If EMS website is down, this price is used as a Courier Service Express delivery price. Leave 0 to not use fixed price approach (in that case error is shown to user during calculating delivery price.'),
    '#size' => 15,
    '#field_suffix' => 'р.',
  );
  $form['commerce_cse_default_weight'] = array(
    '#type' => 'textfield',
    '#title' => t('Default product weight'),
    '#default_value' => variable_get('commerce_cse_default_weight', 0),
    '#description' => t('Courier Service Express requires weight for each item. That means, that if
     you forgot to enter weight in some product, shipping calculation won\'t work. You can specify default product weight here to avoid that behavior. Leave 0 to make this feature inactive.'),
    '#size' => 10,
    '#field_suffix' => 'kg',
  );

  return system_settings_form($form);
}
