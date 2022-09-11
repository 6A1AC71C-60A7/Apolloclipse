
; Move aligned packed single-precision floating-point values from xmm2/mem to xmm1.

movaps xmm7, xmm14
movaps xmm7, [rax]

; Move aligned packed single-precision floating-point values from xmm1 to xmm2/mem.

movaps [rax], xmm7


; Move unaligned packed single-precision floating-point values from xmm2/mem to xmm1.

movups xmm7, xmm14
movups xmm7, [rax]

; Move unaligned packed single-precision floating-point values from xmm1 to xmm2/mem.

movups [rax], xmm7

; Merge scalar single-precision floating-point value from xmm2 to xmm1 register.

movss xmm7, xmm6

; Load scalar single-precision floating-point value from m32 to xmm1 register.

movss xmm7, DWORD [rdi]

; Move scalar single-precision floating-point value from xmm1 register to xmm2/m32.

movss DWORD [rdi], xmm7

; Move two packed single-precision floating-point values from m64 to low quadword of xmm1.

movlps xmm1, [rax]

; Move two packed single-precision floating-point values from low quadword of xmm1 to m64.

movlps [rax], xmm1

; Move two packed single-precision floating-point values from m64 to high quadword of xmm1.

movhps xmm1, [rax]

; Move two packed single-precision floating-point values from high quadword of xmm1 to m64.

movhps [rax], xmm1

; Move two packed single-precision floating-point values from low quadword of xmm2 to high quadword of xmm1.

movlhps xmm1, xmm7

; Move two packed single-precision floating-point values from high quadword of xmm2 to low quadword of xmm1.

movhlps xmm1, xmm7

; Extract 4-bit sign mask from xmm and store in reg. The upper bits of r32 or r64 are filled with zeros.

movmskps rax, xmm2

; Add packed single-precision floating-point values from xmm2/m128 to xmm1 and store result in xmm1.

addps xmm5, xmm10
addps xmm5, [rdi]

; Add the low single-precision floating-point value from xmm2/mem to xmm1 and store the result in xmm1.

addss xmm1, xmm2
addss xmm1, DWORD [rsp]

; Multiply packed single-precision floating-point values in xmm2/m128 with xmm1 and store result in xmm1.

mulps xmm1, xmm2
mulps xmm1, [rax]

; Multiply the low single-precision floating-point value in xmm2/m32 by the low single-precision floating-point value in xmm1.

mulss xmm1, xmm2
mulss xmm1, [rax]

; Divide packed single-precision floating-point values in xmm1 by packed single-precision floating-point values in xmm2/mem.

divps xmm1, xmm2
divps xmm1, [rax]

; Divide low single-precision floating-point value in xmm1 by low single-precision floating-point value in xmm2/m32.


divss xmm1, xmm2
divss xmm1, [rax]

; Computes the approximate reciprocals of the packed single-precision floating-point values in xmm2/m128 and stores the results in xmm1.

rcpps xmm1, xmm2
rcpps xmm1, [rax]

; Computes the approximate reciprocal of the scalar single-precision floating-point value in xmm2/m32 and stores the result in xmm1.

rcpss xmm1, xmm2
rcpss xmm1, [rax]

; Computes Square Roots of the packed single-precision floating-point values in xmm2/m128 and stores the result in xmm1.

sqrtps xmm1, xmm2
sqrtps xmm1, [rax]

; Computes square root of the low single-precision floating-point value in xmm2/m32 and stores the results in xmm1.

sqrtss xmm1, xmm2
sqrtss xmm1, [rax]

; Computes the approximate reciprocals of the square roots of the packed single-precision floating-point values in xmm2/m128 and stores the results in xmm1.

rsqrtps xmm1, xmm2
rsqrtps xmm1, [rax]

; Computes the approximate reciprocal of the square root of the low single-precision floating-point value in xmm2/m32 and stores the results in xmm1.

rsqrtss xmm1, xmm2
rsqrtss xmm1, [rax]

; Return the maximum single-precision floating-point values between xmm1 and xmm2/mem.

maxps xmm1, xmm2
maxps xmm1, [rax]

; Return the maximum scalar single-precision floating-point value between xmm2/m32 and xmm1.

maxss xmm1, xmm2
maxss xmm1, [rax]

; Return the minimum single-precision floating-point values between xmm1 and xmm2/mem.

minps xmm1, xmm2
minps xmm1, [rax]

; Return the minimum scalar single-precision floating-point value between xmm2/m32 and xmm1.

minss xmm1, xmm2
minss xmm1, [rax]

; Return the bitwise logical AND of packed single-precision floating-point values in xmm1 and xmm2/mem.

andps xmm1, xmm2
andps xmm1, [rax]

; Return the bitwise logical AND NOT of packed single-precision floating-point values in xmm1 and xmm2/mem.

andnps xmm1, xmm2
andnps xmm1, [rax]

; Return the bitwise logical OR of packed single-precision floating-point values in xmm1 and xmm2/mem.

orps xmm1, xmm2
orps xmm1, [rax]

; Return the bitwise logical XOR of packed single-precision floating-point values in xmm1 and xmm2/mem.

xorps xmm1, xmm2
xorps xmm1, [rax]

; Compare packed single-precision floating-point values in xmm2/m128 and xmm1 using bits 2:0 of imm8 as a comparison predicate.

cmpps xmm1, xmm2, 0x69
cmpps xmm1, [rax], 0x69

; Compare low single-precision floating-point value in xmm2/m32 and xmm1 using bits 2:0 of imm8 as comparison predicate.

cmpss xmm1, xmm2, 0x69
cmpss xmm1, [rax], 0x69

; Compare low single-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.

comiss xmm1, xmm2
comiss xmm1, [rax]

; Compare low single-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.

ucomiss xmm1, xmm2
ucomiss xmm1, [rax]

; Select from quadruplet of single-precision floating-point values in xmm1 and xmm2/m128 using imm8, interleaved result pairs are stored in xmm1.

shufps xmm1, xmm2, 0x69
shufps xmm1, [rax], 0x69

; Unpacks and Interleaves single-precision floating-point values from high quadwords of xmm1 and xmm2/m128.

unpckhps xmm1, xmm2
unpckhps xmm1, [rax]

; Unpacks and Interleaves single-precision floating-point values from low quadwords of xmm1 and xmm2/m128.

unpcklps xmm1, xmm2
unpcklps xmm1, [rax]

; Convert two signed doubleword integers from mm/m64 to two single-precision floating-point values in xmm.

cvtpi2ps xmm1, mm2
cvtpi2ps xmm1, [rax]

; Convert one signed doubleword integer from r/m32 to one single-precision floating-point value in xmm1.

cvtsi2ss xmm1, eax
cvtsi2ss xmm1, DWORD [rax]

; Convert one signed quadword integer from r/m64 to one single-precision floating-point value in xmm1.

cvtsi2ss xmm1, rax
cvtsi2ss xmm1, QWORD [rax]

; Convert two packed single-precision floating-point values from xmm/m64 to two packed signed doubleword integers in mm.

cvtps2pi mm2, xmm2
cvtps2pi mm2, [rax]

; Convert two single-precision floating-point values from xmm/m64 to two signed doubleword signed integers in mm using truncation.

cvttps2pi mm2, xmm2
cvttps2pi mm2, [rax]

; Convert one single-precision floating-point value from xmm1/m32 to one signed doubleword integer in r32.

cvtss2si eax, xmm1
cvtss2si eax, DWORD [rdi]

; Convert one single-precision floating-point value from xmm1/m32 to one signed quadword integer in r64.

cvtss2si rax, xmm1
cvtss2si rax, DWORD [rdi]

; Convert one single-precision floating-point value from xmm1/m32 to one signed doubleword integer in r32 using truncation.

cvttss2si eax, xmm1
cvttss2si eax, DWORD [rdi]

; Convert one single-precision floating-point value from xmm1/m32 to one signed quadword integer in r64 using truncation.

cvttss2si rax, xmm1
cvttss2si rax, DWORD [rdi]

; Average packed unsigned byte integers from mm2/m64 and mm1 with rounding.

pavgb mm1, mm2
pavgb mm1, [rax]

; Average packed unsigned word integers from mm2/m64 and mm1 with rounding.

pavgw mm1, mm2
pavgw mm1, [rax]

; Extract the word specified by imm8 from mm and move it to reg, bits 15-0. The upper bits of r32 or r64 is zeroed.

; pextrw rax, mm1, 0x69 ; TODO: WHY DOESNT COMPILE ?

; Insert the low word from r32 or from m16 into mm at the word position specified by imm8.

pinsrw mm1, eax, 0x69
pinsrw mm1, WORD [rax], 0x69

; Compare unsigned byte integers in mm2/m64 and mm1 and returns maximum values.

pmaxub mm1, mm2
pmaxub mm1, [rax]

; Compare unsigned byte integers in mm2/m64 and mm1 and returns minimum values.

pminub mm1, mm2
pminub mm1, [rax]

; Compare signed word integers in mm2/m64 and mm1 and return maximum values.

pmaxsw mm1, mm2
pmaxsw mm1, [rax]

; Compare signed word integers in mm2/m64 and mm1 and return minimum values.

pminsw mm1, mm2
pminsw mm1, [rax]

; Move a byte mask of mm to reg. The upper bits of r32 or r64 are zeroed

; pmovmskb rax, mm1 ; TODO: WHY DOESNT COMPILE ?

; Multiply the packed unsigned word integers in mm1 register and mm2/m64, and store the high 16 bits of the results in mm1.

pmulhuw mm1, mm2
pmulhuw mm1, [rax]

; Computes the absolute differences of the packed unsigned byte integers from mm2 /m64 and mm1; differences are then summed to produce an unsigned word integer result.

psadbw mm1, mm2
psadbw mm1, [rax]

; Shuffle the words in mm2/m64 based on the encoding in imm8 and store the result in mm1.

pshufw mm1, mm2, 0x69
; TODO: Invalid instruction pshufw mm1, QWORD [rax], 0x69, documentation states that operand 2 mmx/m64 ...
;pshufw mm1, [rax], 0x69

; Load MXCSR register from m32.

ldmxcsr DWORD [rdi]

; Store contents of MXCSR register to m32.

stmxcsr DWORD [rdi]

; Save the x87 FPU, MMX, XMM, and MXCSR register state to m512byte.

fxsave [rax]

; Save the x87 FPU, MMX, XMM, and MXCSR register state to m512byte.

fxsave64 [rax]

; Restore the x87 FPU, MMX, XMM, and MXCSR register state from m512byte.

fxrstor [rax]

; Restore the x87 FPU, MMX, XMM, and MXCSR register state from m512byte.

fxrstor64 [rax]

