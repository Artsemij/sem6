#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    char* word;
    struct list* next;
};

// ��������� ����� ����� � ����� ������
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

// ������ ������� ��� ����� � ������
void swap_elements(struct list* node1, struct list* node2) {
    char* temp = node1->word;
    node1->word = node2->word;
    node2->word = temp;
}

// ������� ��� ����� � ������
void print_list(struct list* head) {
    struct list* current = head;
    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}

// ������� ��� ���� � ������
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
    char str[] = "efg abcd zzz.";
    char* token = strtok(str, " ");
    struct list* head = NULL;

    while (token != NULL) {
        add_to_list(&head, token);
        token = strtok(NULL, " ");
    }

    printf("������ �����: ");
    struct list* first_word = head;
    print_list(first_word);

    printf("��������� �����: ");
    struct list* last_word = NULL;
    struct list* current = head;
    while (current != NULL) {
        last_word = current;
        current = current->next;
    }
    print_list(last_word);

    delete_list(&head);

    return 0;
}