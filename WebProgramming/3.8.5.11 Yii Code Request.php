<?php

namespace yii\web;
class Request extends \yii\base\Request
{
  string getRawBody():= file_get_contents('php://input')
  setRawBody($raw_body): _rawBody
  array getBodyParams()
  setBodyParams($arr): _bodyParams
  mixed getBodyParam($k, $val = null):= getBodyParams[$k] || $val
  []|mixed post($k = null, $val = null):= $k ? getBodyParam() || getBodyParams()
  array getQueryParams():= _queryParams || $_GET
  setQueryParams($arr): _queryParams
  mixed getQueryParam($k, $val = null):= getQueryParams()[$k] || $val
  []|mixed get($k = null, $val = null):= $k ? getQueryParam($k, $val) : getQueryParams()
  string getBaseUrl():= _baseUrl || rtrim(dirname(getScriptUrl()), '\\/')
  setBaseUrl($val):_baseUrl
  
  [route, array_merge($_GET, Yii::$app->getUrlManager()->parseRequest()[1])] resolve()
  \yii\web\HeaderCollection getHeaders()
  string getMethod():strtoupper($_POST[methodParam] || $_SERVER['HTTP_X_HTTP_METHOD_OVERRIDE']
                      || $_SERVER['REQUEST_METHOD'])
  bool getIsGet():= getMethod() === 'GET'
  bool getIsHead():= getMethod() === 'HEAD'
  bool getIsPost():= getMethod() === 'POST'
  bool getIsDelete()
  bool getIsPut()
  bool getIsPatch()
  bool getIsAjax():= isset($_SERVER['HTTP_X_REQUESTED_WITH']) && $_SERVER['HTTP_X_REQUESTED_WITH'] === 'XMLHttpRequest'
  bool getIsPjax():= getIsAjax()&& !empty($_SERVER['HTTP_X_PJAX'])
  bool getIsFlash()
}


class HeaderCollection extends Object 
                       implements \IteratorAggregate, \ArrayAccess, \Countable
{
  
}





namespace yii\base;
abstract class Request extends \yii\base\Component
{
  abstract [route, args] resolve()
  bool getIsConsoleRequest():= _isConsoleRequest || PHP_SAPI === 'cli'
  setIsConsoleRequest($val):_isConsoleRequest
  setScriptFile($val):= _scriptFile = realpath(Yii::getAlias($val))
  string getScriptFile():= _scriptFile || setScriptFile($_SERVER['SCIRPT_FILENAME'])
}