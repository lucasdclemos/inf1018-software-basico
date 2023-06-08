.text
.globl  main
main:
  pushq  %rbp
  movq  %rsp, %rbp
  subq  $32, %rsp
  movl  -8(%rbp), %eax
  addl  $-100, %eax
  movl  %eax, -12(%rbp)
  leave
  ret
