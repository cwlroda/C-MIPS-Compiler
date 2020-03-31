	.file	1 "testing/s_files/multiply.s"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls


	.text
	.align	2
	.globl	multiply
	.set	nomips16
	.set	nomicromips
	.ent	multiply
	.type	multiply, @function
multiply:
	addiu	$sp,$sp,-32
	sw		$31,28($sp)
	sw		$fp,24($sp)
	move	$fp,$sp
	sw		$4,32($fp)
	sw		$5,36($fp)
	li		$2,0
	sw		$2,8($fp)
	lw		$2,32($fp)
	nop
	li		$3,0
	slt	$2,$2,$3
	andi	$2,$2,0x00ff
	beq		$2,$0,$L1
	nop
	lw		$2,32($fp)
	nop
	subu	$2,$0,$2
	sw		$2,4($fp)
