<?php
$mysqli = mysqli_connect("localhost", "root", "", "jvims");

if (mysqli_connect_errno()) {
	printf("Connect failed: %s\n", mysqli_connect_error());
	exit();
} 
else 
{
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
}
?>
