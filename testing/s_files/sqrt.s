	.file	1 "testing/s_files/sqrt.s"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls


	.text
	.align	2
	.globl	bsqrt
	.set	nomips16
	.set	nomicromips
	.ent	bsqrt
	.type	bsqrt, @function
bsqrt:
	addiu	$sp,$sp,-8
	sw		$31,4($sp)
	sw		$fp,0($sp)
	move	$fp,$sp
	sw		$4,8($fp)
	sw		$5,12($fp)
	sw		$6,16($fp)
	b		$L2
	nop

$L1:
	lw		$2,8($fp)
	nop
	lw		$3,16($fp)
	nop
	addu	$2,$2,$3
	li		$3,1
	sra	$2,$2,$3
	sw		$2,8($fp)
	lw		$2,8($fp)
	nop
	lw		$3,8($fp)
	nop
	mult	$2,$3
	mflo	$2
	sw		$2,12($fp)
	lw		$2,12($fp)
	nop
	lw		$3,12($fp)
	nop
	slt	$2,$3,$2
	xori	$2,$2,0x1
	andi	$2,$2,0x00ff
	beq		$2,$0,$L3
	nop
	sw		$2,8($fp)
	b		$L4
	nop
$L3:
	lw		$2,8($fp)
	sw		$2,16($fp)
$L4:
$L2CONT:
	nop
$L2:
	lw		$2,8($fp)
	nop
	li		$3,1
	addu	$2,$2,$3
	lw		$2,16($fp)
	nop
	lw		$3,16($fp)
	nop
	slt	$2,$2,$3
	andi	$2,$2,0x00ff
	bne		$2,$0,$L1
	nop
$L2END:
	lw		$2,8($fp)
	nop
	lw		$3,8($fp)
	nop
	mult	$2,$3
	mflo	$2
	lw		$2,8($fp)
	nop
	lw		$3,12($fp)
	nop
	slt	$2,$2,$3
	andi	$2,$2,0x00ff
	beq		$2,$0,$L6
	nop
	lw		$2,20($fp)
	nop
	b		$bsqrtEND
	nop
	b		$L7
	nop
$L6:
	lw		$2,12($fp)
	nop
	b		$bsqrtEND
	nop
$L7:
$bsqrtEND:
	move	$16,$2
	move	$sp,$fp
	lw		$31,4($sp)
	lw		$fp,0($sp)
	addiu	$sp,$sp,8
	j		$31
	nop

