<?php
namespace yii\web;
class View extends \yii\base\View
{
  public:
  head():= echo '<![CDATA[YII-BLOCK-HEAD]]>';
  beginBody():= echo '<![CDATA[YII-BLOCK-BODY-BEGIN]]>';
  
  
}

namespace yii\base;
class View extends Component
{
  string render($view, $args=[], $context = null):= renderFile($file, $args, $contex)
  string renderFile($file, $args=[], $context = null)
  string getViewFile():= end(viewFiles)
  bool beforeRender($file, $args)
  afterRender($file, $args, &$output)
  string renderPhpFile($file, $args = []):= ob_start(); require($file); ob_get_clean()
  string renderDynamic($statements)
  addDynamicPlaceholder($placeholder, $statements)
  mixed evaluateDynamicContent($statements)
  Block beginBlock($id, $render_in_place = false):= Block::begin()
  endBlock():= \yii\widgets\Block::end()
  ContentDecorator beginContent($file, $args = [])
  endContent():= \yii\widgets\ContentDecorator::end()
  bool beginCache($id, $properties = []):= FragmentCache::begin($properties)
  endCache():= FragementCache::end()
  beginPage()
  endPage()
}