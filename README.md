# Missão Espacial — Sistema de Monitoramento em C

## Descrição

Sistema desenvolvido em linguagem C para simular o monitoramento de uma missão espacial, acompanhando informações importantes como temperatura da nave, nível de bateria e status da comunicação. O programa registra até 10 leituras no histórico e emite alertas automáticos sempre que alguma situação de risco é identificada, ajudando no controle e segurança da missão.

---

## Estrutura do Projeto

```
missao_espacial.c   → Código-fonte principal
README.md           → Este arquivo
fluxograma.pdf      → Fluxograma do sistema
```

---

## Organização do Código

O código é dividido em **6 funções**, cada uma com responsabilidade única:

| Função | Responsabilidade |
|---|---|
| `menu()` | Exibe o menu principal e lê a opção do usuário |
| `dados()` | Coleta uma nova leitura de sensores e valida as entradas |
| `visu_dados()` | Exibe os dados da leitura mais recente |
| `analise()` | Analisa a leitura mais recente e classifica o status de cada sensor |
| `historico()` | Exibe uma tabela com todas as leituras registradas |
| `main()` | Loop principal do sistema via `do-while` e `switch` |

---

## Variáveis Globais

```c
int OP;            // Opção escolhida no menu
int total;         // Contador de leituras registradas (índice atual)
float temp[10];    // Vetor de temperaturas (°C)
float bater[10];   // Vetor de níveis de bateria (%)
char comu[10];     // Vetor de status de comunicação ('S' ou 'N')
```

O uso de **vetores** permite armazenar o histórico de até 10 leituras. A variável `total` funciona tanto como contador quanto como índice para a próxima posição disponível nos vetores.

---

## Lógica das Funções

### `menu()`
Imprime as 5 opções disponíveis e lê a escolha do usuário com `scanf`. O controle de fluxo é feito no `main()` via `switch(OP)`.

### `dados()`
1. Lê a temperatura e armazena em `temp[total]`
2. Emite alerta imediato se `temp > 80` (superaquecimento) ou `temp <= 10` (congelamento)
3. Lê o nível de bateria em `bater[total]`
4. Valida com `while`: rejeita valores `<= 0` ou `> 100`
5. Emite aviso de economia de energia se `bater < 20`
6. Lê o status de comunicação em `comu[total]`
7. Valida com `while`: aceita apenas `'S'`, `'s'`, `'N'` ou `'n'`
8. Emite alerta de falha se comunicação for `'N'`
9. Incrementa `total` para registrar a leitura

### `visu_dados()`
- Verifica se `total == 0` e avisa se não há leituras
- Exibe os valores de `temp[total-1]`, `bater[total-1]` e `comu[total-1]` (última leitura)

### `analise()`
Classifica cada sensor da última leitura em três níveis:

| Sensor | Condição | Status |
|---|---|---|
| Temperatura | `> 80` ou `<= 10` | CRÍTICO |
| Temperatura | entre 10 e 80 | OK |
| Bateria | `< 10%` | CRÍTICO |
| Bateria | entre 10% e 20% | RUIM |
| Bateria | `>= 20%` | OK |
| Comunicação | `'N'` | CRÍTICO |
| Comunicação | `'S'` | OK |

### `historico()`
Percorre os vetores com um laço `for (int i = 0; i < total; i++)` e imprime uma tabela formatada com todas as leituras registradas, mostrando número da leitura, temperatura, bateria e status da comunicação.

### `main()`
```
do {
    menu()
    switch(OP) {
        case 1 → dados()
        case 2 → visu_dados()
        case 3 → analise()
        case 4 → historico()
        case 5 → encerrar
    }
} while (OP != 5)
```
O loop `do-while` garante que o menu seja exibido pelo menos uma vez antes da verificação de saída.

---

## Regras de Alerta

```
Temperatura > 80°C      →  ALERTA: SUPERAQUECIMENTO
Temperatura <= 10°C     →  ALERTA: CONGELAMENTO
Bateria < 20%           →  Modo economia de energia
Bateria < 10%           →  CRÍTICO — carregar imediatamente
Comunicação = N         →  FALHA — reiniciar sistema
```

---

## Estruturas de Linguagem C Utilizadas

- **Vetores** — `float temp[10]`, `float bater[10]`, `char comu[10]`
- **Estrutura condicional** — `if / else if / else`
- **Repetição com validação** — `while` para entradas inválidas
- **Loop principal** — `do-while`
- **Seleção de menu** — `switch / case`
- **Funções** — separação de responsabilidades em 5 funções + `main`
- **Formatação de saída** — `printf` com `%.2f`, `%-8s`, `%%`

---

## Como Compilar e Executar

```bash
# Compilar (GCC)
gcc missao_espacial.c -o missao_espacial

# Executar (Windows)
missao_espacial.exe

# Executar (Linux/Mac)
./missao_espacial
```

> **Atenção:** as chamadas `system("pause")` e `system("cls")` funcionam apenas no Windows. Em Linux/Mac, substitua por `getchar()` e `system("clear")` respectivamente.

---
