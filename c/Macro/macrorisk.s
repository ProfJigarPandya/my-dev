	.file	"macrorisk.c"
	.section	.rodata
.LC0:
	.string	"\n square of 5 is %d"
.LC1:
	.string	"\n square of 5+5 is %d"
	.align 4
.LC2:
	.string	"\n square of 5 is %d using smart square"
	.align 4
.LC3:
	.string	"\n square of 5+5 is %d using smart square"
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$20, %esp
	movl	$25, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	$35, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	movl	$25, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	$100, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	addl	$20, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.2 20080704 (Red Hat 4.1.2-54)"
	.section	.note.GNU-stack,"",@progbits
