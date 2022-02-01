<?php	include("conn.php"); ?>
<?php 
$id  = "";
$fname = "";
$mname = "";
$lname = "";
$action_url="insert.php";
$action="insert";

if(isset($_GET["id"]))
{

	$id=$_GET['id'];
	$sql = "select id, fname, mname, lname from testTable ";
	$sql .= " where id=$id";
	$res = mysqli_query($mysqli, $sql);	
	if($res->num_rows)
	{		
		$action_url="update.php";
		$action="update";

		$row = mysqli_fetch_array($res, MYSQLI_ASSOC);
		$id  = $row['id'];
		$fname = $row['fname'];
		$mname = $row['mname'];
		$lname = $row['lname'];
	}
}
?>

<form action="<?=$action_url?>" method="POST">
	<input type="hidden" name="id" value="<?=$id?>">
	<br/>First Name : <input type="text" name="fname" id="fname" value="<?=$fname?>">
	<br/>Middle Name : <input type="text" name="mname" id="mname" value="<?=$mname?>">
	<br/>Last Name : <input type="text" name="lname" id="lname" value="<?=$lname?>">		
	<br/><input type="submit" value="<?=$action?>" name="action">
</form>
<?php include("display.php"); ?>