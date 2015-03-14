<?php
/**
 * @link http://www.yiiframework.com/doc-2.0/guide-db-dao.html
 * config/web.php
 */
$config = [
    'components' => [
        'db' => [
            'class' => 'yii\db\Connection',
            'dsn' => 'mysql:host=localhost;dbname=tb',
            /**
             * Optional
             * If you need to execute a SQL query right after establishing a 
             * connection (e.g., to set the timezone or character set), you can 
             * do so in the yii\db\Connection::EVENT_AFTER_OPEN event handler. 
             */
            'on afterOpen' => function($event) {
                $event->sender->createCommand("SET time_zone = 'UTC'")->execute();
            }
            'tablePrefix' => '',
            'username' => 'lef',
            'password' => 'lef',
            'charset' => 'utf8',
            
            /**
             * Optional: Slave Database
             */
            'slaveConfig' => [
                'username' => '',
                'password' => '',
                'attributes' => [
                    PDO::ATTR_TIMEOUT => 10,
                ],
            ],
            /**
             * Optional: list of slave configurations
             */
             'slaves' => [
                [''=>'']
             ],
        ],
        'dbTwo' => [
            'class' => 'yii\db\Connection',
            'dsn' => 'pgsql:host=localhost;port=5432;dbname=tb2',
        ],
    ],
];

$conn = \Yii::$app->db;
$conn2 = \Yii::$app->dbTwo;
$conn3 = new \yii\db\Connection([
    'dsn' => 'pgsql:host=localhost;port=5432;dbname=tb3'
]);
$conn3->open();

$cmd = $conn->createCommand('SELECT * FROM tb');
$qa = $cmd->queryAll();     // array
$qo = $cmd->queryOne();     // array
$cmd = $conn->createCommand('SELECT fld FROM tb');
$fld = $cmd->queryColumn(); // string
$cmd = $conn->createComman('SELECT COUNT(*) FROM tb');
$count = $cmd->queryScalar();
$conn->createCommand('UPDATE tb SET ...')->execute();
$conn->createCommand()->batchInsert('tb',['flds1' => 'vals1'], ['fld2' ...); 


$tran = $conn->beginTransaction();
try{
    $conn->createCommand($sql1)->execute();
    $conn->createCommand($sql2)->execute();
    $tran->commit();
} catch(Exception $e){
    $tran->rollBack();
}
    