<?php
abstract class A{
    public $var;
    public static $static;
}
class B extends A{
    
}

class C extends A{

}

A::$static = 'AAA';
B::$static = 'BBB';
echo A::$static;   // echo 'BBB';
C::$static = 'CCC';
echo A::$static;  // echo 'CCC';

//$A = new A(); // NOT allowed