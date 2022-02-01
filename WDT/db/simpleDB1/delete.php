<?php
include("conn.php");
$id=$_GET['id'];	
$sql = "delete from testTable where id=$id";

$res = mysqli_query($mysqli, $sql);	 
if ($res === TRUE) {
	echo "A record has been deleted.";
} else {
	printf("Could not delete record: %s\n", mysqli_error($mysqli));
}
mysqli_close($mysqli);
include("display.php");
?>
