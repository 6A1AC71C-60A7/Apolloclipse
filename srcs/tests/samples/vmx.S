
; Invalidates EPT-derived entries in the TLBs and paging-structure caches (in 64-bit mode).

invept rax, [rdi]

; Invalidates entries in the TLBs and paging-structure caches based on VPID (in 64-bit mode).

invvpid rax, [rdi]

; Call to VM monitor by causing VM exit.

vmcall

; Copy VMCS data to VMCS region in memory.

vmclear [rdi]

; Invoke VM function specified in EAX.

vmfunc

; Launch virtual machine managed by current VMCS.

vmlaunch

; Resume virtual machine managed by current VMCS.

vmresume

; Loads the current VMCS pointer from memory.

vmptrld [rdi]

; Stores the current VMCS pointer into memory.

vmptrst [rdi]

; Reads a specified VMCS field (in 64-bit mode).

vmread rax, rdi
vmread [rax], rdi

; Writes a specified VMCS field (in 64-bit mode).

vmwrite rax, rdi
vmwrite rax, [rdi]

; Leaves VMX operation.

vmxoff 

; Enter VMX root operation.

vmxon [rax]
