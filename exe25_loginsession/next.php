<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
</head>

<body>

</body>

</html>

<?php session_start();

if (isset($_SESSION['user'])) {
    $user = $_SESSION['user'];
    echo "<h1>welcome " . $user . "</h1>";
} else {
    header('location:index.php');
}
?>

<h2><a href="logout.php">Logout</a><br></h2>

<?php
$mysqli = mysqli_connect("localhost", "root", "", "test");
if (mysqli_connect_errno()) {
    printf("%s \n", mysqli_connect_error());
    exit();
}


$sql = "SELECT item_id, item_name FROM item";
$result = $mysqli->query($sql);
echo "<br><h2>this is items</h2>";

?>
<div class="container">
    <table class="table">
        <thead>
            <tr>
                <th>Items</th>
            </tr>
        </thead>
        <?php

        if ($result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) {
        ?>
                <tbody>
                    <tr>
                        <td><?php echo $row["item_name"]; ?></td>
                        <td>
                            <form method="POST"><input type="submit" value="submit"/></form>
                        </td>
                    </tr>
                </tbody>
        <?php
            }
        } else {
            echo "0 results";
        }
        ?>
    </table>
</div>

<?php

$mysqli = mysqli_connect("localhost", "root", "", "test");
if (mysqli_connect_errno()) {
    printf("%s \n", mysqli_connect_error());
    exit();
}

if (isset($_POST['submit'])) 
{
    $getid = "SELECT `id` FROM `userdata` WHERE user=$user";
    $item_id = $row["item_id"];
    $cart = 1;
    $sql2 = "INSERT INTO cart (cart_id, id, item_id, quantity) VALUES (1,$getid, $item_id, $cart)";
    $res = mysqli_query($mysqli, $sql2);

    if ($res === TRUE) 
        echo "inserted";
    else 
        printf("not insert record: %s\n", mysqli_error($mysqli));
}



$mysqli->close();
?>