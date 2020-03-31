	.file	1 "testing/s_files/if_else_true.s"
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
	beq		$2,$0,$L1
	nop
	li		$2,11
	b		$fEND
	nop
	b		$L2
	nop
$L1:
	li		$2,10
	b		$fEND
	nop
$L2:
$fEND:
	move	$16,$2
	move	$sp,$fp
	lw		$31,4($sp)
	lw		$fp,0($sp)
	addiu	$sp,$sp,8
	j		$31
	nop

