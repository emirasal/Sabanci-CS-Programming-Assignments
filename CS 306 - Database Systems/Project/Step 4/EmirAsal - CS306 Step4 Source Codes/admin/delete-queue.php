<?php

include "../config.php";

if(!empty($_POST['queue']))
{
    $id = $_POST['queue'][0];
    $user = substr($_POST['queue'], 1, strlen($_POST['queue'])-1);
    $sql_statement = "DELETE FROM queue WHERE bid = '$id' AND email = '$user'";
    $result = mysqli_query($db, $sql_statement);
    
    if($result) echo "User has been deleted from the queue.";
    else echo "Something went wrong." . $db -> error;
}

?>