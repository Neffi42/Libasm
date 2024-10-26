section .text
    global ft_strcpy

ft_strcpy:
	xor rax, rax
	xor rcx, rcx

	test rdi, rdi
	je .return_null
	test rsi, rsi
	je .return_null

	jmp .loop

.loop:
	mov al, [rsi + rcx]
	mov [rdi + rcx], al
	cmp al, 0
	je .return_cpy
	inc rcx
	jmp .loop

.return_null:
	ret

.return_cpy:
	mov rax, rdi
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
