<?php
$arr = [1,2,3,4,5];
/**
 * @see http://php.net/manual/en/function.current.php
 */
mixed current(array &$arr)
mixed next(array &$arr)
mixed prev(array &$arr)
mixed end(array &$arr)
/**
 * @return $arr[0]
 */
mixed reset(array &$arr)
/**
 * Return then to next()
 * @return 
 */
array each(array &$arr)
while(list($k, $v) = each($arr)){}