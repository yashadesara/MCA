<?php
$mysqli = mysqli_connect("localhost", "root", "", "jvims");

if (mysqli_connect_errno()) {
	printf("Connect failed: %s\n", mysqli_connect_error());
	exit();
} 
else 
{
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
}
?>
