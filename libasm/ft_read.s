                global      ft_read
                extern      __errno_location
                section     .text
ft_read:
                mov		rax,0
                syscall
                cmp     rax,0
                jl      error
                ret
                
error:
                neg     rax
                mov     rdx, rax
                call    __errno_location
                mov     [rax],rdx
                mov     ecx,0
                mov     rax,-1
                ret
