	.file	1 "testing/s_files/test_LOCAL.s"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls


	.text
	.align	2
	.globl	ffff
	.set	nomips16
	.set	nomicromips
	.ent	ffff
	.type	ffff, @function
ffff:
	addiu	$sp,$sp,-24
	sw		$31,20($sp)
	sw		$fp,16($sp)
	move	$fp,$sp
	sw		$0,8($fp)
	li		$2,10
	sw		$2,8($fp)
	lw		$2,8($fp)
	nop
	b		$ffffEND
	nop
$ffffEND:
	move	$16,$2
	move	$sp,$fp
	lw		$31,20($sp)
	lw		$fp,16($sp)
	addiu	$sp,$sp,24
	j		$31
	nop

