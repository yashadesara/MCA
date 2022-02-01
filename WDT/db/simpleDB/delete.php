<?php
$mysqli = mysqli_connect("localhost", "root", "", "jvims");

if (mysqli_connect_errno()) {
	printf("Connect failed: %s\n", mysqli_connect_error());
	exit();
} 
else 
{
	$id=$_GET['id'];	
	$sql = "delete from testTable where id=$id";
	echo $sql;
	$res = mysqli_query($mysqli, $sql);	 
	if ($res === TRUE) {
	   	echo "A record has been deleted.";
	} else {
		printf("Could not delete record: %s\n", mysqli_error($mysqli));
	}
	mysqli_close($mysqli);
}
?>
