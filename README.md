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

![image](https://user-images.githubusercontent.com/55333375/170543988-20a617b4-c1b6-4883-950a-67a49c82121f.png)

* Por fim é impresso a matriz com o caminho percorrido

# Relatorio
## BFS
#### Breadth First Search (BFS) é o método de deslocamento usado na matriz. Ele usa uma fila para armazenar os vértices visitados. Neste método a ênfase está nos vértices da matriz, um vértice é selecionado no início, então é visitado e marcado. Os vértices adjacentes ao vértice visitado são então visitados de modo que se pareça com uma **onda** e armazenados  na fila sequencialmente. Da mesma forma, os vértices armazenados são então tratados um por um, e seus vértices adjacentes são visitados. Uma posição é totalmente explorada antes de visitar qualquer outra posição na matriz, em outras palavras, ele percorre as posições inexploradas mais rasas primeiro.
* **O BFS é o melhor em encontrar o caminho mais curto na matriz que pode ser visto como uma rede, porém seu custo continua alto.**
## DFS
#### O método de deslocamento DFS (Depth First Search) usa a pilha para armazenar os vértices visitados. O DFS é o método baseado em linhas e funciona de maneira recursiva, em que os vértices são explorados ao longo de um caminho (linha). A exploração de uma posição é suspensa assim que outra posição inexplorada é encontrada e as posições mais inexploradas mais profundas são percorridas antes de tudo. DFS atravessar / visitar cada vértice exatamente uma vez e cada borda é inspecionada exatamente duas vezes.
* **A vantagem do DFS é que ele consome muito menos espaço de memória e ele alcançará a posição objetivo em um período de tempo menor que o BFS se percorrer um caminho certo.** 
## BFS x DFS
Base para comparação    | BFS | 	DFS
--------- | ------ | -------
Basic| 	Algoritmo baseado em vértices | 	Algoritmo baseado em borda
Estrutura de dados usada para armazenar os nós | Fila | 	Pilha
Consumo de memória	| Ineficiente | Eficiente
Estrutura do caminho construído | Largo e curto | 	Estreito e longo
Modo de caminhar | Vértices não visitados mais antigos são explorados em primeiro lugar. | Vértices ao longo da borda são explorados no começo.
## A* 
#### **A*** é um algoritmo de busca que é usado para encontrar o caminho mais curto entre um ponto inicial e um ponto final.
#### Ele procura por caminhos mais curtos primeiro, tornando-o um algoritmo ideal e completo. Um algoritmo ótimo encontrará o resultado de menor custo para um problema, enquanto outro algoritmo encontrará todos os resultados possíveis de um problema.
#### Inicialmente, o Algoritmo calcula o custo para todos os nós vizinhos imediatos, e escolhe aquele de menor custo. Esse processo se repete até que nenhum novo nó possa ser escolhido e todos os caminhos tenham sido percorridos.
#### O algoritmo funciona de maneira que tem alguma estimativa (chamada **heurística**) de quão longe do objetivo está qualquer vértice. Em vez de selecionar o vértice mais próximo do ponto de partida, ele seleciona o vértice mais próximo do objetivo.  
## A* x BFS
#### O BFS sempre encontrará o caminho mais curto entre o nó inicial e um nó de destino. Além disso, o BFS encontrará o caminho mais curto entre o nó inicial e todos os outros nós do grafo. No entanto, o algoritmo pode ser ineficiente, pois 'perderá tempo' avaliando rotas que podem ser ignoradas.

#### O algoritmo A* é mais eficiente que o BFS. Ao usar uma função heurística para fornecer uma estimativa do custo do caminho entre cada nó e o nó de destino, ele pode fazer melhores escolhas sobre o próximo caminho a seguir e encontrar o caminho mais curto mais rapidamente.

#### O maior desafio na seleção de A* é a necessidade de uma boa função heurística. O tempo que leva para fornecer a heurística não deve anular nenhuma economia de tempo no processo de busca de caminhos. Além disso, a heurística não deve superestimar o custo do caminho. Se h(n) for sempre menor que (ou igual) ao custo de se mover de n para o nó de destino, então A* terá a garantia de encontrar o caminho mais curto.

## Conclusão
#### BFS e DFS, ambas as técnicas de busca de matrizes têm tempo de execução semelhante, mas consumo de espaço diferente, o DFS ocupa espaço linear porque temos que lembrar um único caminho com nós inexplorados, enquanto o BFS mantém todos os nós na memória.

#### O DFS produz soluções mais profundas e não é o ideal, mas funciona bem quando a solução é densa, enquanto o BFS é o ideal, que busca primeiro o objetivo ideal.
#### Já o A* consegue produzir o melhor caminho e ser mais eficiente que todos os outros devido o uso de heurísticas.

## Resultados
### Foi observado que dentre os metodos utilizados (BFS, DFS e A*) foram obtidos os seguintes resultados para a mesma matriz e os mesmos obstaculos:
*obs: os resultados são baseados no numero de interações, as mesmas sendo contabilizadas na forma especificada na aba "Interacoes" do readme.*

**Matriz 10x10** 

**Obstáculo: [3,3]**


Metodo   | Resultado
--------- | ------
DFS | 19 interações
BFS | 99 interações
A* (manhattan) | 35 interações
A* (euclidiâna) | 37 interações

![image](https://user-images.githubusercontent.com/55333375/170544912-4444b012-f2ff-49fc-a842-89f47e8f1a22.png)

![image](https://user-images.githubusercontent.com/55333375/170545046-0b127c2e-5f30-4067-9790-161de396b6ce.png)

![image](https://user-images.githubusercontent.com/55333375/170545104-9a120d07-dd09-48d8-b813-cdbbd5e1cad0.png)

![image](https://user-images.githubusercontent.com/55333375/170545177-691564f8-1cd5-43ed-b0b1-19302cae29ee.png)

![image](https://user-images.githubusercontent.com/55333375/170545252-7d46ef2e-02cb-4ef4-87cd-6fc6b9f4a9f3.png)



# Entrada
### A entrada do usuário é feito no arquivo _gameconfig.txt_ e segue a seguinte estrutura:
Linha   | variavel
--------- | ------
1 | ( l x c ) -> Tamanho da matriz
2 | ( l x c ) , ( l x c ) , ... -> Posições dos obstaculos


![image](https://user-images.githubusercontent.com/55333375/170544365-c7d0070b-566e-4587-9af6-45401050c54f.png)


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
