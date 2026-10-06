Aluno 01: Heitor dos Santos Brito
Aluno 02: Ítalo José de Castro Gontijo

1º:Instruções de Compilação e Execução
Para compilar e executar o programa no terminal utilizando o compilador gcc, siga os passos abaixo:

Compilação.

gcc MP02.c -o programa.

Execução:
Linux / macOS / Git Bash:

"./programa"
Windows (Prompt de Comando / PowerShell):
".\programa.exe"
Testando com arquivo de entrada (input.txt):
"./programa < input.txt"

2. Visão Geral do Sistema
O programa realiza uma série de transformações e manipulações em uma string lida do usuário.
Fluxo de Execução na Função main:

Leitura da String: O programa inicia lendo uma string inicial de até 10.000 caracteres através do comando scanf(" %[^\n]%*c", str).

   Laço de Manipulação (while): Entra em um loop contínuo para processar os comandos numéricos de operação:
   
   N = 1: Inverte toda a string.
   
   N = 2: Lê um inteiro n e aplica a cifra/deslocamento nos caracteres (letras e números).
   
   N = 3: Troca os caracteres das posições pares e ímpares adjacentes.
   
   N = 4: Inverte a caixa das letras (maiúsculas viram minúsculas e vice-versa).
   
   N = 5: Lê um inteiro n e rotaciona a string circularmente.
   
   N = 6: Troca a primeira metade da string com a segunda metade.
   
   Outro valor (N <= 0 ou N > 6): Interrompe o laço de repetição (break).
   
   Exibição do Resultado: Ao sair do laço, a string modificada é exibida no terminal através de printf("%s\n", str) e o programa encerra.
   
4. Decisões de Implementação: 
 Abaixo está a documentação detalhada da lógica de cada função implementada no código:

void invert(char *str)
    Objetivo: Inverter uma string inteira in-place usando aritmética de ponteiros.
    
    Lógica: Posiciona o ponteiro end no último caractere válido (antes de \0) e o ponteiro start no início. Realiza a troca dos caracteres avançando start e retrocedendo end até se encontrarem no meio da string.
    
void invert_sub(char *start, int size) (Função Auxiliar):
    Objetivo: Inverter uma sub-string de tamanho size a partir de um ponteiro start.
    Lógica: Substitui temporariamente o caractere no índice size pelo caractere nulo \0 para marcar o fim da sub-string, chama a função invert() padrão e restaura o caractere original.
void deslocar(char *str, int n)
    Objetivo: Aplicar um deslocamento circular (estilo Cifra de César) nos caracteres da string.
    Decisão para Positivos/Negativos: O ajuste (n % k + k) % k (onde k é o tamanho do alfabeto ou conjunto de dígitos) garante que rotações com valores negativos de n funcionem corretamente        sem resultar em módulos negativos no C.
   Regras de Deslocamento:
   Maiúsculas (A-Z): Alfabeto circular de 26 letras.
   Minúsculas (a-z): Alfabeto circular de 26 letras.
   Dígitos (0-9): Conjunto numérico circular de 10 dígitos.
void trocarMetades(char *str)
    Objetivo: Trocar a primeira metade da string com a segunda metade.
    Lógica: Calcula o tamanho total tam. Se houver número ímpar de caracteres, o caractere central permanece fixo (calculado pelo deslocamento tam % 2). Dois ponteiros (p1 no início e p2 na segunda metade) trocam elementos pela metade das iterações.
void trocaParesImpares(char *str)
    Objetivo: Permutar vizinhos adjacentes (índices 0 e 1, 2 e 3, etc.).
    Lógica: Percorre a string de 2 em 2 posições (p += 2), realizando a troca entre o caractere atual *p e o seguinte *(p+1). Garante que não haja invasão de memória caso a string tenha tamanho ímpar.
void invertCaixa(char *str)
    Objetivo: Converter caracteres maiúsculos para minúsculos e vice-versa.
    Lógica: Percorre caractere a caractere ajustando a diferença da tabela ASCII relativa ao deslocamento a partir de 'a' / 'A'.
void rotacionar(char *str, int n)
    Objetivo: Rotacionar circularmente a string à direita por n posições.
    Tratamento de valores positivos/negativos:
       Aplica-se n = n % len para simplificar rotações maiores que o tamanho da string. Caso n seja negativo, converte-se para a rotação equivalente positiva somando o comprimento (n += len).      Algoritmo de Rotação por Inversões:
       Utiliza o método clássico de 3 inversões:
       1º:Inverte a string inteira.
       2º:Inverte o primeiro bloco de n caracteres (invert_sub(str, n)).
       3º:Inverte o bloco restante de len - n caracteres (invert_sub(str + n, len - n)).
