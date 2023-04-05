.data
Sf:  .string "Máximo: %d\n"

.text 
.globl main
main:
/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  /* guarda rbx */
  movq    %r12, -16(%rbp)  /* guarda r12 */
/********************************************************/
  movq  $dados, %r12        # *p = dados
  movl  $0, %ebx        # i = 0
  movl  $0, %eax        # max = 0

FOR:
  cmpl  $3, %ebx
  je  RET
  cmpb  $0, (%r12)
  je  END_IF
  cmpl  %eax, 4(%r12)
  jle  END_IF

  movl  4(%r12), %eax

END_IF:
  addq  $8, %r12
  incl  %ebx
  jmp  FOR

RET:
  /*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/
  /***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
 movq  	$0, %rax  /* rax = 0  (valor de retorno) */
  movq  	-8(%rbp), %rbx
  movq  	-16(%rbp), %r12
  leave
  ret      
/***************************************************************/



  