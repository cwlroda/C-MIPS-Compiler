	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function main
LCPI0_0:
	.quad	4626885667169763328     ## double 22
LCPI0_1:
	.quad	4622382067542392832     ## double 11
LCPI0_2:
	.quad	4611686018427387904     ## double 2
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
	movsd	LCPI0_1(%rip), %xmm0    ## xmm0 = mem[0],zero
	movsd	LCPI0_2(%rip), %xmm1    ## xmm1 = mem[0],zero
	movl	$0, -4(%rbp)
	callq	_f
	movsd	LCPI0_0(%rip), %xmm1    ## xmm1 = mem[0],zero
	ucomisd	%xmm1, %xmm0
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
