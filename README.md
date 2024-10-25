# Compiladores

## Ambiente de Desenvolvimento

Os labs foram desenvolvidos utilizando o WSL (Windows Subsystem for Linux) com a distribuição Ubuntu. Isso é importante pois o teste de vazamento de memória com o Valgrind é possível apenas em distribuições Linux.

## Descrevendo os Laboratórios

### Lab 1: Relembrando Arquivos

#### Objetivos
- Relembrando como trabalhar com arquivos.
- Alocação e desalocação de memória.
- Bufferização de arquivos.

### Lab 2: Buffer em Blocos

#### Objetivos
- Implementar um buffer em blocos.
- Praticar alocação e desalocação de memória.
- Praticar leitura de arquivos.

### Instruções

- Para maiores instruções de cada Lab, consulte o arquivo `INSTRUCTIONS` de cada projeto.

## Valgrind
### Como Rodar o Valgrind

Para realizar um teste de vazamento de memória utilizando o Valgrind, siga os passos abaixo:

1. Instalando o Valgrind:
    ```
    pip install valgrind
    ```

2. Compile seu programa com as opções de depuração ativadas:
    ```sh
    gcc -g -o meu_programa meu_programa.c
    ```

3. Execute o Valgrind com o seu programa:
    ```sh
    valgrind --leak-check=full ./meu_programa
    ```

4. Analise a saída do Valgrind para identificar possíveis vazamentos de memória.

Para mais informações sobre o Valgrind, consulte a [documentação oficial](http://valgrind.org/docs/manual/manual.html).

## Autores
- [Gabriel Almeida](https://github.com.br/garpereira)

## Licença
Este projeto está licenciado sob a Licença MIT. Veja o arquivo `LICENSE` para mais detalhes.
