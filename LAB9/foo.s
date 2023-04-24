foo:
  pushq %rbp        # salva o ponteiro da base da pilha atual
  movq  %rsp, %rbp  # move o ponteiro da base da pilha para o topo da pilha atual
  pushq %rbx        # salva o registrador ebx na pilha
  movl  %edi, %ebx  # move o primeiro parâmetro (a[]) para o registrador ebx
  movl  $0, %eax    # inicializa a variável de soma s com 0
  movl  %esi, %ecx  # move o segundo parâmetro (n) para o registrador ecx
  testl %ecx, %ecx  # verifica se n é igual a 0
  jle   END         # se n for menor ou igual a 0, pula para o final da função

FOR:
  movl  (%ebx), %edx  # carrega o valor atual de a[i] em edx
  addl  %edx, %eax    # soma o valor de a[i] à variável s
  cmpl  $0, %edx      # verifica se a[i] é igual a 0
  jne   END_IF        # se não for, pula para o fim do bloco if

  movl  %eax, (%ebx)  # armazena o valor de s em a[i]
  movl  $0, %eax      # zera a variável s

END_IF:
  addq  $4, %ebx   # incrementa o ponteiro do array a[]
  subl  $1, %ecx   # decrementa o contador i
  jnz   FOR        # se i ainda for maior que 0, volta para o início do loop

END:
  popq %rbx
  movl %edi, %eax        # recupera o valor original do registrador ebx
  leave           # remove o quadro da pilha e restaura o valor do ponteiro da base da pilha
  ret  
