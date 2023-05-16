#include <stdio.h>
#include <stdlib.h>

void clean()
{
    system("cls");
    ////system("clear");
}

// Funciones secundarias
void showMessageError(int errorCode)
{
    clean();
    if (errorCode == 1)
        printf("Error: La dimension debe ser mayor o igual que 10\n");
    if (errorCode == 2)
        printf("Error: La dimension debe ser menor o igual que 35\n");
}
// Funciones principales
int requestSizeArray()
{
    int n;
    do
    {
        printf("Dimension de la sopa de letras: ");
        scanf("%d", &n);
        if (n < 10)
            showMessageError(1);
        if (n > 35)
            showMessageError(2);
    } while (n < 10 || n > 35);
    return n;
}
int requestWordCount(int n)
{
    int k;
    do
    {
        printf("Cantidad de palabras: ");
        scanf("%d", &k);
        if (k < (n / 2))
        {
            clean();
            printf("Error: La cantidad de palabras debe ser mayor o igual que %d.\n", (n / 2));
        }
        if (k > (2 * n))
        {
            clean();
            printf("Error: La cantidad de palabras debe ser menor o igual que %d.\n", (n * 2));
        }
    } while (k < (n / 2) || k > (2 * n));
    return k;
}
void clearAlphabetSoup(int size, char alphabetSoup[size][size])
{
    int i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            alphabetSoup[i][j] = '#';
}
void displayAlphabetSoup(int size, char alphabetSoup[size][size])
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            printf("[%c]", alphabetSoup[i][j]);
        printf("\n");
    }
}

int main()
{
    int sizeArray = requestSizeArray();
    int wordCount = requestWordCount(sizeArray);
    char alphabetSoup[sizeArray][sizeArray];
    clearAlphabetSoup(sizeArray, alphabetSoup);
    displayAlphabetSoup(sizeArray, alphabetSoup);
    return 0;
}