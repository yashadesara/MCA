<?php
include("conn.php");
$fname=$_POST['fname'];
$mname=$_POST['mname'];
$lname=$_POST['lname'];
$sql = "INSERT INTO testTable (fname, mname, lname) VALUES ('$fname','$mname','$lname')";
$res = mysqli_query($mysqli, $sql);
if ($res === TRUE) {
	echo "A record has been inserted.";
} else {
	printf("Could not insert record: %s\n", mysqli_error($mysqli));
}
mysqli_close($mysqli);
include("display.php");
?>
