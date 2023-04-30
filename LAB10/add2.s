.text
.globl  add
add:
  pushq  %rbp
  movq  %rsp, %rbp
  subq  $16, %rsp
  movq  %rdi, -16(%rbp)
  
  movl  $0, -4(%rbp)

if:
  cmpq  $0, -16(%rbp)
  je  else

  movq  -16(%rbp), %r11
  movl  (%r11), %r11d
  movl  %r11d, -4(%rbp)

  movq  -16(%rbp), %r12
  movq  8(%r12), %r12
  movq  %r12, -16(%rbp)
  movq  %r12, %rdi

  call  add

  addl  %eax, -4(%rbp)
  jmp  ret

else:
  movl  $0, -4(%rbp)
  jmp  ret

ret:
  movl  -4(%rbp), %eax
  movq  %rbp, %rsp
  popq  %rbp
  ret
