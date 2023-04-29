#include <stdio.h>
#include <stdlib.h>

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
int setWordCount(int arraySize)
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

int main()
{
    int arraySize = setArraySize();
    int wordCount = setWordCount(arraySize);

    return 0;
}