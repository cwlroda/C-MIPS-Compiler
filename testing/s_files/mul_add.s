	.file	1 "testing/s_files/mul_add.s"
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
	addiu	$sp,$sp,-8
	sw		$31,4($sp)
	sw		$fp,0($sp)
	move	$fp,$sp
	sw		$4,8($fp)
	sw		$5,12($fp)
	sw		$6,16($fp)
	lw		$2,16($fp)
	nop
	lw		$3,8($fp)
	nop
	mul	$2,$2,$3
	mflo	$2
	lw		$3,12($fp)
	nop
	addu	$2,$2,$3
	b		$fEND
	nop
$fEND:
	move	$16,$2
	move	$sp,$fp
	lw		$31,4($sp)
	lw		$fp,0($sp)
	addiu	$sp,$sp,8
	j		$31
	nop

