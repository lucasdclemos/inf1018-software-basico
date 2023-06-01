.text
.globl  foo4
foo4:
  pushq  %rbp
  movq  %rsp, %rbp
  subq  $32, %rsp
  movl  $0, %r8d   /* int i = 0 */
  movl  $0, %r9d
  cvtsi2sd  %r9d, %xmm1     /* double r = 0.0 */

for:
  cmpl  %esi, %r8d
  jge  end_for
  movsd  %xmm1, -16(%rbp)
  movq  %rdi, -24(%rbp)
  movl  %esi, -28(%rbp)
  movsd  (%rdi), %xmm0
  call  sin
  movsd  -16(%rbp), %xmm1
  movq  -24(%rbp), %rdi
  movl  -28(%rbp), %esi
  addsd  %xmm0, %xmm1 
  addq  $8, %rdi
  incl  %r8d
  jmp  for

end_for:
  movsd  %xmm1, %xmm0
  leave
  ret
