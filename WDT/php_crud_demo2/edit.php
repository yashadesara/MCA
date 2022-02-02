<?php
$id=$_GET['id'] ;
$conn=mysqli_connect("localhost","root","","bsrdb");
$res=mysqli_query($conn,"SELECT `id`, `fname`, `lname` FROM `tbl` where id=$id");

if($res->num_rows>0)
{
	$row=mysqli_fetch_assoc($res);
	$id=$row['id'];
	$fname=$row['fname'];
	$lname=$row['lname'];
?>
<form action="update.php" method="post">
<br>
<input type="hidden" name="id" value="<?=$id?>">
Fname:<input type="text" name="fname" value="<?=$fname?>">
<br>
Lname:<input type="text" name="lname" value="<?php echo $lname; ?>">
<br>
<input type="submit" value="submit">
<br>
</form>
<?php	
}
?>
