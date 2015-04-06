<?php
/*******************************************************************************
 * Yii
 */
class BaseYii
{ 
  static $obj configure($obj, array $prop)
  static object createObject($type, $args = []):= static::$container->get($type, $args)
  static yii\log\Logger getLogger():= static::createObject('yii\log\Logger')
  static info($msg, $category = 'application'):= static::getLogger()->log()
  static trace($msg, $category = 'application'):= getLogger()->log()
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
  __construct($config = []):= Yii::configure($this, $config); init();
  string className():= get_called_class()
  
  bool hasProperty($nm, bool $property_exists = true)
  bool canGetProperty($nm, bool $property_exists = true)
  bool canSetProperty($nm, bool $property_exists = true)
  
  bool hasMethod($nm):= method_exists($this, $nm)
}

/*******************************************************************************
 *
 */
class Event extends Object
{
  private:
  static $_events = []
  public:
  /**
   * @example
   *  Event::on(ActiveRecord::className(), ActiveRecord::EVENT_AFTER_INSERT, 
   *    function ($event) {
   *      Yii::trace(get_class($event->sender) . ' is inserted.');
   *    });
   */
  static on(string $class, string $nm, $handler, $data = NULL, $append = true)
    := $_events[$nm][$class][] = [$handler, $data]
  static bool off($class, $nm, $handler = NULL)
    := unset($_events[$nm][$class][$i])
  static bool hasHandler($class, $nm) 
    :=  in_array($class | get_parent_class($class), $_events[$nm][$class])  
  static trigger($class, $nm, Event $event = new static)
    := call_user_func($_events[$nm][$class][$i][0], $event)
    := $_events[$nm][$class][$i][0]($event)
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
  trigger($nm, yii\base\Event $event = null)
}

/*******************************************************************************
 */
 class Behavior extends yii\base\Object
 {
   public:
   \yii\base\Component $owner;

   
 }