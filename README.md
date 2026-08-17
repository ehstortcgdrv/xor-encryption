# xor-encryption

Uma **implementação básica** de criptografia de strings em tempo de compilação.

## Sobre o Projeto
Este projeto demonstra o funcionamento prático de ofuscação e criptografia de strings em tempo de compilação, impedindo que textos confidenciais fiquem expostos em texto plano nas seções de dados do binário.

## Demonstração
Abaixo, a comparação mostrando o comportamento da string comum versus a string protegida com a macro `xorstr_` ao analisar o executável:

![Demonstração do XOR](assets/animation.gif)

## Por que a string volta ao normal quando o programa roda?
O programa precisa da informação original para funcionar corretamente. O processo ocorre em duas etapas:

1. **Na Compilação (No Arquivo/Disco):** A string original é transformada em bytes cifrados. Se você abrir o executável em qualquer **editor binário ou ferramenta de análise**, o texto confidencial não estará visível — apenas bytes embaralhados.
2. **Na Execução (Na Memória RAM):** Assim que o programa é iniciado, a macro executa a rotina de descriptografia, recuperando a string original temporariamente na memória RAM para que o seu código possa utilizá-la.
