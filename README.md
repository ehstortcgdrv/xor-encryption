# xor-encryption

Uma **implementação básica** de criptografia de strings em tempo de compilação.

## Sobre o Projeto
Este projeto demonstra o funcionamento prático de ofuscação e criptografia de strings em tempo de compilação, impedindo que textos confidenciais fiquem expostos em texto plano nas seções de dados do binário.

## Demonstração
Abaixo, a comparação mostrando o comportamento da string comum versus a string protegida com a macro `xorstr_` ao analisar o executável:

![Demonstração do XOR](assets/animation.gif)

## Como a descriptografia funciona em tempo de execução?
Para que o software cumpra sua função, a string protegida precisa ser decifrada durante a execução:

1. **Proteção Estática (Disco):** O binário compilado armazena apenas os bytes embaralhados e a chave gerada por hash. Nenhuma ferramenta de análise consegue ler a string em texto plano.
2. **Decifração Dinâmica (Memória):** No momento em que o código é executado, a rotina reconstrói a string original temporariamente na memória RAM.
