; Premier programme en assembleur modif Q11

SECTION .data
msg :
    db "Adieu monde cruel", 10

SECTION .text
global main
main :
    nop
    mov edx, 0x12
    mov ecx, msg
    mov ebx, 1
    mov eax, 4
    int 0x80
    mov ebx, 0
    mov eax, 1
    int 0x80
