				global		_ft_write

				section		.text
_ft_write:
				push	r8
				push	r9
				cmp		rsi, 0
				jz		error
				mov		r8, rsi
				mov		r9, rdx
				mov		rsi, 0x0
				mov		rax, 0x20000BD ;fstat test fd
				syscall
				cmp		rax, 9
				jz		error
				mov		rsi, r8
				mov		rdx, r9
				mov		rax, 0x2000004
				syscall
				pop		r8
				pop		r9
				ret

error:
				mov		rax, -1
				pop		r8
				pop		r9
				ret
