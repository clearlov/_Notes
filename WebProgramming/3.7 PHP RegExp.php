<?php
/**
 *  ?=a     ==>   a?
 *  ?!a     ==>   [^a]?
 *  ?<=a     ==>  a? 
 *  ?<!a     ==>  [^a]
 *  ?#      ==>   comment
 *  \1      ==>   first match
 *  ?:      ==>   ignore this match
 *  (?P<alias>pattern)           call with (?P=alias)
 *  /i      ==> ignore case-sensitive
 *  /g      ==> match all
 *  /x      ==> ignore all the blanks (not \s)
 *  /m      ==> multiple lines
 *  /s      ==> one line string; regards \r \n as normal character
 *  /u      ==> UTF-8 characters
 */
class WidgetEmail
{ 
  public static $emailAliasPattern = '/^(?P<user>[a-zA-Z0-9!#$%&\'*+\\/=?^_`{|}~-]+(?:\.[a-zA-Z0-9!#$%&\'*+\\/=?^_`{|}~-]+)*)@(?P<host>(?:[a-zA-Z0-9](?:[a-zA-Z0-9-]*[a-zA-Z0-9])?\.)+[a-zA-Z0-9](?:[a-zA-Z0-9-]*[a-zA-Z0-9])?)$/';
  private function emailLink(array $matches){
    return '<a href="mailto:'. $matches['0'] .'">Send Email to '.$matches['user'].'</a>';
  }
  public function emailMaker($str){
    return preg_replace_callback(static::$emailAliasPattern, [$this, 'emailLink'], $str);
  }
} 

$email = new WidgetEmail();
echo $email->emailMaker('lef.well@gmail.com');


$str = 'Lef Well is Lef';

// ignore blank, so \s should be writen
preg_match('/(?P<name>(?:\w+\s?)+)\s  Well\sis\s(?P=name)$/x', $str, $matches);

preg_match('/(?P<name>(?:\w+\s?)+) Well is (?P=name)$/', $str, $matches);
/*
array $matches(size=3)
  0 => string 'Lef Well is Lef' (length=15)
  'name' => string 'Lef' (length=3)
  1 => string 'Lef' (length=3)
*/

preg_match('/(?P<name>(\w+\s?)+) Well is (?P=name)$/', $str, $matches);
/*
array (size=4)
  0 => string 'Lef Well is Lef' (length=15)
  'name' => string 'Lef' (length=3)
  1 => string 'Lef' (length=3)
  2 => string 'Lef' (length=3)
*/



$quote_double = '"Hello, \'Lef\' Well"';
$quote = "'Hello, \"Lef\" Well'";
$quote_empty = '""';
$pattern = '/(\'|\")(([^\1]|\\\1)*)?\1/';
$pattern = <<<_PATTERN_
/(\\'|\\")(([^\\1]|\\\\\\1)*)?\\1/x
_PATTERN_;


preg_match($pattern, $quote, $matches);
var_dump($matches);
preg_match($pattern, $quote_double, $matches);
var_dump($matches);
preg_match($pattern, $quote_empty, $matches);
var_dump($matches);