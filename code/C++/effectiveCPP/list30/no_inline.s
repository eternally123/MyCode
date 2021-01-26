	.file	"main.cc"
	.section	.text._ZN4BaseD2Ev,"axG",@progbits,_ZN4BaseD5Ev,comdat
	.align 2
	.weak	_ZN4BaseD2Ev
	.type	_ZN4BaseD2Ev, @function
_ZN4BaseD2Ev:
.LFB4:
	.cfi_startproc
	rep ret
	.cfi_endproc
.LFE4:
	.size	_ZN4BaseD2Ev, .-_ZN4BaseD2Ev
	.weak	_ZN4BaseD1Ev
	.set	_ZN4BaseD1Ev,_ZN4BaseD2Ev
	.section	.text._ZN4Base5printEv,"axG",@progbits,_ZN4Base5printEv,comdat
	.align 2
	.weak	_ZN4Base5printEv
	.type	_ZN4Base5printEv, @function
_ZN4Base5printEv:
.LFB7:
	.cfi_startproc
	rep ret
	.cfi_endproc
.LFE7:
	.size	_ZN4Base5printEv, .-_ZN4Base5printEv
	.section	.text._ZN7DerivedD2Ev,"axG",@progbits,_ZN7DerivedD5Ev,comdat
	.align 2
	.weak	_ZN7DerivedD2Ev
	.type	_ZN7DerivedD2Ev, @function
_ZN7DerivedD2Ev:
.LFB12:
	.cfi_startproc
	rep ret
	.cfi_endproc
.LFE12:
	.size	_ZN7DerivedD2Ev, .-_ZN7DerivedD2Ev
	.weak	_ZN7DerivedD1Ev
	.set	_ZN7DerivedD1Ev,_ZN7DerivedD2Ev
	.section	.text._ZN7Derived5printEv,"axG",@progbits,_ZN7Derived5printEv,comdat
	.align 2
	.weak	_ZN7Derived5printEv
	.type	_ZN7Derived5printEv, @function
_ZN7Derived5printEv:
.LFB15:
	.cfi_startproc
	rep ret
	.cfi_endproc
.LFE15:
	.size	_ZN7Derived5printEv, .-_ZN7Derived5printEv
	.section	.text._ZN7DerivedD0Ev,"axG",@progbits,_ZN7DerivedD5Ev,comdat
	.align 2
	.weak	_ZN7DerivedD0Ev
	.type	_ZN7DerivedD0Ev, @function
_ZN7DerivedD0Ev:
.LFB14:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	_ZdlPv
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE14:
	.size	_ZN7DerivedD0Ev, .-_ZN7DerivedD0Ev
	.section	.text._ZN4BaseD0Ev,"axG",@progbits,_ZN4BaseD5Ev,comdat
	.align 2
	.weak	_ZN4BaseD0Ev
	.type	_ZN4BaseD0Ev, @function
_ZN4BaseD0Ev:
.LFB6:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	_ZdlPv
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE6:
	.size	_ZN4BaseD0Ev, .-_ZN4BaseD0Ev
	.text
	.globl	main
	.type	main, @function
main:
.LFB16:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$8, %edi
	call	_Znwm
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE16:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
