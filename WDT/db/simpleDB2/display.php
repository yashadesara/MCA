<?php
include("conn.php");	
$sql = "select id, fname, mname, lname from testTable ";
$sql .= " order by id";

$res = mysqli_query($mysqli, $sql);
//	var_dump($res);
if($res->num_rows>0)
{
	//echo "Show records";
	echo "<table border='1' cellpadding='5px'>";
	while($row = mysqli_fetch_array($res, MYSQLI_ASSOC))
	{
		$id=$row['id'];
		$fname=$row['fname'];
		$mname=$row['mname'];
		$lname=$row['lname'];
		echo "<tr><td>$id</td><td>$fname</td>";
		echo "<td>$mname</td><td>$lname</td>";
		//echo "<td><a href='delete.php?id=$id'>delete</a></td>";
		echo "<td><a href='index.php?id=$id'>edit</a></td>";
		echo "<td><a href='delete.php?id=$id' ";
		echo " onclick=\"return confirm('r u sure u want to delete?');\">delete</a></td>";
		echo "</tr>";	

	}
	echo "</table>";
	
}
else
{
	echo "no records available";
}


?>
<br/>
<a href="index.php">insert</a>