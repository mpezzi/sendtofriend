<?php

/**
 * @file
 * Provides administration settings for sendtofriend.module
 */


/**
 * Return an administrative settings form.
 */
function sendtofriend_admin_settings_form() {
  $form = array();
  $form['message'] = array(
    '#type' => 'fieldset',
    '#title' => t('Message settings'),
  );
  $form['message']['sendtofriend_refer_message_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => variable_get('sendtofriend_refer_message_subject', '@from_first_name @from_last_name has shared a link with you'),
    '#maxlength' => 255,
  );
  $form['message']['sendtofriend_refer_message_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => variable_get('sendtofriend_refer_message_body', ''),
    '#description' => t('Available variables: @to_mail, @from_mail, @from_first_name, @from_last_name, @message, @site_url, @site_link'),
  );
  $form['success'] = array(
    '#type' => 'fieldset',
    '#title' => t('Success settings'),
  );
  $form['success']['sendtofriend_refer_message_success'] = array(
    '#type' => 'textarea',
    '#title' => t('Success message'),
    '#default_value' => variable_get('sendtofriend_refer_message_success', "Thanks! We've passed along an email to your friend."),
  );
  return system_settings_form($form);
}