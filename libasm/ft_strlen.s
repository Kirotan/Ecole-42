global ft_strlen
section .text

ft_strlen:
	push	rdi
	xor		rcx, rcx

.loop:
	mov		al, byte [rdi]
	cmp		al, 0
	je		.done
	inc		rdi
	inc		rcx
	jmp		.loop

.done:
	mov		rax, rcx
	pop		rdi
	ret
