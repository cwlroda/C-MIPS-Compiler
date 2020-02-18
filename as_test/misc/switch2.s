	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_g                      ## -- Begin function g
	.p2align	4, 0x90
_g:                                     ## @g
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	-4(%rbp), %edi
	testl	%edi, %edi
	movl	%edi, -12(%rbp)         ## 4-byte Spill
	je	LBB0_1
	jmp	LBB0_6
LBB0_6:
	movl	-12(%rbp), %eax         ## 4-byte Reload
	subl	$1, %eax
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	je	LBB0_3
	jmp	LBB0_7
LBB0_7:
	movl	-12(%rbp), %eax         ## 4-byte Reload
	subl	$2, %eax
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	je	LBB0_2
	jmp	LBB0_4
LBB0_1:
	movl	$1, -8(%rbp)
	jmp	LBB0_5
LBB0_2:
	movl	$2, -8(%rbp)
LBB0_3:
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB0_5
LBB0_4:
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
LBB0_5:
	movl	-8(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
