<?php
    include "../config.php";

    if (!empty($_POST['title'])){
        $title = $_POST['title'];
        $author = $_POST['author'];
        $genre = $_POST['genre'];
        $pages = $_POST['pages'];
        $publisher = $_POST['publisher'];
        $publish_date = $_POST['publish_date'];

        $sql_statement = "INSERT INTO books(title, author, genre, pages, publisher, publish_date) 
        VALUES ('$title', '$author', '$genre', '$pages', '$publisher', '$publish_date')";

        $result = mysqli_query($db, $sql_statement);

        if($result) header('Location: ../index.php');
        else echo "Something went wrong." . $db -> error;
    }
?>