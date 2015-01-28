<?php
/**
 * class
 * object
 * instantiate
 * method
 * property
 */

 
/**
 * supported variable type keywords
 *      array [CLASS]
 */
class Projectile{}
function fascination(array $fascinate, Projectile $vomitting){
    
}

 
 
/**
 * assignment of class via reference, clone a class is copy-on-write
 * Using _clone() method
 */
$Nausea = new Nausea();
$Nausea->neuron = 'Nausea::neuron';
$Seasick = $Nausea;  // assign via reference
$Seasick->neuron = 'Seasick::neuron';
echo $Nausea->neuron;  // Seasick::neuron 
$Carsick = clone $Nausea;  // copy-on-wirte
$Carsick->neuron = 'Carsick::neuron';
echo $Nausea->neuron; // Seasick::neuron
 
 
 
/**
 * interface, abstract and instanceOf, polymorphic
 * 
 */
interface ParalysisIf{
} 
abstract class AnaemiaAb{
    public $property;
    public static $soleStatic;
    public static $overwrite;
}
class Bachelor extends AnaemiaAb implments ParalysisIf{
    public static $overwrite;
}
class Cage extends AnaemiaAb{
    public static $overwrite;
}
$AnaemiaAb = new AnaemiaAb(); // Error: NOT allowed


AnaemiaAb::$soleStatic = 'avian';
/* @ouput avian avian avian */
echo AnaemiaAb::$soleStatic, ' ', Bachelor::$soleStatic, ' ', Cage::$soleStatic;

Bachelor::$soleStatic = 'brutal';
/* @ouput brutal brutal brutal */
echo AnaemiaAb::$soleStatic, ' ', Bachelor::$soleStatic, ' ', Cage::$soleStatic;

Cage::$soleStatic = 'contagious';
/* @ouput contagious contagious contagious */
echo AnaemiaAb::$soleStatic, ' ', Bachelor::$soleStatic, ' ', Cage::$soleStatic;


AnaemiaAb::$overwrite = 'invade';
/* @ouput invade NULL NULL */
echo AnaemiaAb::$overwrite, ' ', Bachelor::$overwrite, ' ', Cage::$overwrite;

Bachelor::$overwrite = 'colony';
/* @ouput invade colony NULL */
echo AnaemiaAb::$overwrite, ' ', Bachelor::$overwrite, ' ', Cage::$overwrite;


// Polymorphic
$Bachelor = new Bachelor();
if($Bachelor instanceOf Bachelor){  // true
}
if($Bachelor instanceOf AnaemiaAb){  // true
}
if($Bachelor instanceOf ParalysisIf){  // true
}


/**
 * serialize
 */
$bachelor_sleep = serialize($Bachelor);  // string for saving (in DB/Disk)
$Bachelor_wakeup = unserialize($bachelor_sleep); // Object








