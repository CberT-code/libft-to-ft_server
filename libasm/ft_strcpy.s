                global      _ft_strcpy

		        section		.text
_ft_strcpy:
                mov     rdx, -1

copy:
	            inc		rdx
			    cmp		byte [rsi + rdx], 0
                jz      return
                mov     al, byte [rsi + rdx]
                mov     byte [rdi + rdx], al
			    jmp		copy

return:
                mov     byte [rdi + rdx], 0
                mov     rax, rdi
                ret