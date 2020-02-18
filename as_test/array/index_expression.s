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
	subq	$64, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$8, -52(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$16, -52(%rbp)
	jge	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-52(%rbp), %eax
	movl	-52(%rbp), %ecx
	subl	$8, %ecx
	movslq	%ecx, %rdx
	movl	%eax, -48(%rbp,%rdx,4)
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-52(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -52(%rbp)
	jmp	LBB0_1
LBB0_4:
	movl	$0, -56(%rbp)
	movl	$0, -52(%rbp)
LBB0_5:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$8, -52(%rbp)
	jge	LBB0_8
## %bb.6:                               ##   in Loop: Header=BB0_5 Depth=1
	movl	-56(%rbp), %eax
	movl	-52(%rbp), %ecx
	addl	$0, %ecx
	movslq	%ecx, %rdx
	addl	-48(%rbp,%rdx,4), %eax
	movl	%eax, -56(%rbp)
## %bb.7:                               ##   in Loop: Header=BB0_5 Depth=1
	movl	-52(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -52(%rbp)
	jmp	LBB0_5
LBB0_8:
	movl	-56(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -60(%rbp)         ## 4-byte Spill
	jne	LBB0_10
## %bb.9:
	movl	-60(%rbp), %eax         ## 4-byte Reload
	addq	$64, %rsp
	popq	%rbp
	retq
LBB0_10:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
