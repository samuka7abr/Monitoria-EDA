# 📘 Atividade 1 – Passagem por Referência

Esta atividade tem como objetivo reforçar o uso de **ponteiros em funções**, explorando o conceito de **passagem por referência** em C.

---

## ✅ Questão 1 – Interpretação de Código

**Enunciado:**  
Observe o código abaixo e diga o que será impresso quando ele for executado.

```c
#include <stdio.h>

void dobra(int *n) {
    *n = *n * 2;
}

int main() {
    int x = 4;
    dobra(&x);
    printf("%d\n", x);
    return 0;
}
```

**a)** 4  
**b)** 8  
**c)** erro de compilação  
**d)** endereço de memória

> 📌 Justifique sua resposta com um comentário no código.

---

## ✅ Questão 2 – Correção de Código

**Enunciado:**  
O código abaixo tem o objetivo de trocar os valores de duas variáveis usando uma função.  
Corrija o código para que funcione corretamente **utilizando passagem por referência**.

```c
#include <stdio.h>

void trocar(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    trocar(x, y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
```

---

## ✅ Questão 3 – Atualização de Notas

**Enunciado:**  
Crie uma função chamada `atualizaNotas` que recebe **3 ponteiros para `float`**: `nota1`, `nota2`, `nota3`.  
A função deve **somar 1.0 ponto de bônus** a cada nota.

No `main`, declare 3 variáveis `float`, chame a função e imprima os valores atualizados.

### 🧠 Exemplo:
```c
float n1 = 7.5, n2 = 6.0, n3 = 8.0;
atualizaNotas(&n1, &n2, &n3);
// resultado esperado: 8.5, 7.0, 9.0
```

---

## ✅ Questão 4 – Deslocar Valor

**Enunciado:**  
Escreva uma função chamada `deslocar` que receba **dois ponteiros para `int`**.  
Ela deve colocar o valor do segundo inteiro dentro do primeiro, e zerar o valor do segundo.

### 🧠 Exemplo:
```c
int a = 10, b = 7;
deslocar(&a, &b);
// resultado esperado: a = 7, b = 0
```

---

## ✅ Questão 5 – Média com Ponteiro de Retorno

**Enunciado:**  
Crie uma função chamada `media` que receba dois `float` por valor e **um ponteiro para `float`** chamado `resultado`.  
A função deve calcular a média aritmética entre os dois valores e armazenar o valor no endereço apontado por `resultado`.

### 🧠 Exemplo:
```c
float resultado;
media(8.5, 7.5, &resultado);
// resultado esperado: 8.0
```