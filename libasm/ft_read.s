global ft_read
section .text
extern __errno_location

ft_read:
	mov		rax, 0
	syscall
	cmp		rax, -4095
	jae		.end
	ret

.end:
	mov		rdi, rax
	neg		rdi
	call	__errno_location wrt ..plt
	mov		[rax], edi
	mov		rax, -1
	ret
