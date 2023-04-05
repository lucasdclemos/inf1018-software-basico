.data
Sf:  .string "%d\n"

.text
.globl main
main:
/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
/********************************************************/

  movl  $1, %ebx

L1:
  cmpl  $11, %ebx
  je  L2
  movl  %ebx, %ecx
  imull  %ecx, %ecx
  
  movl  %ecx, %eax
  /*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/

  incl  %ebx
  jmp  L1

L2:
/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  leave
  ret      
/***************************************************************/
  





