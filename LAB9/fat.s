.text
.globl  fat
fat:
  pushq  %rbp
  movq  %rsp, %rbp
  subq  $16, %rsp

L1:
  cmpl  $0, %edi
  jne  L2
  movl  $1, %eax
  leave
  ret

L2:
  pushq  %rdi
  decl  %edi
  call  fat
  popq  %rdi
  imull  %edi, %eax
  leave
  ret
