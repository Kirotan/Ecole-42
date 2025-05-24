global ft_strdup
section .text
extern malloc
extern ft_strlen
extern ft_strcpy
extern	__errno_location

ft_strdup:
	push	rdi
	call	ft_strlen
	add		rax, 1
	mov		rdi, rax
	call	malloc wrt ..plt
	test	rax, rax
	je		.fail_malloc
	mov		rdi, rax
	pop		rsi
	call	ft_strcpy
	ret

.fail_malloc:
	call	__errno_location wrt ..plt
	mov		dword [rax], 12
	xor		rax, rax
	ret
