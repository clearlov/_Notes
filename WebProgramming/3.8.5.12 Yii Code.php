<?php
namespace yii\di;
class Container extends Component{
    
  protected:
    /**
     * @return [ReflectionClass, [getParameters():: getDefaultValue() | getName()]]
     */
    array getDependencies($class)
  public:
    object get($class, $param=[], $config=[])
    object build($class, $param, $config)
}