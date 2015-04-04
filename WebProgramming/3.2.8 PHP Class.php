<?php

/**
 * static:: = parent:: + self::(will overwrite parent) 
 */
class Abase
{
  public function prissy(){
    return new self();    // Abase always, not its derived class
  }
  public function fervent(){
    return new static(); 
  }
}
class Backer extends Abase{}
$backer = new Backer;
$backer->prissy();  // new Abase()
$backer->fervent(); // new Backer()






mixed call_user_func(string $func[, mixed $arg1[, $arg2...]]):= $func($args)



int func_num_args()
mixed func_get_arg($arg_num)
array func_get_args()
/**
 * @see http://php.net/manual/en/function.get-class.php
 */
string get_class($obj = null)
string get_parent_class($obj = null)
/**
 * @see http://php.net/manual/en/function.get-called-class.php
 * @return string name of the called class; bool false on error
 */
string get_called_class()
bool method_exists($obj, $method_nm)
bool property_exists($class, $property)
bool class_exists($class_nm, $autoload = true)
bool interface_exists($interface_nm, $autoload = true)
bool function_exists($func_nm)
bool class_alias($original = null, $alias = null)
