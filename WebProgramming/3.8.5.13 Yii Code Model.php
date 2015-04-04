<?php
namespace yii\db;
/*******************************************************************************
 *
 */
class ActiveRecord extends BaseActiveRecord{
  public:
    this loadDefaultValue($skip_if_set = true)
    static object getDb():= Yii::$app->getDb()
    /**
     * ::findBySql('SELECT DINSTINCT id FROM tb')->all()
     */
    static findBySql(string $qs, $args = [])
    /**
     * 
     */
    static findByCondition(mixed $cond, bool $one)
    
    static updateAll(string|array $attr, $cond = '', $args = [])
    static string tableName()
}

abstract class BaseActiveRecord extends \yii\base\Model 
                                implements ActiveRecordInterface
{
  public:
  
  
}

interface ActiveRecordInterface
{
  public:
  static array primaryKey()
  mixed getPrimaryKey($as_array = false)
  mixed getOldPrimaryKey($as_array = false)
  static bool isPrimaryKey(array $keys)
  
  array attributes()
  mixed getAttribute($nm)
  mixed setAttribute($nm, $val)
  bool hasAttribute($nm)

  static \yii\app\models\xxx find()
  /**
   * find()->where(['id'=>10])->one()
   * findOne(['id'=>10])
   */
  static \yii\app\models\xxx findOne($cond)
  static [\yii\app\models\xxx] findAll($cond)
  static int updateAll($attr, $cond = null)
  static int deleteAll($attr, $cond = null)
  bool save($run_validation = true, $attr_nms = null)
  bool insert($run_validation = true, $attrs = null)
  int update($run_validation = true, $attrs = null)
  /**
   * @note that it is possible that the number of rows deleted is 0, even though 
   *  the deletion execution is successful
   */
  int|bool delete()

  bool getIsNewRecord();

  bool equals($record);   
  ActiveQueryInterface getRelation($nm, $throw_exception = true);
  
  link($nm, static $model, $extra_columns = []);
  unlink($name, $model, $delete = false);
  mixed getDb()
    
}

namespace yii\base;
/*******************************************************************************
 *
 */
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
    array getValidators():= $this->createValidators()
    array getActiveValidators($attribute = null)
    
    
    array scenarios()
    string formName()
    array attributes():= ReflectionClass($this)
      ->getProperties(\ReflectionProperty::IS_PUBLIC)->!isStatic()->getName()[]
      
    [args=>friendly_name] attributeLabels()
    string getAttributeLabel($attr)
    string generateAttributeLabel($nm):= Inflector::camel2words($name, true)
    
    
    
    bool validate($attr_nms = null, $clr_errs = true)
    bool beforeValidate()
    afterValidate()


    bool isAttributeRequired($attr)
    bool isAttributeSafe($attr)
    bool isAttributeActive($attr)

    addError($attr, $err = '')
    addErrors(array $items)
    bool hasErrors($attr = null)
    /**
     * @return 
     *  [
     *      'username' =>['Error Msg1', ‘Error Msg2'],
     *      'email' => ['Error Msg1']
     *  ]
     */
    array getErrors($attr = null)
    /**
     * @return ['username'=>'Error Msg1', 'email'=>'Error Msg1']
     */
    array getFirstErrors()
    string getFirstError($attr)
    clearErrors($attr = null)
    
    array safeAttributes():= scenario()[getScenario()]{0} != '!'
    array activeAttributes()
    
    
    array getAttributes($nms = null, $except = [])
    
    
    setAttributes($posts, $safe_only = true):= $this->${$posts[k]} = $posts[v]
    onUnsafeAttribute($nm, $val)
    string getScenario()
    setScenario($val)
   
    
    bool load($data, $form_nm = formName())
      := $form_nm ==='' ? setAttributes($data) : setAttributes($data[$form_nm])  
    static bool loadMultiple($models, $data, $form_nm = null)
    static bool validateMultiple($models, $attr_nms = null)
    array fields():= array_combine(attributes(), attributes())
    array getIterator()
    
    bool offsetExists($offset)
    mixed offsetGet($offset)
    offsetSet($offset, $item)
    offsetUnset($offset)
}