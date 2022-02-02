<?php
session_start();
$msg="";
$conn=mysqli_connect("localhost","root","","bsrdb");
if($_REQUEST['action']=='insert')
{
	//echo "insert";
	$fname=$_POST['fname'];
	$lname=$_POST['lname'];	
	$res=mysqli_query($conn,"INSERT INTO `tbl`( `fname`, `lname`) VALUES ('$fname','$lname')");
	$msg="record inserted";
}
else if($_REQUEST['action']=='update')
{
	//echo "update";
	$id=$_POST['id'];
	$fname=$_POST['fname'];
	$lname=$_POST['lname'];	
	$res=mysqli_query($conn,"UPDATE `tbl` SET  `fname`='$fname',`lname`='$lname' WHERE `id`=$id");
	$msg="record updated";
} 
else if($_REQUEST['action']=='delete')
{
	$id=$_GET['id'];	
	$res=mysqli_query($conn,"DELETE FROM `tbl` WHERE `id`=$id");
	$msg="record deleted";
} 
$_SESSION['msg']=$msg;
header("location:index.php");
?>