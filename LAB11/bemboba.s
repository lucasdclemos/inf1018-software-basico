.text
.globl  bemboba
bemboba:
  pushq  %rbp
  movq  %rsp, %rbp
  subq  $16, %rsp
  
  movl  $0, %ecx  /* i = 0 */
  leaq  -16(%rbp), %r10  /* a = local */
for:
  cmpl  $4, %ecx
  je  end_for
  
  movl  %edi, (%r10)
  
  addq  $4, %r10
  incl  %ecx
 
  jmp  for

end_for:
  leaq  -16(%rbp), %rdi
  movl  $4, %esi
  call  addl
  
  leave
  ret

