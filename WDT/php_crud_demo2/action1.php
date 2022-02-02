<?php
session_start();
$msg="";
$conn=mysqli_connect("localhost","root","","bsrdb");
$id=$_REQUEST['id']??0;
$fname=$_REQUEST['fname']??'';
$lname=$_REQUEST['lname']??'';	
if($_REQUEST['action']=='insert')
{
	$res=mysqli_query($conn,"INSERT INTO `tbl`( `fname`, `lname`) VALUES ('$fname','$lname')");
	$msg="record inserted";
}
else if($_REQUEST['action']=='update')
{
	$res=mysqli_query($conn,"UPDATE `tbl` SET  `fname`='$fname',`lname`='$lname' WHERE `id`=$id");
	$msg="record updated";
} 
else if($_REQUEST['action']=='delete')
{
	$res=mysqli_query($conn,"DELETE FROM `tbl` WHERE `id`=$id");
	$msg="record deleted";
} 
$_SESSION['$msg']=$msg;
header("location:index.php");
?>