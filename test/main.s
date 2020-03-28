	.file	1 "test/main.s"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls

	.text
	.align	2
	.globl	test
	.set	nomips16
	.set	nomicromips
	.ent	test
	.type	test, @function
test:
	addiu	$sp,$sp,-8
	sw		$31,4($sp)
	sw		$fp,0($sp)
	move	$fp,$sp
$testEND:
	move	$sp,$fp
	lw		$31,4($sp)
	lw		$fp,0($sp)
	addiu	$sp,$sp,8
	j		$31
	nop


	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	addiu	$sp,$sp,-24
	sw		$31,20($sp)
	sw		$fp,16($sp)
	move	$fp,$sp

	li		$2,100
	sw		$2,8($fp)
	b		$L2
	nop

$L1:
	lw	$2,8($fp)
	li	$3,123456
	addu	$2,$2,$3
	sw		$2,8($fp)
	lw	$2,8($fp)
	li	$3,222222
	xor	$2,$2,$3
	sltu	$2,$2,1
	andi	$2,$2,0x00ff
	beq		$3,$0,$L3
	nop
	b		$L2END
	nop
	b		$L3
	nop
$L3:
	sw		$2,8($fp)
	b		$L4
	nop

$L5:
	li	$3,333333
	xor	$2,$2,$3
	sltu	$2,$2,1
	andi	$2,$2,0x00ff
	beq		$3,$0,$L6
	nop
	b		$L5CONT
	b		$L7
	nop
$L6:
	b		$L5END
	nop
$L7:
$L5CONT:
	li	$3,999999
	addu	$2,$2,$3
$L4:
	lw	$2,8($fp)
	li	$3,5586
	xor	$2,$2,$3
	sltu	$2,$2,1
	andi	$2,$2,0x00ff
	bne		$2,$0,$L5
	nop
$L5END:
	nop
	li	$3,44444
	xor	$2,$2,$3
	sltu	$2,$2,1
	andi	$2,$2,0x00ff
	beq		$3,$0,$L9
	nop
	b		$L2CONT
	b		$L9
	nop
$L9:
$L2CONT:
	nop
$L2:
	lw	$2,8($fp)
	li	$3,406723
	xor	$2,$2,$3
	sltu	$2,$2,1
	andi	$2,$2,0x00ff
	bne		$2,$0,$L1
	nop
$L2END:
$mainEND:
	move	$sp,$fp
	lw		$31,20($sp)
	lw		$fp,16($sp)
	addiu	$sp,$sp,24
	j		$31
	nop

