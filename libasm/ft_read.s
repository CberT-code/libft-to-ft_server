                global      _ft_read

                section     .text
_ft_read:
                push    r8
                mov     r8, rsi
                cmp		rdi, 0
                jz		error
                cmp		rsi, 0
                jz		error
                mov     rsi, 0x0
                mov     rax, 0x20000BD
                syscall
                cmp     rax, 9
                jz      error
                mov     rsi, r8
                mov		rax, 0x2000003 ;read
                syscall
                pop     r8
                ret

error:
                mov		rax, -1
                pop     r8
                ret