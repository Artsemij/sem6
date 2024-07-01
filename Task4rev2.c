/*удаляет все нечётные элементы*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    char* word;
    struct list* next;
};

// Добавляет новое слово в конец списка
void add_to_list(struct list** head, char* word) {
    struct list* new_node = (struct list*)malloc(sizeof(struct list));
    new_node->word = word;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    }
    else {
        struct list* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Выводит все слова в списке
void print_list(struct list* head) {
    struct list* current = head;
    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}

// Удаляет все узлы в списке
void delete_list(struct list** head) {
    struct list* current = *head;
    while (current != NULL) {
        struct list* next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    char str[] = "aa ss dd ff gg hh jj kk ll.";
    char* token = strtok(str, " ");
    struct list* head = NULL;

    while (token != NULL) {
        add_to_list(&head, token);
        token = strtok(NULL, " ");
    }

    struct list* current = head;
    while (current != NULL) {
        if (current->next != NULL && (current->next->word[0] - current->word[0]) % 2 != 0) {
            printf("%s ", current->word);
        }
        current = current->next;
    }
    printf("\n");

    delete_list(&head);

    return 0;
}