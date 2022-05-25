<h1 align="center">Solving Maze (DFS / BFS)</h1>


<p align="center">Grupo: Gabriel Mesquita || Augusto Bebiano</p>
<h1 align="center"> 
    <a href="https://github.com/gabrielmesquita7/solving_maze-BFS-and-DFS-/graphs/contributors">
    <img src="https://contrib.rocks/image?repo=gabrielmesquita7/solving_maze-BFS-and-DFS-" />
    </a>
</h1>
<p align="center">
  <a href="#problema">Problema</a> -
  <a href="#desenvolvimento">Desenvolvimento</a> -
  <a href="#entrada">Entrada</a> -
  <a href="#interacoes">Interacoes</a> -
  <a href="#saida">Saida</a> -
  <a href="#executar">Executar</a>
</p>
 

# Problema
### Regras
1. O jogo deve ser elaborado utilizando um arquivo de configuração. Nele deve conter: (a) tamanho da matriz; (b) posições das paredes e; (c) tipo de busca.
1. O jogo termina assim que for atingido o alvo.
1. É preciso imprimir o caminho em tela sob uma representação de matriz. Então, imprima conforme o exercício de matriz já realizado.

  ![image](https://user-images.githubusercontent.com/55333375/169049899-b17b7be9-8a69-4b39-8b7e-d7464130bb87.png)


### Perguntas
* Para diferentes tamanhos de matriz e posicionamento de paredes, há predominância de um dos dois algoritmos em termos de casas caminhadas e tempo de execução?
* R: **Há predominancia do BFS em numero de interações e casas caminhadas, pois sendo um metodo que caminha em ondas a maioria das matrizes é percorrida quase inteira**
* Um dos dois algoritmos consegue encontrar o melhor caminho, ou seja, o com menor número de passos?
* R: **Depende, se levarmos em consideração somente os dois o DFS é o que encontra o melhor caminho, porém se compararmos outros algaritmos nenhum dos dois consegue ser o melhor em termos de menor numero de passos**

# Desenvolvimento
### O problema foi desenvolvido da seguinte maneira:

* É definido pelo usuario o tamanho da **fila** atribuindo o valor para **N** na função **define**
* É definido pelo usuario o tamanho da **pilha**  atribuindo o valor para **N** na função **define**

* ![image](https://user-images.githubusercontent.com/55333375/167706372-01a0bb6c-44d1-497e-8685-cdc1d21979c6.png)

* Também é definido um máximo de 1024 caracteres em uma linha

* ![image](https://user-images.githubusercontent.com/55333375/167706445-478ff54e-dc10-482c-a0a5-ccbca8d0e7f6.png)

* É feito a abertura do arquivo por meio do **fopen()** e depois tokenizado pela função **TokenizerM()**, dentro dessa função a primeira coisa sendo feita é a tokenização do tamanho da matriz, da posição dos obstaculos e do tipo de busca, e por fim iniciado a matriz de acordo com os parametros e retornando a mesma.
![image](https://user-images.githubusercontent.com/55333375/169050608-887c45c1-2866-4355-9179-97e663b8ff0a.png)
![image](https://user-images.githubusercontent.com/55333375/169050955-d566d211-5d66-4aae-964f-9844bcf0432f.png)



* Depois é executado a função **TipoCaminho()**
* Dentro da função é feito a passagem de um if/else com o tipo de busca especificado no arquivo de texto  para determinar o método a ser executado, por fim é executado o método escolhido.

![image](https://user-images.githubusercontent.com/55333375/169051182-a70aa339-8f9a-49bd-98d2-1e13291ace08.png)

* Por fim é impresso a matriz com o caminho percorrido

# Entrada
### A entrada do usuário é feito no arquivo _gameconfig.txt_ e segue a seguinte estrutura:
Linha   | variavel
--------- | ------
1 | ( l x c ) -> Tamanho da matriz
2 | ( l x c ) , ( l x c ) , ... -> Posições dos obstaculos
3 | Tipo de busca

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
