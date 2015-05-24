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
  object getHeaders():= \yii\web\HeaderCollection
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

class Response extends \yii\base\Response
{
  public:
  int getStatusCode()
  setStatusCode(int $status_code, $response_text = null)
  object getHeaders():= \yii\web\HeaderCollection
  send()
  clear()
  sendHeaders()
  sendCookies()
  sendContent()
  /**
   * @param array $opt 
   *  mimeType: 
   *  inline: bool, whether the browser should open the file within the browser 
   *    window. Defaults to false, meaning a download dialog will pop up.
   *  
   */
  this sendFile($file_path, $attach_nm = null, $opt = [])
  this sendContentAsFile($content, $attach_nm, $opt = [])
  this sendStreamAsFile($handle, $attach_nm, $opt = [])
  this setDownloadHeaders($attach_nm, $mime_type = null, $inline = false, $content_len = null)
  array getHttpRange($file_size):= $_SERVER['HTTP_RANGE'] [begin, end]
  this xSendFile($file, $attach = null, $opt = [])
  
  
  this redirect($url, $status_code = 302, $check_ajax = true)
  this refresh($anchor = ''):= redirect(Yii::$app->getRequest()->getUrl() . $anchor)
  \yii\web\CookieCollection getCookies()
  bool getIsInvalid():=  getStatusCode() not in range [100, 600]
  bool getIsInformational():= getStatusCode() in range [100, 200)
  bool getIsSuccessful():= getStatusCode() in range [200, 300)
  bool getIsRedirection():= getStatusCode() in range [300, 400)
  bool getIsClientError():= getStatusCode() in range [400, 500)
  bool getIsServerError():= getStatusCode() in range [500, 600)
  bool getIsOk():= getStatusCode() == 200
  bool getIsForbidden():= getStatusCode() == 403
  bool getIsNotFound():= getStatusCode() == 404
  bool getIsEmpty():= in_array(getStatusCode(), [201, 204, 304])

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





class Response extends Component
{
  send()
  clearOutputBuffers():= ob_end_clean ||　ob_clean()
}