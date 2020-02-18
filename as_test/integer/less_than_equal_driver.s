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
	xorl	%eax, %eax
	movl	$0, -4(%rbp)
	movl	%eax, %edi
	movl	%eax, %esi
	callq	_f
	cmpl	$1, %eax
	je	LBB0_2
## %bb.1:
	movl	$1, -4(%rbp)
	jmp	LBB0_11
LBB0_2:
	xorl	%edi, %edi
	movl	$1, %esi
	callq	_f
	cmpl	$1, %eax
	je	LBB0_4
## %bb.3:
	movl	$1, -4(%rbp)
	jmp	LBB0_11
LBB0_4:
	xorl	%esi, %esi
	movl	$1, %edi
	callq	_f
	cmpl	$0, %eax
	je	LBB0_6
## %bb.5:
	movl	$1, -4(%rbp)
	jmp	LBB0_11
LBB0_6:
	movl	$4294967295, %edi       ## imm = 0xFFFFFFFF
	movl	$1, %esi
	callq	_f
	cmpl	$1, %eax
	je	LBB0_8
## %bb.7:
	movl	$1, -4(%rbp)
	jmp	LBB0_11
LBB0_8:
	movl	$1, %edi
	movl	$4294967295, %esi       ## imm = 0xFFFFFFFF
	callq	_f
	cmpl	$0, %eax
	je	LBB0_10
## %bb.9:
	movl	$1, -4(%rbp)
	jmp	LBB0_11
LBB0_10:
	movl	$0, -4(%rbp)
LBB0_11:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
