	.file	"macrorisk1.c"
	.section	.rodata
.LC0:
	.string	"\n Array content "
.LC1:
	.string	"%d"
.LC2:
	.string	"\n sum is %d "
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
	subl	$52, %esp
	movl	$0, -12(%ebp)
	movl	$.LC0, (%esp)
	call	printf
	movl	$0, -8(%ebp)
	jmp	.L2
.L3:
	movl	-8(%ebp), %eax
	sall	$2, %eax
	movl	%eax, %edx
	leal	-32(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	scanf
	movl	-8(%ebp), %eax
	movl	-32(%ebp,%eax,4), %eax
	addl	%eax, -12(%ebp)
	addl	$1, -8(%ebp)
.L2:
	cmpl	$4, -8(%ebp)
	jle	.L3
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	addl	$52, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.2 20080704 (Red Hat 4.1.2-54)"
	.section	.note.GNU-stack,"",@progbits
