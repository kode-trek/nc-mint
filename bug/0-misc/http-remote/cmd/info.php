<style>
table, th, td {
	border: 1px solid black;
}
</style>
<?php
	function f1() {return system('uname -s');}
	function f2() {return system('uname -n');}
	function f3() {return system('uname -r');}
	function f4() {return system('uname -v');}
	function f5() {return system('uname -m');}
	function f6() {return system('uname -p');}
	function f7() {return system('uname -i');}
	function f8() {return system('uname -o');}
	function f9() {return system('hostname -I');}
	function f10() {return system('curl ifconfig.me');}
?>
<h2>system information</h2>
<table>
<!-- row1 -->
	<tr>
		<td><b>kernel-name</b></td>
		<td><pre><?php f1(); ?></pre></td>
	</tr>
<!-- row2 -->
	<tr>
		<td><b>node-name</b></td>
		<td><pre><?php f2(); ?></pre></td>
	</tr>
<!-- row3 -->
	<tr>
		<td><b>kernel--release</b></td>
		<td><pre><?php f3(); ?></pre></td>
	</tr>
<!-- row4 -->
	<tr>
		<td><b>kernel-version</b></td>
		<td><pre><?php f4(); ?></pre></td>
	</tr>
<!-- row5 -->
	<tr>
		<td><b>machine</b></td>
		<td><pre><?php f5(); ?></pre></td>
	</tr>
<!-- row6 -->
	<tr>
		<td><b>processor</b></td>
		<td><pre><?php f6(); ?></pre></td>
	</tr>
<!-- row7 -->
	<tr>
		<td><b>hardware-platform</b></td>
		<td><pre><?php f7(); ?></pre></td>
	</tr>
<!-- row8 -->
	<tr>
		<td><b>operating-system</b></td>
		<td><pre><?php f8(); ?></pre></td>
	</tr>
	<tr>
<!-- row9 -->
	<td><b>private-ip:</b></td>
		<td><pre><?php f9(); ?></pre></td>
	</tr>
<!-- row10 -->
	<td><b>public-ip:</b></td>
		<td><pre><?php f10(); ?></pre></td>
	</tr>
</table>
