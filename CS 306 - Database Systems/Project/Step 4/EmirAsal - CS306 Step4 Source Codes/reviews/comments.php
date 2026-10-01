<!DOCTYPE html>
<html>

<head>
  <title>Comments Page</title>
<style>
table {
  font-family: arial, sans-serif;
  border-collapse: collapse;
  width: 90%;
}

td, th {
  border: 3px solid #D5FCFB;
  text-align: left;
  padding: 8px;
}

.commenterAndOpinion{
    width: 30px;
}

tr:nth-child(even) {
  background-color: #D5FCFB;
}

.button{
    padding: 10px;
    margin: 15px;
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

.txtshareOpinion {
  margin-top: 55px;
  font-family: "Lucida Console", "Courier New", monospace;
}

</style>
</head>
</html>


<div align="center">

	<table>
    <tr> <th> User </th> <th> Opinion </th> <th> Comment </th> </tr> 
<?php
    include "../config.php";


    $book_id = $_POST['id'];
    if(!empty($book_id)) {
        
        $sql_statement = "SELECT commenter, opinion, content FROM comments WHERE book_id = '$book_id'";

        $result = mysqli_query($db, $sql_statement);

        
        while($row = mysqli_fetch_assoc($result))
        {
            $commenter = $row['commenter'];
            $opinion = $row['opinion'];
            $content = $row['content'];

            echo "<tr>" . "<th class=" . "commenterAndOpinion" . ">" . $commenter . "</th>";
            if ($opinion == 1) echo "<th class=" . "commenterAndOpinion" . ">Positive" . "</th>";
            else echo "<th class=" . "commenterAndOpinion" . ">Negative" . "</th>";

            echo "<th>" . $content . "</th>" . "</tr>";
        }
        


        // Form below to make a new review
        $sql_statement = "SELECT title FROM books WHERE id = '$book_id'";
        $result = mysqli_query($db, $sql_statement);
        $data = mysqli_fetch_assoc($result);
        $bookTitle = $data['title'];

        echo "<h1>" . "Review page for the book ''" . $bookTitle . "''</h1>";
        echo ' <h3 class=txtshareOpinion>You can share your opinion:</h3>
                <form action="sendComment.php" method="POST">
                  <input class="name" type="text" id="fname" name="name" placeholder="Enter Your E-mail"><br>
                  <textarea name="message" rows="4" cols="70"></textarea><br>
                    Opinion:
                    <select name="opinion" id="opinion">
                        <option value="1">Positive</option>
                        <option value="0">Negative</option>
                    </select>';
        echo "<button class=" . "button " . "name=" . "id " . "value=" . $book_id . ">SEND YOUR REVIEW</button>" . "</form>";

    } 

?>