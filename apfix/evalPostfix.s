#
#  eval.s
#  apfix
#
#  Created by Amor Wang & MW Giannini on 11/26/22.
#

# Macros for pushing and popping double precision values
.macro pushsd r
sub $8, %rsp
movsd \r, (%rsp)
.endm

.macro popsd r
movsd (%rsp), \r
add $8, %rsp
.endm

.bss
.lcomm buffer, 100                  # Operand buffer

.text
.global _evalPostfix
_evalPostfix:
sub $8, %rsp
movq %rdi, %rsi                     # Address of the input string
leaq buffer(%rip), %rbx             # Address of next buffer byte

parse:                              # Parse the input string
movb (%rsi), %al                    # Get the next character
cmpb $',', %al
je comma                            # Jump if al contains ','
cmpb $'+', %al
je add                              # Jump if al contains '+'
cmpb $'-', %al
je subtract                         # Jump if al contains '-'
cmpb $'*', %al
je multiply                         # Jump if al contains '*'
cmpb $'/', %al
je divide                           # Jump if al contains '/'
cmpb $'^', %al
je power                            # Jump if al contains '^'
cmpb $0, %al
je exit                             # Jump if al contains '\0'
jmp operand                    # Else, al contains part of operand

continue:
incq %rsi                           # Next byte
jmp parse

exit:
popsd %xmm0                         # Get the result from the stack
add $8, %rsp
ret

operand:                            # Add to operand buffer
movb %al, (%rbx)
incq %rbx
jmp continue

comma:
leaq buffer(%rip), %rdx
cmpq %rdx, %rbx                     # Continue if buffer is empty,
je continue                         #   operator was just read
xorb %al, %al
movb %al, (%rbx)                    # Null terminate buffer
movq %rdx, %rbx                     # Clear the buffer
movq %rdx, %rdi
push %rsi
call _getValue              # Get floating point value of operand
pop %rsi
pushsd %xmm0                        # Push the value to the stack
jmp continue

# For each operation, pop top two values from stack and return the result to stack
add:
popsd %xmm0
popsd %xmm1
addsd %xmm0, %xmm1
pushsd %xmm1
jmp continue

subtract:
popsd %xmm0
popsd %xmm1
subsd %xmm0, %xmm1
pushsd %xmm1
jmp continue

multiply:
popsd %xmm0
popsd %xmm1
mulsd %xmm0, %xmm1
pushsd %xmm1
jmp continue

divide:
popsd %xmm0
popsd %xmm1
divsd %xmm0, %xmm1
pushsd %xmm1
jmp continue

power:
popsd %xmm1
popsd %xmm0
push %rsi
call _getPower
pop %rsi
pushsd %xmm0
jmp continue

.end
