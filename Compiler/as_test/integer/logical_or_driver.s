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
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movl	$15, %edi
	movl	$240, %esi
	callq	_f
	cmpl	$1, %eax
	je	LBB0_2
## %bb.1:
	movl	$1, -4(%rbp)
	jmp	LBB0_9
LBB0_2:
	xorl	%edi, %edi
	movl	$240, %esi
	callq	_f
	cmpl	$1, %eax
	je	LBB0_4
## %bb.3:
	movl	$1, -4(%rbp)
	jmp	LBB0_9
LBB0_4:
	xorl	%esi, %esi
	movl	$15, %edi
	callq	_f
	cmpl	$1, %eax
	je	LBB0_6
## %bb.5:
	movl	$1, -4(%rbp)
	jmp	LBB0_9
LBB0_6:
	xorl	%eax, %eax
	movl	%eax, %edi
	movl	%eax, %esi
	callq	_f
	cmpl	$0, %eax
	je	LBB0_8
## %bb.7:
	movl	$1, -4(%rbp)
	jmp	LBB0_9
LBB0_8:
	movl	$0, -4(%rbp)
LBB0_9:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
