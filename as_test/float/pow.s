	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.section	__TEXT,__literal4,4byte_literals
	.p2align	2               ## -- Begin function f
LCPI0_0:
	.long	1065353216              ## float 1
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_f
	.p2align	4, 0x90
_f:                                     ## @f
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movss	LCPI0_0(%rip), %xmm1    ## xmm1 = mem[0],zero,zero,zero
	movss	%xmm0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movss	%xmm1, -12(%rbp)
	movl	$0, -16(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-16(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jge	LBB0_3
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	movss	-12(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	mulss	-4(%rbp), %xmm0
	movss	%xmm0, -12(%rbp)
	jmp	LBB0_1
LBB0_3:
	movss	-12(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
