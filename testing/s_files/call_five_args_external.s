	.file	1 "testing/s_files/call_five_args_external.s"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls

	.data
	.globl	e
	.align	2
	.type	e, @object
	.size	e, 4
e:
	.word	0


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
	sw		$5,12($fp)
	sw		$6,16($fp)
	sw		$7,20($fp)
	li		$2,1
	move	$4,$2
	li		$2,2
	move	$5,$2
	li		$2,3
	move	$6,$2
	li		$2,4
	move	$7,$2
	li		$2,5
	sw		$2,16($sp)
	jal	g
	nop
