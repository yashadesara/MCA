<?php
$fname=$_POST['fname'];
$lname=$_POST['lname'];
$conn=mysqli_connect("localhost","root","","bsrdb");
$res=mysqli_query($conn,"INSERT INTO `tbl`( `fname`, `lname`) VALUES ('$fname','$lname')");
echo "record inserted";
?>