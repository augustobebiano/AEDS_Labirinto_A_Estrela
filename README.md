<h1 align="center">A*</h1>


<p align="center">Grupo: Gabriel Mesquita || Augusto Bebiano</p>
<h1 align="center"> 
    <a href="https://github.com/gabrielmesquita7/solving_maze-BFS-and-DFS-/graphs/contributors">
    <img src="https://contrib.rocks/image?repo=gabrielmesquita7/solving_maze-BFS-and-DFS-" />
    </a>
</h1>
<p align="center">
  <a href="#problema">Problema</a> -
  <a href="#desenvolvimento">Desenvolvimento</a> -
  <a href="#relatorio">Relatorio</a> -
  <a href="#entrada">Entrada</a> -
  <a href="#interacoes">Interacoes</a> -
  <a href="#saida">Saida</a> -
  <a href="#executar">Executar</a>
</p>
 

# Problema
### Cada dupla de alunos deve entregar um trabalho contemplando as modificações necessárias do BFS para torna-lo um algoritmo heurístico, chamado A*. Nessa etapa do trabalho é de responsabilidade de cada dupla: 
* Entregar a codificação devidamente elaborada sob o modelo de execução estabelecido, bem como, a comparação do algoritmo A* para as heurísticas euclidiâna e manhattan 
* Um relatório contemplando uma discussão comparativa entre BFS, DFS e A*. Espera-se que este documento apresente fatores comparativos de velocidade de execução e quantidade de passos para a finalização do labirinto. Além disso, espera-se que cada dupla aprofunde em uma apresentação adequada do modelo de funcionamento de cada um e os motivos que tornam uma das soluções a melhor opção.

# Desenvolvimento
### O problema foi desenvolvido da seguinte maneira:

* É definido pelo usuario o tamanho da **fila** atribuindo o valor para **N** na função **define**
* É definido pelo usuario o tamanho da **pilha**  atribuindo o valor para **N** na função **define**

* ![image](https://user-images.githubusercontent.com/55333375/167706372-01a0bb6c-44d1-497e-8685-cdc1d21979c6.png)

* Também é definido um máximo de 1024 caracteres em uma linha

* ![image](https://user-images.githubusercontent.com/55333375/167706445-478ff54e-dc10-482c-a0a5-ccbca8d0e7f6.png)

* É feito a abertura do arquivo por meio do **fopen()** e depois tokenizado pela função **TokenizerM()**, dentro dessa função a primeira coisa sendo feita é a tokenização do tamanho da matriz, da posição dos obstaculos e do tipo de busca, e por fim iniciado a matriz de acordo com os parametros e retornando a mesma.
* Depois é executado a função **TipoCaminho()**
* Dentro da função é feito a passagem de um if/else com o tipo de busca especificado pelo usuario para determinar o método a ser executado, **se for escolhido o A estrela vai ser requisitado qual heuristica a ser utilizada (manhattan / euclidiâna)**  e por fim é executado o método escolhido.

![image](https://user-images.githubusercontent.com/55333375/169051182-a70aa339-8f9a-49bd-98d2-1e13291ace08.png)

* Por fim é impresso a matriz com o caminho percorrido

# Relatorio
* Um relatório contemplando uma discussão comparativa entre BFS, DFS e A*. Espera-se que este documento apresente fatores comparativos de velocidade de execução e quantidade de passos para a finalização do labirinto.

Foi observado que dentre as 




 * Além disso, espera-se que cada dupla aprofunde em uma apresentação adequada do modelo de funcionamento de cada um e os motivos que tornam uma das soluções a melhor opção 

## BFS
#### Breadth First Search (BFS) é o método de deslocamento usado nos gráficos. Ele usa uma fila para armazenar os vértices visitados. Neste método a ênfase está nos vértices do gráfico, um vértice é selecionado no início, então é visitado e marcado. Os vértices adjacentes ao vértice visitado são então visitados e armazenados na fila sequencialmente. Da mesma forma, os vértices armazenados são então tratados um por um, e seus vértices adjacentes são visitados. Um nó é totalmente explorado antes de visitar qualquer outro nó no gráfico, em outras palavras, ele percorre os nós inexplorados mais rasos primeiro.
# Entrada
### A entrada do usuário é feito no arquivo _gameconfig.txt_ e segue a seguinte estrutura:
Linha   | variavel
--------- | ------
1 | ( l x c ) -> Tamanho da matriz
2 | ( l x c ) , ( l x c ) , ... -> Posições dos obstaculos


![image](https://user-images.githubusercontent.com/55333375/169051599-1ae89acc-3e9b-420a-ad42-a2a76e61ded1.png)


# Interacoes
### A contagem do numero de interações foi calculado de forma que considera cada nova posição ocupada na matriz uma interação, ou seja, não sera contabilizado checagens ou mesmo voltar para a mesma posição.

# Saida
### É esperado que a saida tenha o print da matriz após tokenizada, depois a matriz com o caminho percorrido de acordo com o tipo escolhido e por fim o numero de interações que aquele tipo gastou

![image](https://user-images.githubusercontent.com/55333375/169157091-ad123db6-6269-486d-8870-19af47b68f1b.png)

![image](https://user-images.githubusercontent.com/55333375/169157174-5831f671-328f-4639-9323-971151271d97.png)





# Executar
* Como executar:

```
  make clean
  make
  make run
```
