section .data
    hello db 'Hello, Holberton', 0
    format db "%s", 0

section .text
    global main
    extern printf

main:
    sub rsp, 8    ; Align stack to 16-byte boundary
    mov edi, format
    mov rsi, hello
    xor eax, eax  ; Clear eax register (function return value)
    call printf
    add rsp, 8    ; Restore stack
    mov eax, 0    ; Return 0 from main
    ret
