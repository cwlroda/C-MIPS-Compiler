	.file	1 "testing/s_files/call_constant_external.s"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module fp=xx
	.module nooddspreg
	.abicalls

	.data
	.globl	0
	.align	2
	.type	0, @object
	.size	0, 4
0:
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
	jal	g
	nop
