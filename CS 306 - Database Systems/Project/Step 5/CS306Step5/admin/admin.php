<style>
    .position-selector-input{
        width: 42px;
    }
    div.outerdiv{
        text-align: center;
        border: 5px solid black;
        background-color: #E3E3E3;
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
    margin: 21px;
}
</style>


<div class="outerdiv">
<?php 

include "../config.php";

?>

<b><h2>Delete User</h2></b>
<form action="delete-user.php" method="POST">
<select name="email">

<?php

$sql_command = "SELECT name, email FROM users";

$result = mysqli_query($db, $sql_command);

    while($rows = mysqli_fetch_assoc($result))
    {
        $name = $rows['name'];
        $email = $rows['email'];
        echo "<option value=$email>". $name . " - " . $email . "</option>";
    }

?>
</select>
<button>DELETE</button>
</form>




<b><br><h2>Delete Book</h2></b>

<form action="delete-book.php" method="POST">
<select name="id">

<?php

$sql_command = "SELECT id, title, author FROM books";

$result = mysqli_query($db, $sql_command);

    while($rows = mysqli_fetch_assoc($result))
    {
        $id = $rows['id'];
        $title = $rows['title'];
        $author = $rows['author'];
        echo "<option value=" . $id .">". $title . " - " . $author . "</option>";
    }

?>
</select>
<button>DELETE</button>
</form>






<b><br><h2>Filter User by age</h2></b>

<form action="filter_by_ages.php" method="POST">
    Display user's <b>age</b> bigger than:   
    <input type="number" id="age" name="age">

    <input type="submit" value="Display">
</form>




<b><br><h2>Show comments about a certain book (Filter)</h2></b>
<form action="filter_commentByBook.php" method="POST">
<select name="id">

<?php

$sql_command = "SELECT id, title, author FROM books";

$result = mysqli_query($db, $sql_command);

    while($rows = mysqli_fetch_assoc($result))
    {
        $id = $rows['id'];
        $title = $rows['title'];
        $author = $rows['author'];
        echo "<option value=" . $id .">". $title . " - " . $author . "</option>";
    }

?>
</select>
<button>SHOW</button>
</form>




<b><br><h2>Delete Comments</h2></b>
<form action="delete-comment.php" method="POST">
<select name="comment">

<?php

$sql_command = "SELECT book_id, commenter, content FROM comments ORDER BY book_id";

$result = mysqli_query($db, $sql_command);

    while($rows = mysqli_fetch_assoc($result))
    {
        $book_id = $rows['book_id'];
        $commenter = $rows['commenter'];
        $content = $rows['content'];
        echo "<option value=" . $book_id . $commenter .">". $commenter . " - " . $content . "</option>";
    }

?>
</select>
<button>DELETE</button>
</form>








<b><br><h2>Remove a user from a queue</h2></b>
<form action="delete-queue.php" method="POST">
<select name="queue">

<?php

$sql_command = "SELECT bid, email, position FROM queue ORDER BY bid";

$result = mysqli_query($db, $sql_command);

    while($rows = mysqli_fetch_assoc($result))
    {
        $book_id = $rows['bid'];
        $user = $rows['email'];
        $position = $rows['position'];

        $title_result = mysqli_query($db, "SELECT title FROM books WHERE id = '$book_id'");
        $title = mysqli_fetch_assoc($title_result)['title'];

        echo "<option value=" . $book_id . $user .">". $title . " - " . $user . " (" . $position . ")</option>";
    }

?>
</select>
<button>DELETE</button>
</form>



<b><br><h2>Update the position on the queue</h2></b>
<form action="alter-queue.php" method="POST">
<select name="queue">

<?php

$sql_command = "SELECT bid, email, position FROM queue ORDER BY bid";

$result = mysqli_query($db, $sql_command);

    while($rows = mysqli_fetch_assoc($result))
    {
        $book_id = $rows['bid'];
        $user = $rows['email'];
        $position = $rows['position'];

        $title_result = mysqli_query($db, "SELECT title FROM books WHERE id = '$book_id'");
        $title = mysqli_fetch_assoc($title_result)['title'];

        echo "<option value=" . $book_id . $user .">". $title . " - " . $user . " (" . $position . ")</option>";
    }

?>
</select>
New Position:
<input class="position-selector-input" type="number" id="position" name="position">
<button>UPDATE</button>
</form>


<b><br><h2>Get the information about a user</h2></b>
<form action="user-information.php" method="POST">
<select name="email">

<?php

$sql_command = "SELECT name, email FROM users";

$result = mysqli_query($db, $sql_command);

    while($rows = mysqli_fetch_assoc($result))
    {
        $name = $rows['name'];
        $email = $rows['email'];
        echo "<option value=$email>". $name . " - " . $email . "</option>";
    }

?>
</select>
<button>GET THE INFO</button>
</form>



<form action="../support-page/message_admin.php"><button type="support-page-button">Admin Support Page</button></form>


</div>