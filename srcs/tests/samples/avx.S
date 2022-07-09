
; Add packed byte integers from xmm2, and xmm3/m128 and store in xmm1.

vpaddb xmm7, xmm2, xmm15
vpaddb xmm7, xmm2, [rbp]

; Add packed word integers from xmm2, xmm3/m128 and store in xmm1.

vpaddw xmm7, xmm2, xmm15
vpaddw xmm7, xmm2, [rbp]

; Add packed doubleword integers from xmm2, xmm3/m128 and store in xmm1.

vpaddd xmm7, xmm2, xmm15
vpaddd xmm7, xmm2, [rbp]

; Add packed quadword integers from xmm2, xmm3/m128 and store in xmm1.

vpaddq xmm7, xmm2, xmm15
vpaddq xmm7, xmm2, [rbp]

; Subtract packed byte integers in xmm3/m128 from xmm2.

vpsubb xmm7, xmm2, xmm15
vpsubb xmm7, xmm2, [rbp]

; Subtract packed word integers in xmm3/m128 from xmm2.

vpsubw xmm7, xmm2, xmm15
vpsubw xmm7, xmm2, [rbp]

; Subtract packed doubleword integers in xmm3/m128 from xmm2.

vpsubd xmm7, xmm2, xmm15
vpsubd xmm7, xmm2, [rbp]

; Add packed signed byte integers from xmm3/m128 and xmm2 saturate the results.

vpaddsb xmm7, xmm2, xmm15
vpaddsb xmm7, xmm2, [rbp]

; Add packed signed word integers from xmm3/m128 and xmm2 and saturate the results.

vpaddsw xmm7, xmm2, xmm15
vpaddsw xmm7, xmm2, [rbp]

; Subtract packed signed byte integers in xmm3/m128 from packed signed byte integers in xmm2 and saturate results.

vpsubsb xmm7, xmm2, xmm15
vpsubsb xmm7, xmm2, [rbp]

; Subtract packed signed word integers in xmm3/m128 from packed signed word integers in xmm2 and saturate results.

vpsubsw xmm7, xmm2, xmm15
vpsubsw xmm7, xmm2, [rbp]

; Add packed unsigned byte integers from xmm3/m128 to xmm2 and saturate the results.

vpaddusb xmm7, xmm2, xmm15
vpaddusb xmm7, xmm2, [rbp]

; Add packed unsigned word integers from xmm3/m128 to xmm2 and saturate the results.

vpaddusw xmm7, xmm2, xmm15
vpaddusw xmm7, xmm2, [rbp]

; Subtract packed unsigned byte integers in xmm3/m128 from packed unsigned byte integers in xmm2 and saturate result.

vpsubusb xmm7, xmm2, xmm15
vpsubusb xmm7, xmm2, [rbp]

; Subtract packed unsigned word integers in xmm3/m128 from packed unsigned word integers in xmm2 and saturate result.

vpsubusw xmm7, xmm2, xmm15
vpsubusw xmm7, xmm2, [rbp]

; Compare packed bytes in xmm3/m128 and xmm2 for equality.

vpcmpeqb xmm2, xmm4, xmm8
vpcmpeqb xmm2, xmm4, [r8]

;  	Compare packed words in xmm3/m128 and xmm2 for equality.

vpcmpeqw xmm2, xmm4, xmm8
vpcmpeqw xmm2, xmm4, [r8]

;  	Compare packed doublewords in xmm3/m128 and xmm2 for equality.

vpcmpeqd xmm2, xmm4, xmm8
vpcmpeqd xmm2, xmm4, [r8]

; TODO HERE:: VPCMPGTPB

; Converts 8 packed signed word integers from xmm2 and from xmm3/m128 into 16 packed signed byte integers in xmm1 using signed saturation.

vpacksswb xmm2, xmm4, xmm8
vpacksswb xmm2, xmm4, [r8]

; Converts 4 packed signed doubleword integers from xmm2 and from xmm3/m128 into 8 packed signed word integers in xmm1 using signed saturation.

vpackssdw xmm2, xmm4, xmm8
vpackssdw xmm2, xmm4, [r8]

; Converts 8 signed word integers from xmm2 and 8 signed word integers from xmm3/m128 into 16 unsigned byte integers in xmm1 using unsigned saturation.

vpackuswb xmm2, xmm4, xmm8
vpackuswb xmm2, xmm4, [r8]

; Interleave high-order bytes from xmm2 and xmm3/m128 into xmm1.

vpunpckhbw xmm2, xmm4, xmm8
vpunpckhbw xmm2, xmm4, [r8]

; Interleave high-order words from xmm2 and xmm3/m128 into xmm1.

vpunpckhwd xmm2, xmm4, xmm8
vpunpckhwd xmm2, xmm4, [r8]

; Interleave high-order doublewords from xmm2 and xmm3/m128 into xmm1.

vpunpckhdq xmm2, xmm4, xmm8
vpunpckhdq xmm2, xmm4, [r8]

; Interleave high-order quadword from xmm2 and xmm3/m128 into xmm1 register.

vpunpckhqdq xmm2, xmm4, xmm8
vpunpckhqdq xmm2, xmm4, [r8]

; Interleave low-order bytes from xmm2 and xmm3/m128 into xmm1.

vpunpcklbw xmm2, xmm4, xmm8
vpunpcklbw xmm2, xmm4, [r8]

; Interleave low-order words from xmm2 and xmm3/m128 into xmm1.

vpunpcklwd xmm2, xmm4, xmm8
vpunpcklwd xmm2, xmm4, [r8]

; Interleave low-order doublewords from xmm2 and xmm3/m128 into xmm1.

vpunpckldq xmm2, xmm4, xmm8
vpunpckldq xmm2, xmm4, [r8]

; Interleave low-order quadword from xmm2 and xmm3/m128 into xmm1 register.

vpunpcklqdq xmm2, xmm4, xmm8
vpunpcklqdq xmm2, xmm4, [r8]

; Bitwise AND of xmm3/m128 and xmm.

vpand xmm1, xmm3, xmm5
vpand xmm1, xmm3, [rcx]

; Bitwise AND NOT of xmm3/m128 and xmm.

vpandn xmm1, xmm3, xmm5
vpandn xmm1, xmm3, [rcx]

; Bitwise OR of xmm3/m128 and xmm.

vpor xmm1, xmm3, xmm5
vpor xmm1, xmm3, [rcx]

; Bitwise XOR of xmm3/m128 and xmm.

vpxor xmm1, xmm3, xmm5
vpxor xmm1, xmm3, [rcx]

; Shift words in xmm2 left by amount specified in xmm3/m128 while shifting in 0s.

vpsllw xmm1, xmm3, xmm5
vpsllw xmm1, xmm3, [rcx]

; Shift words in xmm2 left by imm8 while shifting in 0s.

vpsllw xmm7, xmm14, 0x69

; Shift doublewords in xmm2 left by amount specified in xmm3/m128 while shifting in 0s.

vpslld xmm1, xmm3, xmm5
vpslld xmm1, xmm3, [rcx]

;  	Shift doublewords in xmm2 left by imm8 while shifting in 0s.

vpslld xmm7, xmm14, 0x69

; Shift quadwords in xmm2 left by amount specified in xmm3/m128 while shifting in 0s.

vpsllq xmm1, xmm3, xmm5
vpsllq xmm1, xmm3, [rcx]

; Shift quadwords in xmm2 left by imm8 while shifting in 0s.

vpsllq xmm7, xmm14, 0x69

; Shift words in xmm2 right by amount specified in xmm3/m128 while shifting in 0s.

vpsrlw xmm1, xmm3, xmm5
vpsrlw xmm1, xmm3, [rcx]

; Shift words in xmm2 right by imm8 while shifting in 0s.

vpsrlw xmm7, xmm14, 0x69

; Shift doublewords in xmm2 right by amount specified in xmm3/m128 while shifting in 0s.

vpsrld xmm1, xmm3, xmm5
vpsrld xmm1, xmm3, [rcx]

;  	Shift doublewords in xmm2 right by imm8 while shifting in 0s.

vpsrld xmm7, xmm14, 0x69

; Shift quadwords in xmm2 right by amount specified in xmm3/m128 while shifting in 0s.

vpsrlq xmm1, xmm3, xmm5
vpsrlq xmm1, xmm3, [rcx]

; Shift quadwords in xmm2 right by imm8 while shifting in 0s.

vpsrlq xmm7, xmm14, 0x69

; Shift words in xmm2 right by amount specified in xmm3/m128 while shifting in sign bits.

vpsraw xmm1, xmm3, xmm5
vpsraw xmm1, xmm3, [rcx]

; Shift words in xmm2 right by imm8 while shifting in sign bits.

vpsraw xmm7, xmm14, 0x69

; Shift doublewords in xmm2 right by amount specified in xmm3/m128 while shifting in sign bits.

vpsrad xmm1, xmm3, xmm5
vpsrad xmm1, xmm3, [rcx]

; Shift doublewords in xmm2 right by imm8 while shifting in sign bits.

vpsrad xmm7, xmm14, 0x69

;;; TODO: WHY AVX and AVX512 MOV*SEEMS TO BE LITERALLY THE SAME ?

; Move doubleword from r/m32 to xmm.

vmovd xmm7, ecx
vmovd xmm7, DWORD [rcx]

; Move quadword from r/m64 to xmm.

vmovq xmm7, rcx
vmovq xmm7, QWORD [rcx]

; Move doubleword from xmm register to r/m32.

vmovd ecx, xmm7
vmovd DWORD [rcx], xmm7

; Move quadword from xmm register to r/m64.

vmovq rcx, xmm7
vmovq QWORD [rcx], xmm7

; Move aligned packed single-precision floating-point values from xmm2/mem to xmm1.

vmovaps xmm7, xmm2
vmovaps xmm7, [rax]

; Move aligned packed single-precision floating-point values from xmm1 to xmm2/mem.

vmovaps [rax], xmm7

; Move aligned packed single-precision floating-point values from ymm2/mem to ymm1.

vmovaps ymm7, ymm2
vmovaps ymm7, [rax]

; Move aligned packed single-precision floating-point values from ymm1 to ymm2/mem.

vmovaps [rax], ymm7

; Move unaligned packed single-precision floating-point values from xmm2/mem to xmm1.

vmovups xmm7, xmm2
vmovups xmm7, [rax]

; Move unaligned packed single-precision floating-point values from xmm1 to xmm2/mem.

vmovups [rax], xmm7

; Move unaligned packed single-precision floating-point values from ymm2/mem to ymm1.

vmovups ymm7, ymm2
vmovups ymm7, [rax]

; Move unaligned packed single-precision floating-point values from ymm1 to ymm2/mem.

vmovups [rax], ymm7

; Merge scalar single-precision floating-point value from xmm2 and xmm3 to xmm1 register

vmovss xmm1, xmm2, xmm3 

; Load scalar single-precision floating-point value from m32 to xmm1 register.

vmovss xmm8, [rdi]

; Move scalar single-precision floating-point value from xmm1 register to m32.

vmovss [rdi], xmm8

; Merge two packed single-precision floating-point values from m64 and the low quadword of xmm1.

vmovlps xmm2, xmm1, [rax]

; Move two packed single-precision floating-point values from low quadword of xmm1 to m64.

vmovlps [rax], xmm1

; Merge two packed single-precision floating-point values from m64 and the high quadword of xmm1.

vmovhps xmm2, xmm1, [rax]

; Move two packed single-precision floating-point values from high quadword of xmm1 to m64.

vmovhps [rax], xmm1

; Merge two packed single-precision floating-point values from low quadword of xmm3 and low quadword of xmm2.

vmovlhps xmm1, xmm2, xmm3

; Merge two packed single-precision floating-point values from high quadword of xmm3 and low quadword of xmm2.

vmovhlps xmm1, xmm2, xmm3

; Extract 4-bit sign mask from xmm2 and store in reg. The upper bits of r32 or r64 are zeroed.

vmovmskps rax, xmm2

; Add packed single-precision floating-point values from xmm3/m128 to xmm2 and store result in xmm1.

vaddps xmm1, xmm2, xmm3
vaddps xmm1, xmm2, [rdi]

; Add packed single-precision floating-point values from ymm3/m256 to ymm2 and store result in ymm1.

vaddps ymm1, ymm2, ymm3
vaddps ymm1, ymm2, [rdi]

; Add the low single-precision floating-point value from xmm3/mem to xmm2 and store the result in xmm1.

vaddss xmm1, xmm2, xmm3
vaddss xmm1, xmm2, DWORD [rax]

; Multiply packed single-precision floating-point values in xmm3/m128 with xmm2 and store result in xmm1.

vmulps xmm1, xmm2, xmm3
vmulps xmm1, xmm2, [rax]

; Multiply packed single-precision floating-point values in ymm3/m256 with ymm2 and store result in ymm1.

vmulps ymm1, ymm2, ymm3
vmulps ymm1, ymm2, [rax]

; Multiply the low single-precision floating-point value in xmm3/m32 by the low single-precision floating-point value in xmm2.

vmulss xmm1, xmm2, xmm3
vmulss xmm1, xmm2, [rax]

; Divide packed single-precision floating-point values in xmm2 by packed single-precision floating-point values in xmm3/mem.

vdivps xmm1, xmm2, xmm3
vdivps xmm1, xmm2, [rax]

; Divide packed single-precision floating-point values in ymm2 by packed single-precision floating-point values in ymm3/mem.

vdivps ymm1, ymm2, ymm3
vdivps ymm1, ymm2, [rax]

; Divide low single-precision floating-point value in xmm2 by low single-precision floating-point value in xmm3/m32.

vdivss xmm1, xmm2, xmm3
vdivss xmm1, xmm2, [rax]

; Computes the approximate reciprocals of packed single-precision values in xmm2/mem and stores the results in xmm1.

vrcpps xmm1, xmm2
vrcpps xmm1, [rax]

; Computes the approximate reciprocals of packed single-precision values in ymm2/mem and stores the results in ymm1.

vrcpps ymm1, ymm2
vrcpps ymm1, [rax]

; Computes the approximate reciprocal of the scalar single-precision floating-point value in xmm3/m32 and stores the result in xmm1. Also, upper single precision floating-point values (bits[127:32]) from xmm2 are copied to xmm1[127:32].

vrcpss xmm1, xmm2, xmm3
vrcpss xmm1, xmm2, [rax]

; Computes Square Roots of the packed single-precision floating-point values in xmm2/m128 and stores the result in xmm1.

vsqrtps xmm1, xmm2
vsqrtps xmm1, [rax]

; Computes Square Roots of the packed single-precision floating-point values in ymm2/m256 and stores the result in ymm1.

vsqrtps ymm1, ymm2
vsqrtps ymm1, [rax]

; AVX 	Computes square root of the low single-precision floating-point value in xmm3/m32 and stores the results in xmm1. Also, upper single-precision floating-point values (bits[127:32]) from xmm2 are copied to xmm1[127:32].

vsqrtss xmm1, xmm2, xmm3
vsqrtss xmm1, xmm2, [rax]

; Computes the approximate reciprocals of the square roots of packed single-precision values in xmm2/mem and stores the results in xmm1.

vrsqrtps xmm1, xmm2
vrsqrtps xmm1, [rax]

; Computes the approximate reciprocals of the square roots of packed single-precision values in ymm2/mem and stores the results in ymm1.

vrsqrtps ymm1, ymm2
vrsqrtps ymm1, [rax]

; Computes the approximate reciprocal of the square root of the low single precision floating-point value in xmm3/m32 and stores the results in xmm1. Also, upper single precision floating-point values (bits[127:32]) from xmm2 are copied to xmm1[127:32].

vrsqrtss xmm1, xmm2, xmm3
vrsqrtss xmm1, xmm2, [rax]

; Return the maximum single-precision floating-point values between xmm2 and xmm3/mem.

vmaxps xmm1, xmm2, xmm3
vmaxps xmm1, xmm2, [rax]

; Return the maximum single-precision floating-point values between ymm2 and ymm3/mem.

vmaxps ymm1, ymm2, ymm3
vmaxps ymm1, ymm2, [rax]

; Return the maximum scalar single-precision floating-point value between xmm3/m32 and xmm2.

vmaxss xmm1, xmm2, xmm3
vmaxss xmm1, xmm2, [rax]

; Return the minimum single-precision floating-point values between xmm2 and xmm3/mem.

vminps xmm1, xmm2, xmm3
vminps xmm1, xmm2, [rax]

; Return the minimum single-precision floating-point values between ymm2 and ymm3/mem.

vminps ymm1, ymm2, ymm3
vminps ymm1, ymm2, [rax]

; Return the minimum scalar single-precision floating-point value between xmm3/m32 and xmm2.

vminss xmm1, xmm2, xmm3
vminss xmm1, xmm2, [rax]

; Return the bitwise logical AND of packed single-precision floating-point values in xmm2 and xmm3/mem.

vandps xmm1, xmm2, xmm3
vandps xmm1, xmm2, [rax]

; Return the bitwise logical AND of packed single-precision floating-point values in ymm2 and ymm3/mem.

vandps ymm1, ymm2, ymm3
vandps ymm1, ymm2, [rax]

; Return the bitwise logical AND NOT of packed single-precision floating-point values in xmm2 and xmm3/mem.

vandps xmm1, xmm2, xmm3
vandps xmm1, xmm2, [rax]

; Return the bitwise logical AND NOT of packed single-precision floating-point values in ymm2 and ymm3/mem.

vandnps ymm1, ymm2, ymm3
vandnps ymm1, ymm2, [rax]

; Return the bitwise logical OR of packed single-precision floating-point values in xmm2 and xmm3/mem.

vorps xmm1, xmm2, xmm3
vorps xmm1, xmm2, [rax]

; Return the bitwise logical OR of packed single-precision floating-point values in ymm2 and ymm3/mem.

vorps ymm1, ymm2, ymm3
vorps ymm1, ymm2, [rax]

; Return the bitwise logical XOR of packed single-precision floating-point values in xmm2 and xmm3/mem.

vxorps xmm1, xmm2, xmm3
vxorps xmm1, xmm2, [rax]

; Return the bitwise logical XOR of packed single-precision floating-point values in ymm2 and ymm3/mem.

vxorps ymm1, ymm2, ymm3
vxorps ymm1, ymm2, [rax]

; Compare packed single-precision floating-point values in xmm3/m128 and xmm2 using bits 4:0 of imm8 as a comparison predicate.

vcmpps xmm1, xmm2, xmm3, 0x69
vcmpps xmm1, xmm2, [rax], 0x69

; Compare packed single-precision floating-point values in ymm3/m256 and ymm2 using bits 4:0 of imm8 as a comparison predicate.

vcmpps ymm1, ymm2, ymm3, 0x69
vcmpps ymm1, ymm2, [rax], 0x69

; Compare low single-precision floating-point value in xmm3/m32 and xmm2 using bits 4:0 of imm8 as comparison predicate.

vcmpss xmm1, xmm2, xmm3, 0x69
vcmpss xmm1, xmm2, [rax], 0x69

; Compare low single-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.

vcomiss xmm1, xmm2
vcomiss xmm1, [rax]

; Compare low single-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.

vucomiss xmm1, xmm2
vucomiss xmm1, [rax]

; Select from quadruplet of single-precision floating-point values in xmm1 and xmm2/m128 using imm8, interleaved result pairs are stored in xmm1.

vshufps xmm1, xmm2, xmm3, 0x69
vshufps xmm1, xmm2, [rax], 0x69

; Select from quadruplet of single-precision floating-point values in ymm2 and ymm3/m256 using imm8, interleaved result pairs are stored in ymm1.

vshufps ymm1, ymm2, ymm3, 0x69
vshufps ymm1, ymm2, [rax], 0x69

; Unpacks and Interleaves single-precision floating-point values from high quadwords of xmm2 and xmm3/m128.

vunpckhps xmm1, xmm2, xmm3
vunpckhps xmm1, xmm2, [rax]

; Unpacks and Interleaves single-precision floating-point values from high quadwords of ymm2 and ymm3/m256.

vunpckhps ymm1, ymm2, ymm3
vunpckhps ymm1, ymm2, [rax]

; Unpacks and Interleaves single-precision floating-point values from low quadwords of xmm2 and xmm3/m128.

vunpcklps xmm1, xmm2, xmm3
vunpcklps xmm1, xmm2, [rax]

; Unpacks and Interleaves single-precision floating-point values from low quadwords of ymm2 and ymm3/m256.

vunpcklps ymm1, ymm2, ymm3
vunpcklps ymm1, ymm2, [rax]

; Convert one signed doubleword integer from r/m32 to one single-precision floating-point value in xmm1.

vcvtsi2ss xmm1, xmm2, eax
vcvtsi2ss xmm1, xmm2, DWORD [rax]

; Convert one signed quadword integer from r/m64 to one single-precision floating-point value in xmm1.

vcvtsi2ss xmm1, xmm2, rax
vcvtsi2ss xmm1, xmm2, QWORD [rax]

; Convert one single-precision floating-point value from xmm1/m32 to one signed doubleword integer in r32.

vcvtss2si eax, xmm1
vcvtss2si eax, DWORD [rdi]

; Convert one single-precision floating-point value from xmm1/m32 to one signed quadword integer in r64.

vcvtss2si rax, xmm1
vcvtss2si rax, DWORD [rdi]

; Convert one single-precision floating-point value from xmm1/m32 to one signed doubleword integer in r32 using truncation.

vcvttss2si eax, xmm1
vcvttss2si eax, DWORD [rdi]

; Convert one single-precision floating-point value from xmm1/m32 to one signed quadword integer in r64 using truncation.

vcvttss2si rax, xmm1
vcvttss2si rax, DWORD [rdi]

; Average packed unsigned byte integers from xmm3/m128 and xmm2 with rounding.

vpavgb xmm1, xmm2, xmm3
vpavgb xmm1, xmm2, [rax]

; Average packed unsigned word integers from xmm3/m128 and xmm2 with rounding.

vpavgw xmm1, xmm2, xmm3
vpavgw xmm1, xmm2, [rax]

; Extract a word integer value from xmm2 at the source word offset specified by imm8 into reg or m16. The upper bits of r64/r32 is filled with zeros.

vpextrw rax, xmm2, 0x69
vpextrw WORD [rax], xmm2, 0x69

; Insert a word integer value from r32/m16 and rest from xmm2 into xmm1 at the word offset in imm8.

vpinsrw xmm1, xmm2, eax, 0x69
vpinsrw xmm1, xmm2, WORD [rax], 0x69

; Compare packed unsigned byte integers in xmm2 and xmm3/m128 and store packed maximum values in xmm1.

vpmaxub xmm1, xmm2, xmm3
vpmaxub xmm1, xmm2, [rax]

; Compare packed unsigned word integers in xmm3/m128 and xmm2 and store maximum packed values in xmm1.

vpmaxuw xmm1, xmm2, xmm3
vpmaxuw xmm1, xmm2, [rax]

; Compare packed unsigned byte integers in xmm2 and xmm3/m128 and store packed minimum values in xmm1.

vpminub xmm1, xmm2, xmm3
vpminub xmm1, xmm2, [rax]

; Compare packed unsigned word integers in xmm3/m128 and xmm2 and store minimum packed values in xmm1.

vpminuw xmm1, xmm2, xmm3
vpminuw xmm1, xmm2, [rax]

; Compare packed signed byte integers in xmm2 and xmm3/m128 and store packed maximum values in xmm1.

vpmaxsb xmm1, xmm2, xmm3
vpmaxsb xmm1, xmm2, [rax]

; Compare packed signed word integers in xmm3/m128 and xmm2 and store packed maximum values in xmm1.

vpmaxsw xmm1, xmm2, xmm3
vpmaxsw xmm1, xmm2, [rax]

; Compare packed signed dword integers in xmm2 and xmm3/m128 and store packed maximum values in xmm1.

vpmaxsd xmm1, xmm2, xmm3
vpmaxsd xmm1, xmm2, [rax]

; Compare packed signed byte integers in xmm2 and xmm3/m128 and store packed minimum values in xmm1.

vpminsb xmm1, xmm2, xmm3
vpminsb xmm1, xmm2, [rax]

; Compare packed signed word integers in xmm3/m128 and xmm2 and store packed minimum values in xmm1.

vpminsw xmm1, xmm2, xmm3
vpminsw xmm1, xmm2, [rax]

; Move a byte mask of xmm1 to reg. The upper bits of r32 or r64 are zeroed

; pmovmskb rax, xmm1 ; TODO: WHY DOESNT COMPILE ?

; Multiply the packed unsigned word integers in xmm2 and xmm3/m128, and store the high 16 bits of the results in xmm1.

vpmulhuw xmm1, xmm2, xmm3
vpmulhuw xmm1, xmm2, [rax]

; Computes the absolute differences of the packed unsigned byte integers from xmm3 /m128 and xmm2; the 8 low differences and 8 high differences are then summed separately to produce two unsigned word integer results.

vpsadbw xmm1, xmm2, xmm3
vpsadbw xmm1, xmm2, [rax]

; Load MXCSR register from m32.

vldmxcsr DWORD [rdi]

; Store contents of MXCSR register to m32.

vstmxcsr DWORD [rdi]

; Move aligned packed double-precision floating-point values from xmm2/mem to xmm1.

vmovapd xmm7, xmm2
vmovapd xmm7, [rax]

; Move aligned packed double-precision floating-point values from xmm1 to xmm2/mem.

vmovapd [rax], xmm7

; Move aligned packed double-precision floating-point values from ymm2/mem to ymm1.

vmovapd ymm7, ymm2
vmovapd ymm7, [rax]

; Move aligned packed double-precision floating-point values from ymm1 to ymm2/mem.

vmovapd [rax], ymm7

; Move unaligned packed double-precision floating-point values from xmm2/mem to xmm1.

vmovupd xmm7, xmm2
vmovupd xmm7, [rax]

; Move unaligned packed double-precision floating-point values from xmm1 to xmm2/mem.

vmovupd [rax], xmm7

; Move unaligned packed double-precision floating-point values from ymm2/mem to ymm1.

vmovupd ymm7, ymm2
vmovupd ymm7, [rax]

; Move unaligned packed double-precision floating-point values from ymm1 to ymm2/mem.

vmovupd [rax], ymm7

; Merge scalar double-precision floating-point value from xmm2 and xmm3 to xmm1 register

vmovsd xmm1, xmm2, xmm3 

; Load scalar double-precision floating-point value from m32 to xmm1 register.

vmovsd xmm8, [rdi]

; Move scalar double-precision floating-point value from xmm1 register to m32.

vmovsd [rdi], xmm8

; Merge two packed double-precision floating-point values from m64 and the low quadword of xmm1.

vmovlpd xmm2, xmm1, [rax]

; Move two packed double-precision floating-point values from low quadword of xmm1 to m64.

vmovlpd [rax], xmm1

; Merge two packed double-precision floating-point values from m64 and the high quadword of xmm1.

vmovhpd xmm2, xmm1, [rax]

; Move two packed double-precision floating-point values from high quadword of xmm1 to m64.

vmovhpd [rax], xmm1

; Extract 4-bit sign mask from xmm2 and store in reg. The upper bits of r32 or r64 are zeroed.

vmovmskpd rax, xmm2

; Add packed double-precision floating-point values from xmm3/m128 to xmm2 and store result in xmm1.

vaddpd xmm1, xmm2, xmm3
vaddpd xmm1, xmm2, [rdi]

; Add packed double-precision floating-point values from ymm3/m256 to ymm2 and store result in ymm1.

vaddpd ymm1, ymm2, ymm3
vaddpd ymm1, ymm2, [rdi]

; Add the low double-precision floating-point value from xmm3/mem to xmm2 and store the result in xmm1.

vaddsd xmm1, xmm2, xmm3
vaddsd xmm1, xmm2, QWORD [rax]

; Multiply packed double-precision floating-point values in xmm3/m128 with xmm2 and store result in xmm1.

vmulpd xmm1, xmm2, xmm3
vmulpd xmm1, xmm2, [rax]

; Multiply packed double-precision floating-point values in ymm3/m256 with ymm2 and store result in ymm1.

vmulpd ymm1, ymm2, ymm3
vmulpd ymm1, ymm2, [rax]

; Multiply the low double-precision floating-point value in xmm3/m32 by the low double-precision floating-point value in xmm2.

vmulsd xmm1, xmm2, xmm3
vmulsd xmm1, xmm2, [rax]

; Divide packed double-precision floating-point values in xmm2 by packed double-precision floating-point values in xmm3/mem.

vdivpd xmm1, xmm2, xmm3
vdivpd xmm1, xmm2, [rax]

; Divide packed double-precision floating-point values in ymm2 by packed double-precision floating-point values in ymm3/mem.

vdivpd ymm1, ymm2, ymm3
vdivpd ymm1, ymm2, [rax]

; Divide low double-precision floating-point value in xmm2 by low double-precision floating-point value in xmm3/m32.

vdivsd xmm1, xmm2, xmm3
vdivsd xmm1, xmm2, [rax]

; Computes Square Roots of the packed double-precision floating-point values in xmm2/m128 and stores the result in xmm1.

vsqrtpd xmm1, xmm2
vsqrtpd xmm1, [rax]

; Computes Square Roots of the packed double-precision floating-point values in ymm2/m256 and stores the result in ymm1.

vsqrtpd ymm1, ymm2
vsqrtpd ymm1, [rax]

; Computes square root of the low double-precision floating-point value in xmm3/m32 and stores the results in xmm1. Also, upper double-precision floating-point values (bits[127:32]) from xmm2 are copied to xmm1[127:32].

vsqrtsd xmm1, xmm2, xmm3
vsqrtsd xmm1, xmm2, [rax]

; Return the maximum double-precision floating-point values between xmm2 and xmm3/mem.

vmaxpd xmm1, xmm2, xmm3
vmaxpd xmm1, xmm2, [rax]

; Return the maximum double-precision floating-point values between ymm2 and ymm3/mem.

vmaxpd ymm1, ymm2, ymm3
vmaxpd ymm1, ymm2, [rax]

; Return the maximum scalar double-precision floating-point value between xmm3/m32 and xmm2.

vmaxsd xmm1, xmm2, xmm3
vmaxsd xmm1, xmm2, [rax]

; Return the minimum double-precision floating-point values between xmm2 and xmm3/mem.

vminpd xmm1, xmm2, xmm3
vminpd xmm1, xmm2, [rax]

; Return the minimum double-precision floating-point values between ymm2 and ymm3/mem.

vminpd ymm1, ymm2, ymm3
vminpd ymm1, ymm2, [rax]

; Return the minimum scalar double-precision floating-point value between xmm3/m32 and xmm2.

vminsd xmm1, xmm2, xmm3
vminsd xmm1, xmm2, [rax]

; Return the bitwise logical AND of packed double-precision floating-point values in xmm2 and xmm3/mem.

vandpd xmm1, xmm2, xmm3
vandpd xmm1, xmm2, [rax]

; Return the bitwise logical AND of packed double-precision floating-point values in ymm2 and ymm3/mem.

vandpd ymm1, ymm2, ymm3
vandpd ymm1, ymm2, [rax]

; Return the bitwise logical AND NOT of packed double-precision floating-point values in xmm2 and xmm3/mem.

vandpd xmm1, xmm2, xmm3
vandpd xmm1, xmm2, [rax]

; Return the bitwise logical AND NOT of packed double-precision floating-point values in ymm2 and ymm3/mem.

vandnpd ymm1, ymm2, ymm3
vandnpd ymm1, ymm2, [rax]

; Return the bitwise logical OR of packed double-precision floating-point values in xmm2 and xmm3/mem.

vorpd xmm1, xmm2, xmm3
vorpd xmm1, xmm2, [rax]

; Return the bitwise logical OR of packed double-precision floating-point values in ymm2 and ymm3/mem.

vorpd ymm1, ymm2, ymm3
vorpd ymm1, ymm2, [rax]

; Return the bitwise logical XOR of packed double-precision floating-point values in xmm2 and xmm3/mem.

vxorpd xmm1, xmm2, xmm3
vxorpd xmm1, xmm2, [rax]

; Return the bitwise logical XOR of packed double-precision floating-point values in ymm2 and ymm3/mem.

vxorpd ymm1, ymm2, ymm3
vxorpd ymm1, ymm2, [rax]

; Compare packed double-precision floating-point values in xmm3/m128 and xmm2 using bits 4:0 of imm8 as a comparison predicate.

vcmppd xmm1, xmm2, xmm3, 0x69
vcmppd xmm1, xmm2, [rax], 0x69

; Compare packed double-precision floating-point values in ymm3/m256 and ymm2 using bits 4:0 of imm8 as a comparison predicate.

vcmppd ymm1, ymm2, ymm3, 0x69
vcmppd ymm1, ymm2, [rax], 0x69

; Compare low double-precision floating-point value in xmm3/m32 and xmm2 using bits 4:0 of imm8 as comparison predicate.

vcmpsd xmm1, xmm2, xmm3, 0x69
vcmpsd xmm1, xmm2, [rax], 0x69

; Compare low double-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.

vcomisd xmm1, xmm2
vcomisd xmm1, [rax]

; Compare low double-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.

vucomisd xmm1, xmm2
vucomisd xmm1, [rax]

; Select from quadruplet of double-precision floating-point values in ymm2 and ymm3/m256 using imm8, interleaved result pairs are stored in ymm1.

vshufpd ymm1, ymm2, ymm3, 0x69
vshufpd ymm1, ymm2, [rax], 0x69

; Unpacks and Interleaves double-precision floating-point values from high quadwords of xmm2 and xmm3/m128.

vunpckhpd xmm1, xmm2, xmm3
vunpckhpd xmm1, xmm2, [rax]

; Unpacks and Interleaves double-precision floating-point values from high quadwords of ymm2 and ymm3/m256.

vunpckhpd ymm1, ymm2, ymm3
vunpckhpd ymm1, ymm2, [rax]

; Unpacks and Interleaves double-precision floating-point values from low quadwords of xmm2 and xmm3/m128.

vunpcklpd xmm1, xmm2, xmm3
vunpcklpd xmm1, xmm2, [rax]

; Unpacks and Interleaves double-precision floating-point values from low quadwords of ymm2 and ymm3/m256.

vunpcklpd ymm1, ymm2, ymm3
vunpcklpd ymm1, ymm2, [rax]

; Convert two packed single-precision floating-point values in xmm2/m64 to two packed double-precision floating-point values in xmm1.

vcvtps2pd xmm1, xmm2
vcvtps2pd xmm1, [rax]

; Convert four packed single-precision floating-point values in xmm2/m128 to four packed double-precision floating-point values in ymm1.

vcvtps2pd ymm1, xmm2
vcvtps2pd ymm1, [rax]

; Convert two packed double-precision floating-point values in xmm2/mem to two single-precision floating-point values in xmm1.

vcvtpd2ps xmm1, xmm2
vcvtpd2ps xmm1, [rax]

; Convert four packed double-precision floating-point values in ymm2/mem to four single-precision floating-point values in xmm1.

vcvtpd2ps xmm1, ymm2
vcvtpd2ps xmm1, [rax]

; Convert one single-precision floating-point value in xmm3/m32 to one double-precision floating-point value and merge with high bits of xmm2.

vcvtss2sd xmm1, xmm2, xmm3
vcvtss2sd xmm1, xmm2, [rax]

; Convert one double-precision floating-point value in xmm3/m64 to one single-precision floating-point value and merge with high bits in xmm2.

vcvtsd2ss xmm1, xmm2, xmm3
vcvtsd2ss xmm1, xmm2, [rax]

; Convert two packed double-precision floating-point values in xmm2/mem to two signed doubleword integers in xmm1.

vcvtpd2dq xmm1, xmm2
vcvtpd2dq xmm1, [rax]

; Convert four packed double-precision floating-point values in ymm2/mem to four signed doubleword integers in xmm1.

vcvtpd2dq xmm1, ymm2
vcvtpd2dq xmm1, [rax]

; Convert two packed double-precision floating-point values in xmm2/mem to two signed doubleword integers in xmm1 using truncation.

vcvttpd2dq xmm1, xmm2
vcvttpd2dq xmm1, [rax]

; Convert four packed double-precision floating-point values in ymm2/mem to four signed doubleword integers in xmm1 using truncation.

vcvttpd2dq xmm1, ymm2
vcvttpd2dq xmm1, [rax]

; Convert two packed signed doubleword integers from xmm2/mem to two packed double-precision floating-point values in xmm1.

vcvtdq2pd xmm1, xmm2
vcvtdq2pd xmm1, [rax]

; Convert four packed signed doubleword integers from xmm2/mem to four packed double-precision floating-point values in ymm1.

vcvtdq2pd ymm1, xmm2
vcvtdq2pd ymm1, [rax]

; Convert one double-precision floating-point value from xmm1/m64 to one signed doubleword integer r32.

vcvtsd2si eax, xmm1
vcvtsd2si eax, QWORD [rdi]

; Convert one double-precision floating-point value from xmm1/m64 to one signed quadword integer sign-extended into r64.

vcvtsd2si rax, xmm1
vcvtsd2si rax, QWORD [rdi]

; Convert one double-precision floating-point value from xmm1/m64 to one signed doubleword integer in r32 using truncation.

vcvttsd2si eax, xmm1
vcvttsd2si eax, QWORD [rdi]

; Convert one double-precision floating-point value from xmm1/m64 to one signed quadword integer in r64 using truncation.

vcvttsd2si rax, xmm1
vcvttsd2si rax, QWORD [rdi]

; Convert one signed doubleword integer from r/m32 to one double-precision floating-point value in xmm1.

vcvtsi2sd xmm1, xmm2, eax
vcvtsi2sd xmm1, xmm2, DWORD [rax]

; Convert one signed quadword integer from r/m64 to one double-precision floating-point value in xmm1.

vcvtsi2sd xmm1, xmm2, rax
vcvtsi2sd xmm1, xmm2, QWORD [rax]

; Convert four packed single-precision floating-point values from xmm2/mem to four packed signed doubleword values in xmm1.

vcvtps2dq xmm1, xmm2
vcvtps2dq xmm1, [rax]

; Convert eight packed single-precision floating-point values from ymm2/mem to eight packed signed doubleword values in ymm1.

vcvtps2dq ymm1, ymm2
vcvtps2dq ymm1, [rax]

; Convert four packed single-precision floating-point values from xmm2/mem to four packed signed doubleword values in xmm1 using truncation.

vcvttps2dq xmm1, xmm2
vcvttps2dq xmm1, [rax]

; Convert eight packed single-precision floating-point values from ymm2/mem to eight packed signed doubleword values in ymm1 using truncation.

vcvttps2dq ymm1, ymm2
vcvttps2dq ymm1, [rax]

; Convert four packed signed doubleword integers from xmm2/mem to four packed single-precision floating-point values in xmm1.

vcvtdq2ps xmm1, xmm2
vcvtdq2ps xmm1, [rax]

; Convert eight packed signed doubleword integers from ymm2/mem to eight packed single-precision floating-point values in ymm1.

vcvtdq2ps ymm1, ymm2
vcvtdq2ps ymm1, [rax]

; Move aligned packed integer values from xmm2/mem to xmm1.

vmovdqa xmm1, xmm2
vmovdqa xmm1, [rax]

; Move aligned packed integer values from xmm1 to xmm2/mem.

vmovdqa [rax], xmm1

; Move aligned packed integer values from ymm2/mem to ymm1.

vmovdqa ymm1, ymm2
vmovdqa ymm1, [rax]

; Move aligned packed integer values from ymm1 to ymm2/mem.

vmovdqa [rax], ymm1

; Move unaligned packed integer values from xmm2/mem to xmm1.

vmovdqu xmm1, xmm2
vmovdqu xmm1, [rax]

; Move unaligned packed integer values from xmm1 to xmm2/mem.

vmovdqu [rax], xmm1

; Move unaligned packed integer values from ymm2/mem to ymm1.

vmovdqu ymm1, ymm2
vmovdqu ymm1, [rax]

; Move unaligned packed integer values from ymm1 to ymm2/mem.

vmovdqu [rax], ymm1

; Subtract packed quadword integers in xmm3/m128 from xmm2.

vpsubq xmm1, xmm2
vpsubq xmm1, [rax]

; Multiply packed unsigned doubleword integers in xmm2 by packed unsigned doubleword integers in xmm3/m128, and store the quadword results in xmm1.

vpmuldq xmm1, xmm2, xmm3
vpmuldq xmm1, xmm2, [rax]

; Shuffle the low words in xmm2/m128 based on the encoding in imm8 and store the result in xmm1.

vpshuflw xmm1, xmm2, 0x69
vpshuflw xmm2, [rax], 0x69

; Shuffle the high words in xmm2/m128 based on the encoding in imm8 and store the result in xmm1.

vpshufhw xmm1, xmm2, 0x69
vpshufhw xmm2, [rax], 0x69

; Shuffle the doublewords in xmm2/m128 based on the encoding in imm8 and store the result in xmm1.

vpshufd xmm1, xmm2, 0x69
vpshufd xmm2, [rax], 0x69

; Shift xmm2 left by imm8 bytes while shifting in 0s and store result in xmm1.

vpslldq xmm1, xmm2, 0x69

; Shift xmm2 right by imm8 bytes while shifting in 0s and store result in xmm1.

vpsrldq xmm1, xmm2, 0x69

; Move packed integer values in xmm1 to m128 using non-temporal hint.

vmovntdq [rax], xmm1

; Move packed integer values in ymm1 to m256 using non-temporal hint.

vmovntdq [rax], ymm1

; Move packed double-precision values in xmm1 to m128 using non-temporal hint.

vmovntpd [rax], xmm1

; Move packed double-precision values in ymm1 to m256 using non-temporal hint.

vmovntpd [rax], ymm1

; Selectively write bytes from xmm1 to memory location using the byte mask in xmm2. The default memory location is specified by DS:DI/EDI/RDI.

vmaskmovdqu xmm1, xmm2

; Gives hint to processor that improves performance of spin-wait loops.

pause

; Load unaligned packed integer values from mem to xmm1.

vlddqu xmm1, [rax]

; Load unaligned packed integer values from mem to ymm1.

vlddqu ymm1, [rax]

; Move odd index single-precision floating-point values from xmm2/mem and duplicate each element into xmm1.

vmovshdup xmm1, xmm2
vmovshdup xmm1, [rax]

; Move odd index single-precision floating-point values from ymm2/mem and duplicate each element into ymm1.

vmovshdup ymm1, ymm2
vmovshdup ymm1, [rax]

; Move even index single-precision floating-point values from xmm2/mem and duplicate each element into xmm1.

vmovsldup xmm1, xmm2
vmovsldup xmm1, [rax]

; Move even index single-precision floating-point values from ymm2/mem and duplicate each element into ymm1.

vmovsldup ymm1, ymm2
vmovsldup ymm1, [rax]

; Move double-precision floating-point value from xmm2/m64 and duplicate into xmm1.

vmovddup xmm1, xmm2
vmovddup xmm1, [rax]

; Move even index double-precision floating-point values from ymm2/mem and duplicate each element into ymm1.

vmovddup ymm1, ymm2
vmovddup ymm1, [rax]

; Add/subtract single-precision floating-point values from xmm3/mem to xmm2 and stores result in xmm1.

vaddsubps xmm1, xmm2
vaddsubps xmm1, [rax]

; Add / subtract single-precision floating-point values from ymm3/mem to ymm2 and stores result in ymm1.

vaddsubps ymm1, ymm2
vaddsubps ymm1, [rax]

; Add/subtract double-precision floating-point values from xmm3/mem to xmm2 and stores result in xmm1.

vaddsubpd xmm1, xmm2
vaddsubpd xmm1, [rax]

; Add / subtract double-precision floating-point values from ymm3/mem to ymm2 and stores result in ymm1.

vaddsubpd ymm1, ymm2
vaddsubpd ymm1, [rax]

; Horizontal add packed single-precision floating-point values from xmm2 and xmm3/mem.

vhaddps xmm1, xmm2, xmm3
vhaddps xmm1, xmm2, [rax]

; Horizontal add packed single-precision floating-point values from ymm2 and ymm3/mem.

vhaddps ymm1, ymm2, ymm3
vhaddps ymm1, ymm2, [rax]

; Horizontal subtract packed single-precision floating-point values from xmm2 and xmm3/mem.

vhsubps xmm1, xmm2, xmm3
vhsubps xmm1, xmm2, [rax]

; Horizontal subtract packed single-precision floating-point values from ymm2 and ymm3/mem.

vhsubps ymm1, ymm2, ymm3
vhsubps ymm1, ymm2, [rax]


; Horizontal add packed double-precision floating-point values from xmm2 and xmm3/mem.

vhaddpd xmm1, xmm2, xmm3
vhaddpd xmm1, xmm2, [rax]

; Horizontal add packed double-precision floating-point values from ymm2 and ymm3/mem.

vhaddpd ymm1, ymm2, ymm3
vhaddpd ymm1, ymm2, [rax]

; Horizontal subtract packed double-precision floating-point values from xmm2 and xmm3/mem.

vhsubpd xmm1, xmm2, xmm3
vhsubpd xmm1, xmm2, [rax]

; Horizontal subtract packed double-precision floating-point values from ymm2 and ymm3/mem.

vhsubpd ymm1, ymm2, ymm3
vhsubpd ymm1, ymm2, [rax]

; Add 16-bit integers horizontally, pack to xmm1.

vphaddw xmm1, xmm2, xmm3
vphaddw xmm1, xmm2, [rax]

; Add 16-bit signed integers horizontally, pack to ymm1.

vphaddw ymm1, ymm2, ymm3
vphaddw ymm1, ymm2, [rax]

; Add 32-bit integers horizontally, pack to xmm1.

vphaddd xmm1, xmm2, xmm3
vphaddd xmm1, xmm2, [rax]

; Add 32-bit signed integers horizontally, pack to ymm1.

vphaddd ymm1, ymm2, ymm3
vphaddd ymm1, ymm2, [rax]

; Add 16-bit signed integers horizontally, pack saturated integers to xmm1.

vphaddsw xmm1, xmm2, xmm3
vphaddsw xmm1, xmm2, [rax]

; Add 16-bit signed integers horizontally, pack saturated integers to ymm1.

vphaddsw ymm1, ymm2, ymm3
vphaddsw ymm1, ymm2, [rax]

; Subtract 16-bit integers horizontally, pack to xmm1.

vphsubw xmm1, xmm2, xmm3
vphsubw xmm1, xmm2, [rax]

; Subtract 16-bit signed integers horizontally, pack to ymm1.

vphsubw ymm1, ymm2, ymm3
vphsubw ymm1, ymm2, [rax]

; Subtract 32-bit integers horizontally, pack to xmm1.

vphsubd xmm1, xmm2, xmm3
vphsubd xmm1, xmm2, [rax]

; Subtract 32-bit signed integers horizontally, pack to ymm1.

vphsubd ymm1, ymm2, ymm3
vphsubd ymm1, ymm2, [rax]

; Subtract 16-bit signed integers horizontally, pack saturated integers to xmm1.

vphsubsw xmm1, xmm2, xmm3
vphsubsw xmm1, xmm2, [rax]

; Subtract 16-bit signed integers horizontally, pack saturated integers to ymm1.

vphsubsw ymm1, ymm2, ymm3
vphsubsw ymm1, ymm2, [rax]

; Compute the absolute value of bytes in xmm2/m128 and store UNSIGNED result in xmm1.

vpabsb xmm1, xmm3
vpabsb xmm1, [rax]

; Compute the absolute value of 16- bit integers in xmm2/m128 and store UNSIGNED result in xmm1.

vpabsw xmm1, xmm3
vpabsw xmm1, [rax]

; Compute the absolute value of 32- bit integers in xmm2/m128 and store UNSIGNED result in xmm1.

vpabsd xmm1, xmm3
vpabsd xmm1, [rax]

; Multiply signed and unsigned bytes, add horizontal pair of signed words, pack saturated signed-words to xmm1.

vpmaddubsw xmm1, xmm2, xmm3
vpmaddubsw xmm1, xmm2, [rax]

; Multiply 16-bit signed words, scale and round signed doublewords, pack high 16 bits to xmm1.

vpmulhrsw xmm1, xmm2, xmm3
vpmulhrsw xmm1, xmm2, [rax]

; Shuffle bytes in xmm2 according to contents of xmm3/m128.

vpshufb xmm1, xmm2, xmm3
vpshufb xmm1, xmm2, [rax]

; Negate/zero/preserve packed byte integers in xmm2 depending on the corresponding sign in xmm3/m128.

vpsignb xmm1, xmm2, xmm3
vpsignb xmm1, xmm2, [rax]

; Negate/zero/preserve packed word integers in xmm2 depending on the corresponding sign in xmm3/m128.

vpsignw xmm1, xmm2, xmm3
vpsignw xmm1, xmm2, [rax]

; Negate/zero/preserve packed doubleword integers in xmm2 depending on the corresponding sign in xmm3/m128.

vpsignd xmm1, xmm2, xmm3
vpsignd xmm1, xmm2, [rax]

; Concatenate xmm2 and xmm3/m128, extract byte aligned result shifted to the right by constant value in imm8 and result is stored in xmm1.

vpalignr xmm1, xmm2, xmm3, 0x69
vpalignr xmm1, xmm2, [rax], 0x69

; Multiply packed SP floating point values from xmm1 with packed SP floating point values from xmm2/mem selectively add and store to xmm1.

vdpps xmm1, xmm2, xmm3, 0x69
vdpps xmm1, xmm2, [rax], 0x69

; Multiply packed single-precision floating-point values from ymm2 with packed SP floating point values from ymm3/mem, selectively add pairs of elements and store to ymm1.

vdpps ymm1, ymm2, ymm3, 0x69
vdpps ymm1, ymm2, [rax], 0x69

; Selectively multiply packed DP floating-point values from xmm2 with packed DP floating-point values from xmm3, add and selectively store the packed DP floating-point values to xmm1.

vdppd xmm1, xmm2, xmm3, 0x69
vdppd xmm1, xmm2, [rax], 0x69

; Round packed single precision floating-point values in xmm2/m128 and place the result in xmm1. The rounding mode is determined by imm8.

vroundps xmm1, xmm2, 0x69
vroundps xmm1, [rax], 0x69

; Round packed single-precision floating-point values in ymm2/m256 and place the result in ymm1. The rounding mode is determined by imm8.

vroundps ymm1, ymm2, 0x69
vroundps ymm1, [rax], 0x69

; Round packed double precision floating-point values in xmm2/m128 and place the result in xmm1. The rounding mode is determined by imm8.

vroundpd xmm1, xmm2, 0x69
vroundpd xmm1, [rax], 0x69

; Round packed double-precision floating-point values in ymm2/m256 and place the result in ymm1. The rounding mode is determined by imm8.

vroundpd ymm1, ymm2, 0x69
vroundpd ymm1, [rax], 0x69

; Round the low packed single precision floating-point value in xmm3/m32 and place the result in xmm1. The rounding mode is determined by imm8. Also, upper packed single precision floating-point values (bits[127:32]) from xmm2 are copied to xmm1[127:32].

vroundss xmm1, xmm2, 0x69
vroundss xmm1, [rax], 0x69

; Round the low packed double precision floating-point value in xmm3/m32 and place the result in xmm1. The rounding mode is determined by imm8. Also, upper packed single precision floating-point values (bits[127:32]) from xmm2 are copied to xmm1[127:32].

vroundsd xmm1, xmm2, 0x69
vroundsd xmm1, [rax], 0x69

; Multiply the packed dword signed integers in xmm2 and xmm3/m128 and store the low 32 bits of each product in xmm1.

vpmulld xmm1, xmm2, xmm3
vpmulld xmm1, xmm2, [rax]

; Multiply packed signed doubleword integers in xmm2 by packed signed doubleword integers in xmm3/m128, and store the quadword results in xmm1.

vpmuldq xmm1, xmm2, xmm3
vpmuldq xmm1, xmm2, [rax]

; Move double quadword from m128 to xmm using non-temporal hint if WC memory type.

vmovntdqa xmm1, [rax]

; Select packed single-precision floating-point values from xmm2 and xmm3/m128 from mask in imm8 and store the values in xmm1.

vblendps xmm1, xmm2, xmm3, 0x69
vblendps xmm1, xmm2, [rax], 0x69

; Select packed single-precision floating-point values from ymm2 and ymm3/m256 from mask in imm8 and store the values in ymm1.

vblendps ymm1, ymm2, ymm3, 0x69
vblendps ymm1, ymm2, [rax], 0x69

; Select packed double-precision floating-point values from xmm2 and xmm3/m128 from mask in imm8 and store the values in xmm1.

vblendpd xmm1, xmm2, xmm3, 0x69
vblendpd xmm1, xmm2, [rax], 0x69

; Select packed double-precision floating-point values from ymm2 and ymm3/m256 from mask in imm8 and store the values in ymm1.

vblendpd ymm1, ymm2, ymm3, 0x69
vblendpd ymm1, ymm2, [rax], 0x69

; Conditionally copy single-precision floating-point values from xmm2 or xmm3/m128 to xmm1, based on mask bits in the specified mask operand, xmm4.

vblendvps xmm1, xmm2, xmm3, xmm4
vblendvps xmm1, xmm2, [rax], xmm4

; Conditionally copy single-precision floating-point values from ymm2 or ymm3/m256 to ymm1, based on mask bits in the specified mask register, ymm4.

vblendvps ymm1, ymm2, ymm3, ymm4
vblendvps ymm1, ymm2, [rax], ymm4

; Conditionally copy double-precision floating-point values from xmm2 or xmm3/m128 to xmm1, based on mask bits in the specified mask operand, xmm4.

vblendvpd xmm1, xmm2, xmm3, xmm4
vblendvpd xmm1, xmm2, [rax], xmm4

; Conditionally copy double-precision floating-point values from ymm2 or ymm3/m256 to ymm1, based on mask bits in the specified mask register, ymm4.

vblendvpd ymm1, ymm2, ymm3, ymm4
vblendvpd ymm1, ymm2, [rax], ymm4

; Select words from xmm2 and xmm3/m128 from mask specified in imm8 and store the values into xmm1.

vpblendw xmm1, xmm2, xmm3, 0x69
vpblendw xmm1, xmm2, [rax], 0x69

; Select words from ymm2 and ymm3/m256 from mask specified in imm8 and store the values into ymm1.

vpblendw ymm1, ymm2, ymm3, 0x69
vpblendw ymm1, ymm2, [rax], 0x69

; Compare packed unsigned dword integers in xmm2 and xmm3/m128 and store packed minimum values in xmm1.

vpminud xmm1, xmm2, xmm3
vpminud xmm1, xmm2, [rax]

; Compare packed signed dword integers in xmm2 and xmm3/m128 and store packed minimum values in xmm1

vpminsd xmm1, xmm2, xmm3
vpminsd xmm1, xmm2, [rax]

; Compare packed unsigned dword integers in xmm2 and xmm3/m128 and store packed maximum values in xmm1.

vpmaxud xmm1, xmm2, xmm3
vpmaxud xmm1, xmm2, [rax]

; Compare packed signed dword integers in xmm2 and xmm3/m128 and store packed maximum values in xmm1

vpmaxsd xmm1, xmm2, xmm3
vpmaxsd xmm1, xmm2, [rax]

; Extract one single-precision floating-point value from xmm1 at the offset specified by imm8 and store the result in reg or m32. Zero extend the results in 64-bit register if applicable.

vextractps eax, xmm1, 0x69
vextractps DWORD [rax], xmm1, 0x69

; Insert a single-precision floating-point value selected by imm8 from xmm3/m32 and merge with values in xmm2 at the specified destination element specified by imm8 and write out the result and zero out destination elements in xmm1 as indicated in imm8.

vinsertps xmm1, xmm2, xmm3, 0x69
vinsertps xmm1, xmm2, DWORD [rax], 0x69

; Merge a byte integer value from r32/m8 and rest from xmm2 into xmm1 at the byte offset in imm8.

vpinsrb xmm1, xmm2, eax, 0x69
vpinsrb xmm1, xmm2, BYTE [rax], 0x69

; Insert a dword integer value from r32/m32 and rest from xmm2 into xmm1 at the dword offset in imm8.

vpinsrd xmm1, xmm2, eax, 0x69
vpinsrd xmm1, xmm2, DWORD [rax], 0x69

; Insert a qword integer value from r64/m64 and rest from xmm2 into xmm1 at the qword offset in imm8.

vpinsrq xmm1, xmm2, rax, 0x69
vpinsrq xmm1, xmm2, QWORD [rax], 0x69

; Extract a byte integer value from xmm2 at the source byte offset specified by imm8 into reg or m8. The upper bits of r64/r32 is filled with zeros.

vpextrb eax, xmm2, 0x69
vpextrb BYTE [rax], xmm2, 0x69

; Extract a dword integer value from xmm2 at the source dword offset specified by imm8 into r32/m32.

vpextrd eax, xmm2, 0x69
vpextrd DWORD [rax], xmm2, 0x69

; Extract a qword integer value from xmm2 at the source dword offset specified by imm8 into r64/m64.

vpextrq rax, xmm2, 0x69
vpextrq QWORD [rax], xmm2, 0x69

; Sums absolute 8-bit integer difference of adjacent groups of 4 byte integers in xmm2 and xmm3/m128 and writes the results in xmm1. Starting offsets within xmm2 and xmm3/m128 are determined by imm8.

vmpsadbw xmm1, xmm2, xmm3, 0x69
vmpsadbw xmm1, xmm2, [rax], 0x69

; Find the minimum unsigned word in xmm2/m128 and place its value in the low word of xmm1 and its index in the second-lowest word of xmm1.

vphminposuw xmm1, xmm2,
vphminposuw xmm1, [rax]

; Set ZF and CF depending on bitwise AND and ANDN of sources.

vptest xmm1, xmm2,
vptest xmm1, [rax]

; Set ZF and CF depending on bitwise AND and ANDN of sources.

vptest ymm1, ymm2,
vptest ymm1, [rax]

; Compare packed quadwords in xmm3/m128 and xmm2 for equality.

vpcmpeqq xmm1, xmm2, xmm3
vpcmpeqq xmm1, xmm2, [rax]

; Convert 4 packed signed doubleword integers from xmm2 and 4 packed signed doubleword integers from xmm3/m128 into 8 packed unsigned word integers in xmm1 using unsigned saturation.

vpackusdw xmm1, xmm2, xmm3
vpackusdw xmm1, xmm2, [rax]

; Perform a packed comparison of string data with explicit lengths, generating an index, and storing the result in ECX.

vpcmpestri xmm1, xmm2, 0x69
vpcmpestri xmm1, [rax], 0x69

; Perform a packed comparison of string data with explicit lengths, generating a mask, and storing the result in XMM0.

vpcmpestrm xmm1, xmm2, 0x69
vpcmpestrm xmm1, [rax], 0x69

; Perform a packed comparison of string data with implicit lengths, generating an index, and storing the result in ECX.

vpcmpistri xmm1, xmm2, 0x69
vpcmpistri xmm1, [rax], 0x69

; Perform a packed comparison of string data with implicit lengths, generating a Mask, and storing the result in XMM0.

vpcmpistrm xmm1, xmm2, 0x69
vpcmpistrm xmm1, [rax], 0x69

; Compare packed signed qwords in xmm2 and xmm3/m128 for greater than.

vpcmpgtq xmm1, xmm2, xmm3
vpcmpgtq xmm1, xmm2, [rax]

; Broadcast single-precision floating-point element in mem to four locations in xmm1.

vbroadcastss xmm1, DWORD [rax]

; Broadcast single-precision floating-point element in mem to eight locations in ymm1.

vbroadcastss ymm1, DWORD [rax]

; Broadcast double-precision floating-point element in mem to four locations in ymm1.

vbroadcastsd ymm1, QWORD [rax]

; Broadcast 128 bits of floating-point data in mem to low and high 128-bits in ymm1.

vbroadcastf128 ymm1, [rax]

; Insert 128 bits of packed floating-point values from xmm3/m128 and the remaining values from ymm2 into ymm1.

vinsertf128 ymm1, ymm2, xmm3, 0x69
vinsertf128 ymm1, ymm2, [rax], 0x69

; Conditionally load packed single-precision values from m128 using mask in xmm2 and store in xmm1.

vmaskmovps xmm1, xmm2, [rax]

; Conditionally load packed single-precision values from m256 using mask in ymm2 and store in ymm1.

vmaskmovps ymm1, ymm2, [rax]

; Conditionally load packed double-precision values from m128 using mask in xmm2 and store in xmm1.

vmaskmovpd xmm1, xmm2, [rax]

; Conditionally load packed double-precision values from m256 using mask in ymm2 and store in ymm1.

vmaskmovpd ymm1, ymm2, [rax]

; Conditionally store packed single-precision values from xmm2 using mask in xmm1.

vmaskmovps [rax], xmm1, xmm2

; Conditionally store packed single-precision values from ymm2 using mask in ymm1.

vmaskmovps [rax], ymm1, ymm2

; Conditionally store packed double-precision values from xmm2 using mask in xmm1.

vmaskmovpd [rax], xmm1, xmm2

; Conditionally store packed double-precision values from ymm2 using mask in ymm1.

vmaskmovpd [rax], ymm1, ymm2

; Permute single-precision floating-point values in xmm2 using controls from xmm3/m128 and store result in xmm1.

vpermilps xmm1, xmm2, xmm3
vpermilps xmm1, xmm2, [rax]

; Permute single-precision floating-point values in ymm2 using controls from ymm3/m256 and store result in ymm1.

vpermilps ymm1, ymm2, ymm3
vpermilps ymm1, ymm2, [rax]

; Permute single-precision floating-point values in xmm2/m128 using controls from imm8.

vpermilps xmm1, xmm3, 0x69
vpermilps xmm1, [rax], 0x69

; Permute single-precision floating-point values in ymm2/m256 using controls from imm8.

vpermilps ymm1, ymm3, 0x69
vpermilps ymm1, [rax], 0x69

; Permute double-precision floating-point values in xmm2 using controls from xmm3/m128 and store result in xmm1.

vpermilpd xmm1, xmm2, xmm3
vpermilpd xmm1, xmm2, [rax]

; Permute double-precision floating-point values in ymm2 using controls from ymm3/m256 and store result in ymm1.

vpermilpd ymm1, ymm2, ymm3
vpermilpd ymm1, ymm2, [rax]

; Permute double-precision floating-point values in xmm2/m128 using controls from imm8.

vpermilpd xmm1, xmm3, 0x69
vpermilpd xmm1, [rax], 0x69

; Permute double-precision floating-point values in ymm2/m256 using controls from imm8.

vpermilpd ymm1, ymm3, 0x69
vpermilpd ymm1, [rax], 0x69

; Permute 128-bit floating-point fields in ymm2 and ymm3/mem using controls from imm8 and store result in ymm1.

vperm2f128 ymm1, ymm2, ymm3, 0x69
vperm2f128 ymm1, ymm2, [rax], 0x69

; Set ZF and CF depending on sign bit AND and ANDN of packed single-precision floating-point sources.

vtestps xmm1, xmm2
vtestps xmm1, [rax]

; Set ZF and CF depending on sign bit AND and ANDN of packed single-precision floating-point sources.

vtestps ymm1, ymm2
vtestps ymm1, [rax]

; Set ZF and CF depending on sign bit AND and ANDN of packed double-precision floating-point sources.

vtestpd xmm1, xmm2
vtestpd xmm1, [rax]

; Set ZF and CF depending on sign bit AND and ANDN of packed double-precision floating-point sources.

vtestpd ymm1, ymm2
vtestpd ymm1, [rax]

; Zero all YMM registers.

vzeroall

; Zero upper 128 bits of all YMM registers.

vzeroupper

; Convert four packed half precision (16-bit) floating-point values in xmm2/m64 to packed single-precision floating-point value in xmm1.
; NOTE: need F16C extension

vcvtph2ps xmm1, xmm2
vcvtph2ps xmm1, [rax]

; Convert eight packed half precision (16-bit) floating-point values in xmm2/m128 to packed single-precision floating-point value in ymm1.
; NOTE: need F16C extension

vcvtph2ps ymm1, xmm2
vcvtph2ps ymm1, [rax]

; Convert four packed single-precision floating-point values in xmm2 to packed half-precision (16-bit) floating-point values in xmm1/m64. Imm8 provides rounding controls.
; NOTE: need F16C extension

vcvtps2ph xmm1, xmm2, 0x69
vcvtps2ph [rax], xmm2, 0x69

; Convert eight packed single-precision floating-point values in ymm2 to packed half-precision (16-bit) floating-point values in xmm1/m128. Imm8 provides rounding controls.
; NOTE: need F16C extension

vcvtps2ph xmm1, ymm2, 0x69
vcvtps2ph [rax], ymm2, 0x69