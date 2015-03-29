<?php
array \yii\base\Component\behaviors()

namespace yii\web;
class Controller extends \yii\base\Controller
{
  public:
    string renderAjax($view, $args = [])
    /**
     * @throws BadRequestHttpException if there are missing or invalid parameters.
     */
    array bindActionParams($action, $args)
    bool beforeAction($action)
    \yii\web\Response redirect($url, int $status_code = 302)
    /**
     * ::redirect(Yii::$app->getUser()->getReturnUrl($defaultUrl))
     */
    \yii\web\Response goHome()
    \yii\web\Response goBack()
    /**
     * ::redirect(Yii::$app->getRequest()->getUrl(). $anchor)
     */
    \yii\web\Response refresh($anchor='')
}



namespace yii\base;
class Controller extends Component
                 implements ViewContextInterface{
  public:
    public $defaultAction = 'index';
    __construct($id, $module, $config=[])
      /**
       * @return
       *  [
       *      'error' => 'yii\web\ErrorAction',
       *      'captcha' => [
       *          'class'=>'yii\captcha\CaptchaAction',
       *          'fixedVerifyCode' => YII_ENV_TEST ? 'testme' : null,
       *      ],
       *  ]
       */
    array actions()
    mixed runAction($id, $params=[])
    mixed run($route, $params=[])
    string getRoute()
    /**
     * @throws InvalidParamException if the view file does not exist.
     */
    string render($view, $args=[]):= 
          \yii\base\View->renderFile($layout_file, ['content'=>$content], $this)
    string renderContent($content)
    string renderPartial($view, $args=[])
    string renderFile($file, $args=[])
    \yii\web\View getView()
    setView($view)
    string getViewPath()
    string|bool findLayoutFile($view)
}