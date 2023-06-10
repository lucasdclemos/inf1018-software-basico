.text
.globl  main
main:
  pushq  %rbp
  movq  %rsp, %rbp
  subq  $32, %rsp
  movl  $100, %eax
  movl  $100, %ebx
  imull  %ebx, %eax
  movl  %eax, -12(%rbp)
  leave
  ret
