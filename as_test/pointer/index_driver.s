	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	leaq	-16(%rbp), %rdi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -20(%rbp)
	movl	$13, -12(%rbp)
	movb	$0, %al
	callq	_f
	cmpl	$13, %eax
	sete	%cl
	xorb	$-1, %cl
	andb	$1, %cl
	movzbl	%cl, %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rdi
	movq	(%rdi), %rdi
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rdi
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	jne	LBB0_2
## %bb.1:
	movl	-24(%rbp), %eax         ## 4-byte Reload
	addq	$32, %rsp
	popq	%rbp
	retq
LBB0_2:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
