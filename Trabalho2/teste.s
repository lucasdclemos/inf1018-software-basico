.text
.globl  main
main:
  pushq  %rbp
  movq  %rsp, %rbp
  subq  $32, %rsp
  movl  -8(%rbp), %eax
  movl  -4(%rbp), %ebx
  addl  %ebx, %eax
  movl  %eax, -12(%rbp)
  leave
  ret
