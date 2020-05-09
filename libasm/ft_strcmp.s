                global	    ft_strcmp

		        section		.text
ft_strcmp:
                mov     rcx, -1

check:
	            inc		rcx
			    mov		al, byte [rdi + rcx]
			    mov		bl, byte [rsi + rcx]
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
                sub     bl, byte [rsi,rcx]
                neg     bl
                ret

positive:
                sub     al, byte [rsi,rcx]
                ret
