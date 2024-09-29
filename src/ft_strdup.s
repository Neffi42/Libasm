section .text
	global ft_strdup
	extern __errno_location
	extern malloc
	extern ft_strlen
	extern ft_strcpy

ft_strdup:
	test rdi, rdi
	je .return_null

	call ft_strlen
	mov rsi, rdi
	inc rax
	mov rdi, rax
	call malloc wrt ..plt
	cmp	rax, 0
	jz	.on_error

	mov rdi, rax
	call ft_strcpy
	ret

.return_null:
	xor rax, rax
	ret

.on_error:
	neg		rax
	mov		rdi, rax
	call    __errno_location wrt ..plt
	mov		[rax], rdi
	mov		rax, -1
	ret
