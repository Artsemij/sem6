#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    
    // Ввод данных
    printf("Введите данные: ");
    fgets(input, MAX_SIZE, stdin);
    
    // Удаление элементов с нечетным порядковым номером
    int input_length = 0;
    int output_length = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (i % 2 == 0) {
            output[output_length] = input[i];
            output_length++;
        }
        input_length++;
    }
    output[output_length] = '\0'; // Добавляем завершающий нуль-символ
    
    // Вывод данных
    printf("Данные на входе: %s\n", input);
    printf("Данные на выходе: %s\n", output);
    
    return 0;
}