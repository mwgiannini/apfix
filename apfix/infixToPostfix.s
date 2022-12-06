#
#  eval.s
#  apfix
#
#  Created by Amor Wang & MW Giannini on 11/26/22.
#

.bss
.lcomm output, 1000                 # Output buffer

.text
.global _evalPostfix
_evalPostfix:
sub $8, %rsp
movq %rdi, %rsi                     # Address of the input string
leaq output(%rip), %rbx             # Address of next output byte

movb (%rsi), %al                    # Get first character
incq %rsi
cmpb $'+', %al
je prepend_zero                     # Jump if first operand positive
cmpb $'-', %al
je prepend_zero                     # Jump if first operand negative

parse:
cmpb $'(', %al
je recurse
cmpb $')', %al
je return
cmpb $0, %al
je return
cmpb $'+', %al
je p1
cmpb $'-', %al
je p1
cmpb $'*', %al
je p2
cmpb $'/', %al
je p2
cmpb $'^', %al
je p3
jmp operand

continue:
movb (%rsi), %al
incq %rsi
jmp parse

p1:
movb $1, %cl
jmp operator

p2:
movb $2, %cl
jmp operator

p3:
movb $3, %cl
jmp operator

operator:

operand:

prepend_zero:
movb $'0', (%rbx)
incq %rbx
movb $',', (%rbx)
incq %rbx
movb %al, (%rbx)
movb (%rsi), %al
incq %rsi

recurse:
incq %rsi
movq %rsi, %rdi
call _evalPostfix
append_output:
movb (%rax), %al
incq %rax
cmpb $0, %al
je continue
movb %al, (%rbx)
incq %rbx
jmp append_output

return:
cmpq %rsp, %rbp
je exit:
movb $',', (%rbx)
incq %rbx
popb %al                            # MIGHT NOT WORK
movb %al, (%rbx)
incq %rbx
jmp return

exit:
movb $0, (%rbx)
incq %rbx
leaq output(%rip), %rax
ret
