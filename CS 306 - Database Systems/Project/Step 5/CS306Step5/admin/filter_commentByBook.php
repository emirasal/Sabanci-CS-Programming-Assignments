<?php

include "../config.php";

if(!empty($_POST['id']))
{
    $id = $_POST['id'];
    $sql_statement = "SELECT* FROM comments WHERE book_id = '$id'";
    $result = mysqli_query($db, $sql_statement);
    
    if($result) {
        while($rows = mysqli_fetch_assoc($result))
        {
        $commenter = $rows['commenter'];
        $content = $rows['content'];
        echo $commenter . " ----- " . $content . " <br>";
        }
    }
    else echo "Something went wrong." . $db -> error;
}

?>