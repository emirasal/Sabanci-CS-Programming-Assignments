<?php

include "../config.php";

if(!empty($_POST['email']))
{
    $email = $_POST['email'];
    $sql_statement = "DELETE FROM users WHERE email = '$email'";
    $result = mysqli_query($db, $sql_statement);
    
    if($result) echo "User has been deleted.";
    else echo "Could not delete the user." . $db -> error;
}

?>