.text
.globl  main
main:
  pushq  %rbp
  movq  %rsp, %rbp
  subq  $32, %rsp
  movl  $1, -4(%rbp)
  movl  $2, %eax
  movl  -4(%rbp), %ebx
  addl  %ebx, %eax
  movl  %eax, -12(%rbp)
  movl  -12(%rbp), %eax
  leave 
  ret