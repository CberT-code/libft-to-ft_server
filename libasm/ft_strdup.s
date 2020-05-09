                global	    ft_strdup
                extern      ft_strlen
                extern      ft_strcpy
                extern      malloc

		        section		.text
_ft_strdup:
                push        rdi
                call        ft_strlen
                mov         rdi, rax
                inc         rdi
                call        malloc
                cmp         rax, 0
                jz          return
                pop         rsi
                mov         rdi, rax
                call        ft_strcpy
                jmp         return
return:
		        ret
