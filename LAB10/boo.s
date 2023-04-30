.text
.globl  boo
boo:
  pushq  %rbp
  movq  %rsp, %rbp
  subq  $16, %rsp
  movq  %rbx, -8(%rbp)
  movq  %r12, -12(%rbp)
  movq  %r13, -16(%rbp)

  movq  %rdi, %rbx
  movl  %esi, %r12d
  movl  %edx, %r13d

while:
  cmpl  $0, %r12d
  je  end_while
  
  movl  (%rbx), %edi
  movl  %r13d, %esi

  call  f

  movl  %eax, 4(%rbx)

  addq  $8, %rbx
  decl  %r12d
  jmp  while

end_while:
  movq  -16(%rbp), %r13
  movq  -12(%rbp), %r12
  movq  -8(%rbp), %rbx
  addq  $16, %rsp
  leave
  ret
