	.file	1 "testing/s_files/switch2.s"
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
	addiu	$sp,$sp,-24
	sw		$31,20($sp)
	sw		$fp,16($sp)
	move	$fp,$sp
	sw		$4,24($fp)
	sw		$0,8($fp)
	li		$2,0
	sw		$2,8($fp)
	lw		$8,4
	nop
$S1C1cond:
	li		$9,0
	bne		$8,$9,$S1C2cond
	nop
$S1C1body:
	li		$2,1
	sw		$2,8($fp)
	b		$S1END
	nop
