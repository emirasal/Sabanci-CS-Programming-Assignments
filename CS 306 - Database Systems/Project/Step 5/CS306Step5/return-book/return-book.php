<?php
    include "../config.php";


    $email = $_POST['email'];
    $title = $_POST['title'];
    if (!empty($email && $title)){

        $sql_statement = "UPDATE books SET current_owner = NULL WHERE current_owner = '$email' AND title = '$title'";

        $result = mysqli_query($db, $sql_statement);

        if($result) echo "Thank you for returning the book . '$title'";
        else echo "One or both of the inputs are entered wrongly!";
 
    }
    else {
        echo "You did not enter anything!";
    }

?>