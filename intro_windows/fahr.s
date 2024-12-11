	.file	"fahr.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC5:
	.ascii "%3d %6.1f\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	call	__main
	pxor	%xmm0, %xmm0
	movss	%xmm0, -8(%rbp)
	movss	.LC1(%rip), %xmm0
	movss	%xmm0, -12(%rbp)
	movss	.LC2(%rip), %xmm0
	movss	%xmm0, -16(%rbp)
	movss	-8(%rbp), %xmm0
	movss	%xmm0, -4(%rbp)
	jmp	.L2
.L3:
	pxor	%xmm0, %xmm0
	cvtss2sd	-4(%rbp), %xmm0
	movsd	.LC3(%rip), %xmm2
	movapd	%xmm0, %xmm1
	subsd	%xmm2, %xmm1
	movsd	.LC4(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -20(%rbp)
	pxor	%xmm1, %xmm1
	cvtss2sd	-20(%rbp), %xmm1
	pxor	%xmm0, %xmm0
	cvtss2sd	-4(%rbp), %xmm0
	movq	%xmm1, %rax
	movq	%rax, %rdx
	movq	%rdx, %xmm1
	movq	%rax, %rdx
	movq	%xmm0, %rax
	movq	%rax, %rcx
	movq	%rcx, %xmm0
	movapd	%xmm1, %xmm2
	movq	%rdx, %r8
	movapd	%xmm0, %xmm1
	movq	%rax, %rdx
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movss	-4(%rbp), %xmm0
	addss	-16(%rbp), %xmm0
	movss	%xmm0, -4(%rbp)
.L2:
	movss	-12(%rbp), %xmm0
	comiss	-4(%rbp), %xmm0
	jnb	.L3
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 4
.LC1:
	.long	1133903872
	.align 4
.LC2:
	.long	1101004800
	.align 8
.LC3:
	.long	0
	.long	1077936128
	.align 8
.LC4:
	.long	1908874354
	.long	1071761180
	.ident	"GCC: (Rev3, Built by MSYS2 project) 13.2.0"
	.def	printf;	.scl	2;	.type	32;	.endef
