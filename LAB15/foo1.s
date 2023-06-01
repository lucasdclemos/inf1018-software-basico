.text
.globl  foo1
foo1:
  cvtsd2ss %xmm0, %xmm0
  movss  %xmm1, %xmm2
  addss  %xmm0, %xmm2
  subss  %xmm1, %xmm0
  mulss  %xmm2, %xmm0
  ret
  