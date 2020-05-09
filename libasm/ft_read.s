                global      _ft_read

                section     .text
_ft_read:
                mov		rax, 0x2000003 ;read
                syscall
                jc      error
                ret

error:
                mov     ecx, 0
                mov		rax, -1
                ret