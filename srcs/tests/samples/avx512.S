
; Add packed byte integers from xmm2, and xmm3/m128 and store in xmm1 using writemask k1.

vpaddb xmm4 {k1}, xmm14, xmm1
vpaddb xmm4 {k1} {z}, xmm14, xmm1
vpaddb xmm4 {k1}, xmm14, [r12]
vpaddb xmm4 {k1} {z}, xmm14, [r12]

; Add packed word integers from xmm2, and xmm3/m128 and store in xmm1 using writemask k1.

vpaddw xmm4 {k1}, xmm14, xmm1
vpaddw xmm4 {k1} {z}, xmm14, xmm1
vpaddw xmm4 {k1}, xmm14, [r12]
vpaddw xmm4 {k1} {z}, xmm14, [r12]

; Add packed doubleword integers from xmm2, and xmm3/m128/m32bcst and store in xmm1 using writemask k1.

vpaddd xmm4 {k1}, xmm14, xmm1
vpaddd xmm4 {k1} {z}, xmm14, xmm1
vpaddd xmm4 {k1}, xmm14, [r12]
vpaddd xmm4 {k1} {z}, xmm14, [r12]

; Add packed quadword integers from xmm2, and xmm3/m128/m64bcst and store in xmm1 using writemask k1.

vpaddq xmm4 {k1}, xmm14, xmm1
vpaddq xmm4 {k1} {z}, xmm14, xmm1
vpaddq xmm4 {k1}, xmm14, [r12]
vpaddq xmm4 {k1} {z}, xmm14, [r12]

; Add packed byte integers from ymm2, and ymm3/m256 and store in ymm1 using writemask k1.

vpaddb ymm4 {k1}, ymm14, ymm1
vpaddb ymm4 {k1} {z}, ymm14, ymm1
vpaddb ymm4 {k1}, ymm14, [r12]
vpaddb ymm4 {k1} {z}, ymm14, [r12]

; Add packed word integers from ymm2, and ymm3/m256 and store in ymm1 using writemask k1.

vpaddw ymm4 {k1}, ymm14, ymm1
vpaddw ymm4 {k1} {z}, ymm14, ymm1
vpaddw ymm4 {k1}, ymm14, [r12]
vpaddw ymm4 {k1} {z}, ymm14, [r12]

; Add packed doubleword integers from ymm2, ymm3/m256/m32bcst and store in ymm1 using writemask k1.

vpaddd ymm4 {k1}, ymm14, ymm1
vpaddd ymm4 {k1} {z}, ymm14, ymm1
vpaddd ymm4 {k1}, ymm14, [r12]
vpaddd ymm4 {k1} {z}, ymm14, [r12]

; Add packed quadword integers from ymm2, ymm3/m256/m64bcst and store in ymm1 using writemask k1.

vpaddq ymm4 {k1}, ymm14, ymm1
vpaddq ymm4 {k1} {z}, ymm14, ymm1
vpaddq ymm4 {k1}, ymm14, [r12]
vpaddq ymm4 {k1} {z}, ymm14, [r12]

; Add packed byte integers from zmm2, and zmm3/m512 and store in zmm1 using writemask k1.

vpaddb zmm4 {k1}, zmm14, zmm1
vpaddb zmm4 {k1} {z}, zmm14, zmm1
vpaddb zmm4 {k1}, zmm14, [r12]
vpaddb zmm4 {k1} {z}, zmm14, [r12]

; Add packed word integers from zmm2, and zmm3/m512 and store in zmm1 using writemask k1.

vpaddw zmm4 {k1}, zmm14, zmm1
vpaddw zmm4 {k1} {z}, zmm14, zmm1
vpaddw zmm4 {k1}, zmm14, [r12]
vpaddw zmm4 {k1} {z}, zmm14, [r12]

; Add packed doubleword integers from zmm2, zmm3/m512/m32bcst and store in zmm1 using writemask k1.

vpaddd zmm4 {k1}, zmm14, zmm1
vpaddd zmm4 {k1} {z}, zmm14, zmm1
vpaddd zmm4 {k1}, zmm14, [r12]
vpaddd zmm4 {k1} {z}, zmm14, [r12]

; Add packed quadword integers from zmm2, zmm3/m512/m64bcst and store in zmm1 using writemask k1.

vpaddq zmm4 {k1}, zmm14, zmm1
vpaddq zmm4 {k1} {z}, zmm14, zmm1
vpaddq zmm4 {k1}, zmm14, [r12]
vpaddq zmm4 {k1} {z}, zmm14, [r12]

; Subtract packed byte integers in xmm3/m128 from xmm2 and store in xmm1 using writemask k1.

vpsubb xmm4 {k1}, xmm14, xmm1
vpsubb xmm4 {k1} {z}, xmm14, xmm1
vpsubb xmm4 {k1}, xmm14, [r12]
vpsubb xmm4 {k1} {z}, xmm14, [r12]

; Subtract packed byte integers in ymm3/m256 from ymm2 and store in ymm1 using writemask k1.

vpsubb ymm4 {k1}, ymm14, ymm1
vpsubb ymm4 {k1} {z}, ymm14, ymm1
vpsubb ymm4 {k1}, ymm14, [r12]
vpsubb ymm4 {k1} {z}, ymm14, [r12]

; Subtract packed byte integers in zmm3/m512 from zmm2 and store in zmm1 using writemask k1.

vpsubb zmm4 {k1}, zmm14, zmm1
vpsubb zmm4 {k1} {z}, zmm14, zmm1
vpsubb zmm4 {k1}, zmm14, [r12]
vpsubb zmm4 {k1} {z}, zmm14, [r12]

; Subtract packed word integers in xmm3/m128 from xmm2 and store in xmm1 using writemask k1.

vpsubw xmm4 {k1}, xmm14, xmm1
vpsubw xmm4 {k1} {z}, xmm14, xmm1
vpsubw xmm4 {k1}, xmm14, [r12]
vpsubw xmm4 {k1} {z}, xmm14, [r12]

; Subtract packed word integers in ymm3/m256 from ymm2 and store in ymm1 using writemask k1.

vpsubw ymm4 {k1}, ymm14, ymm1
vpsubw ymm4 {k1} {z}, ymm14, ymm1
vpsubw ymm4 {k1}, ymm14, [r12]
vpsubw ymm4 {k1} {z}, ymm14, [r12]

; Subtract packed word integers in zmm3/m512 from zmm2 and store in zmm1 using writemask k1.

vpsubw zmm4 {k1}, zmm14, zmm1
vpsubw zmm4 {k1} {z}, zmm14, zmm1
vpsubw zmm4 {k1}, zmm14, [r12]
vpsubw zmm4 {k1} {z}, zmm14, [r12]

; Subtract packed doubleword integers in xmm3/m128/m32bcst from xmm2 and store in xmm1 using writemask k1.

vpsubd xmm4 {k1}, xmm14, xmm1
vpsubd xmm4 {k1} {z}, xmm14, xmm1
vpsubd xmm4 {k1}, xmm14, [r12]
vpsubd xmm4 {k1} {z}, xmm14, [r12]

; Subtract packed doubleword integers in ymm3/m256/m32bcst from ymm2 and store in ymm1 using writemask k1.

vpsubd ymm4 {k1}, ymm14, ymm1
vpsubd ymm4 {k1} {z}, ymm14, ymm1
vpsubd ymm4 {k1}, ymm14, [r12]
vpsubd ymm4 {k1} {z}, ymm14, [r12]

; Subtract packed doubleword integers in zmm3/m512/m32bcst from zmm2 and store in zmm1 using writemask k1.

vpsubd zmm4 {k1}, zmm14, zmm1
vpsubd zmm4 {k1} {z}, zmm14, zmm1
vpsubd zmm4 {k1}, zmm14, [r12]
vpsubd zmm4 {k1} {z}, zmm14, [r12]

; Add packed signed byte integers from xmm2, and xmm3/m128 and store the saturated results in xmm1 under writemask k1.

vpaddsb xmm4 {k1}, xmm14, xmm1
vpaddsb xmm4 {k1} {z}, xmm14, xmm1
vpaddsb xmm4 {k1}, xmm14, [r12]
vpaddsb xmm4 {k1} {z}, xmm14, [r12]

; Add packed signed byte integers from ymm2, and ymm3/m256 and store the saturated results in ymm1 under writemask k1.

vpaddsb ymm4 {k1}, ymm14, ymm1
vpaddsb ymm4 {k1} {z}, ymm14, ymm1
vpaddsb ymm4 {k1}, ymm14, [r12]
vpaddsb ymm4 {k1} {z}, ymm14, [r12]

; Add packed signed byte integers from zmm2, and zmm3/m512 and store the saturated results in zmm1 under writemask k1.

vpaddsb zmm4 {k1}, zmm14, zmm1
vpaddsb zmm4 {k1} {z}, zmm14, zmm1
vpaddsb zmm4 {k1}, zmm14, [r12]
vpaddsb zmm4 {k1} {z}, zmm14, [r12]

; Add packed signed word integers from xmm2, and xmm3/m128 and store the saturated results in xmm1 under writemask k1.

vpaddsw xmm4 {k1}, xmm14, xmm1
vpaddsw xmm4 {k1} {z}, xmm14, xmm1
vpaddsw xmm4 {k1}, xmm14, [r12]
vpaddsw xmm4 {k1} {z}, xmm14, [r12]

; Add packed signed word integers from ymm2, and ymm3/m256 and store the saturated results in ymm1 under writemask k1.

vpaddsw ymm4 {k1}, ymm14, ymm1
vpaddsw ymm4 {k1} {z}, ymm14, ymm1
vpaddsw ymm4 {k1}, ymm14, [r12]
vpaddsw ymm4 {k1} {z}, ymm14, [r12]

; Add packed signed word integers from zmm2, and zmm3/m512 and store the saturated results in zmm1 under writemask k1.

vpaddsw zmm4 {k1}, zmm14, zmm1
vpaddsw zmm4 {k1} {z}, zmm14, zmm1
vpaddsw zmm4 {k1}, zmm14, [r12]
vpaddsw zmm4 {k1} {z}, zmm14, [r12]

; Subtract packed signed byte integers in xmm3/m128 from packed signed byte integers in xmm2 and saturate results and store in xmm1 using writemask k1.

vpsubsb xmm4 {k1}, xmm14, xmm1
vpsubsb xmm4 {k1} {z}, xmm14, xmm1
vpsubsb xmm4 {k1}, xmm14, [r12]
vpsubsb xmm4 {k1} {z}, xmm14, [r12]

; Subtract packed signed byte integers in ymm3/m256 from packed signed byte integers in ymm2 and saturate results and store in ymm1 using writemask k1.

vpsubsb ymm4 {k1}, ymm14, ymm1
vpsubsb ymm4 {k1} {z}, ymm14, ymm1
vpsubsb ymm4 {k1}, ymm14, [r12]
vpsubsb ymm4 {k1} {z}, ymm14, [r12]

; Subtract packed signed byte integers in zmm3/m512 from packed signed byte integers in zmm2 and saturate results and store in zmm1 using writemask k1.

vpsubsb zmm4 {k1}, zmm14, zmm1
vpsubsb zmm4 {k1} {z}, zmm14, zmm1
vpsubsb zmm4 {k1}, zmm14, [r12]
vpsubsb zmm4 {k1} {z}, zmm14, [r12]

; Subtract packed signed word integers in xmm3/m128 from packed signed word integers in xmm2 and saturate results and store in xmm1 using writemask k1.

vpsubsw xmm4 {k1}, xmm14, xmm1
vpsubsw xmm4 {k1} {z}, xmm14, xmm1
vpsubsw xmm4 {k1}, xmm14, [r12]
vpsubsw xmm4 {k1} {z}, xmm14, [r12]

; Subtract packed signed word integers in ymm3/m256 from packed signed word integers in ymm2 and saturate results and store in ymm1 using writemask k1.

vpsubsw ymm4 {k1}, ymm14, ymm1
vpsubsw ymm4 {k1} {z}, ymm14, ymm1
vpsubsw ymm4 {k1}, ymm14, [r12]
vpsubsw ymm4 {k1} {z}, ymm14, [r12]

; Subtract packed signed word integers in zmm3/m512 from packed signed word integers in zmm2 and saturate results and store in zmm1 using writemask k1.

vpsubsw zmm4 {k1}, zmm14, zmm1
vpsubsw zmm4 {k1} {z}, zmm14, zmm1
vpsubsw zmm4 {k1}, zmm14, [r12]
vpsubsw zmm4 {k1} {z}, zmm14, [r12]

; Add packed unsigned byte integers from xmm2, and xmm3/m128 and store the saturated results in xmm1 under writemask k1.

vpaddusb xmm4 {k1}, xmm14, xmm1
vpaddusb xmm4 {k1} {z}, xmm14, xmm1
vpaddusb xmm4 {k1}, xmm14, [r12]
vpaddusb xmm4 {k1} {z}, xmm14, [r12]

; Add packed unsigned byte integers from ymm2, and ymm3/m256 and store the saturated results in ymm1 under writemask k1.

vpaddusb ymm4 {k1}, ymm14, ymm1
vpaddusb ymm4 {k1} {z}, ymm14, ymm1
vpaddusb ymm4 {k1}, ymm14, [r12]
vpaddusb ymm4 {k1} {z}, ymm14, [r12]

; Add packed unsigned byte integers from zmm2, and zmm3/m512 and store the saturated results in zmm1 under writemask k1.

vpaddusb zmm4 {k1}, zmm14, zmm1
vpaddusb zmm4 {k1} {z}, zmm14, zmm1
vpaddusb zmm4 {k1}, zmm14, [r12]
vpaddusb zmm4 {k1} {z}, zmm14, [r12]

; Add packed unsigned word integers from xmm2, and xmm3/m128 and store the saturated results in xmm1 under writemask k1.

vpaddusw xmm4 {k1}, xmm14, xmm1
vpaddusw xmm4 {k1} {z}, xmm14, xmm1
vpaddusw xmm4 {k1}, xmm14, [r12]
vpaddusw xmm4 {k1} {z}, xmm14, [r12]

; Add packed unsigned word integers from ymm2, and ymm3/m256 and store the saturated results in ymm1 under writemask k1.

vpaddsw ymm4 {k1}, ymm14, ymm1
vpaddsw ymm4 {k1} {z}, ymm14, ymm1
vpaddsw ymm4 {k1}, ymm14, [r12]
vpaddsw ymm4 {k1} {z}, ymm14, [r12]

; Add packed unsigned word integers from zmm2, and zmm3/m512 and store the saturated results in zmm1 under writemask k1.

vpaddusw zmm4 {k1}, zmm14, zmm1
vpaddusw zmm4 {k1} {z}, zmm14, zmm1
vpaddusw zmm4 {k1}, zmm14, [r12]
vpaddusw zmm4 {k1} {z}, zmm14, [r12]

; Subtract packed unsigned byte integers in xmm3/m128 from packed unsigned byte integers in xmm2, saturate results and store in xmm1 using writemask k1.

vpsubusb xmm4 {k1}, xmm14, xmm1
vpsubusb xmm4 {k1} {z}, xmm14, xmm1
vpsubusb xmm4 {k1}, xmm14, [r12]
vpsubusb xmm4 {k1} {z}, xmm14, [r12]

; Subtract packed unsigned byte integers in ymm3/m256 from packed unsigned byte integers in ymm2, saturate results and store in ymm1 using writemask k1.

vpsubusb ymm4 {k1}, ymm14, ymm1
vpsubusb ymm4 {k1} {z}, ymm14, ymm1
vpsubusb ymm4 {k1}, ymm14, [r12]
vpsubusb ymm4 {k1} {z}, ymm14, [r12]

; Subtract packed unsigned byte integers in zmm3/m512 from packed unsigned byte integers in zmm2, saturate results and store in zmm1 using writemask k1.

vpsubusb zmm4 {k1}, zmm14, zmm1
vpsubusb zmm4 {k1} {z}, zmm14, zmm1
vpsubusb zmm4 {k1}, zmm14, [r12]
vpsubusb zmm4 {k1} {z}, zmm14, [r12]

; Subtract packed unsigned word integers in xmm3/m128 from packed unsigned word integers in xmm2 and saturate results and store in xmm1 using writemask k1.

vpsubusw xmm4 {k1}, xmm14, xmm1
vpsubusw xmm4 {k1} {z}, xmm14, xmm1
vpsubusw xmm4 {k1}, xmm14, [r12]
vpsubusw xmm4 {k1} {z}, xmm14, [r12]

; Subtract packed unsigned word integers in ymm3/m256 from packed unsigned word integers in ymm2, saturate results and store in ymm1 using writemask k1.

vpsubusw ymm4 {k1}, ymm14, ymm1
vpsubusw ymm4 {k1} {z}, ymm14, ymm1
vpsubusw ymm4 {k1}, ymm14, [r12]
vpsubusw ymm4 {k1} {z}, ymm14, [r12]

; Subtract packed unsigned word integers in zmm3/m512 from packed unsigned word integers in zmm2, saturate results and store in zmm1 using writemask k1.

vpsubusw zmm4 {k1}, zmm14, zmm1
vpsubusw zmm4 {k1} {z}, zmm14, zmm1
vpsubusw zmm4 {k1}, zmm14, [r12]
vpsubusw zmm4 {k1} {z}, zmm14, [r12]

; Compare packed bytes in xmm3/m128 and xmm2 for equality and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.

vpcmpeqb k1 {k2}, xmm4, xmm8
vpcmpeqb k1, xmm4, xmm8
vpcmpeqb k1 {k2}, xmm4, [rsi]
vpcmpeqb k1, xmm4, [rsi]

; Compare packed bytes in ymm3/m256 and ymm2 for equality and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.

vpcmpeqb k1 {k2}, ymm4, ymm8
vpcmpeqb k1, ymm4, ymm8
vpcmpeqb k1 {k2}, ymm4, [rsi]
vpcmpeqb k1, ymm4, [rsi]

; Compare packed bytes in zmm3/m512 and zmm2 for equality and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.

vpcmpeqb k1 {k2}, zmm4, zmm8
vpcmpeqb k1, zmm4, zmm8
vpcmpeqb k1 {k2}, zmm4, [rsi]
vpcmpeqb k1, zmm4, [rsi]

; Compare packed words in xmm3/m128 and xmm2 for equality and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.

vpcmpeqw k1 {k2}, xmm4, xmm8
vpcmpeqw k1, xmm4, xmm8
vpcmpeqw k1 {k2}, xmm4, [rsi]
vpcmpeqw k1, xmm4, [rsi]

; Compare packed words in ymm3/m256 and ymm2 for equality and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.

vpcmpeqw k1 {k2}, ymm4, ymm8
vpcmpeqw k1, ymm4, ymm8
vpcmpeqw k1 {k2}, ymm4, [rsi]
vpcmpeqw k1, ymm4, [rsi]

; Compare packed words in zmm3/m512 and zmm2 for equality and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.

vpcmpeqw k1 {k2}, zmm4, zmm8
vpcmpeqw k1, zmm4, zmm8
vpcmpeqw k1 {k2}, zmm4, [rsi]
vpcmpeqw k1, zmm4, [rsi]

; Compare Equal between int32 vector xmm2 and int32 vector xmm3/m128/m32bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.

vpcmpeqd k1 {k2}, xmm4, xmm8
vpcmpeqd k1, xmm4, xmm8
vpcmpeqd k1 {k2}, xmm4, [rsi]
vpcmpeqd k1, xmm4, [rsi]

; Compare Equal between int32 vector ymm2 and int32 vector ymm3/m256/m32bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.

vpcmpeqd k1 {k2}, ymm4, ymm8
vpcmpeqd k1, ymm4, ymm8
vpcmpeqd k1 {k2}, ymm4, [rsi]
vpcmpeqd k1, ymm4, [rsi]

; Compare Equal between int32 vectors in zmm2 and zmm3/m512/m32bcst, and set destination k1 according to the comparison results under writemask k2.

vpcmpeqd k1 {k2}, zmm4, zmm8
vpcmpeqd k1, zmm4, zmm8
vpcmpeqd k1 {k2}, zmm4, [rsi]
vpcmpeqd k1, zmm4, [rsi]

; TODO HERE:: VPCMPGTPB

; Converts packed signed word integers from xmm2 and from xmm3/m128 into packed signed byte integers in xmm1 using signed saturation under writemask k1.

vpacksswb xmm4 {k1}, xmm14, xmm1
vpacksswb xmm4 {k1} {z}, xmm14, xmm1
vpacksswb xmm4 {k1}, xmm14, [r12]
vpacksswb xmm4 {k1} {z}, xmm14, [r12]

; Converts packed signed word integers from ymm2 and from ymm3/m256 into packed signed byte integers in ymm1 using signed saturation under writemask k1.

vpacksswb ymm4 {k1}, ymm14, ymm1
vpacksswb ymm4 {k1} {z}, ymm14, ymm1
vpacksswb ymm4 {k1}, ymm14, [r12]
vpacksswb ymm4 {k1} {z}, ymm14, [r12]

; Converts packed signed word integers from zmm2 and from zmm3/m512 into packed signed byte integers in zmm1 using signed saturation under writemask k1.

vpacksswb zmm4 {k1}, zmm14, zmm1
vpacksswb zmm4 {k1} {z}, zmm14, zmm1
vpacksswb zmm4 {k1}, zmm14, [r12]
vpacksswb zmm4 {k1} {z}, zmm14, [r12]

; Converts packed signed doubleword integers from xmm2 and from xmm3/m128/m32bcst into packed signed word integers in xmm1 using signed saturation under writemask k1.

vpackssdw xmm4 {k1}, xmm14, xmm1
vpackssdw xmm4 {k1} {z}, xmm14, xmm1
vpackssdw xmm4 {k1}, xmm14, [r12]
vpackssdw xmm4 {k1} {z}, xmm14, [r12]

; Converts packed signed doubleword integers from ymm2 and from ymm3/m256/m32bcst into packed signed word integers in ymm1 using signed saturation under writemask k1.

vpackssdw ymm4 {k1}, ymm14, ymm1
vpackssdw ymm4 {k1} {z}, ymm14, ymm1
vpackssdw ymm4 {k1}, ymm14, [r12]
vpackssdw ymm4 {k1} {z}, ymm14, [r12]

; Converts packed signed doubleword integers from zmm2 and from zmm3/m512/m32bcst into packed signed word integers in zmm1 using signed saturation under writemask k1.

vpackssdw zmm4 {k1}, zmm14, zmm1
vpackssdw zmm4 {k1} {z}, zmm14, zmm1
vpackssdw zmm4 {k1}, zmm14, [r12]
vpackssdw zmm4 {k1} {z}, zmm14, [r12]

; Converts signed word integers from xmm2 and signed word integers from xmm3/m128 into unsigned byte integers in xmm1 using unsigned saturation under writemask k1.

vpackuswb xmm4 {k1}, xmm14, xmm1
vpackuswb xmm4 {k1} {z}, xmm14, xmm1
vpackuswb xmm4 {k1}, xmm14, [r12]
vpackuswb xmm4 {k1} {z}, xmm14, [r12]

; Converts signed word integers from ymm2 and signed word integers from ymm3/m256 into unsigned byte integers in ymm1 using unsigned saturation under writemask k1.

vpackuswb ymm4 {k1}, ymm14, ymm1
vpackuswb ymm4 {k1} {z}, ymm14, ymm1
vpackuswb ymm4 {k1}, ymm14, [r12]
vpackuswb ymm4 {k1} {z}, ymm14, [r12]

; Converts signed word integers from zmm2 and signed word integers from zmm3/m512 into unsigned byte integers in zmm1 using unsigned saturation under writemask k1.

vpackuswb zmm4 {k1}, zmm14, zmm1
vpackuswb zmm4 {k1} {z}, zmm14, zmm1
vpackuswb zmm4 {k1}, zmm14, [r12]
vpackuswb zmm4 {k1} {z}, zmm14, [r12]

; Interleave high-order bytes from xmm2 and xmm3/m128 into xmm1 register using k1 write mask.

vpunpckhbw xmm4 {k1}, xmm14, xmm1
vpunpckhbw xmm4 {k1} {z}, xmm14, xmm1
vpunpckhbw xmm4 {k1}, xmm14, [r12]
vpunpckhbw xmm4 {k1} {z}, xmm14, [r12]

; Interleave high-order words from xmm2 and xmm3/m128 into xmm1 register using k1 write mask.

vpunpckhwd xmm4 {k1}, xmm14, xmm1
vpunpckhwd xmm4 {k1} {z}, xmm14, xmm1
vpunpckhwd xmm4 {k1}, xmm14, [r12]
vpunpckhwd xmm4 {k1} {z}, xmm14, [r12]

; Interleave high-order doublewords from xmm2 and xmm3/m128/m32bcst into xmm1 register using k1 write mask.

vpunpckhdq xmm4 {k1}, xmm14, xmm1
vpunpckhdq xmm4 {k1} {z}, xmm14, xmm1
vpunpckhdq xmm4 {k1}, xmm14, [r12]
vpunpckhdq xmm4 {k1} {z}, xmm14, [r12]

; Interleave high-order quadword from xmm2 and xmm3/m128/m64bcst into xmm1 register using k1 write mask.

vpunpckhqdq xmm4 {k1}, xmm14, xmm1
vpunpckhqdq xmm4 {k1} {z}, xmm14, xmm1
vpunpckhqdq xmm4 {k1}, xmm14, [r12]
vpunpckhqdq xmm4 {k1} {z}, xmm14, [r12]

; Interleave high-order bytes from ymm2 and ymm3/m256 into ymm1 register using k1 write mask.

vpunpckhbw ymm4 {k1}, ymm14, ymm1
vpunpckhbw ymm4 {k1} {z}, ymm14, ymm1
vpunpckhbw ymm4 {k1}, ymm14, [r12]
vpunpckhbw ymm4 {k1} {z}, ymm14, [r12]

; Interleave high-order words from ymm2 and ymm3/m256 into ymm1 register using k1 write mask.

vpunpckhwd ymm4 {k1}, ymm14, ymm1
vpunpckhwd ymm4 {k1} {z}, ymm14, ymm1
vpunpckhwd ymm4 {k1}, ymm14, [r12]
vpunpckhwd ymm4 {k1} {z}, ymm14, [r12]

; Interleave high-order doublewords from ymm2 and ymm3/m256/m32bcst into ymm1 register using k1 write mask.

vpunpckhdq ymm4 {k1}, ymm14, ymm1
vpunpckhdq ymm4 {k1} {z}, ymm14, ymm1
vpunpckhdq ymm4 {k1}, ymm14, [r12]
vpunpckhdq ymm4 {k1} {z}, ymm14, [r12]

; Interleave high-order quadword from ymm2 and ymm3/m256/m64bcst into ymm1 register using k1 write mask.

vpunpckhqdq ymm4 {k1}, ymm14, ymm1
vpunpckhqdq ymm4 {k1} {z}, ymm14, ymm1
vpunpckhqdq ymm4 {k1}, ymm14, [r12]
vpunpckhqdq ymm4 {k1} {z}, ymm14, [r12]

; Interleave high-order bytes from zmm2 and zmm3/m512 into zmm1 register.

vpunpckhbw zmm4 {k1}, zmm14, zmm1
vpunpckhbw zmm4 {k1} {z}, zmm14, zmm1
vpunpckhbw zmm4 {k1}, zmm14, [r12]
vpunpckhbw zmm4 {k1} {z}, zmm14, [r12]

; Interleave high-order words from zmm2 and zmm3/m512 into zmm1 register.

vpunpckhwd zmm4 {k1}, zmm14, zmm1
vpunpckhwd zmm4 {k1} {z}, zmm14, zmm1
vpunpckhwd zmm4 {k1}, zmm14, [r12]
vpunpckhwd zmm4 {k1} {z}, zmm14, [r12]

; Interleave high-order doublewords from zmm2 and zmm3/m512/m32bcst into zmm1 register using k1 write mask.

vpunpckhdq zmm4 {k1}, zmm14, zmm1
vpunpckhdq zmm4 {k1} {z}, zmm14, zmm1
vpunpckhdq zmm4 {k1}, zmm14, [r12]
vpunpckhdq zmm4 {k1} {z}, zmm14, [r12]

; Interleave high-order quadword from zmm2 and zmm3/m512/m64bcst into zmm1 register using k1 write mask.

vpunpckhqdq zmm4 {k1}, zmm14, zmm1
vpunpckhqdq zmm4 {k1} {z}, zmm14, zmm1
vpunpckhqdq zmm4 {k1}, zmm14, [r12]
vpunpckhqdq zmm4 {k1} {z}, zmm14, [r12]

; Interleave low-order bytes from xmm2 and xmm3/m128 into xmm1 register using k1 write mask.

vpunpcklbw xmm4 {k1}, xmm14, xmm1
vpunpcklbw xmm4 {k1} {z}, xmm14, xmm1
vpunpcklbw xmm4 {k1}, xmm14, [r12]
vpunpcklbw xmm4 {k1} {z}, xmm14, [r12]

; Interleave low-order words from xmm2 and xmm3/m128 into xmm1 register using k1 write mask.

vpunpcklwd xmm4 {k1}, xmm14, xmm1
vpunpcklwd xmm4 {k1} {z}, xmm14, xmm1
vpunpcklwd xmm4 {k1}, xmm14, [r12]
vpunpcklwd xmm4 {k1} {z}, xmm14, [r12]

; Interleave low-order doublewords from xmm2 and xmm3/m128/m32bcst into xmm1 register using k1 write mask.

vpunpckldq xmm4 {k1}, xmm14, xmm1
vpunpckldq xmm4 {k1} {z}, xmm14, xmm1
vpunpckldq xmm4 {k1}, xmm14, [r12]
vpunpckldq xmm4 {k1} {z}, xmm14, [r12]

; Interleave low-order quadword from xmm2 and xmm3/m128/m64bcst into xmm1 register using k1 write mask.

vpunpcklqdq xmm4 {k1}, xmm14, xmm1
vpunpcklqdq xmm4 {k1} {z}, xmm14, xmm1
vpunpcklqdq xmm4 {k1}, xmm14, [r12]
vpunpcklqdq xmm4 {k1} {z}, xmm14, [r12]

; Interleave low-order bytes from ymm2 and ymm3/m256 into ymm1 register using k1 write mask.

vpunpcklbw ymm4 {k1}, ymm14, ymm1
vpunpcklbw ymm4 {k1} {z}, ymm14, ymm1
vpunpcklbw ymm4 {k1}, ymm14, [r12]
vpunpcklbw ymm4 {k1} {z}, ymm14, [r12]

; Interleave low-order words from ymm2 and ymm3/m256 into ymm1 register using k1 write mask.

vpunpcklwd ymm4 {k1}, ymm14, ymm1
vpunpcklwd ymm4 {k1} {z}, ymm14, ymm1
vpunpcklwd ymm4 {k1}, ymm14, [r12]
vpunpcklwd ymm4 {k1} {z}, ymm14, [r12]

; Interleave low-order doublewords from ymm2 and ymm3/m256/m32bcst into ymm1 register using k1 write mask.

vpunpckldq ymm4 {k1}, ymm14, ymm1
vpunpckldq ymm4 {k1} {z}, ymm14, ymm1
vpunpckldq ymm4 {k1}, ymm14, [r12]
vpunpckldq ymm4 {k1} {z}, ymm14, [r12]

; Interleave low-order quadword from ymm2 and ymm3/m256/m64bcst into ymm1 register using k1 write mask.

vpunpcklqdq ymm4 {k1}, ymm14, ymm1
vpunpcklqdq ymm4 {k1} {z}, ymm14, ymm1
vpunpcklqdq ymm4 {k1}, ymm14, [r12]
vpunpcklqdq ymm4 {k1} {z}, ymm14, [r12]

; Interleave low-order bytes from zmm2 and zmm3/m512 into zmm1 register.

vpunpcklbw zmm4 {k1}, zmm14, zmm1
vpunpcklbw zmm4 {k1} {z}, zmm14, zmm1
vpunpcklbw zmm4 {k1}, zmm14, [r12]
vpunpcklbw zmm4 {k1} {z}, zmm14, [r12]

; Interleave low-order words from zmm2 and zmm3/m512 into zmm1 register.

vpunpcklwd zmm4 {k1}, zmm14, zmm1
vpunpcklwd zmm4 {k1} {z}, zmm14, zmm1
vpunpcklwd zmm4 {k1}, zmm14, [r12]
vpunpcklwd zmm4 {k1} {z}, zmm14, [r12]

; Interleave low-order doublewords from zmm2 and zmm3/m512/m32bcst into zmm1 register using k1 write mask.

vpunpckldq zmm4 {k1}, zmm14, zmm1
vpunpckldq zmm4 {k1} {z}, zmm14, zmm1
vpunpckldq zmm4 {k1}, zmm14, [r12]
vpunpckldq zmm4 {k1} {z}, zmm14, [r12]

; Interleave low-order quadword from zmm2 and zmm3/m512/m64bcst into zmm1 register using k1 write mask.

vpunpcklqdq zmm4 {k1}, zmm14, zmm1
vpunpcklqdq zmm4 {k1} {z}, zmm14, zmm1
vpunpcklqdq zmm4 {k1}, zmm14, [r12]
vpunpcklqdq zmm4 {k1} {z}, zmm14, [r12]

; Bitwise AND of packed doubleword integers in xmm2 and xmm3/m128/m32bcst and store result in xmm1 using writemask k1.

vpandd xmm1 {k1}, xmm3, xmm5
vpandd xmm1 {k1} {z}, xmm3, xmm5
vpandd xmm1 {k1}, xmm3, [rdi]
vpandd xmm1 {k1} {z}, xmm3, [rdi]

; Bitwise AND of packed doubleword integers in ymm2 and ymm3/m256/m32bcst and store result in ymm1 using writemask k1.

vpandd ymm1 {k1}, ymm3, ymm5
vpandd ymm1 {k1} {z}, ymm3, ymm5
vpandd ymm1 {k1}, ymm3, [rdi]
vpandd ymm1 {k1} {z}, ymm3, [rdi]

; Bitwise AND of packed doubleword integers in zmm2 and zmm3/m512/m32bcst and store result in zmm1 using writemask k1.

vpandd zmm1 {k1}, zmm3, zmm5
vpandd zmm1 {k1} {z}, zmm3, zmm5
vpandd zmm1 {k1}, zmm3, [rdi]
vpandd zmm1 {k1} {z}, zmm3, [rdi]

; Bitwise AND of packed quadword integers in xmm2 and xmm3/m128/m64bcst and store result in xmm1 using writemask k1.

vpandq xmm1 {k1}, xmm3, xmm5
vpandq xmm1 {k1} {z}, xmm3, xmm5
vpandq xmm1 {k1}, xmm3, [rdi]
vpandq xmm1 {k1} {z}, xmm3, [rdi]

; Bitwise AND of packed quadword integers in ymm2 and ymm3/m256/m64bcst and store result in ymm1 using writemask k1.

vpandq ymm1 {k1}, ymm3, ymm5
vpandq ymm1 {k1} {z}, ymm3, ymm5
vpandq ymm1 {k1}, ymm3, [rdi]
vpandq ymm1 {k1} {z}, ymm3, [rdi]

; Bitwise AND of packed quadword integers in zmm2 and zmm3/m512/m64bcst and store result in zmm1 using writemask k1.

vpandq zmm1 {k1}, zmm3, zmm5
vpandq zmm1 {k1} {z}, zmm3, zmm5
vpandq zmm1 {k1}, zmm3, [rdi]
vpandq zmm1 {k1} {z}, zmm3, [rdi]

; Bitwise AND NOT of packed doubleword integers in xmm2 and xmm3/m128/m32bcst and store result in xmm1 using writemask k1.

vpandnd xmm1 {k1}, xmm3, xmm5
vpandnd xmm1 {k1} {z}, xmm3, xmm5
vpandnd xmm1 {k1}, xmm3, [rdi]
vpandnd xmm1 {k1} {z}, xmm3, [rdi]

; Bitwise AND NOT of packed doubleword integers in ymm2 and ymm3/m256/m32bcst and store result in ymm1 using writemask k1.

vpandnd ymm1 {k1}, ymm3, ymm5
vpandnd ymm1 {k1} {z}, ymm3, ymm5
vpandnd ymm1 {k1}, ymm3, [rdi]
vpandnd ymm1 {k1} {z}, ymm3, [rdi]

; Bitwise AND NOT of packed doubleword integers in zmm2 and zmm3/m512/m32bcst and store result in zmm1 using writemask k1.

vpandnd zmm1 {k1}, zmm3, zmm5
vpandnd zmm1 {k1} {z}, zmm3, zmm5
vpandnd zmm1 {k1}, zmm3, [rdi]
vpandnd zmm1 {k1} {z}, zmm3, [rdi]

; Bitwise AND NOT of packed quadword integers in xmm2 and xmm3/m128/m64bcst and store result in xmm1 using writemask k1.

vpandnq xmm1 {k1}, xmm3, xmm5
vpandnq xmm1 {k1} {z}, xmm3, xmm5
vpandnq xmm1 {k1}, xmm3, [rdi]
vpandnq xmm1 {k1} {z}, xmm3, [rdi]

; Bitwise AND NOT of packed quadword integers in ymm2 and ymm3/m256/m64bcst and store result in ymm1 using writemask k1.

vpandnq ymm1 {k1}, ymm3, ymm5
vpandnq ymm1 {k1} {z}, ymm3, ymm5
vpandnq ymm1 {k1}, ymm3, [rdi]
vpandnq ymm1 {k1} {z}, ymm3, [rdi]

; Bitwise AND NOT of packed quadword integers in zmm2 and zmm3/m512/m64bcst and store result in zmm1 using writemask k1.

vpandnq zmm1 {k1}, zmm3, zmm5
vpandnq zmm1 {k1} {z}, zmm3, zmm5
vpandnq zmm1 {k1}, zmm3, [rdi]
vpandnq zmm1 {k1} {z}, zmm3, [rdi]

; Bitwise OR of packed doubleword integers in xmm2 and xmm3/m128/m32bcst and store result in xmm1 using writemask k1.

vpord xmm1 {k1}, xmm3, xmm5
vpord xmm1 {k1} {z}, xmm3, xmm5
vpord xmm1 {k1}, xmm3, [rdi]
vpord xmm1 {k1} {z}, xmm3, [rdi]

; Bitwise OR of packed doubleword integers in ymm2 and ymm3/m256/m32bcst and store result in ymm1 using writemask k1.

vpord ymm1 {k1}, ymm3, ymm5
vpord ymm1 {k1} {z}, ymm3, ymm5
vpord ymm1 {k1}, ymm3, [rdi]
vpord ymm1 {k1} {z}, ymm3, [rdi]

; Bitwise OR of packed doubleword integers in zmm2 and zmm3/m512/m32bcst and store result in zmm1 using writemask k1.

vpord zmm1 {k1}, zmm3, zmm5
vpord zmm1 {k1} {z}, zmm3, zmm5
vpord zmm1 {k1}, zmm3, [rdi]
vpord zmm1 {k1} {z}, zmm3, [rdi]

; Bitwise OR of packed quadword integers in xmm2 and xmm3/m128/m64bcst and store result in xmm1 using writemask k1.

vporq xmm1 {k1}, xmm3, xmm5
vporq xmm1 {k1} {z}, xmm3, xmm5
vporq xmm1 {k1}, xmm3, [rdi]
vporq xmm1 {k1} {z}, xmm3, [rdi]

; Bitwise OR of packed quadword integers in ymm2 and ymm3/m256/m64bcst and store result in ymm1 using writemask k1.

vporq ymm1 {k1}, ymm3, ymm5
vporq ymm1 {k1} {z}, ymm3, ymm5
vporq ymm1 {k1}, ymm3, [rdi]
vporq ymm1 {k1} {z}, ymm3, [rdi]

; Bitwise OR of packed quadword integers in zmm2 and zmm3/m512/m64bcst and store result in zmm1 using writemask k1.

vporq zmm1 {k1}, zmm3, zmm5
vporq zmm1 {k1} {z}, zmm3, zmm5
vporq zmm1 {k1}, zmm3, [rdi]
vporq zmm1 {k1} {z}, zmm3, [rdi]

; Bitwise XOR of packed doubleword integers in xmm2 and xmm3/m128/m32bcst and store result in xmm1 using writemask k1.

vpxord xmm1 {k1}, xmm3, xmm5
vpxord xmm1 {k1} {z}, xmm3, xmm5
vpxord xmm1 {k1}, xmm3, [rdi]
vpxord xmm1 {k1} {z}, xmm3, [rdi]

; Bitwise XOR of packed doubleword integers in ymm2 and ymm3/m256/m32bcst and store result in ymm1 using writemask k1.

vpxord ymm1 {k1}, ymm3, ymm5
vpxord ymm1 {k1} {z}, ymm3, ymm5
vpxord ymm1 {k1}, ymm3, [rdi]
vpxord ymm1 {k1} {z}, ymm3, [rdi]

; Bitwise XOR of packed doubleword integers in zmm2 and zmm3/m512/m32bcst and store result in zmm1 using writemask k1.

vpxord zmm1 {k1}, zmm3, zmm5
vpxord zmm1 {k1} {z}, zmm3, zmm5
vpxord zmm1 {k1}, zmm3, [rdi]
vpxord zmm1 {k1} {z}, zmm3, [rdi]

; Bitwise XOR of packed quadword integers in xmm2 and xmm3/m128/m64bcst and store result in xmm1 using writemask k1.

vpxorq xmm1 {k1}, xmm3, xmm5
vpxorq xmm1 {k1} {z}, xmm3, xmm5
vpxorq xmm1 {k1}, xmm3, [rdi]
vpxorq xmm1 {k1} {z}, xmm3, [rdi]

; Bitwise XOR of packed quadword integers in ymm2 and ymm3/m256/m64bcst and store result in ymm1 using writemask k1.

vpxorq ymm1 {k1}, ymm3, ymm5
vpxorq ymm1 {k1} {z}, ymm3, ymm5
vpxorq ymm1 {k1}, ymm3, [rdi]
vpxorq ymm1 {k1} {z}, ymm3, [rdi]

; Bitwise XOR of packed quadword integers in zmm2 and zmm3/m512/m64bcst and store result in zmm1 using writemask k1.

vpxorq zmm1 {k1}, zmm3, zmm5
vpxorq zmm1 {k1} {z}, zmm3, zmm5
vpxorq zmm1 {k1}, zmm3, [rdi]
vpxorq zmm1 {k1} {z}, zmm3, [rdi]

; Shift words in xmm2 left by amount specified in xmm3/m128 while shifting in 0s using writemask k1.

vpsllw xmm1 {k1}, xmm7, xmm11
vpsllw xmm1 {k1} {z}, xmm7, xmm11
vpsllw xmm1 {k1}, xmm7, [rdi]
vpsllw xmm1 {k1} {z}, xmm7, [rdi]

; Shift words in ymm2 left by amount specified in xmm3/m128 while shifting in 0s using writemask k1.

vpsllw ymm1 {k1}, ymm7, xmm11
vpsllw ymm1 {k1} {z}, ymm7, xmm11
vpsllw ymm1 {k1}, ymm7, [rdi]
vpsllw ymm1 {k1} {z}, ymm7, [rdi]

; Shift words in zmm2 left by amount specified in xmm3/m128 while shifting in 0s using writemask k1.

vpsllw zmm1 {k1}, zmm7, xmm11
vpsllw zmm1 {k1} {z}, zmm7, xmm11
vpsllw zmm1 {k1}, zmm7, [rdi]
vpsllw zmm1 {k1} {z}, zmm7, [rdi]

; Shift words in xmm2/m128 left by imm8 while shifting in 0s using writemask k1.

vpsllw xmm6 {k1} {z}, xmm9, 0x69
vpsllw xmm6 {k1} {z}, [rax], 0x69

; Shift words in ymm2/m256 left by imm8 while shifting in 0s using writemask k1.

vpsllw ymm6 {k1} {z}, ymm9, 0x69
vpsllw ymm6 {k1} {z}, [rax], 0x69

; Shift words in zmm2/m512 left by imm8 while shifting in 0 using writemask k1.

vpsllw zmm6 {k1} {z}, zmm9, 0x69
vpsllw zmm6 {k1} {z}, [rax], 0x69

; Shift doublewords in xmm2 left by amount specified in xmm3/m128 while shifting in 0s under writemask k1.

vpslld xmm1 {k1}, xmm7, xmm11
vpslld xmm1 {k1} {z}, xmm7, xmm11
vpslld xmm1 {k1}, xmm7, [rdi]
vpslld xmm1 {k1} {z}, xmm7, [rdi]

; Shift doublewords in ymm2 left by amount specified in xmm3/m128 while shifting in 0s under writemask k1.

vpslld ymm1 {k1}, ymm7, xmm11
vpslld ymm1 {k1} {z}, ymm7, xmm11
vpslld ymm1 {k1}, ymm7, [rdi]
vpslld ymm1 {k1} {z}, ymm7, [rdi]

; Shift doublewords in zmm2 left by amount specified in xmm3/m128 while shifting in 0s under writemask k1.

vpslld zmm1 {k1}, zmm7, xmm11
vpslld zmm1 {k1} {z}, zmm7, xmm11
vpslld zmm1 {k1}, zmm7, [rdi]
vpslld zmm1 {k1} {z}, zmm7, [rdi]

; Shift doublewords in xmm2/m128/m32bcst left by imm8 while shifting in 0s using writemask k1.
; TODO: WHAT IS A 'm32bcst' (possible 2nd argument option) ?

vpslld xmm6 {k1} {z}, xmm9, 0x69
vpslld xmm6 {k1} {z}, [rax], 0x69

; Shift doublewords in ymm2/m256/m32bcst left by imm8 while shifting in 0s using writemask k1.
; TODO: WHAT IS A 'm32bcst' (possible 2nd argument option) ?

vpslld ymm6 {k1} {z}, ymm9, 0x69
vpslld ymm6 {k1} {z}, [rax], 0x69

; Shift doublewords in zmm2/m512/m32bcst left by imm8 while shifting in 0s using writemask k1.

vpslld zmm6 {k1} {z}, zmm9, 0x69
vpslld zmm6 {k1} {z}, [rax], 0x69

; Shift quadwords in xmm2 left by amount specified in xmm3/m128 while shifting in 0s using writemask k1.

vpsllq xmm1 {k1}, xmm7, xmm11
vpsllq xmm1 {k1} {z}, xmm7, xmm11
vpsllq xmm1 {k1}, xmm7, [rdi]
vpsllq xmm1 {k1} {z}, xmm7, [rdi]

; Shift quadwords in ymm2 left by amount specified in xmm3/m128 while shifting in 0s using writemask k1.

vpsllq ymm1 {k1}, ymm7, xmm11
vpsllq ymm1 {k1} {z}, ymm7, xmm11
vpsllq ymm1 {k1}, ymm7, [rdi]
vpsllq ymm1 {k1} {z}, ymm7, [rdi]

; Shift quadwords in zmm2 left by amount specified in xmm3/m128 while shifting in 0s using writemask k1.

vpsllq zmm1 {k1}, zmm7, xmm11
vpsllq zmm1 {k1} {z}, zmm7, xmm11
vpsllq zmm1 {k1}, zmm7, [rdi]
vpsllq zmm1 {k1} {z}, zmm7, [rdi]

; Shift quadwords in xmm2/m128/m64bcst left by imm8 while shifting in 0s using writemask k1.
; TODO: WHAT IS A 'm64bcst' (possible 2nd argument option) ?

vpsllq xmm6 {k1} {z}, xmm9, 0x69
vpsllq xmm6 {k1} {z}, [rax], 0x69

; Shift quadwords in ymm2/m256/m64bcst left by imm8 while shifting in 0s using writemask k1.
; TODO: WHAT IS A 'm64bcst' (possible 2nd argument option) ?

vpsllq ymm6 {k1} {z}, ymm9, 0x69
vpsllq ymm6 {k1} {z}, [rax], 0x69

;  	Shift quadwords in zmm2/m512/m64bcst left by imm8 while shifting in 0s using writemask k1.
; TODO: WHAT IS A 'm64bcst' (possible 2nd argument option) ?

vpsllq zmm6 {k1} {z}, zmm9, 0x69
vpsllq zmm6 {k1} {z}, [rax], 0x69

; Shift words in xmm2 right by amount specified in xmm3/m128 while shifting in 0s using writemask k1.

vpsrlw xmm1 {k1}, xmm7, xmm11
vpsrlw xmm1 {k1} {z}, xmm7, xmm11
vpsrlw xmm1 {k1}, xmm7, [rdi]
vpsrlw xmm1 {k1} {z}, xmm7, [rdi]

; Shift words in ymm2 right by amount specified in xmm3/m128 while shifting in 0s using writemask k1.

vpsrlw ymm1 {k1}, ymm7, xmm11
vpsrlw ymm1 {k1} {z}, ymm7, xmm11
vpsrlw ymm1 {k1}, ymm7, [rdi]
vpsrlw ymm1 {k1} {z}, ymm7, [rdi]

; Shift words in zmm2 right by amount specified in xmm3/m128 while shifting in 0s using writemask k1.

vpsrlw zmm1 {k1}, zmm7, xmm11
vpsrlw zmm1 {k1} {z}, zmm7, xmm11
vpsrlw zmm1 {k1}, zmm7, [rdi]
vpsrlw zmm1 {k1} {z}, zmm7, [rdi]

; Shift words in xmm2/m128 right by imm8 while shifting in 0s using writemask k1.

vpsrlw xmm6 {k1} {z}, xmm9, 0x69
vpsrlw xmm6 {k1} {z}, [rax], 0x69

; Shift words in ymm2/m256 right by imm8 while shifting in 0s using writemask k1.

vpsrlw ymm6 {k1} {z}, ymm9, 0x69
vpsrlw ymm6 {k1} {z}, [rax], 0x69

; Shift words in zmm2/m512 right by imm8 while shifting in 0 using writemask k1.

vpsrlw zmm6 {k1} {z}, zmm9, 0x69
vpsrlw zmm6 {k1} {z}, [rax], 0x69

; Shift doublewords in xmm2 right by amount specified in xmm3/m128 while shifting in 0s under writemask k1.

vpsrld xmm1 {k1}, xmm7, xmm11
vpsrld xmm1 {k1} {z}, xmm7, xmm11
vpsrld xmm1 {k1}, xmm7, [rdi]
vpsrld xmm1 {k1} {z}, xmm7, [rdi]

; Shift doublewords in ymm2 right by amount specified in xmm3/m128 while shifting in 0s under writemask k1.

vpsrld ymm1 {k1}, ymm7, xmm11
vpsrld ymm1 {k1} {z}, ymm7, xmm11
vpsrld ymm1 {k1}, ymm7, [rdi]
vpsrld ymm1 {k1} {z}, ymm7, [rdi]

; Shift doublewords in zmm2 right by amount specified in xmm3/m128 while shifting in 0s under writemask k1.

vpsrld zmm1 {k1}, zmm7, xmm11
vpsrld zmm1 {k1} {z}, zmm7, xmm11
vpsrld zmm1 {k1}, zmm7, [rdi]
vpsrld zmm1 {k1} {z}, zmm7, [rdi]

; Shift doublewords in xmm2/m128/m32bcst right by imm8 while shifting in 0s using writemask k1.
; TODO: WHAT IS A 'm32bcst' (possible 2nd argument option) ?

vpsrld xmm6 {k1} {z}, xmm9, 0x69
vpsrld xmm6 {k1} {z}, [rax], 0x69

; Shift doublewords in ymm2/m256/m32bcst right by imm8 while shifting in 0s using writemask k1.
; TODO: WHAT IS A 'm32bcst' (possible 2nd argument option) ?

vpsrld ymm6 {k1} {z}, ymm9, 0x69
vpsrld ymm6 {k1} {z}, [rax], 0x69

; Shift doublewords in zmm2/m512/m32bcst right by imm8 while shifting in 0s using writemask k1.

vpsrld zmm6 {k1} {z}, zmm9, 0x69
vpsrld zmm6 {k1} {z}, [rax], 0x69

; Shift quadwords in xmm2 right by amount specified in xmm3/m128 while shifting in 0s using writemask k1.

vpsrlq xmm1 {k1}, xmm7, xmm11
vpsrlq xmm1 {k1} {z}, xmm7, xmm11
vpsrlq xmm1 {k1}, xmm7, [rdi]
vpsrlq xmm1 {k1} {z}, xmm7, [rdi]

; Shift quadwords in ymm2 right by amount specified in xmm3/m128 while shifting in 0s using writemask k1.

vpsrlq ymm1 {k1}, ymm7, xmm11
vpsrlq ymm1 {k1} {z}, ymm7, xmm11
vpsrlq ymm1 {k1}, ymm7, [rdi]
vpsrlq ymm1 {k1} {z}, ymm7, [rdi]

; Shift quadwords in zmm2 right by amount specified in xmm3/m128 while shifting in 0s using writemask k1.

vpsrlq zmm1 {k1}, zmm7, xmm11
vpsrlq zmm1 {k1} {z}, zmm7, xmm11
vpsrlq zmm1 {k1}, zmm7, [rdi]
vpsrlq zmm1 {k1} {z}, zmm7, [rdi]

; Shift quadwords in xmm2/m128/m64bcst right by imm8 while shifting in 0s using writemask k1.
; TODO: WHAT IS A 'm64bcst' (possible 2nd argument option) ?

vpsrlq xmm6 {k1} {z}, xmm9, 0x69
vpsrlq xmm6 {k1} {z}, [rax], 0x69

; Shift quadwords in ymm2/m256/m64bcst right by imm8 while shifting in 0s using writemask k1.
; TODO: WHAT IS A 'm64bcst' (possible 2nd argument option) ?

vpsrlq ymm6 {k1} {z}, ymm9, 0x69
vpsrlq ymm6 {k1} {z}, [rax], 0x69

;  	Shift quadwords in zmm2/m512/m64bcst right by imm8 while shifting in 0s using writemask k1.
; TODO: WHAT IS A 'm64bcst' (possible 2nd argument option) ?

vpsrlq zmm6 {k1} {z}, zmm9, 0x69
vpsrlq zmm6 {k1} {z}, [rax], 0x69

; Shift words in xmm2/m128 right by imm8 while shifting in sign bits using writemask k1.

vpsraw xmm1 {k1}, xmm7, xmm11
vpsraw xmm1 {k1} {z}, xmm7, xmm11
vpsraw xmm1 {k1}, xmm7, [rdi]
vpsraw xmm1 {k1} {z}, xmm7, [rdi]

; Shift words in ymm2/m256 right by imm8 while shifting in sign bits using writemask k1.

vpsraw ymm1 {k1}, ymm7, xmm11
vpsraw ymm1 {k1} {z}, ymm7, xmm11
vpsraw ymm1 {k1}, ymm7, [rdi]
vpsraw ymm1 {k1} {z}, ymm7, [rdi]

; Shift words in zmm2/m512 right by imm8 while shifting in sign bits using writemask k1.

vpsraw zmm1 {k1}, zmm7, xmm11
vpsraw zmm1 {k1} {z}, zmm7, xmm11
vpsraw zmm1 {k1}, zmm7, [rdi]
vpsraw zmm1 {k1} {z}, zmm7, [rdi]

; Shift words in xmm2/m128 right by imm8 while shifting in sign bits using writemask k1.

vpsraw xmm6 {k1} {z}, xmm9, 0x69
vpsraw xmm6 {k1} {z}, [rax], 0x69

; Shift words in ymm2/m256 right by imm8 while shifting in sign bits using writemask k1.

vpsraw ymm6 {k1} {z}, ymm9, 0x69
vpsraw ymm6 {k1} {z}, [rax], 0x69

; Shift words in zmm2/m512 right by imm8 while shifting in sign bits using writemask k1.

vpsraw zmm6 {k1} {z}, zmm9, 0x69
vpsraw zmm6 {k1} {z}, [rax], 0x69

; Shift doublewords in xmm2 right by amount specified in xmm3/m128 while shifting in sign bits using writemask k1.

vpsrad xmm1 {k1}, xmm7, xmm11
vpsrad xmm1 {k1} {z}, xmm7, xmm11
vpsrad xmm1 {k1}, xmm7, [rdi]
vpsrad xmm1 {k1} {z}, xmm7, [rdi]

; Shift doublewords in ymm2 right by amount specified in xmm3/m128 while shifting in sign bits using writemask k1.

vpsrad ymm1 {k1}, ymm7, xmm11
vpsrad ymm1 {k1} {z}, ymm7, xmm11
vpsrad ymm1 {k1}, ymm7, [rdi]
vpsrad ymm1 {k1} {z}, ymm7, [rdi]

; Shift doublewords in zmm2 right by amount specified in xmm3/m128 while shifting in sign bits using writemask k1.

vpsrad zmm1 {k1}, zmm7, xmm11
vpsrad zmm1 {k1} {z}, zmm7, xmm11
vpsrad zmm1 {k1}, zmm7, [rdi]
vpsrad zmm1 {k1} {z}, zmm7, [rdi]

; Shift doublewords in xmm2/m128/m32bcst right by imm8 while shifting in sign bits using writemask k1.
; TODO: WHAT IS A 'm32bcst' (possible 2nd argument option) ?

vpsrad xmm6 {k1} {z}, xmm9, 0x69
vpsrad xmm6 {k1} {z}, [rax], 0x69

; Shift doublewords in ymm2/m256/m32bcst right by imm8 while shifting in sign bits using writemask k1.
; TODO: WHAT IS A 'm32bcst' (possible 2nd argument option) ?

vpsrad ymm6 {k1} {z}, ymm9, 0x69
vpsrad ymm6 {k1} {z}, [rax], 0x69

; Shift doublewords in zmm2/m512/m32bcst right by imm8 while shifting in sign bits using writemask k1.
; TODO: WHAT IS A 'm32bcst' (possible 2nd argument option) ?

vpsrad zmm6 {k1} {z}, zmm9, 0x69
vpsrad zmm6 {k1} {z}, [rax], 0x69

; Shift quadwords in xmm2 right by amount specified in xmm3/m128 while shifting in sign bits using writemask k1.

vpsraq xmm1 {k1}, xmm7, xmm11
vpsraq xmm1 {k1} {z}, xmm7, xmm11
vpsraq xmm1 {k1}, xmm7, [rdi]
vpsraq xmm1 {k1} {z}, xmm7, [rdi]

; Shift quadwords in ymm2 right by amount specified in xmm3/m128 while shifting in sign bits using writemask k1.

vpsraq ymm1 {k1}, ymm7, xmm11
vpsraq ymm1 {k1} {z}, ymm7, xmm11
vpsraq ymm1 {k1}, ymm7, [rdi]
vpsraq ymm1 {k1} {z}, ymm7, [rdi]

; Shift quadwords in zmm2 right by amount specified in xmm3/m128 while shifting in sign bits using writemask k1.

vpsraq zmm1 {k1}, zmm7, xmm11
vpsraq zmm1 {k1} {z}, zmm7, xmm11
vpsraq zmm1 {k1}, zmm7, [rdi]
vpsraq zmm1 {k1} {z}, zmm7, [rdi]

; Shift quadwords in xmm2/m128/m64bcst right by imm8 while shifting in sign bits using writemask k1.
; TODO: WHAT IS A 'm64bcst' (possible 2nd argument option) ?

vpsraq xmm6 {k1} {z}, xmm9, 0x69
vpsraq xmm6 {k1} {z}, [rax], 0x69

; Shift quadwords in ymm2/m256/m64bcst right by imm8 while shifting in sign bits using writemask k1.
; TODO: WHAT IS A 'm64bcst' (possible 2nd argument option) ?

vpsraq ymm6 {k1} {z}, ymm9, 0x69
vpsraq ymm6 {k1} {z}, [rax], 0x69

; Shift quadwords in zmm2/m512/m64bcst right by imm8 while shifting in sign bits using writemask k1.
; TODO: WHAT IS A 'm64bcst' (possible 2nd argument option) ?

vpsraq zmm6 {k1} {z}, zmm9, 0x69
vpsraq zmm6 {k1} {z}, [rax], 0x69

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
