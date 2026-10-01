<!DOCTYPE html>
<html>
<head>
	<title>Library Management Project</title>
<style>


h1, h3{
    display:flex;
    justify-content:center;
}

table {
  font-family: arial, sans-serif;
  border-collapse: collapse;
  width: 100%;
}

td, th {
  border: 3px solid #D1B378;
  text-align: left;
  padding: 8px;
}

tr:nth-child(even) {
  background-color: #D1B378;
}

button[type="create-account-button"]{
    display: center;
    height: 60px;
    width: 200px;
    border-radius: 5px;
    font-size: 22px;
    font-weight: 520;
    background: #84B936;
    cursor: pointer;
}


button[type="create-account-button"]:hover{
    background: #A7EEE4;
}

button[type="support-page-button"]{
    display: center;
    height: 60px;
    width: 200px;
    border-radius: 5px;
    font-size: 22px;
    font-weight: 520;
    background: #EAACF9;
    cursor: pointer;
    float: right;
    margin: 21px;
}

button[type="donate-return-book-button"]{
    display: center;
    height: 50px;
    width: 180px;
    border-radius: 5px;
    font-size: 20px;
    font-weight: 520;
    background: #ffffcc;
    cursor: pointer;
    float: right;
}

button[type="donate-return-book-button"]:hover{
    background: #F1A4A4;
} 



.review-btn{
    border: 0;
    padding: 9px;
    background: #AFAFFA;
    font-family: "Lucida Console", "Courier New", monospace;
    cursor: pointer;
    font-size: 14px;
}
.review-btn:hover, .order-btn:hover, .queue-btn:hover{
    color: white;
}
.order-btn{
    background: #BBF68A;
    padding:5px;
    margin-top:5px;
    cursor: pointer;
}
.queue-btn{
    background: #F69A8A;
    padding:5px;
    margin-top:5px;
    cursor: pointer;
}
</style>

</head>


<body>


<form action="/CS306Step5/register/register.html"><button type="create-account-button">Create an account!</button></form>

<h1> Library Management </h1>

<form action="/CS306Step5/donate-book/donate-book.html"><button type="donate-return-book-button">Donate a Book</button></form>
<form action="/CS306Step5/return-book/return-book.html"><button type="donate-return-book-button">Return a Book</button></form>




<div align="center">

	<table>

<tr> <th> Title </th> <th> Author </th> <th> Genre </th> <th> Pages </th> <th> Publisher </th> <th> Publish Date </th> <th> Reviews </th> <th> Availability </th> </tr> 

<?php

include "config.php";

$sql_statement = "SELECT * FROM books";

$result = mysqli_query($db, $sql_statement);

while($row = mysqli_fetch_assoc($result))
{
    $id = $row['id'];
    $title = $row['title'];
    $author = $row['author'];
    $genre = $row['genre'];
    $pages = $row['pages'];
    $publisher = $row['publisher'];
    $publish_date = $row['publish_date'];
    $current_owner = $row['current_owner'];

	echo "<tr>" . "<th>" . $title . "</th>" . "<th>" . $author . "</th>" . "<th>" . $genre . "</th>" . "<th>" . $pages . "</th>" . "<th>" . $publisher . "</th>" . "<th>" . $publish_date . "</th>";

    // Reviews part
    echo "<th>". "<form action=" . "reviews/comments.php" . " method=" . "POST>" . "<button class=" . "review-btn " . "name=" . "id" .  " value=" . $id . ">Click for reviews</button>" . "</form>" ."</th>";

    // Recieve book and enter queue part
    if(is_null($current_owner)) {
        echo "<th>". "✓ Available" . "<form action=" . "recieve-book/recieve-book.php" . " method=" . "POST>" . "<button " . "class=" . "order-btn " . "name=" . "order" .  " value=" . $id . ">Order Now!</button>" . "</form>" ."</th>". "</tr>";
    } else {
        echo "<th>". "X Not Available" . "<form action=" . "queue/queue.php" . " method=" . "POST>" . "<button " . "class=". "queue-btn " . "name=" . "id" .  " value=" . $id . ">Enter the queue</button>" . "</form>" ."</th>". "</tr>";
    }
}

?>

</table>
</div>


<form action="/CS306Step5/support-page/message_client.php"><button type="support-page-button">Support Page</button></form>
</body>
</html>