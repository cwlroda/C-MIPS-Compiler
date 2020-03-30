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
hi
	li		$2,0
	sw		$2,8($fp)
	lw		$2,8($fp)
	nop
	li		$3,1
	addu	$2,$2,$3
	lw		$2,8($fp)
	nop
	li		$3,1
	addu	$2,$2,$3
$S1C1cond:
	bne	$2,$3,$S1C2cond
	nop
$S1C1body:
	li		$2,0
	sw		$2,20($fp)
	b		$S1END
$S1C3cond:
	bne	$2,$3,$S1C4cond
	nop
$S1C3body:
	lw		$2,8($fp)
	nop
	li		$3,1
	addu	$2,$2,$3
	sw		$2,20($fp)
	b		$S1END
$DEFAULT1:
	li		$2,777
	sw		$2,20($fp)
	b		$S1END
$S1END:
	move	$16,$2
$mainEND:
	move	$sp,$fp
	lw		$31,12($sp)
	lw		$fp,8($sp)
	addiu	$sp,$sp,16
	j		$31
	nop

