
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
