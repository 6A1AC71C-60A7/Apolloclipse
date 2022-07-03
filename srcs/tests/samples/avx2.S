
; Add packed byte integers from ymm2, and ymm3/m256 and store in ymm1.

vpaddb ymm7, ymm2, ymm15
vpaddb ymm7, ymm2, [rbp]

; Add packed word integers from ymm2, ymm3/m256 and store in ymm1.

vpaddw ymm7, ymm2, ymm15
vpaddw ymm7, ymm2, [rbp]

; Add packed doubleword integers from ymm2, ymm3/m256 and store in ymm1.

vpaddd ymm7, ymm2, ymm15
vpaddd ymm7, ymm2, [rbp]

; Add packed quadword integers from ymm2, ymm3/m256 and store in ymm1.

vpaddq ymm7, ymm2, ymm15
vpaddq ymm7, ymm2, [rbp]

; Subtract packed byte integers in ymm3/m256 from ymm2.

vpsubb ymm7, ymm2, ymm15
vpsubb ymm7, ymm2, [rbp]

; Subtract packed word integers in ymm3/m256 from ymm2.

vpsubw ymm7, ymm2, ymm15
vpsubw ymm7, ymm2, [rbp]

; Subtract packed doubleword integers in ymm3/m256 from ymm2.

vpsubd ymm7, ymm2, ymm15
vpsubd ymm7, ymm2, [rbp]

; Add packed signed byte integers from ymm2, and ymm3/m256 and store the saturated results in ymm1.

vpaddsb ymm7, ymm2, ymm15
vpaddsb ymm7, ymm2, [rbp]

; Add packed signed word integers from ymm2, and ymm3/m256 and store the saturated results in ymm1.

vpaddsw ymm7, ymm2, ymm15
vpaddsw ymm7, ymm2, [rbp]

; Subtract packed signed byte integers in ymm3/m256 from packed signed byte integers in ymm2 and saturate results.

vpsubsb ymm7, ymm2, ymm15
vpsubsb ymm7, ymm2, [rbp]

; Subtract packed signed word integers in ymm3/m256 from packed signed word integers in ymm2 and saturate results.

vpsubsw ymm7, ymm2, ymm15
vpsubsw ymm7, ymm2, [rbp]

; Add packed unsigned byte integers from ymm2, and ymm3/m256 and store the saturated results in ymm1.

vpaddusb ymm7, ymm2, ymm15
vpaddusb ymm7, ymm2, [rbp]

; Add packed unsigned word integers from ymm2, and ymm3/m256 and store the saturated results in ymm1.

vpaddusw ymm7, ymm2, ymm15
vpaddusw ymm7, ymm2, [rbp]

; Subtract packed unsigned byte integers in ymm3/m256 from packed unsigned byte integers in ymm2 and saturate result.

vpsubusb ymm7, ymm2, ymm15
vpsubusb ymm7, ymm2, [rbp]

; Subtract packed unsigned word integers in ymm3/m256 from packed unsigned word integers in ymm2 and saturate result.

vpsubusw ymm7, ymm2, ymm15
vpsubusw ymm7, ymm2, [rbp]

; Compare packed bytes in ymm3/m256 and ymm2 for equality.

vpcmpeqb ymm2, ymm4, ymm8
vpcmpeqb ymm2, ymm4, [rbx]

; Compare packed words in ymm3/m256 and ymm2 for equality.

vpcmpeqw ymm2, ymm4, ymm8
vpcmpeqw ymm2, ymm4, [rbx]

; Compare packed doublewords in ymm3/m256 and ymm2 for equality.

vpcmpeqd ymm2, ymm4, ymm8
vpcmpeqd ymm2, ymm4, [rbx]

; TODO HERE:: VPCMPGTPB

; Converts 16 packed signed word integers from ymm2 and from ymm3/m256 into 32 packed signed byte integers in ymm1 using signed saturation.

vpacksswb ymm2, ymm4, ymm8
vpacksswb ymm2, ymm4, [rbx]

; Converts 8 packed signed doubleword integers from ymm2 and from ymm3/m256 into 16 packed signed word integers in ymm1using signed saturation.

vpackssdw ymm2, ymm4, ymm8
vpackssdw ymm2, ymm4, [rbx]

; Converts 16 signed word integers from ymm2 and 16signed word integers from ymm3/m256 into 32 unsigned byte integers in ymm1 using unsigned saturation.

vpackuswb ymm2, ymm4, ymm8
vpackuswb ymm2, ymm4, [rbx]

; Interleave high-order bytes from ymm2 and ymm3/m256 into ymm1 register.

vpunpckhbw ymm2, ymm4, ymm8
vpunpckhbw ymm2, ymm4, [rbx]

; Interleave high-order words from ymm2 and ymm3/m256 into ymm1 register.

vpunpckhwd ymm2, ymm4, ymm8
vpunpckhwd ymm2, ymm4, [rbx]

; Interleave high-order doublewords from ymm2 and ymm3/m256 into ymm1 register.

vpunpckhdq ymm2, ymm4, ymm8
vpunpckhdq ymm2, ymm4, [rbx]

; Interleave high-order quadword from ymm2 and ymm3/m256 into ymm1 register.

vpunpckhqdq ymm2, ymm4, ymm8
vpunpckhqdq ymm2, ymm4, [rbx]

; Interleave low-order bytes from ymm2 and ymm3/m256 into ymm1 register.

vpunpcklbw ymm2, ymm4, ymm8
vpunpcklbw ymm2, ymm4, [rbx]

; Interleave low-order words from ymm2 and ymm3/m256 into ymm1 register.

vpunpcklwd ymm2, ymm4, ymm8
vpunpcklwd ymm2, ymm4, [rbx]

; Interleave low-order doublewords from ymm2 and ymm3/m256 into ymm1 register.

vpunpckldq ymm2, ymm4, ymm8
vpunpckldq ymm2, ymm4, [rbx]

; Interleave low-order quadword from ymm2 and ymm3/m256 into ymm1 register.

vpunpcklqdq ymm2, ymm4, ymm8
vpunpcklqdq ymm2, ymm4, [rbx]

; Bitwise AND of ymm2, and ymm3/m256 and store result in ymm1.

vpand ymm1, ymm3, ymm5
vpand ymm1, ymm3, [rcx]

; Bitwise AND NOT of ymm2, and ymm3/m256 and store result in ymm1.

vpandn ymm1, ymm3, ymm5
vpandn ymm1, ymm3, [rcx]

; Bitwise OR of ymm2, and ymm3/m256 and store result in ymm1.

vpor ymm1, ymm3, ymm5
vpor ymm1, ymm3, [rcx]

; Bitwise XOR of ymm2, and ymm3/m256 and store result in ymm1.

vpxor ymm1, ymm3, ymm5
vpxor ymm1, ymm3, [rcx]

; Shift words in ymm2 left by amount specified in xmm3/m128 while shifting in 0s.

vpsllw ymm1, ymm3, xmm5
vpsllw ymm1, ymm3, [rcx]

; Shift words in ymm2 left by imm8 while shifting in 0s.

vpsllw ymm2, ymm8, 0x69

; Shift doublewords in ymm2 left by amount specified in xmm3/m128 while shifting in 0s.

vpslld ymm1, ymm3, xmm5
vpslld ymm1, ymm3, [rcx]

; Shift doublewords in ymm2 left by imm8 while shifting in 0s.

vpslld ymm2, ymm8, 0x69

; Shift quadwords in ymm2 left by amount specified in xmm3/m128 while shifting in 0s.

vpsllq ymm1, ymm3, xmm5
vpsllq ymm1, ymm3, [rcx]

; Shift quadwords in ymm2 left by imm8 while shifting in 0s.

vpsllq ymm2, ymm8, 0x69

; Shift words in ymm2 right by amount specified in xmm3/m128 while shifting in 0s.

vpsrlw ymm1, ymm3, xmm5
vpsrlw ymm1, ymm3, [rcx]

; Shift words in ymm2 right by imm8 while shifting in 0s.

vpsrlw ymm2, ymm8, 0x69

; Shift doublewords in ymm2 right by amount specified in xmm3/m128 while shifting in 0s.

vpsrld ymm1, ymm3, xmm5
vpsrld ymm1, ymm3, [rcx]

; Shift doublewords in ymm2 right by imm8 while shifting in 0s.

vpsrld ymm2, ymm8, 0x69

; Shift quadwords in ymm2 right by amount specified in xmm3/m128 while shifting in 0s.

vpsrlq ymm1, ymm3, xmm5
vpsrlq ymm1, ymm3, [rcx]

; Shift quadwords in ymm2 right by imm8 while shifting in 0s.

vpsrlq ymm2, ymm8, 0x69

; Shift words in ymm2 right by amount specified in xmm3/m128 while shifting in sign bits.

vpsraw ymm1, ymm3, xmm5
vpsraw ymm1, ymm3, [rcx]

; Shift words in ymm2 right by imm8 while shifting in sign bits.

vpsraw ymm2, ymm8, 0x69

; Shift doublewords in ymm2 right by amount specified in xmm3/m128 while shifting in sign bits.

vpsrad ymm1, ymm3, xmm5
vpsrad ymm1, ymm3, [rcx]

; Shift words in ymm2 right by imm8 while shifting in sign bits.

vpsrad ymm2, ymm8, 0x69

