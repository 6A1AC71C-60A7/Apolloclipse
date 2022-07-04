
; Add packed byte integers from xmm2/m128 and xmm1.

paddb xmm7, xmm2
paddb xmm7, [rax]

; Add packed word integers from xmm2/m128 and xmm1.

paddw xmm7, xmm2
paddw xmm7, [rax]

; Add packed doubleword integers from xmm2/m128 and xmm1.

paddd xmm7, xmm2
paddd xmm7, [rax]

; Add packed quadword integers from xmm2/m128 and xmm1.

paddq xmm7, xmm2
paddq xmm7, [rax]

; Subtract packed byte integers in xmm2/m128 from packed byte integers in xmm1.

psubb xmm7, xmm2
psubb xmm7, [rax]

; Subtract packed word integers in xmm2/m128 from packed word integers in xmm1.

psubw xmm7, xmm2
psubw xmm7, [rax]

; Subtract packed doubleword integers in xmm2/mem128 from packed doubleword integers in xmm1.

psubd xmm7, xmm2
psubd xmm7, [rax]

; Add packed signed byte integers from xmm2/m128 and xmm1 saturate the results.

paddsb xmm7, xmm2
paddsb xmm7, [rax]

; Add packed signed word integers from xmm2/m128 and xmm1 and saturate the results.

paddsw xmm7, xmm2
paddsw xmm7, [rax]

; Subtract packed signed byte integers in xmm2/m128 from packed signed byte integers in xmm1 and saturate results.

psubsb xmm7, xmm2
psubsb xmm7, [rax]

; Subtract packed signed word integers in xmm2/m128 from packed signed word integers in xmm1 and saturate results.

psubsw xmm7, xmm2
psubsw xmm7, [rax]

; Add packed unsigned byte integers from xmm2/m128 and xmm1 saturate the results.

paddusb xmm7, xmm2
paddusb xmm7, [rax]

; Add packed unsigned word integers from xmm2/m128 to xmm1 and saturate the results.

paddusw xmm7, xmm2
paddusw xmm7, [rax]

; Subtract packed unsigned byte integers in xmm2/m128 from packed unsigned byte integers in xmm1 and saturate result.

psubusb xmm7, xmm2
psubusb xmm7, [rax]

; Subtract packed unsigned word integers in xmm2/m128 from packed unsigned word integers in xmm1 and saturate result.

psubusw xmm7, xmm2
psubusw xmm7, [rax]

; Compare packed bytes in xmm2/m128 and xmm1 for equality.

pcmpeqb xmm5, xmm10
pcmpeqb xmm5, [rsp]

; Compare packed words in xmm2/m128 and xmm1 for equality.

pcmpeqw xmm5, xmm10
pcmpeqw xmm5, [rsp]

; Compare packed doublewords in xmm2/m128 and xmm1 for equality.

pcmpeqd xmm5, xmm10
pcmpeqd xmm5, [rsp]

; TODO HERE:: PCMPGTPB

; Converts 8 packed signed word integers from xmm1 and from xxm2/m128 into 16 packed signed byte integers in xxm1 using signed saturation.

packsswb xmm5, xmm10
packsswb xmm5, [rsp]

; Converts 4 packed signed doubleword integers from xmm1 and from xxm2/m128 into 8 packed signed word integers in xxm1 using signed saturation.

packssdw xmm5, xmm10
packssdw xmm5, [rsp]

; Converts 8 signed word integers from xmm1 and 8 signed word integers from xmm2/m128 into 16 unsigned byte integers in xmm1 using unsigned saturation.

packuswb xmm5, xmm10
packuswb xmm5, [rsp]

; Unpack and interleave high-order bytes from xmm1 and xmm2/m128 into xmm1.

punpckhbw xmm5, xmm10
punpckhbw xmm5, [rsp]

; Unpack and interleave high-order words from xmm1 and xmm2/m128 into xmm1.

punpckhwd xmm5, xmm10
punpckhwd xmm5, [rsp]

; Unpack and interleave high-order doublewords from xmm1 and xmm2/m128 into xmm1.

punpckhdq xmm5, xmm10
punpckhdq xmm5, [rsp]

; Unpack and interleave high-order quadwords from xmm1 and xmm2/m128 into xmm1.

punpckhqdq xmm5, xmm10
punpckhqdq xmm5, [rsp]

; Unpack and interleave low-order bytes from xmm1 and xmm2/m128 into xmm1.

punpcklbw xmm5, xmm10
punpcklbw xmm5, [rsp]

; Unpack and interleave low-order words from xmm1 and xmm2/m128 into xmm1.

punpcklwd xmm5, xmm10
punpcklwd xmm5, [rsp]

; Unpack and interleave low-order doublewords from xmm1 and xmm2/m128 into xmm1.

punpckldq xmm5, xmm10
punpckldq xmm5, [rsp]

; Unpack and interleave low-order quadwords from xmm1 and xmm2/m128 into xmm1.

punpcklqdq xmm5, xmm10
punpcklqdq xmm5, [rsp]

; Bitwise AND of xmm2/m128 and xmm1.

pand xmm2, xmm3
pand xmm2, [r12]

; Bitwise AND NOT of xmm2/m128 and xmm1.

pandn xmm2, xmm3
pandn xmm2, [r12]

; Bitwise OR of xmm2/m128 and xmm1.

por xmm2, xmm3
por xmm2, [r12]

; Bitwise XOR of xmm2/m128 and xmm1.

pxor xmm2, xmm3
pxor xmm2, [r12]

; Shift words in xmm1 left by xmm2/m128 while shifting in 0s.

psllw xmm2, xmm3
psllw xmm2, [r12]

; Shift words in xmm1 left by imm8 while shifting in 0s.

psllw xmm7, 0x69

; Shift doublewords in xmm1 left by xmm2/m128 while shifting in 0s.

pslld xmm2, xmm3
pslld xmm2, [r12]

; Shift doublewords in xmm1 left by imm8 while shifting in 0s.

pslld xmm7, 0x69

; Shift quadwords in xmm1 left by xmm2/m128 while shifting in 0s.

psllq xmm2, xmm3
psllq xmm2, [r12]

; Shift quadwords in xmm1 left by imm8 while shifting in 0s.

psllq xmm7, 0x69

; Shift words in xmm1 right by xmm2/m128 while shifting in 0s.

psrlw xmm2, xmm3
psrlw xmm2, [r12]

; Shift words in xmm1 right by imm8 while shifting in 0s.

psrlw xmm7, 0x69

; Shift doublewords in xmm1 right by xmm2/m128 while shifting in 0s.

psrld xmm2, xmm3
psrld xmm2, [r12]

; Shift doublewords in xmm1 right by imm8 while shifting in 0s.

psrld xmm7, 0x69

; Shift quadwords in xmm1 right by xmm2/m128 while shifting in 0s.

psrlq xmm2, xmm3
psrlq xmm2, [r12]

; Shift quadwords in xmm1 right by imm8 while shifting in 0s.

psrlq xmm7, 0x69

; Shift words in xmm1 right by xmm2/m128 while shifting in sign bits.

psraw xmm2, xmm3
psraw xmm2, [r12]

; Shift words in xmm1 right by imm8 while shifting in sign bits

psraw xmm7, 0x69

; Shift doubleword in xmm1 right by xmm2 /m128 while shifting in sign bits.

psrad xmm2, xmm3
psrad xmm2, [r12]

; Shift doublewords in xmm1 right by imm8 while shifting in sign bits.

psrad xmm7, 0x69

; Move doubleword from r/m32 to xmm.

movd xmm7, ecx
movd xmm7, DWORD [rcx]

; Move quadword from r/m64 to xmm.

movq xmm7, rcx
movq xmm7, QWORD [rcx]

; Move doubleword from xmm register to r/m32.

movd ecx, xmm7
movd DWORD [rcx], xmm7

; Move quadword from xmm register to r/m64.

movq rcx, xmm7
movq QWORD [rcx], xmm7

; Average packed unsigned byte integers from xmm2/m128 and xmm1 with rounding.

pavgb xmm1, xmm2
pavgb xmm2, [rax]

; Average packed unsigned byte integers from xmm2/m128 and xmm1 with rounding.

pavgw xmm1, xmm2
pavgw xmm2, [rax]

; Extract the word specified by imm8 from xmm and move it to reg, bits 15-0. The upper bits of r32 or r64 is zeroed.

pextrw rax, xmm2, 0x69

; Move the low word of r32 or from m16 into xmm at the word position specified by imm8.

pinsrw xmm1, eax, 0x69
pinsrw xmm1, WORD [rax], 0x69

; Compare packed unsigned byte integers in xmm1 and xmm2/m128 and store packed maximum values in xmm1.

pmaxub xmm1, xmm2
pmaxub xmm1, [rax]

; Compare packed unsigned byte integers in xmm1 and xmm2/m128 and store packed minimum values in xmm1.

pminub xmm1, xmm2
pminub xmm1, [rax]

; Compare packed signed word integers in xmm2/m128 and xmm1 and stores maximum packed values in xmm1.

pmaxsw xmm1, xmm2
pmaxsw xmm1, [rax]

; Compare packed signed word integers in xmm2/m128 and xmm1 and store packed minimum values in xmm1.

pminsd xmm1, xmm2
pminsd xmm1, [rax]

; Move a byte mask of xmm to reg. The upper bits of r32 or r64 are zeroed

; pmovmskb rax, xmm1 ; TODO: WHY DOESNT COMPILE ?

; Multiply the packed unsigned word integers in xmm1 and xmm2/m128, and store the high 16 bits of the results in xmm1.

pmulhuw xmm1, xmm2
pmulhuw xmm1, [rax]

; Computes the absolute differences of the packed unsigned byte integers from xmm2 /m128 and xmm1; the 8 low differences and 8 high differences are then summed separately to produce two unsigned word integer results.

psadbw xmm1, xmm2
psadbw xmm1, [rax]

; Move aligned packed double-precision floating-point values from xmm2/mem to xmm1.

movapd xmm7, xmm14
movapd xmm7, [rax]

; Move aligned packed double-precision floating-point values from xmm1 to xmm2/mem.

movapd [rax], xmm7


; Move unaligned packed double-precision floating-point values from xmm2/mem to xmm1.

movupd xmm7, xmm14
movupd xmm7, [rax]

; Move unaligned packed double-precision floating-point values from xmm1 to xmm2/mem.

movupd [rax], xmm7

; Merge scalar double-precision floating-point value from xmm2 to xmm1 register.

movsd xmm7, xmm6

; Load scalar double-precision floating-point value from m32 to xmm1 register.

movsd xmm7, QWORD [rdi]

; Move scalar double-precision floating-point value from xmm1 register to xmm2/m32.

movsd QWORD [rdi], xmm7

; Move two packed double-precision floating-point values from m64 to low quadword of xmm1.

movlpd xmm1, [rax]

; Move two packed double-precision floating-point values from low quadword of xmm1 to m64.

movlpd [rax], xmm1

; Move two packed double-precision floating-point values from m64 to high quadword of xmm1.

movhpd xmm1, [rax]

; Move two packed double-precision floating-point values from high quadword of xmm1 to m64.

movhpd [rax], xmm1

; Extract 4-bit sign mask from xmm and store in reg. The upper bits of r32 or r64 are filled with zeros.

movmskpd rax, xmm2

; Add packed double-precision floating-point values from xmm2/m128 to xmm1 and store result in xmm1.

addpd xmm5, xmm10
addpd xmm5, [rdi]

; Add the low double-precision floating-point value from xmm2/mem to xmm1 and store the result in xmm1.

addsd xmm1, xmm2
addsd xmm1, QWORD [rsp]

; Multiply packed double-precision floating-point values in xmm2/m128 with xmm1 and store result in xmm1.

mulpd xmm1, xmm2
mulpd xmm1, [rax]

; Multiply the low double-precision floating-point value in xmm2/m32 by the low double-precision floating-point value in xmm1.

mulsd xmm1, xmm2
mulsd xmm1, [rax]

; Divide packed double-precision floating-point values in xmm1 by packed double-precision floating-point values in xmm2/mem.

divpd xmm1, xmm2
divpd xmm1, [rax]

; Divide low double-precision floating-point value in xmm1 by low double-precision floating-point value in xmm2/m32.

divsd xmm1, xmm2
divsd xmm1, [rax]

; Computes Square Roots of the packed double-precision floating-point values in xmm2/m128 and stores the result in xmm1.

sqrtpd xmm1, xmm2
sqrtpd xmm1, [rax]

; Computes square root of the low double-precision floating-point value in xmm2/m32 and stores the results in xmm1.

sqrtsd xmm1, xmm2
sqrtsd xmm1, [rax]

; Return the maximum double-precision floating-point values between xmm1 and xmm2/mem.

maxpd xmm1, xmm2
maxpd xmm1, [rax]

; Return the maximum scalar double-precision floating-point value between xmm2/m32 and xmm1.

maxsd xmm1, xmm2
maxsd xmm1, [rax]

; Return the minimum double-precision floating-point values between xmm1 and xmm2/mem.

minpd xmm1, xmm2
minpd xmm1, [rax]

; Return the minimum scalar double-precision floating-point value between xmm2/m32 and xmm1.

minsd xmm1, xmm2
minsd xmm1, [rax]




; Return the bitwise logical AND of packed double-precision floating-point values in xmm1 and xmm2/mem.

andpd xmm1, xmm2
andpd xmm1, [rax]

; Return the bitwise logical AND NOT of packed double-precision floating-point values in xmm1 and xmm2/mem.

andnpd xmm1, xmm2
andnpd xmm1, [rax]

; Return the bitwise logical OR of packed double-precision floating-point values in xmm1 and xmm2/mem.

orpd xmm1, xmm2
orpd xmm1, [rax]

; Return the bitwise logical XOR of packed double-precision floating-point values in xmm1 and xmm2/mem.

xorpd xmm1, xmm2
xorpd xmm1, [rax]

; Compare packed double-precision floating-point values in xmm2/m128 and xmm1 using bits 2:0 of imm8 as a comparison predicate.

cmppd xmm1, xmm2, 0x69
cmppd xmm1, [rax], 0x69

; Compare low double-precision floating-point value in xmm2/m32 and xmm1 using bits 2:0 of imm8 as comparison predicate.

cmpsd xmm1, xmm2, 0x69
cmpsd xmm1, [rax], 0x69

; Compare low double-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.

comisd xmm1, xmm2
comisd xmm1, [rax]

; Compare low double-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.

ucomisd xmm1, xmm2
ucomisd xmm1, [rax]



; Select from quadruplet of double-precision floating-point values in xmm1 and xmm2/m128 using imm8, interleaved result pairs are stored in xmm1.

shufpd xmm1, xmm2, 0x69
shufpd xmm1, [rax], 0x69

; Unpacks and Interleaves double-precision floating-point values from high quadwords of xmm1 and xmm2/m128.

unpckhpd xmm1, xmm2
unpckhpd xmm1, [rax]

; Unpacks and Interleaves double-precision floating-point values from low quadwords of xmm1 and xmm2/m128.

unpcklpd xmm1, xmm2
unpcklpd xmm1, [rax]

; Convert two packed single-precision floating-point values in xmm2/m64 to two packed double-precision floating-point values in xmm1.

cvtps2pd xmm1, xmm2
cvtps2pd xmm1, [rax]

; Convert two packed double-precision floating-point values in xmm2/mem to two single-precision floating-point values in xmm1.

cvtpd2ps xmm1, xmm2
cvtpd2ps xmm1, [rax]

; Convert one single-precision floating-point value in xmm2/m32 to one double-precision floating-point value in xmm1.

cvtss2sd xmm1, xmm2
cvtss2sd xmm1, [rax]

; Convert one double-precision floating-point value in xmm2/m64 to one single-precision floating-point value in xmm1.

cvtsd2ss xmm1, xmm2
cvtsd2ss xmm1, [rax]

; Convert two packed double-precision floating-point values from xmm/m128 to two packed signed doubleword integers in mm.

cvtpd2pi mm2, xmm1
cvtpd2pi mm2, [rax]

; Convert two packer double-precision floating-point values from xmm/m128 to two packed signed doubleword integers in mm using truncation.

cvttpd2pi mm2, xmm1
cvttpd2pi mm2, [rax]

; Convert two packed double-precision floating-point values in xmm2/mem to two signed doubleword integers in xmm1.

cvtpd2dq xmm1, xmm2
cvtpd2dq xmm1, [rax]

; Convert two packed double-precision floating-point values in xmm2/mem to two signed doubleword integers in xmm1 using truncation.

cvttpd2dq xmm1, xmm2
cvttpd2dq xmm1, [rax]

; Convert two packed signed doubleword integers from xmm2/mem to two packed double-precision floating-point values in xmm1.

cvtdq2pd xmm1, xmm2
cvtdq2pd xmm1, [rax]

; Convert one double-precision floating-point value from xmm1/m64 to one signed doubleword integer r32.

cvtsd2si eax, xmm1
cvtsd2si eax, QWORD [rdi]

; Convert one double-precision floating-point value from xmm1/m64 to one signed quadword integer sign-extended into r64.

cvtsd2si rax, xmm1
cvtsd2si rax, QWORD [rdi]

; Convert one double-precision floating-point value from xmm1/m64 to one signed doubleword integer in r32 using truncation.

cvttsd2si eax, xmm1
cvttsd2si eax, QWORD [rdi]

; Convert one double-precision floating-point value from xmm1/m64 to one signed quadword integer in r64 using truncation.

cvttsd2si rax, xmm1
cvttsd2si rax, QWORD [rdi]

; Convert one signed doubleword integer from r32/m32 to one double-precision floating-point value in xmm1.

cvtsi2sd xmm1, eax
cvtsi2sd xmm1,  DWORD [rax]

; Convert one signed quadword integer from r/m64 to one double-precision floating-point value in xmm1.

cvtsi2sd xmm1, rax
cvtsi2sd xmm1, QWORD [rax]

; Convert four packed single-precision floating-point values from xmm2/mem to four packed signed doubleword values in xmm1.

cvtps2dq xmm1, xmm2
cvtps2dq xmm1, [rax]

; Convert four packed single-precision floating-point values from xmm2/mem to four packed signed doubleword values in xmm1 using truncation.

cvttps2dq xmm1, xmm2
cvttps2dq xmm1, [rax]

; Convert four packed signed doubleword integers from xmm2/mem to four packed single-precision floating-point values in xmm1.

cvtdq2ps xmm1, xmm2
cvtdq2ps xmm1, [rax]

; Move aligned packed integer values from xmm2/mem to xmm1.

movdqa xmm1, xmm2
movdqa xmm1, [rax]

; Move aligned packed integer values from xmm1 to xmm2/mem.

movdqa [rax], xmm1

; Move unaligned packed integer values from xmm2/mem to xmm1.

movdqu xmm1, xmm2
movdqu xmm1, [rax]

; Move unaligned packed integer values from xmm1 to xmm2/mem.

movdqu [rax], xmm1

; Subtract quadword integer in mm1 from mm2 /m64.

psubq mm1, mm2
psubq mm1, [rax]

; Subtract packed quadword integers in xmm1 from xmm2 /m128.

psubq xmm1, xmm2
psubq xmm2, [rax]

; Multiply unsigned doubleword integer in mm1 by unsigned doubleword integer in mm2/m64, and store the quadword result in mm1.

pmuludq mm1, mm2
pmuludq mm1, [rax]

; Multiply packed unsigned doubleword integers in xmm1 by packed unsigned doubleword integers in xmm2/m128, and store the quadword results in xmm1.

pmuludq xmm1, xmm2
pmuludq xmm2, [rax]

; Shuffle the low words in xmm2/m128 based on the encoding in imm8 and store the result in xmm1.

pshuflw xmm1, xmm2, 0x69
pshuflw xmm2, [rax], 0x69

; Shuffle the high words in xmm2/m128 based on the encoding in imm8 and store the result in xmm1.

pshufhw xmm1, xmm2, 0x69
pshufhw xmm2, [rax], 0x69

; Shuffle the doublewords in xmm2/m128 based on the encoding in imm8 and store the result in xmm1.

pshufd xmm1, xmm2, 0x69
pshufd xmm2, [rax], 0x69

; Shift xmm1 left by imm8 bytes while shifting in 0s.

pslldq xmm1, 0x69

; Shift xmm1 right by imm8 bytes while shifting in 0s.

psrldq xmm1, 0x69

; Move Quadword from XMM to MMX Technology Register

movdq2q mm1, xmm1

; Flush Cache Line

clflush [rax]

; Move packed integer values in xmm1 to m128 using non-temporal hint.

movntdq [rax], xmm1

; Move packed double-precision values in xmm1 to m128 using non-temporal hint.

movntpd [rax], xmm1

; Move doubleword from r32 to m32 using non-temporal hint.

movnti DWORD [rax], edi

; Move quadword from r64 to m64 using non-temporal hint.

movnti QWORD [rax], rdi

; Selectively write bytes from xmm1 to memory location using the byte mask in xmm2. The default memory location is specified by DS:DI/EDI/RDI.

maskmovdqu xmm1, xmm2

