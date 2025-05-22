.intel_syntax noprefix
.text
.global ft_strcpy

ft_strcpy:
	mov		rax, rdi

.loop:
	mov		al, byte ptr [rsi]
	mov		byte ptr [rdi], al
	inc		rsi
	inc		rdi
	test	al, al
	jne		.loop
	ret
