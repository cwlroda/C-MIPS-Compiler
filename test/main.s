	.file	1 "test/main.s"
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
	addiu	$sp,$sp,-24
	sw		$31,20($sp)
	sw		$fp,16($sp)
	move	$fp,$sp
	sw		$0,8($fp)
	li		$2,4
