	.file	1 "testing/s_files/while_multiple.s"
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
	li		$2,20
	sw		$2,8($fp)
	b		$L2
	nop

$L1:
	lw		$2,8($fp)
	nop
	li		$3,1
	subu	$2,$2,$3
	sw		$2,8($fp)
$L2CONT:
	nop
$L2:
	lw		$2,8($fp)
	nop
	li		$3,10
	slt	$2,$3,$2
	andi	$2,$2,0x00ff
	bne		$2,$0,$L1
	nop
$L2END:
	lw		$2,8($fp)
	nop
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

