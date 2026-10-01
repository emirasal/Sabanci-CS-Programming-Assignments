<?php
    include "../config.php";

    $age = $_POST['age'];
    if (is_numeric($age)){
      
        $current_year = 2022;
        $sql_statement = "SELECT name, email, phone_number, birth_year, address FROM users WHERE '$current_year'- birth_year > '$age'";

        $result = mysqli_query($db, $sql_statement);

        if($result) {

            while($row = mysqli_fetch_assoc($result)) {
                $name = $row['name']; 
                $email = $row['email']; 
                $phone_number = $row['phone_number'];
                $user_age = $current_year - $row['birth_year'];
                $address = $row['address']; 
                echo "----------------------------"; 
                echo "<br>" . "Name: " . $name . "<br>" . "E-mail: " . $email . "<br>" . "Phone-number: " . $phone_number . "<br>" . "Age: " . $user_age. "<br>". "Address: ". $address ."<br>";
            } 
        }
        else echo "Something went wrong." . $db -> error;
    }

?>