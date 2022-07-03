
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
