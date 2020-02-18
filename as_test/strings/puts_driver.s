	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_fakeputs               ## -- Begin function fakeputs
	.p2align	4, 0x90
_fakeputs:                              ## @fakeputs
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	_ok@GOTPCREL(%rip), %rax
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	leaq	L_.str(%rip), %rsi
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	callq	_strcmp
	cmpl	$0, %eax
	setne	%cl
	xorb	$-1, %cl
	andb	$1, %cl
	movzbl	%cl, %eax
	movq	-16(%rbp), %rsi         ## 8-byte Reload
	movl	%eax, (%rsi)
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
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
	movq	_ok@GOTPCREL(%rip), %rax
	movl	$0, -4(%rbp)
	movl	$0, (%rax)
	movb	$0, %al
	callq	_g
	movq	_ok@GOTPCREL(%rip), %rcx
	cmpl	$1, (%rcx)
	sete	%dl
	xorb	$-1, %dl
	andb	$1, %dl
	movzbl	%dl, %esi
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	movl	%esi, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"wibble"

	.comm	_ok,4,2                 ## @ok

.subsections_via_symbols
