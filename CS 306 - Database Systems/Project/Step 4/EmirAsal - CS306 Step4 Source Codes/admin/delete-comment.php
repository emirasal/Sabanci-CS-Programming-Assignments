<?php

include "../config.php";

if(!empty($_POST['comment']))
{
    $id = $_POST['comment'][0];
    $commenter = substr($_POST['comment'], 1, strlen($_POST['comment'])-1);
    $sql_statement = "DELETE FROM comments WHERE book_id = '$id' AND commenter = '$commenter'";
    $result = mysqli_query($db, $sql_statement);
    
    if($result) echo "Comment has been deleted.";
    else echo "Something went wrong." . $db -> error;
}

?>