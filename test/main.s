	.file	1 "test/main.s"
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
	lw		$8,8($fp)
	nop
$S1C1cond:
	li		$9,1
	bne		$8,$9,$S1C2cond
	nop
$S1C1body:
	li		$2,10
	b		$gEND
	nop
	b		$S1END
	nop
$S1C2cond:
	li		$9,2
	bne		$8,$9,$S1C3cond
	nop
$S1C2body:
	li		$2,11
	b		$gEND
	nop
	b		$S1END
	nop
$S1C3cond:
$S1END:
$gEND:
	move	$16,$2
	move	$sp,$fp
	lw		$31,4($sp)
	lw		$fp,0($sp)
	addiu	$sp,$sp,8
	j		$31
	nop

