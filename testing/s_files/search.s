	.file	1 "testing/s_files/search.s"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls


	.text
	.align	2
	.globl	search
	.set	nomips16
	.set	nomicromips
	.ent	search
	.type	search, @function
search:
	addiu	$sp,$sp,-8
	sw		$31,4($sp)
	sw		$fp,0($sp)
	move	$fp,$sp
	sw		$4,8($fp)
	sw		$5,12($fp)
	b		$L2
	nop

$L1:
	lw		$2,8($fp)
	nop
	lw		$3,12($fp)
	nop
	xor	$2,$2,$3
	sltu	$2,$2,1
	andi	$2,$2,0x00ff
	beq		$2,$0,$L3
	nop
	lw		$2,12($fp)
	nop
	b		$searchEND
	nop
$L3:
	lw		$2,8($fp)
	nop
	li		$3,1
	addu	$2,$2,$3
	sw		$2,8($fp)
$L2CONT:
	nop
$L2:
	bne		$2,$0,$L1
	nop
$L2END:
	move		$2,$0
	b		$searchEND
	nop
$searchEND:
	move	$16,$2
	move	$sp,$fp
	lw		$31,4($sp)
	lw		$fp,0($sp)
	addiu	$sp,$sp,8
	j		$31
	nop

