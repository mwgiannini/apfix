#
#  eval.s
#  apfix
#
#  Created by Amor Wang & MW Giannini on 11/26/22.
#

.macro prior ir, or
cmpb $'+', \ir
je 1f
cmpb $'-', \ir
je 1f
cmpb $'*', \ir
je 2f
cmpb $'/', \ir
je 2f
cmpb $'^', \ir
je 3f
xorb \or, \or
jmp 0f
1:
movb $1, \or
jmp 0f
2:
movb $2, \or
jmp 0f
3:
movb $3, \or
jmp 0f
0:
.endm

.text
.global _infixToPostfix
_infixToPostfix:
sub $8, %rsp
# %rdi                     Address of the output string
# %rsi                     Address of the input string
movq %rsp, %rbx          # Bottom of the operator stack

movb (%rsi), %al         # Get first character
incq %rsi
cmpb $'+', %al
je prepend_zero       # Jump if first operand positive
cmpb $'-', %al
je prepend_zero       # Jump if first operand negative

parse:
cmpb $'(', %al
je recurse
cmpb $')', %al
je return
cmpb $0, %al
je return
prior %al, %dl          # Get priority of character
cmpb $0, %dl         # priority = zero if not operator
je operand
jmp operator

continue:
movb (%rsi), %al
incq %rsi
jmp parse

operator:
movb $',', (%rdi)
incq %rdi
cmpq %rsp, %rbx         # Jump if stack empty
je push_operator
movb (%rsp), %cl
prior %cl, %cl
cmpb %cl, %dl
jg push_operator
pop %rdx
movb %dl, (%rdi)
incq %rdi
jmp operator

push_operator:
push %rax
jmp continue

operand:
movb %al, (%rdi)
incq %rdi
jmp continue

prepend_zero:
movb $'0', (%rdi)
incq %rdi
jmp parse

recurse:
push %rbx
call _infixToPostfix
pop %rbx
decq %rdi
jmp continue

return:
cmpq %rsp, %rbx           # Check if the stack is empty
je exit
movb $',', (%rdi)
incq %rdi
pop %rax
movb %al, (%rdi)
incq %rdi
jmp return

exit:
movb $0, (%rdi)
incq %rdi
add $8, %rsp
ret
