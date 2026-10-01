<?php

include "../config.php";

if(!empty($_POST['queue']))
{
    $id = $_POST['queue'][0];
    $user = substr($_POST['queue'], 1, strlen($_POST['queue'])-1);
    $position = $_POST['position'];

    $sql_statement = "UPDATE queue SET position = '$position' WHERE bid = '$id' AND email = '$user'";
    $result = mysqli_query($db, $sql_statement);
    
    if($result) echo "Position of the user has been updated.";
    else echo "Something went wrong." . $db -> error;
}

?>