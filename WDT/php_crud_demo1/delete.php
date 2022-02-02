<?php
$id=$_GET['id'];
$conn=mysqli_connect("localhost","root","","bsrdb");
$res=mysqli_query($conn,"DELETE FROM `tbl` WHERE `id`=$id");
echo "record deleted";
?>