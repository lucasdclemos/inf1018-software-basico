.data
nums: .int 3, -5, 7, 8, -2
s1:   .string "%d\n"

.text
.globl main
main:
/* prologo */
  pushq %rbp
  movq  %rsp, %rbp
  subq  $16, %rsp
  movq  %rbx, -8(%rbp)
  movq  %r12, -16(%rbp)

  movq  $nums, %r12
  movl  $0, %ebx

FOR:
  cmpl  $5, %ebx
  je  END_FOR

  movl  (%r12), %edi
  movl  $1, %esi
  call  filtro
  movl  %eax, %ecx

  movq  $s1, %rdi
  movl  %ecx, %esi
  movl  $0, %eax
  call  printf


  addq  $4, %r12
  incl  %ebx
  jmp  FOR

END_FOR:
/* finalizacao */
  movq -8(%rbp), %rbx
  movq -16(%rbp), %r12
  leave
  ret