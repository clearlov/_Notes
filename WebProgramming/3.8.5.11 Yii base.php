<?php
/*******************************************************************************
 * Yii
 */
class BaseYii
{ 
  static $obj configure($obj, array $prop)
}

/*******************************************************************************
 */
class Object
{
  public:
  __construct($conf = [])
  virtual init() = 0;
  mixed __get($nm)
  __set($nm, $val)
  __isset($nm)
  __unset($nm)
  string className():= get_called_class()
  
  bool hasProperty($nm, bool $property_exists = true)
  bool canGetProperty($nm, bool $property_exists = true)
  bool canSetProperty($nm, bool $property_exists = true)
  
  bool hasMethod($nm):= method_exists($this, $nm)
}

/*******************************************************************************
 */
class Component extends yii\base\Object
{
  public:
  /**
   * @return
   *  'behaviorName' => [
   *     'class' => 'BehaviorClass',
   *     'property1' => 'value1',
   *     'property2' => 'value2',
   * ]
   */
  array behaviors()
  trigger($nm, Event $event = null)
}