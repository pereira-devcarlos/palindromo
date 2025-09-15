# 🧩 Trabalho Prático 1 – Palíndromos  

## 📌 Descrição  
Este projeto foi desenvolvido como parte da disciplina **Algoritmos e Estruturas de Dados II (AEDS 2)** da **Universidade Federal de Alfenas (UNIFAL-MG)**.  

O objetivo do trabalho é implementar um **algoritmo em C** capaz de verificar se uma palavra, frase ou número é um **palíndromo**.  

Um **palíndromo** é uma sequência de caracteres que pode ser lida da esquerda para a direita ou da direita para a esquerda mantendo-se igual.  
Exemplos:  
- `Ana`  
- `Otto`  
- `01010`  
- `Roma me tem amor`  
- `12/3/21`  

⚠️ Importante: No reconhecimento de palíndromos, **acentos, cedilha, espaços e sinais de pontuação não são considerados**.  

---

## 🛠 Estruturas de Dados Utilizadas  
O trabalho **não permite** o uso direto de funções de manipulação de strings para inverter ou percorrer a entrada.  
Foram utilizadas apenas as estruturas de dados estudadas em sala:  

- **Listas**  
- **Filas**  
- **Pilhas**  

Essas estruturas permitem manipular os caracteres de forma organizada e verificar a simetria da sequência.  

---

## 📂 Estrutura do Projeto  

```
📦 trabalho-palindromos
┣ 📜 main.c              # Código principal
┣ 📜 lista.c / lista.h   # Implementação de listas
┣ 📜 fila.c / fila.h     # Implementação de filas
┣ 📜 pilha.c / pilha.h   # Implementação de pilhas
┣ 📜 Makefile            # Automação da compilação
┣ 📜 README.md           # Documentação do projeto
┗ 📂 entradas
┗ 📜 entrada.txt      # Arquivo de entrada com expressões

````

---

## ▶️ Execução do Programa  

### 🔧 Compilação  
O projeto utiliza **Makefile** para facilitar a compilação.  
No terminal, execute:  

```bash
make
````

Isso irá gerar o executável `palindromos`.

### 📥 Entrada

O programa recebe um **arquivo de texto** (`entrada.txt`) contendo as expressões a serem verificadas, uma por linha.

Exemplo de entrada (`entrada.txt`):

```
Ana
Maria
12/3/21
01010
OtTo
Ônibus
```

### 📤 Saída

A saída é padronizada e mostra se a expressão é ou não um palíndromo.

* `1` → é palíndromo
* `0` → não é palíndromo

Além disso, o programa deve mostrar o **passo a passo da verificação em duas colunas** (entrada → saída).

Exemplo de saída:

```
Ana,1
Maria,0
12/3/21,1
01010,1
OtTo,1
Ônibus,0
```

---

## 📊 Complexidade

A análise de complexidade deve ser descrita no relatório (`.pdf`) conforme solicitado no enunciado:

* **Tempo:** Depende do tamanho da entrada `n`, sendo `O(n)` para verificar se a palavra é palíndromo.
* **Espaço:** Estruturas auxiliares (pilhas e filas) também ocupam `O(n)`.

---

## 📑 Relatório

Além do código, cada grupo deverá entregar um relatório em `.pdf` com as seções:

1. Introdução (definição e contexto do problema)
2. Estruturas de dados utilizadas
3. Descrição e análise do algoritmo (incluindo complexidade)
4. Explicação do Makefile e instruções de compilação

---

## 👨‍💻 Autores

* Carlos Eduardo Pereira dos Santos
* Marcos Felipe dos Reis Bento
* Guilherme Aredes

