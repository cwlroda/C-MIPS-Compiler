	.file	1 "test/main.s"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls


	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	addiu	$sp,$sp,-32
	sw		$31,28($sp)
	sw		$fp,24($sp)
	move	$fp,$sp
	li		$2,10
	sw		$2,8($fp)
	li		$2,10
	sw		$2,12($fp)
	li		$2,10
	sw		$2,16($fp)
	move	$16,$2
$mainEND:
	move	$sp,$fp
	lw		$31,28($sp)
	lw		$fp,24($sp)
	addiu	$sp,$sp,32
	j		$31
	nop

