	.file	"testovf.c"
	.text
	.p2align 4
	.globl	testovf
	.type	testovf, @function
testovf:
.LFB0:
	.cfi_startproc
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	testovf, .-testovf
	.ident	"GCC: (GNU) 9.2.0"
	.section	.note.GNU-stack,"",@progbits
