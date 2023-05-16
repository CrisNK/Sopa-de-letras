#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clean()
{
    ////system("cls");
    system("clear");
}

// Funciones secundarias
void showMessageError(int errorCode, int aux)
{
    clean();
    if (errorCode == 1)
        printf("Error: La dimension debe ser mayor o igual que 10\n");
    if (errorCode == 2)
        printf("Error: La dimension debe ser menor o igual que 35\n");
    if (errorCode == 3)
        printf("Error: La cantidad de palabras debe ser mayor o igual que %d.\n", (aux / 2));
    if (errorCode == 4)
        printf("Error: La cantidad de palabras debe ser menor o igual que %d.\n", (aux * 2));
    if (errorCode == 5)
        printf("Error: La longitud de la palabra debe ser menor o igual que %d.\n", aux);
    if (errorCode == 6)
        printf("Error: La longitud de la palabra debe contener al menos 2 caracteres.\n");
}
// Funciones principales
int requestSoupSize()
{
    clean();
    int soupSize;
    do
    {
        printf("Dimension de la sopa de letras: ");
        scanf("%d", &soupSize);
        if (soupSize < 10)
            showMessageError(1, 0);
        if (soupSize > 35)
            showMessageError(2, 0);
    } while (soupSize < 10 || soupSize > 35);
    return soupSize;
}
int requestQuantityWords(int soupSize)
{
    int quantityWords;
    do
    {
        printf("Cantidad de palabras: ");
        scanf("%d", &quantityWords);
        if (quantityWords < (soupSize / 2))
            showMessageError(3, soupSize);
        if (quantityWords > (2 * soupSize))
            showMessageError(4, soupSize);
    } while (quantityWords < (soupSize / 2) || quantityWords > (2 * soupSize));
    return quantityWords;
}
char *requestWord(int soupSize)
{
    int wordLenght;
    char *word = malloc(sizeof(char) * soupSize);
    do
    {
        printf("Ingrese palabra: ");
        scanf("%s", word);
        wordLenght = strlen(word);
        if (wordLenght > soupSize)
            showMessageError(5, soupSize);
        if (wordLenght < 2)
            showMessageError(6, 0);
    } while (wordLenght > soupSize || wordLenght < 2);
    return word;
}

void clearAlphabetSoup(int soupSize, char alphabetSoup[soupSize][soupSize])
{
    int i, j;
    for (i = 0; i < soupSize; i++)
        for (j = 0; j < soupSize; j++)
            alphabetSoup[i][j] = '#';
}
void displayAlphabetSoup(int soupSize, char alphabetSoup[soupSize][soupSize])
{
    int i, j;
    for (i = 0; i < soupSize; i++)
    {
        for (j = 0; j < soupSize; j++)
            printf("[%c]", alphabetSoup[i][j]);
        printf("\n");
    }
}

int main()
{
    int soupSize = requestSoupSize();
    int quantityWords = requestQuantityWords(soupSize);
    int i;
    for (i = 0; i < quantityWords; i++)
    {
        printf("Palabra %d de %d.\n", i + 1, quantityWords);
        char *word = requestWord(soupSize);
    }
    //char alphabetSoup[soupSize][soupSize];
    //clearAlphabetSoup(soupSize, alphabetSoup);
    // displayAlphabetSoup(soupSize, alphabetSoup);
    return 0;
}