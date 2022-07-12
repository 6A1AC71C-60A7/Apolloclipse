
; NOTE: Fused Multiply-Add is skiped (see FMA)

; Add packed byte integers from xmm2, and xmm3/m128 and store in xmm1 using writemask k1.

vpaddb xmm31 {k1}, xmm30, xmm29
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
vpaddb zmm4 {k1}, zmm31, [r12]
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

; Permute doublewords in ymm3/m256/m32bcst using indexes in ymm2 and store the result in ymm1 using writemask k1.
; TODO: 'm64bcst' third argument

vpermd ymm1 {k1} {z}, ymm2, ymm3
vpermd ymm1 {k1} {z}, ymm2, [rax]

; Permute doublewords in zmm3/m512/m32bcst using indices in zmm2 and store the result in zmm1 using writemask k1.
; TODO: 'm64bcst' third argument

vpermd zmm1 {k1} {z}, zmm2, zmm3
vpermd zmm1 {k1} {z}, zmm2, [rax]

; Permute word integers in xmm3/m128 using indexes in xmm2 and store the result in xmm1 using writemask k1.

vpermw xmm1 {k1} {z}, xmm2, xmm3
vpermw xmm1 {k1} {z}, xmm2, [rax]

; Permute word integers in ymm3/m256 using indexes in ymm2 and store the result in ymm1 using writemask k1.

vpermw ymm1 {k1} {z}, ymm2, ymm3
vpermw ymm1 {k1} {z}, ymm2, [rax]

; Permute word integers in zmm3/m512 using indexes in zmm2 and store the result in zmm1 using writemask k1.

vpermw zmm1 {k1} {z}, zmm2, zmm3
vpermw zmm1 {k1} {z}, zmm2, [rax]

; Permute single-precision floating-point elements in ymm3/m256/m64bcst using indexes in ymm2 and store the result in ymm1 subject to writemask k1.
; TODO: 'm64bcst' third argument

vpermps ymm1 {k1} {z}, ymm2, ymm3
vpermps ymm1 {k1} {z}, ymm2, [rax]

; Permute single-precision floating-point elements in zmm3/m512/m64bcst using indices in zmm2 and store the result in zmm1 subject to writemask k1.
; TODO: 'm64bcst' third argument

vpermps zmm1 {k1} {z}, zmm2, zmm3
vpermps zmm1 {k1} {z}, zmm2, [rax]

; Permute double-precision floating-point elements in ymm2/m256/m64bcst using indexes in imm8 and store the result in ymm1 subject to writemask k1.
; TODO: 'm64bcst' second argument

vpermpd ymm1 {k1} {z}, ymm2, 0x69
vpermpd ymm1 {k1} {z}, [rax], 0x69

; Permute double-precision floating-point elements in zmm2/m512/m64bcst using indices in imm8 and store the result in zmm1 subject to writemask k1.
; TODO: 'm64bcst' second argument

vpermpd zmm1 {k1} {z}, zmm2, 0x69
vpermpd zmm1 {k1} {z}, [rax], 0x69

; Permute double-precision floating-point elements in ymm3/m256/m64bcst using indexes in ymm2 and store the result in ymm1 subject to writemask k1.
; TODO: 'm64bcst' third argument

vpermpd ymm1 {k1} {z}, ymm2, ymm3
vpermpd ymm1 {k1} {z}, ymm2, [rax]

; Permute double-precision floating-point elements in zmm3/m512/m64bcst using indices in zmm2 and store the result in zmm1 subject to writemask k1.
; TODO: 'm64bcst' third argument

vpermpd zmm1 {k1} {z}, zmm2, zmm3
vpermpd zmm1 {k1} {z}, zmm2, [rax]

; Permute qwords in ymm2/m256/m64bcst using indexes in imm8 and store the result in ymm1.

vpermq ymm1 {k1} {z}, ymm2, 0x69
vpermq ymm1 {k1} {z}, [rax], 0x69

; Permute qwords in zmm2/m512/m64bcst using indices in imm8 and store the result in zmm1.

vpermq zmm1 {k1} {z}, zmm2, 0x69
vpermq zmm1 {k1} {z}, [rax], 0x69

; Permute qwords in ymm3/m256/m64bcst using indexes in ymm2 and store the result in ymm1.

vpermq ymm1 {k1} {z}, ymm2, ymm3
vpermq ymm1 {k1} {z}, ymm2, [rax]

; Permute qwords in zmm3/m512/m64bcst using indices in zmm2 and store the result in zmm1.

vpermq zmm1 {k1} {z}, zmm2, zmm3
vpermq zmm1 {k1} {z}, zmm2, [rax]

; Shift words in xmm2 left by amount specified in the corresponding element of xmm3/m128 while shifting in 0s using writemask k1.

vpsllvw xmm1 {k1} {z}, xmm2, xmm3
vpsllvw xmm1 {k1} {z}, xmm2, [rax]

; Shift words in ymm2 left by amount specified in the corresponding element of ymm3/m256 while shifting in 0s using writemask k1.

vpsllvw ymm1 {k1} {z}, ymm2, ymm3
vpsllvw ymm1 {k1} {z}, ymm2, [rax]

; Shift words in zmm2 left by amount specified in the corresponding element of zmm3/m512 while shifting in 0s using writemask k1.

vpsllvw zmm1 {k1} {z}, zmm2, zmm3
vpsllvw zmm1 {k1} {z}, zmm2, [rax]

; Shift doublewords in xmm2 left by amount specified in the corresponding element of xmm3/m128/m32bcst while shifting in 0s using writemask k1.

vpsllvd xmm1 {k1} {z}, xmm2, xmm3
vpsllvd xmm1 {k1} {z}, xmm2, [rax]

; Shift doublewords in ymm2 left by amount specified in the corresponding element of ymm3/m256/m32bcst while shifting in 0s using writemask k1.

vpsllvd ymm1 {k1} {z}, ymm2, ymm3
vpsllvd ymm1 {k1} {z}, ymm2, [rax]

; Shift doublewords in zmm2 left by amount specified in the corresponding element of zmm3/m512/m32bcst while shifting in 0s using writemask k1.

vpsllvd zmm1 {k1} {z}, zmm2, zmm3
vpsllvd zmm1 {k1} {z}, zmm2, [rax]

; Shift quadwords in xmm2 left by amount specified in the corresponding element of xmm3/m128/m64bcst while shifting in 0s using writemask k1.

vpsllvq xmm1 {k1} {z}, xmm2, xmm3
vpsllvq xmm1 {k1} {z}, xmm2, [rax]

; Shift quadwords in ymm2 left by amount specified in the corresponding element of ymm3/m256/m64bcst while shifting in 0s using writemask k1.

vpsllvq ymm1 {k1} {z}, ymm2, ymm3
vpsllvq ymm1 {k1} {z}, ymm2, [rax]

; Shift quadwords in zmm2 left by amount specified in the corresponding element of zmm3/m512/m64bcst while shifting in 0s using writemask k1.

vpsllvq zmm1 {k1} {z}, zmm2, zmm3
vpsllvq zmm1 {k1} {z}, zmm2, [rax]

; Shift words in xmm2 right by amount specified in the corresponding element of xmm3/m128 while shifting in sign bits using writemask k1.

vpsravw xmm1 {k1} {z}, xmm2, xmm3
vpsravw xmm1 {k1} {z}, xmm2, [rax]

; Shift words in ymm2 right by amount specified in the corresponding element of ymm3/m256 while shifting in sign bits using writemask k1.

vpsravw ymm1 {k1} {z}, ymm2, ymm3
vpsravw ymm1 {k1} {z}, ymm2, [rax]

; Shift words in zmm2 right by amount specified in the corresponding element of zmm3/m512 while shifting in sign bits using writemask k1.

vpsravw zmm1 {k1} {z}, zmm2, zmm3
vpsravw zmm1 {k1} {z}, zmm2, [rax]

; Shift doublewords in xmm2 right by amount specified in the corresponding element of xmm3/m128/m32bcst while shifting in sign bits using writemask k1.

vpsravd xmm1 {k1} {z}, xmm2, xmm3
vpsravd xmm1 {k1} {z}, xmm2, [rax]

; Shift doublewords in ymm2 right by amount specified in the corresponding element of ymm3/m256/m32bcst while shifting in sign bits using writemask k1.

vpsravd ymm1 {k1} {z}, ymm2, ymm3
vpsravd ymm1 {k1} {z}, ymm2, [rax]

; Shift doublewords in zmm2 right by amount specified in the corresponding element of zmm3/m512/m32bcst while shifting in sign bits using writemask k1.

vpsravd zmm1 {k1} {z}, zmm2, zmm3
vpsravd zmm1 {k1} {z}, zmm2, [rax]

; Shift quadwords in xmm2 right by amount specified in the corresponding element of xmm3/m128/m64bcst while shifting in sign bits using writemask k1.

vpsravq xmm1 {k1} {z}, xmm2, xmm3
vpsravq xmm1 {k1} {z}, xmm2, [rax]

; Shift quadwords in ymm2 right by amount specified in the corresponding element of ymm3/m256/m64bcst while shifting in sign bits using writemask k1.

vpsravq ymm1 {k1} {z}, ymm2, ymm3
vpsravq ymm1 {k1} {z}, ymm2, [rax]

; Shift quadwords in zmm2 right by amount specified in the corresponding element of zmm3/m512/m64bcst while shifting in sign bits using writemask k1.

vpsravq zmm1 {k1} {z}, zmm2, zmm3
vpsravq zmm1 {k1} {z}, zmm2, [rax]

; Shift words in xmm2 right by amount specified in the corresponding element of xmm3/m128 while shifting in 0s using writemask k1.

vpsrlvw xmm1 {k1} {z}, xmm2, xmm3
vpsrlvw xmm1 {k1} {z}, xmm2, [rax]

; Shift words in ymm2 right by amount specified in the corresponding element of ymm3/m256 while shifting in 0s using writemask k1.

vpsrlvw ymm1 {k1} {z}, ymm2, ymm3
vpsrlvw ymm1 {k1} {z}, ymm2, [rax]

; Shift words in zmm2 right by amount specified in the corresponding element of zmm3/m512 while shifting in 0s using writemask k1.

vpsrlvw zmm1 {k1} {z}, zmm2, zmm3
vpsrlvw zmm1 {k1} {z}, zmm2, [rax]

; Shift doublewords in xmm2 right by amount specified in the corresponding element of xmm3/m128/m32bcst while shifting in 0s using writemask k1.

vpsrlvd xmm1 {k1} {z}, xmm2, xmm3
vpsrlvd xmm1 {k1} {z}, xmm2, [rax]

; Shift doublewords in ymm2 right by amount specified in the corresponding element of ymm3/m256/m32bcst while shifting in 0s using writemask k1.

vpsrlvd ymm1 {k1} {z}, ymm2, ymm3
vpsrlvd ymm1 {k1} {z}, ymm2, [rax]

; Shift doublewords in zmm2 right by amount specified in the corresponding element of zmm3/m512/m32bcst while shifting in 0s using writemask k1.

vpsrlvd zmm1 {k1} {z}, zmm2, zmm3
vpsrlvd zmm1 {k1} {z}, zmm2, [rax]

; Shift quadwords in xmm2 right by amount specified in the corresponding element of xmm3/m128/m64bcst while shifting in 0s using writemask k1.

vpsrlvq xmm1 {k1} {z}, xmm2, xmm3
vpsrlvq xmm1 {k1} {z}, xmm2, [rax]

; Shift quadwords in ymm2 right by amount specified in the corresponding element of ymm3/m256/m64bcst while shifting in 0s using writemask k1.

vpsrlvq ymm1 {k1} {z}, ymm2, ymm3
vpsrlvq ymm1 {k1} {z}, ymm2, [rax]

; Shift quadwords in zmm2 right by amount specified in the corresponding element of zmm3/m512/m64bcst while shifting in 0s using writemask k1.

vpsrlvq zmm1 {k1} {z}, zmm2, zmm3
vpsrlvq zmm1 {k1} {z}, zmm2, [rax]

; Add 8 bits masks in k2 and k3 and place result in k1.

kaddb k1, k2, k3

; Add 16 bits masks in k2 and k3 and place result in k1.

kaddw k1, k2, k3

; Add 32 bits masks in k2 and k3 and place result in k1.

kaddd k1, k2, k3

; Add 64 bits masks in k2 and k3 and place result in k1.

kaddq k1, k2, k3

; Bitwise AND 8 bits masks k2 and k3 and place result in k1.

kandb k1, k2, k3

; Bitwise AND 16 bits masks k2 and k3 and place result in k1.

kandw k1, k2, k3

; Bitwise AND 32 bits masks k2 and k3 and place result in k1.

kandd k1, k2, k3

; Bitwise AND 64 bits masks k2 and k3 and place result in k1.

kandq k1, k2, k3


; Bitwise AND NOT 8 bits masks k2 and k3 and place result in k1.

kandnb k1, k2, k3

; Bitwise AND NOT 16 bits masks k2 and k3 and place result in k1.

kandnw k1, k2, k3

; Bitwise AND NOT 32 bits masks k2 and k3 and place result in k1.

kandnd k1, k2, k3

; Bitwise AND NOT 64 bits masks k2 and k3 and place result in k1.

kandnq k1, k2, k3

; Move 8 bits mask from k2/m8 and store the result in k1.

kmovb k1, k2
kmovb k1, BYTE [rax]

; Move 16 bits mask from k2/m16 and store the result in k1.

kmovw k1, k2
kmovw k1, WORD [rax]

; Move 32 bits mask from k2/m32 and store the result in k1.

kmovd k1, k2
kmovd k1, DWORD [rax]

; Move 64 bits mask from k2/m64 and store the result in k1.

kmovq k1, k2
kmovq k1, QWORD [rax]

; Move 8 bits mask from k1 and store the result in m8.

kmovb BYTE [rax], k2

; Move 16 bits mask from r32 to k1.

kmovw WORD [rax], k2

; Move 32 bits mask from k1 and store the result in m32.

kmovd DWORD [rax], k2

; Move 64 bits mask from k1 and store the result in m64.

kmovq QWORD [rax], k2

; Move 8 bits mask from r32 to k1.

kmovb k1, eax

; Move 16 bits mask from r32 to k1.

kmovw k1, eax

; Move 32 bits mask from r32 to k1.

kmovd k1, eax

; Move 64 bits mask from r64 to k1.

kmovq k1, rax

; Move 8 bits mask from k1 to r32.

kmovb eax, k2

; Move 16 bits mask from k1 to r32.

kmovw eax, k2

; Move 32 bits mask from k1 to r32.

kmovd eax, k2

; Move 64 bits mask from k1 to r64.

kmovq rax, k2

; Bitwise NOT of 8 bits mask k2.

knotb k1, k2

; Bitwise NOT of 16 bits mask k2.

knotw k1, k2

; Bitwise NOT of 32 bits mask k2.

knotd k1, k2

; Bitwise NOT of 64 bits mask k2.

knotq k1, k2

; Bitwise OR 8 bits masks k2 and k3 and place result in k1.

korb k1, k2, k3

; Bitwise OR 16 bits masks k2 and k3 and place result in k1.

korw k1, k2, k3

; Bitwise OR 32 bits masks k2 and k3 and place result in k1.

kord k1, k2, k3

; Bitwise OR 64 bits masks k2 and k3 and place result in k1.

korq k1, k2, k3

; Bitwise OR 8 bits masks k1 and k2 and update ZF and CF accordingly.

kortestb k1, k2

; Bitwise OR 16 bits masks k1 and k2 and update ZF and CF accordingly.

kortestw k1, k2

; Bitwise OR 32 bits masks k1 and k2 and update ZF and CF accordingly.

kortestd k1, k2

; Bitwise OR 64 bits masks k1 and k2 and update ZF and CF accordingly.

kortestq k1, k2

; Shift left 8 bits in k2 by immediate and write result in k1.

kshiftlb k1, k2, 0x69

; Shift left 16 bits in k2 by immediate and write result in k1.

kshiftlw k1, k2, 0x69

; Shift left 32 bits in k2 by immediate and write result in k1.

kshiftld k1, k2, 0x69

; Shift left 64 bits in k2 by immediate and write result in k1.

kshiftlq k1, k2, 0x69

; Shift right 8 bits in k2 by immediate and write result in k1.

kshiftrb k1, k2, 0x69

; Shift right 16 bits in k2 by immediate and write result in k1.

kshiftrw k1, k2, 0x69

; Shift right 32 bits in k2 by immediate and write result in k1.

kshiftrd k1, k2, 0x69

; Shift right 64 bits in k2 by immediate and write result in k1.

kshiftrq k1, k2, 0x69

; Set ZF and CF depending on sign bit AND and ANDN of 8 bits mask register sources.

ktestb k1, k2

; Set ZF and CF depending on sign bit AND and ANDN of 16 bits mask register sources.

ktestw k1, k2

; Set ZF and CF depending on sign bit AND and ANDN of 32 bits mask register sources.

ktestd k1, k2

; Set ZF and CF depending on sign bit AND and ANDN of 64 bits mask register sources.

ktestq k1, k2

; Unpack 8-bit masks in k2 and k3 and write word result in k1

kunpckbw k1, k2, k3

; Unpack 16-bit masks in k2 and k3 and write doubleword result in k1.

kunpckwd k1, k2, k3

; Unpack 32-bit masks in k2 and k3 and write quadword result in k1.

kunpckdq k1, k2, k3

; Bitwise XNOR 8-bit masks k2 and k3 and place result in k1.

kxnorb k1, k2, k3

; Bitwise XNOR 16-bit masks k2 and k3 and place result in k1.

kxnorw k1, k2, k3

; Bitwise XNOR 32-bit masks k2 and k3 and place result in k1.

kxnord k1, k2, k3

; Bitwise XNOR 64-bit masks k2 and k3 and place result in k1.

kxnorq k1, k2, k3

; Bitwise XOR 8-bit masks k2 and k3 and place result in k1.

kxorb k1, k2, k3

; Bitwise XOR 16-bit masks k2 and k3 and place result in k1.

kxorw k1, k2, k3

; Bitwise XOR 32-bit masks k2 and k3 and place result in k1.

kxord k1, k2, k3

; Bitwise XOR 64-bit masks k2 and k3 and place result in k1.

kxorq k1, k2, k3

; Shift right and merge vectors xmm2 and xmm3/m128/m32bcst with double-word granularity using imm8 as number of elements to shift, and store the final result in xmm1, under writemask.
; TODO: 'm64bcst' third argument

valignd xmm1 {k1} {z}, xmm2, xmm3, 0x69
valignd xmm1 {k1} {z}, xmm2, [rax], 0x69

; Shift right and merge vectors xmm2 and xmm3/m128/m64bcst with quad-word granularity using imm8 as number of elements to shift, and store the final result in xmm1, under writemask.
; TODO: 'm64bcst' third argument

valignq xmm1 {k1} {z}, xmm2, xmm3, 0x69
valignq xmm1 {k1} {z}, xmm2, [rax], 0x69

; Shift right and merge vectors ymm2 and ymm3/m256/m32bcst with double-word granularity using imm8 as number of elements to shift, and store the final result in ymm1, under writemask.
; TODO: 'm64bcst' third argument

valignd ymm1 {k1} {z}, ymm2, ymm3, 0x69
valignd ymm1 {k1} {z}, ymm2, [rax], 0x69

; Shift right and merge vectors ymm2 and ymm3/m256/m64bcst with quad-word granularity using imm8 as number of elements to shift, and store the final result in ymm1, under writemask.
; TODO: 'm64bcst' third argument

valignq ymm1 {k1} {z}, ymm2, ymm3, 0x69
valignq ymm1 {k1} {z}, ymm2, [rax], 0x69

; Shift right and merge vectors zmm2 and zmm3/m512/m32bcst with double-word granularity using imm8 as number of elements to shift, and store the final result in zmm1, under writemask.
; TODO: 'm64bcst' third argument

valignd zmm1 {k1} {z}, zmm2, zmm3, 0x69
valignd zmm1 {k1} {z}, zmm2, [rax], 0x69

; Shift right and merge vectors zmm2 and zmm3/m512/m64bcst with quad-word granularity using imm8 as number of elements to shift, and store the final result in zmm1, under writemask.
; TODO: 'm64bcst' third argument

valignq zmm1 {k1} {z}, zmm2, zmm3, 0x69
valignq zmm1 {k1} {z}, zmm2, [rax], 0x69

; Blend double-precision vector xmm2 and double-precision vector xmm3/m128/m64bcst and store the result in xmm1, under control mask.
; TODO: 'm64bcst' third argument

vblendmpd xmm1 {k1} {z}, xmm2, xmm3
vblendmpd xmm1 {k1} {z}, xmm2, [rax]

; Blend double-precision vector ymm2 and double-precision vector ymm3/m256/m64bcst and store the result in ymm1, under control mask.
; TODO: 'm64bcst' third argument

vblendmpd ymm1 {k1} {z}, ymm2, ymm3
vblendmpd ymm1 {k1} {z}, ymm2, [rax]

; Blend double-precision vector zmm2 and double-precision vector zmm3/m512/m64bcst and store the result in zmm1, under control mask.
; TODO: 'm64bcst' third argument

vblendmpd zmm1 {k1} {z}, zmm2, zmm3
vblendmpd zmm1 {k1} {z}, zmm2, [rax]

; Blend single-precision vector xmm2 and single-precision vector xmm3/m128/m32bcst and store the result in xmm1, under control mask.
; TODO: 'm32bcst' third argument

vblendmps xmm1 {k1} {z}, xmm2, xmm3
vblendmps xmm1 {k1} {z}, xmm2, [rax]

; Blend single-precision vector ymm2 and single-precision vector ymm3/m256/m32bcst and store the result in ymm1, under control mask.
; TODO: 'm32bcst' third argument

vblendmps ymm1 {k1} {z}, ymm2, ymm3
vblendmps ymm1 {k1} {z}, ymm2, [rax]

; Blend single-precision vector zmm2 and single-precision vector zmm3/m512/m32bcst using k1 as select control and store the result in zmm1.
; TODO: 'm32bcst' third argument

vblendmps zmm1 {k1} {z}, zmm2, zmm3
vblendmps zmm1 {k1} {z}, zmm2, [rax]

; Compress packed double-precision floating-point values from xmm2 to xmm1/m128 using writemask k1.

vcompresspd xmm1 {k1} {z}, xmm2
vcompresspd [rax], xmm2

; Compress packed double-precision floating-point values from ymm2 to ymm1/m256 using writemask k1.

vcompresspd ymm1 {k1} {z}, ymm2
vcompresspd [rax], ymm2

; Compress packed double-precision floating-point values from zmm2 using control mask k1 to zmm1/m512.

vcompresspd zmm1 {k1} {z}, zmm2
vcompresspd [rax], zmm2

; Compress packed single-precision floating-point values from xmm2 to xmm1/m128 using writemask k1.

vcompresspd xmm1 {k1} {z}, xmm2
vcompresspd [rax], xmm2

; Compress packed single-precision floating-point values from ymm2 to ymm1/m256 using writemask k1.

vcompresspd ymm1 {k1} {z}, ymm2
vcompresspd [rax], ymm2

; Compress packed single-precision floating-point values from zmm2 using control mask k1 to zmm1/m512.

vcompresspd zmm1 {k1} {z}, zmm2
vcompresspd [rax], zmm2

; Convert two packed double-precision floating-point values from xmm2/m128/m64bcst to two packed quadword integers in xmm1 with writemask k1.
; TODO: 'm64bcst' second argument

vcvtpd2qq xmm1 {k1} {z}, xmm2
vcvtpd2qq xmm1 {k1} {z}, [rax]


; Convert four packed double-precision floating-point values from ymm2/m256/m64bcst to four packed quadword integers in ymm1 with writemask k1.
; TODO: 'm64bcst' second argument

vcvtpd2qq ymm1 {k1} {z}, ymm2
vcvtpd2qq ymm1 {k1} {z}, [rax]

; Convert eight packed double-precision floating-point values from zmm2/m512/m64bcst to eight packed quadword integers in zmm1 with writemask k1.
; TODO: 'm64bcst' second argument

vcvtpd2qq zmm1 {k1} {z}, zmm2
vcvtpd2qq zmm1 {k1} {z}, [rax]

; Convert two packed double-precision floating-point values in xmm2/m128/m64bcst to two unsigned doubleword integers in xmm1 subject to writemask k1.
; TODO: 'm64bcst' second argument

vcvtpd2udq xmm1 {k1} {z}, xmm2

; Convert four packed double-precision floating-point values in ymm2/m256/m64bcst to four unsigned doubleword integers in xmm1 subject to writemask k1.
; TODO: 'm64bcst' second argument

vcvtpd2udq xmm1 {k1} {z}, ymm2

; Convert eight packed double-precision floating-point values in zmm2/m512/m64bcst to eight unsigned doubleword integers in ymm1 subject to writemask k1.
; TODO: 'm64bcst' second argument

vcvtpd2udq ymm1 {k1} {z}, zmm2

; Convert two packed double-precision floating-point values from xmm2/mem to two packed unsigned quadword integers in xmm1 with writemask k1.
; TODO: 'm64bcst' second argument

vcvtpd2uqq xmm1 {k1} {z}, xmm2
vcvtpd2uqq xmm1 {k1} {z}, [rax]

; Convert fourth packed double-precision floating-point values from ymm2/mem to four packed unsigned quadword integers in ymm1 with writemask k1.
; TODO: 'm64bcst' second argument

vcvtpd2uqq ymm1 {k1} {z}, ymm2
vcvtpd2uqq ymm1 {k1} {z}, [rax]

; Convert eight packed double-precision floating-point values from zmm2/mem to eight packed unsigned quadword integers in zmm1 with writemask k1.
; TODO: 'm64bcst' second argument

vcvtpd2uqq zmm1 {k1} {z}, zmm2
vcvtpd2uqq zmm1 {k1} {z}, [rax]

; Convert two packed single precision floating-point values from xmm2/m64/m32bcst to two packed signed quadword values in xmm1 subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvtpd2qq xmm1 {k1} {z}, xmm2
vcvtpd2qq xmm1 {k1} {z}, [rax]


; Convert four packed single precision floating-point values from xmm2/m128/m32bcst to four packed signed quadword values in ymm1 subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvtpd2qq ymm1 {k1} {z}, ymm2
vcvtpd2qq ymm1 {k1} {z}, [rax]

; Convert eight packed single precision floating-point values from ymm2/m256/m32bcst to eight packed signed quadword values in zmm1 subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvtpd2qq zmm1 {k1} {z}, zmm2
vcvtpd2qq zmm1 {k1} {z}, [rax]

; Convert four packed single precision floating-point values from xmm2/m128/m32bcst to four packed unsigned doubleword values in xmm1 subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvtps2udq xmm1 {k1} {z}, xmm2
vcvtps2udq xmm1 {k1} {z}, [rax]

; Convert eight packed single precision floating-point values from ymm2/m256/m32bcst to eight packed unsigned doubleword values in ymm1 subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvtps2udq ymm1 {k1} {z}, ymm2
vcvtps2udq ymm1 {k1} {z}, [rax]

; Convert sixteen packed single-precision floating-point values from zmm2/m512/m32bcst to sixteen packed unsigned doubleword values in zmm1 subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvtps2udq zmm1 {k1} {z}, zmm2
vcvtps2udq zmm1 {k1} {z}, [rax]

; Convert two packed single precision floating-point values from zmm2/m64/m32bcst to two packed unsigned quadword values in zmm1 subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvtps2uqq xmm1 {k1} {z}, xmm2
vcvtps2uqq xmm1 {k1} {z}, [rax]

; Convert four packed single precision floating-point values from xmm2/m128/m32bcst to four packed unsigned quadword values in ymm1 subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvtps2uqq ymm1 {k1} {z}, xmm2
vcvtps2uqq ymm1 {k1} {z}, [rax]

; Convert eight packed single precision floating-point values from ymm2/m256/m32bcst to eight packed unsigned quadword values in zmm1 subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvtps2uqq zmm1 {k1} {z}, ymm2
vcvtps2uqq zmm1 {k1} {z}, [rax]

; Convert two packed quadword integers from xmm2/m128/m64bcst to packed double-precision floating-point values in xmm1 with writemask k1.
; TODO: 'm64bcst' second argument

vcvtqq2pd xmm1 {k1} {z}, xmm2
vcvtqq2pd xmm1 {k1} {z}, [rax]

; Convert four packed quadword integers from ymm2/m256/m64bcst to packed double-precision floating-point values in ymm1 with writemask k1.
; TODO: 'm64bcst' second argument

vcvtqq2pd ymm1 {k1} {z}, ymm2
vcvtqq2pd ymm1 {k1} {z}, [rax]

; Convert eight packed quadword integers from zmm2/m512/m64bcst to eight packed double-precision floating-point values in zmm1 with writemask k1.
; TODO: 'm64bcst' second argument

vcvtqq2pd zmm1 {k1} {z}, zmm2
vcvtqq2pd zmm1 {k1} {z}, [rax]

; Convert two packed quadword integers from xmm2/m128/m64bcst to packed single-precision floating-point values in xmm1 with writemask k1.
; TODO: 'm32bcst' second argument

vcvtqq2ps xmm1 {k1} {z}, xmm2

; Convert four packed quadword integers from ymm2/m256/m32bcst to packed single-precision floating-point values in ymm1 with writemask k1.
; TODO: 'm32bcst' second argument

vcvtqq2ps xmm1 {k1} {z}, ymm2

; Convert eight packed quadword integers from zmm2/m512/m32bcst to eight packed single-precision floating-point values in zmm1 with writemask k1.
; TODO: 'm32bcst' second argument

vcvtqq2ps ymm1 {k1} {z}, zmm2
vcvtqq2ps ymm1 {k1} {z}, [rax]

; Convert one double-precision floating-point value from xmm1/m64 to one unsigned doubleword integer r32.

vcvtsd2usi eax, xmm1
vcvtsd2usi eax, [rcx]

; Convert one double-precision floating-point value from xmm1/m64 to one unsigned quadword integer zero-extended into r64.

vcvtsd2usi rax, xmm1
vcvtsd2usi rax, [rcx]

; Convert one single-precision floating-point value from xmm1/m32 to one unsigned doubleword integer in r32.

vcvtss2usi eax, xmm1
vcvtss2usi eax, [rcx]

; Convert one single-precision floating-point value from xmm1/m32 to one unsigned quadword integer in r64.

vcvtss2usi rax, xmm1
vcvtss2usi rax, [rcx]

; Convert two packed double-precision floating-point values from zmm2/m128/m64bcst to two packed quadword integers in zmm1 using truncation with writemask k1.
; TODO: 'm64bcst' second argument

vcvttpd2qq xmm1 {k1} {z}, xmm2
vcvttpd2qq xmm1 {k1} {z}, [rax]

; Convert four packed double-precision floating-point values from ymm2/m256/m64bcst to four packed quadword integers in ymm1 using truncation with writemask k1.
; TODO: 'm64bcst' second argument

vcvttpd2qq ymm1 {k1} {z}, ymm2
vcvttpd2qq ymm1 {k1} {z}, [rax]

; Convert eight packed double-precision floating-point values from zmm2/m512 to eight packed quadword integers in zmm1 using truncation with writemask k1.
; TODO: 'm64bcst' second argument

vcvttpd2qq zmm1 {k1} {z}, zmm2
vcvttpd2qq zmm1 {k1} {z}, [rax]

; Convert two packed double-precision floating-point values in xmm2/m128/m64bcst to two unsigned doubleword integers in xmm1 using truncation subject to writemask k1.
; TODO: 'm64bcst' second argument

vcvttpd2udq xmm1 {k1} {z}, xmm2

; Convert four packed double-precision floating-point values in ymm2/m256/m64bcst to four unsigned doubleword integers in xmm1 using truncation subject to writemask k1.
; TODO: 'm64bcst' second argument

vcvttpd2udq xmm1 {k1} {z}, ymm2

; Convert eight packed double-precision floating-point values in zmm2/m512/m64bcst to eight unsigned doubleword integers in ymm1 using truncation subject to writemask k1.
; TODO: 'm64bcst' second argument

vcvttpd2udq ymm1 {k1} {z}, zmm2
vcvttpd2udq ymm1 {k1} {z}, [rax]

; Convert two packed double-precision floating-point values from xmm2/m128/m64bcst to two packed unsigned quadword integers in xmm1 using truncation with writemask k1.

vcvttpd2uqq xmm1 {k1} {z}, xmm2
vcvttpd2uqq xmm1 {k1} {z}, [rax]

; Convert four packed double-precision floating-point values from ymm2/m256/m64bcst to four packed unsigned quadword integers in ymm1 using truncation with writemask k1.

vcvttpd2uqq ymm1 {k1} {z}, ymm2
vcvttpd2uqq ymm1 {k1} {z}, [rax]

; Convert eight packed double-precision floating-point values from zmm2/mem to eight packed unsigned quadword integers in zmm1 using truncation with writemask k1.

vcvttpd2uqq zmm1 {k1} {z}, zmm2
vcvttpd2uqq zmm1 {k1} {z}, [rax]

; Convert two packed single precision floating-point values from xmm2/m64/m32bcst to two packed signed quadword values in xmm1 using truncation subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvttps2qq xmm1 {k1} {z}, xmm2
vcvttps2qq xmm1 {k1} {z}, [rax]

; Convert four packed single precision floating-point values from xmm2/m128/m32bcst to four packed signed quadword values in ymm1 using truncation subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvttps2qq ymm1 {k1} {z}, xmm2
vcvttps2qq ymm1 {k1} {z}, [rax]

; Convert eight packed single precision floating-point values from ymm2/m256/m32bcst to eight packed signed quadword values in zmm1 using truncation subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvttps2qq zmm1 {k1} {z}, ymm2
vcvttps2qq zmm1 {k1} {z}, [rax]

; Convert four packed single precision floating-point values from xmm2/m128/m32bcst to four packed unsigned doubleword values in xmm1 using truncation subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvttps2udq xmm1 {k1} {z}, xmm2
vcvttps2udq xmm1 {k1} {z}, [rax]

; Convert eight packed single precision floating-point values from ymm2/m256/m32bcst to eight packed unsigned doubleword values in ymm1 using truncation subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvttps2udq ymm1 {k1} {z}, ymm2
vcvttps2udq ymm1 {k1} {z}, [rax]

; Convert sixteen packed single-precision floating-point values from zmm2/m512/m32bcst to sixteen packed unsigned doubleword values in zmm1 using truncation subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvttps2udq zmm1 {k1} {z}, zmm2
vcvttps2udq zmm1 {k1} {z}, [rax]

; Convert two packed single precision floating-point values from xmm2/m64/m32bcst to two packed unsigned quadword values in xmm1 using truncation subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvttps2uqq xmm1 {k1} {z}, xmm2
vcvttps2uqq xmm1 {k1} {z}, [rax]

; Convert four packed single precision floating-point values from xmm2/m128/m32bcst to four packed unsigned quadword values in ymm1 using truncation subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvttps2uqq ymm1 {k1} {z}, xmm2
vcvttps2uqq ymm1 {k1} {z}, [rax]

; Convert eight packed single precision floating-point values from ymm2/m256/m32bcst to eight packed unsigned quadword values in zmm1 using truncation subject to writemask k1.
; TODO: 'm32bcst' second argument

vcvttps2uqq zmm1 {k1} {z}, ymm2
vcvttps2uqq zmm1 {k1} {z}, [rax]

; Convert one double-precision floating-point value from xmm1/m64 to one unsigned doubleword integer r32 using truncation.

vcvttsd2usi eax, xmm1
vcvttsd2usi eax, [rax]

; Convert one double-precision floating-point value from xmm1/m64 to one unsigned quadword integer zero-extended into r64 using truncation.

vcvttsd2usi rax, xmm1
vcvttsd2usi rax, [rax]

; Convert one single-precision floating-point value from xmm1/m32 to one unsigned doubleword integer in r32 using truncation.

vcvttss2usi eax, xmm1
vcvttss2usi eax, [rax]

; Convert one single-precision floating-point value from xmm1/m32 to one unsigned quadword integer in r64 using truncation.

vcvttss2usi rax, xmm1
vcvttss2usi rax, [rax]

; Convert two packed unsigned doubleword integers from ymm2/m64/m32bcst to packed double-precision floating-point values in zmm1 with writemask k1.
; TODO: 'm32bcst' second argument

vcvtudq2pd xmm1 {k1} {z}, xmm2
vcvtudq2pd xmm1 {k1} {z}, [rax]

; Convert four packed unsigned doubleword integers from xmm2/m128/m32bcst to packed double-precision floating-point values in zmm1 with writemask k1.
; TODO: 'm32bcst' second argument

vcvtudq2pd ymm1 {k1} {z}, xmm2
vcvtudq2pd ymm1 {k1} {z}, [rax]

; Convert eight packed unsigned doubleword integers from ymm2/m256/m32bcst to eight packed double-precision floating-point values in zmm1 with writemask k1.
; TODO: 'm32bcst' second argument

vcvtudq2pd zmm1 {k1} {z}, ymm2
vcvtudq2pd zmm1 {k1} {z}, [rax]

; Convert four packed unsigned doubleword integers from xmm2/m128/m32bcst to packed single-precision floating-point values in xmm1 with writemask k1.
; TODO: 'm32bcst' second argument

vcvtudq2ps xmm1 {k1} {z}, xmm2
vcvtudq2ps xmm1 {k1} {z}, [rax]

; Convert eight packed unsigned doubleword integers from ymm2/m256/m32bcst to packed single-precision floating-point values in zmm1 with writemask k1.
; TODO: 'm32bcst' second argument

vcvtudq2ps ymm1 {k1} {z}, ymm2
vcvtudq2ps ymm1 {k1} {z}, [rax]

; Convert sixteen packed unsigned doubleword integers from zmm2/m512/m32bcst to sixteen packed single-precision floating-point values in zmm1 with writemask k1.
; TODO: 'm32bcst' second argument

vcvtudq2ps zmm1 {k1} {z}, zmm2
vcvtudq2ps zmm1 {k1} {z}, [rax]

; Convert two packed unsigned quadword integers from xmm2/m128/m64bcst to two packed double-precision floating-point values in xmm1 with writemask k1.
; TODO: 'm64bcst' second argument

vcvtuqq2pd xmm1 {k1} {z}, xmm2
vcvtuqq2pd xmm1 {k1} {z}, [rax]

; Convert four packed unsigned quadword integers from ymm2/m256/m64bcst to packed double-precision floating-point values in ymm1 with writemask k1.
; TODO: 'm64bcst' second argument

vcvtuqq2pd ymm1 {k1} {z}, ymm2
vcvtuqq2pd ymm1 {k1} {z}, [rax]

; Convert eight packed unsigned quadword integers from zmm2/m512/m64bcst to eight packed double-precision floating-point values in zmm1 with writemask k1.
; TODO: 'm64bcst' second argument

vcvtuqq2pd zmm1 {k1} {z}, zmm2
vcvtuqq2pd zmm1 {k1} {z}, [rax]

; Convert two packed unsigned quadword integers from xmm2/m128/m64bcst to packed single-precision floating-point values in zmm1 with writemask k1.
; TODO: 'm64bcst' second argument

vcvtuqq2ps xmm1 {k1} {z}, xmm2

; Convert four packed unsigned quadword integers from ymm2/m256/m64bcst to packed single-precision floating-point values in xmm1 with writemask k1.
; TODO: 'm64bcst' second argument

vcvtuqq2ps xmm1 {k1} {z}, ymm2

; Convert eight packed unsigned quadword integers from zmm2/m512/m64bcst to eight packed single-precision floating-point values in zmm1 with writemask k1.
; TODO: 'm64bcst' second argument

vcvtuqq2ps ymm1 {k1} {z}, zmm2
vcvtuqq2ps ymm1 {k1} {z}, [rax]

; Convert one unsigned doubleword integer from r/m32 to one double-precision floating-point value in xmm1.

vcvtusi2sd xmm1, xmm2, eax
vcvtusi2sd xmm1, xmm2, DWORD [rax]

; Convert one unsigned quadword integer from r/m64 to one double-precision floating-point value in xmm1.

vcvtusi2sd xmm1, xmm2, rax
vcvtusi2sd xmm1, xmm2, QWORD [rax]

; Convert one signed doubleword integer from r/m32 to one single-precision floating-point value in xmm1.

vcvtusi2ss xmm1, xmm2, eax
vcvtusi2ss xmm1, xmm2, DWORD [rax]

; Convert one signed quadword integer from r/m64 to one single-precision floating-point value in xmm1.

vcvtusi2ss xmm1, xmm2, rax
vcvtusi2ss xmm1, xmm2, QWORD [rax]

; Compute packed SAD word results of unsigned bytes in dword block from xmm2 with unsigned bytes of dword blocks transformed from xmm3/m128 using the shuffle controls in imm8. Results are written to xmm1 under the writemask k1.

vdbpsadbw xmm1 {k1} {z}, xmm2, xmm3, 0x69
vdbpsadbw xmm1 {k1} {z}, xmm2, [rax], 0x69

; Compute packed SAD word results of unsigned bytes in dword block from ymm2 with unsigned bytes of dword blocks transformed from ymm3/m256 using the shuffle controls in imm8. Results are written to ymm1 under the writemask k1.

vdbpsadbw ymm1 {k1} {z}, ymm2, ymm3, 0x69
vdbpsadbw ymm1 {k1} {z}, ymm2, [rax], 0x69

; Compute packed SAD word results of unsigned bytes in dword block from zmm2 with unsigned bytes of dword blocks transformed from zmm3/m512 using the shuffle controls in imm8. Results are written to zmm1 under the writemask k1.

vdbpsadbw zmm1 {k1} {z}, zmm2, zmm3, 0x69
vdbpsadbw zmm1 {k1} {z}, zmm2, [rax], 0x69

; Expand packed double-precision floating-point values from xmm2/m128 to xmm1 using writemask k1.

vexpandpd xmm1 {k1} {z}, xmm2
vexpandpd xmm1 {k1} {z}, [rax]

; Expand packed double-precision floating-point values from ymm2/m256 to ymm1 using writemask k1.

vexpandpd ymm1 {k1} {z}, ymm2
vexpandpd ymm1 {k1} {z}, [rax]

; Expand packed double-precision floating-point values from zmm2/m512 to zmm1 using writemask k1.

vexpandpd zmm1 {k1} {z}, zmm2
vexpandpd zmm1 {k1} {z}, [rax]

; Expand packed single-precision floating-point values from xmm2/m128 to xmm1 using writemask k1.

vexpandps xmm1 {k1} {z}, xmm2
vexpandps xmm1 {k1} {z}, [rax]

; Expand packed single-precision floating-point values from ymm2/m256 to ymm1 using writemask k1.

vexpandps ymm1 {k1} {z}, ymm2
vexpandps ymm1 {k1} {z}, [rax]

; Expand packed single-precision floating-point values from zmm2/m512 to zmm1 using writemask k1.

vexpandps zmm1 {k1} {z}, zmm2
vexpandps zmm1 {k1} {z}, [rax]

; Fix up special numbers in float64 vector xmm1, float64 vector xmm2 and int64 vector xmm3/m128/m64bcst and store the result in xmm1, under writemask.

vfixupimmpd xmm1 {k1} {z}, xmm2, xmm3, 0x69
vfixupimmpd xmm1 {k1} {z}, xmm2, [rax], 0x69

; Fix up special numbers in float64 vector ymm1, float64 vector ymm2 and int64 vector ymm3/m256/m64bcst and store the result in ymm1, under writemask.

vfixupimmpd ymm1 {k1} {z}, ymm2, ymm3, 0x69
vfixupimmpd ymm1 {k1} {z}, ymm2, [rax], 0x69

; Fix up elements of float64 vector in zmm2 using int64 vector table in zmm3/m512/m64bcst, combine with preserved elements from zmm1, and store the result in zmm1.

vfixupimmpd zmm1 {k1} {z}, zmm2, zmm3, 0x69
vfixupimmpd zmm1 {k1} {z}, zmm2, [rax], 0x69

; Fix up special numbers in float32 vector xmm1, float32 vector xmm2 and int32 vector xmm3/m128/m32bcst and store the result in xmm1, under writemask.

vfixupimmps xmm1 {k1} {z}, xmm2, xmm3, 0x69
vfixupimmps xmm1 {k1} {z}, xmm2, [rax], 0x69

; Fix up special numbers in float32 vector ymm1, float32 vector ymm2 and int32 vector ymm3/m256/m32bcst and store the result in ymm1, under writemask.

vfixupimmps ymm1 {k1} {z}, ymm2, ymm3, 0x69
vfixupimmps ymm1 {k1} {z}, ymm2, [rax], 0x69

; Fix up elements of float32 vector in zmm2 using int32 vector table in zmm3/m512/m32bcst, combine with preserved elements from zmm1, and store the result in zmm1.

vfixupimmps zmm1 {k1} {z}, zmm2, zmm3, 0x69
vfixupimmps zmm1 {k1} {z}, zmm2, [rax], 0x69

; Fix up a float64 number in the low quadword element of xmm2 using scalar int32 table in xmm3/m64 and store the result in xmm1.

vfixupimmsd xmm1 {k1} {z}, xmm2, xmm3, 0x69
vfixupimmsd xmm1 {k1} {z}, xmm2, [rax], 0x69

; Fix up a float32 number in the low doubleword element in xmm2 using scalar int32 table in xmm3/m32 and store the result in xmm1.

vfixupimmss xmm1 {k1} {z}, xmm2, xmm3, 0x69
vfixupimmss xmm1 {k1} {z}, xmm2, [rax], 0x69

; Tests the input for the following categories: NaN, +0, -0, +Infinity, -Infinity, denormal, finite negative. The immediate field provides a mask bit for each of these category tests. The masked test results are OR-ed together to form a mask result.
; TODO: 'm64bcst' second argument

vfpclasspd k2 {k1}, xmm2, 0x69

; Tests the input for the following categories: NaN, +0, -0, +Infinity, -Infinity, denormal, finite negative. The immediate field provides a mask bit for each of these category tests. The masked test results are OR-ed together to form a mask result.
; TODO: 'm64bcst' second argument

vfpclasspd k2 {k1}, ymm2, 0x69

; Tests the input for the following categories: NaN, +0, -0, +Infinity, -Infinity, denormal, finite negative. The immediate field provides a mask bit for each of these category tests. The masked test results are OR-ed together to form a mask result.
; TODO: 'm64bcst' second argument

vfpclasspd k2 {k1}, zmm2, 0x69

; Tests the input for the following categories: NaN, +0, -0, +Infinity, -Infinity, denormal, finite negative. The immediate field provides a mask bit for each of these category tests. The masked test results are OR-ed together to form a mask result.
; TODO: 'm32bcst' second argument

vfpclassps k2 {k1}, xmm2, 0x69

; Tests the input for the following categories: NaN, +0, -0, +Infinity, -Infinity, denormal, finite negative. The immediate field provides a mask bit for each of these category tests. The masked test results are OR-ed together to form a mask result.
; TODO: 'm32bcst' second argument

vfpclassps k2 {k1}, ymm2, 0x69

; Tests the input for the following categories: NaN, +0, -0, +Infinity, -Infinity, denormal, finite negative. The immediate field provides a mask bit for each of these category tests. The masked test results are OR-ed together to form a mask result.
; TODO: 'm32bcst' second argument

vfpclassps k2 {k1}, zmm2, 0x69

; Tests the input for the following categories: NaN, +0, -0, +Infinity, -Infinity, denormal, finite negative. The immediate field provides a mask bit for each of these category tests. The masked test results are OR-ed together to form a mask result.

vfpclasssd k2 {k1}, xmm2, 0x69
vfpclasssd k2 {k1}, [rax], 0x69

; Tests the input for the following categories: NaN, +0, -0, +Infinity, -Infinity, denormal, finite negative. The immediate field provides a mask bit for each of these category tests. The masked test results are OR-ed together to form a mask result.

vfpclassss k2 {k1}, xmm2, 0x69
vfpclassss k2 {k1}, [rax], 0x69

; Using signed dword indices, gather single-precision floating-point values from memory using k1 as completion mask.

vgatherdps xmm1 {k1}, [xmm2]

; Using signed dword indices, gather single-precision floating-point values from memory using k1 as completion mask.

vgatherdps ymm1 {k1}, [ymm2]

; Using signed dword indices, gather single-precision floating-point values from memory using k1 as completion mask.

vgatherdps zmm1 {k1}, [zmm2]

; Using signed dword indices, gather double-precision floating-point values from memory using k1 as completion mask.

vgatherdpd xmm1 {k1}, [xmm2]

; Using signed dword indices, gather double-precision floating-point values from memory using k1 as completion mask.

vgatherdpd ymm1 {k1}, [xmm2]

; Using signed dword indices, gather double-precision floating-point values from memory using k1 as completion mask.

vgatherdpd zmm1 {k1}, [ymm2]




; Using signed qword indices, gather single-precision floating-point values from memory using k1 as completion mask.

vgatherqps xmm1 {k1}, [xmm2]

; Using signed qword indices, gather single-precision floating-point values from memory using k1 as completion mask.

vgatherqps xmm1 {k1}, [ymm2]

; Using signed qword indices, gather single-precision floating-point values from memory using k1 as completion mask.

vgatherqps ymm1 {k1}, [zmm2]

; Using signed qword indices, gather double-precision floating-point values from memory using k1 as completion mask.

vgatherqpd xmm1 {k1}, [xmm2]

; Using signed qword indices, gather double-precision floating-point values from memory using k1 as completion mask.

vgatherqpd ymm1 {k1}, [ymm2]

; Using signed qword indices, gather double-precision floating-point values from memory using k1 as completion mask.

vgatherqpd zmm1 {k1}, [zmm2]

; Convert the exponent of packed double-precision floating-point values in the source operand to DP FP results representing unbiased integer exponents and stores the results in the destination register.
; TODO: 'm64bcst' second argument

vgetexppd xmm1 {k1} {z}, xmm2
vgetexppd xmm1 {k1} {z}, [rax]

; Convert the exponent of packed double-precision floating-point values in the source operand to DP FP results representing unbiased integer exponents and stores the results in the destination register.
; TODO: 'm64bcst' second argument

vgetexppd ymm1 {k1} {z}, ymm2
vgetexppd ymm1 {k1} {z}, [rax]

; Convert the exponent of packed double-precision floating-point values in the source operand to DP FP results representing unbiased integer exponents and stores the results in the destination under writemask k1.
; TODO: 'm64bcst' second argument

vgetexppd zmm1 {k1} {z}, zmm2
vgetexppd zmm1 {k1} {z}, [rax]

; Convert the exponent of packed single-precision floating-point values in the source operand to DP FP results representing unbiased integer exponents and stores the results in the destination register.
; TODO: 'm32bcst' second argument

vgetexpps xmm1 {k1} {z}, xmm2
vgetexpps xmm1 {k1} {z}, [rax]

; Convert the exponent of packed single-precision floating-point values in the source operand to DP FP results representing unbiased integer exponents and stores the results in the destination register.
; TODO: 'm32bcst' second argument

vgetexpps ymm1 {k1} {z}, ymm2
vgetexpps ymm1 {k1} {z}, [rax]

; Convert the exponent of packed single-precision floating-point values in the source operand to DP FP results representing unbiased integer exponents and stores the results in the destination under writemask k1.
; TODO: 'm32bcst' second argument

vgetexpps zmm1 {k1} {z}, zmm2
vgetexpps zmm1 {k1} {z}, [rax]

; Convert the biased exponent (bits 62:52) of the low double-precision floating-point value in xmm3/m64 to a DP FP value representing unbiased integer exponent. Stores the result to the low 64-bit of xmm1 under the writemask k1 and merge with the other elements of xmm2.

vgetexpsd xmm1 {k1} {z}, xmm2, xmm3
vgetexpsd xmm1 {k1} {z}, xmm2, [rax]

; Convert the biased exponent (bits 62:52) of the low single-precision floating-point value in xmm3/m64 to a DP FP value representing unbiased integer exponent. Stores the result to the low 64-bit of xmm1 under the writemask k1 and merge with the other elements of xmm2.

vgetexpss xmm1 {k1} {z}, xmm2, xmm3
vgetexpss xmm1 {k1} {z}, xmm2, [rax]

; Get Normalized Mantissa from float64 vector xmm2/m128/m64bcst and store the result in xmm1, using imm8 for sign control and mantissa interval normalization, under writemask.

vgetmantpd xmm1 {k1} {z}, xmm2, 0x69
vgetmantpd xmm1 {k1} {z}, [rax], 0x69

; Get Normalized Mantissa from float64 vector ymm2/m256/m64bcst and store the result in ymm1, using imm8 for sign control and mantissa interval normalization, under writemask.

vgetmantpd ymm1 {k1} {z}, ymm2, 0x69
vgetmantpd ymm1 {k1} {z}, [rax], 0x69

; Get Normalized Mantissa from float64 vector zmm2/m512/m64bcst and store the result in zmm1, using imm8 for sign control and mantissa interval normalization, under writemask.

vgetmantpd zmm1 {k1} {z}, zmm2, 0x69
vgetmantpd zmm1 {k1} {z}, [rax], 0x69

; Get Normalized Mantissa from float32 vector xmm2/m128/m32bcst and store the result in xmm1, using imm8 for sign control and mantissa interval normalization, under writemask.

vgetmantps xmm1 {k1} {z}, xmm2, 0x69
vgetmantps xmm1 {k1} {z}, [rax], 0x69

; Get Normalized Mantissa from float32 vector ymm2/m256/m32bcst and store the result in ymm1, using imm8 for sign control and mantissa interval normalization, under writemask.

vgetmantps ymm1 {k1} {z}, ymm2, 0x69
vgetmantps ymm1 {k1} {z}, [rax], 0x69

; Get Normalized Mantissa from float32 vector zmm2/m512/m32bcst and store the result in zmm1, using imm8 for sign control and mantissa interval normalization, under writemask.

vgetmantps zmm1 {k1} {z}, zmm2, 0x69
vgetmantps zmm1 {k1} {z}, [rax], 0x69

; Extract the normalized mantissa of the low float64 element in xmm3/m64 using imm8 for sign control and mantissa interval normalization. Store the mantissa to xmm1 under the writemask k1 and merge with the other elements of xmm2.

vgetmantsd xmm1 {k1} {z}, xmm2, xmm3, 0x69
vgetmantsd xmm1 {k1} {z}, xmm2, [rax], 0x69

; Extract the normalized mantissa of the low float32 element in xmm3/m64 using imm8 for sign control and mantissa interval normalization. Store the mantissa to xmm1 under the writemask k1 and merge with the other elements of xmm2.

vgetmantss xmm1 {k1} {z}, xmm2, xmm3, 0x69
vgetmantss xmm1 {k1} {z}, xmm2, [rax], 0x69

; Blend byte integer vector xmm2 and byte vector xmm3/m128 and store the result in xmm1, under control mask.

vpblendmb xmm1 {k1} {z}, xmm2, xmm3
vpblendmb xmm1 {k1} {z}, xmm2, [rax]

; Blend byte integer vector ymm2 and byte vector ymm3/m256 and store the result in ymm1, under control mask.

vpblendmb ymm1 {k1} {z}, ymm2, ymm3
vpblendmb ymm1 {k1} {z}, ymm2, [rax]

; Blend byte integer vector zmm2 and byte vector zmm3/m512 and store the result in zmm1, under control mask.

vpblendmb zmm1 {k1} {z}, zmm2, zmm3
vpblendmb zmm1 {k1} {z}, zmm2, [rax]

; Blend word integer vector xmm2 and word vector xmm3/m128 and store the result in xmm1, under control mask.

vpblendmw xmm1 {k1} {z}, xmm2, xmm3
vpblendmw xmm1 {k1} {z}, xmm2, [rax]

; Blend word integer vector ymm2 and word vector ymm3/m256 and store the result in ymm1, under control mask.

vpblendmw ymm1 {k1} {z}, ymm2, ymm3
vpblendmw ymm1 {k1} {z}, ymm2, [rax]

; Blend word integer vector zmm2 and word vector zmm3/m512 and store the result in zmm1, under control mask.

vpblendmw zmm1 {k1} {z}, zmm2, zmm3
vpblendmw zmm1 {k1} {z}, zmm2, [rax]

; Blend doubleword integer vector xmm2 and doubleword vector xmm3/m128/m32bcst and store the result in xmm1, under control mask.
; TODO: 'm32bcst' third argument

vpblendmd xmm1 {k1} {z}, xmm2, xmm3
vpblendmd xmm1 {k1} {z}, xmm2, [rax]

; Blend doubleword integer vector ymm2 and doubleword vector ymm3/m256/m32bcst and store the result in ymm1, under control mask.
; TODO: 'm32bcst' third argument

vpblendmd ymm1 {k1} {z}, ymm2, ymm3
vpblendmd ymm1 {k1} {z}, ymm2, [rax]

; Blend doubleword integer vector zmm2 and doubleword vector zmm3/m512/m32bcst and store the result in zmm1, under control mask.
; TODO: 'm32bcst' third argument

vpblendmd zmm1 {k1} {z}, zmm2, zmm3
vpblendmd zmm1 {k1} {z}, zmm2, [rax]

; Blend quadword integer vector xmm2 and quadword vector xmm3/m128/m64bcst and store the result in xmm1, under control mask.
; TODO: 'm64bcst' third argument

vpblendmq xmm1 {k1} {z}, xmm2, xmm3
vpblendmq xmm1 {k1} {z}, xmm2, [rax]

; Blend quadword integer vector ymm2 and quadword vector ymm3/m256/m64bcst and store the result in ymm1, under control mask.
; TODO: 'm64bcst' third argument

vpblendmq ymm1 {k1} {z}, ymm2, ymm3
vpblendmq ymm1 {k1} {z}, ymm2, [rax]

; Blend quadword integer vector zmm2 and quadword vector zmm3/m512/m64bcst and store the result in zmm1, under control mask.
; TODO: 'm64bcst' third argument

vpblendmq zmm1 {k1} {z}, zmm2, zmm3
vpblendmq zmm1 {k1} {z}, zmm2, [rax]

; Broadcast an 8-bit value from a GPR to all bytes in the 128-bit destination subject to writemask k1.

vpbroadcastb xmm1 {k1} {z}, eax

; Broadcast an 8-bit value from a GPR to all bytes in the 256-bit destination subject to writemask k1.

vpbroadcastb ymm1 {k1} {z}, eax

; Broadcast an 8-bit value from a GPR to all bytes in the 512-bit destination subject to writemask k1.

vpbroadcastb zmm1 {k1} {z}, eax

; Broadcast a 16-bit value from a GPR to all words in the 128-bit destination subject to writemask k1.

vpbroadcastw xmm1 {k1} {z}, eax

; Broadcast a 16-bit value from a GPR to all words in the 256-bit destination subject to writemask k1.

vpbroadcastw ymm1 {k1} {z}, eax

; Broadcast a 16-bit value from a GPR to all words in the 512-bit destination subject to writemask k1.

vpbroadcastw ymm1 {k1} {z}, eax

; Broadcast a 32-bit value from a GPR to all double-words in the 128-bit destination subject to writemask k1.

vpbroadcastd xmm1 {k1} {z}, eax

; Broadcast a 32-bit value from a GPR to all double-words in the 256-bit destination subject to writemask k1.

vpbroadcastd ymm1 {k1} {z}, eax

; Broadcast a 32-bit value from a GPR to all double-words in the 512-bit destination subject to writemask k1.

vpbroadcastd zmm1 {k1} {z}, eax

; Broadcast a 64-bit value from a GPR to all quad-words in the 128-bit destination subject to writemask k1.

vpbroadcastq xmm1 {k1} {z}, rax

; Broadcast a 64-bit value from a GPR to all quad-words in the 256-bit destination subject to writemask k1.

vpbroadcastq ymm1 {k1} {z}, rax

; Broadcast a 64-bit value from a GPR to all quad-words in the 512-bit destination subject to writemask k1.

vpbroadcastq zmm1 {k1} {z}, rax

; Broadcast low byte value in k1 to two locations in xmm1.

vpbroadcastmb2q xmm1, k1

; Broadcast low byte value in k1 to four locations in ymm1.

vpbroadcastmb2q ymm1, k1

; Broadcast low byte value in k1 to eight locations in zmm1.

vpbroadcastmb2q zmm1, k1

; Broadcast low word value in k1 to four locations in xmm1.

vpbroadcastmw2d xmm1, k1

; Broadcast low word value in k1 to eight locations in ymm1.

vpbroadcastmw2d ymm1, k1

; Broadcast low word value in k1 to sixteen locations in zmm1.

vpbroadcastmw2d zmm1, k1

; Compare packed signed byte values in xmm3/m128 and xmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpb k1 {k2}, xmm2, xmm3, 0x69
vpcmpb k1 {k2}, xmm2, [rax], 0x69

; Compare packed signed byte values in ymm3/m256 and ymm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpb k1 {k2}, ymm2, ymm3, 0x69
vpcmpb k1 {k2}, ymm2, [rax], 0x69

; Compare packed signed byte values in zmm3/m512 and zmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpb k1 {k2}, zmm2, zmm3, 0x69
vpcmpb k1 {k2}, zmm2, [rax], 0x69

; Compare packed unsigned byte values in xmm3/m128 and xmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpub k1 {k2}, xmm2, xmm3, 0x69
vpcmpub k1 {k2}, xmm2, [rax], 0x69

; Compare packed unsigned byte values in ymm3/m256 and ymm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpub k1 {k2}, ymm2, ymm3, 0x69
vpcmpub k1 {k2}, ymm2, [rax], 0x69

; Compare packed unsigned byte values in zmm3/m512 and zmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpub k1 {k2}, zmm2, zmm3, 0x69
vpcmpub k1 {k2}, zmm2, [rax], 0x69

; Compare packed signed doubleword integer values in xmm3/m128/m32bcst and xmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpd k1 {k2}, xmm2, xmm3, 0x69
vpcmpd k1 {k2}, xmm2, [rax], 0x69

; Compare packed signed doubleword integer values in ymm3/m256/m32bcst and ymm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpd k1 {k2}, ymm2, ymm3, 0x69
vpcmpd k1 {k2}, ymm2, [rax], 0x69

; Compare packed signed doubleword integer values in zmm2 and zmm3/m512/m32bcst using bits 2:0 of imm8 as a comparison predicate. The comparison results are written to the destination k1 under writemask k2.

vpcmpd k1 {k2}, zmm2, zmm3, 0x69
vpcmpd k1 {k2}, zmm2, [rax], 0x69

; Compare packed unsigned doubleword integer values in xmm3/m128/m32bcst and xmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpud k1 {k2}, xmm2, xmm3, 0x69
vpcmpud k1 {k2}, xmm2, [rax], 0x69

; Compare packed unsigned doubleword integer values in ymm3/m256/m32bcst and ymm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpud k1 {k2}, ymm2, ymm3, 0x69
vpcmpud k1 {k2}, ymm2, [rax], 0x69

; Compare packed unsigned doubleword integer values in zmm2 and zmm3/m512/m32bcst using bits 2:0 of imm8 as a comparison predicate. The comparison results are written to the destination k1 under writemask k2.

vpcmpud k1 {k2}, zmm2, zmm3, 0x69
vpcmpud k1 {k2}, zmm2, [rax], 0x69

; Compare packed signed quadword integer values in xmm3/m128/m64bcst and xmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpq k1 {k2}, xmm2, xmm3, 0x69
vpcmpq k1 {k2}, xmm2, [rax], 0x69

; Compare packed signed quadword integer values in ymm3/m256/m64bcst and ymm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpq k1 {k2}, ymm2, ymm3, 0x69
vpcmpq k1 {k2}, ymm2, [rax], 0x69

; Compare packed signed quadword integer values in zmm3/m512/m64bcst and zmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpq k1 {k2}, zmm2, zmm3, 0x69
vpcmpq k1 {k2}, zmm2, [rax], 0x69

; Compare packed unsigned quadword integer values in xmm3/m128/m64bcst and xmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpuq k1 {k2}, xmm2, xmm3, 0x69
vpcmpuq k1 {k2}, xmm2, [rax], 0x69

; Compare packed unsigned quadword integer values in ymm3/m256/m64bcst and ymm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpuq k1 {k2}, ymm2, ymm3, 0x69
vpcmpuq k1 {k2}, ymm2, [rax], 0x69

; Compare packed unsigned quadword integer values in zmm3/m512/m64bcst and zmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpuq k1 {k2}, zmm2, zmm3, 0x69
vpcmpuq k1 {k2}, zmm2, [rax], 0x69

; Compare packed signed word integers in xmm3/m128 and xmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpw k1 {k2}, xmm2, xmm3, 0x69
vpcmpw k1 {k2}, xmm2, [rax], 0x69

; Compare packed signed word integers in ymm3/m256 and ymm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpw k1 {k2}, ymm2, ymm3, 0x69
vpcmpw k1 {k2}, ymm2, [rax], 0x69

; Compare packed signed word integers in zmm3/m512 and zmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpw k1 {k2}, zmm2, zmm3, 0x69
vpcmpw k1 {k2}, zmm2, [rax], 0x69

; Compare packed unsigned word integers in xmm3/m128 and xmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpuw k1 {k2}, xmm2, xmm3, 0x69
vpcmpuw k1 {k2}, xmm2, [rax], 0x69

; Compare packed unsigned word integers in ymm3/m256 and ymm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpuw k1 {k2}, ymm2, ymm3, 0x69
vpcmpuw k1 {k2}, ymm2, [rax], 0x69

; Compare packed unsigned word integers in zmm3/m512 and zmm2 using bits 2:0 of imm8 as a comparison predicate with writemask k2 and leave the result in mask register k1.

vpcmpuw k1 {k2}, zmm2, zmm3, 0x69
vpcmpuw k1 {k2}, zmm2, [rax], 0x69

; Compress packed doubleword integer values from xmm2 to xmm1/m128 using controlmask k1.

vpcompressd xmm1, xmm2
vpcompressd [rdi], xmm2

; Compress packed doubleword integer values from ymm2 to ymm1/m256 using controlmask k1.

vpcompressd ymm1, ymm2
vpcompressd [rdi], ymm2

; Compress packed doubleword integer values from zmm2 to zmm1/m512 using controlmask k1.

vpcompressd zmm1, zmm2
vpcompressd [rdi], zmm2

; Compress packed quadword integer values from xmm2 to xmm1/m128 using controlmask k1.

vpcompressq xmm1, xmm2
vpcompressq [rdi], xmm2

; Compress packed quadword integer values from ymm2 to ymm1/m256 using controlmask k1.

vpcompressq ymm1, ymm2
vpcompressq [rdi], ymm2

; Compress packed quadword integer values from zmm2 to zmm1/m512 using controlmask k1.

vpcompressq zmm1, zmm2
vpcompressq [rdi], zmm2

; Detect duplicate double-word values in xmm2/m128/m32bcst using writemask k1.

vpconflictd xmm1, xmm2
vpconflictd xmm1, [rax]

; Detect duplicate double-word values in ymm2/m256/m32bcst using writemask k1.

vpconflictd ymm1, ymm2
vpconflictd ymm1, [rax]

; Detect duplicate double-word values in zmm2/m512/m32bcst using writemask k1.

vpconflictd zmm1, zmm2
vpconflictd zmm1, [rax]

; Detect duplicate quad-word values in xmm2/m128/m64bcst using writemask k1.

vpconflictq xmm1, xmm2
vpconflictq xmm1, [rax]

; Detect duplicate quad-word values in ymm2/m256/m64bcst using writemask k1.

vpconflictq ymm1, ymm2
vpconflictq ymm1, [rax]

; Detect duplicate quad-word values in zmm2/m512/m64bcst using writemask k1.

vpconflictq zmm1, zmm2
vpconflictq zmm1, [rax]

; Permute bytes in xmm3/m128 using byte indexes in xmm2 and store the result in xmm1 using writemask k1.

vpermb xmm1, xmm2, xmm3
vpermb xmm1, xmm2, [rax]

; Permute bytes in ymm3/m256 using byte indexes in ymm2 and store the result in ymm1 using writemask k1.

vpermb ymm1, ymm2, ymm3
vpermb ymm1, ymm2, [rax]

; Permute bytes in zmm3/m512 using byte indexes in zmm2 and store the result in zmm1 using writemask k1.

vpermb zmm1, zmm2, zmm3
vpermb zmm1, zmm2, [rax]

; Permute bytes in xmm3/m128 and xmm2 using byte indexes in xmm1 and store the byte results in xmm1 using writemask k1.

vpermi2b xmm1, xmm2, xmm3
vpermi2b xmm1, xmm2, [rax]

; Permute bytes in ymm3/m256 and ymm2 using byte indexes in ymm1 and store the byte results in ymm1 using writemask k1.

vpermi2b ymm1, ymm2, ymm3
vpermi2b ymm1, ymm2, [rax]

; Permute bytes in zmm3/m512 and zmm2 using byte indexes in zmm1 and store the byte results in zmm1 using writemask k1.

vpermi2b zmm1, zmm2, zmm3
vpermi2b zmm1, zmm2, [rax]

; Permute word integers from two tables in xmm3/m128 and xmm2 using indexes in xmm1 and store the result in xmm1 using writemask k1.

vpermi2w xmm1, xmm2, xmm3
vpermi2w xmm1, xmm2, [rax]

; Permute word integers from two tables in ymm3/m256 and ymm2 using indexes in ymm1 and store the result in ymm1 using writemask k1.

vpermi2w ymm1, ymm2, ymm3
vpermi2w ymm1, ymm2, [rax]

; Permute word integers from two tables in zmm3/m512 and zmm2 using indexes in zmm1 and store the result in zmm1 using writemask k1.

vpermi2w zmm1, zmm2, zmm3
vpermi2w zmm1, zmm2, [rax]

; Permute double-words from two tables in xmm3/m128/m32bcst and xmm2 using indexes in xmm1 and store the result in xmm1 using writemask k1.

vpermi2d xmm1, xmm2, xmm3
vpermi2d xmm1, xmm2, [rax]

; Permute double-words from two tables in ymm3/m256/m32bcst and ymm2 using indexes in ymm1 and store the result in ymm1 using writemask k1.

vpermi2d ymm1, ymm2, ymm3
vpermi2d ymm1, ymm2, [rax]

; Permute double-words from two tables in zmm3/m512/m32bcst and zmm2 using indices in zmm1 and store the result in zmm1 using writemask k1.

vpermi2d zmm1, zmm2, zmm3
vpermi2d zmm1, zmm2, [rax]

; Permute quad-words from two tables in xmm3/m128/m64bcst and xmm2 using indexes in xmm1 and store the result in xmm1 using writemask k1.

vpermi2q xmm1, xmm2, xmm3
vpermi2q xmm1, xmm2, [rax]

; Permute quad-words from two tables in ymm3/m256/m64bcst and ymm2 using indexes in ymm1 and store the result in ymm1 using writemask k1.

vpermi2q ymm1, ymm2, ymm3
vpermi2q ymm1, ymm2, [rax]

; Permute quad-words from two tables in zmm3/m512/m64bcst and zmm2 using indices in zmm1 and store the result in zmm1 using writemask k1.

vpermi2q zmm1, zmm2, zmm3
vpermi2q zmm1, zmm2, [rax]

; Permute single-precision FP values from two tables in xmm3/m128/m32bcst and xmm2 using indexes in xmm1 and store the result in xmm1 using writemask k1.

vpermi2ps xmm1, xmm2, xmm3
vpermi2ps xmm1, xmm2, [rax]

; Permute single-precision FP values from two tables in ymm3/m256/m32bcst and ymm2 using indexes in ymm1 and store the result in ymm1 using writemask k1.

vpermi2ps ymm1, ymm2, ymm3
vpermi2ps ymm1, ymm2, [rax]

; Permute single-precision FP values from two tables in zmm3/m512/m32bcst and zmm2 using indices in zmm1 and store the result in zmm1 using writemask k1.

vpermi2ps zmm1, zmm2, zmm3
vpermi2ps zmm1, zmm2, [rax]

; Permute double-precision FP values from two tables in xmm3/m128/m32bcst and xmm2 using indexes in xmm1 and store the result in xmm1 using writemask k1.

vpermi2pd xmm1, xmm2, xmm3
vpermi2pd xmm1, xmm2, [rax]

; Permute double-precision FP values from two tables in ymm3/m256/m32bcst and ymm2 using indexes in ymm1 and store the result in ymm1 using writemask k1.

vpermi2pd ymm1, ymm2, ymm3
vpermi2pd ymm1, ymm2, [rax]

; Permute double-precision FP values from two tables in zmm3/m512/m32bcst and zmm2 using indices in zmm1 and store the result in zmm1 using writemask k1.

vpermi2pd zmm1, zmm2, zmm3
vpermi2pd zmm1, zmm2, [rax]

; Permute bytes in xmm3/m128 and xmm1 using byte indexes in xmm2 and store the byte results in xmm1 using writemask k1.

vpermt2b xmm1, xmm2, xmm3
vpermt2b xmm1, xmm2, [rax]

; Permute bytes in ymm3/m256 and ymm1 using byte indexes in ymm2 and store the byte results in ymm1 using writemask k1.

vpermt2b ymm1, ymm2, ymm3
vpermt2b ymm1, ymm2, [rax]

; Permute bytes in zmm3/m512 and zmm1 using byte indexes in zmm2 and store the byte results in zmm1 using writemask k1.

vpermt2b zmm1, zmm2, zmm3
vpermt2b zmm1, zmm2, [rax]

; Permute word integers from two tables in xmm3/m128 and xmm1 using indexes in xmm2 and store the result in xmm1 using writemask k1.Permute word integers from two tables in xmm3/m128 and xmm1 using indexes in xmm2 and store the result in xmm1 using writemask k1.

vpermt2w xmm1, xmm2, xmm3
vpermt2w xmm1, xmm2, [rax]

; Permute word integers from two tables in ymm3/m256 and ymm1 using indexes in ymm2 and store the result in ymm1 using writemask k1.

vpermt2w ymm1, ymm2, ymm3
vpermt2w ymm1, ymm2, [rax]

; Permute word integers from two tables in zmm3/m512 and zmm1 using indexes in zmm2 and store the result in zmm1 using writemask k1.

vpermt2w zmm1, zmm2, zmm3
vpermt2w zmm1, zmm2, [rax]

; Permute double-words from two tables in xmm3/m128/m32bcst and xmm1 using indexes in xmm2 and store the result in xmm1 using writemask k1.

vpermt2d xmm1, xmm2, xmm3
vpermt2d xmm1, xmm2, [rax]

; Permute double-words from two tables in ymm3/m256/m32bcst and ymm1 using indexes in ymm2 and store the result in ymm1 using writemask k1.

vpermt2d ymm1, ymm2, ymm3
vpermt2d ymm1, ymm2, [rax]

; Permute double-words from two tables in zmm3/m512/m32bcst and zmm1 using indices in zmm2 and store the result in zmm1 using writemask k1.

vpermt2d zmm1, zmm2, zmm3
vpermt2d zmm1, zmm2, [rax]

; Permute quad-words from two tables in xmm3/m128/m64bcst and xmm1 using indexes in xmm2 and store the result in xmm1 using writemask k1.

vpermt2q xmm1, xmm2, xmm3
vpermt2q xmm1, xmm2, [rax]

; Permute quad-words from two tables in ymm3/m256/m64bcst and ymm1 using indexes in ymm2 and store the result in ymm1 using writemask k1.

vpermt2q ymm1, ymm2, ymm3
vpermt2q ymm1, ymm2, [rax]

; Permute quad-words from two tables in zmm3/m512/m64bcst and zmm1 using indices in zmm2 and store the result in zmm1 using writemask k1.

vpermt2q zmm1, zmm2, zmm3
vpermt2q zmm1, zmm2, [rax]

; Permute single-precision FP values from two tables in xmm3/m128/m32bcst and xmm1 using indexes in xmm2 and store the result in xmm1 using writemask k1.

vpermt2ps xmm1, xmm2, xmm3
vpermt2ps xmm1, xmm2, [rax]

; Permute single-precision FP values from two tables in ymm3/m256/m32bcst and ymm1 using indexes in ymm2 and store the result in ymm1 using writemask k1.

vpermt2ps ymm1, ymm2, ymm3
vpermt2ps ymm1, ymm2, [rax]

; Permute single-precision FP values from two tables in zmm3/m512/m32bcst and zmm1 using indices in zmm2 and store the result in zmm1 using writemask k1.

vpermt2ps zmm1, zmm2, zmm3
vpermt2ps zmm1, zmm2, [rax]

; Permute double-precision FP values from two tables in xmm3/m128/m32bcst and xmm1 using indexes in xmm2 and store the result in xmm1 using writemask k1.

vpermt2pd xmm1, xmm2, xmm3
vpermt2pd xmm1, xmm2, [rax]

; Permute double-precision FP values from two tables in ymm3/m256/m32bcst and ymm1 using indexes in ymm2 and store the result in ymm1 using writemask k1.

vpermt2pd ymm1, ymm2, ymm3
vpermt2pd ymm1, ymm2, [rax]

; Permute double-precision FP values from two tables in zmm3/m512/m32bcst and zmm1 using indices in zmm2 and store the result in zmm1 using writemask k1.

vpermt2pd zmm1, zmm2, zmm3
vpermt2pd zmm1, zmm2, [rax]

; Expand packed double-word integer values from xmm2/m128 to xmm1 using writemask k1.

vpexpandd xmm1, xmm3
vpexpandd xmm1, [rax]

; Expand packed double-word integer values from ymm2/m256 to ymm1 using writemask k1.

vpexpandd ymm1, ymm3
vpexpandd ymm1, [rax]

; Expand packed double-word integer values from zmm2/m512 to zmm1 using writemask k1.

vpexpandd zmm1, zmm3
vpexpandd zmm1, [rax]

; Expand packed quad-word integer values from xmm2/m128 to xmm1 using writemask k1.

vpexpandq xmm1, xmm3
vpexpandq xmm1, [rax]

; Expand packed quad-word integer values from ymm2/m256 to ymm1 using writemask k1.

vpexpandq ymm1, ymm3
vpexpandq ymm1, [rax]

; Expand packed quad-word integer values from zmm2/m512 to zmm1 using writemask k1.

vpexpandq zmm1, zmm3
vpexpandq zmm1, [rax]

; Using signed dword indices, gather dword values from memory using writemask k1 for merging-masking.

vpgatherdd xmm1 {k1}, [xmm2]

; Using signed dword indices, gather dword values from memory using writemask k1 for merging-masking.

vpgatherdd ymm1 {k1}, [ymm2]

; Using signed dword indices, gather dword values from memory using writemask k1 for merging-masking.

vpgatherdd zmm1 {k1}, [zmm2]

; Using signed dword indices, gather quadword values from memory using writemask k1 for merging-masking.

vpgatherdq xmm1 {k1}, [xmm2]

; Using signed dword indices, gather quadword values from memory using writemask k1 for merging-masking.

vpgatherdq ymm1 {k1}, [xmm2]

; Using signed dword indices, gather quadword values from memory using writemask k1 for merging-masking.

vpgatherdq zmm1 {k1}, [ymm2]

; Using signed qword indices, gather dword values from memory using writemask k1 for merging-masking.

vpgatherqd xmm1 {k1}, [xmm1]

; Using signed qword indices, gather dword values from memory using writemask k1 for merging-masking.

vpgatherqd ymm1 {k1}, [zmm1]

; Using signed qword indices, gather dword values from memory using writemask k1 for merging-masking.

vpgatherqd ymm1 {k1}, [zmm1]

; Using signed qword indices, gather quadword values from memory using writemask k1 for merging-masking.

vpgatherqq xmm1 {k1}, [xmm1]

; Using signed qword indices, gather quadword values from memory using writemask k1 for merging-masking.

vpgatherqq ymm1 {k1}, [ymm1]

; Using signed qword indices, gather quadword values from memory using writemask k1 for merging-masking.

vpgatherqq zmm1 {k1}, [zmm1]

; Count the number of leading zero bits in each dword element of xmm2/m128/m32bcst using writemask k1.
; TODO: m32cst 2nd arg possible

vplzcntd xmm1, xmm2
vplzcntd xmm1, [rax]

; Count the number of leading zero bits in each dword element of ymm2/m256/m32bcst using writemask k1.
; TODO: m32cst 2nd arg possible

vplzcntd ymm1, ymm2
vplzcntd ymm1, [rax]

; Count the number of leading zero bits in each dword element of zmm2/m512/m32bcst using writemask k1.
; TODO: m32cst 2nd arg possible

vplzcntd zmm1, zmm2
vplzcntd zmm1, [rax]

; Count the number of leading zero bits in each qword element of xmm2/m128/m64bcst using writemask k1.
; TODO: m64cst 2nd arg possible

vplzcntq xmm1, xmm2
vplzcntq xmm1, [rax]

; Count the number of leading zero bits in each qword element of ymm2/m256/m64bcst using writemask k1.
; TODO: m64cst 2nd arg possible

vplzcntq ymm1, ymm2
vplzcntq ymm1, [rax]

; Count the number of leading zero bits in each qword element of zmm2/m512/m64bcst using writemask k1.
; TODO: m64cst 2nd arg possible

vplzcntq zmm1, zmm2
vplzcntq zmm1, [rax]

; Multiply unsigned 52-bit integers in xmm2 and xmm3/m128 and add the high 52 bits of the 104-bit product to the qword unsigned integers in xmm1 using writemask k1.
; TODO: m64cst 2nd arg possible

vpmadd52huq xmm1, xmm2, xmm3
vpmadd52huq xmm1, xmm2, [rax]

; Multiply unsigned 52-bit integers in ymm2 and ymm3/m128 and add the high 52 bits of the 104-bit product to the qword unsigned integers in ymm1 using writemask k1.
; TODO: m64cst 2nd arg possible

vpmadd52huq ymm1, ymm2, ymm3
vpmadd52huq ymm1, ymm2, [rax]

; Multiply unsigned 52-bit integers in zmm2 and zmm3/m128 and add the high 52 bits of the 104-bit product to the qword unsigned integers in zmm1 using writemask k1.
; TODO: m64cst 2nd arg possible

vpmadd52huq zmm1, zmm2, zmm3
vpmadd52huq zmm1, zmm2, [rax]


; Multiply unsigned 52-bit integers in xmm2 and xmm3/m128 and add the low 52 bits of the 104-bit product to the qword unsigned integers in xmm1 using writemask k1.
; TODO: m64cst 2nd arg possible

vpmadd52luq xmm1, xmm2, xmm3
vpmadd52luq xmm1, xmm2, [rax]

; Multiply unsigned 52-bit integers in ymm2 and ymm3/m128 and add the low 52 bits of the 104-bit product to the qword unsigned integers in ymm1 using writemask k1.
; TODO: m64cst 2nd arg possible

vpmadd52luq ymm1, ymm2, ymm3
vpmadd52luq ymm1, ymm2, [rax]

; Multiply unsigned 52-bit integers in zmm2 and zmm3/m128 and add the low 52 bits of the 104-bit product to the qword unsigned integers in zmm1 using writemask k1.
; TODO: m64cst 2nd arg possible

vpmadd52luq zmm1, zmm2, zmm3
vpmadd52luq zmm1, zmm2, [rax]

; Sets each bit in k1 to 1 or 0 based on the value of the most significant bit of the corresponding byte in XMM1.

vpmovb2m k1, xmm1

; Sets each bit in k1 to 1 or 0 based on the value of the most significant bit of the corresponding byte in YMM1.

vpmovb2m k1, ymm1

; Sets each bit in k1 to 1 or 0 based on the value of the most significant bit of the corresponding byte in ZMM1.

vpmovb2m k1, zmm1

; Sets each bit in k1 to 1 or 0 based on the value of the most significant bit of the corresponding word in XMM1.

vpmovw2m k1, xmm1

; Sets each bit in k1 to 1 or 0 based on the value of the most significant bit of the corresponding word in YMM1.

vpmovw2m k1, ymm1

; Sets each bit in k1 to 1 or 0 based on the value of the most significant bit of the corresponding word in ZMM1.

vpmovw2m k1, zmm1

; Sets each bit in k1 to 1 or 0 based on the value of the most significant bit of the corresponding doubleword in XMM1.

vpmovd2m k1, xmm1

; Sets each bit in k1 to 1 or 0 based on the value of the most significant bit of the corresponding doubleword in YMM1.

vpmovd2m k1, ymm1

; Sets each bit in k1 to 1 or 0 based on the value of the most significant bit of the corresponding doubleword in ZMM1.

vpmovd2m k1, zmm1

; Sets each bit in k1 to 1 or 0 based on the value of the most significant bit of the corresponding quadword in XMM1.

vpmovq2m k1, xmm1

; Sets each bit in k1 to 1 or 0 based on the value of the most significant bit of the corresponding quadword in YMM1.

vpmovq2m k1, ymm1

; Sets each bit in k1 to 1 or 0 based on the value of the most significant bit of the corresponding quadword in ZMM1.

vpmovq2m k1, zmm1

; Converts 4 packed double-word integers from xmm2 into 4 packed byte integers in xmm1/m32 with truncation under writemask k1.

vpmovdb xmm1, xmm2
vpmovdb [rax], xmm2

; Converts 4 packed signed double-word integers from xmm2 into 4 packed signed byte integers in xmm1/m32 using signed saturation under writemask k1.

vpmovsdb xmm1, xmm2
vpmovsdb [rax], xmm2

; Converts 4 packed unsigned double-word integers from xmm2 into 4 packed unsigned byte integers in xmm1/m32 using unsigned saturation under writemask k1.

vpmovusdb xmm1, xmm2
vpmovusdb [rax], xmm2

; Converts 8 packed double-word integers from ymm2 into 8 packed byte integers in xmm1/m64 with truncation under writemask k1.

vpmovsdb xmm1, ymm2
vpmovsdb [rax], ymm2

; Converts 8 packed signed double-word integers from ymm2 into 8 packed signed byte integers in xmm1/m64 using signed saturation under writemask k1.

vpmovsdb xmm1, ymm2
vpmovsdb [rax], ymm2

; Converts 8 packed unsigned double-word integers from ymm2 into 8 packed unsigned byte integers in xmm1/m64 using unsigned saturation under writemask k1.

vpmovusdb xmm1, ymm2
vpmovusdb [rax], ymm2

; Converts 16 packed double-word integers from zmm2 into 16 packed byte integers in xmm1/m128 with truncation under writemask k1.

vpmovsdb xmm1, zmm2
vpmovsdb [rax], zmm2

; Converts 16 packed signed double-word integers from zmm2 into 16 packed signed byte integers in xmm1/m128 using signed saturation under writemask k1.

vpmovsdb xmm1, zmm2
vpmovsdb [rax], zmm2

; Converts 16 packed unsigned double-word integers from zmm2 into 16 packed unsigned byte integers in xmm1/m128 using unsigned saturation under writemask k1.

vpmovusdb xmm1, zmm2
vpmovusdb [rax], zmm2

; Converts 4 packed double-word integers from xmm2 into 4 packed word integers in xmm1/m32 with truncation under writemask k1.

vpmovdw xmm1, xmm2
vpmovdw [rax], xmm2

; Converts 4 packed signed double-word integers from xmm2 into 4 packed signed word integers in xmm1/m32 using signed saturation under writemask k1.

vpmovsdw xmm1, xmm2
vpmovsdw [rax], xmm2

; Converts 4 packed unsigned double-word integers from xmm2 into 4 packed unsigned word integers in xmm1/m32 using unsigned saturation under writemask k1.

vpmovusdw xmm1, xmm2
vpmovusdw [rax], xmm2

; Converts 8 packed double-word integers from ymm2 into 8 packed word integers in xmm1/m64 with truncation under writemask k1.

vpmovsdw xmm1, ymm2
vpmovsdw [rax], ymm2

; Converts 8 packed signed double-word integers from ymm2 into 8 packed signed word integers in xmm1/m64 using signed saturation under writemask k1.

vpmovsdw xmm1, ymm2
vpmovsdw [rax], ymm2

; Converts 8 packed unsigned double-word integers from ymm2 into 8 packed unsigned word integers in xmm1/m64 using unsigned saturation under writemask k1.

vpmovusdw xmm1, ymm2
vpmovusdw [rax], ymm2

; Converts 16 packed double-word integers from zmm2 into 16 packed word integers in xmm1/m128 with truncation under writemask k1.

vpmovsdw ymm1, zmm2
vpmovsdw [rax], zmm2

; Converts 16 packed signed double-word integers from zmm2 into 16 packed signed word integers in xmm1/m128 using signed saturation under writemask k1.

vpmovsdw ymm1, zmm2
vpmovsdw [rax], zmm2

; Converts 16 packed unsigned double-word integers from zmm2 into 16 packed unsigned word integers in xmm1/m128 using unsigned saturation under writemask k1.

vpmovusdw ymm1, zmm2
vpmovusdw [rax], zmm2

; Sets each byte in XMM1 to all 1’s or all 0’s based on the value of the corresponding bit in k1.

vpmovm2b xmm1, k1

; Sets each byte in YMM1 to all 1’s or all 0’s based on the value of the corresponding bit in k1.

vpmovm2b ymm1, k1

; Sets each byte in ZMM1 to all 1’s or all 0’s based on the value of the corresponding bit in k1.

vpmovm2b zmm1, k1

; Sets each word in XMM1 to all 1’s or all 0’s based on the value of the corresponding bit in k1.

vpmovm2w xmm1, k1

; Sets each word in YMM1 to all 1’s or all 0’s based on the value of the corresponding bit in k1.

vpmovm2w ymm1, k1

; Sets each word in ZMM1 to all 1’s or all 0’s based on the value of the corresponding bit in k1.

vpmovm2w zmm1, k1

; Sets each doubleword in XMM1 to all 1’s or all 0’s based on the value of the corresponding bit in k1.

vpmovm2d xmm1, k1

; Sets each doubleword in YMM1 to all 1’s or all 0’s based on the value of the corresponding bit in k1.

vpmovm2d ymm1, k1

; Sets each doubleword in ZMM1 to all 1’s or all 0’s based on the value of the corresponding bit in k1.

vpmovm2d zmm1, k1

; Sets each quadword in XMM1 to all 1’s or all 0’s based on the value of the corresponding bit in k1.

vpmovm2q xmm1, k1

; Sets each quadword in YMM1 to all 1’s or all 0’s based on the value of the corresponding bit in k1.

vpmovm2q ymm1, k1

; Sets each quadword in ZMM1 to all 1’s or all 0’s based on the value of the corresponding bit in k1.

vpmovm2q ymm1, k1

; Converts 2 packed quad-word integers from xmm2 into 2 packed byte integers in xmm1/m16 with truncation under writemask k1.

vpmovqb xmm1, xmm2
vpmovqb [rax], xmm2

; Converts 2 packed signed quad-word integers from xmm2 into 2 packed signed byte integers in xmm1/m16 using signed saturation under writemask k1.

vpmovsqb xmm1, xmm2
vpmovsqb [rax], xmm2

; Converts 2 packed unsigned quad-word integers from xmm2 into 2 packed unsigned byte integers in xmm1/m16 using unsigned saturation under writemask k1.

vpmovusqb xmm1, xmm2
vpmovusqb [rax], xmm2

; Converts 4 packed quad-word integers from ymm2 into 4 packed byte integers in xmm1/m32 with truncation under writemask k1.

vpmovqb xmm1, ymm2
vpmovqb [rax], ymm2

; Converts 4 packed signed quad-word integers from ymm2 into 4 packed signed byte integers in xmm1/m32 using signed saturation under writemask k1.

vpmovsqb xmm1, ymm2
vpmovsqb [rax], ymm2

; Converts 4 packed unsigned quad-word integers from ymm2 into 4 packed unsigned byte integers in xmm1/m32 using unsigned saturation under writemask k1.

vpmovusqb xmm1, ymm2
vpmovusqb [rax], ymm2

; Converts 8 packed quad-word integers from zmm2 into 8 packed byte integers in xmm1/m64 with truncation under writemask k1.

vpmovqb xmm1, zmm2
vpmovqb [rax], zmm2

; Converts 8 packed signed quad-word integers from zmm2 into 8 packed signed byte integers in xmm1/m64 using signed saturation under writemask k1.

vpmovsqb xmm1, zmm2
vpmovsqb [rax], zmm2

; Converts 8 packed unsigned quad-word integers from zmm2 into 8 packed unsigned byte integers in xmm1/m64 using unsigned saturation under writemask k1.

vpmovusqb xmm1, zmm2
vpmovusqb [rax], zmm2

; Converts 2 packed quad-word integers from xmm2 into 2 packed double-word integers in xmm1/m16 with truncation under writemask k1.

vpmovqd xmm1, xmm2
vpmovqd [rax], xmm2

; Converts 2 packed signed quad-word integers from xmm2 into 2 packed signed double-word integers in xmm1/m16 using signed saturation under writemask k1.

vpmovsqd xmm1, xmm2
vpmovsqd [rax], xmm2

; Converts 2 packed unsigned quad-word integers from xmm2 into 2 packed unsigned double-word integers in xmm1/m16 using unsigned saturation under writemask k1.

vpmovusqd xmm1, xmm2
vpmovusqd [rax], xmm2

; Converts 4 packed quad-word integers from ymm2 into 4 packed double-word integers in xmm1/m32 with truncation under writemask k1.

vpmovqd xmm1, ymm2
vpmovqd [rax], ymm2

; Converts 4 packed signed quad-word integers from ymm2 into 4 packed signed double-word integers in xmm1/m32 using signed saturation under writemask k1.

vpmovsqd xmm1, ymm2
vpmovsqd [rax], ymm2

; Converts 4 packed unsigned quad-word integers from ymm2 into 4 packed unsigned double-word integers in xmm1/m32 using unsigned saturation under writemask k1.

vpmovusqd xmm1, ymm2
vpmovusqd [rax], ymm2

; Converts 8 packed quad-word integers from zmm2 into 8 packed double-word integers in xmm1/m64 with truncation under writemask k1.

vpmovqd ymm1, zmm2
vpmovqd [rax], zmm2

; Converts 8 packed signed quad-word integers from zmm2 into 8 packed signed double-word integers in xmm1/m64 using signed saturation under writemask k1.

vpmovsqd ymm1, zmm2
vpmovsqd [rax], zmm2

; Converts 8 packed unsigned quad-word integers from zmm2 into 8 packed unsigned double-word integers in xmm1/m64 using unsigned saturation under writemask k1.

vpmovusqd ymm1, zmm2
vpmovusqd [rax], zmm2

; Converts 2 packed quad-word integers from xmm2 into 2 packed word integers in xmm1/m16 with truncation under writemask k1.

vpmovqw xmm1, xmm2
vpmovqw [rax], xmm2

; Converts 2 packed signed quad-word integers from xmm2 into 2 packed signed word integers in xmm1/m16 using signed saturation under writemask k1.

vpmovsqw xmm1, xmm2
vpmovsqw [rax], xmm2

; Converts 2 packed unsigned quad-word integers from xmm2 into 2 packed unsigned word integers in xmm1/m16 using unsigned saturation under writemask k1.

vpmovusqw xmm1, xmm2
vpmovusqw [rax], xmm2

; Converts 4 packed quad-word integers from ymm2 into 4 packed word integers in xmm1/m32 with truncation under writemask k1.

vpmovqw xmm1, ymm2
vpmovqw [rax], ymm2

; Converts 4 packed signed quad-word integers from ymm2 into 4 packed signed word integers in xmm1/m32 using signed saturation under writemask k1.

vpmovsqw xmm1, ymm2
vpmovsqw [rax], ymm2

; Converts 4 packed unsigned quad-word integers from ymm2 into 4 packed unsigned word integers in xmm1/m32 using unsigned saturation under writemask k1.

vpmovusqw xmm1, ymm2
vpmovusqw [rax], ymm2

; Converts 8 packed quad-word integers from zmm2 into 8 packed word integers in xmm1/m64 with truncation under writemask k1.

vpmovqw xmm1, zmm2
vpmovqw [rax], zmm2

; Converts 8 packed signed quad-word integers from zmm2 into 8 packed signed word integers in xmm1/m64 using signed saturation under writemask k1.

vpmovsqw xmm1, zmm2
vpmovsqw [rax], zmm2

; Converts 8 packed unsigned quad-word integers from zmm2 into 8 packed unsigned word integers in xmm1/m64 using unsigned saturation under writemask k1.

vpmovusqw xmm1, zmm2
vpmovusqw [rax], zmm2

; Converts 8 packed word integers from xmm2 into 8 packed bytes in xmm1/m64 with truncation under writemask k1.

vpmovwb xmm1, xmm2
vpmovwb [rax], xmm2

; Converts 8 packed signed word integers from xmm2 into 8 packed signed bytes in xmm1/m64 using signed saturation under writemask k1.

vpmovswb xmm1, xmm2
vpmovswb [rax], xmm2

; Converts 8 packed unsigned word integers from xmm2 into 8 packed unsigned bytes in 8mm1/m64 using unsigned saturation under writemask k1.

vpmovuswb xmm1, xmm2
vpmovuswb [rax], xmm2

; Converts 16 packed word integers from ymm2 into 16 packed bytes in xmm1/m128 with truncation under writemask k1.

vpmovwb xmm1, ymm2
vpmovwb [rax], ymm2

; Converts 16 packed signed word integers from ymm2 into 16 packed signed bytes in xmm1/m128 using signed saturation under writemask k1.

vpmovswb xmm1, ymm2
vpmovswb [rax], ymm2

; Converts 16 packed unsigned word integers from ymm2 into 16 packed unsigned bytes in xmm1/m128 using unsigned saturation under writemask k1.

vpmovuswb xmm1, ymm2
vpmovuswb [rax], ymm2

; Converts 32 packed word integers from zmm2 into 32 packed bytes in ymm1/m256 with truncation under writemask k1.

vpmovwb ymm1, zmm2
vpmovwb [rax], zmm2

; Converts 32 packed signed word integers from zmm2 into 32 packed signed bytes in ymm1/m256 using signed saturation under writemask k1.

vpmovswb ymm1, zmm2
vpmovswb [rax], zmm2

; Converts 32 packed unsigned word integers from zmm2 into 32 packed unsigned bytes in ymm1/m256 using unsigned saturation under writemask k1.

vpmovuswb ymm1, zmm2
vpmovuswb [rax], zmm2

; Select unaligned bytes from qwords in xmm3/m128/m64bcst using control bytes in xmm2, write byte results to xmm1 under k1.

vpmultishiftqb xmm1, xmm2, xmm3
vpmultishiftqb xmm1, xmm2, [rax]

; Select unaligned bytes from qwords in ymm3/m256/m64bcst using control bytes in ymm2, write byte results to ymm1 under k1.

vpmultishiftqb ymm1, ymm2, ymm3
vpmultishiftqb ymm1, ymm2, [rax]

; Select unaligned bytes from qwords in zmm3/m512/m64bcst using control bytes in zmm2, write byte results to zmm1 under k1.

vpmultishiftqb zmm1, zmm2, zmm3
vpmultishiftqb zmm1, zmm2, [rax]

; Rotate doublewords in xmm2 left by count in the corresponding element of xmm3/m128/m32bcst. Result written to xmm1 under writemask k1.

vprolvd xmm1, xmm2, xmm3
vprolvd xmm1, xmm2, [rax]

; Rotate doublewords in xmm2/m128/m32bcst left by imm8. Result written to xmm1 using writemask k1.

vprold xmm1, xmm3, 0x69
vprold xmm1, [rax], 0x69

; Rotate quadwords in xmm2 left by count in the corresponding element of xmm3/m128/m64bcst. Result written to xmm1 under writemask k1.

vprolvq xmm1, xmm2, xmm3
vprolvq xmm1, xmm2, [rax]

; Rotate quadwords in xmm2/m128/m64bcst left by imm8. Result written to xmm1 using writemask k1.

vprolq xmm1, xmm3, 0x69
vprolq xmm1, [rax], 0x69

; Rotate doublewords in ymm2 left by count in the corresponding element of ymm3/m256/m32bcst. Result written to ymm1 under writemask k1.

vprolvd ymm1, ymm2, ymm3
vprolvd ymm1, ymm2, [rax]

; Rotate doublewords in ymm2/m256/m32bcst left by imm8. Result written to ymm1 using writemask k1.

vprold ymm1, ymm3, 0x69
vprold ymm1, [rax], 0x69

; Rotate quadwords in ymm2 left by count in the corresponding element of ymm3/m256/m64bcst. Result written to ymm1 under writemask k1.

vprolvq ymm1, ymm2, ymm3
vprolvq ymm1, ymm2, [rax]

; Rotate quadwords in ymm2 left by count in the corresponding element of ymm3/m256/m64bcst. Result written to ymm1 under writemask k1.

vprolq ymm1, ymm3, 0x69
vprolq ymm1, [rax], 0x69

; Rotate left of doublewords in zmm2 by count in the corresponding element of zmm3/m512/m32bcst. Result written to zmm1 using writemask k1.

vprolvd zmm1, zmm2, zmm3
vprolvd zmm1, zmm2, [rax]

; Rotate left of doublewords in zmm3/m512/m32bcst by imm8. Result written to zmm1 using writemask k1.

vprold zmm1, zmm3, 0x69
vprold zmm1, [rax], 0x69

; Rotate quadwords in zmm2 left by count in the corresponding element of zmm3/m512/m64bcst. Result written to zmm1under writemask k1.

vprolvq zmm1, zmm2, zmm3
vprolvq zmm1, zmm2, [rax]

; Rotate quadwords in zmm2/m512/m64bcst left by imm8. Result written to zmm1 using writemask k1.

vprolvq zmm1, zmm2, zmm3
vprolvq zmm1, zmm2, [rax]

; Rotate doublewords in xmm2 right by count in the corresponding element of xmm3/m128/m32bcst. Result written to xmm1 under writemask k1.

vprorvd xmm1, xmm2, xmm3
vprorvd xmm1, xmm2, [rax]

; Rotate doublewords in xmm2/m128/m32bcst right by imm8. Result written to xmm1 using writemask k1.

vprord xmm1, xmm3, 0x69
vprord xmm1, [rax], 0x69

; Rotate quadwords in xmm2 right by count in the corresponding element of xmm3/m128/m64bcst. Result written to xmm1 under writemask k1.

vprorvq xmm1, xmm2, xmm3
vprorvq xmm1, xmm2, [rax]

; Rotate quadwords in xmm2/m128/m64bcst right by imm8. Result written to xmm1 using writemask k1.

vprorq xmm1, xmm3, 0x69
vprorq xmm1, [rax], 0x69

; Rotate doublewords in ymm2 right by count in the corresponding element of ymm3/m256/m32bcst. Result written to ymm1 under writemask k1.

vprorvd ymm1, ymm2, ymm3
vprorvd ymm1, ymm2, [rax]

; Rotate doublewords in ymm2/m256/m32bcst right by imm8. Result written to ymm1 using writemask k1.

vprord ymm1, ymm3, 0x69
vprord ymm1, [rax], 0x69

; Rotate quadwords in ymm2 right by count in the corresponding element of ymm3/m256/m64bcst. Result written to ymm1 under writemask k1.

vprorvq ymm1, ymm2, ymm3
vprorvq ymm1, ymm2, [rax]

; Rotate quadwords in ymm2 right by count in the corresponding element of ymm3/m256/m64bcst. Result written to ymm1 under writemask k1.

vprorq ymm1, ymm3, 0x69
vprorq ymm1, [rax], 0x69

; Rotate right of doublewords in zmm2 by count in the corresponding element of zmm3/m512/m32bcst. Result written to zmm1 using writemask k1.

vprorvd zmm1, zmm2, zmm3
vprorvd zmm1, zmm2, [rax]

; Rotate right of doublewords in zmm3/m512/m32bcst by imm8. Result written to zmm1 using writemask k1.

vprord zmm1, zmm3, 0x69
vprord zmm1, [rax], 0x69

; Rotate quadwords in zmm2 right by count in the corresponding element of zmm3/m512/m64bcst. Result written to zmm1under writemask k1.

vprorvq zmm1, zmm2, zmm3
vprorvq zmm1, zmm2, [rax]

; Rotate quadwords in zmm2/m512/m64bcst right by imm8. Result written to zmm1 using writemask k1.

vprorvq zmm1, zmm2, zmm3
vprorvq zmm1, zmm2, [rax]

; Using signed dword indices, scatter dword values to memory using writemask k1.

vpscatterdd [xmm1], xmm1

; Using signed dword indices, scatter dword values to memory using writemask k1.

vpscatterdd [ymm1], ymm1

; Using signed dword indices, scatter dword values to memory using writemask k1.

vpscatterdd [zmm1], zmm1

; Using signed dword indices, scatter qword values to memory using writemask k1.

vpscatterdq [xmm1], xmm1

; Using signed dword indices, scatter qword values to memory using writemask k1.

vpscatterdq [xmm1], ymm1

; Using signed dword indices, scatter qword values to memory using writemask k1.

vpscatterdq [ymm1], zmm1

; Using signed qword indices, scatter dword values to memory using writemask k1.

vpscatterqd [xmm1], xmm1

; Using signed qword indices, scatter dword values to memory using writemask k1.

vpscatterqd [ymm1], xmm1

; Using signed qword indices, scatter dword values to memory using writemask k1.

vpscatterqd [zmm1], ymm1

; Using signed qword indices, scatter qword values to memory using writemask k1.

vpscatterqq [xmm1], xmm1

; Using signed qword indices, scatter qword values to memory using writemask k1.

vpscatterqq [ymm1], ymm1

; Using signed qword indices, scatter qword values to memory using writemask k1.

vpscatterqq [zmm1], zmm1

; Bitwise ternary logic taking xmm1, xmm2 and xmm3/m128/m32bcst as source operands and writing the result to xmm1 under writemask k1 with dword granularity. The immediate value determines the specific binary function being implemented.
; TODO: m32cst 2nd arg possible

vpternlogd xmm1, xmm2, xmm3, 0x69
vpternlogd xmm1, xmm2, [rax], 0x69

; Bitwise ternary logic taking ymm1, ymm2 and ymm3/m256/m32bcst as source operands and writing the result to ymm1 under writemask k1 with dword granularity. The immediate value determines the specific binary function being implemented.
; TODO: m32cst 3rd arg possible

vpternlogd ymm1, ymm2, ymm3, 0x69
vpternlogd ymm1, ymm2, [rax], 0x69

; Bitwise ternary logic taking zmm1, zmm2 and zmm3/m512/m32bcst as source operands and writing the result to zmm1 under writemask k1 with dword granularity. The immediate value determines the specific binary function being implemented.
; TODO: m32cst 3rd arg possible

vpternlogd zmm1, zmm2, zmm3, 0x69
vpternlogd zmm1, zmm2, [rax], 0x69

; Bitwise ternary logic taking xmm1, xmm2 and xmm3/m128/m64bcst as source operands and writing the result to xmm1 under writemask k1 with qword granularity. The immediate value determines the specific binary function being implemented.
; TODO: m64cst 3rd arg possible

vpternlogq xmm1, xmm2, xmm3, 0x69
vpternlogq xmm1, xmm2, [rax], 0x69

; Bitwise ternary logic taking ymm1, ymm2 and ymm3/m256/m64bcst as source operands and writing the result to ymm1 under writemask k1 with qword granularity. The immediate value determines the specific binary function being implemented.
; TODO: m64cst 3rd arg possible

vpternlogq ymm1, ymm2, ymm3, 0x69
vpternlogq ymm1, ymm2, [rax], 0x69

; Bitwise ternary logic taking zmm1, zmm2 and zmm3/m512/m64bcst as source operands and writing the result to zmm1 under writemask k1 with qword granularity. The immediate value determines the specific binary function being implemented.
; TODO: m64cst 3rd arg possible

vpternlogq zmm1, zmm2, zmm3, 0x69
vpternlogq zmm1, zmm2, [rax], 0x69

; Bitwise AND of packed byte integers in xmm2 and xmm3/m128 and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.

vptestmb k1, xmm2, xmm3
vptestmb k1, xmm2, [rax]

; Bitwise AND of packed byte integers in ymm2 and ymm3/m256 and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.

vptestmb k1, ymm2, ymm3
vptestmb k1, ymm2, [rax]

; Bitwise AND of packed byte integers in zmm2 and zmm3/m512 and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.

vptestmb k1, zmm2, zmm3
vptestmb k1, zmm2, [rax]

; Bitwise AND of packed word integers in xmm2 and xmm3/m128 and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.

vptestmw k1, xmm2, xmm3
vptestmw k1, xmm2, [rax]

; Bitwise AND of packed word integers in ymm2 and ymm3/m256 and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.

vptestmw k1, ymm2, ymm3
vptestmw k1, ymm2, [rax]

; Bitwise AND of packed word integers in zmm2 and zmm3/m512 and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.

vptestmw k1, zmm2, zmm3
vptestmw k1, zmm2, [rax]

; Bitwise AND of packed doubleword integers in xmm2 and xmm3/m128/m32bcst and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.
; TODO: m32cst 2nd arg possible

vptestmd k1, xmm2, xmm3
vptestmd k1, xmm2, [rax]

; Bitwise AND of packed doubleword integers in ymm2 and ymm3/m256/m32bcst and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.
; TODO: m32cst 2nd arg possible

vptestmd k1, ymm2, ymm3
vptestmd k1, ymm2, [rax]

; Bitwise AND of packed doubleword integers in zmm2 and zmm3/m512/m32bcst and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.
; TODO: m32cst 2nd arg possible

vptestmd k1, zmm2, zmm3
vptestmd k1, zmm2, [rax]

; Bitwise AND of packed quadword integers in xmm2 and xmm3/m128/m64bcst and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.
; TODO: m64cst 2nd arg possible

vptestmq k1, xmm2, xmm3
vptestmq k1, xmm2, [rax]

; Bitwise AND of packed quadword integers in ymm2 and ymm3/m256/m64bcst and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.
; TODO: m64cst 2nd arg possible

vptestmq k1, ymm2, ymm3
vptestmq k1, ymm2, [rax]

; Bitwise AND of packed quadword integers in zmm2 and zmm3/m512/m64bcst and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.
; TODO: m64cst 2nd arg possible

vptestmq k1, zmm2, zmm3
vptestmq k1, zmm2, [rax]

; Bitwise NAND of packed byte integers in xmm2 and xmm3/m128 and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.

vptestnmb k1, xmm2, xmm3
vptestnmb k1, xmm2, [rax]

; Bitwise NAND of packed byte integers in ymm2 and ymm3/m256 and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.

vptestnmb k1, ymm2, ymm3
vptestnmb k1, ymm2, [rax]

; Bitwise NAND of packed byte integers in zmm2 and zmm3/m512 and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.

vptestnmb k1, zmm2, zmm3
vptestnmb k1, zmm2, [rax]

; Bitwise NAND of packed word integers in xmm2 and xmm3/m128 and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.

vptestnmw k1, xmm2, xmm3
vptestnmw k1, xmm2, [rax]

; Bitwise NAND of packed word integers in ymm2 and ymm3/m256 and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.

vptestnmw k1, ymm2, ymm3
vptestnmw k1, ymm2, [rax]

; Bitwise NAND of packed word integers in zmm2 and zmm3/m512 and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.

vptestnmw k1, zmm2, zmm3
vptestnmw k1, zmm2, [rax]

; Bitwise NAND of packed doubleword integers in xmm2 and xmm3/m128/m32bcst and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.
; TODO: m32cst 2nd arg possible

vptestnmd k1, xmm2, xmm3
vptestnmd k1, xmm2, [rax]

; Bitwise NAND of packed doubleword integers in ymm2 and ymm3/m256/m32bcst and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.
; TODO: m32cst 2nd arg possible

vptestnmd k1, ymm2, ymm3
vptestnmd k1, ymm2, [rax]

; Bitwise NAND of packed doubleword integers in zmm2 and zmm3/m512/m32bcst and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.
; TODO: m32cst 2nd arg possible

vptestnmd k1, zmm2, zmm3
vptestnmd k1, zmm2, [rax]

; Bitwise NAND of packed quadword integers in xmm2 and xmm3/m128/m64bcst and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.
; TODO: m64cst 2nd arg possible

vptestnmq k1, xmm2, xmm3
vptestnmq k1, xmm2, [rax]

; Bitwise NAND of packed quadword integers in ymm2 and ymm3/m256/m64bcst and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.
; TODO: m64cst 2nd arg possible

vptestnmq k1, ymm2, ymm3
vptestnmq k1, ymm2, [rax]

; Bitwise NAND of packed quadword integers in zmm2 and zmm3/m512/m64bcst and set mask k2 to reflect the zero/non-zero status of each element of the result, under writemask k1.
; TODO: m64cst 2nd arg possible

vptestnmq k1, zmm2, zmm3
vptestnmq k1, zmm2, [rax]

; Calculate two RANGE operation output value from 2 pairs of double-precision floating-point values in xmm2 and xmm3/m128/m32bcst, store the results to xmm1 under the writemask k1. Imm8 specifies the comparison and sign of the range operation.
; TODO: m64cst 3rd arg possible

vrangepd xmm1, xmm2, xmm3, 0x69
vrangepd xmm1, xmm2, [rax], 0x69

; Calculate four RANGE operation output value from 4pairs of double-precision floating-point values in ymm2 and ymm3/m256/m32bcst, store the results to ymm1 under the writemask k1. Imm8 specifies the comparison and sign of the range operation.
; TODO: m64cst 3rd arg possible

vrangepd ymm1, ymm2, ymm3, 0x69
vrangepd ymm1, ymm2, [rax], 0x69

; Calculate eight RANGE operation output value from 8 pairs of double-precision floating-point values in zmm2 and zmm3/m512/m32bcst, store the results to zmm1 under the writemask k1. Imm8 specifies the comparison and sign of the range operation.
; TODO: m64cst 3rd arg possible

vrangepd zmm1, zmm2, zmm3, 0x69
vrangepd zmm1, zmm2, [rax], 0x69

; Calculate two RANGE operation output value from 2 pairs of single-precision floating-point values in xmm2 and xmm3/m128/m32bcst, store the results to xmm1 under the writemask k1. Imm8 specifies the comparison and sign of the range operation.
; TODO: m64cst 3rd arg possible

vrangeps xmm1, xmm2, xmm3, 0x69
vrangeps xmm1, xmm2, [rax], 0x69

; Calculate four RANGE operation output value from 4pairs of single-precision floating-point values in ymm2 and ymm3/m256/m32bcst, store the results to ymm1 under the writemask k1. Imm8 specifies the comparison and sign of the range operation.
; TODO: m64cst 3rd arg possible

vrangeps ymm1, ymm2, ymm3, 0x69
vrangeps ymm1, ymm2, [rax], 0x69

; Calculate eight RANGE operation output value from 8 pairs of single-precision floating-point values in zmm2 and zmm3/m512/m32bcst, store the results to zmm1 under the writemask k1. Imm8 specifies the comparison and sign of the range operation.
; TODO: m64cst 3rd arg possible

vrangeps zmm1, zmm2, zmm3, 0x69
vrangeps zmm1, zmm2, [rax], 0x69

; Calculate a RANGE operation output value from 2 double-precision floating-point values in xmm2 and xmm3/m64, store the output to xmm1 under writemask. Imm8 specifies the comparison and sign of the range operation.

vrangesd xmm1, xmm2, xmm3, 0x69
vrangesd xmm1, xmm2, [rax], 0x69

; Calculate a RANGE operation output value from 2 single-precision floating-point values in xmm2 and xmm3/m64, store the output to xmm1 under writemask. Imm8 specifies the comparison and sign of the range operation.

vrangess xmm1, xmm2, xmm3, 0x69
vrangess xmm1, xmm2, [rax], 0x69

; Computes the approximate reciprocals of the packed double-precision floating-point values in xmm2/m128/m64bcst and stores the results in xmm1. Under writemask.
; TODO: m64cst 2nd arg possible

vrcp14pd xmm1, xmm2
vrcp14pd xmm1, [rax]

; Computes the approximate reciprocals of the packed double-precision floating-point values in ymm2/m256/m64bcst and stores the results in ymm1. Under writemask.
; TODO: m64cst 2nd arg possible

vrcp14pd ymm1, ymm2
vrcp14pd ymm1, [rax]

; Computes the approximate reciprocals of the packed double-precision floating-point values in zmm2/m512/m64bcst and stores the results in zmm1. Under writemask.
; TODO: m64cst 2nd arg possible

vrcp14pd zmm1, zmm2
vrcp14pd zmm1, [rax]

; Computes the approximate reciprocals of the packed single-precision floating-point values in xmm2/m128/m64bcst and stores the results in xmm1. Under writemask.
; TODO: m64cst 2nd arg possible

vrcp14ps xmm1, xmm2
vrcp14ps xmm1, [rax]

; Computes the approximate reciprocals of the packed single-precision floating-point values in ymm2/m256/m64bcst and stores the results in ymm1. Under writemask.
; TODO: m64cst 2nd arg possible

vrcp14ps ymm1, ymm2
vrcp14ps ymm1, [rax]

; Computes the approximate reciprocals of the packed single-precision floating-point values in zmm2/m512/m64bcst and stores the results in zmm1. Under writemask.
; TODO: m64cst 2nd arg possible

vrcp14ps zmm1, zmm2
vrcp14ps zmm1, [rax]

; Computes the approximate reciprocal of the scalar double-precision floating-point value in xmm3/m64 and stores the result in xmm1 using writemask k1. Also, upper double-precision floating-point value (bits[127:64]) from xmm2 is copied to xmm1[127:64].

vrcp14sd xmm1, xmm2
vrcp14sd xmm1, [rax]

; Computes the approximate reciprocal of the scalar single-precision floating-point value in xmm3/m32 and stores the results in xmm1 using writemask k1. Also, upper double-precision floating-point value (bits[127:32]) from xmm2 is copied to xmm1[127:32].

vrcp14ss xmm1, xmm2
vrcp14ss xmm1, [rax]

; Perform reduction transformation on packed double-precision floating point values in xmm2/m128/m32bcst by subtracting a number of fraction bits specified by the imm8 field. Stores the result in xmm1 register under writemask k1.
; TODO: m64cst 2nd arg possible

vreducepd xmm1, xmm2, 0x69
vreducepd xmm1, [rax], 0x69

; Perform reduction transformation on packed double-precision floating point values in ymm2/m256/m32bcst by subtracting a number of fraction bits specified by the imm8 field. Stores the result in ymm1 register under writemask k1.
; TODO: m64cst 2nd arg possible

vreducepd ymm1, ymm2, 0x69
vreducepd ymm1, [rax], 0x69

; Perform reduction transformation on double-precision floating point values in zmm2/m512/m32bcst by subtracting a number of fraction bits specified by the imm8 field. Stores the result in zmm1 register under writemask k1.
; TODO: m64cst 2nd arg possible

vreducepd zmm1, zmm2, 0x69
vreducepd zmm1, [rax], 0x69

; Perform reduction transformation on packed single-precision floating point values in xmm2/m128/m32bcst by subtracting a number of fraction bits specified by the imm8 field. Stores the result in xmm1 register under writemask k1.
; TODO: m32cst 2nd arg possible

vreduceps xmm1, xmm2, 0x69
vreduceps xmm1, [rax], 0x69

; Perform reduction transformation on packed single-precision floating point values in ymm2/m256/m32bcst by subtracting a number of fraction bits specified by the imm8 field. Stores the result in ymm1 register under writemask k1.
; TODO: m32cst 2nd arg possible

vreduceps ymm1, ymm2, 0x69
vreduceps ymm1, [rax], 0x69

; Perform reduction transformation on single-precision floating point values in zmm2/m512/m32bcst by subtracting a number of fraction bits specified by the imm8 field. Stores the result in zmm1 register under writemask k1.
; TODO: m32cst 2nd arg possible

vreduceps zmm1, zmm2, 0x69
vreduceps zmm1, [rax], 0x69

; Perform a reduction transformation on a scalar double-precision floating point value in xmm3/m64 by subtracting a number of fraction bits specified by the imm8 field. Also, upper double precision floating-point value (bits[127:64]) from xmm2 are copied to xmm1[127:64]. Stores the result in xmm1 register.

vreducesd xmm1, xmm2, 0x69
vreducesd xmm1, [rax], 0x69

; Perform a reduction transformation on a scalar single-precision floating point value in xmm3/m64 by subtracting a number of fraction bits specified by the imm8 field. Also, upper double precision floating-point value (bits[127:64]) from xmm2 are copied to xmm1[127:64]. Stores the result in xmm1 register.

vreducess xmm1, xmm2, 0x69
vreducess xmm1, [rax], 0x69

; Rounds packed double-precision floating point values in xmm2/m128/m64bcst to a number of fraction bits specified by the imm8 field. Stores the result in xmm1 register. Under writemask.

vrndscalepd xmm1, xmm2, 0x69
vrndscalepd xmm1, [rax], 0x69

; Rounds packed double-precision floating point values in ymm2/m256/m64bcst to a number of fraction bits specified by the imm8 field. Stores the result in ymm1 register. Under writemask.

vrndscalepd ymm1, ymm2, 0x69
vrndscalepd ymm1, [rax], 0x69

; Rounds packed double-precision floating-point values in zmm2/m512/m64bcst to a number of fraction bits specified by the imm8 field. Stores the result in zmm1 register using writemask k1.

vrndscalepd zmm1, zmm2, 0x69
vrndscalepd zmm1, [rax], 0x69

; Rounds packed single-precision floating point values in xmm2/m128/m64bcst to a number of fraction bits specified by the imm8 field. Stores the result in xmm1 register. Under writemask.

vrndscaleps xmm1, xmm2, 0x69
vrndscaleps xmm1, [rax], 0x69

; Rounds packed single-precision floating point values in ymm2/m256/m64bcst to a number of fraction bits specified by the imm8 field. Stores the result in ymm1 register. Under writemask.

vrndscaleps ymm1, ymm2, 0x69
vrndscaleps ymm1, [rax], 0x69

; Rounds packed single-precision floating-point values in zmm2/m512/m64bcst to a number of fraction bits specified by the imm8 field. Stores the result in zmm1 register using writemask k1.

vrndscaleps zmm1, zmm2, 0x69
vrndscaleps zmm1, [rax], 0x69

; Rounds scalar double-precision floating-point value in xmm3/m64 to a number of fraction bits specified by the imm8 field. Stores the result in xmm1 register.

vrndscalesd xmm1, xmm2, 0x69
vrndscalesd xmm1, [rax], 0x69

; Rounds scalar single-precision floating-point value in xmm3/m64 to a number of fraction bits specified by the imm8 field. Stores the result in xmm1 register.

vrndscaless xmm1, xmm2, 0x69
vrndscaless xmm1, [rax], 0x69

; Computes the approximate reciprocal square roots of the packed double-precision floating-point values in xmm2/m128/m64bcst and stores the results in xmm1. Under writemask.

vrsqrt14pd xmm1, xmm2
vrsqrt14pd xmm1, [rax]

; Computes the approximate reciprocal square roots of the packed double-precision floating-point values in ymm2/m256/m64bcst and stores the results in ymm1. Under writemask.

vrsqrt14pd ymm1, ymm2
vrsqrt14pd ymm1, [rax]

; Computes the approximate reciprocal square roots of the packed double-precision floating-point values in zmm2/m512/m64bcst and stores the results in zmm1 under writemask.

vrsqrt14pd zmm1, zmm2
vrsqrt14pd zmm1, [rax]

; Computes the approximate reciprocal square roots of the packed single-precision floating-point values in xmm2/m128/m64bcst and stores the results in xmm1. Under writemask.

vrsqrt14ps xmm1, xmm2
vrsqrt14ps xmm1, [rax]

; Computes the approximate reciprocal square roots of the packed single-precision floating-point values in ymm2/m256/m64bcst and stores the results in ymm1. Under writemask.

vrsqrt14ps ymm1, ymm2
vrsqrt14ps ymm1, [rax]

; Computes the approximate reciprocal square roots of the packed single-precision floating-point values in zmm2/m512/m64bcst and stores the results in zmm1 under writemask.

vrsqrt14ps zmm1, zmm2
vrsqrt14ps zmm1, [rax]

; Computes the approximate reciprocal square root of the scalar double-precision floating-point value in xmm3/m64 and stores the result in the low quadword element of xmm1 using writemask k1. Bits[127:64] of xmm2 is copied to xmm1[127:64].

vrsqrt14sd xmm1, xmm2
vrsqrt14sd xmm1, [rax]

; Computes the approximate reciprocal square root of the scalar single-precision floating-point value in xmm3/m64 and stores the result in the low quadword element of xmm1 using writemask k1. Bits[127:64] of xmm2 is copied to xmm1[127:64].

vrsqrt14ss xmm1, xmm2
vrsqrt14ss xmm1, [rax]

; Scale the packed double-precision floating-point values in xmm2 using values from xmm3/m128/m64bcst. Under writemask k1.

vscalefpd xmm1, xmm2, xmm3
vscalefpd xmm1, xmm2, [rax]

; Scale the packed double-precision floating-point values in ymm2 using values from ymm3/m256/m64bcst. Under writemask k1.

vscalefpd ymm1, ymm2, ymm3
vscalefpd ymm1, ymm2, [rax]

; Scale the packed double-precision floating-point values in zmm2 using values from zmm3/m512/m64bcst. Under writemask k1.

vscalefpd zmm1, zmm2, zmm3
vscalefpd zmm1, zmm2, [rax]

; Scale the packed single-precision floating-point values in xmm2 using values from xmm3/m128/m64bcst. Under writemask k1.

vscalefps xmm1, xmm2, xmm3
vscalefps xmm1, xmm2, [rax]

; Scale the packed single-precision floating-point values in ymm2 using values from ymm3/m256/m64bcst. Under writemask k1.

vscalefps ymm1, ymm2, ymm3
vscalefps ymm1, ymm2, [rax]

; Scale the packed single-precision floating-point values in zmm2 using values from zmm3/m512/m64bcst. Under writemask k1.

vscalefps zmm1, zmm2, zmm3
vscalefps zmm1, zmm2, [rax]

; Scale the scalar double-precision floating-point values in xmm2 using the value from xmm3/m64. Under writemask k1.

vscalefsd xmm1, xmm2, xmm3
vscalefsd xmm1, xmm2, [rax]

; Scale the scalar single-precision floating-point values in xmm2 using the value from xmm3/m64. Under writemask k1.

vscalefss xmm1, xmm2, xmm3
vscalefss xmm1, xmm2, [rax]

; Using signed dword indices, scatter single-precision floating-point values to memory using writemask k1.

vscatterdps [xmm1], xmm1

; Using signed dword indices, scatter single-precision floating-point values to memory using writemask k1.

vscatterdps [ymm1], ymm1

; Using signed dword indices, scatter single-precision floating-point values to memory using writemask k1.

vscatterdps [zmm1], zmm1

; Using signed dword indices, scatter double-precision floating-point values to memory using writemask k1.

vscatterdpd [xmm1], xmm1

; Using signed dword indices, scatter double-precision floating-point values to memory using writemask k1.

vscatterdpd [xmm1], ymm1

; Using signed dword indices, scatter double-precision floating-point values to memory using writemask k1.

vscatterdpd [ymm1], zmm1

; Using signed qword indices, scatter single-precision floating-point values to memory using writemask k1.

vscatterqps [xmm1], xmm1

; Using signed qword indices, scatter single-precision floating-point values to memory using writemask k1.

vscatterqps [ymm1], xmm1

; Using signed qword indices, scatter single-precision floating-point values to memory using writemask k1.

vscatterqps [zmm1], ymm1

; Using signed qword indices, scatter double-precision floating-point values to memory using writemask k1.

vscatterqpd [xmm1], xmm1

; Using signed qword indices, scatter double-precision floating-point values to memory using writemask k1.

vscatterqpd [ymm1], ymm1

; Using signed qword indices, scatter double-precision floating-point values to memory using writemask k1.

vscatterqpd [zmm1], zmm1

; Shuffle 128-bit packed single-precision floating-point values selected by imm8 from ymm2 and ymm3/m256/m32bcst and place results in ymm1 subject to writemask k1.

vshuff32x4 ymm1, ymm2, ymm3, 0x69
vshuff32x4 ymm1, ymm2, [rax], 0x69

; Shuffle 128-bit packed single-precision floating-point values selected by imm8 from zmm2 and zmm3/m512/m32bcst and place results in zmm1 subject to writemask k1.

vshuff32x4 zmm1, zmm2, zmm3, 0x69
vshuff32x4 zmm1, zmm2, [rax], 0x69

; Shuffle 128-bit packed double-precision floating-point values selected by imm8 from ymm2 and ymm3/m256/m64bcst and place results in ymm1 subject to writemask k1.

vshuff64x2 ymm1, ymm2, ymm3, 0x69
vshuff64x2 ymm1, ymm2, [rax], 0x69

; Shuffle 128-bit packed double-precision floating-point values selected by imm8 from zmm2 and zmm3/m512/m64bcst and place results in zmm1 subject to writemask k1.

vshuff64x2 zmm1, zmm2, zmm3, 0x69
vshuff64x2 zmm1, zmm2, [rax], 0x69

; Shuffle 128-bit packed double-word values selected by imm8 from ymm2 and ymm3/m256/m32bcst and place results in ymm1 subject to writemask k1.

vshufi32x4 ymm1, ymm2, ymm3, 0x69
vshufi32x4 ymm1, ymm2, [rax], 0x69

; Shuffle 128-bit packed double-word values selected by imm8 from zmm2 and zmm3/m512/m32bcst and place results in zmm1 subject to writemask k1.

vshufi32x4 zmm1, zmm2, zmm3, 0x69
vshufi32x4 zmm1, zmm2, [rax], 0x69

; Shuffle 128-bit packed quad-word values selected by imm8 from ymm2 and ymm3/m256/m64bcst and place results in ymm1 subject to writemask k1.

vshufi64x2 ymm1, ymm2, ymm3, 0x69
vshufi64x2 ymm1, ymm2, [rax], 0x69

; Shuffle 128-bit packed quad-word values selected by imm8 from zmm2 and zmm3/m512/m64bcst and place results in zmm1 subject to writemask k1.

vshufi64x2 zmm1, zmm2, zmm3, 0x69
vshufi64x2 zmm1, zmm2, [rax], 0x69
