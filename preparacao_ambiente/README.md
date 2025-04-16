# 🐧 Configuração do Ambiente WSL + Ubuntu + VSCode

Este guia tem como objetivo ajudar você a configurar um ambiente completo de desenvolvimento com **WSL2**, **Ubuntu 24.04** e **Visual Studio Code**, diretamente no seu Windows.

---

## ✅ Etapa 1 — Instalação do WSL2 + Ubuntu 24.04

### 1. Baixe o script de instalação:

📥 Link:  
https://gist.github.com/j3r3mias/69ae94a57fd0663d4aa353684306324c

### 2. Libere a execução de scripts no PowerShell (caso necessário):

Abra o PowerShell como administrador e execute:

```powershell
powershell -executionpolicy bypass -File .\script-instala-atualiza-wsl.ps1
```

### 3. Finalize a instalação

Se tudo der certo, o Ubuntu 24.04 estará instalado no seu sistema. Ele aparecerá como um programa comum no menu iniciar.

Abra o Ubuntu e siga as instruções para **criar seu nome de usuário e senha**.  
⚠️ **Guarde essa senha!** Ela será usada sempre que precisar instalar pacotes.

---

## ✅ Etapa 2 — Atualização do Ubuntu

Com o Ubuntu aberto, atualize a lista de pacotes:

```bash
sudo apt update
```

---

## ✅ Etapa 3 — Instalação das ferramentas de desenvolvimento

### 1. Baixe o script de configuração:

📥 Link:  
https://gist.github.com/j3r3mias/70c98521aa74769bf1a41c611a72b8a6

### 2. Dê permissão de execução e rode o script:

```bash
chmod +x script-instalacao-dell-2025.sh
./script-instalacao-dell-2025.sh
```

Pronto! Seu ambiente estará configurado com todos os compiladores e ferramentas.

---

## 📁 Etapa 4 — Criando um diretório para seus códigos

1. Acesse seu diretório pessoal:

```bash
cd ~
```

2. Crie uma pasta para seus códigos da disciplina:

```bash
mkdir Estrutura_de_dados
```

3. Verifique se ela foi criada:

```bash
ls
```

Você verá a pasta `Estrutura_de_dados` listada.

---

## 🧠 Dica de terminal

- Use `pwd` para saber onde você está
- Use `ls -lha` para listar arquivos com detalhes

---

## 🖥️ Etapa 5 — Configurando o Visual Studio Code

### 1. Instale a extensão **Remote - WSL**:

📥 Link direto:  
https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-wsl

Ou pesquise por “WSL” no próprio VSCode (Ctrl+Shift+X).

### 2. Conecte ao WSL:

- Clique no ícone `><` no canto inferior esquerdo
- Selecione **"New WSL Window"**
- O canto inferior esquerdo mostrará `WSL: Ubuntu-24.04`

### 3. Escolha o diretório de trabalho:

Clique em **"Abrir Diretório"** e selecione:  
```bash
/home/<seu_usuario>/Estrutura_de_dados
```

---

## ✅ Testando os compiladores

Abra um terminal novo no VSCode (Ctrl+Shift+`) e execute:

```bash
gcc --version
g++ --version
python --version
java --version
```

Se tudo estiver certo, ele mostrará as versões instaladas.

---

## 🚀 Compilando um arquivo C

Crie um arquivo chamado `exemplo.c` e salve no seu diretório.

No terminal, compile com:

```bash
gcc exemplo.c -o programa
./programa
```

---

Agora seu ambiente está pronto para programar em C, C++, Python e Java!  
Se tiver dúvidas, fale com a monitoria! 💻🐧

