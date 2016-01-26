<?php

/**
 * Implements hook_drush_command().
 */
function lisa_dev_drush_command() {
  return array(
    'var-dump' => array(
      'aliases' => array(
        'var_dump',
        'vardump',
        'vd',
      ),
      'arguments' => array(
        'php' => 'PHP with a return value to var_dump().'
      ),
      'description' => 'Execute PHP and var_dump() the result.',
      'examples' => array(
        'drush vd \'array("x" => "y")\'',
      ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    ),
    'print-r' => array(
      'aliases' => array(
        'print_r',
        'printr',
        'pr',
      ),
      'arguments' => array(
        'php' => 'PHP with a return value to print_r().'
      ),
      'description' => 'Execute PHP and print_r() the result.',
      'examples' => array(
        'drush pr \'array("x" => "y")\'',
      ),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    ),
  );
}


function drush_lisa_dev_var_dump($php) {
  var_dump(eval('return ' . $php . ';'));
}

function drush_lisa_dev_print_r($php) {
  print_r(eval('return ' . $php . ';'));
}

