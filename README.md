# Linguagem-C-lab05
Quinto laboratório da disciplina Estrutura de Dados da Universidade Estadual de Campinas

Lista crossref
Este trabalho consiste em implementar uma lista duplamente encadeada que vamos chamar de lista crossref. Cada nó i na lista armazena

um apontador para o sucessor e para o precedessor,
um apontador, que vamos chamar de ref e aponta para algum outro nó na lista ou é nulo,
um float, que vamos chamar de chave,
um inteiro, que vamos chamar de tempo e registra um momento discreto de tempo em que a chave foi inserida, contado a partir do tempo 1.

[Entrada]
Seu programa deve ler um conjunto de valores da entrada padrão. A entrada contém um conjunto de linhas. Cada linha tem três formas possíveis:

i x k y 

sendo x um float, k um inteiro e y um float, significando que um novo nó deve passar a ocupar a posição k da lista e deve ter chave igual a x. A posição da cabeça é 0. No novo nó, ref deve apontar para o nó mais próximo da posição k que tem chave igual a y, resolvendo empates dando preferência para um predecessor. Se y=0.0 ou não houver nó com chave y na lista, então o apontador ref deve ser nulo. O nó deve ainda registrar o tempo corrente, que deve ser incrementado depois da inserção.

r x 

sendo x um float, significando que o nó mais próximo da cabeça que contiver a chave x deve ser removido. Todos os nós com apontadores ref apontando para o nó que será removido devem ser atualizados para nulo. O tempo corrente deve ser incrementado depois da remoção.

p 

significa que seu programa deve imprimir as chaves e o tempo armazenado nos nós da lista ao percorrê-la da cabeça para o rabo, no formato que aparece no exemplo abaixo. Quando um nó contiver um apontador ref não-nulo, o programa deve imprimir, após o tempo, a chave e o tempo no nó apontado por ref. Se a lista estiver vazia, o programa deve imprimir vazia em uma linha.

f 
indicando o fim do programa.

[Saída]
A saída do programa são as linhas produzidas pelos comandos p.
Antes de terminar, seu programa deve liberar toda a memória alocada dinamicamente por ele.
