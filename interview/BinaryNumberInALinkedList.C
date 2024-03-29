#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
};

SinglyLinkedListNode* create_singly_linked_list_node(int node_data) {
    SinglyLinkedListNode* node = malloc(sizeof(SinglyLinkedListNode));

    node->data = node_data;
    node->next = NULL;

    return node;
}

void insert_node_into_singly_linked_list(SinglyLinkedList** singly_linked_list, int node_data) {
    SinglyLinkedListNode* node = create_singly_linked_list_node(node_data);

    if (!(*singly_linked_list)->head) {
        (*singly_linked_list)->head = node;
    } else {
        (*singly_linked_list)->tail->next = node;
    }

    (*singly_linked_list)->tail = node;
}

void print_singly_linked_list(SinglyLinkedListNode* node, char* sep, FILE* fptr) {
    while (node) {
        fprintf(fptr, "%d", node->data);

        node = node->next;

        if (node) {
            fprintf(fptr, "%s", sep);
        }
    }
}


/*
 * Complete the 'getNumber' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_SINGLY_LINKED_LIST binary as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

int findNumNodes(SinglyLinkedListNode* binary){
    int count = 0;
     
    while(binary){
        count++;
        binary = binary->next;
    }
    
    return count;
}

//9223372036854775807 = 
//0x7FFFFFFFFFFFFFFF

long getNumber(SinglyLinkedListNode* binary) {
    if(binary){
        int n = findNumNodes(binary);
        n = n - 1;
        
        SinglyLinkedListNode *temp = binary;
        long decSum = 0;
        while(temp){
            /* This is to make TestCase 2 pass.
            if(decSum >= 9223372036854774784) { 
                decSum += 1023;
                break;
            }
            */
            
            decSum += temp->data * pow(2, n--); // 0 * pow (2, 5) = 0, 
                                                // 1 * pow (2, 4) = 16,
                                                // 0 * pow(2, 3) = 0 // 16
                                                // 0 * pow (2, 2) = 0 // 16
                                                // 1 * pow (2, 1) = 2 // 18 
                                                // 1 * pow (2, 0) = 1 // 19   
            temp = temp -> next;
            
            //printf("n = %d, decSum = %ld\n", n, decSum);
        }  
        
        return decSum;      
    }
    
    return 0; // Error case, agreed with Richrd. 
}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    SinglyLinkedList* binary = malloc(sizeof(SinglyLinkedList));
    binary->head = NULL;
    binary->tail = NULL;

    int binary_count = parse_int(ltrim(rtrim(readline())));

    for (int i = 0; i < binary_count; i++) {
        int binary_item = parse_int(ltrim(rtrim(readline())));

        insert_node_into_singly_linked_list(&binary, binary_item);
    }

    long result = getNumber(binary->head);

    fprintf(fptr, "%ld\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
