<?php
namespace yii\web;
class AssetBundle extends Object
{
  static register($view):= $view->registerAssertBundle(get_called_class())
  \yii\web\View registerAssertFiles($view):= 
}


class View extends \yii\base\View
{
  
}










namespace yii\base;
class Widget extends Component implements ViewContextInterface
{
  static Widget begin($conf = [])
    := Yii::createObject(array_merge($config, ['class'=>get_called_class()]))
  static Widget end():= array_pop(static::$stack)->run()
  
  virtual string run()
  static string widget($conf = []):= ob_start();ob_implicit_flush(false);
                                      ob_get_clean(). begin()->run()
                                      
  string getId($auto_gen = true):= _id && static::$autoIdPrefix. static::$counter++
  setId($val): _id
  \yii\web\View getView():= _view && Yii::$app->getView()
  setView($view): _view
  
  string render($view, $args = []):= getView()->render($view, $args, $this)
  string renderFile($file, $args):= getView()->renderFile($file, $args, $this)
  string getViewPath()
    := dirname(new ReflectionClass($this)) . DIRECTORY_SEPARATOR . 'view'
}

interface ViewContextInteface
{
  string getViewPath()
}





class View extends Component
{
  string|false getViewFile():= end(_viewFiles)
  bool beforeRender($file, $args)
  afterRender($file, $args, &$output)
  string renderPhpFile($file, $args = []):= ob_start();ob_implicit_flush(false);
                        extract($args); require($file); ob_get_clean();
  string renderDynamic($statements)
  string renderFile($file, $args, $context = null)
  string render($view, $args = [], $context = null):= renderFile()
}



