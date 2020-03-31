	.file	1 "testing/s_files/call_recursive_internal.s"
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
	addiu	$sp,$sp,-8
	sw		$31,4($sp)
	sw		$fp,0($sp)
	move	$fp,$sp
	sw		$4,8($fp)
	lw		$2,8($fp)
	nop
	li		$3,0
	xor	$2,$2,$3
	sltu	$2,$2,1
	andi	$2,$2,0x00ff
	beq		$2,$0,$L1
	nop
	move		$2,$0
	b		$fEND
	nop
$L1:
	lw		$2,8($fp)
	nop
	li		$3,1
	subu	$2,$2,$3
	lw		$2,12($fp)
	nop
	move	$4,$2
	jal	f
	nop
