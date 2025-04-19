---

## 🧠 Parte 1 – Questões de Interpretação (responda no arquivo `respostas.md`)

1. O que a função `calcular_valor_total(Carro *carro)` deve fazer? R - Deve calcular o valor total que o usuario vai precisar pagar por estacionar o carro.
2. Explique a lógica de aprovação na função `aprovar_reprovar_carro(Usuario *usuario, Carro *carro)`. R - Primeiro essa função vai chamar a calcular_valor_total() e depois verificar o saldo disponível do usuario para saber se ele tem saldo suficiente para pagar o estacionamento.
3. O que acontece se um usuário tenta registrar um carro com valor superior ao seu saldo? R - Retorna um erro falando "Saldo insuficiente para pagar o estacionamento!"
4. Como o sistema armazena todos os carros registrados por um usuário? R - Usando alocação dinâmica para realocar novos carros no sistema.
5. Para que serve a função `realocar_memoria_usuario`, e por que ela é necessária? R - Quando precisa adicionar um novo usariario no sistema é preciso realocar a memoria e aumentar o tamanho para poder adicionar novos usuarios.
6. Qual o papel de `adicionar_carro_historico`, e por que ela depende de outra função? R - Serve para ter o controle de carros que entrou e saiu do estacionamento. Ela depende da função realocar_memoria_carro() para poder adicionar um novo carro no historico.
7. O que a função `solicitar_nova_entrada` deve fazer do início ao fim? R - Deve verificar se o usuario existe no sistema, pede as informações do carro, placa e horario, para poder calcular o valor total a ser pago pelo usuario pelo uso do estacionamento e adiciona o carro no historico.

---