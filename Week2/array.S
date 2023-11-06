	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	stur	w0, [x29, #-8]
	str	x1, [sp, #16]
	str	x2, [sp, #8]
	ldur	w8, [x29, #-8]
	subs	w8, w8, #1
	cset	w8, le
	tbz	w8, #0, LBB0_2
	b	LBB0_1
LBB0_1:
	adrp	x0, l___func__.main@PAGE
	add	x0, x0, l___func__.main@PAGEOFF
	adrp	x1, l_.str@PAGE
	add	x1, x1, l_.str@PAGEOFF
	mov	w2, #23
	adrp	x3, l_.str.1@PAGE
	add	x3, x3, l_.str.1@PAGEOFF
	bl	___assert_rtn
LBB0_2:
	b	LBB0_3
LBB0_3:
	ldr	x8, [sp, #16]
	ldr	x1, [x8, #8]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_strcmp
	cbnz	w0, LBB0_5
	b	LBB0_4
LBB0_4:
	bl	_demo1
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	b	LBB0_12
LBB0_5:
	ldr	x8, [sp, #16]
	ldr	x1, [x8, #8]
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_strcmp
	cbnz	w0, LBB0_7
	b	LBB0_6
LBB0_6:
	bl	_demo2
	b	LBB0_11
LBB0_7:
	ldr	x8, [sp, #16]
	ldr	x1, [x8, #8]
	adrp	x0, l_.str.5@PAGE
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_strcmp
	cbnz	w0, LBB0_9
	b	LBB0_8
LBB0_8:
	bl	_demo3
	b	LBB0_10
LBB0_9:
	adrp	x0, l___func__.main@PAGE
	add	x0, x0, l___func__.main@PAGEOFF
	adrp	x1, l_.str@PAGE
	add	x1, x1, l_.str@PAGEOFF
	mov	w2, #34
	adrp	x3, l_.str.6@PAGE
	add	x3, x3, l_.str.6@PAGEOFF
	bl	___assert_rtn
LBB0_10:
	b	LBB0_11
LBB0_11:
	b	LBB0_12
LBB0_12:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_demo1                          ; -- Begin function demo1
	.p2align	2
_demo1:                                 ; @demo1
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #160
	stp	x29, x30, [sp, #144]            ; 16-byte Folded Spill
	add	x29, sp, #144
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	sub	x0, x29, #48
	adrp	x1, l___const.demo1.a@PAGE
	add	x1, x1, l___const.demo1.a@PAGEOFF
	mov	x2, #40
	str	x2, [sp, #16]                   ; 8-byte Folded Spill
	bl	_memcpy
	ldr	x2, [sp, #16]                   ; 8-byte Folded Reload
	add	x0, sp, #56
	str	x0, [sp, #24]                   ; 8-byte Folded Spill
	mov	w1, #0
	str	w1, [sp, #12]                   ; 4-byte Folded Spill
	bl	_memset
	mov	w8, #2
	str	w8, [sp, #56]
	mov	w8, #3
	str	w8, [sp, #60]
	adrp	x8, l___const.demo1.passwords@PAGE
	add	x8, x8, l___const.demo1.passwords@PAGEOFF
	ldr	x9, [x8]
	str	x9, [sp, #40]
	ldrh	w8, [x8, #8]
	strh	w8, [sp, #48]
	mov	w0, #30
	bl	_sleep
	ldr	w1, [sp, #12]                   ; 4-byte Folded Reload
	ldr	x3, [sp, #16]                   ; 8-byte Folded Reload
	ldr	x0, [sp, #24]                   ; 8-byte Folded Reload
	mov	x2, #10000
	bl	___memset_chk
	str	wzr, [sp, #36]
	b	LBB1_1
LBB1_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #36]
	subs	w8, w8, #10
	b.ge	LBB1_4
	b	LBB1_2
LBB1_2:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldrsw	x9, [sp, #36]
	sub	x8, x29, #48
	ldr	w9, [x8, x9, lsl #2]
                                        ; implicit-def: $x8
	mov	x8, x9
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.7@PAGE
	add	x0, x0, l_.str.7@PAGEOFF
	bl	_printf
	b	LBB1_3
LBB1_3:                                 ;   in Loop: Header=BB1_1 Depth=1
	ldr	w8, [sp, #36]
	add	w8, w8, #1
	str	w8, [sp, #36]
	b	LBB1_1
LBB1_4:
	ldur	x9, [x29, #-8]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	b.eq	LBB1_6
	b	LBB1_5
LBB1_5:
	bl	___stack_chk_fail
LBB1_6:
	ldp	x29, x30, [sp, #144]            ; 16-byte Folded Reload
	add	sp, sp, #160
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_demo2                          ; -- Begin function demo2
	.p2align	2
_demo2:                                 ; @demo2
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #128
	stp	x29, x30, [sp, #112]            ; 16-byte Folded Spill
	add	x29, sp, #112
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
                                        ; implicit-def: $x9
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	adrp	x8, l___const.demo2.arrchar@PAGE
	add	x8, x8, l___const.demo2.arrchar@PAGEOFF
	ldrh	w11, [x8]
	add	x10, sp, #20
	strh	w11, [sp, #20]
	ldrb	w8, [x8, #2]
	strb	w8, [sp, #22]
	adrp	x11, l___const.demo2.__arrchar@PAGE
	add	x11, x11, l___const.demo2.__arrchar@PAGEOFF
	ldrh	w12, [x11]
	add	x8, sp, #16
	strh	w12, [sp, #16]
	ldrb	w11, [x11, #2]
	strb	w11, [sp, #18]
	adrp	x11, l___const.demo2.arrint@PAGE
	add	x11, x11, l___const.demo2.arrint@PAGEOFF
	ldr	x12, [x11]
	stur	x12, [x29, #-24]
	ldr	w11, [x11, #8]
	stur	w11, [x29, #-16]
	mov	w11, #100
	stur	w11, [x29, #-36]
	mov	w11, #99
	stur	w11, [x29, #-32]
                                        ; kill: def $w10 killed $w10 killed $x10
	stur	w10, [x29, #-28]
	adrp	x10, l___const.demo2.arrll@PAGE
	add	x10, x10, l___const.demo2.arrll@PAGEOFF
	ldr	q0, [x10]
	str	q0, [sp, #48]
	ldr	x10, [x10, #16]
	str	x10, [sp, #64]
	str	x9, [sp, #24]
	str	x9, [sp, #32]
	str	x8, [sp, #40]
	str	wzr, [sp, #12]
	b	LBB2_1
LBB2_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #12]
	subs	w8, w8, #3
	b.ge	LBB2_4
	b	LBB2_2
LBB2_2:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldrsw	x9, [sp, #12]
	add	x8, sp, #24
	ldr	x8, [x8, x9, lsl #3]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.8@PAGE
	add	x0, x0, l_.str.8@PAGEOFF
	bl	_printf
	b	LBB2_3
LBB2_3:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB2_1
LBB2_4:
	ldur	x9, [x29, #-8]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	b.eq	LBB2_6
	b	LBB2_5
LBB2_5:
	bl	___stack_chk_fail
LBB2_6:
	ldp	x29, x30, [sp, #112]            ; 16-byte Folded Reload
	add	sp, sp, #128
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_demo3                          ; -- Begin function demo3
	.p2align	2
_demo3:                                 ; @demo3
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	sub	sp, sp, #128
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	stur	x8, [x29, #-8]
	sub	sp, sp, #16
	mov	x9, sp
	sub	x8, x29, #52
	str	x8, [x9]
	adrp	x0, l_.str.9@PAGE
	add	x0, x0, l_.str.9@PAGEOFF
	bl	_scanf
	add	sp, sp, #16
	ldur	w8, [x29, #-52]
                                        ; kill: def $x8 killed $w8
	mov	x9, sp
	stur	x9, [x29, #-64]
	lsl	x9, x8, #2
	add	x9, x9, #15
	and	x9, x9, #0xfffffffffffffff0
	stur	x9, [x29, #-96]                 ; 8-byte Folded Spill
	adrp	x16, ___chkstk_darwin@GOTPAGE
	ldr	x16, [x16, ___chkstk_darwin@GOTPAGEOFF]
	blr	x16
	ldur	x10, [x29, #-96]                ; 8-byte Folded Reload
	mov	x9, sp
	subs	x0, x9, x10
	mov	sp, x0
	stur	x8, [x29, #-72]
	ldursw	x8, [x29, #-52]
	lsl	x0, x8, #2
	bl	_malloc
	stur	x0, [x29, #-80]
	stur	wzr, [x29, #-84]
	b	LBB3_1
LBB3_1:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-84]
	ldur	w9, [x29, #-52]
	subs	w8, w8, w9
	b.ge	LBB3_4
	b	LBB3_2
LBB3_2:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldur	x8, [x29, #-80]
	ldursw	x9, [x29, #-84]
	ldr	w9, [x8, x9, lsl #2]
                                        ; implicit-def: $x8
	mov	x8, x9
	sub	sp, sp, #16
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.10@PAGE
	add	x0, x0, l_.str.10@PAGEOFF
	bl	_printf
	add	sp, sp, #16
	b	LBB3_3
LBB3_3:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldur	w8, [x29, #-84]
	add	w8, w8, #1
	stur	w8, [x29, #-84]
	b	LBB3_1
LBB3_4:
	sub	x0, x29, #48
	mov	w1, #0
	mov	x2, #40
	bl	_memset
	ldur	x0, [x29, #-80]
	ldur	w9, [x29, #-52]
	mov	w8, #4
	mul	w9, w8, w9
                                        ; implicit-def: $x8
	mov	x8, x9
	sxtw	x2, w8
	mov	w1, #0
	mov	x3, #-1
	bl	___memset_chk
	stur	wzr, [x29, #-88]
	b	LBB3_5
LBB3_5:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-88]
	ldur	w9, [x29, #-52]
	subs	w8, w8, w9
	b.ge	LBB3_8
	b	LBB3_6
LBB3_6:                                 ;   in Loop: Header=BB3_5 Depth=1
	ldur	x8, [x29, #-80]
	ldursw	x9, [x29, #-88]
	ldr	w9, [x8, x9, lsl #2]
                                        ; implicit-def: $x8
	mov	x8, x9
	sub	sp, sp, #16
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.10@PAGE
	add	x0, x0, l_.str.10@PAGEOFF
	bl	_printf
	add	sp, sp, #16
	b	LBB3_7
LBB3_7:                                 ;   in Loop: Header=BB3_5 Depth=1
	ldur	w8, [x29, #-88]
	add	w8, w8, #1
	stur	w8, [x29, #-88]
	b	LBB3_5
LBB3_8:
	ldur	x0, [x29, #-80]
	ldur	w9, [x29, #-52]
	mov	w8, #4
	stur	w8, [x29, #-116]                ; 4-byte Folded Spill
	mul	w9, w8, w9
                                        ; implicit-def: $x8
	mov	x8, x9
	sxtw	x2, w8
	mov	w1, #1
	mov	x3, #-1
	stur	x3, [x29, #-112]                ; 8-byte Folded Spill
	bl	___memset_chk
	ldur	w8, [x29, #-116]                ; 4-byte Folded Reload
	ldur	x3, [x29, #-112]                ; 8-byte Folded Reload
	ldur	x0, [x29, #-80]
	ldur	w9, [x29, #-52]
	mul	w9, w8, w9
                                        ; implicit-def: $x8
	mov	x8, x9
	sxtw	x2, w8
	mov	w1, #23456
	bl	___memset_chk
	ldur	w8, [x29, #-116]                ; 4-byte Folded Reload
	ldur	x3, [x29, #-112]                ; 8-byte Folded Reload
	ldur	x0, [x29, #-80]
	ldur	w9, [x29, #-52]
	mul	w9, w8, w9
                                        ; implicit-def: $x8
	mov	x8, x9
	sxtw	x2, w8
	mov	w1, #63
	bl	___memset_chk
	ldur	w8, [x29, #-116]                ; 4-byte Folded Reload
	ldur	x3, [x29, #-112]                ; 8-byte Folded Reload
	ldur	x0, [x29, #-80]
	ldur	w9, [x29, #-52]
	mul	w9, w8, w9
                                        ; implicit-def: $x8
	mov	x8, x9
	sxtw	x2, w8
	mov	w1, #16191
	bl	___memset_chk
	ldur	x8, [x29, #-64]
	stur	x8, [x29, #-104]                ; 8-byte Folded Spill
	ldur	x9, [x29, #-8]
	adrp	x8, ___stack_chk_guard@GOTPAGE
	ldr	x8, [x8, ___stack_chk_guard@GOTPAGEOFF]
	ldr	x8, [x8]
	subs	x8, x8, x9
	b.eq	LBB3_10
	b	LBB3_9
LBB3_9:
	bl	___stack_chk_fail
LBB3_10:
	ldur	x8, [x29, #-104]                ; 8-byte Folded Reload
	mov	sp, x8
	mov	sp, x29
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l___func__.main:                        ; @__func__.main
	.asciz	"main"

l_.str:                                 ; @.str
	.asciz	"array.c"

l_.str.1:                               ; @.str.1
	.asciz	"argc > 1"

l_.str.2:                               ; @.str.2
	.asciz	"demo1"

l_.str.3:                               ; @.str.3
	.asciz	"Return"

l_.str.4:                               ; @.str.4
	.asciz	"demo2"

l_.str.5:                               ; @.str.5
	.asciz	"demo3"

l_.str.6:                               ; @.str.6
	.asciz	"0"

	.section	__TEXT,__const
	.p2align	2                               ; @__const.demo1.a
l___const.demo1.a:
	.long	100                             ; 0x64
	.long	2                               ; 0x2
	.long	3                               ; 0x3
	.long	4                               ; 0x4
	.long	5                               ; 0x5
	.long	6                               ; 0x6
	.long	7                               ; 0x7
	.long	8                               ; 0x8
	.long	9                               ; 0x9
	.long	10                              ; 0xa

	.section	__TEXT,__cstring,cstring_literals
l___const.demo1.passwords:              ; @__const.demo1.passwords
	.asciz	"dadadadad"

l_.str.7:                               ; @.str.7
	.asciz	"a[%d] is %d\n"

	.section	__TEXT,__const
l___const.demo2.arrchar:                ; @__const.demo2.arrchar
	.ascii	"\001\002\003"

l___const.demo2.__arrchar:              ; @__const.demo2.__arrchar
	.ascii	"\001\002\003"

	.p2align	2                               ; @__const.demo2.arrint
l___const.demo2.arrint:
	.long	100                             ; 0x64
	.long	99                              ; 0x63
	.long	320                             ; 0x140

	.p2align	3                               ; @__const.demo2.arrll
l___const.demo2.arrll:
	.quad	100                             ; 0x64
	.quad	4294967296                      ; 0x100000000
	.quad	0                               ; 0x0

	.section	__TEXT,__cstring,cstring_literals
l_.str.8:                               ; @.str.8
	.asciz	"%lx "

l_.str.9:                               ; @.str.9
	.asciz	"%d"

l_.str.10:                              ; @.str.10
	.asciz	"%d "

.subsections_via_symbols
