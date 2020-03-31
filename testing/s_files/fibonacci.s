	.file	1 "testing/s_files/fibonacci.s"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls


	.text
	.align	2
	.globl	fib
	.set	nomips16
	.set	nomicromips
	.ent	fib
	.type	fib, @function
fib:
	addiu	$sp,$sp,-8
	sw		$31,4($sp)
	sw		$fp,0($sp)
	move	$fp,$sp
	sw		$4,8($fp)
	lw		$2,8($fp)
	nop
	li		$3,0
	slt	$2,$3,$2
	xori	$2,$2,0x1
	andi	$2,$2,0x00ff
	beq		$2,$0,$L1
	nop
	move		$2,$0
	b		$fibEND
	nop
$L1:
	lw		$2,8($fp)
	nop
	li		$3,1
	xor	$2,$2,$3
	sltu	$2,$2,1
	andi	$2,$2,0x00ff
	beq		$2,$0,$L2
	nop
	li		$2,1
	b		$fibEND
	nop
$L2:
	lw		$2,8($fp)
	nop
	li		$3,1
	subu	$2,$2,$3
