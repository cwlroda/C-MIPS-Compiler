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
	addiu	$sp,$sp,-16
	sw		$31,12($sp)
	sw		$fp,8($sp)
	move	$fp,$sp
	li		$2,0
	sw		$2,8($fp)
	lw		$2,8($fp)
	nop
	li		$3,1
	addu	$2,$2,$3
	move	$8,$2
$S1C1cond:
	li		$9,1
	bne		$8,$9,$S1C2cond
	nop
$S1C1body:
	li		$2,0
	sw		$2,8($fp)
	b		$S1END
	nop
$S1C2cond:
	li		$9,2
	bne		$8,$9,$S1C3cond
	nop
$S1C2body:
	lw		$2,8($fp)
	nop
	li		$3,1
	addu	$2,$2,$3
	sw		$2,8($fp)
	b		$S1END
	nop
$S1C3cond:
	nop
$DEFAULT1:
	li		$2,777
	sw		$2,8($fp)
	b		$S1END
	nop
$S1END:
$mainEND:
	move	$16,$2
	move	$sp,$fp
	lw		$31,12($sp)
	lw		$fp,8($sp)
	addiu	$sp,$sp,16
	j		$31
	nop

