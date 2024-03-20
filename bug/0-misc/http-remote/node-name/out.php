<?php include 'src.php'; ?>

<style>
table, th, td {
	border: 1px solid black;
}
</style>

<h2>system information</h2>

<table>
<!-- row1 -->
	<tr>
		<th>&emsp;</th>
		<th>&emsp;</th>
	</tr>
<!-- row2 -->
	<tr>
		<td><b>kernel-name</b></td>
		<td><pre><?php f1(); ?></pre></td>
	</tr>
<!-- row3 -->
	<tr>
		<td><b>node-name</b></td>
		<td><pre><?php f2(); ?></pre></td>
	</tr>
<!-- row4 -->
	<tr>
		<td><b>kernel--release</b></td>
		<td><pre><?php f3(); ?></pre></td>
	</tr>
<!-- row5 -->
	<tr>
		<td><b>kernel-version</b></td>
		<td><pre><?php f4(); ?></pre></td>
	</tr>
<!-- row6 -->
	<tr>
		<td><b>machine</b></td>
		<td><pre><?php f5(); ?></pre></td>
	</tr>
<!-- row7 -->
	<tr>
		<td><b>processor</b></td>
		<td><pre><?php f6(); ?></pre></td>
	</tr>
<!-- row8 -->
	<tr>
		<td><b>hardware-platform</b></td>
		<td><pre><?php f7(); ?></pre></td>
	</tr>
<!-- row9 -->
	<tr>
		<td><b>operating-system</b></td>
		<td><pre><?php f8(); ?></pre></td>
	</tr>
</table>
