	.file	1 "testing/s_files/less_than_equal.s"
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
	addiu	$sp,$sp,-32
	sw		$31,28($sp)
	sw		$fp,24($sp)
	move	$fp,$sp
	sw		$4,32($fp)
	sw		$5,36($fp)
	sw		$0,8($fp)
	lw		$2,32($fp)
	nop
	lw		$3,36($fp)
	nop
	slt	$2,$3,$2
	xori	$2,$2,0x1
	andi	$2,$2,0x00ff
	sw		$2,8($fp)
	lw		$2,8($fp)
	nop
	b		$fEND
	nop
$fEND:
	move	$16,$2
	move	$sp,$fp
	lw		$31,28($sp)
	lw		$fp,24($sp)
	addiu	$sp,$sp,32
	j		$31
	nop

