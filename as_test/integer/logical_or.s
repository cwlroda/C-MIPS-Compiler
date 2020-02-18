	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_f                      ## -- Begin function f
	.p2align	4, 0x90
_f:                                     ## @f
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$0, -4(%rbp)
	movb	$1, %al
	movb	%al, -9(%rbp)           ## 1-byte Spill
	jne	LBB0_2
## %bb.1:
	cmpl	$0, -8(%rbp)
	setne	%al
	movb	%al, -9(%rbp)           ## 1-byte Spill
LBB0_2:
	movb	-9(%rbp), %al           ## 1-byte Reload
	andb	$1, %al
	movzbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
