<?php
namespace app\controllers;
class NitCtrl extends Controller{
  /**
   * @extends \yii\base\Controller::defaultAction
   */
  public $defaultAction = 'index';
  /**
   * @extends \yii\base\Component::behaviors()
   */
  public function behaviors(){
      return [
          'access' => [
              'class' => AccessControl::className(),
              'only' => ['logout'],
              'rules' => [
                  [
                      'actions' => ['logout'],
                      'allow' => true,
                      'roles' => ['@'],
                  ],
              ],
          ],
          'verbs' => [
              'class' => VerbFilter::className(),
              'actions' => [
                  'logout' => ['post'],
              ],
          ],
      ];
  }
  
  /**
   * @extends \yii\base\Controller::actions()
   * e.g. \yii\web\ViewAction \yii\web\ErrorAction are all standalone actions
   */
  public function actions(){
    return [
      'error' => 'yii\web\ErrorAction',
      'captcha' => [
        'class' => 'yii\captcha\CaptchaAction',
        'viewPrefix' => '',
        'fixedVerifyCode' => YII_ENV_TEST ? 'testme' : null,
      ],
    ];
  }
  /**
   * @example
   *  ?r=nit-ctrl/sec&arg1=&arg2=
   */
  public function actionSec($arg1, $arg2 = null){
      
  }
}