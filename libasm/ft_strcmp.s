                global	    ft_strcmp

		        section		.text
ft_strcmp:
                mov     rdx, -1

check:
	            inc		rdx
			    mov		al, byte [rdi + rdx]
			    mov		bl, byte [rsi + rdx]
                cmp     al, 0
                jz      return
                cmp     bl, 0
                jz      return
                cmp     al, bl
			    jz      check
                jmp    return

return:
                sub     rax, rbx
                js      negative
                jnz     positive
                mov    rax, 0
                ret

negative:
                mov    rax, -1
                ret

positive:
                mov    rax, 1
                ret
