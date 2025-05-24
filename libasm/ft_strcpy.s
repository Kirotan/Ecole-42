global ft_strcpy
section .text

ft_strcpy:
	push	rdi

.copy_loop:
	mov		al, [rsi]
	mov		[rdi], al
	inc		rsi
	inc		rdi
	test	al, al
	jne		.copy_loop
	pop		rax
	ret
