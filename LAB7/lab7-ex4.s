.data
nums:   .int  65,  -105,  111,  34
Sf:  .string "soma = %d\n"

.text
.globl main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
/********************************************************/

  movq  $nums, %r12
  movl  $0, %ebx    /*i*/
  movl  $0, %eax    /*soma*/

L1:
  cmpl  $4, %ebx
  je  L2

  movl  %ebx, %edx  /* preserva i */
  imull  $4, %edx   
  movq  %r12, %r13  /* preserva nums */

  movslq  %edx, %rcx
  addq  %rcx, %r12
  addl  (%r12), %eax
  movq  %r13, %r12

  incl  %ebx
  jmp L1

L2:
    /*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/
/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  leave
  ret      
/***************************************************************/