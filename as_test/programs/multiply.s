	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_multiply               ## -- Begin function multiply
	.p2align	4, 0x90
_multiply:                              ## @multiply
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	%edi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	$0, -16(%rbp)
	cmpl	$0, -8(%rbp)
	jge	LBB0_2
## %bb.1:
	xorl	%eax, %eax
	subl	-8(%rbp), %eax
	movl	-12(%rbp), %esi
	movl	%eax, %edi
	callq	_multiply
	xorl	%esi, %esi
	subl	%eax, %esi
	movl	%esi, -4(%rbp)
	jmp	LBB0_6
LBB0_2:
	jmp	LBB0_3
LBB0_3:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -8(%rbp)
	jle	LBB0_5
## %bb.4:                               ##   in Loop: Header=BB0_3 Depth=1
	movl	-12(%rbp), %eax
	addl	-16(%rbp), %eax
	movl	%eax, -16(%rbp)
	movl	-8(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB0_3
LBB0_5:
	movl	-16(%rbp), %eax
	movl	%eax, -4(%rbp)
LBB0_6:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
