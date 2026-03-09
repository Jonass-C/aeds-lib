# 🧩 aeds-lib

Repositório pessoal para estudo de conceitos e algoritmos aprendidos nas disciplinas de **Algoritmos e Estruturas de Dados I e II**, servindo como uma biblioteca modular.

- **⚠️ Observação:** A lógica, em algumas funções, foi adaptada para que eu tivesse um melhor entendimento.

## 🗂️ Implementações

- **Estruturas de Dados**
  - Listas
  - Pilhas
  - Filas
  - Árvores
  - Tabela Hash

- **Algoritmos**
  - Ordenação
  - Pesquisa
  - Casamento de padrões

## ️⚙️ Compilação

- O projeto foi configurado com CMake. 
- Cada módulo possui seu próprio diretório e executável, disponível no arquivo `CMakeLists.txt`

### 🐧 Ambiente Linux
O projeto pode ser compilado em ambientes Linux utilizando o `gcc`.
```bash
mkdir build && cd build
cmake ..
make
```

### 🪟 Ambiente Windows e MSVC
- O projeto é plenamente compatível com Windows através do **MinGW** ou **Cygwin**.
- 🚨 O **MSVC** (Visual Studio) pode gerar erros de compilação em algumas partes, como a utilização de **vetores de tamanho variável (VLA)** na função `inverterFila`.

---
