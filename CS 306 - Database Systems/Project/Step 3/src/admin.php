<?php 

include "config.php";

?>

<b><h2>Deletion</h2></b>

<form action="delete.php" method="POST">
<select name="emails">

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
<button>DELETE USER</button>
</form>


<b><h2>Selection</h2></b>

<form action="filter_by_ages.php" method="POST">
    Display user's <b>age</b> bigger than:   
    <input type="number" id="age" name="age">

    <input type="submit" value="Display">
</form>

