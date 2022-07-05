
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

; Move aligned packed single-precision floating-point values from xmm2/m128 to xmm1 using writemask k1.

vmovaps xmm7 {k6} {z}, xmm3
vmovaps xmm7 {k6} {z}, [rax]

; Move aligned packed single-precision floating-point values from ymm2/m256 to ymm1 using writemask k1.

vmovaps ymm7 {k6} {z}, ymm3
vmovaps ymm7 {k6} {z}, [rax]

; Move aligned packed single-precision floating-point values from zmm2/m512 to zmm1 using writemask k1.

vmovaps zmm7 {k6} {z}, zmm3
vmovaps zmm7 {k6} {z}, [rax]

; Move aligned packed single-precision floating-point values from xmm1 to xmm2/m128 using writemask k1.

vmovaps [rax], xmm7

; Move aligned packed single-precision floating-point values from ymm1 to ymm2/m256 using writemask k1.

vmovaps [rax], ymm7

; Move aligned packed single-precision floating-point values from zmm1 to zmm2/m512 using writemask k1.

vmovaps [rax], zmm7

; Move unaligned packed single-precision floating-point values from xmm2/m128 to xmm1 using writemask k1.

vmovups xmm7 {k6} {z}, xmm3
vmovups xmm7 {k6} {z}, [rax]

; Move unaligned packed single-precision floating-point values from ymm2/m256 to ymm1 using writemask k1.

vmovups ymm7 {k6} {z}, ymm3
vmovups ymm7 {k6} {z}, [rax]

; Move unaligned packed single-precision floating-point values from zmm2/m512 to zmm1 using writemask k1.

vmovups zmm7 {k6} {z}, zmm3
vmovups zmm7 {k6} {z}, [rax]

; Move unaligned packed single-precision floating-point values from xmm1 to xmm2/m128 using writemask k1.

vmovups [rax], xmm7

; Move unaligned packed single-precision floating-point values from ymm1 to ymm2/m256 using writemask k1.

vmovups [rax], ymm7

; Move unaligned packed single-precision floating-point values from zmm1 to zmm2/m512 using writemask k1.

vmovups [rax], zmm7

; Move scalar single-precision floating-point value from xmm2 and xmm3 to xmm1 register under writemask k1.

vmovss xmm1 {k3} {z}, xmm2, xmm3

; Move scalar single-precision floating-point values from m32 to xmm1 under writemask k1.

vmovss xmm1, [rdi]

; Move scalar single-precision floating-point values from xmm1 to m32 under writemask k1.

vmovss [rdi], xmm2

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

; Extract 8-bit sign mask from ymm2 and store in reg. The upper bits of r32 or r64 are zeroed.

vmovmskps rax, ymm2

; Add packed single-precision floating-point values from xmm3/m128/m32bcst to xmm2 and store result in xmm1 with writemask k1.
; TODO: 'm32bcst' possible thrid argument

vaddps xmm1 {k3} {z}, xmm4, xmm3
vaddps xmm1 {k3} {z}, xmm4, [rax]

; Add packed single-precision floating-point values from ymm3/m256/m32bcst to ymm2 and store result in ymm1 with writemask k1.
; TODO: 'm32bcst' possible thrid argument

vaddps ymm1 {k3} {z}, ymm4, ymm3
vaddps ymm1 {k3} {z}, ymm4, [rax]

; Add packed single-precision floating-point values from zmm3/m512/m32bcst to zmm2 and store result in zmm1 with writemask k1.
; TODO: 'm32bcst' possible thrid argument

vaddps zmm1 {k3} {z}, zmm4, zmm3
vaddps zmm1 {k3} {z}, zmm4, [rax]

; Add the low single-precision floating-point value from xmm3/m32 to xmm2 and store the result in xmm1with writemask k1.

vaddss xmm1, xmm2, xmm3
vaddss xmm1 {k4} {z}, xmm2, DWORD [rax]

; Multiply packed single-precision floating-point values from xmm3/m128/m32bcst to xmm2 and store result in xmm1.
; TODO: 'm32bcst' possible thrid argument

vmulps xmm1 {k3} {z}, xmm2, xmm3
vmulps xmm1 {k3} {z}, xmm2, [rax]

; Multiply packed single-precision floating-point values from ymm3/m256/m32bcst to ymm2 and store result in ymm1.
; TODO: 'm32bcst' possible thrid argument

vmulps ymm1 {k3} {z}, ymm2, ymm3
vmulps ymm1 {k3} {z}, ymm2, [rax]

; Multiply packed single-precision floating-point values from ymm3/m256/m32bcst to ymm2 and store result in ymm1.
; TODO: 'm32bcst' possible thrid argument

vmulps zmm1 {k3} {z}, zmm2, zmm3
vmulps zmm1 {k3} {z}, zmm2, [rax]

; Multiply the low single-precision floating-point value in xmm3/m32 by the low single-precision floating-point value in xmm2.

vmulss xmm1 {k3} {z}, xmm2, xmm3
vmulss xmm1 {k3} {z}, xmm2, [rax]

; Divide packed single-precision floating-point values in xmm2 by packed single-precision floating-point values in xmm3/m128/m32bcst and write results to xmm1 subject to writemask k1.
; TODO: 'm32bcst' possible thrid argument

vdivps xmm1 {k3} {z}, xmm2, xmm3
vdivps xmm1 {k3} {z}, xmm2, [rax]

; Divide packed single-precision floating-point values in ymm2 by packed single-precision floating-point values in ymm3/m256/m32bcst and write results to ymm1 subject to writemask k1.
; TODO: 'm32bcst' possible thrid argument

vdivps ymm1 {k3} {z}, ymm2, ymm3
vdivps ymm1 {k3} {z}, ymm2, [rax]

; Divide packed single-precision floating-point values in zmm2 by packed single-precision floating-point values in zmm3/m512/m32bcst and write results to zmm1 subject to writemask k1.
; TODO: 'm32bcst' possible thrid argument

vdivps zmm1 {k3} {z}, zmm2, zmm3
vdivps zmm1 {k3} {z}, zmm2, [rax]

; Divide low single-precision floating-point value in xmm2 by low single-precision floating-point value in xmm3/m32.

vdivss xmm1 {k3} {z}, xmm2, xmm3
vdivss xmm1 {k3} {z}, xmm2, [rax]

; Computes Square Roots of the packed single-precision floating-point values in xmm2/m128/m32bcst and stores the result in xmm1 subject to writemask k1.
; TODO: 'm32bcst' possible second argument

vsqrtps xmm1 {k3} {z}, xmm3
vsqrtps xmm1 {k3} {z}, [rax]

; Computes Square Roots of the packed single-precision floating-point values in ymm2/m256/m32bcst and stores the result in ymm1 subject to writemask k1.
; TODO: 'm32bcst' possible second argument

vsqrtps ymm1 {k3} {z}, ymm3
vsqrtps ymm1 {k3} {z}, [rax]

; Computes Square Roots of the packed single-precision floating-point values in zmm2/m512/m32bcst and stores the result in zmm1 subject to writemask k1.
; TODO: 'm32bcst' possible second argument

vsqrtps zmm1 {k3} {z}, zmm3
vsqrtps zmm1 {k3} {z}, [rax]

; Computes square root of the low single-precision floating-point value in xmm3/m32 and stores the results in xmm1 under writemask k1. Also, upper single-precision floating-point values (bits[127:32]) from xmm2 are copied to xmm1[127:32].

vsqrtss xmm1 {k3} {z}, xmm2, xmm3
vsqrtss xmm1 {k3} {z}, xmm2, [rax]

; Return the maximum packed single-precision floating-point values between xmm2 and xmm3/m128/m32bcst and store result in xmm1 subject to writemask k1.re result in xmm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vmaxps xmm1 {k3} {z}, xmm2, xmm3
vmaxps xmm1 {k3} {z}, xmm2, [rax]

; Return the maximum packed single-precision floating-point values between ymm2 and ymm3/m256/m32bcst and store result in ymm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vmaxps ymm1 {k3} {z}, ymm2, ymm3
vmaxps ymm1 {k3} {z}, ymm2, [rax]

; Return the maximum packed single-precision floating-point values between zmm2 and zmm3/m512/m32bcst and store result in zmm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vmaxps zmm1 {k3} {z}, zmm2, zmm3
vmaxps zmm1 {k3} {z}, zmm2, [rax]

; Return the maximum scalar single-precision floating-point value between xmm3/m32 and xmm2.

vmaxss xmm1 {k3} {z}, xmm2, xmm3
vmaxss xmm1 {k3} {z}, xmm2, [rax]

; Return the minimum packed single-precision floating-point values between xmm2 and xmm3/m128/m32bcst and store result in xmm1 subject to writemask k1.re result in xmm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vminps xmm1 {k3} {z}, xmm2, xmm3
vminps xmm1 {k3} {z}, xmm2, [rax]

; Return the minimum packed single-precision floating-point values between ymm2 and ymm3/m256/m32bcst and store result in ymm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vminps ymm1 {k3} {z}, ymm2, ymm3
vminps ymm1 {k3} {z}, ymm2, [rax]

; Return the minimum packed single-precision floating-point values between zmm2 and zmm3/m512/m32bcst and store result in zmm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vminps zmm1 {k3} {z}, zmm2, zmm3
vminps zmm1 {k3} {z}, zmm2, [rax]

; Return the minimum scalar single-precision floating-point value between xmm3/m32 and xmm2.

vminss xmm1 {k3} {z}, xmm2, xmm3
vminss xmm1 {k3} {z}, xmm2, [rax]

; Return the bitwise logical AND of packed single-precision floating-point values in xmm2 and xmm3/m128/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vandps xmm1 {k3} {z}, xmm2, xmm3
vandps xmm1 {k3} {z}, xmm2, [rax]

; Return the bitwise logical AND of packed single-precision floating-point values in ymm2 and ymm3/m256/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vandps ymm1 {k3} {z}, ymm2, ymm3
vandps ymm1 {k3} {z}, ymm2, [rax]

; Return the bitwise logical AND of packed single-precision floating-point values in zmm2 and zmm3/m512/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vandps zmm1 {k3} {z}, zmm2, zmm3
vandps zmm1 {k3} {z}, zmm2, [rax]

; Return the bitwise logical AND NOT of packed single-precision floating-point values in xmm2 and xmm3/m128/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vandnps xmm1 {k3} {z}, xmm2, xmm3
vandnps xmm1 {k3} {z}, xmm2, [rax]

; Return the bitwise logical AND NOT of packed single-precision floating-point values in ymm2 and ymm3/m256/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vandnps ymm1 {k3} {z}, ymm2, ymm3
vandnps ymm1 {k3} {z}, ymm2, [rax]

; Return the bitwise logical AND NOT of packed single-precision floating-point values in zmm2 and zmm3/m512/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vandnps zmm1 {k3} {z}, zmm2, zmm3
vandnps zmm1 {k3} {z}, zmm2, [rax]

; Return the bitwise logical OR of packed single-precision floating-point values in xmm2 and xmm3/m128/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vorps xmm1 {k3} {z}, xmm2, xmm3
vorps xmm1 {k3} {z}, xmm2, [rax]

; Return the bitwise logical OR of packed single-precision floating-point values in ymm2 and ymm3/m256/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vorps ymm1 {k3} {z}, ymm2, ymm3
vorps ymm1 {k3} {z}, ymm2, [rax]

; Return the bitwise logical OR of packed single-precision floating-point values in zmm2 and zmm3/m512/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vorps zmm1 {k3} {z}, zmm2, zmm3
vorps zmm1 {k3} {z}, zmm2, [rax]

; Return the bitwise logical XOR of packed single-precision floating-point values in xmm2 and xmm3/m128/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vxorps xmm1 {k3} {z}, xmm2, xmm3
vxorps xmm1 {k3} {z}, xmm2, [rax]

; Return the bitwise logical XOR of packed single-precision floating-point values in ymm2 and ymm3/m256/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vxorps ymm1 {k3} {z}, ymm2, ymm3
vxorps ymm1 {k3} {z}, ymm2, [rax]

; Return the bitwise logical XOR of packed single-precision floating-point values in zmm2 and zmm3/m512/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vxorps zmm1 {k3} {z}, zmm2, zmm3
vxorps zmm1 {k3} {z}, zmm2, [rax]

; Compare packed single-precision floating-point values in xmm3/m128/m32bcst and xmm2 using bits 4:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.
; TODO: 'm32bcst' possible third argument

vcmpps k3 {k2}, xmm2, xmm3, 0x69
vcmpps k3 {k2}, xmm2, [rax], 0x69

; Compare packed single-precision floating-point values in ymm3/m256/m32bcst and ymm2 using bits 4:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.
; TODO: 'm32bcst' possible third argument

vcmpps k3 {k2}, ymm2, ymm3, 0x69
vcmpps k3 {k2}, ymm2, [rax], 0x69

; Compare packed single-precision floating-point values in zmm3/m512/m32bcst and zmm2 using bits 4:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.
; TODO: 'm32bcst' possible third argument

vcmpps k3 {k2}, zmm2, zmm3, 0x69
vcmpps k3 {k2}, zmm2, [rax], 0x69

; Compare low single-precision floating-point value in xmm3/m32 and xmm2 using bits 4:0 of imm8 as comparison predicate with writemask k2 and leave the result in mask register k1.

vcmpss k3 {k2}, xmm2, xmm3, 0x69
vcmpss k3 {k2}, xmm2, [rax], 0x69

; Compare low single-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.

vcomiss xmm1, xmm2
vcomiss xmm1, [rax]

; Compare low single-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.

vucomiss xmm1, xmm2
vucomiss xmm1, [rax]

; Select from quadruplet of single-precision floating-point values in xmm1 and xmm2/m128 using imm8, interleaved result pairs are stored in xmm1, subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vshufps xmm1 {k7} {z}, xmm2, xmm3, 0x69
vshufps xmm1 {k7} {z}, xmm2, [rax], 0x69

; Select from quadruplet of single-precision floating-point values in ymm2 and ymm3/m256 using imm8, interleaved result pairs are stored in ymm1, subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vshufps ymm1 {k7} {z}, ymm2, ymm3, 0x69
vshufps ymm1 {k7} {z}, ymm2, [rax], 0x69

; Select from quadruplet of single-precision floating-point values in zmm2 and zmm3/m512 using imm8, interleaved result pairs are stored in zmm1, subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vshufps zmm1 {k7} {z}, zmm2, zmm3, 0x69
vshufps zmm1 {k7} {z}, zmm2, [rax], 0x69

; Unpacks and Interleaves single-precision floating-point values from high quadwords of xmm2 and xmm3/m128/m32bcst and write result to xmm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vunpckhps xmm1 {k4} {z}, xmm2, xmm3
vunpckhps xmm1 {k4} {z}, xmm2, [rax]

; Unpacks and Interleaves single-precision floating-point values from high quadwords of ymm2 and ymm3/m256/m32bcst and write result to ymm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vunpckhps ymm1 {k4} {z}, ymm2, ymm3
vunpckhps ymm1 {k4} {z}, ymm2, [rax]

; Unpacks and Interleaves single-precision floating-point values from high quadwords of zmm2 and zmm3/m512/m32bcst and write result to zmm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vunpckhps zmm1 {k4} {z}, zmm2, zmm3
vunpckhps zmm1 {k4} {z}, zmm2, [rax]

; Unpacks and Interleaves single-precision floating-point values from low quadwords of xmm2 and xmm3/m128/m32bcst and write result to xmm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vunpcklps xmm1 {k4} {z}, xmm2, xmm3
vunpcklps xmm1 {k4} {z}, xmm2, [rax]

; Unpacks and Interleaves single-precision floating-point values from low quadwords of ymm2 and ymm3/m256/m32bcst and write result to ymm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vunpcklps ymm1 {k4} {z}, ymm2, ymm3
vunpcklps ymm1 {k4} {z}, ymm2, [rax]

; Unpacks and Interleaves single-precision floating-point values from low quadwords of zmm2 and zmm3/m512/m32bcst and write result to zmm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vunpcklps zmm1 {k4} {z}, zmm2, zmm3
vunpcklps zmm1 {k4} {z}, zmm2, [rax]

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

; Average packed unsigned byte integers from ymm2, and ymm3/m256 with rounding and store to ymm1 under writemask k1.

vpavgb xmm1 {k3} {z}, xmm2, xmm3
vpavgb xmm1 {k3} {z}, xmm2, [rax]

; Average packed unsigned byte integers from ymm2, and ymm3/m256 with rounding and store to ymm1 under writemask k1.

vpavgb ymm1 {k3} {z}, ymm2, ymm3
vpavgb ymm1 {k3} {z}, ymm2, [rax]

; Average packed unsigned byte integers from zmm2, and zmm3/m512 with rounding and store to zmm1 under writemask k1.

vpavgb zmm1 {k3} {z}, zmm2, zmm3
vpavgb zmm1 {k3} {z}, zmm2, [rax]

; Average packed unsigned word integers from xmm2, xmm3/m128 with rounding to xmm1 under writemask k1.

vpavgw xmm1 {k3} {z}, xmm2, xmm3
vpavgw xmm1 {k3} {z}, xmm2, [rax]

; Average packed unsigned word integers from ymm2, ymm3/m256 with rounding to ymm1 under writemask k1.

vpavgw ymm1 {k3} {z}, ymm2, ymm3
vpavgw ymm1 {k3} {z}, ymm2, [rax]

; Average packed unsigned word integers from zmm2, zmm3/m512 with rounding to zmm1 under writemask k1.

vpavgw zmm1 {k3} {z}, zmm2, zmm3
vpavgw zmm1 {k3} {z}, zmm2, [rax]

; Extract a word integer value from xmm2 at the source word offset specified by imm8 into reg or m16. The upper bits of r64/r32 is filled with zeros.

pextrw rax, xmm2, 0x69
pextrw WORD [rax], xmm2, 0x69

; Insert a word integer value from r32/m16 and rest from xmm2 into xmm1 at the word offset in imm8.

vpinsrw xmm1, xmm2, eax, 0x69
vpinsrw xmm1, xmm2, WORD [rax], 0x69

; Compare packed unsigned byte integers in xmm2 and xmm3/m128 and store packed maximum values in xmm1 under writemask k1.

vpmaxub xmm1 {k1} {z}, xmm2, xmm3
vpmaxub xmm1 {k1} {z}, xmm2, [rax]

; Compare packed unsigned byte integers in ymm2 and ymm3/m256 and store packed maximum values in ymm1 under writemask k1.

vpmaxub ymm1 {k1} {z}, ymm2, ymm3
vpmaxub ymm1 {k1} {z}, ymm2, [rax]

; Compare packed unsigned byte integers in zmm2 and zmm3/m512 and store packed maximum values in zmm1 under writemask k1.

vpmaxub zmm1 {k1} {z}, zmm2, zmm3
vpmaxub zmm1 {k1} {z}, zmm2, [rax]

; Compare packed unsigned word integers in xmm2 and xmm3/m128 and store packed maximum values in xmm1 under writemask k1.

vpmaxuw xmm1 {k1} {z}, xmm2, xmm3
vpmaxuw xmm1 {k1} {z}, xmm2, [rax]

; Compare packed unsigned word integers in ymm2 and ymm3/m256 and store packed maximum values in ymm1 under writemask k1.

vpmaxuw ymm1 {k1} {z}, ymm2, ymm3
vpmaxuw ymm1 {k1} {z}, ymm2, [rax]

; Compare packed unsigned word integers in zmm2 and zmm3/m512 and store packed maximum values in zmm1 under writemask k1.

vpmaxuw zmm1 {k1} {z}, zmm2, zmm3
vpmaxuw zmm1 {k1} {z}, zmm2, [rax]

; Compare packed unsigned byte integers in xmm2 and xmm3/m128 and store packed minimum values in xmm1 under writemask k1.

vpminub xmm1 {k1} {z}, xmm2, xmm3
vpminub xmm1 {k1} {z}, xmm2, [rax]

; Compare packed unsigned byte integers in ymm2 and ymm3/m256 and store packed minimum values in ymm1 under writemask k1.

vpminub ymm1 {k1} {z}, ymm2, ymm3
vpminub ymm1 {k1} {z}, ymm2, [rax]

; Compare packed unsigned byte integers in zmm2 and zmm3/m512 and store packed minimum values in zmm1 under writemask k1.

vpminub zmm1 {k1} {z}, zmm2, zmm3
vpminub zmm1 {k1} {z}, zmm2, [rax]

; Compare packed unsigned word integers in xmm2 and xmm3/m128 and store packed minimum values in xmm1 under writemask k1.

vpminuw xmm1 {k1} {z}, xmm2, xmm3
vpminuw xmm1 {k1} {z}, xmm2, [rax]

; Compare packed unsigned word integers in ymm2 and ymm3/m256 and store packed minimum values in ymm1 under writemask k1.

vpminuw ymm1 {k1} {z}, ymm2, ymm3
vpminuw ymm1 {k1} {z}, ymm2, [rax]

; Compare packed unsigned word integers in zmm2 and zmm3/m512 and store packed minimum values in zmm1 under writemask k1.

vpminuw zmm1 {k1} {z}, zmm2, zmm3
vpminuw zmm1 {k1} {z}, zmm2, [rax]

; Compare packed signed byte integers in xmm2 and xmm3/m128 and store packed maximum values in xmm1 under writemask k1.

vpmaxsb xmm1 {k1} {z}, xmm2, xmm3
vpmaxsb xmm1 {k1} {z}, xmm2, [rax]

; Compare packed signed byte integers in ymm2 and ymm3/m256 and store packed maximum values in ymm1 under writemask k1.

vpmaxsb ymm1 {k1} {z}, ymm2, ymm3
vpmaxsb ymm1 {k1} {z}, ymm2, [rax]

; Compare packed signed byte integers in zmm2 and zmm3/m512 and store packed maximum values in zmm1 under writemask k1.

vpmaxsb zmm1 {k1} {z}, zmm2, zmm3
vpmaxsb zmm1 {k1} {z}, zmm2, [rax]

; Compare packed signed word integers in xmm2 and xmm3/m128 and store packed maximum values in xmm1 under writemask k1.

vpmaxsw xmm1 {k1} {z}, xmm2, xmm3
vpmaxsw xmm1 {k1} {z}, xmm2, [rax]

; Compare packed signed word integers in ymm2 and ymm3/m256 and store packed maximum values in ymm1 under writemask k1.

vpmaxsw ymm1 {k1} {z}, ymm2, ymm3
vpmaxsw ymm1 {k1} {z}, ymm2, [rax]

; Compare packed signed word integers in zmm2 and zmm3/m512 and store packed maximum values in zmm1 under writemask k1.

vpmaxsw zmm1 {k1} {z}, zmm2, zmm3
vpmaxsw zmm1 {k1} {z}, zmm2, [rax]

; Compare packed signed dword integers in xmm2 and xmm3/m128/m32bcst and store packed maximum values in xmm1 using writemask k1.

vpmaxsd xmm1 {k1} {z}, xmm2, xmm3
vpmaxsd xmm1 {k1} {z}, xmm2, [rax]

; Compare packed signed dword integers in ymm2 and ymm3/m256/m32bcst and store packed maximum values in ymm1 using writemask k1.

vpmaxsd ymm1 {k1} {z}, ymm2, ymm3
vpmaxsd ymm1 {k1} {z}, ymm2, [rax]

; Compare packed signed dword integers in zmm2 and zmm3/m512/m32bcst and store packed maximum values in zmm1 using writemask k1.

vpmaxsd zmm1 {k1} {z}, zmm2, zmm3
vpmaxsd zmm1 {k1} {z}, zmm2, [rax]

; Compare packed signed qword integers in xmm2 and xmm3/m128/m64bcst and store packed maximum values in xmm1 using writemask k1.

vpmaxsq xmm1 {k1} {z}, xmm2, xmm3
vpmaxsq xmm1 {k1} {z}, xmm2, [rax]

; Compare packed signed qword integers in ymm2 and ymm3/m256/m64bcst and store packed maximum values in ymm1 using writemask k1.

vpmaxsq ymm1 {k1} {z}, ymm2, ymm3
vpmaxsq ymm1 {k1} {z}, ymm2, [rax]

; Compare packed signed qword integers in zmm2 and zmm3/m512/m64bcst and store packed maximum values in zmm1 using writemask k1.

vpmaxsq zmm1 {k1} {z}, zmm2, zmm3
vpmaxsq zmm1 {k1} {z}, zmm2, [rax]

; Compare packed signed byte integers in xmm2 and xmm3/m128 and store packed minimum values in xmm1 under writemask k1.

vpminsb xmm1 {k1} {z}, xmm2, xmm3
vpminsb xmm1 {k1} {z}, xmm2, [rax]

; Compare packed signed byte integers in ymm2 and ymm3/m256 and store packed minimum values in ymm1 under writemask k1.

vpminsb ymm1 {k1} {z}, ymm2, ymm3
vpminsb ymm1 {k1} {z}, ymm2, [rax]

; Compare packed signed byte integers in zmm2 and zmm3/m512 and store packed minimum values in zmm1 under writemask k1.

vpminsb zmm1 {k1} {z}, zmm2, zmm3
vpminsb zmm1 {k1} {z}, zmm2, [rax]

; Compare packed signed word integers in xmm2 and xmm3/m128 and store packed minimum values in xmm1 under writemask k1.

vpminsw xmm1 {k1} {z}, xmm2, xmm3
vpminsw xmm1 {k1} {z}, xmm2, [rax]

; Compare packed signed word integers in ymm2 and ymm3/m256 and store packed minimum values in ymm1 under writemask k1.

vpminsw ymm1 {k1} {z}, ymm2, ymm3
vpminsw ymm1 {k1} {z}, ymm2, [rax]

; Compare packed signed word integers in zmm2 and zmm3/m512 and store packed minimum values in zmm1 under writemask k1.

vpminsw zmm1 {k1} {z}, zmm2, zmm3
vpminsw zmm1 {k1} {z}, zmm2, [rax]

; Multiply the packed unsigned word integers in xmm2 and xmm3/m128, and store the high 16 bits of the results in xmm1 under writemask k1.

vpmulhuw xmm1 {k1} {z}, xmm2, xmm3
vpmulhuw xmm1 {k1} {z}, xmm2, [rax]

; Multiply the packed unsigned word integers in ymm2 and ymm3/m256, and store the high 16 bits of the results in ymm1 under writemask k1.

vpmulhuw ymm1 {k1} {z}, ymm2, ymm3
vpmulhuw ymm1 {k1} {z}, ymm2, [rax]

; Multiply the packed unsigned word integers in zmm2 and zmm3/m512, and store the high 16 bits of the results in zmm1 under writemask k1.

vpmulhuw zmm1 {k1} {z}, zmm2, zmm3
vpmulhuw zmm1 {k1} {z}, zmm2, [rax]

; Computes the absolute differences of the packed unsigned byte integers from xmm3 /m128 and xmm2; then each consecutive 8 differences are summed separately to produce four unsigned word integer results.

vpsadbw xmm1, xmm2, xmm3
vpsadbw xmm1, xmm2, [rax]

; Computes the absolute differences of the packed unsigned byte integers from ymm3 /m256 and ymm2; then each consecutive 8 differences are summed separately to produce four unsigned word integer results.

vpsadbw ymm1, ymm2, ymm3
vpsadbw ymm1, ymm2, [rax]

; Computes the absolute differences of the packed unsigned byte integers from zmm3 /m512 and zmm2; then each consecutive 8 differences are summed separately to produce four unsigned word integer results.

vpsadbw zmm1, zmm2, zmm3
vpsadbw zmm1, zmm2, [rax]

; Move aligned packed double-precision floating-point values from xmm2/m128 to xmm1 using writemask k1.

vmovapd xmm7 {k6} {z}, xmm3
vmovapd xmm7 {k6} {z}, [rax]

; Move aligned packed double-precision floating-point values from ymm2/m256 to ymm1 using writemask k1.

vmovapd ymm7 {k6} {z}, ymm3
vmovapd ymm7 {k6} {z}, [rax]

; Move aligned packed double-precision floating-point values from zmm2/m512 to zmm1 using writemask k1.

vmovapd zmm7 {k6} {z}, zmm3
vmovapd zmm7 {k6} {z}, [rax]

; Move aligned packed double-precision floating-point values from xmm1 to xmm2/m128 using writemask k1.

vmovapd [rax], xmm7

; Move aligned packed double-precision floating-point values from ymm1 to ymm2/m256 using writemask k1.

vmovapd [rax], ymm7

; Move aligned packed double-precision floating-point values from zmm1 to zmm2/m512 using writemask k1.

vmovapd [rax], zmm7

; Move unaligned packed double-precision floating-point values from xmm2/m128 to xmm1 using writemask k1.

vmovupd xmm7 {k6} {z}, xmm3
vmovupd xmm7 {k6} {z}, [rax]

; Move unaligned packed double-precision floating-point values from ymm2/m256 to ymm1 using writemask k1.

vmovupd ymm7 {k6} {z}, ymm3
vmovupd ymm7 {k6} {z}, [rax]

; Move unaligned packed double-precision floating-point values from zmm2/m512 to zmm1 using writemask k1.

vmovupd zmm7 {k6} {z}, zmm3
vmovupd zmm7 {k6} {z}, [rax]

; Move unaligned packed double-precision floating-point values from xmm1 to xmm2/m128 using writemask k1.

vmovupd [rax], xmm7

; Move unaligned packed double-precision floating-point values from ymm1 to ymm2/m256 using writemask k1.

vmovupd [rax], ymm7

; Move unaligned packed double-precision floating-point values from zmm1 to zmm2/m512 using writemask k1.

vmovupd [rax], zmm7

; Move scalar double-precision floating-point value from xmm2 and xmm3 to xmm1 register under writemask k1.

vmovsd xmm1 {k3} {z}, xmm2, xmm3

; Move scalar double-precision floating-point values from m32 to xmm1 under writemask k1.

vmovsd xmm1, [rdi]

; Move scalar double-precision floating-point values from xmm1 to m32 under writemask k1.

vmovsd [rdi], xmm2

; Merge two packed double-precision floating-point values from m64 and the low quadword of xmm1.

vmovlpd xmm2, xmm1, [rax]

; Move two packed double-precision floating-point values from low quadword of xmm1 to m64.

vmovlpd [rax], xmm1

; Merge two packed double-precision floating-point values from m64 and the high quadword of xmm1.

vmovhpd xmm2, xmm1, [rax]

; Move two packed double-precision floating-point values from high quadword of xmm1 to m64.

vmovhpd [rax], xmm1

; Extract 8-bit sign mask from ymm2 and store in reg. The upper bits of r32 or r64 are zeroed.

vmovmskpd rax, ymm2

; Add packed double-precision floating-point values from xmm3/m128/m32bcst to xmm2 and store result in xmm1 with writemask k1.
; TODO: 'm32bcst' possible thrid argument

vaddpd xmm1 {k3} {z}, xmm4, xmm3
vaddpd xmm1 {k3} {z}, xmm4, [rax]

; Add packed double-precision floating-point values from ymm3/m256/m32bcst to ymm2 and store result in ymm1 with writemask k1.
; TODO: 'm32bcst' possible thrid argument

vaddpd ymm1 {k3} {z}, ymm4, ymm3
vaddpd ymm1 {k3} {z}, ymm4, [rax]

; Add packed double-precision floating-point values from zmm3/m512/m32bcst to zmm2 and store result in zmm1 with writemask k1.
; TODO: 'm32bcst' possible thrid argument

vaddpd zmm1 {k3} {z}, zmm4, zmm3
vaddpd zmm1 {k3} {z}, zmm4, [rax]

; Add the low double-precision floating-point value from xmm3/m32 to xmm2 and store the result in xmm1with writemask k1.

vaddsd xmm1, xmm2, xmm3
vaddsd xmm1 {k4} {z}, xmm2, QWORD [rax]

; Multiply packed double-precision floating-point values from xmm3/m128/m32bcst to xmm2 and store result in xmm1.
; TODO: 'm32bcst' possible thrid argument

vmulpd xmm1 {k3} {z}, xmm2, xmm3
vmulpd xmm1 {k3} {z}, xmm2, [rax]

; Multiply packed double-precision floating-point values from ymm3/m256/m32bcst to ymm2 and store result in ymm1.
; TODO: 'm32bcst' possible thrid argument

vmulpd ymm1 {k3} {z}, ymm2, ymm3
vmulpd ymm1 {k3} {z}, ymm2, [rax]

; Multiply packed double-precision floating-point values from ymm3/m256/m32bcst to ymm2 and store result in ymm1.
; TODO: 'm32bcst' possible thrid argument

vmulpd zmm1 {k3} {z}, zmm2, zmm3
vmulpd zmm1 {k3} {z}, zmm2, [rax]

; Multiply the low double-precision floating-point value in xmm3/m32 by the low double-precision floating-point value in xmm2.

vmulsd xmm1 {k3} {z}, xmm2, xmm3
vmulsd xmm1 {k3} {z}, xmm2, [rax]

; Divide packed double-precision floating-point values in xmm2 by packed double-precision floating-point values in xmm3/m128/m32bcst and write results to xmm1 subject to writemask k1.
; TODO: 'm32bcst' possible thrid argument

vdivpd xmm1 {k3} {z}, xmm2, xmm3
vdivpd xmm1 {k3} {z}, xmm2, [rax]

; Divide packed double-precision floating-point values in ymm2 by packed double-precision floating-point values in ymm3/m256/m32bcst and write results to ymm1 subject to writemask k1.
; TODO: 'm32bcst' possible thrid argument

vdivpd ymm1 {k3} {z}, ymm2, ymm3
vdivpd ymm1 {k3} {z}, ymm2, [rax]

; Divide packed double-precision floating-point values in zmm2 by packed double-precision floating-point values in zmm3/m512/m32bcst and write results to zmm1 subject to writemask k1.
; TODO: 'm32bcst' possible thrid argument

vdivpd zmm1 {k3} {z}, zmm2, zmm3
vdivpd zmm1 {k3} {z}, zmm2, [rax]

; Divide low double-precision floating-point value in xmm2 by low double-precision floating-point value in xmm3/m32.

vdivsd xmm1 {k3} {z}, xmm2, xmm3
vdivsd xmm1 {k3} {z}, xmm2, [rax]

; Computes Square Roots of the packed double-precision floating-point values in xmm2/m128/m32bcst and stores the result in xmm1 subject to writemask k1.
; TODO: 'm32bcst' possible second argument

vsqrtpd xmm1 {k3} {z}, xmm3
vsqrtpd xmm1 {k3} {z}, [rax]

; Computes Square Roots of the packed double-precision floating-point values in ymm2/m256/m32bcst and stores the result in ymm1 subject to writemask k1.
; TODO: 'm32bcst' possible second argument

vsqrtpd ymm1 {k3} {z}, ymm3
vsqrtpd ymm1 {k3} {z}, [rax]

; Computes Square Roots of the packed double-precision floating-point values in zmm2/m512/m32bcst and stores the result in zmm1 subject to writemask k1.
; TODO: 'm32bcst' possible second argument

vsqrtpd zmm1 {k3} {z}, zmm3
vsqrtpd zmm1 {k3} {z}, [rax]

; Computes square root of the low double-precision floating-point value in xmm3/m32 and stores the results in xmm1 under writemask k1. Also, upper double-precision floating-point values (bits[127:32]) from xmm2 are copied to xmm1[127:32].

vsqrtsd xmm1 {k3} {z}, xmm2, xmm3
vsqrtsd xmm1 {k3} {z}, xmm2, [rax]

; Return the maximum packed double-precision floating-point values between xmm2 and xmm3/m128/m32bcst and store result in xmm1 subject to writemask k1.re result in xmm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vmaxpd xmm1 {k3} {z}, xmm2, xmm3
vmaxpd xmm1 {k3} {z}, xmm2, [rax]

; Return the maximum packed double-precision floating-point values between ymm2 and ymm3/m256/m32bcst and store result in ymm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vmaxpd ymm1 {k3} {z}, ymm2, ymm3
vmaxpd ymm1 {k3} {z}, ymm2, [rax]

; Return the maximum packed double-precision floating-point values between zmm2 and zmm3/m512/m32bcst and store result in zmm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vmaxpd zmm1 {k3} {z}, zmm2, zmm3
vmaxpd zmm1 {k3} {z}, zmm2, [rax]

; Return the maximum scalar double-precision floating-point value between xmm3/m32 and xmm2.

vmaxsd xmm1 {k3} {z}, xmm2, xmm3
vmaxsd xmm1 {k3} {z}, xmm2, [rax]

; Return the minimum packed double-precision floating-point values between xmm2 and xmm3/m128/m32bcst and store result in xmm1 subject to writemask k1.re result in xmm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vminpd xmm1 {k3} {z}, xmm2, xmm3
vminpd xmm1 {k3} {z}, xmm2, [rax]

; Return the minimum packed double-precision floating-point values between ymm2 and ymm3/m256/m32bcst and store result in ymm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vminpd ymm1 {k3} {z}, ymm2, ymm3
vminpd ymm1 {k3} {z}, ymm2, [rax]

; Return the minimum packed double-precision floating-point values between zmm2 and zmm3/m512/m32bcst and store result in zmm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vminpd zmm1 {k3} {z}, zmm2, zmm3
vminpd zmm1 {k3} {z}, zmm2, [rax]

; Return the minimum scalar double-precision floating-point value between xmm3/m32 and xmm2.

vminsd xmm1 {k3} {z}, xmm2, xmm3
vminsd xmm1 {k3} {z}, xmm2, [rax]

; Return the bitwise logical AND of packed double-precision floating-point values in xmm2 and xmm3/m128/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vandpd xmm1 {k3} {z}, xmm2, xmm3
vandpd xmm1 {k3} {z}, xmm2, [rax]

; Return the bitwise logical AND of packed double-precision floating-point values in ymm2 and ymm3/m256/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vandpd ymm1 {k3} {z}, ymm2, ymm3
vandpd ymm1 {k3} {z}, ymm2, [rax]

; Return the bitwise logical AND of packed double-precision floating-point values in zmm2 and zmm3/m512/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vandpd zmm1 {k3} {z}, zmm2, zmm3
vandpd zmm1 {k3} {z}, zmm2, [rax]

; Return the bitwise logical AND NOT of packed double-precision floating-point values in xmm2 and xmm3/m128/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vandnpd xmm1 {k3} {z}, xmm2, xmm3
vandnpd xmm1 {k3} {z}, xmm2, [rax]

; Return the bitwise logical AND NOT of packed double-precision floating-point values in ymm2 and ymm3/m256/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vandnpd ymm1 {k3} {z}, ymm2, ymm3
vandnpd ymm1 {k3} {z}, ymm2, [rax]

; Return the bitwise logical AND NOT of packed double-precision floating-point values in zmm2 and zmm3/m512/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vandnpd zmm1 {k3} {z}, zmm2, zmm3
vandnpd zmm1 {k3} {z}, zmm2, [rax]

; Return the bitwise logical OR of packed double-precision floating-point values in xmm2 and xmm3/m128/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vorpd xmm1 {k3} {z}, xmm2, xmm3
vorpd xmm1 {k3} {z}, xmm2, [rax]

; Return the bitwise logical OR of packed double-precision floating-point values in ymm2 and ymm3/m256/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vorpd ymm1 {k3} {z}, ymm2, ymm3
vorpd ymm1 {k3} {z}, ymm2, [rax]

; Return the bitwise logical OR of packed double-precision floating-point values in zmm2 and zmm3/m512/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vorpd zmm1 {k3} {z}, zmm2, zmm3
vorpd zmm1 {k3} {z}, zmm2, [rax]

; Return the bitwise logical XOR of packed double-precision floating-point values in xmm2 and xmm3/m128/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vxorpd xmm1 {k3} {z}, xmm2, xmm3
vxorpd xmm1 {k3} {z}, xmm2, [rax]

; Return the bitwise logical XOR of packed double-precision floating-point values in ymm2 and ymm3/m256/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vxorpd ymm1 {k3} {z}, ymm2, ymm3
vxorpd ymm1 {k3} {z}, ymm2, [rax]

; Return the bitwise logical XOR of packed double-precision floating-point values in zmm2 and zmm3/m512/m32bcst subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vxorpd zmm1 {k3} {z}, zmm2, zmm3
vxorpd zmm1 {k3} {z}, zmm2, [rax]

; Compare packed double-precision floating-point values in xmm3/m128/m32bcst and xmm2 using bits 4:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.
; TODO: 'm32bcst' possible third argument

vcmppd k3 {k2}, xmm2, xmm3, 0x69
vcmppd k3 {k2}, xmm2, [rax], 0x69

; Compare packed double-precision floating-point values in ymm3/m256/m32bcst and ymm2 using bits 4:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.
; TODO: 'm32bcst' possible third argument

vcmppd k3 {k2}, ymm2, ymm3, 0x69
vcmppd k3 {k2}, ymm2, [rax], 0x69

; Compare packed double-precision floating-point values in zmm3/m512/m32bcst and zmm2 using bits 4:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.
; TODO: 'm32bcst' possible third argument

vcmppd k3 {k2}, zmm2, zmm3, 0x69
vcmppd k3 {k2}, zmm2, [rax], 0x69

; Compare low double-precision floating-point value in xmm3/m32 and xmm2 using bits 4:0 of imm8 as comparison predicate with writemask k2 and leave the result in mask register k1.

vcmpsd k3 {k2}, xmm2, xmm3, 0x69
vcmpsd k3 {k2}, xmm2, [rax], 0x69

; Compare low double-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.

vcomisd xmm1, xmm2
vcomisd xmm1, [rax]

; Compare low double-precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.

vucomisd xmm1, xmm2
vucomisd xmm1, [rax]

; Select from quadruplet of double-precision floating-point values in xmm1 and xmm2/m128 using imm8, interleaved result pairs are stored in xmm1, subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vshufpd xmm1 {k7} {z}, xmm2, xmm3, 0x69
vshufpd xmm1 {k7} {z}, xmm2, [rax], 0x69

; Select from quadruplet of double-precision floating-point values in ymm2 and ymm3/m256 using imm8, interleaved result pairs are stored in ymm1, subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vshufpd ymm1 {k7} {z}, ymm2, ymm3, 0x69
vshufpd ymm1 {k7} {z}, ymm2, [rax], 0x69

; Select from quadruplet of double-precision floating-point values in zmm2 and zmm3/m512 using imm8, interleaved result pairs are stored in zmm1, subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vshufpd zmm1 {k7} {z}, zmm2, zmm3, 0x69
vshufpd zmm1 {k7} {z}, zmm2, [rax], 0x69

; Unpacks and Interleaves double-precision floating-point values from high quadwords of xmm2 and xmm3/m128/m32bcst and write result to xmm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vunpckhpd xmm1 {k4} {z}, xmm2, xmm3
vunpckhpd xmm1 {k4} {z}, xmm2, [rax]

; Unpacks and Interleaves double-precision floating-point values from high quadwords of ymm2 and ymm3/m256/m32bcst and write result to ymm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vunpckhpd ymm1 {k4} {z}, ymm2, ymm3
vunpckhpd ymm1 {k4} {z}, ymm2, [rax]

; Unpacks and Interleaves double-precision floating-point values from high quadwords of zmm2 and zmm3/m512/m32bcst and write result to zmm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vunpckhpd zmm1 {k4} {z}, zmm2, zmm3
vunpckhpd zmm1 {k4} {z}, zmm2, [rax]

; Unpacks and Interleaves double-precision floating-point values from low quadwords of xmm2 and xmm3/m128/m32bcst and write result to xmm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vunpcklpd xmm1 {k4} {z}, xmm2, xmm3
vunpcklpd xmm1 {k4} {z}, xmm2, [rax]

; Unpacks and Interleaves double-precision floating-point values from low quadwords of ymm2 and ymm3/m256/m32bcst and write result to ymm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vunpcklpd ymm1 {k4} {z}, ymm2, ymm3
vunpcklpd ymm1 {k4} {z}, ymm2, [rax]

; Unpacks and Interleaves double-precision floating-point values from low quadwords of zmm2 and zmm3/m512/m32bcst and write result to zmm1 subject to writemask k1.
; TODO: 'm32bcst' possible third argument

vunpcklpd zmm1 {k4} {z}, zmm2, zmm3
vunpcklpd zmm1 {k4} {z}, zmm2, [rax]

; Convert two packed single-precision floating-point values in xmm2/m64/m32bcst to packed double-precision floating-point values in xmm1 with writemask k1.
; TODO: 'm32bcst' possible second argument

vcvtps2pd xmm1 {k1} {z}, xmm2
vcvtps2pd xmm1 {k1} {z}, [rax]

; Convert four packed single-precision floating-point values in xmm2/m128/m32bcst to packed double-precision floating-point values in ymm1 with writemask k1.
; TODO: 'm32bcst' possible second argument

vcvtps2pd ymm1 {k1} {z}, xmm2
vcvtps2pd ymm1 {k1} {z}, [rax]

; Convert eight packed single-precision floating-point values in ymm2/m256/b32bcst to eight packed double-precision floating-point values in zmm1 with writemask k1.
; TODO: 'm32bcst' possible second argument

vcvtps2pd zmm1, ymm2
vcvtps2pd zmm1 {k1} {z}, [rax]

; Convert two packed double-precision floating-point values in xmm2/m128/m64bcst to two single-precision floating-point values in xmm1with writemask k1.
; TODO: 'm64bcst' possible second argument

vcvtpd2ps xmm1 {k1} {z}, xmm2
vcvtpd2ps xmm1, [rax]

; Convert four packed double-precision floating-point values in ymm2/m256/m64bcst to four single-precision floating-point values in xmm1with writemask k1.
; TODO: 'm64bcst' possible second argument

vcvtpd2ps xmm1 {k1} {z}, ymm2
vcvtpd2ps xmm1, [rax]

; Convert eight packed double-precision floating-point values in zmm2/m512/m64bcst to eight single-precision floating-point values in ymm1with writemask k1.
; TODO: 'm64bcst' possible second argument

vcvtpd2ps ymm1, zmm2
vcvtpd2ps xmm1, [rax]

; Convert one single-precision floating-point value in xmm3/m32 to one double-precision floating-point value and merge with high bits of xmm2 under writemask k1.

vcvtss2sd xmm1 {k1} {z}, xmm2, xmm3
vcvtss2sd xmm1 {k1} {z}, xmm2, DWORD [rax]

; Convert one double-precision floating-point value in xmm3/m64 to one single-precision floating-point value and merge with high bits in xmm2 under writemask k1.

vcvtsd2ss xmm1 {k1} {z}, xmm2, xmm3
vcvtsd2ss xmm1 {k1} {z}, xmm2, QWORD [rax]

; Convert two packed double-precision floating-point values in xmm2/m128/m64bcst to two signed doubleword integers in xmm1 subject to writemask k1.
; TODO: 'm64bcst' possible second argument

vcvtpd2dq xmm1 {k1} {z}, xmm2
vcvtpd2dq xmm1, [rax]

; Convert four packed double-precision floating-point values in ymm2/m256/m64bcst to four signed doubleword integers in xmm1 subject to writemask k1.
; TODO: 'm64bcst' possible second argument

vcvtpd2dq xmm1 {k1} {z}, ymm2
vcvtpd2dq xmm1, [rax]

; Convert eight packed double-precision floating-point values in zmm2/m512/m64bcst to eight signed doubleword integers in ymm1 subject to writemask k1.
; TODO: 'm64bcst' possible second argument

vcvtpd2dq ymm1 {k1} {z}, zmm2
vcvtpd2dq ymm1, [rax]

; Convert two packed double-precision floating-point values in xmm2/m128/m64bcst to two signed doubleword integers in xmm1 using truncation subject to writemask k1.
; TODO: 'm64bcst' possible second argument

vcvttpd2dq xmm1 {k1} {z}, xmm2
vcvttpd2dq xmm1, [rax]

; Convert four packed double-precision floating-point values in ymm2/m256/m64bcst to four signed doubleword integers in xmm1 using truncation subject to writemask k1.
; TODO: 'm64bcst' possible second argument

vcvttpd2dq xmm1 {k1} {z}, ymm2
vcvttpd2dq xmm1, [rax]

; Convert eight packed double-precision floating-point values in zmm2/m512/m64bcst to eight signed doubleword integers in ymm1 using truncation subject to writemask k1.
; TODO: 'm64bcst' possible second argument

vcvttpd2dq ymm1 {k1} {z}, zmm2
vcvttpd2dq ymm1, [rax]

; Convert 2 packed signed doubleword integers from xmm2/m128/m32bcst to eight packed double-precision floating-point values in xmm1 with writemask k1.
; TODO: 'm32bcst' possible second argument

vcvtdq2pd xmm1 {k1} {z}, xmm2
vcvtdq2pd xmm1 {k1} {z}, [rax]

; Convert 4 packed signed doubleword integers from xmm2/m128/m32bcst to 4 packed double-precision floating-point values in ymm1 with writemask k1.
; TODO: 'm32bcst' possible second argument

vcvtdq2pd ymm1 {k1} {z}, xmm2
vcvtdq2pd ymm1 {k1} {z}, [rax]

; Convert eight packed signed doubleword integers from ymm2/m256/m32bcst to eight packed double-precision floating-point values in zmm1 with writemask k1.
; TODO: 'm32bcst' possible second argument

vcvtdq2pd zmm1 {k1} {z}, ymm2
vcvtdq2pd zmm1 {k1} {z}, [rax]

; Convert one double-precision floating-point value from xmm1/m64 to one signed doubleword integer r32.

vcvtsd2si eax, xmm1
vcvtsd2si eax, QWORD [rdi]

; Convert one double-precision floating-point value from xmm1/m64 to one signed quadword integer sign-extended into r64.

vcvtsd2si rax, xmm1
vcvtsd2si rax, QWORD [rdi]

; Convert one double-precision floating-point value from xmm1/m64 to one signed doubleword integer in r32 using truncation.

vcvttsd2si eax, xmm1
vcvttsd2si eax, QWORD [rdi]

; Convert one double-precision floating-point value from xmm1/m64 to one signed quadword integer in r64 using truncation.

vcvttsd2si rax, xmm1
vcvttsd2si rax, QWORD [rdi]

; Convert one signed doubleword integer from r/m32 to one double-precision floating-point value in xmm1.

vcvtsi2sd xmm1, xmm2, eax
vcvtsi2sd xmm1, xmm2, DWORD [rax]

; Convert one signed quadword integer from r/m64 to one double-precision floating-point value in xmm1.

vcvtsi2sd xmm1, xmm2, rax
vcvtsi2sd xmm1, xmm2, QWORD [rax]

; Convert four packed single precision floating-point values from xmm2/m128/m32bcst to four packed signed doubleword values in xmm1 subject to writemask k1.
; TODO: 'm32bcst' possible second argument

vcvtps2dq xmm1 {k1} {z}, xmm2
vcvtps2dq xmm1 {k1} {z}, [rax]

; Convert eight packed single precision floating-point values from ymm2/m256/m32bcst to eight packed signed doubleword values in ymm1 subject to writemask k1.
; TODO: 'm32bcst' possible second argument

vcvtps2dq ymm1 {k1} {z}, ymm2
vcvtps2dq ymm1 {k1} {z}, [rax]

; Convert sixteen packed single-precision floating-point values from zmm2/m512/m32bcst to sixteen packed signed doubleword values in zmm1 subject to writemask k1.
; TODO: 'm32bcst' possible second argument

vcvtps2dq zmm1 {k1} {z}, zmm2
vcvtps2dq zmm1 {k1} {z}, [rax]

; Convert four packed single precision floating-point values from xmm2/m128/m32bcst to four packed signed doubleword values in xmm1 using truncation subject to writemask k1.
; TODO: 'm32bcst' possible second argument

vcvttps2dq xmm1 {k1} {z}, xmm2
vcvttps2dq xmm1 {k1} {z}, [rax]

; Convert eight packed single precision floating-point values from ymm2/m256/m32bcst to eight packed signed doubleword values in ymm1 using truncation subject to writemask k1.
; TODO: 'm32bcst' possible second argument

vcvttps2dq ymm1 {k1} {z}, ymm2
vcvttps2dq ymm1 {k1} {z}, [rax]

; Convert sixteen packed single-precision floating-point values from zmm2/m512/m32bcst to sixteen packed signed doubleword values in zmm1 using truncation subject to writemask k1.
; TODO: 'm32bcst' possible second argument

vcvttps2dq zmm1 {k1} {z}, zmm2
vcvttps2dq zmm1 {k1} {z}, [rax]

; Convert four packed signed doubleword integers from xmm2/m128/m32bcst to four packed single-precision floating-point values in xmm1with writemask k1.

vcvtdq2ps xmm1 {k1} {z}, xmm2
vcvtdq2ps xmm1 {k1} {z}, [rax]

; Convert eight packed signed doubleword integers from ymm2/m256/m32bcst to eight packed single-precision floating-point values in ymm1with writemask k1.

vcvtdq2ps ymm1 {k1} {z}, ymm2
vcvtdq2ps ymm1, [rax]

; Convert sixteen packed signed doubleword integers from zmm2/m512/m32bcst to sixteen packed single-precision floating-point values in zmm1with writemask k1.

vcvtdq2ps zmm1 {k1} {z}, zmm2
vcvtdq2ps zmm1, [rax]

; Move aligned packed doubleword integer values from xmm2/m128 to xmm1 using writemask k1.

vmovdqa xmm1, xmm2
vmovdqa xmm1, [rax]

; Move aligned packed doubleword integer values from ymm2/m256 to ymm1 using writemask k1.

vmovdqa ymm1, ymm2
vmovdqa ymm1, [rax]

; Move aligned packed doubleword integer values from zmm2/m512 to zmm1 using writemask k1.

; vmovdqa zmm1, zmm2 ; TODO: DOES NOT COMPILE
; vmovdqa zmm1, [rax]

; Move aligned packed doubleword integer values from xmm1 to xmm2/m128 using writemask k1.

vmovdqa [rax], xmm1

; Move aligned packed doubleword integer values from ymm1 to ymm2/m256 using writemask k1.

vmovdqa [rax], ymm1

; Move aligned packed doubleword integer values from zmm1 to zmm2/m512 using writemask k1.

; vmovdqa [rax], zmm1 ; TODO: DOESNOT COMPILE

; Move aligned packed doubleword integer values from xmm2/m128 to xmm1 using writemask k1.

vmovdqa32 xmm1, xmm2
vmovdqa32 xmm1, [rax]

; Move aligned packed doubleword integer values from ymm2/m256 to ymm1 using writemask k1.

vmovdqa32 ymm1, ymm2
vmovdqa32 ymm1, [rax]

; Move aligned packed doubleword integer values from zmm2/m512 to zmm1 using writemask k1.

vmovdqa32 zmm1, zmm2
vmovdqa32 zmm1, [rax]

; Move aligned packed doubleword integer values from xmm1 to xmm2/m128 using writemask k1.

vmovdqa32 [rax], xmm1

; Move aligned packed doubleword integer values from ymm1 to ymm2/m256 using writemask k1.

vmovdqa32 [rax], ymm1

; Move aligned packed doubleword integer values from zmm1 to zmm2/m512 using writemask k1.

vmovdqa32 [rax], zmm1

; Move aligned packed doubleword integer values from xmm2/m128 to xmm1 using writemask k1.

vmovdqa64 xmm1, xmm2
vmovdqa64 xmm1, [rax]

; Move aligned packed doubleword integer values from ymm2/m256 to ymm1 using writemask k1.

vmovdqa64 ymm1, ymm2
vmovdqa64 ymm1, [rax]

; Move aligned packed doubleword integer values from zmm2/m512 to zmm1 using writemask k1.

vmovdqa64 zmm1, zmm2
vmovdqa64 zmm1, [rax]

; Move aligned packed doubleword integer values from xmm1 to xmm2/m128 using writemask k1.

vmovdqa64 [rax], xmm1

; Move aligned packed doubleword integer values from ymm1 to ymm2/m256 using writemask k1.

vmovdqa64 [rax], ymm1

; Move aligned packed doubleword integer values from zmm1 to zmm2/m512 using writemask k1.

vmovdqa64 [rax], zmm1

; Move unaligned packed doubleword integer values from xmm2/m128 to xmm1 using writemask k1.

vmovdqu xmm1, xmm2
vmovdqu xmm1, [rax]

; Move unaligned packed doubleword integer values from ymm2/m256 to ymm1 using writemask k1.

vmovdqu ymm1, ymm2
vmovdqu ymm1, [rax]

; Move unaligned packed doubleword integer values from zmm2/m512 to zmm1 using writemask k1.

; vmovdqu zmm1, zmm2 ; TODO: DOES NOT COMPILE
; vmovdqu zmm1, [rax]

; Move unaligned packed doubleword integer values from xmm1 to xmm2/m128 using writemask k1.

vmovdqu [rax], xmm1

; Move unaligned packed doubleword integer values from ymm1 to ymm2/m256 using writemask k1.

vmovdqu [rax], ymm1

; Move unaligned packed doubleword integer values from zmm1 to zmm2/m512 using writemask k1.

; vmovdqu [rax], zmm1 ; TODO: DOESNOT COMPILE

; Move unaligned packed doubleword integer values from xmm2/m128 to xmm1 using writemask k1.

vmovdqu32 xmm1, xmm2
vmovdqu32 xmm1, [rax]

; Move unaligned packed doubleword integer values from ymm2/m256 to ymm1 using writemask k1.

vmovdqu32 ymm1, ymm2
vmovdqu32 ymm1, [rax]

; Move unaligned packed doubleword integer values from zmm2/m512 to zmm1 using writemask k1.

vmovdqu32 zmm1, zmm2
vmovdqu32 zmm1, [rax]

; Move unaligned packed doubleword integer values from xmm1 to xmm2/m128 using writemask k1.

vmovdqu32 [rax], xmm1

; Move unaligned packed doubleword integer values from ymm1 to ymm2/m256 using writemask k1.

vmovdqu32 [rax], ymm1

; Move unaligned packed doubleword integer values from zmm1 to zmm2/m512 using writemask k1.

vmovdqu32 [rax], zmm1

; Move unaligned packed doubleword integer values from xmm2/m128 to xmm1 using writemask k1.

vmovdqu64 xmm1, xmm2
vmovdqu64 xmm1, [rax]

; Move unaligned packed doubleword integer values from ymm2/m256 to ymm1 using writemask k1.

vmovdqu64 ymm1, ymm2
vmovdqu64 ymm1, [rax]

; Move unaligned packed doubleword integer values from zmm2/m512 to zmm1 using writemask k1.

vmovdqu64 zmm1, zmm2
vmovdqu64 zmm1, [rax]

; Move unaligned packed doubleword integer values from xmm1 to xmm2/m128 using writemask k1.

vmovdqu64 [rax], xmm1

; Move unaligned packed doubleword integer values from ymm1 to ymm2/m256 using writemask k1.

vmovdqu64 [rax], ymm1

; Move unaligned packed doubleword integer values from zmm1 to zmm2/m512 using writemask k1.

vmovdqu64 [rax], zmm1

; Subtract packed quadword integers in xmm3/m128/m64bcst from xmm2 and store in xmm1 using writemask k1.
; TODO: 'm64bcst' possible second argument

vpsubq xmm1 {k1} {z}, xmm2
vpsubq xmm1 {k1} {z}, [rax]

; Subtract packed quadword integers in ymm3/m256/m64bcst from ymm2 and store in ymm1 using writemask k1.
; TODO: 'm64bcst' possible second argument

vpsubq ymm1 {k1} {z}, ymm2
vpsubq ymm1 {k1} {z}, [rax]

; Subtract packed quadword integers in zmm3/m512/m64bcst from zmm2 and store in zmm1 using writemask k1.
; TODO: 'm64bcst' possible second argument

vpsubq zmm1 {k1} {z}, zmm2
vpsubq zmm1 {k1} {z}, [rax]

; Multiply packed unsigned doubleword integers in xmm2 by packed unsigned doubleword integers in xmm3/m128/m64bcst, and store the quadword results in xmm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpmuldq xmm1 {k1} {z}, xmm2, xmm3
vpmuldq xmm1 {k1} {z}, xmm2, [rax]

; Multiply packed unsigned doubleword integers in ymm2 by packed unsigned doubleword integers in ymm3/m256/m64bcst, and store the quadword results in ymm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpmuldq ymm1 {k1} {z}, ymm2, ymm3
vpmuldq ymm1 {k1} {z}, ymm2, [rax]

; Multiply packed unsigned doubleword integers in zmm2 by packed unsigned doubleword integers in zmm3/m512/m64bcst, and store the quadword results in zmm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpmuldq zmm1 {k1} {z}, zmm2, zmm3
vpmuldq zmm1 {k1} {z}, zmm2, [rax]

; Shuffle the low words in xmm2/m128 based on the encoding in imm8 and store the result in xmm1 under write mask k1.

vpshuflw xmm1 {k1} {z}, xmm2, 0x69
vpshuflw xmm2 {k1} {z}, [rax], 0x69

; Shuffle the low words in ymm2/m256 based on the encoding in imm8 and store the result in ymm1 under write mask k1.

vpshuflw ymm1 {k1} {z}, ymm2, 0x69
vpshuflw ymm2 {k1} {z}, [rax], 0x69

; Shuffle the low words in zmm2/m512 based on the encoding in imm8 and store the result in zmm1 under write mask k1.

vpshuflw zmm1 {k1} {z}, zmm2, 0x69
vpshuflw zmm2 {k1} {z}, [rax], 0x69

; Shuffle the high words in xmm2/m128 based on the encoding in imm8 and store the result in xmm1 under write mask k1.

vpshufhw xmm1 {k1} {z}, xmm2, 0x69
vpshufhw xmm2 {k1} {z}, [rax], 0x69

; Shuffle the high words in ymm2/m256 based on the encoding in imm8 and store the result in ymm1 under write mask k1.

vpshufhw ymm1 {k1} {z}, ymm2, 0x69
vpshufhw ymm2 {k1} {z}, [rax], 0x69

; Shuffle the high words in zmm2/m512 based on the encoding in imm8 and store the result in zmm1 under write mask k1.

vpshufhw zmm1 {k1} {z}, zmm2, 0x69
vpshufhw zmm2 {k1} {z}, [rax], 0x69

; Shuffle the doublewords in xmm2/m128/m32bcst based on the encoding in imm8 and store the result in xmm1 using writemask k1.
; TODO: 'm32bcst' possible second argument

vpshufd xmm1 {k1} {z}, xmm2, 0x69
vpshufd xmm2 {k1} {z}, [rax], 0x69

; Shuffle the doublewords in ymm2/m256/m32bcst based on the encoding in imm8 and store the result in ymm1 using writemask k1.
; TODO: 'm32bcst' possible second argument

vpshufd ymm1 {k1} {z}, ymm2, 0x69
vpshufd ymm2 {k1} {z}, [rax], 0x69

; Shuffle the doublewords in zmm2/m512/m32bcst based on the encoding in imm8 and store the result in zmm1 using writemask k1.
; TODO: 'm32bcst' possible second argument

vpshufd zmm1 {k1} {z}, zmm2, 0x69
vpshufd zmm2 {k1} {z}, [rax], 0x69

; Shift xmm2/m128 left by imm8 bytes while shifting in 0s and store result in xmm1.

vpslldq xmm1, xmm2, 0x69
vpslldq xmm2, [rax], 0x69

; Shift ymm2/m256 left by imm8 bytes while shifting in 0s and store result in ymm1.

vpslldq ymm1, ymm2, 0x69
vpslldq ymm2, [rax], 0x69

; Shift zmm2/m512 left by imm8 bytes while shifting in 0s and store result in zmm1.

vpsrldq zmm1, zmm2, 0x69
vpsrldq zmm2, [rax], 0x69

; Shift xmm2/m128 right by imm8 bytes while shifting in 0s and store result in xmm1.

vpsrldq xmm1, xmm2, 0x69
vpsrldq xmm2, [rax], 0x69

; Shift ymm2/m256 right by imm8 bytes while shifting in 0s and store result in ymm1.

vpsrldq ymm1, ymm2, 0x69
vpsrldq ymm2, [rax], 0x69

; Shift zmm2/m512 right by imm8 bytes while shifting in 0s and store result in zmm1.

vpsrldq zmm1, zmm2, 0x69
vpsrldq zmm2, [rax], 0x69

; Move packed integer values in xmm1 to m128 using non-temporal hint.

vmovntdq [rax], xmm1

; Move packed integer values in ymm1 to m256 using non-temporal hint.

vmovntdq [rax], ymm1

; Move packed integer values in zmm1 to m512 using non-temporal hint.

vmovntdq [rax], zmm1

; Move packed double-precision values in xmm1 to m128 using non-temporal hint.

vmovntpd [rax], xmm1

; Move packed double-precision values in ymm1 to m256 using non-temporal hint.

vmovntpd [rax], ymm1

; Move packed double-precision values in zmm1 to m512 using non-temporal hint.

vmovntpd [rax], zmm1

; Move odd index single-precision floating-point values from xmm2/m128 and duplicate each element into xmm1 under writemask.

vmovshdup xmm1 {k1} {z}, xmm2
vmovshdup xmm1 {k1} {z}, [rax]

; Move odd index single-precision floating-point values from ymm2/m256 and duplicate each element into ymm1 under writemask.

vmovshdup ymm1 {k1} {z}, ymm2
vmovshdup ymm1 {k1} {z}, [rax]

; Move odd index single-precision floating-point values from zmm2/m512 and duplicate each element into zmm1 under writemask.

vmovshdup zmm1 {k1} {z}, zmm2
vmovshdup zmm1 {k1} {z}, [rax]

; Move even index single-precision floating-point values from xmm2/m128 and duplicate each element into xmm1 under writemask.

vmovsldup xmm1 {k1} {z}, xmm2
vmovsldup xmm1 {k1} {z}, [rax]

; Move even index single-precision floating-point values from ymm2/m256 and duplicate each element into ymm1 under writemask.

vmovsldup ymm1 {k1} {z}, ymm2
vmovsldup ymm1 {k1} {z}, [rax]

; Move even index single-precision floating-point values from zmm2/m512 and duplicate each element into zmm1 under writemask.

vmovsldup zmm1 {k1} {z}, zmm2
vmovsldup zmm1 {k1} {z}, [rax]

; Move double-precision floating-point value from xmm2/m64 and duplicate each element into xmm1 subject to writemask k1.

vmovddup xmm1 {k1} {z}, xmm2
vmovddup xmm1 {k1} {z}, [rax]

; Move even index double-precision floating-point values from ymm2/m256 and duplicate each element into ymm1 subject to writemask k1.

vmovddup ymm1 {k1} {z}, ymm2
vmovddup ymm1 {k1} {z}, [rax]

; Move even index double-precision floating-point values from zmm2/m512 and duplicate each element into zmm1 subject to writemask k1.

vmovddup zmm1 {k1} {z}, zmm2
vmovddup zmm1 {k1} {z}, [rax]

; Compute the absolute value of bytes in xmm2/m128 and store UNSIGNED result in xmm1 using writemask k1.

vpabsb xmm1 {k1} {z}, xmm2
vpabsb xmm1 {k1} {z}, [rax]

; Compute the absolute value of bytes in ymm2/m256 and store UNSIGNED result in ymm1 using writemask k1.

vpabsb ymm1 {k1} {z}, ymm2
vpabsb ymm1 {k1} {z}, [rax]

; Compute the absolute value of bytes in zmm2/m512 and store UNSIGNED result in zmm1 using writemask k1.

vpabsb zmm1 {k1} {z}, zmm2
vpabsb zmm1 {k1} {z}, [rax]

; Compute the absolute value of 16-bit integers in xmm2/m128 and store UNSIGNED result in xmm1 using writemask k1.

vpabsw xmm1 {k1} {z}, xmm2
vpabsw xmm1 {k1} {z}, [rax]

; Compute the absolute value of 16-bit integers in ymm2/m256 and store UNSIGNED result in ymm1 using writemask k1.

vpabsw ymm1 {k1} {z}, ymm2
vpabsw ymm1 {k1} {z}, [rax]

; Compute the absolute value of 16-bit integers in zmm2/m512 and store UNSIGNED result in zmm1 using writemask k1.

vpabsw zmm1 {k1} {z}, zmm2
vpabsw zmm1 {k1} {z}, [rax]

; Compute the absolute value of 32-bit integers in xmm2/m128/m32bcst and store UNSIGNED result in xmm1 using writemask k1.

vpabsd xmm1 {k1} {z}, xmm2
vpabsd xmm1 {k1} {z}, [rax]

; Compute the absolute value of 32-bit integers in ymm2/m256/m32bcst and store UNSIGNED result in ymm1 using writemask k1.

vpabsd ymm1 {k1} {z}, ymm2
vpabsd ymm1 {k1} {z}, [rax]

; Compute the absolute value of 32-bit integers in zmm2/m512/m32bcst and store UNSIGNED result in zmm1 using writemask k1.

vpabsd zmm1 {k1} {z}, zmm2
vpabsd zmm1 {k1} {z}, [rax]

; Compute the absolute value of 64-bit integers in xmm2/m128/m64bcst and store UNSIGNED result in xmm1 using writemask k1.

vpabsq xmm1 {k1} {z}, xmm2
vpabsq xmm1 {k1} {z}, [rax]

; Compute the absolute value of 64-bit integers in ymm2/m256/m64bcst and store UNSIGNED result in ymm1 using writemask k1.

vpabsq ymm1 {k1} {z}, ymm2
vpabsq ymm1 {k1} {z}, [rax]

; Compute the absolute value of 64-bit integers in zmm2/m512/m64bcst and store UNSIGNED result in zmm1 using writemask k1.

vpabsq zmm1 {k1} {z}, zmm2
vpabsq zmm1 {k1} {z}, [rax]

; Multiply signed and unsigned bytes, add horizontal pair of signed words, pack saturated signed-words to xmm1 under writemask k1.

vpmaddubsw xmm1 {k1} {z}, xmm2, xmm3
vpmaddubsw xmm1 {k1} {z}, xmm2, [rax]

; Multiply signed and unsigned bytes, add horizontal pair of signed words, pack saturated signed-words to ymm1 under writemask k1.

vpmaddubsw ymm1 {k1} {z}, ymm2, ymm3
vpmaddubsw ymm1 {k1} {z}, ymm2, [rax]

; Multiply signed and unsigned bytes, add horizontal pair of signed words, pack saturated signed-words to zmm1 under writemask k1.

vpmaddubsw zmm1 {k1} {z}, zmm2, zmm3
vpmaddubsw zmm1 {k1} {z}, zmm2, [rax]

; Multiply 16-bit signed words, scale and round signed doublewords, pack high 16 bits to xmm1 under writemask k1.

vpmulhrsw xmm1 {k1} {z}, xmm2, xmm3
vpmulhrsw xmm1 {k1} {z}, xmm2, [rax]

; Multiply 16-bit signed words, scale and round signed doublewords, pack high 16 bits to ymm1 under writemask k1.

vpmulhrsw ymm1 {k1} {z}, ymm2, ymm3
vpmulhrsw ymm1 {k1} {z}, ymm2, [rax]

; Multiply 16-bit signed words, scale and round signed doublewords, pack high 16 bits to zmm1 under writemask k1.

vpmulhrsw zmm1 {k1} {z}, zmm2, zmm3
vpmulhrsw zmm1 {k1} {z}, zmm2, [rax]

; Shuffle bytes in xmm2 according to contents of xmm3/m128 under write mask k1.

vpshufb xmm1 {k1} {z}, xmm2, xmm3
vpshufb xmm1 {k1} {z}, xmm2, [rax]

; Shuffle bytes in ymm2 according to contents of ymm3/m256 under write mask k1.

vpshufb ymm1 {k1} {z}, ymm2, ymm3
vpshufb ymm1 {k1} {z}, ymm2, [rax]

; Shuffle bytes in zmm2 according to contents of zmm3/m512 under write mask k1.

vpshufb zmm1 {k1} {z}, zmm2, zmm3
vpshufb zmm1 {k1} {z}, zmm2, [rax]

; Concatenate xmm2 and xmm3/m128 into a 32-byte intermediate result, extract byte aligned result shifted to the right by constant value in imm8 and result is stored in xmm1.

vpalignr xmm1 {k1} {z}, xmm2, xmm3, 0x69
vpalignr xmm1 {k1} {z}, xmm2, [rax], 0x69

; Concatenate pairs of 16 bytes in ymm2 and ymm3/m256 into 32-byte intermediate result, extract byte-aligned, 16-byte result shifted to the right by constant values in imm8 from each intermediate result, and two 16-byte results are stored in ymm1.

vpalignr ymm1 {k1} {z}, ymm2, ymm3, 0x69
vpalignr ymm1 {k1} {z}, ymm2, [rax], 0x69

; Concatenate pairs of 16 bytes in zmm2 and zmm3/m512 into 32-byte intermediate result, extract byte-aligned, 16-byte result shifted to the right by constant values in imm8 from each intermediate result, and four 16-byte results are stored in zmm1.

vpalignr zmm1 {k1} {z}, zmm2, zmm3, 0x69
vpalignr zmm1 {k1} {z}, zmm2, [rax], 0x69

; Multiply the packed dword signed integers in xmm2 and xmm3/m128/m32bcst and store the low 32 bits of each product in xmm1 under writemask k1.
; TODO: 'm32bcst' possible third argument

vpmulld xmm1 {k1} {z}, xmm2, xmm3
vpmulld xmm1 {k1} {z}, xmm2, [rax]

; Multiply the packed dword signed integers in ymm2 and ymm3/m256/m32bcst and store the low 32 bits of each product in ymm1 under writemask k1.
; TODO: 'm32bcst' possible third argument

vpmulld ymm1 {k1} {z}, ymm2, ymm3
vpmulld ymm1 {k1} {z}, ymm2, [rax]

; Multiply the packed dword signed integers in zmm2 and zmm3/m512/m32bcst and store the low 32 bits of each product in zmm1 under writemask k1.
; TODO: 'm32bcst' possible third argument

vpmulld ymm1 {k1} {z}, ymm2, ymm3
vpmulld ymm1 {k1} {z}, ymm2, [rax]

; Multiply the packed qword signed integers in xmm2 and xmm3/m128/m64bcst and store the low 64 bits of each product in xmm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpmullq xmm1 {k1} {z}, xmm2, xmm3
vpmullq xmm1 {k1} {z}, xmm2, [rax]

; Multiply the packed qword signed integers in ymm2 and ymm3/m256/m64bcst and store the low 64 bits of each product in ymm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpmullq ymm1 {k1} {z}, ymm2, ymm3
vpmullq ymm1 {k1} {z}, ymm2, [rax]

; Multiply the packed qword signed integers in zmm2 and zmm3/m512/m64bcst and store the low 64 bits of each product in zmm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpmullq zmm1 {k1} {z}, zmm2, zmm3
vpmullq zmm1 {k1} {z}, zmm2, [rax]

; Multiply packed signed doubleword integers in xmm2 by packed signed doubleword integers in xmm3/m128/m64bcst, and store the quadword results in xmm1 using writemask k1.

vpmuldq xmm1 {k1} {z}, xmm2, xmm3
vpmuldq xmm1 {k1} {z}, xmm2, [rax]

; Multiply packed signed doubleword integers in ymm2 by packed signed doubleword integers in ymm3/m256/m64bcst, and store the quadword results in ymm1 using writemask k1.

vpmuldq ymm1 {k1} {z}, ymm2, ymm3
vpmuldq ymm1 {k1} {z}, ymm2, [rax]

; Multiply packed signed doubleword integers in zmm2 by packed signed doubleword integers in zmm3/m512/m64bcst, and store the quadword results in zmm1 using writemask k1.

vpmuldq zmm1 {k1} {z}, zmm2, zmm3
vpmuldq zmm1 {k1} {z}, zmm2, [rax]

; Move 128-bit data from m128 to xmm using non-temporal hint if WC memory type.

vmovntdqa xmm1, [rax]

; Move 256-bit data from m256 to ymm using non-temporal hint if WC memory type.

vmovntdqa ymm1, [rax]

; Move 512-bit data from m512 to zmm using non-temporal hint if WC memory type.

vmovntdqa zmm1, [rax]

; Compare packed unsigned dword integers in xmm2 and xmm3/m128/m32bcst and store packed minimum values in xmm1 under writemask k1.
; TODO: 'm32bcst' possible third argument

vpminud xmm1 {k1} {z}, xmm2, xmm3
vpminud xmm1 {k1} {z}, xmm2, [rax]

; Compare packed unsigned dword integers in ymm2 and ymm3/m256/m32bcst and store packed minimum values in ymm1 under writemask k1.
; TODO: 'm32bcst' possible third argument

vpminud ymm1 {k1} {z}, ymm2, ymm3
vpminud ymm1 {k1} {z}, ymm2, [rax]

; Compare packed unsigned dword integers in zmm2 and zmm3/m512/m32bcst and store packed minimum values in zmm1 under writemask k1.
; TODO: 'm32bcst' possible third argument

vpminud zmm1 {k1} {z}, zmm2, zmm3
vpminud zmm1 {k1} {z}, zmm2, [rax]

; Compare packed unsigned qword integers in xmm2 and xmm3/m128/m64bcst and store packed minimum values in xmm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpminuq xmm1 {k1} {z}, xmm2, xmm3
vpminuq xmm1 {k1} {z}, xmm2, [rax]


; Compare packed unsigned qword integers in ymm2 and ymm3/m256/m64bcst and store packed minimum values in ymm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpminuq ymm1 {k1} {z}, ymm2, ymm3
vpminuq ymm1 {k1} {z}, ymm2, [rax]

; Compare packed unsigned qword integers in zmm2 and zmm3/m512/m64bcst and store packed minimum values in zmm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpminuq zmm1 {k1} {z}, zmm2, zmm3
vpminuq zmm1 {k1} {z}, zmm2, [rax]

; Compare packed signed dword integers in xmm2 and xmm3/m128 and store packed minimum values in xmm1 under writemask k1.
; TODO: 'm32bcst' possible third argument

vpminsd xmm1 {k1} {z}, xmm2, xmm3
vpminsd xmm1 {k1} {z}, xmm2, [rax]

; Compare packed signed dword integers in ymm2 and ymm3/m256 and store packed minimum values in ymm1 under writemask k1.
; TODO: 'm32bcst' possible third argument

vpminsd ymm1 {k1} {z}, ymm2, ymm3
vpminsd ymm1 {k1} {z}, ymm2, [rax]

; Compare packed signed dword integers in zmm2 and zmm3/m512/m32bcst and store packed minimum values in zmm1 under writemask k1.
; TODO: 'm32bcst' possible third argument

vpminsd zmm1 {k1} {z}, zmm2, zmm3
vpminsd zmm1 {k1} {z}, zmm2, [rax]

; Compare packed signed qword integers in xmm2 and xmm3/m128 and store packed minimum values in xmm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpminsq xmm1 {k1} {z}, xmm2, xmm3
vpminsq xmm1 {k1} {z}, xmm2, [rax]

; Compare packed signed qword integers in ymm2 and ymm3/m256 and store packed minimum values in ymm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpminsq ymm1 {k1} {z}, ymm2, ymm3
vpminsq ymm1 {k1} {z}, ymm2, [rax]

; Compare packed signed qword integers in zmm2 and zmm3/m512/m64bcst and store packed minimum values in zmm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpminsq zmm1 {k1} {z}, zmm2, zmm3
vpminsq zmm1 {k1} {z}, zmm2, [rax]






; Compare packed unsigned dword integers in xmm2 and xmm3/m128/m32bcst and store packed maximum values in xmm1 under writemask k1.
; TODO: 'm32bcst' possible third argument

vpmaxud xmm1 {k1} {z}, xmm2, xmm3
vpmaxud xmm1 {k1} {z}, xmm2, [rax]

; Compare packed unsigned dword integers in ymm2 and ymm3/m256/m32bcst and store packed maximum values in ymm1 under writemask k1.
; TODO: 'm32bcst' possible third argument

vpmaxud ymm1 {k1} {z}, ymm2, ymm3
vpmaxud ymm1 {k1} {z}, ymm2, [rax]

; Compare packed unsigned dword integers in zmm2 and zmm3/m512/m32bcst and store packed maximum values in zmm1 under writemask k1.
; TODO: 'm32bcst' possible third argument

vpmaxud zmm1 {k1} {z}, zmm2, zmm3
vpmaxud zmm1 {k1} {z}, zmm2, [rax]

; Compare packed unsigned qword integers in xmm2 and xmm3/m128/m64bcst and store packed maximum values in xmm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpmaxuq xmm1 {k1} {z}, xmm2, xmm3
vpmaxuq xmm1 {k1} {z}, xmm2, [rax]


; Compare packed unsigned qword integers in ymm2 and ymm3/m256/m64bcst and store packed maximum values in ymm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpmaxuq ymm1 {k1} {z}, ymm2, ymm3
vpmaxuq ymm1 {k1} {z}, ymm2, [rax]

; Compare packed unsigned qword integers in zmm2 and zmm3/m512/m64bcst and store packed maximum values in zmm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpmaxuq zmm1 {k1} {z}, zmm2, zmm3
vpmaxuq zmm1 {k1} {z}, zmm2, [rax]

; Compare packed signed dword integers in xmm2 and xmm3/m128 and store packed maximum values in xmm1 under writemask k1.
; TODO: 'm32bcst' possible third argument

vpmaxsd xmm1 {k1} {z}, xmm2, xmm3
vpmaxsd xmm1 {k1} {z}, xmm2, [rax]

; Compare packed signed dword integers in ymm2 and ymm3/m256 and store packed maximum values in ymm1 under writemask k1.
; TODO: 'm32bcst' possible third argument

vpmaxsd ymm1 {k1} {z}, ymm2, ymm3
vpmaxsd ymm1 {k1} {z}, ymm2, [rax]

; Compare packed signed dword integers in zmm2 and zmm3/m512/m32bcst and store packed maximum values in zmm1 under writemask k1.
; TODO: 'm32bcst' possible third argument

vpmaxsd zmm1 {k1} {z}, zmm2, zmm3
vpmaxsd zmm1 {k1} {z}, zmm2, [rax]

; Compare packed signed qword integers in xmm2 and xmm3/m128 and store packed maximum values in xmm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpmaxsq xmm1 {k1} {z}, xmm2, xmm3
vpmaxsq xmm1 {k1} {z}, xmm2, [rax]

; Compare packed signed qword integers in ymm2 and ymm3/m256 and store packed maximum values in ymm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpmaxsq ymm1 {k1} {z}, ymm2, ymm3
vpmaxsq ymm1 {k1} {z}, ymm2, [rax]

; Compare packed signed qword integers in zmm2 and zmm3/m512/m64bcst and store packed maximum values in zmm1 under writemask k1.
; TODO: 'm64bcst' possible third argument

vpmaxsq zmm1 {k1} {z}, zmm2, zmm3
vpmaxsq zmm1 {k1} {z}, zmm2, [rax]

; Extract one single-precision floating-point value from xmm1 at the offset specified by imm8 and store the result in reg or m32. Zero extend the results in 64-bit register if applicable.

vextractps eax, xmm1, 0x69
vextractps DWORD [rax], xmm1, 0x69

; Insert a single-precision floating-point value selected by imm8 from xmm3/m32 and merge with values in xmm2 at the specified destination element specified by imm8 and write out the result and zero out destination elements in xmm1 as indicated in imm8.

vinsertps xmm1, xmm2, xmm3, 0x69
vinsertps xmm1, xmm2, DWORD [rax], 0x69

; Merge a byte integer value from r32/m8 and rest from xmm2 into xmm1 at the byte offset in imm8.

vpinsrb xmm1, xmm2, eax, 0x69
vpinsrb xmm1, xmm2, BYTE [rax], 0x69

; Insert a dword integer value from r32/m32 and rest from xmm2 into xmm1 at the dword offset in imm8.

vpinsrd xmm1, xmm2, eax, 0x69
vpinsrd xmm1, xmm2, DWORD [rax], 0x69

; Insert a qword integer value from r64/m64 and rest from xmm2 into xmm1 at the qword offset in imm8.

vpinsrq xmm1, xmm2, rax, 0x69
vpinsrq xmm1, xmm2, QWORD [rax], 0x69

; Extract a byte integer value from xmm2 at the source byte offset specified by imm8 into reg or m8. The upper bits of r64/r32 is filled with zeros.

vpextrb eax, xmm2, 0x69
vpextrb BYTE [rax], xmm2, 0x69

; Extract a dword integer value from xmm2 at the source dword offset specified by imm8 into r32/m32.

vpextrd eax, xmm2, 0x69
vpextrd DWORD [rax], xmm2, 0x69

; Extract a qword integer value from xmm2 at the source dword offset specified by imm8 into r64/m64.

vpextrq rax, xmm2, 0x69
vpextrq QWORD [rax], xmm2, 0x69

; Compare Equal between int64 vector xmm2 and int64 vector xmm3/m128/m64bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.
; TODO: 'm64bcst' possible third argument

vpcmpeqq k1 {k2}, xmm2, xmm3
vpcmpeqq k1 {k2}, xmm2, [rax]

; Compare Equal between int64 vector ymm2 and int64 vector ymm3/m256/m64bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.
; TODO: 'm64bcst' possible third argument

vpcmpeqq k1 {k2}, ymm2, ymm3
vpcmpeqq k1 {k2}, ymm2, [rax]

; Compare Equal between int64 vector zmm2 and int64 vector zmm3/m512/m64bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.
; TODO: 'm64bcst' possible third argument

vpcmpeqq k1 {k2}, zmm2, zmm3
vpcmpeqq k1 {k2}, zmm2, [rax]

; Convert packed signed doubleword integers from xmm2 and packed signed doubleword integers from xmm3/m128/m32bcst into packed unsigned word integers in xmm1 using unsigned saturation under writemask k1.
; TODO: 'm64bcst' possible third argument

vpackusdw xmm1 {k2}, xmm2, xmm3
vpackusdw xmm1 {k2}, xmm2, [rax]


; Convert packed signed doubleword integers from ymm2 and packed signed doubleword integers from ymm3/m256/m32bcst into packed unsigned word integers in ymm1 using unsigned saturation under writemask k1.
; TODO: 'm64bcst' possible third argument

vpackusdw ymm1 {k2}, ymm2, ymm3
vpackusdw ymm1 {k2}, ymm2, [rax]

; Convert packed signed doubleword integers from zmm2 and packed signed doubleword integers from zmm3/m512/m32bcst into packed unsigned word integers in zmm1 using unsigned saturation under writemask k1.
; TODO: 'm64bcst' possible third argument

vpackusdw zmm1 {k2}, zmm2, zmm3
vpackusdw zmm1 {k2}, zmm2, [rax]

; Compare Greater between int64 vector xmm2 and int64 vector xmm3/m128/m64bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.
; TODO: 'm64bcst' possible third argument

vpcmpgtq k1 {k2}, xmm2, xmm3
vpcmpgtq k1 {k2}, xmm2, [rax]

; Compare Greater between int64 vector ymm2 and int64 vector ymm3/m256/m64bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.
; TODO: 'm64bcst' possible third argument

vpcmpgtq k1 {k2}, ymm2, ymm3
vpcmpgtq k1 {k2}, ymm2, [rax]

; Compare Greater between int64 vector zmm2 and int64 vector zmm3/m512/m64bcst, and set vector mask k1 to reflect the zero/nonzero status of each element of the result, under writemask.
; TODO: 'm64bcst' possible third argument

vpcmpgtq k1 {k2}, zmm2, zmm3
vpcmpgtq k1 {k2}, zmm2, [rax]

; Broadcast low double-precision floating-point element in xmm2/m64 to four locations in ymm1 using writemask k1.

vbroadcastsd ymm1 {k1} {z}, xmm2
vbroadcastsd ymm1 {k1} {z}, [rax]

; Broadcast low double-precision floating-point element in xmm2/m64 to eight locations in zmm1 using writemask k1.

vbroadcastsd zmm1 {k1} {z}, xmm2
vbroadcastsd zmm1 {k1} {z}, [rax]

; Broadcast two single-precision floating-point elements in xmm2/m64 to locations in ymm1 using writemask k1.

vbroadcastf32x2 ymm1 {k1} {z}, xmm2
vbroadcastf32x2 ymm1 {k1} {z}, [rax]

; Broadcast two single-precision floating-point elements in xmm2/m64 to locations in zmm1 using writemask k1.

vbroadcastf32x2 zmm1 {k1} {z}, xmm2
vbroadcastf32x2 zmm1 {k1} {z}, [rax]

; Broadcast low single-precision floating-point element in xmm2/m32 to all locations in xmm1 using writemask k1.

vbroadcastss xmm1 {k1} {z}, xmm2
vbroadcastss xmm1 {k1} {z}, DWORD [rax]

; Broadcast low single-precision floating-point element in xmm2/m32 to all locations in ymm1 using writemask k1.

vbroadcastss ymm1 {k1} {z}, xmm2
vbroadcastss ymm1 {k1} {z}, DWORD [rax]

; Broadcast low single-precision floating-point element in xmm2/m32 to all locations in zmm1 using writemask k1.

vbroadcastss zmm1 {k1} {z}, xmm2
vbroadcastss zmm1 {k1} {z}, DWORD [rax]

; Broadcast 128 bits of 4 single-precision floating-point data in mem to locations in ymm1 using writemask k1.

vbroadcastf32x4 ymm1 {k1} {z}, [rax]

; Broadcast 128 bits of 4 single-precision floating-point data in mem to locations in zmm1 using writemask k1.

vbroadcastf32x4 zmm1 {k1} {z}, [rax]

; Broadcast 128 bits of 2 double-precision floating-point data in mem to locations in ymm1 using writemask k1.

vbroadcastf64x2 ymm1 {k1} {z}, [rax]

; Broadcast 128 bits of 2 double-precision floating-point data in mem to locations in zmm1 using writemask k1.

vbroadcastf64x2 zmm1 {k1} {z}, [rax]

; Broadcast 256 bits of 8 single-precision floating-point data in mem to locations in zmm1 using writemask k1.

vbroadcastf32x8 zmm1 {k1} {z}, [rax]

; Broadcast 256 bits of 4 double-precision floating-point data in mem to locations in zmm1 using writemask k1.

vbroadcastf64x4 zmm1 {k1} {z}, [rax]

; Insert 128 bits of packed single-precision floating-point values from xmm3/m128 and the remaining values from ymm2 into ymm1 under writemask k1.

vinsertf32x4 ymm1 {k1} {z}, ymm2, xmm3, 0x69
vinsertf32x4 ymm1 {k1} {z}, ymm2, [rax], 0x69

; Insert 128 bits of packed single-precision floating-point values from xmm3/m128 and the remaining values from zmm2 into zmm1 under writemask k1.

vinsertf32x4 zmm1 {k1} {z}, zmm2, xmm3, 0x69
vinsertf32x4 zmm1 {k1} {z}, zmm2, [rax], 0x69

; Insert 128 bits of packed double-precision floating-point values from xmm3/m128 and the remaining values from ymm2 into ymm1 under writemask k1.

vinsertf64x2 ymm1 {k1} {z}, ymm2, xmm3, 0x69
vinsertf64x2 ymm1 {k1} {z}, ymm2, [rax], 0x69

; Insert 128 bits of packed double-precision floating-point values from xmm3/m128 and the remaining values from zmm2 into zmm1 under writemask k1.

vinsertf64x2 zmm1 {k1} {z}, zmm2, xmm3, 0x69
vinsertf64x2 zmm1 {k1} {z}, zmm2, [rax], 0x69

; Insert 256 bits of packed single-precision floating-point values from ymm3/m256 and the remaining values from zmm2 into zmm1 under writemask k1.

vinsertf32x8 zmm1 {k1} {z}, zmm2, ymm3, 0x69
vinsertf32x8 zmm1 {k1} {z}, zmm2, [rax], 0x69

; Insert 256 bits of packed double-precision floating-point values from ymm3/m256 and the remaining values from zmm2 into zmm1 under writemask k1.

vinsertf64x4 zmm1 {k1} {z}, zmm2, ymm3, 0x69
vinsertf64x4 zmm1 {k1} {z}, zmm2, [rax], 0x69


; Permute single-precision floating-point values in xmm2 using control from xmm3/m128/m64bcst and store the result in xmm1 using writemask k1.
; TODO: 'm64bcst' possible third argument

vpermilps xmm1 {k1} {z}, xmm2, xmm3
vpermilps xmm1 {k1} {z}, xmm2, [rax]

; Permute single-precision floating-point values in ymm2 using control from ymm3/m256/m64bcst and store the result in ymm1 using writemask k1.
; TODO: 'm64bcst' possible third argument

vpermilps ymm1 {k1} {z}, ymm2, ymm3
vpermilps ymm1 {k1} {z}, ymm2, [rax]

; Permute single-precision floating-point values in zmm2 using control from zmm3/m512/m64bcst and store the result in zmm1 using writemask k1.
; TODO: 'm64bcst' possible third argument

vpermilps zmm1 {k1} {z}, zmm2, zmm3
vpermilps zmm1 {k1} {z}, zmm2, [rax]

; Permute single-precision floating-point values in xmm2/m128/m64bcst using controls from imm8 and store the result in xmm1 using writemask k1.
; TODO: 'm64bcst' possible second argument

vpermilps xmm1 {k1} {z}, xmm3, 0x69
vpermilps xmm1 {k1} {z}, [rax], 0x69

; Permute single-precision floating-point values in ymm2/m256/m64bcst using controls from imm8 and store the result in ymm1 using writemask k1.
; TODO: 'm64bcst' possible second argument

vpermilps ymm1 {k1} {z}, ymm3, 0x69
vpermilps ymm1 {k1} {z}, [rax], 0x69

; Permute single-precision floating-point values in zmm2/m512/m64bcst using controls from imm8 and store the result in zmm1 using writemask k1.
; TODO: 'm64bcst' possible second argument

vpermilps zmm1 {k1} {z}, zmm3, 0x69
vpermilps zmm1 {k1} {z}, [rax], 0x69

; Permute double-precision floating-point values in xmm2 using control from xmm3/m128/m64bcst and store the result in xmm1 using writemask k1.
; TODO: 'm64bcst' possible third argument

vpermilpd xmm1 {k1} {z}, xmm2, xmm3
vpermilpd xmm1 {k1} {z}, xmm2, [rax]

; Permute double-precision floating-point values in ymm2 using control from ymm3/m256/m64bcst and store the result in ymm1 using writemask k1.
; TODO: 'm64bcst' possible third argument

vpermilpd ymm1 {k1} {z}, ymm2, ymm3
vpermilpd ymm1 {k1} {z}, ymm2, [rax]

; Permute double-precision floating-point values in zmm2 using control from zmm3/m512/m64bcst and store the result in zmm1 using writemask k1.
; TODO: 'm64bcst' possible third argument

vpermilpd zmm1 {k1} {z}, zmm2, zmm3
vpermilpd zmm1 {k1} {z}, zmm2, [rax]

; Permute double-precision floating-point values in xmm2/m128/m64bcst using controls from imm8 and store the result in xmm1 using writemask k1.
; TODO: 'm64bcst' possible second argument

vpermilpd xmm1 {k1} {z}, xmm3, 0x69
vpermilpd xmm1 {k1} {z}, [rax], 0x69

; Permute double-precision floating-point values in ymm2/m256/m64bcst using controls from imm8 and store the result in ymm1 using writemask k1.
; TODO: 'm64bcst' possible second argument

vpermilpd ymm1 {k1} {z}, ymm3, 0x69
vpermilpd ymm1 {k1} {z}, [rax], 0x69

; Permute double-precision floating-point values in zmm2/m512/m64bcst using controls from imm8 and store the result in zmm1 using writemask k1.
; TODO: 'm64bcst' possible second argument

vpermilpd zmm1 {k1} {z}, zmm3, 0x69
vpermilpd zmm1 {k1} {z}, [rax], 0x69

; Convert four packed half precision (16-bit) floating-point values in xmm2/m64 to packed single-precision floating-point values in xmm1.

vcvtph2ps xmm1 {k1} {z}, xmm2
vcvtph2ps xmm1 {k1} {z}, [rax]

; Convert eight packed half precision (16-bit) floating-point values in xmm2/m128 to packed single-precision floating-point values in ymm1.

vcvtph2ps ymm1 {k1} {z}, xmm2
vcvtph2ps ymm1 {k1} {z}, [rax]

; Convert sixteen packed half precision (16-bit) floating-point values in ymm2/m256 to packed single-precision floating-point values in zmm1.

vcvtph2ps zmm1 {k1} {z}, ymm2
vcvtph2ps zmm1 {k1} {z}, [rax]

; Convert four packed single-precision floating-point values in xmm2 to packed half-precision (16-bit) floating-point values in xmm1/m64. Imm8 provides rounding controls.

vcvtps2ph xmm1 {k1} {z}, xmm2, 0x69
vcvtps2ph [rax], xmm2, 0x69

; Convert eight packed single-precision floating-point values in ymm2 to packed half-precision (16-bit) floating-point values in xmm1/m128. Imm8 provides rounding controls.

vcvtps2ph xmm1 {k1} {z}, ymm2, 0x69
vcvtps2ph [rax], ymm2, 0x69

; Convert sixteen packed single-precision floating-point values in zmm2 to packed half-precision (16-bit) floating-point values in ymm1/m256. Imm8 provides rounding controls.

vcvtps2ph ymm1 {k1} {z}, zmm2, 0x69
vcvtps2ph [rax], zmm2, 0x69


