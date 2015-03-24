<?php
namespace yii\validators;
class Validator extends Component{
  public:
    static $builtInValidators = [
        'boolean' => 'yii\validators\BooleanValidator',
        'captcha' => 'yii\captcha\CaptchaValidator',
        'compare' => 'yii\validators\CompareValidator',
        'date' => 'yii\validators\DateValidator',
        'default' => 'yii\validators\DefaultValueValidator',
        'double' => 'yii\validators\NumberValidator',
        'email' => 'yii\validators\EmailValidator',
        'exist' => 'yii\validators\ExistValidator',
        'file' => 'yii\validators\FileValidator',
        'filter' => 'yii\validators\FilterValidator',
        'image' => 'yii\validators\ImageValidator',
        'in' => 'yii\validators\RangeValidator',
        'integer' => [
            'class' => 'yii\validators\NumberValidator',
            'integerOnly' => true,
        ],
        'match' => 'yii\validators\RegularExpressionValidator',
        'number' => 'yii\validators\NumberValidator',
        'required' => 'yii\validators\RequiredValidator',
        'safe' => 'yii\validators\SafeValidator',
        'string' => 'yii\validators\StringValidator',
        'trim' => [
            'class' => 'yii\validators\FilterValidator',
            'filter' => 'trim',
            'skipOnArray' => true,
        ],
        'unique' => 'yii\validators\UniqueValidator',
        'url' => 'yii\validators\UrlValidator',
    ];
    /**
     * @return Yii::createObject()
     * @example
     *  \yii\base\Model::rules()
     *    return [
     *      [['username', 'password'], 'required'],
     *       ['username', 'string', 'min'=>3, 'max'=12]
     *    ]
     *  \yii\base\Model::createValidators()
     *    ArrayObject->append(
     *      ::createValidator('required',$this,['username','password'],[]]
     *      )
     *    )
     *    Yii::createObject(
     *      [   'attributes'=>['username','password'], 
     *          'class'=>'yii\validators\RequiredValidator'
     *      ]
     *    )
     *    \yii\di\Container->get('yii\validators\RequiredValidator',[],
     *      'attributes'=>['username','password']
     *    )
     *    @return [ReflectionClass, [getParameters():: getDefaultValue() | getName()]]
     *    ArrayObject->append(
     *      ::createValidator('string',$this,['username'],['min'=>3,'max'=12]]
     *    )
     *    Yii::createObject(
     *      [   'attributes'=>['username','min'=>3,'max'=12],
     *          'class'=>'yii\validators\StringValidator'
     *      ]
     *    )
     *   \yii\di\Container->get('yii\validators\StringValidator', [],
     *      'attributes'=>['username','min'=>3,'max'=12]
     *   )
     */
    static object createValidator($type, $model, $attr, $params = [])
    
    bool isActive($scenario)
    
}    