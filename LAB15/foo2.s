.text
.globl  foo2
foo2:
  pushq  %rbp
  movq  %rsp, %rbp
  subq  $16, %rsp
  cvtss2sd  %xmm0, %xmm0
  cvtss2sd  %xmm1, %xmm1
  movsd  %xmm1, -8(%rbp)
  call  sin
  movsd  -8(%rbp), %xmm1
  addsd  %xmm1, %xmm0
  cvtsd2ss %xmm0, %xmm0
  leave
  ret
  