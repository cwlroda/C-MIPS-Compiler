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
	addiu	$sp,$sp,-64
	sw		$31,60($sp)
	sw		$fp,56($sp)
	move	$fp,$sp
	li	$2,1
	move	$4,$2
	li	$2,2
	move	$5,$2
	li	$2,3
	move	$6,$2
	li	$2,4
	move	$7,$2
	li	$2,5
	sw	$2,16($sp)
	li	$2,6
	sw	$2,20($sp)
	jal	f
	nop
	move	$16,$2
$mainEND:
	move	$sp,$fp
	lw		$31,60($sp)
	lw		$fp,56($sp)
	addiu	$sp,$sp,64
	j		$31
	nop


	.text
	.align	2
	.globl	f
	.set	nomips16
	.set	nomicromips
	.ent	f
	.type	f, @function
f:
	addiu	$sp,$sp,-8
	sw		$31,4($sp)
	sw		$fp,0($sp)
	move	$fp,$sp
