.text
.globl  map2
map2:

map2:
  pushq  %rbp
  movq  %rsp, %rbp
  subq  $32, %rsp
  movq  %rbx, -8(%rbp)
  movq  %r12, -16(%rbp)
  movq  %r13, -20(%rbp)

  movq  %rdi, %rbx
  movq  %rsi, %r12
  movl  %edx, %r13d
  movl  $0, -24(%rbp)

for:
  cmpl  %r13d, -24(%rbp)
  je  end_for

  movl  -24(%rbp), %r11d
  imull  $4, %r11d

  addq  %rbx, %r11
  movq  (%r11), %rdi
  call  f

  movl  -24(%rbp), %r11d
  imull  $4, %r11d

  addq  %r12, %r11
  movl  %eax, (%r11)

  addl  $1, -24(%rbp)

  jmp  for

end_for:
  movq  -8(%rbp), %rbx
  movq  -16(%rbp), %r12
  movq  -20(%rbp), %r13
  addq  $32, %rsp
  leave 
  ret 

  
