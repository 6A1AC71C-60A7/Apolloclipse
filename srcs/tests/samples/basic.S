
; https://www.felixcloutier.com/x86/cmps:cmpsb:cmpsw:cmpsd:cmpsq
; https://www.felixcloutier.com/x86/cmpsd
; ambigious af mnemonic



; Skiped:
;   - addpd
;   - addps
;   - addsd
;   - addss
;   - addsubpd
;   - addsubps
;   - addsub
;   - aesdec
;   - aesdeclast
;   - aesimc
;   - aeskeygenassist
;   - andn
;   - andnpd
;   - andnps
;   - andpd
;   - andps
;   - bextr
;   - blendpd
;   - blendps
;   - blendvpd
;   - blandvps
;   - blsi
;   - blsmsk
;   - blsr
;   - bndcl
;   - bndcn
;   - bndcu
;   - bndldx
;   - bndmk
;   - bndmov
;   - bndstx
;   - bzhi
;   - cldemote
;   - clflush
;   - clflushopt
;   - clwb
;   - cmppd
;   - cmpds
;   - cmpss
;   - comisd
;   - comiss
;   - cvtdq2pd
;   - cvtdq2ps
;   - cvtpd2dq
;   - cvtpd2pi
;   - cvtpd2ps
;   - cvtpi2pd
;   - cvtpi2ps
;   - ...
;   - cvttss2si
;   - divpd
;   - divps
;   - divsd
;   - dicss
;   - emms
;   - extractps
;   - f2xm1
;   - fabs
;   - ALL f*
;   - gf2p8affineinvqb
;   - gf2p8affineqb
;   - gf2p8mulb
;   - haddpd
;   - haddps
;   - hsubpd
;   - hsubps
;   - insertps
;   - k*
;   - lddqu
;   - ldmxcsr
;   - lds, les, lfs, lgs, lss
;   - maskmovdqu
;   - maskmovq
;   - maxpd
;   - maxps
;   - maxsd
;   - maxss
;   - mfence
;   - minpd
;   - minps
;   - minsd
;   - minss
;   - movapd
;   - movaps
;   - movd
;   - movddup
;   - movdir64b
;   - movdiri
;   - movdq2q to movq2dq
;   - movsd
;   - movshdup
;   - movsldup
;   - movsq
;   - movss
;   - movupd
;   - movups
;   - mpsadbw
;   - mulpd/ps/sd/ss
;   - mulx
;   - orpd
;   - orps
;   - pabsb
;   - pabsd
;   - pabsq
;   - pabsw
;   //- packssdw/sswb/usdw/uswb
;   - ...
;   - pmuludq
;   //- por
;   - psadbw
;   - pshufb too punpcklwd
;   //- pxor
;   - rorx
;   - rounded
;   - roundps/sd/ss
;   - rsqrtps/ss
;   - roundpd/ps/sd/ss
;   - sha*
;   - shufpd/ps
;   - sqrtpd/ps/sd/ss
;   - stmxcsr
;   - subpd/ps/sd/ss
;   - tpause
;   - ucommisd/ss
;   - umwait
;   - unpckhpd to vzeroupper
;   - xadquire/xrelease
;   - xorpd/ps
;   - 
;   - 
;   - 
;   - 
;   - 



; All commented instruction are 32-bit only


; ASCII Adjust After Addition

; aaa

; ASCII Adjust AX Before Division/

; aad
; aad 2

; ASCII Adjust AX After Multiply

; aam
; aam 2

; ASCII Adjust AL After Subtraction

; aas

; Add with Carry

    adc al, 0x69
    adc ax, 0x69
    adc eax, 0x69
    adc rax, 0x69
    adc dl, 0x69
    adc BYTE [rdx], 0x69
    adc dx, 0x6969
    adc WORD [rdx], 0x6969
    adc edx, 0x69696969
    adc DWORD [rdx], 0x69696969
    adc rdx, 0x69696969
    adc QWORD [rdx], 0x69696969
    adc dx, 0x69
    adc WORD [rdx], 0x69
    adc edx, 0x69
    adc DWORD [rdx], 0x69
    adc rdx, 0x69
    adc QWORD [rdx], 0x69
    adc dil, r12b
    adc BYTE [rdi], r12b
    adc di, r12w
    adc WORD [rdi], r12w
    adc edi, r12d
    adc DWORD [rdi], r12d 
    adc rdi, r12
    adc [rdi], r12
    adc dil, [r12]
    adc di, [r12]
    adc dx, [r12]
    adc rdx, [r12]

    ; Unsigned Integer Addition of Two Operands with Carry Flag

    adcx esi, r15d
    adcx esi, [r15]
    adcx rsi, r15
    adcx rsi, [r15]

    ; Add

    add al, 0x69
    add ax, 0x69
    add eax, 0x69
    add rax, 0x69
    add dl, 0x69
    add BYTE [rdx], 0x69
    add dx, 0x6969
    add WORD [rdx], 0x6969
    add edx, 0x69696969
    add DWORD [rdx], 0x69696969
    add rdx, 0x69696969
    add QWORD [rdx], 0x69696969
    add dx, 0x69
    add WORD [rdx], 0x69
    add edx, 0x69
    add DWORD [rdx], 0x69
    add rdx, 0x69
    add QWORD [rdx], 0x69
    add dil, r12b
    add BYTE [rdi], r12b
    add di, r12w
    add WORD [rdi], r12w
    add edi, r12d
    add DWORD [rdi], r12d 
    add rdi, r12
    add [rdi], r12
    add dil, [r12]
    add di, [r12]
    add dx, [r12]
    add rdx, [r12]

    ; Unsigned Integer Addition of Two Operands with Overflow Flag

    adox esi, r15d
    adox esi, [r15]
    adox rsi, r15
    adox rsi, [r15]

    ; Logical AND

    and al, 0x69
    and ax, 0x69
    and eax, 0x69
    and rax, 0x69
    and dl, 0x69
    and BYTE [rdx], 0x69
    and dx, 0x6969
    and WORD [rdx], 0x6969
    and edx, 0x69696969
    and DWORD [rdx], 0x69696969
    and rdx, 0x69696969
    and QWORD [rdx], 0x69696969
    and dx, 0x69
    and WORD [rdx], 0x69
    and edx, 0x69
    and DWORD [rdx], 0x69
    and rdx, 0x69
    and QWORD [rdx], 0x69
    and dil, r12b
    and BYTE [rdi], r12b
    and di, r12w
    and WORD [rdi], r12w
    and edi, r12d
    and DWORD [rdi], r12d 
    and rdi, r12
    and QWORD [rdi], r12
    and dil, [r12]
    and di, [r12]
    and dx, [r12]
    and rdx, [r12]

    ; Adjust RPL Field of Segment Selector

    ; arpl dx, r13w
    ; arpl [rdx], r13w

    ; Check Array Index Against Bounds

    ; bound eax, [edx]
    ; bound ax, [edx]

    ; Bit Scan Forward

    bsf dx, cx
    bsf dx, [rcx]
    bsf edx, ecx
    bsf edx, [rcx]
    bsf rdx, rcx
    bsf rdx, [rcx]

    ; Bit Scan Reverse

    bsr dx, cx
    bsr dx, [rcx]
    bsr edx, ecx
    bsr edx, [rcx]
    bsr rdx, rcx
    bsr rdx, [rcx]

    ; Byte Swap

    bswap eax
    bswap rax

    ; Bit Test

    bt bx, cx
    bt [rbx], cx
    bt ebx, ecx
    bt [rbx], ecx
    bt rbx, rcx
    bt [rbx], rcx
    bt bx, 0x69
    bt WORD [rbx], 0x69
    bt ebx, 0x69
    bt DWORD [rbx], 0x69
    bt rbx, 0x69
    bt QWORD [rbx], 0x69


    ; Bit Test and Complement

    btc bx, cx
    btc [rbx], cx
    btc ebx, ecx
    btc [rbx], ecx
    btc rbx, rcx
    btc [rbx], rcx
    btc bx, 0x69
    btc WORD [rbx], 0x69
    btc ebx, 0x69
    btc DWORD [rbx], 0x69
    btc rbx, 0x69
    btc QWORD [rbx], 0x69

    ; Bit Test and Reset

    btr bx, cx
    btr [rbx], cx
    btr ebx, ecx
    btr [rbx], ecx
    btr rbx, rcx
    btr [rbx], rcx
    btr bx, 0x69
    btr WORD [rbx], 0x69
    btr ebx, 0x69
    btr DWORD [rbx], 0x69
    btr rbx, 0x69
    btr QWORD [rbx], 0x69

    ; Bit Test and Set

    bts bx, cx
    bts [rbx], cx
    bts ebx, ecx
    bts [rbx], ecx
    bts rbx, rcx
    bts [rbx], rcx
    bts bx, 0x69
    bts WORD [rbx], 0x69
    bts ebx, 0x69
    bts DWORD [rbx], 0x69
    bts rbx, 0x69
    bts QWORD [rbx], 0x69

    ; Call Procedure

    call 0x6969
    call 0x69696969
    ; call WORD [rbx]
    ; call DWORD [rbx]
    call [rbx]

    ; Convert Byte to Word/Convert Word to Doubleword/Convert Doubleword to Quadword

    cbw
    cwde
    cdqe

    ; Convert Word to Doubleword/Convert Doubleword to Quadword

    cwd
    cdq
    cqo

    ; Clear AC Flag in EFLAGS Register

    clac

    ; Clear Carry Flag

    clac

    ; Clear Direction Flag

    cld

    ; Clear Interrupt Flag

    cli

    ; Clear Task-Switched Flag in CR0

    clts

    ; Complement Carry Flag

    cmc

    ; Conditional Move

    cmova dx, bx
    cmova dx, [rbx]
    cmova edx, ebx
    cmova edx, [rbx]
    cmova rdx, rbx
    cmova rdx, [rbx]
    cmovae dx, bx
    cmovae dx, [rbx]
    cmovae edx, ebx
    cmovae edx, [rbx]
    cmovae rdx, rbx
    cmovae rdx, [rbx]
    cmovb dx, bx
    cmovb dx, [rbx]
    cmovb edx, ebx
    cmovb edx, [rbx]
    cmovb rdx, rbx
    cmovb rdx, [rbx]
    cmovbe dx, bx
    cmovbe dx, [rbx]
    cmovbe edx, ebx
    cmovbe edx, [rbx]
    cmovbe rdx, rbx
    cmovbe rdx, [rbx]
    cmovc dx, bx
    cmovc dx, [rbx]
    cmovc edx, ebx
    cmovc edx, [rbx]
    cmovc rdx, rbx
    cmovc rdx, [rbx]
    cmove dx, bx
    cmove dx, [rbx]
    cmove edx, ebx
    cmove edx, [rbx]
    cmove rdx, rbx
    cmove rdx, [rbx]
    cmovg dx, bx
    cmovg dx, [rbx]
    cmovg edx, ebx
    cmovg edx, [rbx]
    cmovg rdx, rbx
    cmovg rdx, [rbx]
    cmovge dx, bx
    cmovge dx, [rbx]
    cmovge edx, ebx
    cmovge edx, [rbx]
    cmovge rdx, rbx
    cmovge rdx, [rbx]
    cmovl dx, bx
    cmovl dx, [rbx]
    cmovl edx, ebx
    cmovl edx, [rbx]
    cmovl rdx, rbx
    cmovl rdx, [rbx]
    cmovle dx, bx
    cmovle dx, [rbx]
    cmovle edx, ebx
    cmovle edx, [rbx]
    cmovle rdx, rbx
    cmovle rdx, [rbx]
    cmovna dx, bx
    cmovna dx, [rbx]
    cmovna edx, ebx
    cmovna edx, [rbx]
    cmovna rdx, rbx
    cmovna rdx, [rbx]
    cmovnae dx, bx
    cmovnae dx, [rbx]
    cmovnae edx, ebx
    cmovnae edx, [rbx]
    cmovnae rdx, rbx
    cmovnae rdx, [rbx]
    cmovnb dx, bx
    cmovnb dx, [rbx]
    cmovnb edx, ebx
    cmovnb edx, [rbx]
    cmovnb rdx, rbx
    cmovnb rdx, [rbx]
    cmovnbe dx, bx
    cmovnbe dx, [rbx]
    cmovnbe edx, ebx
    cmovnbe edx, [rbx]
    cmovnbe rdx, rbx
    cmovnbe rdx, [rbx]
    cmovnc dx, bx
    cmovnc dx, [rbx]
    cmovnc edx, ebx
    cmovnc edx, [rbx]
    cmovnc rdx, rbx
    cmovnc rdx, [rbx]
    cmovne dx, bx
    cmovne dx, [rbx]
    cmovne edx, ebx
    cmovne edx, [rbx]
    cmovne rdx, rbx
    cmovne rdx, [rbx]
    cmovng dx, bx
    cmovng dx, [rbx]
    cmovng edx, ebx
    cmovng edx, [rbx]
    cmovng rdx, rbx
    cmovng rdx, [rbx]
    cmovnge dx, bx
    cmovnge dx, [rbx]
    cmovnge edx, ebx
    cmovnge edx, [rbx]
    cmovnge rdx, rbx
    cmovnge rdx, [rbx]
    cmovnl dx, bx
    cmovnl dx, [rbx]
    cmovnl edx, ebx
    cmovnl edx, [rbx]
    cmovnl rdx, rbx
    cmovnl rdx, [rbx]
    cmovnle dx, bx
    cmovnle dx, [rbx]
    cmovnle edx, ebx
    cmovnle edx, [rbx]
    cmovnle rdx, rbx
    cmovnle rdx, [rbx]
    cmovno dx, bx
    cmovno dx, [rbx]
    cmovno edx, ebx
    cmovno edx, [rbx]
    cmovno rdx, rbx
    cmovno rdx, [rbx]
    cmovnp dx, bx
    cmovnp dx, [rbx]
    cmovnp edx, ebx
    cmovnp edx, [rbx]
    cmovnp rdx, rbx
    cmovnp rdx, [rbx]
    cmovns dx, bx
    cmovns dx, [rbx]
    cmovns edx, ebx
    cmovns edx, [rbx]
    cmovns rdx, rbx
    cmovns rdx, [rbx]
    cmovnz dx, bx
    cmovnz dx, [rbx]
    cmovnz edx, ebx
    cmovnz edx, [rbx]
    cmovnz rdx, rbx
    cmovnz rdx, [rbx]
    cmovo dx, bx
    cmovo dx, [rbx]
    cmovo edx, ebx
    cmovo edx, [rbx]
    cmovo rdx, rbx
    cmovo rdx, [rbx]
    cmovp dx, bx
    cmovp dx, [rbx]
    cmovp edx, ebx
    cmovp edx, [rbx]
    cmovp rdx, rbx
    cmovp rdx, [rbx]
    cmovpe dx, bx
    cmovpe dx, [rbx]
    cmovpe edx, ebx
    cmovpe edx, [rbx]
    cmovpe rdx, rbx
    cmovpe rdx, [rbx]
    cmovpo dx, bx
    cmovpo dx, [rbx]
    cmovpo edx, ebx
    cmovpo edx, [rbx]
    cmovpo rdx, rbx
    cmovpo rdx, [rbx]
    cmovs dx, bx
    cmovs dx, [rbx]
    cmovs edx, ebx
    cmovs edx, [rbx]
    cmovs rdx, rbx
    cmovs rdx, [rbx]
    cmovz dx, bx
    cmovz dx, [rbx]
    cmovz edx, ebx
    cmovz edx, [rbx]
    cmovz rdx, rbx
    cmovz rdx, [rbx]

    ; Compare Two Operands

    cmp al, 0x69
    cmp ax, 0x69
    cmp eax, 0x69
    cmp rax, 0x69
    cmp dl, 0x69
    cmp BYTE [rdx], 0x69
    cmp dx, 0x6969
    cmp WORD [rdx], 0x6969
    cmp edx, 0x69696969
    cmp DWORD [rdx], 0x69696969
    cmp rdx, 0x69696969
    cmp QWORD [rdx], 0x69696969
    cmp dx, 0x69
    cmp WORD [rdx], 0x69
    cmp edx, 0x69
    cmp DWORD [rdx], 0x69
    cmp rdx, 0x69
    cmp QWORD [rdx], 0x69
    cmp dil, r12b
    cmp BYTE [rdi], r12b
    cmp di, r12w
    cmp WORD [rdi], r12w
    cmp edi, r12d
    cmp DWORD [rdi], r12d 
    cmp rdi, r12
    cmp [rdi], r12
    cmp dil, [r12]
    cmp di, [r12]
    cmp dx, [r12]
    cmp rdx, [r12]

    ; Compare String Operands

    cmpsb
    cmpsw
    cmpsd
    cmpsq

    ; Compare and Exchange

    cmpxchg al, cl
    cmpxchg [rax], cl
    cmpxchg ax, cx
    cmpxchg [rax], cx
    cmpxchg eax, ecx
    cmpxchg [rax], ecx
    cmpxchg rax, rcx
    cmpxchg [rax], rcx

    ; Compare and Exchange Bytes

    cmpxchg8b [rax]
    cmpxchg16b [rax]

    ; CPU Identification

    cpuid

    ; Convert Word to Doubleword/Convert Doubleword to Quadword

    cwd
    cdq
    cqo

    ; Accumulate CRC32 Value

    crc32 eax, dl
    crc32 eax, dx
    crc32 eax, edx
    crc32 rax, dl
    crc32 rax, rdx

    ; Decimal Adjust AL after Addition

    ; daa

    ; Decimal Adjust AL after Subtraction

    ; das

    ; Decrement by 1

    dec r8b
    dec BYTE [r8]
    dec r8w
    dec WORD [r8]
    dec r8d
    dec DWORD [r8]
    dec r8
    dec QWORD [r8]

    ; Unsigned Divide

    div r8b
    div BYTE [r8]
    div r8w
    div WORD [r8]
    div r8d
    div DWORD [r8]
    div r8
    div QWORD [r8]

    ; Make Stack Frame for Procedure Parameters

    enter 0x10, 0
    enter 0x10, 1
    enter 0x10, 0x10

    ; Halt

    hlt

    ; Signed Divide

    idiv r8b
    idiv BYTE [r8]
    idiv r8w
    idiv WORD [r8]
    idiv r8d
    idiv DWORD [r8]
    idiv r8
    idiv QWORD [r8]

    ; Signed Multiply

    imul r8b
    imul BYTE [r8]
    imul r8w
    imul WORD [r8]
    imul r8d
    imul DWORD [r8]
    imul r8
    imul QWORD [r8]
    imul r8w, r9w
    imul r8w, [r9]
    imul r8d, r9d
    imul r8d, [r9]
    imul r8, r9
    imul r8, [r9]
    imul r8w, r9w, 0x8
    imul r8w, [r9], 0x8
    imul r8d, r9d, 0x8
    imul r8d, [r9], 0x8
    imul r8, r9, 0x8
    imul r8, [r9], 0x8
    imul r8w, r9w, 0x6969
    imul r8w, [r9], 0x6969
    imul r8d, r9d, 0x69696969
    imul r8d, [r9], 0x69696969
    imul r8, r9, 0x69696969
    imul r8, [r9], 0x69696969

    ; Input from Port

    in al, 0x69
    in ax, 0x69
    in eax, 0x69
    in al, dx
    in ax, dx
    in eax, dx

    ; Increment by 1

    inc r8b
    inc BYTE [r8]
    inc r8w
    inc WORD [r8]
    inc r8d
    inc DWORD [r8]
    inc r8
    inc QWORD [r8]

    ; Input from Port to String

    insb
    insw
    insd

    ; Call to Interrupt Procedure

    int3
    int 0x42
    ; into
    int1

    ; Flush internal caches; initiate flushing of external caches.

    invd

    ; Invalidate TLB Entries

    invlpg [rax]

    ; Invalidate Process-Context Identifier

    invpcid rax, [rcx]

    ; Interrupt Return

    iret
    iretq

    ; Jump

    jmp 0x69
    jmp 0x6969
    jmp 0x69696969
    ; jmp bx
    ; jmp WORD [rbx]
    ; jmp ebx 
    ; jmp DWORD [rbx]
    jmp rbx
    jmp QWORD [rbx]

    ; Jump if Condition Is Met

    ja 0x69
    jae 0x69
    jb 0x69
    jbe 0x69
    jc 0x69
    ;jcxz 0x69
    ;jecxz 0x69
    ;jrcxz 0x69
    je 0x69
    jg 0x69
    jge 0x69
    jl 0x69
    jle 0x69
    jna 0x69
    jnae 0x69
    jnb 0x69
    jnbe 0x69
    jnc 0x69
    jne 0x69
    jng 0x69
    jnge 0x69
    jnl 0x69
    jnle 0x69
    jno 0x69
    jnp 0x69
    jns 0x69
    jnz 0x69
    jo 0x69
    jp 0x69
    jpe 0x69
    jpo 0x69
    js 0x69
    jz 0x69
    ja 0x6969
    jae 0x6969
    jae 0x69696969
    jb 0x6969
    jb 0x69696969
    jbe 0x6969
    jbe 0x69696969
    jc 0x6969
    jc 0x69696969
    je 0x6969
    je 0x69696969
    jz 0x6969
    jz 0x69696969
    jg 0x6969
    jg 0x69696969
    jge 0x6969
    jge 0x69696969
    jl 0x6969
    jl 0x69696969
    jle 0x6969
    jle 0x69696969
    jna 0x6969
    jna 0x69696969
    jnae 0x6969
    jnae 0x69696969
    jnb 0x6969
    jnb 0x69696969
    jnbe 0x6969
    jnbe 0x69696969
    jnc 0x6969
    jnc 0x69696969
    jne 0x6969
    jne 0x69696969
    jng 0x6969
    jng 0x69696969
    jnge 0x6969
    jnge 0x69696969
    jnl 0x6969
    jnl 0x69696969
    jnle 0x6969
    jnle 0x69696969
    jno 0x6969
    jno 0x69696969
    jnp 0x6969
    jnp 0x69696969
    jns 0x6969
    jns 0x69696969
    jnz 0x6969
    jnz 0x69696969
    jo 0x6969
    jo 0x69696969
    jp 0x6969
    jpe 0x69696969
    jpo 0x6969
    jpo 0x69696969
    js 0x6969
    js 0x69696969
    jz 0x6969
    jz 0x69696969

    ; Load Status Flags into AH Register

    ;lahf

    ; Load Access Rights Byte

    lar dx, bx
    lar dx, [rbx]
    lar edx, ebx
    lar edx, [rbx]

    ; Load Effective Address

    lea cx, [rsp]
    lea ecx, [rsp]
    lea rcx, [rsp]

    ; High Level Procedure Exit

    leave

    ; Load Fence

    lfence

    ; Load Global/Interrupt Descriptor Table Register

    lgdt [rax]
    lidt [rax]

    ; Load Machine Status Word

    lmsw ax
    lmsw WORD [rax]

    ; Load String

    lodsb
    lodsw
    lodsd
    lodsq

    ; Loop According to ECX Counter

    loop 0x21
    loope 0x21
    loopne 0x21

    ; Load Segment Limit

    lsl ax, dx
    lsl ax, [rdx]
    lsl rax, dx
    lsl rax, [rdx]

    ; Load Task Register

    ltr ax
    ltr [rax]

    ; Count the Number of Leading Zero Bits

    lzcnt dx, ax
    lzcnt dx, [rax]
    lzcnt edx, eax
    lzcnt edx, [rax]
    lzcnt rdx, rax
    lzcnt rdx, [rax]

    ; Memory Fence

    mfence

    ; Set Up Monitor Address

    monitor

    ; Move

    mov dl, bl
    mov [rdx], bl
    mov dx, bx
    mov [rdx], bx
    mov edx, ebx
    mov [rdx], ebx
    mov rdx, rbx
    mov [rdx], rbx
    mov dl, [rbx]
    mov dx, [rbx]
    mov edx, [rbx]
    mov rdx, [rbx]
    mov dx, gs
    mov [rdx], gs
    mov edx, gs
    mov rdx, gs
    mov gs, dx
    mov gs, [rbx]
    mov gs, rdx
    ; TODO: mov rax, moffs
    ; TODO: mov moffs, rax
    mov dl, 0x69
    mov dx, 0x6969
    mov edx, 0x69696969
    mov rdx, 0x6969696969696969
    mov BYTE [rdx], 0x69
    mov WORD [rdx], 0x6969
    mov DWORD [rdx], 0x69696969
    mov QWORD [rdx], 0x69696969

    ; Move to/from Control Registers

    mov rax, cr1
    mov rax, cr8
    mov cr1, rax
    mov cr8, rax

    ; Move to/from Debug Registers

    mov rax, dr1
    mov rax, dr8
    mov dr1, rax
    mov dr8, rax

    ; Move Data After Swapping Bytes

    movbe eax, [rdx]
    movbe rax, [rdx]
    movbe [rax], edx
    movbe [rax], rdx

    ; Move Data from String to String

    movsb
    movsw
    movsd
    movsq

    ; Move with Sign-Extension

    movsx dx, cl
    movsx dx, [rcx]
    movsx edx, cl
    ;movsx edx, [rcx] ; BUG NASM
    movsx rdx, cl
    ;movsx rdx, [rcx] ; BUG NASM
    movsx eax, cx
    ;movsx eax, [rcx] ; BUG NASM
    ; movsxd ax, cx
    ; movsxd ax, [rcx]
    ; movsxd eax, ecx
    ; movsxd eax, [rcx]
    ; movsxd rax, rcx
    movsxd rax, [rcx]

    ; Move with Zero-Extend

    movzx dx, cl
    movzx dx, [rcx]
    movzx edx, cl
    ; movzx edx, [rcx] ; BUG NASM
    movzx rdx, cl
    ; movzx rdx, [rcx] ; BUG NASM
    movzx eax, cx
    movzx rax, cx

    ; Unsigned Multiply

    mul r8b
    mul BYTE [r8]
    mul r8w
    mul WORD [r8]
    mul r8d
    mul DWORD [r8]
    mul r8
    mul QWORD [r8]

    ; Monitor Wait

    mwait

    ; Two's Compliment Negation

    neg r8b
    neg BYTE [r8]
    neg r8w
    neg WORD [r8]
    neg r8d
    neg DWORD [r8]
    neg r8
    neg QWORD [r8]

    ; No operation

    nop
    nop WORD [rax]
    nop ax
    nop DWORD [rax]
    nop eax

    ; One's Complement Negation

    not r8b
    not BYTE [r8]
    not r8w
    not WORD [r8]
    not r8d
    not DWORD [r8]
    not r8
    not QWORD [r8]

    ; Logical Exclusive OR

    or al, 0x69
    or ax, 0x69
    or eax, 0x69
    or rax, 0x69
    or dl, 0x69
    or BYTE [rdx], 0x69
    or dx, 0x6969
    or WORD [rdx], 0x6969
    or edx, 0x69696969
    or DWORD [rdx], 0x69696969
    or rdx, 0x69696969
    or QWORD [rdx], 0x69696969
    or dx, 0x69
    or WORD [rdx], 0x69
    or edx, 0x69
    or DWORD [rdx], 0x69
    or rdx, 0x69
    or QWORD [rdx], 0x69
    or dil, r12b
    or BYTE [rdi], r12b
    or di, r12w
    or WORD [rdi], r12w
    or edi, r12d
    or DWORD [rdi], r12d 
    or rdi, r12
    or QWORD [rdi], r12
    or dil, [r12]
    or di, [r12]
    or dx, [r12]
    or rdx, [r12]

    ; Output to Port

    out 0x69, al
    out 0x69, ax
    out 0x69, eax
    out dx, al
    out dx, ax
    out dx, eax

    ; Output String to Port

    outsb
    outsw
    outsd

    ; Pop a Value from the Stack

    pop r8w
    pop WORD [r8]
    ; pop r8d
    ; pop DWORD [r8]
    pop r8
    pop QWORD [r8]
    ; pop es
    ; pop cs
    ; pop ss
    ; pop ds
    pop fs
    pop gs

    ; Pop All General_Purpose Registers

    ; popa
    ; popad

    ; Return the Count of Number of Bits Set to 1

    popcnt ax, dx
    popcnt ax, [rdx]
    popcnt eax, edx
    popcnt eax, [rdx]
    popcnt rax, rdx
    popcnt rax, [rdx]

    ; Pop Stack into EFLAGS Register

    popf
    popfq

    ; Prefetch Data into Caches in Anticipation of a Write

    prefetchw [rax]

    ; Prefetch Data into Caches

    prefetcht0 [rax]
    prefetcht1 [rax]
    prefetcht2 [rax]
    prefetchnta [rax]

    ; Push Word, Doubleword or Quadword Onto the Stack

    push r8w
    push WORD [r8]
    ; push r8d
    ; push DWORD [r8]
    push r8
    ; push [r8]
    push 0x69
    push 0x6969
    push 0x69696969
    ; push es
    ; push cs
    ; push ss
    ; push ds
    push fs
    push gs

    ; Push EFLAGS Register onto the Stack

    pushf
    pushfq

    ; Rotate

    rcl al, 1
    rcl BYTE [rax], 1
    rcl al, cl
    rcl BYTE [rax], cl
    rcl al, 0x69
    rcl BYTE [rax], 0x69
    rcl ax, 1
    rcl WORD [rax], 1
    rcl ax, cl
    rcl WORD [rax], cl
    rcl ax, 0x69
    rcl WORD [rax], 0x69
    rcl eax, 1
    rcl DWORD [rax], 1
    rcl rax, 1
    rcl QWORD [rax], 1
    rcl eax, cl
    rcl DWORD [rax], cl
    rcl rax, cl
    rcl QWORD [rax], cl
    rcl eax, 0x69
    rcl DWORD [rax], 0x69
    rcl rax, 0x69
    rcl QWORD [rax], 0x69

    rcr al, 1
    rcr BYTE [rax], 1
    rcr al, cl
    rcr BYTE [rax], cl
    rcr al, 0x69
    rcr BYTE [rax], 0x69
    rcr ax, 1
    rcr WORD [rax], 1
    rcr ax, cl
    rcr WORD [rax], cl
    rcr ax, 0x69
    rcr WORD [rax], 0x69
    rcr eax, 1
    rcr DWORD [rax], 1
    rcr rax, 1
    rcr QWORD [rax], 1
    rcr eax, cl
    rcr DWORD [rax], cl
    rcr rax, cl
    rcr QWORD [rax], cl
    rcr eax, 0x69
    rcr DWORD [rax], 0x69
    rcr rax, 0x69
    rcr QWORD [rax], 0x69

    rol al, 1
    rol BYTE [rax], 1
    rol al, cl
    rol BYTE [rax], cl
    rol al, 0x69
    rol BYTE [rax], 0x69
    rol ax, 1
    rol WORD [rax], 1
    rol ax, cl
    rol WORD [rax], cl
    rol ax, 0x69
    rol WORD [rax], 0x69
    rol eax, 1
    rol DWORD [rax], 1
    rol rax, 1
    rol QWORD [rax], 1
    rol eax, cl
    rol DWORD [rax], cl
    rol rax, cl
    rol QWORD [rax], cl
    rol eax, 0x69
    rol DWORD [rax], 0x69
    rol rax, 0x69
    rol QWORD [rax], 0x69

    ror al, 1
    ror BYTE [rax], 1
    ror al, cl
    ror BYTE [rax], cl
    ror al, 0x69
    ror BYTE [rax], 0x69
    ror ax, 1
    ror WORD [rax], 1
    ror ax, cl
    ror WORD [rax], cl
    ror ax, 0x69
    ror WORD [rax], 0x69
    ror eax, 1
    ror DWORD [rax], 1
    ror rax, 1
    ror QWORD [rax], 1
    ror eax, cl
    ror DWORD [rax], cl
    ror rax, cl
    ror QWORD [rax], cl
    ror eax, 0x69
    ror DWORD [rax], 0x69
    ror rax, 0x69
    ror QWORD [rax], 0x69

    ; Resume from System Managemetn Mode

    rsm

    ; Shift

    shl al, 1
    shl BYTE [rax], 1
    shl al, cl
    shl BYTE [rax], cl
    shl al, 0x69
    shl BYTE [rax], 0x69
    shl ax, 1
    shl WORD [rax], 1
    shl ax, cl
    shl WORD [rax], cl
    shl ax, 0x69
    shl WORD [rax], 0x69
    shl eax, 1
    shl DWORD [rax], 1
    shl rax, 1
    shl QWORD [rax], 1
    shl eax, cl
    shl DWORD [rax], cl
    shl rax, cl
    shl QWORD [rax], cl
    shl eax, 0x69
    shl DWORD [rax], 0x69
    shl rax, 0x69
    shl QWORD [rax], 0x69

    sar al, 1
    sar BYTE [rax], 1
    sar al, cl
    sar BYTE [rax], cl
    sar al, 0x69
    sar BYTE [rax], 0x69
    sar ax, 1
    sar WORD [rax], 1
    sar ax, cl
    sar WORD [rax], cl
    sar ax, 0x69
    sar WORD [rax], 0x69
    sar eax, 1
    sar DWORD [rax], 1
    sar rax, 1
    sar QWORD [rax], 1
    sar eax, cl
    sar DWORD [rax], cl
    sar rax, cl
    sar QWORD [rax], cl
    sar eax, 0x69
    sar DWORD [rax], 0x69
    sar rax, 0x69
    sar QWORD [rax], 0x69

    shl al, 1
    shl BYTE [rax], 1
    shl al, cl
    shl BYTE [rax], cl
    shl al, 0x69
    shl BYTE [rax], 0x69
    shl ax, 1
    shl WORD [rax], 1
    shl ax, cl
    shl WORD [rax], cl
    shl ax, 0x69
    shl WORD [rax], 0x69
    shl eax, 1
    shl DWORD [rax], 1
    shl rax, 1
    shl QWORD [rax], 1
    shl eax, cl
    shl DWORD [rax], cl
    shl rax, cl
    shl QWORD [rax], cl
    shl eax, 0x69
    shl DWORD [rax], 0x69
    shl rax, 0x69
    shl QWORD [rax], 0x69

    shr al, 1
    shr BYTE [rax], 1
    shr al, cl
    shr BYTE [rax], cl
    shr al, 0x69
    shr BYTE [rax], 0x69
    shr ax, 1
    shr WORD [rax], 1
    shr ax, cl
    shr WORD [rax], cl
    shr ax, 0x69
    shr WORD [rax], 0x69
    shr eax, 1
    shr DWORD [rax], 1
    shr rax, 1
    shr QWORD [rax], 1
    shr eax, cl
    shr DWORD [rax], cl
    shr rax, cl
    shr QWORD [rax], cl
    shr eax, 0x69
    shr DWORD [rax], 0x69
    shr rax, 0x69
    shr QWORD [rax], 0x69

    ; Read from Model Specific Register

    rdmsr 

    ; Read Processor ID

    rdpid rax
    ; rdpid [rax]

    ; Read Protection Key Rights for User Pages

    ; rdpkpu

    ; Read Performance-Monitoring Counters

    rdpmc

    ; Read Random Number

    rdrand ax
    rdrand eax
    rdrand rax

    ; Read Random SEED

    rdseed ax
    rdseed eax
    rdseed rax

    ; Read Time-Stamp Counter

    rdtsc

    ; Read Time-Stamp Counter abd Processor ID

    rdtscp

    ; Return from Procedure

    ret
    ret 0x6969

    ; Interger Subtraction with Borrow

    sbb al, 0x69
    sbb ax, 0x69
    sbb eax, 0x69
    sbb rax, 0x69
    sbb dl, 0x69
    sbb BYTE [rdx], 0x69
    sbb dx, 0x6969
    sbb WORD [rdx], 0x6969
    sbb edx, 0x69696969
    sbb DWORD [rdx], 0x69696969
    sbb rdx, 0x69696969
    sbb QWORD [rdx], 0x69696969
    sbb dx, 0x69
    sbb WORD [rdx], 0x69
    sbb edx, 0x69
    sbb DWORD [rdx], 0x69
    sbb rdx, 0x69
    sbb QWORD [rdx], 0x69
    sbb dil, r12b
    sbb BYTE [rdi], r12b
    sbb di, r12w
    sbb WORD [rdi], r12w
    sbb edi, r12d
    sbb DWORD [rdi], r12d 
    sbb rdi, r12
    sbb QWORD [rdi], r12
    sbb dil, [r12]
    sbb di, [r12]
    sbb dx, [r12]
    sbb rdx, [r12]

    ; Scan String

    scasb
    scasw
    scasd
    scasq

    ; Set byte on Condition

    seta al
    seta [rax]
    setae al
    setae [rax]
    setb al
    setb [rax]
    setne al
    setbe [rax]
    setc al
    setc [rax]
    sete al
    sete [rax]
    setg al
    setg [rax]
    setge al
    setge [rax]
    setl al
    setl [rax]
    setle al
    setle [rax]
    setna al
    setna [rax]
    setnae al
    setnae [rax]
    setnb al
    setnb [rax]
    setnbe al
    setnbe [rax]
    setnc al
    setnc [rax]
    setne al
    setne [rax]
    setng al
    setng [rax]
    setnge al
    setnge [rax]
    setnl al
    setnl [rax]
    setnle al
    setnle [rax]
    setno al
    setno [rax]
    setnp al
    setnp [rax]
    setns al
    setns [rax]
    setnz al
    setnz [rax]
    seto al
    seto [rax]
    setp al
    setp [rax]
    setpe al
    setpe [rax]
    setpo al
    setpo [rax]
    sets al
    sets [rax]
    setz al
    setz [rax]

    ; Store Fence

    sfence

    ; Store Global Descriptor Table Regiter

    sgdt [rax]

    ; Double Precision Shift Left

    shld ax, bx, 0x69
    shld [rax], bx, 0x69
    shld ax, bx, cl
    shld [rax], bx, 0x69
    shld eax, ebx, 0x69
    shld [rax], ebx, 0x69
    shld eax, ebx, cl
    shld [rax], ebx, 0x69
    shld rax, rbx, 0x69
    shld [rax], rbx, 0x69
    shld rax, rbx, cl
    shld [rax], rbx, 0x69

    ; Double Precision Shift Right

    shrd ax, bx, 0x69
    shrd [rax], bx, 0x69
    shrd ax, bx, cl
    shrd [rax], bx, 0x69
    shrd eax, ebx, 0x69
    shrd [rax], ebx, 0x69
    shrd eax, ebx, cl
    shrd [rax], ebx, 0x69
    shrd rax, rbx, 0x69
    shrd [rax], rbx, 0x69
    shrd rax, rbx, cl
    shrd [rax], rbx, 0x69

    ; Store Interrupt Descriptor Table Register

    sidt [rax]

    ; Store Local Descriptor Table Register

    sldt ax
    sldt [rax]
    sldt rax

    ; Store Machine Status Word

    smsw ax
    smsw eax
    smsw rax
    smsw [rax]

    ; Set AC Flag in EFLAGS Register

    stac

    ; Set Carry Flag

    stc

    ; Set Direction Flag

    std

    ; Set Inerrupt Flag

    sti

    ; Store String

    stosb
    stosw
    stosd
    stosq

    ; Store Task Register

    str ax
    str [rax]

    ; Subtract

    sub al, 0x69
    sub ax, 0x69
    sub eax, 0x69
    sub rax, 0x69
    sub dl, 0x69
    sub BYTE [rdx], 0x69
    sub dx, 0x6969
    sub WORD [rdx], 0x6969
    sub edx, 0x69696969
    sub DWORD [rdx], 0x69696969
    sub rdx, 0x69696969
    sub QWORD [rdx], 0x69696969
    sub dx, 0x69
    sub WORD [rdx], 0x69
    sub edx, 0x69
    sub DWORD [rdx], 0x69
    sub rdx, 0x69
    sub QWORD [rdx], 0x69
    sub dil, r12b
    sub BYTE [rdi], r12b
    sub di, r12w
    sub WORD [rdi], r12w
    sub edi, r12d
    sub DWORD [rdi], r12d 
    sub rdi, r12
    sub QWORD [rdi], r12
    sub dil, [r12]
    sub di, [r12]
    sub edi, [r12]
    sub rdx, [r12]

    ; Swap GS Base Register

    swapgs

    ; Fast System Call

    syscall

    ; Fast System Call

    sysenter

    ; Fast Return from Fast System Call

    sysexit

    ; Return from Fast System Call

    sysret

    ; Logical Compare

    test al, 0x69
    test ax, 0x69
    test eax, 0x69
    test rax, 0x69
    test dl, 0x69
    test BYTE [rdx], 0x69
    test dx, 0x6969
    test WORD [rdx], 0x6969
    test edx, 0x69696969
    test DWORD [rdx], 0x69696969
    test rdx, 0x69696969
    test QWORD [rdx], 0x69696969
    test dx, 0x69
    test WORD [rdx], 0x69
    test edx, 0x69
    test DWORD [rdx], 0x69
    test rdx, 0x69
    test QWORD [rdx], 0x69
    test dil, r12b
    test BYTE [rdi], r12b
    test di, r12w
    test WORD [rdi], r12w
    test edi, r12d
    test DWORD [rdi], r12d 
    test rdi, r12
    test QWORD [rdi], r12

    ; Count the number of Trailing Zero Bits

    tzcnt ax, bx
    tzcnt ax, [rbx]
    tzcnt eax, ebx
    tzcnt eax, [rbx]
    tzcnt rax, rbx
    tzcnt rax, [rbx]

    ; Undefined Instruction

    ; ud0 eax, ebx
    ; ud0 eax, [rbx]
    ; ud1 eax, ebx
    ; ud1 eax, [rbx]
    ; ud2

    ; User Level Set Up Monitor Address

    umonitor rax

    ; Write Back and Invalitade Cache

    wbinvd

    ; Write to Model Specific Register

    wrmsr

    ; Write Data to User Page Key Register

    wrpkru

    ; Transactional Abort

    xabort 0x69

    ; Exchange and Add

    xadd al, r8b
    xadd [rax], r8b
    xadd ax, r8w
    xadd [rax], r8w
    xadd eax, r8d
    xadd [rax], r8d
    xadd rax, r8
    xadd [rax], r8

    ; Transactional Begin

    xbegin 0x6969
    xbegin 0x69696969

    ; Exchage Register/Memory with Register

    xchg ax, dx
    xchg dx, ax
    xchg eax, edx
    xchg rax, rdx
    xchg edx, eax
    xchg rdx, rax
    xchg al, dl
    xchg al, [rdx]
    xchg dl, al
    xchg dl, [rax]
    xchg dx, bx
    xchg dx, [rbx]
    xchg [rdx], bx
    xchg edx, ebx
    xchg edx, [rbx]
    xchg [rdx], ebx
    xchg rdx, rbx
    xchg rdx, [rbx]
    xchg [rdx], rbx

    ; Transactional end

    xend

    ; Get Value of Extented Control Register

    xgetbv

    ; Table Look-up Translation

    xlat

    ; Logical Exclusive OR

    xor al, 0x69
    xor ax, 0x69
    xor dl, 0x69
    xor BYTE [rdx], 0x69
    xor dx, 0x6969
    xor WORD [rdx], 0x6969
    xor edx, 0x69696969
    xor DWORD [rdx], 0x69696969
    xor rdx, 0x69696969
    xor QWORD [rdx], 0x69696969
    xor dx, 0x69
    xor WORD [rdx], 0x69
    xor edx, 0x69
    xor DWORD [rdx], 0x69
    xor rdx, 0x69
    xor QWORD [rdx], 0x69
    xor dil, r12b
    xor BYTE [rdi], r12b
    xor di, r12w
    xor WORD [rdi], r12w
    xor edi, r12d
    xor DWORD [rdi], r12d 
    xor rdi, r12
    xor [rdi], r12
    xor dil, [r12]
    xor di, [r12]
    xor edi, [r12]
    xor rdx, [r12]

    ; Restore Processor Extented States

    xrstor [rax]
    xrstor64 [rax]

    ; Restore Processor Extented States Supervisor

    xrstors [rax]
    xrstors64 [rax]

    ; Save Processor States

    xsave [rax]
    xsave64 [rax]

    ; Save Processor States with comparison

    xsavec [rax]
    xsavec64 [rax]

    ; Save Processor Extended States Optimized

    ; saveopt [rax]
    ; saveopt64 [rax]

    ; Save Processor States Supervisor

    xsaves [rax]
    xsaves64 [rax]

    ; Set Extended Control Register

    xsetbv

    ; Test if In Transactional Execution

    xtest
