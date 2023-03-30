.data
nums:  .int  10, -21, -30, 45
Sf:  .string "%d\n" 

.text
.globl  main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)
  movq    %r12, -16(%rbp)
/********************************************************/

  movl  $0, %ebx    /* ebx (i) = 0 */
  movq  $nums, %r12     /* r12 = &nums */

FOR:
  cmpl  $4, %ebx
  je  RET

  movl  (%r12), %ecx
  andl  $1, %ecx
  cmpl  $1, %ecx
  je  PRINT

  addl  $1, %ebx
  addq  $4, %r12
  jmp  FOR

PRINT:
  movl  (%r12), %eax

  /*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/
  addl  $1, %ebx
  addq  $4, %r12
  jmp FOR

RET:

/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq  -8(%rbp), %rbx
  movq  -16(%rbp), %r12
  leave
  ret      
/***************************************************************/