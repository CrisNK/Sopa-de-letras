#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen()
#include <time.h> // rand()
#define up 0, down 1, left 2, right 3, upLeft 4, upRight 5, downLeft 6, downRight 7
#define true 1
#define false 0

struct Word
{
    char *word;
    int X;
    int Y;
    int orientation;
};

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
    int x, y;
    for (y = 0; y < soupSize; y++)
        for (x = 0; x < soupSize; x++)
            alphabetSoup[y][x] = '#';
}
void displayAlphabetSoup(int soupSize, char alphabetSoup[soupSize][soupSize])
{
    int x, y;
    for (y = 0; y < soupSize; y++)
    {
        for (x = 0; x < soupSize; x++)
            printf("[%c]", alphabetSoup[y][x]);
        printf("\n");
    }
}
int calculateSpace(struct Word word)
{
    int lenghtString = strlen(word.word);
    word.
}

int main()
{
    srand(time(NULL));
    int i;
    struct Word word;
    int soupSize = requestSoupSize();
    int quantityWords = requestQuantityWords(soupSize);

    char alphabetSoup[soupSize][soupSize];
    clearAlphabetSoup(soupSize, alphabetSoup);
    for (i = 0; i < down; i++)
    {
        int hasSpace = false;
        clean();
        printf("Palabra %d de %d.\n", i + 1, quantityWords);
        word.word = requestWord(soupSize);
        do
        {
            word.X = rand() % soupSize;
            word.Y = rand() % soupSize;
            word.orientation = rand() % 8;
            hasSpace = calculateSpace(word);
        } while (hasSpace == false);
        // Asignar una dirección aleatoria para la palabra.
        // Verificar de que quepa la palabra en la orientación seleccionada, sino volver a generar una orientación aleatoria
        // Insertar la palabra en la sopa de letras según la orientación generada.
    }
    // displayAlphabetSoup(soupSize, alphabetSoup);
    return 0;
}

// *----------------------------------------------------------------*
// | N° Depósito | N° de Artículo | N° Vendedor | Valor de la venta |
// *----------------------------------------------------------------*
// |       39213 |              2 |       42323 |          $199 990 |
// *----------------------------------------------------------------*







