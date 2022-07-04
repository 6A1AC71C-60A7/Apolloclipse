
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