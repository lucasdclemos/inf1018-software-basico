.data
S1:  .string "numero: "
Sf:  .string "%d"  

.text
.globl  novonum
novonum:
  pushq  %rbp
  movq  %rsp, %rbp
  subq  $16, %rsp

  movq  $S1, %rdi
  call printf

  movq  $Sf, %rdi
  leaq  -4(%rbp), %rsi
  call  scanf

  movl  -4(%rbp), %eax

  leave
  ret

