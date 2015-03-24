<?php
namespace yii\base;
class Model extends Component 
            implements IteratorAggregate, ArrayAccess, Arrayable{
  public:
    /**
     * It's used by $this->validate()
     * attr.: required specifies
     * @see \yii\validators\Validator::$builtInValidators
     */
    array rules()
    /**
     * @return
     * [
     *   [ReflectionClass, [getParameters():: getDefaultValue() | getName()]]
     * ]
     * @throw InvalidConfigException if any validation rule configuration is invalid
     */
    array createValidators()
    /**
     * @return $this->createValidators()
     */
    array getValidators()
    array getActiveValidators($attribute = null)
    
    
    array scenarios()
    string formName()
    array attributes()
    /**
     * @return [name=>friendly_name]
     */
    array attributeLabels()
    string getAttributeLabel($attribute)
    /**
     * @return string Inflector::camel2words($name, true)
     */
    string generateAttributeLabel($name)
    
    
    
    bool validate($attributeNames = null, $clearErrors = true)
    bool beforeValidate()
    afterValidate()


    bool isAttributeRequired($attribute)
    bool isAttributeSafe($attribute)
    bool isAttributeActive($attribute)

    addError($attribute, $error = '')
    addErrors(array $items)
    bool hasErrors($attribute = null)
    /**
     * @return 
     *  [
     *      'username' =>['Error Msg1', ‘Error Msg2'],
     *      'email' => ['Error Msg1']
     *  ]
     */
    array getErrors($attribute = null)
    /**
     * @return ['username'=>'Error Msg1', 'email'=>'Error Msg1']
     */
    array getFirstErrors()
    string getFirstError($attr)
    clearErrors($attribute = null)
    
    array getAttributes($names = null, $except = [])
    setAttributes($values, $safeOnly = true)
    onUnsafeAttribute($name, $value)
    string getScenario()
    setScenario($value)
    array safeAttributes()
    array activeAttributes()
    bool load($data, $formName = null)
    static bool loadMultiple($models, $data, $formName = null)
    static bool validateMultiple($models, $attributeNames = null)
    array fields()
    array getIterator()
    
    bool offsetExists($offset)
    mixed offsetGet($offset)
    offsetSet($offset, $item)
    offsetUnset($offset)
}

namespace yii\db;
class ActiveRecord extends BaseActiveRecord{
    
    
    
}