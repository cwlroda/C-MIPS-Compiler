	.file	1 "testing/s_files/index_expression.s"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls


	.text
	.align	2
	.globl	f
	.set	nomips16
	.set	nomicromips
	.ent	f
	.type	f, @function
f:
	addiu	$sp,$sp,-32
	sw		$31,28($sp)
	sw		$fp,24($sp)
	move	$fp,$sp
	sw		$0,8($fp)
