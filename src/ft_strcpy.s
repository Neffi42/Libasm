section .text
    global ft_strcpy
	extern ft_strlen

ft_strcpy:
	xor rax, rax
	xor rcx, rcx

	test rdi, rdi
	je .return_null
	test rsi, rsi
	je .return_null

	call ft_strlen
	mov rcx, rax
	cld
	rep movsb
	mov rax, rdi
	ret

.return_null:
	ret
