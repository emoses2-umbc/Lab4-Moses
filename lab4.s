.section .text
.globl sum_array

sum_array:
    mov $0, %ecx
    mov $0, %eax

.Lloop:
    cmp %esi, %ecx
    jge .Ldone
    mov (%rdi,%rcx,4), %edx
    add %edx, %eax
    inc %ecx
    jmp .Lloop

.Ldone:
    ret


.section .note.GNU-stack,"",@progbits

    
