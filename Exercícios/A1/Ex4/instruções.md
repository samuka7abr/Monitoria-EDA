# 🚗 Atividade – Sistema de Estacionamento

Nesta atividade, você vai praticar **leitura de código, interpretação de lógica e implementação de funções** a partir de uma base já estruturada.

O sistema simula o controle de entrada de carros em um estacionamento. Cada **usuário** tem um saldo disponível, e pode registrar **carros** com quantidade de horas de permanência. O sistema calcula o valor total e decide se a entrada é **aprovada** ou **reprovada**, com base no saldo do usuário.

---

## 📂 Estrutura da entrega

Sua entrega deve conter **os seguintes arquivos obrigatórios**:

```
├─📁 entregas
    📁 <Seu_nome>/
    ├── main.c
    ├── utils.c
    ├── utils.h
    └── respostas.md  ← suas respostas das questões abertas
```

---

## 🎯 Objetivo

- Interpretar um sistema pronto em C
- Compreender a lógica de structs, funções e realocação de memória
- Implementar **apenas as funções principais**
- Praticar o raciocínio lógico de um sistema modular

---

## 🧠 Parte 1 – Questões de Interpretação (responda no arquivo `respostas.md`)

1. O que a função `calcular_valor_total(Carro *carro)` deve fazer?
2. Explique a lógica de aprovação na função `aprovar_reprovar_carro(Usuario *usuario, Carro *carro)`.
3. O que acontece se um usuário tenta registrar um carro com valor superior ao seu saldo?
4. Como o sistema armazena todos os carros registrados por um usuário?
5. Para que serve a função `realocar_memoria_usuario`, e por que ela é necessária?
6. Qual o papel de `adicionar_carro_historico`, e por que ela depende de outra função?
7. O que a função `solicitar_nova_entrada` deve fazer do início ao fim?

---

## 🛠️ Parte 2 – Funções a implementar (em `utils.c`)

Você deverá completar **apenas as seguintes funções**:

```c
Usuario *realocar_memoria_usuario(Usuario *usuarios, int novo_tamanho);
Carro *realocar_memoria_carro(Carro *carros, int novo_tamanho);
void calcular_valor_total(Carro *carro);
void aprovar_reprovar_carro(Usuario *usuario, Carro *carro);
void solicitar_nova_entrada(Usuario *usuarios, int num_usuarios);
```

> 💡 Dica: o comportamento esperado dessas funções é quase idêntico ao da atividade anterior do sistema de empréstimos.

---

## ✅ Dicas Gerais

- Leia o código com atenção antes de começar a implementar
- Se necessário, execute o programa e observe o comportamento atual
- As funções que você precisa fazer estão **comentadas como TODO** no `utils.c`
- O `main.c` já está pronto e funcionando
- Use `gcc main.c utils.c -o estacionamento` para compilar

---

## 📆 Entrega

- Data limite: **22/04//2025** (mas recomendo fazer antes da prova do dia 17/04, pois é revisão)
- Envie sua pasta com todos os arquivos por GitHub ou outro canal indicado
- **Não altere os nomes dos arquivos**

---

Em caso de dúvida, entre em contato pela monitoria no Discord.
