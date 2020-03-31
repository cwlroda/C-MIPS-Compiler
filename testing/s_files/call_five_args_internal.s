	.file	1 "testing/s_files/call_five_args_internal.s"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls


	.text
	.align	2
	.globl	g
	.set	nomips16
	.set	nomicromips
	.ent	g
	.type	g, @function
g:
	addiu	$sp,$sp,-8
	sw		$31,4($sp)
	sw		$fp,0($sp)
	move	$fp,$sp
	sw		$4,8($fp)
	sw		$5,12($fp)
	sw		$6,16($fp)
	sw		$7,20($fp)
	lw		$2,8($fp)
	nop
	lw		$3,24($fp)
	nop
	addu	$2,$2,$3
	lw		$3,20($fp)
	nop
	addu	$2,$2,$3
	lw		$3,16($fp)
	nop
	addu	$2,$2,$3
	lw		$3,12($fp)
	nop
	addu	$2,$2,$3
	b		$gEND
	nop
$gEND:
	move	$16,$2
	move	$sp,$fp
	lw		$31,4($sp)
	lw		$fp,0($sp)
	addiu	$sp,$sp,8
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
	li		$2,1
	move	$4,$2
	li		$2,2
	move	$5,$2
	li		$2,3
	move	$6,$2
	li		$2,4
	move	$7,$2
	li		$2,5
	sw		$2,16($sp)
	jal	g
	nop
