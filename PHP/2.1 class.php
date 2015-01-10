<?php
/**
 * class
 * object
 * instantiate
 * method
 * property
 */

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
    public static $static;
}
class Bachelor extends AnaemiaAb implments ParalysisIf{
}
class Cage extends AnaemiaAb{
}

AnaemiaAb::$static = 'Avian'; // Bachelor::$static = Cage::$static = 'Avian';
echo Bachelor::$static; // Avian
Bachelor::$static = 'Brutal';
echo AnaemiaAb::$static;   // Brutal
Cage::$static = 'Contagious';
echo Bachelor::$static;  // Contagious
//$AnaemiaAb = new AnaemiaAb(); // NOT allowed

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








