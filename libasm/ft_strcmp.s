.intel_syntax noprefix
.text
.global ft_strcmp

ft_strcmp:
	xor	rax, rax

.loop:
	mov al, byte ptr [rdi]
	mov dl, byte ptr [rsi]
	cmp al, dl
	jne .diff
	test	al, al
	je	.equal
	inc	rdi
	inc	rsi
	jmp	.loop

.diff:
	movzx	eax, al
	movzx	edx, dl
	sub		eax, edx
	ret

.equal:
	xor eax, eax
	ret
