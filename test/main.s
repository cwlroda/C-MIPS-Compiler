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

	li		$2,0
	sw		$2,8($fp)
	li		$2,10
	b		$fEND
$fEND:
	move	$sp,$fp
	lw		$31,20($sp)
	lw		$fp,16($sp)
	addiu	$sp,$sp,24
	j		$31
	nop

