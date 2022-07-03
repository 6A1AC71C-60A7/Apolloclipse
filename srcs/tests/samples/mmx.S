
; Add packed byte integers from mm/m64 and mm.

paddb mm7, mm2
paddb mm7, [rax]

; Add packed word integers from mm/m64 and mm.

paddw mm7, mm2
paddw mm7, [rax]

; Add packed doubleword integers from mm/m64 and mm.

paddd mm7, mm2
paddd mm7, [rax]

; Add packed quadword integers from mm/m64 and mm.

paddq mm7, mm2
paddq mm7, [rax]

; Subtract packed byte integers in mm/m64 from packed byte integers in mm.

psubb mm7, mm2
psubb mm7, [rax]

; Subtract packed word integers in mm/m64 from packed word integers in mm.

psubw mm7, mm2
psubw mm7, [rax]

; Subtract packed doubleword integers in mm/m64 from packed doubleword integers in mm.

psubd mm7, mm2
psubd mm7, [rax]

; Add packed signed byte integers from mm/m64 and mm and saturate the results.

paddsb mm7, mm2
paddsb mm7, [rax]

; Add packed signed word integers from mm/m64 and mm and saturate the results.

paddsw mm7, mm2
paddsw mm7, [rax]

; Subtract signed packed bytes in mm/m64 from signed packed bytes in mm and saturate results.

psubsb mm7, mm2
psubsb mm7, [rax]

; Subtract signed packed words in mm/m64 from signed packed words in mm and saturate results.

psubsw mm7, mm2
psubsw mm7, [rax]

; Add packed unsigned byte integers from mm/m64 and mm and saturate the results.

paddusb mm7, mm2
paddusb mm7, [rax]

; Add packed unsigned word integers from mm/m64 and mm and saturate the results.

paddusw mm7, mm2
paddusw mm7, [rax]

; Subtract unsigned packed bytes in mm/m64 from unsigned packed bytes in mm and saturate result.

psubusb mm7, mm2
psubusb mm7, [rax]

; Subtract unsigned packed words in mm/m64 from unsigned packed words in mm and saturate result.

psubusw mm7, mm2
psubusw mm7, [rax]

; Compare packed bytes in mm/m64 and mm for equality.

pcmpeqb mm2, mm6
pcmpeqb mm2, [rsi]

; Compare packed words in mm/m64 and mm for equality.

pcmpeqw mm2, mm6
pcmpeqw mm2, [rsi]

; Compare packed doublewords in mm/m64 and mm for equality.

pcmpeqd mm2, mm6
pcmpeqd mm2, [rsi]

; TODO HERE:: PCMPGTPB

; Converts 4 packed signed word integers from mm1 and from mm2/m64 into 8 packed signed byte integers in mm1 using signed saturation.

packsswb mm2, mm6
packsswb mm2, [rsi]

; Converts 2 packed signed doubleword integers from mm1 and from mm2/m64 into 4 packed signed word integers in mm1 using signed saturation.

packssdw mm2, mm6
packssdw mm2, [rsi]

; Converts 4 signed word integers from mm and 4 signed word integers from mm/m64 into 8 unsigned byte integers in mm using unsigned saturation.

packuswb mm2, mm6
packuswb mm2, [rsi]

; Unpack and interleave high-order bytes from mm and mm/m64 into mm.

punpckhbw mm2, mm6
punpckhbw mm2, [rsi]

; Unpack and interleave high-order words from mm and mm/m64 into mm.

punpckhwd mm2, mm6
punpckhwd mm2, [rsi]

; Unpack and interleave high-order doublewords from mm and mm/m64 into mm.

punpckhdq mm2, mm6
punpckhdq mm2, [rsi]

; Unpack and interleave low-order bytes from mm and mm/m64 into mm.

punpcklbw mm2, mm6
punpcklbw mm2, [rsi]

; Unpack and interleave low-order words from mm and mm/m64 into mm.

punpcklwd mm2, mm6
punpcklwd mm2, [rsi]

; Unpack and interleave low-order doublewords from mm and mm/m64 into mm.

punpckldq mm2, mm6
punpckldq mm2, [rsi]

; Bitwise AND mm/m64 and mm.

pand mm7, mm5
pand mm7, [rcx]

; Bitwise AND NOT of mm/m64 and mm.

pandn mm7, mm5
pandn mm7, [rcx]

; Bitwise OR mm/m64 and mm.

por mm7, mm5
por mm7, [rcx]

; Bitwise XOR mm/m64 and mm.

pxor mm7, mm5
pxor mm7, [rcx]

; Shift words in mm left mm/m64 while shifting in 0s.

psllw mm7, mm5
psllw mm7, [rcx]

; Shift words in mm left by imm8 while shifting in 0s.

psllw mm7, 0x69

; Shift doublewords in mm left by mm/m64 while shifting in 0s.

pslld mm7, mm5
pslld mm7, [rcx]

; Shift doublewords in mm left by imm8 while shifting in 0s.

pslld mm7, 0x69

; Shift quadword in mm left by mm/m64 while shifting in 0s.

psllq mm7, mm5
psllq mm7, [rcx]

; Shift quadword in mm left by imm8 while shifting in 0s.

psllq mm7, 0x69

; Shift words in mm right mm/m64 while shifting in 0s.

psrlw mm7, mm5
psrlw mm7, [rcx]

; Shift words in mm right by imm8 while shifting in 0s.

psrlw mm7, 0x69

; Shift doublewords in mm right by mm/m64 while shifting in 0s.

psrld mm7, mm5
psrld mm7, [rcx]

; Shift doublewords in mm right by imm8 while shifting in 0s.

psrld mm7, 0x69

; Shift quadword in mm right by mm/m64 while shifting in 0s.

psrlq mm7, mm5
psrlq mm7, [rcx]

; Shift quadword in mm right by imm8 while shifting in 0s.

psrlq mm7, 0x69

; Shift words in mm right by mm/m64 while shifting in sign bits.

psraw mm7, mm5
psraw mm7, [rcx]

; Shift words in mm right by imm8 while shifting in sign bits

psraw mm7, 0x69

; Shift doublewords in mm right by mm/m64 while shifting in sign bits.

psrad mm7, mm5
psrad mm7, [rcx]

; Shift doublewords in mm right by imm8 while shifting in sign bits.

psrad mm7, 0x69

; Move doubleword from r/m32 to mm.

movd mm7, ecx
movd mm7, DWORD [rcx]

; Move quadword from r/m64 to mm.

movq mm7, rcx
movq mm7, QWORD [rcx]

; Move doubleword from mm to r/m32.

movd ecx, mm7
movd DWORD [rcx], mm7

; Move quadword from mm to r/m64.

movq rcx, mm7
movq QWORD [rcx], mm7

; Empty MMX Technology State

emms

