<?php
session_start();
$msg="";
$id="";
$lname="";
$fname="";
$action='insert';
if(isset($_GET['id']))
{
	$id=$_GET['id'] ;
	$conn=mysqli_connect("localhost","root","","bsrdb");
	$res=mysqli_query($conn,"SELECT `id`, `fname`, `lname` FROM `tbl` where id=$id");
	if($res->num_rows>0)
	{
		$row=mysqli_fetch_assoc($res);
		$id=$row['id'];
		$fname=$row['fname'];
		$lname=$row['lname'];
		$action='update';
	}
}
if(isset($_SESSION['msg']))
{
	$msg=$_SESSION['msg'];
	$_SESSION['msg']="";
	unset($_SESSION['msg']);
}
?>
<div>
<p><?=$msg?></p>
</div>
<form action="action.php" method="post">
<br>
<input type="hidden" name="id" value="<?=$id?>">
Fname:<input type="text" name="fname" value="<?=$fname?>">
<br>
Lname:<input type="text" name="lname" value="<?php echo $lname; ?>">
<br>
<input type="submit" name="action" value="<?=$action?>">
<br>
</form>
 
<?php
 
$conn=mysqli_connect("localhost","root","","bsrdb");
$res=mysqli_query($conn,"SELECT `id`, `fname`, `lname` FROM `tbl`");
if($res->num_rows>0)
{
	echo "<table border=1>";
	while($row=mysqli_fetch_assoc($res))
	{
		echo "<tr>";
			echo "<td>";
				echo "".$row['id'];
			echo "</td>";		
		
			echo "<td>";
				echo "".$row['fname'];
			echo "</td>";		
		
			echo "<td>";
				echo "".$row['lname'];
			echo "</td>";
			echo "<td>";
			$id=$row['id'];
			?>			
			<a href='action.php?action=delete&id=<?=$id?>' onclick="return confirm('are you sure u want to delete?');">Delete</a>
			<a href='index.php?id=<?=$id?>' >Edit</a>
			<?php
			echo "</td>";		
		echo "</tr>";
	}
	echo "</table>";
}
else
{
	echo "no rows available";
}
?>
 