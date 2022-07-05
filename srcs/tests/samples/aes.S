
; Perform one round of an AES decryption flow, using the Equivalent Inverse Cipher, operating on a 128-bit data (state) from xmm1 with a 128-bit round key from xmm2/m128.

aesdec xmm1, xmm2
aesdec xmm1, [rax]

; Perform one round of an AES decryption flow, using the Equivalent Inverse Cipher, operating on a 128-bit data (state) from xmm2 with a 128-bit round key from xmm3/m128; store the result in xmm1.
; NOTE: Also require AVX

vaesdec xmm1, xmm2
vaesdec xmm1, [rax]

; Perform the last round of an AES decryption flow, using the Equivalent Inverse Cipher, operating on a 128-bit data (state) from xmm1 with a 128-bit round key from xmm2/m128.

aesdeclast xmm1, xmm2
aesdeclast xmm1, [rax]

; Perform the last round of an AES decryption flow, using the Equivalent Inverse Cipher, operating on a 128-bit data (state) from xmm2 with a 128-bit round key from xmm3/m128; store the result in xmm1.
; NOTE: Also require AVX

vaesdeclast xmm1, xmm2
vaesdeclast xmm1, [rax]

; Perform one round of an AES encryption flow, operating on a 128-bit data (state) from xmm1 with a 128-bit round key from xmm2/m128.

aesenc xmm1, xmm2
aesenc xmm1, [rax]

; Perform one round of an AES encryption flow, operating on a 128-bit data (state) from xmm2 with a 128-bit round key from the xmm3/m128; store the result in xmm1.
; NOTE: Also require AVX

vaesenc xmm1, xmm2
vaesenc xmm1, [rax]

; Perform the last round of an AES encryption flow, operating on a 128-bit data (state) from xmm1 with a 128-bit round key from xmm2/m128.

aesenclast xmm1, xmm2
aesenclast xmm1, [rax]

; Perform the last round of an AES encryption flow, operating on a 128-bit data (state) from xmm2 with a 128 bit round key from xmm3/m128; store the result in xmm1.
; NOTE: Also require AVX

vaesenclast xmm1, xmm2
vaesenclast xmm1, [rax]

; Perform the InvMixColumn transformation on a 128-bit round key from xmm2/m128 and store the result in xmm1.

aesimc xmm1, xmm2
aesimc xmm1, [rax]

; Perform the InvMixColumn transformation on a 128-bit round key from xmm2/m128 and store the result in xmm1.
; NOTE: Also require AVX

vaesimc xmm1, xmm2
vaesimc xmm1, [rax]

; Assist in AES round key generation using an 8 bits Round Constant (RCON) specified in the immediate byte, operating on 128 bits of data specified in xmm2/m128 and stores the result in xmm1.

aeskeygenassist xmm1, xmm2, 0x69
aeskeygenassist xmm1, [rax], 0x69

; Assist in AES round key generation using 8 bits Round Constant (RCON) specified in the immediate byte, operating on 128 bits of data specified in xmm2/m128 and stores the result in xmm1.
; NOTE: Also require AVX

vaeskeygenassist xmm1, xmm2, 0x69
vaeskeygenassist xmm1, [rax], 0x69

; Carry-less multiplication of one quadword of xmm1 by one quadword of xmm2/m128, stores the 128-bit result in xmm1. The immediate is used to determine which quadwords of xmm1 and xmm2/m128 should be used.
; NOTE: Require PCLMULQDQ not AES

pclmulqdq xmm1, xmm2, 0x69
pclmulqdq xmm1, [rax], 0x69

; Carry-less multiplication of one quadword of xmm2 by one quadword of xmm3/m128, stores the 128-bit result in xmm1. The immediate is used to determine which quadwords of xmm2 and xmm3/m128 should be used.
; NOTE: Require PCLMULQDQ and AVX not AES

vpclmulqdq xmm1, xmm2, 0x69
vpclmulqdq xmm1, [rax], 0x69
