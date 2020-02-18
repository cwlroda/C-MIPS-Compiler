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
	subq	$48, %rsp
	movl	$0, -4(%rbp)
	movl	$0, -12(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$4, -12(%rbp)
	jge	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	movl	-12(%rbp), %edx
	movl	-12(%rbp), %ecx
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movl	%ecx, %edi
	movl	%edx, -28(%rbp)         ## 4-byte Spill
	callq	_g
	movq	-24(%rbp), %rdi         ## 8-byte Reload
	leaq	L_.str(%rip), %rsi
	movl	-28(%rbp), %edx         ## 4-byte Reload
	movl	%eax, %ecx
	movb	$0, %al
	callq	_fprintf
	movl	%eax, -32(%rbp)         ## 4-byte Spill
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	LBB0_1
LBB0_4:
	xorl	%edi, %edi
	callq	_g
	movl	$1, %edi
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	callq	_g
	movl	-36(%rbp), %edi         ## 4-byte Reload
	addl	%eax, %edi
	movl	$2, %eax
	movl	%edi, -40(%rbp)         ## 4-byte Spill
	movl	%eax, %edi
	callq	_g
	movl	-40(%rbp), %edi         ## 4-byte Reload
	addl	%eax, %edi
	movl	$3, %eax
	movl	%edi, -44(%rbp)         ## 4-byte Spill
	movl	%eax, %edi
	callq	_g
	movl	-44(%rbp), %edi         ## 4-byte Reload
	addl	%eax, %edi
	cmpl	$9, %edi
	sete	%cl
	xorb	$-1, %cl
	andb	$1, %cl
	movzbl	%cl, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"g(%d)==%d\n"


.subsections_via_symbols
