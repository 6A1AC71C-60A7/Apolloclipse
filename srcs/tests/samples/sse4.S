
; Extract the word specified by imm8 from xmm and copy it to lowest 16 bits of reg or m16. Zero-extend the result in the destination, r32 or r64.

pextrw rax, xmm2, 0x69
pextrw WORD [rax], xmm2, 0x69

; Compare packed unsigned word integers in xmm2/m128 and xmm1 and stores maximum packed values in xmm1.

pmaxuw xmm1, xmm2
pmaxuw xmm1, [rax]

; Compare packed unsigned word integers in xmm2/m128 and xmm1 and stores minimum packed values in xmm1.

pminuw xmm1, xmm2
pminuw xmm1, [rax]

; Compare packed signed byte integers in xmm1 and xmm2/m128 and store packed maximum values in xmm1.

pmaxsb xmm1, xmm2
pmaxsb xmm1, [rax]

; Compare packed signed dword integers in xmm1 and xmm2/m128 and store packed maximum values in xmm1.

pmaxsd xmm1, xmm2
pmaxsd xmm1, [rax]

; Compare packed signed byte integers in xmm1 and xmm2/m128 and store packed minimum values in xmm1.

pminsb xmm1, xmm2
pminsb xmm1, [rax]

; Selectively multiply packed SP floating-point values from xmm1 with packed SP floating-point values from xmm2, add and selectively store the packed SP floating-point values or zero values to xmm1.

dpps xmm1, xmm2, 0x69
dpps xmm1, [rax], 0x69

; Selectively multiply packed DP floating-point values from xmm1 with packed SP floating-point values from xmm2, add and selectively store the packed DP floating-point values or zero values to xmm1.

dppd xmm1, xmm2, 0x69
dppd xmm1, [rax], 0x69

; Round packed single precision floating-point values in xmm2/m128 and place the result in xmm1. The rounding mode is determined by imm8.

roundps xmm1, xmm2, 0x69
roundps xmm1, [rax], 0x69

; Round packed double precision floating-point values in xmm2/m128 and place the result in xmm1. The rounding mode is determined by imm8.

roundpd xmm1, xmm2, 0x69
roundpd xmm1, [rax], 0x69

; Round the low packed single precision floating-point value in xmm2/m32 and place the result in xmm1. The rounding mode is determined by imm8.

roundss xmm1, xmm2, 0x69
roundss xmm1, [rax], 0x69

; Round the low packed double precision floating-point value in xmm2/m32 and place the result in xmm1. The rounding mode is determined by imm8.

roundsd xmm1, xmm2, 0x69
roundsd xmm1, [rax], 0x69

; Multiply the packed dword signed integers in xmm1 and xmm2/m128 and store the low 32 bits of each product in xmm1.

pmulld xmm1, xmm2
pmulld xmm1, [rax]

; Multiply packed signed doubleword integers in xmm1 by packed signed doubleword integers in xmm2/m128, and store the quadword results in xmm1.

pmuldq xmm1, xmm2
pmuldq xmm1, [rax]

; Move double quadword from m128 to xmm1 using non-temporal hint if WC memory type.

movntdqa xmm1, [rax]

; Select packed single precision floating-point values from xmm1 and xmm2/m128 from mask specified in imm8 and store the values into xmm1.

blendps xmm1, xmm2, 0x69
blendps xmm1, [rax], 0x69

; Select packed DP-FP values from xmm1 and xmm2/m128 from mask specified in imm8 and store the values into xmm1.

blendpd xmm1, xmm2, 0x69
blendpd xmm1, [rax], 0x69

; Select packed single precision floating-point values from xmm1 and xmm2/m128 from mask specified in XMM0 and store the values into xmm1.

blendvps xmm1, xmm2, xmm0
blendvps xmm1, [rax], xmm0

; Select packed double precision floating-point values from xmm1 and xmm2/m128 from mask specified in XMM0 and store the values into xmm1.

blendvpd xmm1, xmm2, xmm0
blendvpd xmm1, [rax], xmm0

; Select words from xmm1 and xmm2/m128 from mask specified in imm8 and store the values into xmm1.

pblendw xmm1, xmm2, 0x69
pblendw xmm1, [rax], 0x69

; Compare packed unsigned dword integers in xmm1 and xmm2/m128 and store packed minimum values in xmm1.

pminud xmm1, xmm2,
pminud xmm1, [rax]

; Compare packed signed dword integers in xmm1 and xmm2/m128 and store packed minimum values in xmm1.

pminsd xmm1, xmm2,
pminsd xmm1, [rax]

; Compare packed unsigned dword integers in xmm1 and xmm2/m128 and store packed maximum values in xmm1.

pmaxud xmm1, xmm2,
pmaxud xmm1, [rax]

; Compare packed signed dword integers in xmm1 and xmm2/m128 and store packed maximum values in xmm1.

pmaxsd xmm1, xmm2,
pmaxsd xmm1, [rax]

; Extract one single-precision floating-point value from xmm1 at the offset specified by imm8 and store the result in reg or m32. Zero extend the results in 64-bit register if applicable.

extractps eax, xmm1, 0x69
extractps DWORD [rax], xmm1, 0x69

; Insert a single-precision floating-point value selected by imm8 from xmm2/m32 into xmm1 at the specified destination element specified by imm8 and zero out destination elements in xmm1 as indicated in imm8.

insertps xmm1, xmm2, 0x69
insertps xmm1, DWORD [rax], 0x69

; Insert a byte integer value from r32/m8 into xmm1 at the destination element in xmm1 specified by imm8.

pinsrb xmm1, eax, 0x69
pinsrb xmm1, BYTE [rax], 0x69

; Insert a dword integer value from r/m32 into the xmm1 at the destination element specified by imm8.

pinsrd xmm1, eax, 0x69
pinsrd xmm1, DWORD [rax], 0x69

; Insert a qword integer value from r/m64 into the xmm1 at the destination element specified by imm8.

pinsrq xmm1, rax, 0x69
pinsrq xmm1, QWORD [rax], 0x69

; Extract a byte integer value from xmm2 at the source byte offset specified by imm8 into reg or m8. The upper bits of r32 or r64 are zeroed.

pextrb eax, xmm2, 0x69
pextrb BYTE [rax], xmm2, 0x69

; Extract a dword integer value from xmm2 at the source dword offset specified by imm8 into r/m32.

pextrd eax, xmm2, 0x69
pextrd DWORD [rax], xmm2, 0x69

; Extract a qword integer value from xmm2 at the source qword offset specified by imm8 into r/m64.

pextrq rax, xmm2, 0x69
pextrq QWORD [rax], xmm2, 0x69

; Sums absolute 8-bit integer difference of adjacent groups of 4 byte integers in xmm1 and xmm2/m128 and writes the results in xmm1. Starting offsets within xmm1 and xmm2/m128 are determined by imm8.

mpsadbw xmm1, xmm2, 0x69
mpsadbw xmm1, [rax], 0x69

; Find the minimum unsigned word in xmm2/m128 and place its value in the low word of xmm1 and its index in the second-lowest word of xmm1.

phminposuw xmm1, xmm2,
phminposuw xmm1, [rax]

; Set ZF if xmm2/m128 AND xmm1 result is all 0s. Set CF if xmm2/m128 AND NOT xmm1 result is all 0s.

ptest xmm1, xmm2,
ptest xmm1, [rax]

; Compare packed qwords in xmm2/m128 and xmm1 for equality.

pcmpeqq xmm1, xmm2,
pcmpeqq xmm1, [rax]

; Convert 4 packed signed doubleword integers from xmm1 and 4 packed signed doubleword integers from xmm2/m128 into 8 packed unsigned word integers in xmm1 using unsigned saturation.

packusdw xmm1, xmm2,
packusdw xmm1, [rax]

; Perform a packed comparison of string data with explicit lengths, generating an index, and storing the result in ECX.

pcmpestri xmm1, xmm2, 0x69
pcmpestri xmm1, [rax], 0x69

; Perform a packed comparison of string data with explicit lengths, generating a mask, and storing the result in XMM0.

pcmpestrm xmm1, xmm2, 0x69
pcmpestrm xmm1, [rax], 0x69

; Perform a packed comparison of string data with implicit lengths, generating an index, and storing the result in ECX.

pcmpistri xmm1, xmm2, 0x69
pcmpistri xmm1, [rax], 0x69

; Perform a packed comparison of string data with implicit lengths, generating a mask, and storing the result in XMM0.

pcmpistrm xmm1, xmm2, 0x69
pcmpistrm xmm1, [rax], 0x69

; Compare packed signed qwords in xmm2/m128 and xmm1 for greater than.

pcmpgtq xmm1, xmm2,
pcmpgtq xmm1, [rax]

