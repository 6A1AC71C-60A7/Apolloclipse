
; Compute 2x–1

f2xm1

; Absolute Value

fabs

; Add

fadd DWORD [r15]
fadd QWORD [r15]
fadd st0, st0
fadd st0, st7
fadd st7, st0
fadd st7
faddp
faddp st7
fiadd DWORD [rax]
fiadd WORD [rax]

; Load Binary Coded Decimal

fbld [rax]

; Store BCD Integer and Pop

fbstp [r15]

; Change Sign

fchs

; Clear Exceptions

fclex
fnclex

; Compare Floating Point Values

fcom DWORD [r14]
fcom QWORD [r14]
fcom st7
fcom
fcomp DWORD [r8]
fcomp QWORD [r8]
fcomp st7
fcomp
fcompp

; Decrement Stack-Top Pointer

fdecstp

; Divide

fdiv DWORD [rsi]
fdiv QWORD [rsi]
fdiv st0, st0
fdiv st0, st1
fdiv st1, st0
fdiv
fdivp st0, st0
fdivp st1, st0
fdivp
fidiv WORD [rdi]
fidiv DWORD [rdi]

; Reverse Divide

fdivr DWORD [rsi]
fdivr QWORD [rsi]
fdivr st0, st0
fdivr st0, st1
fdivr st1, st0
fdivr
fdivrp st0, st0
fdivrp st1, st0
fdivrp
fidivr WORD [rdi]
fidivr DWORD [rdi]

; Free Floating-Point Register

ffree st7

; Compare Integer

ficom WORD [rbx]
ficom DWORD [rbx]
ficomp WORD [rbx]
ficomp DWORD [rbx]

; Load Integer

fild WORD [rdx]
fild DWORD [rdx]
fild QWORD [rdx]

; Increment Stack-Top Pointer

fincstp

; Initialize Floating-Point Unit

finit
fninit

; Store Integer

fist WORD [rcx]
fist DWORD [rcx]
fistp WORD [rcx]
fistp DWORD [rcx]
fistp QWORD [rcx]

; Load Floating Point Value

fld DWORD [rax]
fld QWORD [rax]
; TODO: m80fp
fld st7

; Load Constant

fld1
fldl2t
fldl2e
fldpi
fldlg2
fldln2
fldz

; Load x87 FPU Control Word

fldcw WORD [rax]

; Load x87 FPU Environment

fldenv [rax]
fstenv [rax]

; Multiply

fmul DWORD [rax]
fmul QWORD [rax]
fmul st0, st0
fmul st0, st7
fmul st7, st0
fmul
fmulp st0, st0
fmulp st7, st0
fmulp
fimul WORD [rax]
fimul DWORD [rax]

; No Operation

fnop

; Partial Arctangent

fpatan

; Partial Remainder

fprem

; Partial Tangent

fptan

; Round to Integer

frndint

; Restore x87 FPU State

frstor [r15]

; Store x87 FPU State

fsave [r14]
fnsave [r14]

; Scale

fscale

; Square Root

fsqrt

; Store Floating Point Value

fst DWORD [rax]
fst QWORD [rax]
fst st7
fstp DWORD [rax]
fstp QWORD [rax]
; TODO: m80fp
fstp st7

; Subtract

fsub DWORD [rax]
fsub QWORD [rax]
fsub st0, st0
fsub st0, st7
fsub st7, st0
fsub
fsubp st0, st0
fsubp st7, st0
fsubp
fisub WORD [rax]
fisub DWORD [rax]

; Reverse Subtract

fsubr DWORD [rax]
fsubr QWORD [rax]
fsubr st0, st0
fsubr st0, st7
fsubr st7, st0
fsubr
fsubrp st0, st0
fsubrp st7, st0
fsubrp
fisubr WORD [rax]
fisubr DWORD [rax]

; TEST

ftst

; Wait

; NOTE: No longuer possible to display these 2, however they are perfecty parsed

; wait
; fwait

; Examine Floating-Point

fxam

; Exchange Register Contents

fxch st7
fxch

; Extract Exponent and Significand

fxtract

; Compute y ∗ log2x

fyl2x

; Compute y ∗ log2(x +1)

fyl2xp1

; Partial Remainder

fprem1

; Sine

fsin

; Cosine

fcos

; Sine and Cosine

fsincos

; Unordered Compare Floating Point Values

fucom st7
fucom
fucomp st7
fucomp
fucompp

; Load x87 FPU Control Word

fldcw WORD [rdi]

; Condiational move

fcmovb st0, st0
fcmovb st0, st1
fcmovb st0, st2
fcmovb st0, st3
fcmovb st0, st4
fcmovb st0, st5
fcmovb st0, st6
fcmovb st0, st7
fcmovbe st0, st0
fcmovbe st0, st1
fcmovbe st0, st2
fcmovbe st0, st3
fcmovbe st0, st4
fcmovbe st0, st5
fcmovbe st0, st6
fcmovbe st0, st7
fcmovu st0, st0
fcmovu st0, st1
fcmovu st0, st2
fcmovu st0, st3
fcmovu st0, st4
fcmovu st0, st5
fcmovu st0, st6
fcmovu st0, st7
fcmovnb st0, st0
fcmovnb st0, st1
fcmovnb st0, st2
fcmovnb st0, st3
fcmovnb st0, st4
fcmovnb st0, st5
fcmovnb st0, st6
fcmovnb st0, st7
fcmovne st0, st0
fcmovne st0, st1
fcmovne st0, st2
fcmovne st0, st3
fcmovne st0, st4
fcmovne st0, st5
fcmovne st0, st6
fcmovne st0, st7
fcmovnu st0, st0
fcmovnu st0, st1
fcmovnu st0, st2
fcmovnu st0, st3
fcmovnu st0, st4
fcmovnu st0, st5
fcmovnu st0, st6
fcmovnu st0, st7

; Compare floating-point and set EFLAGS.

fcomi st0, st7

; Unordered compare floating-point and set EFLAGS.

fucomi st0, st7

; Compare floating-point, set EFLAGS, and pop

fcomip st0, st7

; Unordered compare floating-point, set EFLAGS, and pop.

fucomip st0, st7
