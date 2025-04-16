# 🧠 Guia Básico: Como Navegar no Linux e Rodar Programas em C com `gcc`

---

## 📁 Navegação de Diretórios no Linux

### 👉 Comando `pwd`

Mostra em qual pasta você está:

```bash
pwd
```

---

### 👉 Comando `ls`

Lista o que tem na pasta atual:

```bash
ls
```

Para ver mais informações (como permissões, tamanho, datas):

```bash
ls -lha
```

---

### 👉 Comando `cd`

Serve para **entrar em uma pasta**:

```bash
cd nome_da_pasta
```

Para **voltar uma pasta**:

```bash
cd ..
```

Para **voltar direto para sua pasta pessoal**:

```bash
cd ~
```

---

### 👉 Criar uma nova pasta

```bash
mkdir nome_da_pasta
```

---

## 💻 Rodando Programas em C com `gcc`

---

### ✅ 1. Crie um arquivo `.c`

Por exemplo: `ola.c`

```c
#include <stdio.h>

int main() {
    printf("Olá, mundo!\n");
    return 0;
}
```

---

### ✅ 2. Compile com `gcc`

Abra o terminal, vá até a pasta onde o arquivo está salvo e rode:

```bash
gcc ola.c -o programa
```

> Isso vai gerar um arquivo executável chamado `programa`.

---

### ✅ 3. Rode o programa

```bash
./programa
```

Se tudo estiver certo, a saída será:

```
Olá, mundo!
```

---

## 🧪 Dica: Verifique se o `gcc` está instalado

```bash
gcc --version
```

Se mostrar a versão, está tudo certo!

---

Se tiver dúvidas ou erros, entre em contato com a monitoria.
Bons estudos e bora codar! 💪
