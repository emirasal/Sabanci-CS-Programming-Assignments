<?php
require __DIR__.'/vendor/autoload.php';


use Kreait\Firebase\Factory;

$factory = (new Factory)
    ->withServiceAccount('cs306-step5-e6b41-firebase-adminsdk-om53i-79eb76898b.json')
    ->withDatabaseUri('https://cs306-step5-e6b41-default-rtdb.europe-west1.firebasedatabase.app/');

$database = $factory->createDatabase();

?>