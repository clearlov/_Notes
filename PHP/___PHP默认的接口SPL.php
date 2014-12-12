<?php

/*
 * http://php.net/manual/en/class.traversable.php
 *
 * 默认SPL 接口
   这是PHP内置的，不需要再写了

SPL提供了6个迭代器接口：

Traversable	遍历接口（检测一个类是否可以使用 foreach 进行遍历的接口）
Iterator	迭代器接口（可在内部迭代自己的外部迭代器或类的接口）
IteratorAggregate	聚合式迭代器接口（创建外部迭代器的接口）
Generator








OuterIterator	迭代器嵌套接口（将一个或多个迭代器包裹在另一个迭代器中）
RecursiveIterator	递归迭代访问接口（提供递归访问功能）
SeekableIterator	可索引迭代访问接口（实现查找功能）


 */


interface Traversable{
}


/*
 * http://php.net/manual/en/class.arrayaccess.php
 *
 * 数组式访问接口。实现该接口的对象能像数组一样使用：
 * */

interface ArrayAccess extends \Traversable{
    public function offsetExists($offset);

    public function offsetGet($offset);

    public function offsetSet($offset, $value);

    public function offsetUnset($offset);
}

/*
 *
 * http://php.net/manual/en/class.iterator.php
 *
 * Iterator接口的主要用途是允许一个类实现一个基本的迭代功能，从而使它可以被循环访问，根据键值访问以及回滚。Iterator接口摘要如下：
 * */

interface Iterator extends Traversable{
    //返回当前索引游标指向的元素
    public function current();

    //返回当前索引游标指向的元素的键名
    public function key();

    //移动当前索引游标指向下一元素
    public function next();

    //重置索引游标的指向第一个元素
    public function rewind();

    //判断当前索引游标指向的是否是一个元素，常常在调用 rewind()或 next()使用
    public function valid();
}



/*
 *http://php.net/manual/en/class.generator.php
 *
 * Generator objects are returned from generators.
 * 这是对 yield 数组定义的类，直接使用就可以了
 *
 * Caution
Generator objects cannot be instantiated via new.


 * */
class Generator implements \Iterator{
    /* Methods */
    public function current(){
    }

    public function key(){
    }

    public function next(){
    }

    public function rewind(){
    }

    public function send($value){
    }

    //public function throw (Exception $exception){}

    public function valid(){
    }

    public function __wakeup(){
    }
}




function foo() {
    $string = yield;
    echo $string;
    for ($i = 1; $i <= 3; $i++) {
        yield $i;
    }
}

$generator = foo();
$generator->send('Hello world!');
foreach ($generator as $value) echo "$value\n";


















/*
 * http://php.net/manual/en/class.iteratoraggregate.php
 *
 * 聚合式迭代器。创建外部迭代器的接口，
 * */

interface IteratorAggregate extends Traversable{

    //实现该方法时，必须返回一个实现了Iterator接口的类的实例
    /*其中getIterator 方法返回值必须是能遍历或实现Iterator接口（must be traversable or implement interface Iterator）。SPL还提供了一些专门用来与IteratorAggregate接口一起使用的内置迭代器。使用这些迭代器意味着只需要实现一个方法并实例化一个类就可以使对象可以迭代访问了。
    */

    public function getIterator();

}

/**
 * @author 简明现代魔法 http://www.nowamagic.net
 */
class myData implements IteratorAggregate{
    public $property1 = "公共属性1";
    public $property2 = "公共属性2";
    public $property3 = "公共属性3";

    public function __construct(){
        $this->property4 = "最后一个公共属性";
    }

    public function getIterator(){
        return new ArrayIterator($this);
    }
}

$obj = new myData;
foreach($obj as $key => $value){
    echo "键名：{$key}  值：{$value}\n";
}


/*
 * 上例输出：
 *
 * 键名：property1  值：公共属性1

键名：property2  值：公共属性2

键名：property3  值：公共属性3

键名：property4  值：最后一个公共属性*/


/*
 *
 * 序列化接口。实现该接口的类不能使用__sleep() 和__wakeup().在serialize时不执行__destruct()，在unserialize不执行__construct()。
 * 不论何时，只要有实例需要被序列化，serialize 方法都将被调用。它将不会调用 __destruct() 或有其他影响，除非程序化地调用此方法。当数据被反序列化时，类将被感知并且调用合适的 unserialize() 方法而不是调用 __construct()。如果需要执行标准的构造器，你应该在这个方法中进行处理。
 *
 * */

interface Serializable{
    public function serialize();

    public function unserialize();
}


class obj implements Serializable{
    private $data;

    public function __construct(){
        $this->data = "My private data";
    }

    public function serialize(){
        return serialize($this->data);
    }

    public function unserialize($data){
        $this->data = unserialize($data);
    }

    public function getData(){
        return $this->data;
    }
}

$obj = new obj;
$ser = serialize($obj);

$newobj = unserialize($ser);

var_dump($newobj->getData());


interface Closure{
    // private function __construct ();
    public static function bind($closure, $newthis, $newscope = 'static');

    public function bindTo($newthis, $newscope = 'static');
}

