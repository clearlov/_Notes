<?php
namespace app\controllers;
use Yii;
use yii\filters\AccessControl;
use yii\web\Controller;
use yii\filters\VerbFilter;
use app\models\LoginForm;
use app\models\ContactForm;
class AnonymousController extends Controller{
    
    /**
     * Standalone Actions
     * extends \yii\base\Action, 
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
    
    public function anonymousView($param1, $param2 = null){
        
    }
}