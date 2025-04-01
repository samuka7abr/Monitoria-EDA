# 📘 Lista de Atividades 2 – Ponteiros em C

Essa atividade tem como objetivo consolidar os conceitos de **ponteiros em C**, aplicando passagem por referência, manipulação de memória e interação com vetores.

📌 **Total de questões:** 5  
📆 **Prazo de entrega:** até **terça-feira, 23h59**  
📂 **Entrega:** via PR no repositório, seguindo a estrutura `Ex2/entregas/seu_nome/`.

---

## ✅ Questão 1 – Identificando Endereços

**Enunciado:**  
Declare uma variável `int x = 42` e um ponteiro `p`.  
Atribua a `p` o endereço de `x` e imprima:
- O valor de `x`
- O endereço de `x` com `&x`
- O valor armazenado em `p`
- O conteúdo de `p` com `*p`

🎯 **Objetivo:** entender ponteiro básico e o operador de desreferência.

---

## ✅ Questão 2 – Soma com Ponteiros

**Enunciado:**  
Crie uma função `soma(int *a, int *b, int *resultado)` que recebe dois inteiros por referência e armazena a soma no ponteiro `resultado`.

🎯 **Objetivo:** exercitar função com saída por ponteiro.

---

## ✅ Questão 3 – Troca de Valores

**Enunciado:**  
Implemente uma função `trocar(int *a, int *b)` que troque os valores de duas variáveis.  
Mostre os valores antes e depois da troca no `main`.

🎯 **Objetivo:** reforçar manipulação de valores por ponteiro.

---

## ✅ Questão 4 – Verificação de Inicialização

**Enunciado:**  
Escreva uma função `verificar(int *ptr)` que:
- Testa se o ponteiro é `NULL`
- Se não for, dobra o valor apontado

No `main`, chame a função com:
- Um ponteiro nulo
- Um ponteiro para variável inicializada

🎯 **Objetivo:** ensinar boas práticas com ponteiros (verificação de nulidade).

---

## ✅ Questão 5 – Vetor e Ponteiro

**Enunciado:**  
Crie um vetor de 5 inteiros e uma função `modificar(int *v, int tamanho)` que multiplica cada valor por 2, usando ponteiros.

🎯 **Objetivo:** aplicar aritmética de ponteiros com vetores.

---

## 📂 Entrega

Crie uma pasta com seu nome completo ou usuário GitHub, dentro de:

```
Ex2/
└── entregas/
    └── seu_nome/
        ├── q1.c
        ├── q2.c
        ├── q3.c
        ├── q4.c
        └── q5.c
```

✍️ Não esqueça de comentar seus códigos sempre que possível!

---

Dúvidas? Pergunta no Discord da monitoria.  
Bons estudos! 👊
