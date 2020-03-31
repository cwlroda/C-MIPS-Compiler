	.file	1 "testing/s_files/call_two_args_external.s"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls

	.data
	.globl	y
	.align	2
	.type	y, @object
	.size	y, 4
y:
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
	li		$2,10
	move	$4,$2
	li		$2,20
	move	$5,$2
	jal	g
	nop
