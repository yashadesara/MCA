<?php
session_start();
$msg="";
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
Fname:<input type="text" name="fname">
<br>
Lname:<input type="text" name="lname">
<br>
<input type="submit" name="action" value="insert">
<br>
</form>
<?php
include("display.php");
?>