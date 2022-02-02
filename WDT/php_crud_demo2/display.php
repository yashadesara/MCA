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
			<a href='edit.php?id=<?=$id?>' >Edit</a>
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