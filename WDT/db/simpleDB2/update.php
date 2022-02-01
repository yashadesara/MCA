<?php
include("conn.php");
$id=$_POST['id'];
$fname=$_POST['fname'];
$mname=$_POST['mname'];
$lname=$_POST['lname'];	
$sql = "update testTable set fname='$fname', mname='$mname' ,  lname='$lname'  where id=$id";
//echo $sql;
$res = mysqli_query($mysqli, $sql);
 
if ($res === TRUE) {
	echo "A record has been updated.";
} else {
	printf("Could not delete updated: %s\n", mysqli_error($mysqli));
}
mysqli_close($mysqli);
header("location:index.php");
?>
