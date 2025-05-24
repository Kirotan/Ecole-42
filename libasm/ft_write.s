global ft_write
section .text
extern __errno_location

ft_write:
	mov		rax, 1
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
