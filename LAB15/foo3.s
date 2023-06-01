.text
.globl  foo3
foo3:
  pushq  %rbp
  movq  %rsp, %rbp
  subq  $16, %rsp
  cvtss2sd  %xmm0, %xmm0
  cvtss2sd  %xmm1, %xmm1
  movsd  %xmm1, -8(%rbp)
  call  sin
  movsd  %xmm0, -16(%rbp)
  movsd  -8(%rbp), %xmm0
  call  cos
  addsd  -16(%rbp), %xmm0
  leave
  ret
  