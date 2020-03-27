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
	addiu	$sp,$sp,-40
	sw		$31,36($sp)
	sw		$fp,32($sp)
	move	$fp,$sp

	li		$2,1
	sw		$2,8($fp)

	li		$2,2
	sw		$2,12($fp)

	li		$2,3
	sw		$2,16($fp)

	li		$2,4
	sw		$2,20($fp)

	li		$2,5
	sw		$2,24($fp)

	li		$2,6
	sw		$2,28($fp)
	lw	$2,12($fp)
	lw	$3,16($fp)
	nop
	addu	$2,$3,$2
	lw	$3,24($fp)
	nop
	mult	$2,$3,$2
	mflo	$2
	li	$3,0
IM HERE BIJ
	subu	$2,$3,$2
	lw	$3,28($fp)
	nop
	beq	$2,$0,$L4
	div	$0,$3,$2
$L4:
	mfhi	$2
	mflo	$2
	li	$3,20
	and	$2,$3,$2
	li	$3,20
	nop
	or	$2,$3,$2
	bne	$2,$0,$L1
	nop
	beq	$2,$0,$L5
	nop
	lw	$3,16($fp)
	nop
	slt	$2,$2,$3
	andi	$2,$2,0x00ff
	lw	$3,20($fp)
	nop
	slt	$2,$3,$2
	andi	$2,$2,0x00ff
	lw	$3,24($fp)
	nop
	slt	$2,$3,$2
	xori	$2,$2,0x1
	andi	$2,$2,0x00ff
	lw	$3,28($fp)
	nop
	sll	$2,$3,$2
	li	$3,8
	sra	$2,$3,$2
	li	$3,8
	slt	$2,$2,$3
	xori	$2,$2,0x1
	andi	$2,$2,0x00ff
	li	$3,8
	xor	$2,$3,$2
	li	$2,8
	beq	$2,$0,$L5
	nop

$L5:
	move	$2,$0
$L6:
	li	$2,8
	beq	$2,$0,$L2
	nop

$L1:
	li	$2,1
	b	$L3
nop

$L2:
	move	$2,$0
$L3:
	sw		$2,28($fp)
	li		$2,10
	j		$mainEND
$mainEND:
	move	$sp,$fp
	lw		$31,36($sp)
	lw		$fp,32($sp)
	addiu	$sp,$sp,40
	j		$31
	nop


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
	li		$2,5
	j		$fEND
$fEND:
	move	$sp,$fp
	lw		$31,4($sp)
	lw		$fp,0($sp)
	addiu	$sp,$sp,8
	j		$31
	nop

