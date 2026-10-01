<?php
    include "../config.php";


    if(!empty($_POST)) {

        $email = $_POST['email'];
        $book_id = $_POST['recieve-id'];
        $sql_statement = "UPDATE books SET current_owner = '$email' WHERE id = '$book_id'";

        $result = mysqli_query($db, $sql_statement);

        if ($result) echo "Book will send to your address shortly.";
        else echo "E-mail does not exist!";
    }
    

?>
