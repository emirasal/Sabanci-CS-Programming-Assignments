<?php
    include "../config.php";


    if(!empty($_POST)) {

        $email = $_POST['email'];
        $book_id = $_POST['id'];
        
        $sql_statement = "SELECT COUNT(bid) as total FROM queue WHERE bid='$book_id'";
        $result = mysqli_query($db, $sql_statement);
        $data = mysqli_fetch_assoc($result);
        
        $position = $data['total']+1;



        $sql_statement = "INSERT INTO queue(bid, email, position) VALUES('$book_id', '$email', '$position')";
        $result = mysqli_query($db, $sql_statement);

        if ($result) {
            header("Location: ../index.php");
        }
        else echo "Please enter a valid e-mail.";
    }
    

?>
