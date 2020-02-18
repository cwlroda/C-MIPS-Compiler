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
	movl	%edi, -8(%rbp)
	movl	-8(%rbp), %edi
	movl	%edi, %eax
	subl	$1, %eax
	movl	%edi, -12(%rbp)         ## 4-byte Spill
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	je	LBB0_1
	jmp	LBB0_4
LBB0_4:
	movl	-12(%rbp), %eax         ## 4-byte Reload
	subl	$2, %eax
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	je	LBB0_2
	jmp	LBB0_3
LBB0_1:
	movl	$10, -4(%rbp)
	jmp	LBB0_3
LBB0_2:
	movl	$11, -4(%rbp)
LBB0_3:
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
