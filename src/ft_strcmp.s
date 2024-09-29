section .text
    global ft_strcmp

ft_strcmp:
    xor rax, rax
    xor rcx, rcx

    test rdi, rdi
    je .return_null
    test rsi, rsi
	je .return_null

.loop:
	mov al, [rdi + rcx]
	mov bl, [rsi + rcx]
	cmp al, bl
	jne .return_diff

	test al, al
	je .return_equal

    inc rcx
    jmp .loop

.return_diff:
	movzx rax, al
	movzx rbx, bl
	sub rax, rbx
	ret

.return_equal:
	xor rax, rax
	ret

.return_null:
    ret
