	.file	1 "testing/s_files/call_mutual_recursive.s"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls

	.data
	.globl	n
	.align	2
	.type	n, @object
	.size	n, 4
n:
	.word	0


	.text
	.align	2
	.globl	r1
	.set	nomips16
	.set	nomicromips
	.ent	r1
	.type	r1, @function
r1:
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
	li		$2,1
	b		$r1END
	nop
	b		$L2
	nop
$L1:
	lw		$2,8($fp)
	nop
	li		$3,1
	subu	$2,$2,$3
