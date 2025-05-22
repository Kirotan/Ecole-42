.intel_syntax noprefix
.text
.global ft_strlen

ft_strlen:
	xor	rcx, rcx

.loop:
	mov	al, byte ptr [rdi]
	test	al, al
	je	.done
	inc	rdi
	inc rcx
	jmp .loop

.done:
	mov	rax, rcx
	ret
