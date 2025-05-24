global ft_read
section .text
extern __errno_location

ft_read:
	mov		rax, 0
	syscall
	cmp		rax, 0
	jae		.ok
	neg		rax
	mov		rdi, rax
	call	__errno_location wrt ..plt
	mov		[rax], edi
	mov	rax, -1

.ok:
	ret
