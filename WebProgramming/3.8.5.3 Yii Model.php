<?php
/**
 * install pdo and pdo_mysql
 */



namespace app\models;
/**
 * You do not need to write any code inside of it! With just the above code, Yii will guess the associated table name from the class name.
 */
class DbMdl extends \yii\db\ActiveRecord{  
}

namespace app\controllers;
$query_all = \yii\app\models\DbMdl::find()
  ->orderBy('')
  ->offset('')
  ->limit('')
  ->all();
$query_one = \yii\app\models\DbMdl::findOne('');
$qa_fld = $query_one->fld;
$query_one->fld = 'Modify'; 
$query_one->save;       // save the modify


class DemitForm extends Model{
  public function rules(){
    return [
      [['param1', 'param2' ...], 'required']
    ];
  }
}