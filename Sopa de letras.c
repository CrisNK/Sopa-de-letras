#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define up 1
#define down 2
#define left 3
#define right 4

// Funciones secundarias.
void clean()
{
    // Support for MacOS:
    ////system("clear");

    // Support for Windows:
    system("cls");
}
void pause()
{
    // Support for MacOS:
    ////getchar();
    ////fflush(stdin);
    // Support for Windows:
    system("pause");
}

// Funciones prinicipales.
int setArraySize()
{
    clean();
    int sizeArray;
    do
    {
        printf("Ingrese el tamano de la sopa de letras: ");
        scanf("%d", &sizeArray);
        if (sizeArray < 10)
        {
            clean();
            printf("Error: El tamano de la sopa de letras debe ser mayor o igual que 10.\n");
        }
        if (sizeArray > 35)
        {
            clean();
            printf("Error: El tamano de la sopa de letras debe ser menor o igual que 35.\n");
        }
    } while (sizeArray < 10 || sizeArray > 35);
    return sizeArray;
}
int setNumberOfWords(int arraySize)
{
    clean();
    int wordCount;
    do
    {
        printf("Ingrese la cantidad de palabras a ingresar: ");
        scanf("%d", &wordCount);
        if (wordCount < (arraySize / 2))
        {
            clean();
            printf("Error: La cantidad de palabras ingresadas debe ser mayor o igual que %d.\n", (arraySize / 2));
        }
        if (wordCount > (arraySize * 2))
        {
            clean();
            printf("Error: La cantidad de de palabras ingresadas debe ser menor o igual que %d.\n", (arraySize * 2));
        }

    } while (wordCount < (arraySize / 2) || wordCount > (arraySize * 2));
    return wordCount;
}
char *setWord(int arraySize, int numberOfWords, int i)
{
    char *word = (char *)malloc(arraySize * (sizeof(char)));
    do
    {
        printf("Palabra %d de %d.\n", i + 1, numberOfWords);
        printf("Ingrese palabra: ");
        scanf("%s", word);
        if ((int)strlen(word) < 2)
        {
            clean();
            printf("Error: El tamano de la palabra debe contener al menos 2 caracteres.\n");
        }
        if ((int)strlen(word) > arraySize)
        {
            clean();
            printf("Error: El tamano de la palabra supera el tamano de la sopa de letras.\n");
            printf("Tip: La palabra debe contener un máximo de %d caracteres.\n", arraySize);
        }
    } while ((int)strlen(word) < 2 || (int)strlen(word) > arraySize);
    free(word);
    return word;
}

int main()
{
    srand(time(NULL));
    int arraySize = setArraySize();
    int numberOfWords = setNumberOfWords(arraySize);
    int i;
    for (i = 0; i < arraySize; i++)
    {
        clean();
        char *word = setWord(arraySize, numberOfWords, i);

    }

    return 0;
}