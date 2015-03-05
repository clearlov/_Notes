<?php
/**
 *@link http://php.net/manual/zh/class.reflection.php
 */
interface Reflector{
    public static export();
    public static __toString();
}

abstract class Reflection{
    public static export(Reflector $reflector, $return = false);
    public static getModifierNames(int $modifiers);
}

/**
 *@link http://php.net/manual/zh/class.reflectionclass.php
 */
class ReflectionClass implements Reflector{
     
}

/**
 *@link http://php.net/manual/zh/class.reflectionproperty.php
 */
class ReflectionProperty implements Reflector{
    
}

/**
 *@link http://php.net/manual/zh/class.reflectionobject.php
 */
class ReflectionObject extends ReflectionClass implements Reflector{
    
}