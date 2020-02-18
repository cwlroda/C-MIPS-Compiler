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
	jmp	LBB0_1
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
	movb	%al, %cl
	testb	$1, %cl
	jne	LBB0_2
	jmp	LBB0_3
LBB0_2:                                 ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_1
LBB0_3:
	movl	$19937, %eax            ## imm = 0x4DE1
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
