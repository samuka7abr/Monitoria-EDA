# Respostas - Sistema de Estacionamento

1. **O que a função `calcular_valor_total(Carro *carro)` deve fazer?**  
   A função deve calcular o valor total do estacionamento multiplicando o número de horas (carro->horas) pela taxa por hora (TAXA_POR_HORA = 5.0) e armazenar o resultado em carro->valor_total.

2. **Explique a lógica de aprovação na função `aprovar_reprovar_carro(Usuario *usuario, Carro *carro)`.**  
   A função calcula o valor total chamando calcular_valor_total. Se o valor_total for menor ou igual ao usuario->saldo, marca o carro como aprovado (se for igual a 1), ativo (1) e debita o valor do saldo. Caso contrário, marca como reprovado (aprovado = 0) e não ativo (0).

3. **O que acontece se um usuário tenta registrar um carro com valor superior ao seu saldo?**  
   O carro é reprovado (aprovado = 0, ativo = 0), o saldo não é alterado, e o carro é adicionado ao histórico para registrar a tentativa.

4. **Como o sistema armazena todos os carros registrados por um usuário?**  
   Os carros são armazenados em um array dinâmico historico_carros na struct Usuario. O array é redimensionado por realocar_memoria_carro quando um novo carro é adicionado, e num_carros rastreia a quantidade.

5. **Para que serve a função `realocar_memoria_usuario`, e por que ela é necessária?**  
   A função redimensiona o array de Usuario usando realloc para um novo tamanho. É necessária para permitir a adição de novos usuários dinamicamente, garantindo flexibilidade no tamanho do array.

6. **Qual o papel de `adicionar_carro_historico`, e por que ela depende de outra função?**  
   A função adiciona um carro ao historico_carros de um usuário, realocando o array e incrementando num_carros. Depende de realocar_memoria_carro para aumentar o tamanho do array dinamicamente.

7. **O que a função `solicitar_nova_entrada` deve fazer do início ao fim?**  
   A função pede o ID do usuário, placa e horas; busca o usuário; valida as horas; cria um novo carro; chama aprovar_reprovar_carro para calcular o valor e verificar o saldo; adiciona o carro ao histórico com adicionar_carro_historico, e informa se foi aprovado ou reprovado.