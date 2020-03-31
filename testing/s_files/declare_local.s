	.file	1 "testing/s_files/declare_local.s"
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
	addiu	$sp,$sp,-16
	sw		$31,12($sp)
	sw		$fp,8($sp)
	move	$fp,$sp
	sw		$0,8($fp)
