section .text
    global ft_strlen

ft_strlen:
    xor rax, rax
    test rdi, rdi
    je .return_len

.loop:
    cmp byte [rdi + rax],  0
    je .return_len
    inc rax
    jmp .loop

.return_len:
    ret
