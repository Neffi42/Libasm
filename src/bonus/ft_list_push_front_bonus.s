section .text
    global ft_list_push_front
	extern __errno_location
	extern malloc

ft_list_push_front:
	push rdi
	mov rdi, rsi
	call .create_elem
	pop rdi
	cmp	rax, 0
	je .end
	mov rsi, qword [rdi]
	mov qword [rax + 8], rsi
	mov qword [rdi], rax
	ret

.create_elem:
	push rdi
	mov rdi, 16
	call malloc wrt ..plt
	pop rdi
	cmp	rax, 0
	jz	.on_error
	mov qword [rax], rdi
	mov qword [rax + 8], 0
	ret

.on_error:
	call __errno_location wrt ..plt
	mov qword [rax], 12
	xor rax, rax
	ret


.end:
	ret

section .note.GNU-stack noalloc noexec nowrite progbits
