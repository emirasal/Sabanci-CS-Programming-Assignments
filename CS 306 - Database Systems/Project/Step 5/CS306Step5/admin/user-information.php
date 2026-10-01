<?php

include "../config.php";

if(!empty($_POST['email']))
{
    $email = $_POST['email'];

    $sql_statement = "SELECT name, phone_number, address, birth_year FROM users WHERE email = '$email'";
    $result = mysqli_query($db, $sql_statement);

    $data = mysqli_fetch_assoc($result);

    $name = $data['name'];
    $pNumber = $data['phone_number'];
    $address = $data['address'];
    $birth_year = $data['birth_year'];

    if($result) {
        echo "Name: " . $name . "<br>" . "Email: " . $email . "<br>" . "Phone Number: " . $pNumber .  "<br>" . "Address: " . $address . "<br>" . "Birth Year: " . $birth_year;
    }
    else echo "Something went wrong." . $db -> error;
}

?>