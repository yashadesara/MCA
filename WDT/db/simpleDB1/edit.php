<?php
include("conn.php");	 
$id=$_GET['id'];
$sql = "select id, fname, mname, lname from testTable ";
$sql .= " where id=$id";
$res = mysqli_query($mysqli, $sql);	
if($res->num_rows)
{		
	$row = mysqli_fetch_array($res, MYSQLI_ASSOC);
	$id  = $row['id'];
	$fname = $row['fname'];
	$mname = $row['mname'];
	$lname = $row['lname'];
	?>
	<form action="update.php" method="POST">
	<input type="hidden" name="id" value="<?=$id?>">
	<br/>First Name : <input type="text" name="fname" id="fname" value="<?=$fname?>">
	<br/>Middle Name : <input type="text" name="mname" id="mname" value="<?=$mname?>">
	<br/>Last Name : <input type="text" name="lname" id="lname" value="<?=$lname?>">		
	<br/><input type="submit" value="Update">
	</form>
	<?php		
}
else
{
	echo "No records found";
}
mysqli_close($mysqli);

?>
