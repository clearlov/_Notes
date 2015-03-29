<?php
namespace yii\web;
class Response extends \yii\base\Response
{
  public:
  int getStatusCode()
  setStatusCode(int $status_code, $response_text = null)
  \yii\web\HeaderCollection getHeaders()
  send()
  clear()
  sendHeaders()
  sendCookies()
  sendContent()
  /**
   * @arg array $opt 
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

namespace yii\base;
class Response extends Component
{
  public:
  send()
  clearOutputBuffers():= ob_clean()
}