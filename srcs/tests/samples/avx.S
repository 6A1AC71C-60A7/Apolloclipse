
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

vpaddd xmm7, xmm2, xmm15
vpaddd xmm7, xmm2, [rbp]

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
