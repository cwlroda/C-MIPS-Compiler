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
	sw		$4,24($fp)
	sw		$5,28($fp)
	li		$2,7
	sw		$2,8($fp)
	lw		$2,8($fp)
	li		$3,1
	addu	$2,$2,$3
	sw		$2,24($fp)
	lw		$2,24($fp)
	li		$3,2
	addu	$2,$2,$3
	sw		$2,28($fp)
	move	$16,$2
$fEND:
	move	$sp,$fp
	lw		$31,20($sp)
	lw		$fp,16($sp)
	addiu	$sp,$sp,24
	j		$31
	nop


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
	li		$2,6
	sw		$2,8($fp)
	li		$2,7
	sw		$2,12($fp)
	lw		$2,8($fp)
	nop
	move	$4,$2
	lw		$2,12($fp)
	nop
	move	$5,$2
	jal	f
	nop
	move		$2,$0
	b		$mainEND
	move	$16,$2
$mainEND:
	move	$sp,$fp
	lw		$31,28($sp)
	lw		$fp,24($sp)
	addiu	$sp,$sp,32
	j		$31
	nop

