# 📘 Lista de Exercícios – Structs, Ponteiros e Alocação Dinâmica

Esta lista foi criada para te ajudar a treinar os conceitos de **structs**, **funções**, **ponteiros** e **alocação dinâmica de memória**, com exercícios objetivos e diretos, ideais para praticar o que você viu nas monitorias e nas atividades maiores da disciplina.

---

## ✅ Exercícios

### 1. Struct simples  
Declare uma struct chamada `Pessoa` com `nome` (char[100]) e `idade` (int).  
No `main`, leia os dados de uma pessoa e imprima-os.

---

### 2. Struct com função  
Crie uma função `imprimir_pessoa` que recebe uma `Pessoa` por valor e imprime seus dados.

---

### 3. Struct com ponteiro  
Altere a função `imprimir_pessoa` para receber um ponteiro para `Pessoa`.

---

### 4. Struct com alocação dinâmica  
Aloque dinamicamente uma struct `Pessoa`, preencha seus dados via `scanf`, e imprima.

---

### 5. Array dinâmico de structs  
Crie um array dinâmico de `Pessoa` com `n` posições. Leia e imprima os dados de todos.

---

### 6. Realloc de structs  
Aumente dinamicamente o vetor anterior em +5 posições usando `realloc`, mantendo os dados já preenchidos.

---

### 7. Cadastro com função de realocação  
Implemente uma função `Pessoa* realocar_pessoas(Pessoa *vetor, int novo_tam)`.

---

### 8. Struct com struct interna  
Crie uma struct `Endereco` e inclua-a dentro de `Pessoa`. Imprima os dados completos da pessoa, incluindo o endereço.

---

### 9. Cálculo com dados da struct  
Crie uma struct `Produto` com `preco` e `quantidade`, e uma função que retorna o total (`preco × quantidade`).

---

### 10. Histórico de compras  
Adicione à struct `Cliente` um array de `Produto`. Leia e imprima os produtos de um cliente.

---

### 11. Empréstimo simples  
Crie uma struct `Emprestimo` com `valor`, `parcelas` e `valor_parcela`.  
Calcule o valor da parcela com juros de 5%.

---

### 12. Aprovação de empréstimo  
Crie uma função `int aprova_emprestimo(float salario, float parcela)` que retorna 1 se a parcela for ≤ 20% do salário, e 0 caso contrário.

---

### 13. Histórico de empréstimos por cliente  
Crie uma struct `Cliente` com `nome`, `salario` e vetor de `Emprestimo`.  
Cadastre 2 empréstimos por cliente e imprima os dados.

---

### 14. Busca por CPF  
Adicione `cpf[15]` à struct `Cliente` e implemente uma função `Cliente* buscar_por_cpf(Cliente *v, int n, char *cpf)` que retorna um ponteiro para o cliente correspondente (ou NULL se não encontrar).

---

### 15. Soma de parcelas ativas  
Implemente uma função que recebe um cliente e retorna a soma das parcelas dos empréstimos que estão marcados como "ativos".

---

