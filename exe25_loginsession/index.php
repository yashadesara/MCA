<?php session_start(); ?>
<form method="POST">
    <input type="text" name='user'><br><br>
    <input type="password" name='pass'><br><br>
    <input type="submit" value="Login">
</form>

<?php
$mysqli = mysqli_connect("localhost","root","","test");
if(mysqli_connect_errno())
{
    printf("%s \n",mysqli_connect_error());
    exit();
}

if ($_POST) {

    $user = $_POST['user'];
    $pass = $_POST['pass'];
    $sql = "select 'id', 'user', 'pass' from userdata where user='$user' and pass='$pass'";
    $res = mysqli_query($mysqli, $sql);

    if ($res->num_rows > 0) {
        $row = mysqli_fetch_array($res, MYSQLI_ASSOC);
        $_SESSION['id'] = $row['id'];
        $_SESSION['user'] = $user;
        echo 'success';
        header('location:next.php');
    } else {
        echo 'failed';
    }
}
?>