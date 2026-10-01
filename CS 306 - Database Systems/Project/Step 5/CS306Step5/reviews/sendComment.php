<?php
    include "../config.php";

    if (!empty($_POST['name']) && !empty($_POST['message'])){
        $email = $_POST['name'];
        $message = $_POST['message'];
        $opinion = $_POST['opinion'];
        $id = $_POST['id'];

        $sql_statement = "INSERT INTO comments(book_id, commenter, content, opinion) 
        VALUES ('$id', '$email', '$message', '$opinion')";

        $result = mysqli_query($db, $sql_statement);

        if($result) {
            header("Location: ../index.php");
        }
        else echo "Please enter a valid e-mail. (Only 1 comment per user)";
    }
    else{
        echo "You have not entered the inputs correctly";
    }
?>