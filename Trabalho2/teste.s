.data
Sf:  .string "%d\n"    # string de formato para printf

.text
.globl  main
main:
  pushq  %rbp
  movq  %rsp, %rbp
  subq  $32, %rsp
  movl  $-10, -4(%rbp)
  cmpl  $0, -4(%rbp)
  jle  teste
  movl  $0, %eax
  /*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/
  call  printf
  leave
  ret

teste:
  movl  -4(%rbp), %eax
  /*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/
  call  printf
  leave
  ret
