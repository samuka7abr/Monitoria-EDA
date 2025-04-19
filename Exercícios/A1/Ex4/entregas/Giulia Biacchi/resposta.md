
#  Respostas


1- ***O que a função calcular_valor_total(Carro *carro) deve fazer?***

R: Tem como objetivo calcular o valor a ser cobrado pelo uso de um carro com base na quantidade de horas utilizadas. Ela faz isso multiplicando o número de horas pela constante TAXA_POR_HORA, armazenando o resultado no campo valor_total da estrtura Carro.

2- ***Explique a lógica de aprovação na função aprovar_reprovar_carro(Usuario *usuario, Carro *carro)***

R: 1- calcula o valor total da entrada do carro utilizando a função calcular_valor_total.
2- Verifica se o saldo do usuario é suficiente, o carro é aprovado e ativado, depois o valor é debitado do saldo usuário. Caso contrario, o carro é reprovado e não é ativado, e neum valor é cobrado.

3- ***O que acontece se um usuário tenta registrar um carro com valor superior ao seu saldo?***

R: Se o valor total da entrada do carro for superior ao saldo disponivel do usuario, a função aprovar_reprovar_carro marca o carro como reprovado e inativo. Nenhum valor é cobrado e mesmo assim, o registro do carro é mantido no historico do usuario.

4- ***Como o sistema armazena todos os carros registrados por um usuário?***

R: Cada usuario possui um vetor dinamico de estrturas Carro, reperesentado pelo ponteiro historico_carros, alem de num_carros que indica quantos carros estão registrados. Sempre que um carro é inserido, a memoria é realocada com a função realocar_memoria_carro, o novo carro é adicionado na proxima posição disponivel, e o contador num_carros é incrementado.

5- ***Para que serve a função realocar_memoria_usuario, e por que ela é necessária?***

R: Serve para redimencionar dinamicamente o vetor de usuarios em tempo de execução, utilizando a função realloc. Ela é necessaria, pois vetores nao crescem automaticamente. Portanto, sempre há adição ou remoção de usuários, é preciso alocar novamente a memória para refletir o novo tamanho do vetor, garantindo o correto armazenamento dos dados.

6- ***Qual o papel de adicionar_carro_historico, e por que ela depende de outra função?***

R: A função insere um novo carro no histórico do usuário, realocando dinamicamente o vetor historico_carros para garantir espaço e, em seguida, atualizando o campo num_carros. A realocação evita acessos inválidos à memória.

7- ***O que a função solicitar_nova_entrada deve fazer do início ao fim?***

R:  função solicitar_nova_entrada permite que um usuário registre um novo carro no sistema. Ela solicita o ID do usuário e, após localizá-lo, coleta os dados da placa e das horas de uso. Com essas informações, cria uma estrutura Carro, calcula o valor da entrada e verifica se ela será aprovada com base no saldo disponível. Em seguida, adiciona o carro ao histórico do usuário e informa o resultado da solicitação.