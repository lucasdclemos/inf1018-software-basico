  .data
  s1: .string "ls -ls"

  .text
  .globl main
  main:
  /* prologo */
    pushq %rbp
    movq  %rsp, %rbp

    movq  $s1, %rdi
    movl  $0, %eax
    call printf

  /* finalizacao */
    leave
    ret