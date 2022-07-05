
; Fused Multiply-Add of Packed Single-Precision Floating-Point Values

vfmadd132ps xmm0, xmm1, xmm2
vfmadd132ps xmm0, xmm1, [rax]

vfmadd213ps xmm0, xmm1, xmm2
vfmadd213ps xmm0, xmm1, [rax]

vfmadd231ps xmm0, xmm1, xmm2
vfmadd231ps xmm0, xmm1, [rax]

vfmadd132ps ymm0, ymm1, ymm2
vfmadd132ps ymm0, ymm1, [rax]

vfmadd213ps ymm0, ymm1, ymm2
vfmadd213ps ymm0, ymm1, [rax]

vfmadd231ps ymm0, ymm1, ymm2
vfmadd231ps ymm0, ymm1, [rax]

; Fused Multiply-Add of Packed Double-Precision Floating-Point Values

vfmadd132pd xmm0, xmm1, xmm2
vfmadd132pd xmm0, xmm1, [rax]

vfmadd213pd xmm0, xmm1, xmm2
vfmadd213pd xmm0, xmm1, [rax]

vfmadd231pd xmm0, xmm1, xmm2
vfmadd231pd xmm0, xmm1, [rax]

vfmadd132pd ymm0, ymm1, ymm2
vfmadd132pd ymm0, ymm1, [rax]

vfmadd213pd ymm0, ymm1, ymm2
vfmadd213pd ymm0, ymm1, [rax]

vfmadd231pd ymm0, ymm1, ymm2
vfmadd231pd ymm0, ymm1, [rax]

; Fused Multiply-Add of Scalar Single-Precision Floating-Point Values

vfmadd132ss xmm0, xmm1, xmm2
vfmadd132ss xmm0, xmm1, [rax]

vfmadd213ss xmm0, xmm1, xmm2
vfmadd213ss xmm0, xmm1, [rax]

vfmadd231ss xmm0, xmm1, xmm2
vfmadd231ss xmm0, xmm1, [rax]

; Fused Multiply-Add of Scalar Double-Precision Floating-Point Values

vfmadd132sd xmm0, xmm1, xmm2
vfmadd132sd xmm0, xmm1, [rax]

vfmadd213sd xmm0, xmm1, xmm2
vfmadd213sd xmm0, xmm1, [rax]

vfmadd231sd xmm0, xmm1, xmm2
vfmadd231sd xmm0, xmm1, [rax]

; Fused Multiply-Alternating Add/Subtract of Packed Single-Precision Floating-Point Values

vfmaddsub132ps xmm0, xmm1, xmm2
vfmaddsub132ps xmm0, xmm1, [rax]

vfmaddsub213ps xmm0, xmm1, xmm2
vfmaddsub213ps xmm0, xmm1, [rax]

vfmaddsub231ps xmm0, xmm1, xmm2
vfmaddsub231ps xmm0, xmm1, [rax]

vfmaddsub132ps ymm0, ymm1, ymm2
vfmaddsub132ps ymm0, ymm1, [rax]

vfmaddsub213ps ymm0, ymm1, ymm2
vfmaddsub213ps ymm0, ymm1, [rax]

vfmaddsub231ps ymm0, ymm1, ymm2
vfmaddsub231ps ymm0, ymm1, [rax]

; Fused Multiply-Alternating Add/Subtract of Packed Double-Precision Floating-Point Values

vfmaddsub132pd xmm0, xmm1, xmm2
vfmaddsub132pd xmm0, xmm1, [rax]

vfmaddsub213pd xmm0, xmm1, xmm2
vfmaddsub213pd xmm0, xmm1, [rax]

vfmaddsub231pd xmm0, xmm1, xmm2
vfmaddsub231pd xmm0, xmm1, [rax]

vfmaddsub132pd ymm0, ymm1, ymm2
vfmaddsub132pd ymm0, ymm1, [rax]

vfmaddsub213pd ymm0, ymm1, ymm2
vfmaddsub213pd ymm0, ymm1, [rax]

vfmaddsub231pd ymm0, ymm1, ymm2
vfmaddsub231pd ymm0, ymm1, [rax]

; Fused Multiply-Alternating Subtract/Add of Packed Single-Precision Floating-Point Values

vfmsubadd132ps xmm0, xmm1, xmm2
vfmsubadd132ps xmm0, xmm1, [rax]

vfmsubadd213ps xmm0, xmm1, xmm2
vfmsubadd213ps xmm0, xmm1, [rax]

vfmsubadd231ps xmm0, xmm1, xmm2
vfmsubadd231ps xmm0, xmm1, [rax]

vfmsubadd132ps ymm0, ymm1, ymm2
vfmsubadd132ps ymm0, ymm1, [rax]

vfmsubadd213ps ymm0, ymm1, ymm2
vfmsubadd213ps ymm0, ymm1, [rax]

vfmsubadd231ps ymm0, ymm1, ymm2
vfmsubadd231ps ymm0, ymm1, [rax]

; Fused Multiply-Alternating Subtract/Add of Packed Double-Precision Floating-Point Values

vfmsubadd132pd xmm0, xmm1, xmm2
vfmsubadd132pd xmm0, xmm1, [rax]

vfmsubadd213pd xmm0, xmm1, xmm2
vfmsubadd213pd xmm0, xmm1, [rax]

vfmsubadd231pd xmm0, xmm1, xmm2
vfmsubadd231pd xmm0, xmm1, [rax]

vfmsubadd132pd ymm0, ymm1, ymm2
vfmsubadd132pd ymm0, ymm1, [rax]

vfmsubadd213pd ymm0, ymm1, ymm2
vfmsubadd213pd ymm0, ymm1, [rax]

vfmsubadd231pd ymm0, ymm1, ymm2
vfmsubadd231pd ymm0, ymm1, [rax]

; Fused Multiply-Subtract of Packed Single-Precision Floating-Point Values

vfmsub132ps xmm0, xmm1, xmm2
vfmsub132ps xmm0, xmm1, [rax]

vfmsub213ps xmm0, xmm1, xmm2
vfmsub213ps xmm0, xmm1, [rax]

vfmsub231ps xmm0, xmm1, xmm2
vfmsub231ps xmm0, xmm1, [rax]

vfmsub132ps ymm0, ymm1, ymm2
vfmsub132ps ymm0, ymm1, [rax]

vfmsub213ps ymm0, ymm1, ymm2
vfmsub213ps ymm0, ymm1, [rax]

vfmsub231ps ymm0, ymm1, ymm2
vfmsub231ps ymm0, ymm1, [rax]

; Fused Multiply-Subtract of Packed Double-Precision Floating-Point Values

vfmsub132pd xmm0, xmm1, xmm2
vfmsub132pd xmm0, xmm1, [rax]

vfmsub213pd xmm0, xmm1, xmm2
vfmsub213pd xmm0, xmm1, [rax]

vfmsub231pd xmm0, xmm1, xmm2
vfmsub231pd xmm0, xmm1, [rax]

vfmsub132pd ymm0, ymm1, ymm2
vfmsub132pd ymm0, ymm1, [rax]

vfmsub213pd ymm0, ymm1, ymm2
vfmsub213pd ymm0, ymm1, [rax]

vfmsub231pd ymm0, ymm1, ymm2
vfmsub231pd ymm0, ymm1, [rax]

; Fused Multiply-Subtract of Scalar Single-Precision Floating-Point Values

vfmsub132ss xmm0, xmm1, xmm2
vfmsub132ss xmm0, xmm1, [rax]

vfmsub213ss xmm0, xmm1, xmm2
vfmsub213ss xmm0, xmm1, [rax]

vfmsub231ss xmm0, xmm1, xmm2
vfmsub231ss xmm0, xmm1, [rax]

; Fused Multiply-Subtract of Scalar Double-Precision Floating-Point Values

vfmsub132sd xmm0, xmm1, xmm2
vfmsub132sd xmm0, xmm1, [rax]

vfmsub213sd xmm0, xmm1, xmm2
vfmsub213sd xmm0, xmm1, [rax]

vfmsub231sd xmm0, xmm1, xmm2
vfmsub231sd xmm0, xmm1, [rax]

; Fused Negative Multiply-Add of Packed Single-Precision Floating-Point Values

vfnmadd132ps xmm0, xmm1, xmm2
vfnmadd132ps xmm0, xmm1, [rax]

vfnmadd213ps xmm0, xmm1, xmm2
vfnmadd213ps xmm0, xmm1, [rax]

vfnmadd231ps xmm0, xmm1, xmm2
vfnmadd231ps xmm0, xmm1, [rax]

vfnmadd132ps ymm0, ymm1, ymm2
vfnmadd132ps ymm0, ymm1, [rax]

vfnmadd213ps ymm0, ymm1, ymm2
vfnmadd213ps ymm0, ymm1, [rax]

vfnmadd231ps ymm0, ymm1, ymm2
vfnmadd231ps ymm0, ymm1, [rax]

; Fused Negative Multiply-Add of Packed Double-Precision Floating-Point Values

vfnmadd132pd xmm0, xmm1, xmm2
vfnmadd132pd xmm0, xmm1, [rax]

vfnmadd213pd xmm0, xmm1, xmm2
vfnmadd213pd xmm0, xmm1, [rax]

vfnmadd231pd xmm0, xmm1, xmm2
vfnmadd231pd xmm0, xmm1, [rax]

vfnmadd132pd ymm0, ymm1, ymm2
vfnmadd132pd ymm0, ymm1, [rax]

vfnmadd213pd ymm0, ymm1, ymm2
vfnmadd213pd ymm0, ymm1, [rax]

vfnmadd231pd ymm0, ymm1, ymm2
vfnmadd231pd ymm0, ymm1, [rax]

; Fused Negative Multiply-Add of Scalar Single-Precision Floating-Point Values

vfnmadd132ss xmm0, xmm1, xmm2
vfnmadd132ss xmm0, xmm1, [rax]

vfnmadd213ss xmm0, xmm1, xmm2
vfnmadd213ss xmm0, xmm1, [rax]

vfnmadd231ss xmm0, xmm1, xmm2
vfnmadd231ss xmm0, xmm1, [rax]

; Fused Negative Multiply-Add of Scalar Double-Precision Floating-Point Values

vfnmadd132sd xmm0, xmm1, xmm2
vfnmadd132sd xmm0, xmm1, [rax]

vfnmadd213sd xmm0, xmm1, xmm2
vfnmadd213sd xmm0, xmm1, [rax]

vfnmadd231sd xmm0, xmm1, xmm2
vfnmadd231sd xmm0, xmm1, [rax]

; Fused Negative Multiply-Subtract of Packed Single-Precision Floating-Point Values

vfnmsub132ps xmm0, xmm1, xmm2
vfnmsub132ps xmm0, xmm1, [rax]

vfnmsub213ps xmm0, xmm1, xmm2
vfnmsub213ps xmm0, xmm1, [rax]

vfnmsub231ps xmm0, xmm1, xmm2
vfnmsub231ps xmm0, xmm1, [rax]

vfnmsub132ps ymm0, ymm1, ymm2
vfnmsub132ps ymm0, ymm1, [rax]

vfnmsub213ps ymm0, ymm1, ymm2
vfnmsub213ps ymm0, ymm1, [rax]

vfnmsub231ps ymm0, ymm1, ymm2
vfnmsub231ps ymm0, ymm1, [rax]

; Fused Negative Multiply-Subtract of Packed Double-Precision Floating-Point Values

vfnmsub132pd xmm0, xmm1, xmm2
vfnmsub132pd xmm0, xmm1, [rax]

vfnmsub213pd xmm0, xmm1, xmm2
vfnmsub213pd xmm0, xmm1, [rax]

vfnmsub231pd xmm0, xmm1, xmm2
vfnmsub231pd xmm0, xmm1, [rax]

vfnmsub132pd ymm0, ymm1, ymm2
vfnmsub132pd ymm0, ymm1, [rax]

vfnmsub213pd ymm0, ymm1, ymm2
vfnmsub213pd ymm0, ymm1, [rax]

vfnmsub231pd ymm0, ymm1, ymm2
vfnmsub231pd ymm0, ymm1, [rax]

; Fused Negative Multiply-Subtract of Scalar Single-Precision Floating-Point Values

vfnmsub132ss xmm0, xmm1, xmm2
vfnmsub132ss xmm0, xmm1, [rax]

vfnmsub213ss xmm0, xmm1, xmm2
vfnmsub213ss xmm0, xmm1, [rax]

vfnmsub231ss xmm0, xmm1, xmm2
vfnmsub231ss xmm0, xmm1, [rax]

; Fused Negative Multiply-Subtract of Scalar Double-Precision Floating-Point Values

vfnmsub132sd xmm0, xmm1, xmm2
vfnmsub132sd xmm0, xmm1, [rax]

vfnmsub213sd xmm0, xmm1, xmm2
vfnmsub213sd xmm0, xmm1, [rax]

vfnmsub231sd xmm0, xmm1, xmm2
vfnmsub231sd xmm0, xmm1, [rax]
