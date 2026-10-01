<?php
    include "../config.php";

    if (!empty($_POST['email']) && !empty($_POST['password'])){
        $name = $_POST['name'];
        $email = $_POST['email'];
        $password = $_POST['password'];
        $phone_number = $_POST['p_num'];
        $address = $_POST['address'];
        $birth_year = $_POST['birth_year'];

        $sql_statement = "INSERT INTO users(name, email, password, phone_number, address, birth_year) 
        VALUES ('$name', '$email', '$password', '$phone_number', '$address', '$birth_year')";

        $result = mysqli_query($db, $sql_statement);

        if($result) echo "You have successfully registered.";
        else echo "Something went wrong." . $db -> error;
    }
    else{
        echo "You have not entered the inputs correctly";
    }
?>