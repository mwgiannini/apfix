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
.lcomm buffer, 100                  # Buffer to hold operands

.text
.global _evalPostfix
_evalPostfix:
sub $8, %rsp
movq %rdi, %rcx
xorq %rbx, %rbx                      # Number of characters in the operand buffer

parse:                              # Parse the input string

lodsb                               # Get the next character
cmpb $',', %al
je comma                            # Jump if ,
cmpb $'+', %al
je add                              # Jump if +
cmpb $'-', %al
je subtract                         # Jump if -
cmpb $'/', %al
je multiply                         # Jump if /
cmpb $'*', %al
je divide                           # Jump if *
jmp operand                         # Jump if anything else (part of an operand)

continue:
loop parse

popsd %xmm0                         # Get the result from the stack
add $8, %rsp
ret

operand:                            # Add the character to the buffer
leaq buffer(%rip), %rdx
movb %al, (%rdx, %rbx, 1)
incq %rbx
jmp continue

comma:
leaq buffer(%rip), %rdx             # Null terminate the buffered string
movb $0, %al
movb %al, (%rdx, %rbx, 1)
xorq %rbx, %rbx

leaq buffer(%rip), %rdi             # Get the floating point value of the string in the buffer
push %rcx
push %rsi
call _getValue
pop %rsi
pop %rcx

pushsd %xmm0                        # Push the value to the stack
# No need to clear the buffer, it will be overwritten
jmp continue

# For each operation, pop the top two values from the stack and return the result to the stack
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

.end
