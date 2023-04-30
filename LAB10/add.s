.text
.globl	add
add:
  pushq  %rbp
  movq  %rsp, %rbp
  movq  %rdi, -16(%rbp)

  movl  $0, -4(%rbp)

for:
  cmpq  $0, -16(%rbp)
  je  end_for

  movq  -16(%rbp), %r11
  movl  (%r11), %r11d
  addl  %r11d, -4(%rbp)

  movq  -16(%rbp), %r12  
  movq  8(%r12), %r12
  movq  %r12, -16(%rbp)
  jmp  for

end_for:
  movl  -4(%rbp), %eax
  movq  %rbp, %rsp
  popq  %rbp 
  ret
