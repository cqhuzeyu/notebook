	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 14, 0	sdk_version 14, 0
	.globl	_classily_string                ## -- Begin function classily_string
	.p2align	4, 0x90
_classily_string:                       ## @classily_string
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	_this@GOTPCREL(%rip), %rax
	addq	$1, %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rdi
	leaq	L_.str(%rip), %rsi
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB0_2
## %bb.1:
	movq	-16(%rbp), %rdi
	leaq	L_.str.1(%rip), %rsi
	movq	$-1, %rdx
	callq	___strcpy_chk
	movl	$1, -4(%rbp)
	jmp	LBB0_29
LBB0_2:
	movq	-16(%rbp), %rdi
	leaq	L_.str.2(%rip), %rsi
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB0_4
## %bb.3:
	movl	$1, -4(%rbp)
	jmp	LBB0_29
LBB0_4:
	movq	-16(%rbp), %rdi
	leaq	L_.str.3(%rip), %rsi
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB0_6
## %bb.5:
	movl	$2, -4(%rbp)
	jmp	LBB0_29
LBB0_6:
	movq	-16(%rbp), %rdi
	leaq	L_.str.4(%rip), %rsi
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB0_8
## %bb.7:
	movl	$2, -4(%rbp)
	jmp	LBB0_29
LBB0_8:
	movq	-16(%rbp), %rdi
	leaq	L_.str.5(%rip), %rsi
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB0_10
## %bb.9:
	movl	$2, -4(%rbp)
	jmp	LBB0_29
LBB0_10:
	movq	-16(%rbp), %rdi
	leaq	L_.str.6(%rip), %rsi
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB0_12
## %bb.11:
	movl	$2, -4(%rbp)
	jmp	LBB0_29
LBB0_12:
	movq	-16(%rbp), %rdi
	leaq	L_.str.7(%rip), %rsi
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB0_14
## %bb.13:
	movl	$2, -4(%rbp)
	jmp	LBB0_29
LBB0_14:
	movq	-16(%rbp), %rdi
	leaq	L_.str.8(%rip), %rsi
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB0_16
## %bb.15:
	movl	$2, -4(%rbp)
	jmp	LBB0_29
LBB0_16:
	movq	-16(%rbp), %rdi
	leaq	L_.str.9(%rip), %rsi
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB0_18
## %bb.17:
	movl	$2, -4(%rbp)
	jmp	LBB0_29
LBB0_18:
	movq	-16(%rbp), %rdi
	leaq	L_.str.10(%rip), %rsi
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB0_20
## %bb.19:
	movl	$2, -4(%rbp)
	jmp	LBB0_29
LBB0_20:
	movq	-16(%rbp), %rdi
	leaq	L_.str.11(%rip), %rsi
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB0_22
## %bb.21:
	movl	$2, -4(%rbp)
	jmp	LBB0_29
LBB0_22:
	movq	-16(%rbp), %rdi
	leaq	L_.str.12(%rip), %rsi
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB0_24
## %bb.23:
	movl	$2, -4(%rbp)
	jmp	LBB0_29
LBB0_24:
	movq	-16(%rbp), %rdi
	leaq	L_.str.13(%rip), %rsi
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB0_26
## %bb.25:
	movl	$2, -4(%rbp)
	jmp	LBB0_29
LBB0_26:
	movq	-16(%rbp), %rdi
	leaq	L_.str.14(%rip), %rsi
	callq	_strcmp
	cmpl	$0, %eax
	jne	LBB0_28
## %bb.27:
	movl	$2, -4(%rbp)
	jmp	LBB0_29
LBB0_28:
	movl	$0, -4(%rbp)
LBB0_29:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_gettoken                       ## -- Begin function gettoken
	.p2align	4, 0x90
_gettoken:                              ## @gettoken
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	_this@GOTPCREL(%rip), %rax
	addq	$1, %rax
	movq	%rax, -8(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	callq	_getchar
                                        ## kill: def $al killed $al killed $eax
	movq	-8(%rbp), %rcx
	movb	%al, (%rcx)
	movsbl	%al, %eax
	cmpl	$32, %eax
	jne	LBB1_3
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_1
LBB1_3:
	movq	-8(%rbp), %rax
	movsbl	(%rax), %edi
	callq	_isalnum
	cmpl	$0, %eax
	je	LBB1_8
## %bb.4:
	jmp	LBB1_5
LBB1_5:                                 ## =>This Inner Loop Header: Depth=1
	callq	_getchar
                                        ## kill: def $al killed $al killed $eax
	movq	-8(%rbp), %rcx
	movq	%rcx, %rdx
	addq	$1, %rdx
	movq	%rdx, -8(%rbp)
	movb	%al, 1(%rcx)
	movsbl	%al, %edi
	callq	_isalnum
	cmpl	$0, %eax
	je	LBB1_7
## %bb.6:                               ##   in Loop: Header=BB1_5 Depth=1
	jmp	LBB1_5
LBB1_7:
	movq	-8(%rbp), %rax
	movsbl	(%rax), %edi
	movq	___stdinp@GOTPCREL(%rip), %rax
	movq	(%rax), %rsi
	callq	_ungetc
	movq	-8(%rbp), %rax
	movb	$0, (%rax)
	callq	_classily_string
	movb	%al, %cl
	movq	_this@GOTPCREL(%rip), %rax
	movb	%cl, (%rax)
	jmp	LBB1_11
LBB1_8:
	movq	-8(%rbp), %rax
	movsbl	(%rax), %eax
	cmpl	$42, %eax
	jne	LBB1_10
## %bb.9:
	movq	_this@GOTPCREL(%rip), %rdi
	addq	$1, %rdi
	leaq	L_.str.15(%rip), %rsi
	movl	$100, %edx
	callq	___strcpy_chk
	movq	_this@GOTPCREL(%rip), %rax
	movb	$42, (%rax)
	jmp	LBB1_11
LBB1_10:
	movq	_this@GOTPCREL(%rip), %rax
	movb	$0, 2(%rax)
	movq	-8(%rbp), %rax
	movb	(%rax), %cl
	movq	_this@GOTPCREL(%rip), %rax
	movb	%cl, (%rax)
LBB1_11:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_read_to_first_identifier       ## -- Begin function read_to_first_identifier
	.p2align	4, 0x90
_read_to_first_identifier:              ## @read_to_first_identifier
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	callq	_gettoken
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	_this@GOTPCREL(%rip), %rax
	movsbl	(%rax), %eax
	cmpl	$0, %eax
	je	LBB2_3
## %bb.2:                               ##   in Loop: Header=BB2_1 Depth=1
	movl	_top(%rip), %eax
	addl	$1, %eax
	movl	%eax, _top(%rip)
	cltq
	movq	_stack@GOTPCREL(%rip), %rdi
	imulq	$101, %rax, %rax
	addq	%rax, %rdi
	movq	_this@GOTPCREL(%rip), %rsi
	movl	$101, %edx
	callq	_memcpy
	callq	_gettoken
	jmp	LBB2_1
LBB2_3:
	leaq	L_.str.16(%rip), %rdi
	movq	_this@GOTPCREL(%rip), %rsi
	addq	$1, %rsi
	movb	$0, %al
	callq	_printf
	callq	_gettoken
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_deal_with_arrays               ## -- Begin function deal_with_arrays
	.p2align	4, 0x90
_deal_with_arrays:                      ## @deal_with_arrays
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	jmp	LBB3_1
LBB3_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	_this@GOTPCREL(%rip), %rax
	movsbl	(%rax), %eax
	cmpl	$91, %eax
	jne	LBB3_5
## %bb.2:                               ##   in Loop: Header=BB3_1 Depth=1
	leaq	L_.str.17(%rip), %rdi
	movb	$0, %al
	callq	_printf
	callq	_gettoken
	movq	_this@GOTPCREL(%rip), %rax
	movsbl	1(%rax), %edi
	callq	_isdigit
	cmpl	$0, %eax
	je	LBB3_4
## %bb.3:                               ##   in Loop: Header=BB3_1 Depth=1
	movq	_this@GOTPCREL(%rip), %rdi
	addq	$1, %rdi
	callq	_atoi
	movl	%eax, %esi
	subl	$1, %esi
	leaq	L_.str.18(%rip), %rdi
	movb	$0, %al
	callq	_printf
	callq	_gettoken
LBB3_4:                                 ##   in Loop: Header=BB3_1 Depth=1
	callq	_gettoken
	leaq	L_.str.19(%rip), %rdi
	movb	$0, %al
	callq	_printf
	jmp	LBB3_1
LBB3_5:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_deal_with_function_args        ## -- Begin function deal_with_function_args
	.p2align	4, 0x90
_deal_with_function_args:               ## @deal_with_function_args
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	jmp	LBB4_1
LBB4_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	_this@GOTPCREL(%rip), %rax
	movsbl	(%rax), %eax
	cmpl	$41, %eax
	je	LBB4_3
## %bb.2:                               ##   in Loop: Header=BB4_1 Depth=1
	callq	_gettoken
	jmp	LBB4_1
LBB4_3:
	callq	_gettoken
	leaq	L_.str.20(%rip), %rdi
	movb	$0, %al
	callq	_printf
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_deal_with_pointers             ## -- Begin function deal_with_pointers
	.p2align	4, 0x90
_deal_with_pointers:                    ## @deal_with_pointers
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	jmp	LBB5_1
LBB5_1:                                 ## =>This Inner Loop Header: Depth=1
	movslq	_top(%rip), %rcx
	movq	_stack@GOTPCREL(%rip), %rax
	imulq	$101, %rcx, %rcx
	addq	%rcx, %rax
	movsbl	(%rax), %eax
	cmpl	$42, %eax
	jne	LBB5_3
## %bb.2:                               ##   in Loop: Header=BB5_1 Depth=1
	movl	_top(%rip), %eax
	movl	%eax, %ecx
	addl	$-1, %ecx
	movl	%ecx, _top(%rip)
	cltq
	movq	_stack@GOTPCREL(%rip), %rsi
	imulq	$101, %rax, %rax
	addq	%rax, %rsi
	addq	$1, %rsi
	leaq	L_.str.21(%rip), %rdi
	movb	$0, %al
	callq	_printf
	jmp	LBB5_1
LBB5_3:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_deal_with_declarator           ## -- Begin function deal_with_declarator
	.p2align	4, 0x90
_deal_with_declarator:                  ## @deal_with_declarator
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	_this@GOTPCREL(%rip), %rax
	movsbl	(%rax), %eax
	movl	%eax, -4(%rbp)                  ## 4-byte Spill
	subl	$40, %eax
	je	LBB6_2
	jmp	LBB6_10
LBB6_10:
	movl	-4(%rbp), %eax                  ## 4-byte Reload
	subl	$91, %eax
	jne	LBB6_3
	jmp	LBB6_1
LBB6_1:
	callq	_deal_with_arrays
	jmp	LBB6_3
LBB6_2:
	callq	_deal_with_function_args
LBB6_3:
	callq	_deal_with_pointers
LBB6_4:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, _top(%rip)
	jl	LBB6_9
## %bb.5:                               ##   in Loop: Header=BB6_4 Depth=1
	movslq	_top(%rip), %rcx
	movq	_stack@GOTPCREL(%rip), %rax
	imulq	$101, %rcx, %rcx
	addq	%rcx, %rax
	movsbl	(%rax), %eax
	cmpl	$40, %eax
	jne	LBB6_7
## %bb.6:                               ##   in Loop: Header=BB6_4 Depth=1
	movl	_top(%rip), %eax
	addl	$-1, %eax
	movl	%eax, _top(%rip)
	callq	_gettoken
	callq	_deal_with_declarator
	jmp	LBB6_8
LBB6_7:                                 ##   in Loop: Header=BB6_4 Depth=1
	movl	_top(%rip), %eax
	movl	%eax, %ecx
	addl	$-1, %ecx
	movl	%ecx, _top(%rip)
	cltq
	movq	_stack@GOTPCREL(%rip), %rsi
	imulq	$101, %rax, %rax
	addq	%rax, %rsi
	addq	$1, %rsi
	leaq	L_.str.21(%rip), %rdi
	movb	$0, %al
	callq	_printf
LBB6_8:                                 ##   in Loop: Header=BB6_4 Depth=1
	jmp	LBB6_4
LBB6_9:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                           ## -- Begin function main
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
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	callq	_read_to_first_identifier
	callq	_deal_with_declarator
	leaq	L_.str.22(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__DATA,__data
	.globl	_top                            ## @top
	.p2align	2, 0x0
_top:
	.long	4294967295                      ## 0xffffffff

	.comm	_this,101,0                     ## @this
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"const"

L_.str.1:                               ## @.str.1
	.asciz	"read-only"

L_.str.2:                               ## @.str.2
	.asciz	"volatile"

L_.str.3:                               ## @.str.3
	.asciz	"void"

L_.str.4:                               ## @.str.4
	.asciz	"char"

L_.str.5:                               ## @.str.5
	.asciz	"signed"

L_.str.6:                               ## @.str.6
	.asciz	"unsigned"

L_.str.7:                               ## @.str.7
	.asciz	"short"

L_.str.8:                               ## @.str.8
	.asciz	"int"

L_.str.9:                               ## @.str.9
	.asciz	"long"

L_.str.10:                              ## @.str.10
	.asciz	"float"

L_.str.11:                              ## @.str.11
	.asciz	"double"

L_.str.12:                              ## @.str.12
	.asciz	"struct"

L_.str.13:                              ## @.str.13
	.asciz	"union"

L_.str.14:                              ## @.str.14
	.asciz	"enum"

L_.str.15:                              ## @.str.15
	.asciz	"pointer to"

	.comm	_stack,10100,4                  ## @stack
L_.str.16:                              ## @.str.16
	.asciz	"%s is "

L_.str.17:                              ## @.str.17
	.asciz	"array "

L_.str.18:                              ## @.str.18
	.asciz	"0..%d "

L_.str.19:                              ## @.str.19
	.asciz	"of "

L_.str.20:                              ## @.str.20
	.asciz	"function returning "

L_.str.21:                              ## @.str.21
	.asciz	"%s "

L_.str.22:                              ## @.str.22
	.asciz	"\n"

.subsections_via_symbols
