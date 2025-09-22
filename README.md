# 🧩 Trabalho Prático 1 – Palíndromos

## 📌 Descrição
Este projeto foi desenvolvido para a disciplina **Algoritmos e Estruturas de Dados II (AEDS 2)** da **UNIFAL-MG**.

O objetivo é implementar um **algoritmo em C** capaz de verificar se uma palavra, frase ou número é um **palíndromo**.

Um **palíndromo** é uma sequência de caracteres que pode ser lida da esquerda para a direita ou da direita para a esquerda mantendo-se igual.

**Exemplos:**
- `Ana`
- `Otto`
- `01010`
- `Roma me tem amor`
- `12/3/21`

⚠️ **Importante:** No reconhecimento de palíndromos, **acentos, cedilha, espaços e sinais de pontuação não são considerados**. O algoritmo normaliza a entrada removendo esses caracteres e convertendo tudo para minúsculo.

---

## 🛠 Estrutura de Dados Utilizada
O trabalho utiliza **apenas lista duplamente encadeada** para manipular os caracteres, conforme implementado em `lista.c` e `lista.h`. Não são usadas pilhas ou filas na versão atual do código.

---

## 📂 Estrutura do Projeto

```
palindromo/
├── LICENSE
├── README.md
├── data/
│   ├── entrada.txt
│   └── saida.txt
├── src/
│   ├── main.c
│   ├── makefile
│   └── build/
│       └── palindromo
│   └── lista/
│       ├── lista.c
│       └── lista.h
```

---

## ▶️ Execução do Programa

### 🔧 Compilação
O projeto utiliza **Makefile** para facilitar a compilação. No terminal, execute:

```bash
make
```

Isso irá gerar o executável em `src/build/palindromo`.

### 📥 Entrada
O programa lê o arquivo `data/entrada.txt`, onde cada linha contém uma expressão a ser verificada.

Exemplo de entrada (`data/entrada.txt`):

```
Ana
Maria
12/3/21
01010
OtTo
Ônibus
```

### 📤 Saída
O resultado é escrito em `data/saida.txt`, uma linha para cada expressão, indicando se é palíndromo (`1`) ou não (`0`).

Exemplo de saída (`data/saida.txt`):

```
1
0
1
1
1
0
```

Além disso, o programa imprime o resultado no terminal.

---

## ⚙️ Funcionamento do Algoritmo

1. **Normalização:**
	- Remove acentos, cedilha, espaços e pontuação.
	- Converte para minúsculo.
2. **Construção da lista:**
	- Cada caractere normalizado é inserido em uma lista duplamente encadeada.
3. **Verificação de palíndromo:**
	- O algoritmo compara os caracteres do início e do fim da lista, avançando para o centro.
	- Complexidade: O(n/2) para cada expressão.

---

## 👨‍💻 Autores

- Carlos Eduardo Pereira dos Santos
- Marcos Felipe dos Reis Bento
- Guilherme de Oliveira Aredes

