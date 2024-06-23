#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Введите данные: ");
    fgets(input, sizeof(input), stdin);

    char firstWord[50];
    char lastWord[50];
    int i, j, start, end;
  
    // Находим первое слово
    i = 0;
    while (input[i] == ' ')
        i++;
    start = i;
    while (input[i] != ' ' && input[i] != '\0')
        i++;
    end = i;
    strncpy(firstWord, input + start, end - start);
    firstWord[end - start] = '\0';

    // Находим последнее слово
    i = strlen(input) - 2;
    while (input[i] == ' ')
        i--;
    end = i + 1;
    while (input[i] != ' ' && i >= 0)
        i--;
    start = i + 1;
    strncpy(lastWord, input + start, end - start);
    lastWord[end - start] = '\0';

    printf("Данные на входе: %s\n", input);
    printf("Первое слово: %s\n", firstWord);
    printf("Последнее слово: %s\n", lastWord);

    return 0;
}