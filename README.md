# Get_Next_Line

## Description / Descrição
This project involves programming a function in C that returns a line read from a file descriptor. The primary functionality is the ability to read and extract lines from a file, facilitating data manipulation in a programming context.

Este projeto envolve programar uma função em C que retorna uma linha lida de um descritor de arquivo. A funcionalidade principal é a capacidade de ler e extrair linhas de um arquivo, facilitando a manipulação de dados em um contexto de programação.

## Key Features / Principais Características
Line Reading: The developed function is capable of reading a line from the file associated with the provided file descriptor parameter.

Leitura de Linha: A função desenvolvida é capaz de ler uma linha do arquivo associado ao parâmetro fornecido do descritor de arquivo.

## Learned Concepts / Conceitos aprendidos 
During the development of this project, I gained essential programming knowledge, including:
Static Variable: I employed concepts of static variables to preserve state between successive calls to the function.
Memory Management: I learned to handle and address memory leaks, ensuring efficient execution without resource wastage.
Linked List: I developed the function using a linked list structure, demonstrating the practical application of this data structure.

Durante o desenvolvimento deste projeto, adquiri conhecimentos essenciais de programação, incluindo:
Variável Estática: Utilizei conceitos de variáveis estáticas para preservar o estado entre chamadas sucessivas à função.
Gerenciamento de Memória: Aprendi a lidar e corrigir vazamentos de memória, garantindo uma execução eficiente sem desperdício de recursos.
Lista Encadeada: Desenvolvi a função utilizando uma estrutura de lista encadeada, demonstrando a aplicação prática dessa estrutura de dados.

## Main
To test, add the following code to the get_next_line.c file:

Para testar, adicione o seguinte comando no arquivo "get_next_line.c":

```c
int    main(void)
{
    int        fd;
    char    *str;

    fd = open("teste.txt", O_RDONLY);
    while ((str = get_next_line(fd)) != NULL)
    {
        printf("%s", str);
        free(str);
    }
    close (fd);
    return (0);
}
```
- **Obs:** you need to edit the file 'teste.txt' containing what you want get_next_line to read.
- **Obs:** você precisa editar o arquivo 'teste.txt' com o que você quer que a get_next_line leia.
  
## Compilation
After adding the main() to the .c file and saving, type the following command in the terminal:

Após adicionar o main() no arquivo .c e salvar, digite o seguinte comando no terminal:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c && ./a.out

- **Obs:** -D BUFFER_SIZE=42 -> define how many bytes will get_next_line read per iteration
