<?php

include "../config.php";

if(!empty($_POST['id']))
{
    $id = $_POST['id'];
    $sql_statement = "DELETE FROM books WHERE id = '$id'";
    $result = mysqli_query($db, $sql_statement);
    
    if($result) echo "Book has been deleted from the system.";
    else echo "Something went wrong." . $db -> error;
}

?>