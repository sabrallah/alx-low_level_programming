; -----------------------------------------------------------------------------
; A 64-bit program in assembly that prints "Hello, Holberton" followed by a
; new line. Compiled using nasm and gcc.
; nasm -f elf64 101-hello_holberton.asm && gcc -no-pie -std=gnu89 101-hello_holberton.o -o hello
; -----------------------------------------------------------------------------

section .data
    ; Define format string and message
    format db "%s", 10, 0
    message db "Hello, Holberton", 0

section .text
    extern printf ; Declare C function to be called
    global main   ; Declare main function

main:
    ; Set up stack and arguments for printf
    push rbp
    mov rdi, format
    mov rsi, message
    mov rax, 0 ; Or use xor rax, rax

    ; Call printf function
    call printf

    ; Restore stack and return
    pop rbp
    mov rax, 0 ; Normal, no error, return value
    ret

