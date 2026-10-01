<?php

include "config.php";

if(!empty($_POST['emails']))
{
    $email = $_POST['emails'];
    $sql_statement = "DELETE FROM users WHERE email = '$email'";
    $result = mysqli_query($db, $sql_statement);
    
    if($result) echo "User has been deleted.";
    else echo "Could not delete the user." . $db -> error;
}

?>