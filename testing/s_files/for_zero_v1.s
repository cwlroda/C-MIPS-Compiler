	.file	1 "testing/s_files/for_zero_v1.s"
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
	addiu	$sp,$sp,-16
	sw		$31,12($sp)
	sw		$fp,8($sp)
	move	$fp,$sp
	sw		$0,8($fp)
	li		$2,0
	sw		$2,8($fp)
	b		$L1
	nop

$L2:
	li		$2,1
	b		$fEND
	nop
$L2CONT:
	lw		$2,8($fp)
	nop
	li		$3,1
	addu	$2,$2,$3
	sw		$2,8($fp)
$L1:
	lw		$2,8($fp)
	nop
	li		$3,0
	slt	$2,$2,$3
	andi	$2,$2,0x00ff
	bne		$2,$0,$L2
	nop
$L2END:
	nop
	li		$2,19937
	b		$fEND
	nop
$fEND:
	move	$16,$2
	move	$sp,$fp
	lw		$31,12($sp)
	lw		$fp,8($sp)
	addiu	$sp,$sp,16
	j		$31
	nop

