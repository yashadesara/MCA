<?php
$id=$_POST['id'];
$fname=$_POST['fname'];
$lname=$_POST['lname'];
$conn=mysqli_connect("localhost","root","","bsrdb");
$res=mysqli_query($conn,"UPDATE `tbl` SET  `fname`='$fname',`lname`='$lname' WHERE `id`=$id");
echo "record updated";
?>