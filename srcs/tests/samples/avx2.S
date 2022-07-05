
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

; Average packed unsigned byte integers from ymm2, and ymm3/m256 with rounding and store to ymm1.

vpavgb ymm1, ymm2, ymm3
vpavgb ymm1, ymm2, [rax]

; Average packed unsigned word integers from ymm2, ymm3/m256 with rounding to ymm1.

vpavgw ymm1, ymm2, ymm3
vpavgw ymm1, ymm2, [rax]

; Compare packed unsigned byte integers in ymm2 and ymm3/m256 and store packed maximum values in ymm1.

vpmaxub ymm1, ymm2, ymm3
vpmaxub ymm1, ymm2, [rax]

; Compare packed unsigned word integers in ymm3/m256 and ymm2 and store maximum packed values in ymm1.

vpmaxuw ymm1, ymm2, ymm3
vpmaxuw ymm1, ymm2, [rax]

; Compare packed signed byte integers in ymm2 and ymm3/m256 and store packed maximum values in ymm1.

vpmaxsb ymm1, ymm2, ymm3
vpmaxsb ymm1, ymm2, [rax]

; Compare packed signed word integers in ymm3/m256 and ymm2 and store packed maximum values in ymm1.

vpmaxsw ymm1, ymm2, ymm3
vpmaxsw ymm1, ymm2, [rax]

; Compare packed signed dword integers in ymm2 and ymm3/m256 and store packed maximum values in ymm1.

vpmaxsd ymm1, ymm2, ymm3
vpmaxsd ymm1, ymm2, [rax]

; Compare packed signed byte integers in ymm2 and ymm3/m256 and store packed minimum values in ymm1.

vpminsb ymm1, ymm2, ymm3
vpminsb ymm1, ymm2, [rax]

; Compare packed signed word integers in ymm3/m256 and ymm2 and store packed minimum values in ymm1.

vpminsw ymm1, ymm2, ymm3
vpminsw ymm1, ymm2, [rax]

; Move a byte mask of ymm1 to reg. The upper bits of r32 or r64 are zeroed

; pmovmskb rax, ymm1 ; TODO: WHY DOESNT COMPILE ?

; Multiply the packed unsigned word integers in ymm2 and ymm3/m256, and store the high 16 bits of the results in ymm1.

vpmulhuw ymm1, ymm2, ymm3
vpmulhuw ymm1, ymm2, [rax]

; Computes the absolute differences of the packed unsigned byte integers from ymm3 /m256 and ymm2; then each consecutive 8 differences are summed separately to produce four unsigned word integer results.

vpsadbw ymm1, ymm2, ymm3
vpsadbw ymm1, ymm2, [rax]

; Subtract packed quadword integers in ymm3/m256 from ymm2.

vpsubq ymm1, ymm2
vpsubq ymm1, [rax]

; Multiply packed unsigned doubleword integers in ymm2 by packed unsigned doubleword integers in ymm3/m256, and store the quadword results in ymm1.

vpmuldq ymm1, ymm2, ymm3
vpmuldq ymm1, ymm2, [rax]

; Shuffle the low words in ymm2/m256 based on the encoding in imm8 and store the result in ymm1.

vpshuflw ymm1, ymm2, 0x69
vpshuflw ymm2, [rax], 0x69

; Shuffle the hugh words in ymm2/m256 based on the encoding in imm8 and store the result in ymm1.

vpshufhw ymm1, ymm2, 0x69
vpshufhw ymm2, [rax], 0x69

; Shuffle the doublewords in ymm2/m256 based on the encoding in imm8 and store the result in ymm1.

vpshufd ymm1, ymm2, 0x69
vpshufd ymm2, [rax], 0x69

; Shift ymm2 left by imm8 bytes while shifting in 0s and store result in ymm1.

vpslldq ymm1, ymm2, 0x69

; Shift ymm2 right by imm8 bytes while shifting in 0s and store result in ymm1.

vpsrldq ymm1, ymm2, 0x69

; Compute the absolute value of bytes in ymm2/m128 and store UNSIGNED result in ymm1.

vpabsb ymm1, ymm3
vpabsb ymm1, [rax]

; Compute the absolute value of 16- bit integers in ymm2/m128 and store UNSIGNED result in ymm1.

vpabsw ymm1, ymm3
vpabsw ymm1, [rax]

; Compute the absolute value of 32- bit integers in ymm2/m128 and store UNSIGNED result in ymm1.

vpabsd ymm1, ymm3
vpabsd ymm1, [rax]

; Multiply signed and unsigned bytes, add horizontal pair of signed words, pack saturated signed-words to ymm1.

vpmaddubsw ymm1, ymm2, ymm3
vpmaddubsw ymm1, ymm2, [rax]

; Multiply 16-bit signed words, scale and round signed doublewords, pack high 16 bits to ymm1.

vpmulhrsw ymm1, ymm2, ymm3
vpmulhrsw ymm1, ymm2, [rax]

; Shuffle bytes in ymm2 according to contents of ymm3/m256.

vpshufb ymm1, ymm2, ymm3
vpshufb ymm1, ymm2, [rax]

; Negate/zero/preserve packed byte integers in ymm2 depending on the corresponding sign in ymm3/m128.

vpsignb ymm1, ymm2, ymm3
vpsignb ymm1, ymm2, [rax]

; Negate/zero/preserve packed word integers in ymm2 depending on the corresponding sign in ymm3/m128.

vpsignw ymm1, ymm2, ymm3
vpsignw ymm1, ymm2, [rax]

; Negate/zero/preserve packed doubleword integers in ymm2 depending on the corresponding sign in ymm3/m128.

vpsignd ymm1, ymm2, ymm3
vpsignd ymm1, ymm2, [rax]

; Concatenate pairs of 16 bytes in ymm2 and ymm3/m256 into 32-byte intermediate result, extract byte-aligned, 16-byte result shifted to the right by constant values in imm8 from each intermediate result, and two 16-byte results are stored in ymm1.

vpalignr ymm1, ymm2, ymm3, 0x69
vpalignr ymm1, ymm2, [rax], 0x69

; Multiply the packed dword signed integers in ymm2 and ymm3/m256 and store the low 32 bits of each product in ymm1.

vpmulld ymm1, ymm2, ymm3
vpmulld ymm1, ymm2, [rax]

; Multiply packed signed doubleword integers in ymm2 by packed signed doubleword integers in ymm3/m256, and store the quadword results in ymm1.

vpmuldq ymm1, ymm2, ymm3
vpmuldq ymm1, ymm2, [rax]

; Move 256-bit data from m256 to ymm using non-temporal hint if WC memory type.

vmovntdqa ymm1, [rax]

; Compare packed unsigned dword integers in ymm2 and ymm3/m256 and store packed minimum values in ymm1.

vpminud ymm1, ymm2, ymm3
vpminud ymm1, ymm2, [rax]

; Compare packed signed dword integers in ymm2 and ymm3/m128 and store packed minimum values in ymm1.

vpminsd ymm1, ymm2, ymm3
vpminsd ymm1, ymm2, [rax]

; Compare packed unsigned dword integers in ymm2 and ymm3/m256 and store packed maximum values in ymm1.

vpmaxud ymm1, ymm2, ymm3
vpmaxud ymm1, ymm2, [rax]

; Compare packed signed dword integers in ymm2 and ymm3/m128 and store packed maximum values in ymm1.

vpmaxsd ymm1, ymm2, ymm3
vpmaxsd ymm1, ymm2, [rax]

; Sums absolute 8-bit integer difference of adjacent groups of 4 byte integers in xmm2 and ymm3/m128 and writes the results in ymm1. Starting offsets within ymm2 and xmm3/m128 are determined by imm8.

vmpsadbw ymm1, ymm2, ymm3, 0x69
vmpsadbw ymm1, ymm2, [rax], 0x69

; Compare packed quadwords in ymm3/m256 and ymm2 for equality.

vpcmpeqq ymm1, ymm2, ymm3
vpcmpeqq ymm1, ymm2, [rax]

; Convert 8 packed signed doubleword integers from ymm2 and 8 packed signed doubleword integers from ymm3/m256 into 16 packed unsigned word integers in ymm1 using unsigned saturation.

vpackusdw ymm1, ymm2, ymm3
vpackusdw ymm1, ymm2, [rax]

; Compare packed signed qwords in ymm2 and ymm3/m256 for greater than.

vpcmpgtq ymm1, ymm2, ymm3
vpcmpgtq ymm1, ymm2, [rax]

