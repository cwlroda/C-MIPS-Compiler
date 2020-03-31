	.file	1 "testing/s_files/for_multiple.s"
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
	sw		$0,12($fp)
	li		$2,0
	sw		$2,12($fp)
	li		$2,0
	sw		$2,8($fp)
	b		$L1
	nop

$L2:
	lw		$2,12($fp)
	nop
	li		$3,1
	subu	$2,$2,$3
	sw		$2,12($fp)
$L2CONT:
	lw		$2,8($fp)
	nop
	li		$3,1
	addu	$2,$2,$3
	sw		$2,8($fp)
$L1:
	lw		$2,8($fp)
	nop
	li		$3,10
	slt	$2,$2,$3
	andi	$2,$2,0x00ff
	bne		$2,$0,$L2
	nop
$L2END:
	nop
	lw		$2,12($fp)
	nop
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

