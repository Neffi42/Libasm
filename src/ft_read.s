section .text
	global ft_read
	extern __errno_location

ft_read:
	test rsi, rsi
	je .return_null

	mov rax, 0
	syscall

	cmp rax, 0
	jl .on_error

    ret

.return_null:
	mov rax, -1
	ret

.on_error:
	neg		rax
	mov		rdi, rax
	call    __errno_location wrt ..plt
	mov		[rax], rdi
	mov		rax, -1
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
