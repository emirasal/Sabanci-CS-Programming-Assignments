<!DOCTYPE html>
<html>

<head>
  <title>Queue Page</title>
<style>
table {
  font-family: arial, sans-serif;
  border-collapse: collapse;
  width: 30%;
  position: center;
}

td, th {
  border: 3px solid #E2AAAA;
  text-align: left;
  padding: 8px;
}

.user{
    width: 30px;
}

tr:nth-child(even) {
  background-color: #E2AAAA;
}

.button{
    padding: 10px;
    margin-bottom: 32px;
    border: none;
    color: #0B5250;
}

.button:hover{
    color: black;
    font-weight: 700;
    cursor: pointer;
}
.name{
    margin:16px;
}

.txtenterqueue {
  margin-top: 60px;
  font-family: "Lucida Console", "Courier New", monospace;
}

</style>
</head>
</html>

<div align="center">

	<table>
    <tr> <th> Line In The Queue </th> <th> User </th> </tr> 
<?php
    include "../config.php";

    if(!empty($_POST['id'])) {
        $book_id = $_POST['id'];

        $sql_statement = "SELECT email, position FROM queue WHERE bid = '$book_id' ORDER BY position";

        $result = mysqli_query($db, $sql_statement);

        while($row = mysqli_fetch_assoc($result))
        {
            $commenter = $row['email'];
            $position = $row['position'];

            echo "<tr>" . "<th class=" . "position" . ">" . $position . "</th>";
            echo "<th class=" . "user" . ">" . $commenter . "</th>" . "</tr>";
        }
        

        // Form below to make a new queue
        $sql_statement = "SELECT title FROM books WHERE id = '$book_id'";
        $result = mysqli_query($db, $sql_statement);
        $data = mysqli_fetch_assoc($result);
        $bookTitle = $data['title'];

        echo "<h1>" . "Queue page for the book ''" . $bookTitle . "''</h1>";
        echo ' <h3 class=txtenterqueue>You can enter the queue for this book:</h3>
                <form action="sendQueue.php" method="POST">
                  <input class="name" type="text" id="email" name="email" placeholder="Enter Your E-mail"><br>';
        echo "<button class=" . "button " . "name=" . "id " . "value=" . $book_id . ">SUBMIT</button>" . "</form>";
    } 
?>