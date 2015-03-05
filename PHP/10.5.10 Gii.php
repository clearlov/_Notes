<?php
/**
 * Note: If you are accessing Gii from a machine other than localhost, the access will be denied by default for security purpose. You can configure Gii to add the allowed IP addresses as follows,
 */
\yii\config\web.php
if(YII_ENV_DEV){
$config['modules']['gii'] => [
    'gii' => 'yii\gii\Module',
    'allowedIPs' => ['127.0.0.1', '::1', '192.168.1.*']
];
}