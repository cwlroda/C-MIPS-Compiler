	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.section	__TEXT,__literal4,4byte_literals
	.p2align	2               ## -- Begin function main
LCPI0_0:
	.long	1094713344              ## float 12
LCPI0_1:
	.long	1093664768              ## float 11
LCPI0_2:
	.long	1065353216              ## float 1
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
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
	movss	LCPI0_1(%rip), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movss	LCPI0_2(%rip), %xmm1    ## xmm1 = mem[0],zero,zero,zero
	movl	$0, -4(%rbp)
	callq	_f
	movss	LCPI0_0(%rip), %xmm1    ## xmm1 = mem[0],zero,zero,zero
	ucomiss	%xmm1, %xmm0
	sete	%al
	setnp	%cl
	andb	%cl, %al
	xorb	$-1, %al
	andb	$1, %al
	movzbl	%al, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
