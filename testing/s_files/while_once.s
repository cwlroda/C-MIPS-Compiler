	.file	1 "testing/s_files/while_once.s"
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
	li		$2,1
	sw		$2,8($fp)
	b		$L2
	nop

$L1:
	li		$2,0
	sw		$2,8($fp)
$L2CONT:
	nop
$L2:
	bne		$2,$0,$L1
	nop
$L2END:
	li		$2,19937
	b		$fEND
	nop
$fEND:
	move	$16,$2
	move	$sp,$fp
	lw		$31,20($sp)
	lw		$fp,16($sp)
	addiu	$sp,$sp,24
	j		$31
	nop

