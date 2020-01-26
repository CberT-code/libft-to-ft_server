	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_test                   ## -- Begin function test
	.p2align	4, 0x90
_test:                                  ## @test
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$4, %eax
	movl	%eax, %edi
	callq	_malloc
	movl	$3, %ecx
	movl	%ecx, %edx
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movb	$98, 1(%rax)
	movq	-8(%rbp), %rax
	movb	$99, 2(%rax)
	movq	-8(%rbp), %rax
	movb	$0, 3(%rax)
	movq	-8(%rbp), %rsi
	movl	$1, %edi
	callq	_write
	movq	%rax, -16(%rbp)         ## 8-byte Spill
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
	movl	$0, -4(%rbp)
	callq	_test
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_end                    ## -- Begin function end
	.p2align	4, 0x90
_end:                                   ## @end
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$6, %eax
	movl	%eax, %edx
	movl	$1, %edi
	leaq	L_.str(%rip), %rsi
	callq	_write
	movq	%rax, -8(%rbp)          ## 8-byte Spill
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	jmp	LBB2_1
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__StaticInit,regular,pure_instructions
	.p2align	4, 0x90         ## -- Begin function __GLOBAL_init_65535
___GLOBAL_init_65535:                   ## @__GLOBAL_init_65535
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	leaq	_end(%rip), %rax
	xorl	%ecx, %ecx
	movl	%ecx, %esi
	movq	%rax, %rdi
	leaq	___dso_handle(%rip), %rdx
	callq	___cxa_atexit
	movl	%eax, -4(%rbp)          ## 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Bye !\n"

	.section	__DATA,__mod_init_func,mod_init_funcs
	.p2align	3
	.quad	___GLOBAL_init_65535

.subsections_via_symbols
