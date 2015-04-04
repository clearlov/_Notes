<?php
namespace yii\web;
class User extends Component
{
  public:
  yii\web\IdentityInterface getIdentity($auto_renew = true)
  setIdentity($identity)
  
  bool beforeLogin($identity, $cookie_based, $duration)
  bool afterLogin($identity, $cookie_based, $duration)
  
  bool beforeLogin(yii\web\IdentityInterface $identity, $cookie_based, $duration)
    := trigger(, new UserEvent())
  afterLogin($identity, $cookie_based, $duration)
    := trigger(, new UserEvent())
  bool login($identity, $duration = 0)
  
  yii\web\IdentityInterface loginByAccessToken($token, $type = NULL)
    := $this->identityClass::findIdentityByAccessTokey($token, $type)
  loginByCookie()
  
  bool beforeLogout($identity)
  afterLogout($identity)
  bool logout($destroy_sess = true)
  
  bool getIsGuest():= $this->getIdentity() === NULL
  string|int getId():= $this->getIdentity()->getId()
  string getReturnUrl($default_url = NULL):= Yii::$app->getUrlManager()->createUrl($url)
  setReturnUrl($url):= Yii::$app->getSession()->set($this->returnUrlParam, $url)
  ForbiddenHttpException loginRequired($check_ajax = true)
}

IdentityInterface
{
  public:
  static this findIdentity($id)
  static this findIdentityByAccessToken($token, $type = NULL)
  string|int getId()
  string getAuthKey()
  bool validateAuthKey($key)
}