<?php
    include "../config.php";


    $book_id = $_POST['order'];
    if(!empty($book_id)) {
        
        $sql_statement = "SELECT title FROM books WHERE id = '$book_id'";

        $result = mysqli_query($db, $sql_statement);

        
        $row = mysqli_fetch_assoc($result);
        $title = $row['title'];
        echo '<div class="outerdiv">';
        echo '<form class="main" action="recieve-book2.php" method= "POST">';
        echo "<h2>" ."Enter your email to recieve the book  ''" . $title . "''</h2>"; 

        echo '<input class="input" type=text id="email" name= "email" placeholder="Your Email">';
        echo "<button class=" . "submit-btn " . "name=" . "recieve-id " . "value=" . $book_id .">Submit</button>" . "</form>" . "</div>";  
    }

?>

<style>
div.outerdiv{
    display: flex;
    justify-content: center;
    margin-top: 50px;
}
.main{
    border: 5px solid black;
    text-align: center;
    width: 30%;
    background-color: #E3E3E3;
}
.input{
    font-size: 20px;
}

.submit-btn{
        margin: 30px;
        background: #B9E587;
        padding: .8rem;
        color: black;
        border: 0;
        font-size: 20px;
    }
    .submit-btn:hover{
        color: whitesmoke;
        cursor: pointer;
    }
</style>