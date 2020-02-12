	.file	"fmatest.c"
	.text
	.p2align 4
	.globl	f1
	.type	f1, @function
f1:
.LFB3:
	.cfi_startproc
	vfmadd132ss	%xmm1, %xmm2, %xmm0
	ret
	.cfi_endproc
.LFE3:
	.size	f1, .-f1
	.p2align 4
	.globl	f2
	.type	f2, @function
f2:
.LFB4:
	.cfi_startproc
	vmulss	%xmm1, %xmm0, %xmm0
	vaddss	%xmm2, %xmm0, %xmm0
	ret
	.cfi_endproc
.LFE4:
	.size	f2, .-f2
	.p2align 4
	.globl	fmatest
	.type	fmatest, @function
fmatest:
.LFB5:
	.cfi_startproc
	vmovaps	%xmm0, %xmm3
	vmulss	%xmm1, %xmm0, %xmm0
	vfmadd132ss	%xmm1, %xmm2, %xmm3
	movl	$1, %edx
	vaddss	%xmm2, %xmm0, %xmm2
	vucomiss	%xmm3, %xmm2
	setp	%al
	cmovne	%edx, %eax
	ret
	.cfi_endproc
.LFE5:
	.size	fmatest, .-fmatest
	.ident	"GCC: (GNU) 9.2.0"
	.section	.note.GNU-stack,"",@progbits
