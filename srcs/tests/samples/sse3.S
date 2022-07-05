
; Store ST(0) in m16int with truncation.

fisttp WORD [rax]

; Store ST(0) in m32int with truncation.

fisttp DWORD [rax]

; Store ST(0) in m64int with truncation.

fisttp QWORD [rax]

; Load unaligned data from mem and return double quadword in xmm1.

lddqu xmm1, [rax]

; Move odd index single-precision floating-point values from xmm2/mem and duplicate each element into xmm1.

movshdup xmm1, xmm2
movshdup xmm1, [rax]

; Move even index single-precision floating-point values from xmm2/mem and duplicate each element into xmm1.

movsldup xmm1, xmm2
movsldup xmm1, [rax]

; Move double-precision floating-point value from xmm2/m64 and duplicate into xmm1.

movddup xmm1, xmm2
movddup xmm1, [rax]

; Add/subtract single-precision floating-point values from xmm2/m128 to xmm1.

addsubps xmm1, xmm2
addsubps xmm1, [rax]

; Add/subtract double-precision floating-point values from xmm2/m128 to xmm1.

addsubpd xmm1, xmm2
addsubpd xmm1, [rax]

; Horizontal add packed single-precision floating-point values from xmm2/m128 to xmm1.

haddps xmm1, xmm2
haddps xmm1, [rax]

; Horizontal subtract packed single-precision floating-point values from xmm2/m128 to xmm1.

hsubps xmm1, xmm2
hsubps xmm1, [rax]


; Horizontal add packed double-precision floating-point values from xmm2/m128 to xmm1.

haddpd xmm1, xmm2
haddpd xmm1, [rax]

; Horizontal subtract packed double-precision floating-point values from xmm2/m128 to xmm1.

hsubpd xmm1, xmm2
hsubpd xmm1, [rax]

; Set Up Monitor Address

monitor

; A hint that allows the processor to stop instruction execution and enter an implementation-dependent optimized state until occurrence of a class of events.

mwait

; Add 16-bit integers horizontally, pack to mm1.

phaddw mm1, mm2
phaddw mm1, [rax]

; Add 16-bit integers horizontally, pack to xmm1.

phaddw xmm1, xmm2
phaddw xmm1, [rax]

; Add 32-bit integers horizontally, pack to mm1

phaddd mm1, mm2
phaddd mm1, [rax]

; Add 32-bit integers horizontally, pack to xmm1.

phaddd xmm1, xmm2
phaddd xmm1, [rax]

; Add 16-bit signed integers horizontally, pack saturated integers to mm1.

phaddsw mm1, mm2
phaddsw mm1, [rax]

; Add 16-bit signed integers horizontally, pack saturated integers to xmm1.

phaddsw xmm1, xmm2
phaddsw xmm1, [rax]

; Subtract 16-bit integers horizontally, pack to mm1.

phsubw mm1, mm2
phsubw mm1, [rax]

; Subtract 16-bit integers horizontally, pack to xmm1.

phsubw xmm1, xmm2
phsubw xmm1, [rax]

; Subtract 32-bit integers horizontally, pack to mm1

phsubd mm1, mm2
phsubd mm1, [rax]

; Subtract 32-bit integers horizontally, pack to xmm1.

phsubd xmm1, xmm2
phsubd xmm1, [rax]

; Subtract 16-bit signed integers horizontally, pack saturated integers to mm1.

phsubsw mm1, mm2
phsubsw mm1, [rax]

; Subtract 16-bit signed integers horizontally, pack saturated integers to xmm1.

phaddsw xmm1, xmm2
phaddsw xmm1, [rax]

; Compute the absolute value of bytes in mm2/m64 and store UNSIGNED result in mm1.

pabsb mm1, mm2
pabsb mm1, [rax]

; Compute the absolute value of bytes in xmm2/m128 and store UNSIGNED result in xmm1.

pabsb xmm1, xmm2
pabsb xmm1, [rax]

; Compute the absolute value of 16-bit integers in mm2/m64 and store UNSIGNED result in mm1.

pabsw mm1, mm2
pabsw mm1, [rax]

; Compute the absolute value of 16-bit integers in xmm2/m128 and store UNSIGNED result in xmm1.

pabsw xmm1, xmm2
pabsw xmm1, [rax]

; Compute the absolute value of 32-bit integers in mm2/m64 and store UNSIGNED result in mm1.

pabsd mm1, mm2
pabsd mm1, [rax]

; Compute the absolute value of 32-bit integers in xmm2/m128 and store UNSIGNED result in xmm1.

pabsd xmm1, xmm2
pabsd xmm1, [rax]

; Multiply signed and unsigned bytes, add horizontal pair of signed words, pack saturated signed-words to mm1.

pmaddubsw mm1, mm2
pmaddubsw mm1, [rax]

; Multiply signed and unsigned bytes, add horizontal pair of signed words, pack saturated signed-words to xmm1.

pmaddubsw xmm1, xmm2
pmaddubsw xmm1, [rax]

; Multiply 16-bit signed words, scale and round signed doublewords, pack high 16 bits to mm1.

pmulhrsw mm1, mm2
pmulhrsw mm1, [rax]

; Multiply 16-bit signed words, scale and round signed doublewords, pack high 16 bits to xmm1.

pmulhrsw xmm1, xmm2
pmulhrsw xmm1, [rax]

; Shuffle bytes in mm1 according to contents of mm2/m64.

pshufb mm1, mm2
pshufb mm1, [rax]

; Shuffle bytes in xmm1 according to contents of xmm2/m128.

pshufb xmm1, xmm2
pshufb xmm1, [rax]

; Negate/zero/preserve packed byte integers in mm1 depending on the corresponding sign in mm2/m64.

psignb mm1, mm2
psignb mm1, [rax]

; Negate/zero/preserve packed byte integers in xmm1 depending on the corresponding sign in xmm2/m128.

psignb xmm1, xmm2
psignb xmm1, [rax]

; Negate/zero/preserve packed word integers in mm1 depending on the corresponding sign in mm2/m128.

psignw mm1, mm2
psignw mm1, [rax]

; Negate/zero/preserve packed word integers in xmm1 depending on the corresponding sign in xmm2/m128.

psignw xmm1, xmm2
psignw xmm1, [rax]

; Negate/zero/preserve packed doubleword integers in mm1 depending on the corresponding sign in mm2/m128.

psignd mm1, mm2
psignd mm1, [rax]

; Negate/zero/preserve packed doubleword integers in xmm1 depending on the corresponding sign in xmm2/m128.

psignd xmm1, xmm2
psignd xmm1, [rax]

; Concatenate destination and source operands, extract byte-aligned result shifted to the right by constant value in imm8 into mm1.

palignr mm1, mm2, 0x69
palignr mm1, [rax], 0x69

; Concatenate destination and source operands, extract byte-aligned result shifted to the right by constant value in imm8 into xmm1.

palignr xmm1, xmm2, 0x69
palignr xmm1, [rax], 0x69

