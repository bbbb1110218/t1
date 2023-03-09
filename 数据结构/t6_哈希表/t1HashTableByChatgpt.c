#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000

// 定义哈希表的节点结构
struct Node {
    char *key;
    int value;
    struct Node *next;
};

// 计算字符串的哈希值
unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

// 创建一个新的节点
struct Node *createNode(const char *key, int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->key = (char *) malloc(strlen(key) + 1);
    strcpy(node->key, key);
    node->value = value;
    node->next = NULL;
    return node;
}

// 向哈希表中插入一个键值对
void insert(struct Node **table, const char *key, int value) {
    unsigned long index = hash(key) % TABLE_SIZE;
    struct Node *node = table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    struct Node *newNode = createNode(key, value);
    newNode->next = table[index];
    table[index] = newNode;
}

// 从哈希表中查找一个键对应的值
int lookup(struct Node **table, const char *key) {
    unsigned long index = hash(key) % TABLE_SIZE;
    struct Node *node = table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0)
            return node->value;
        node = node->next;
    }
    return -1;
}

// 销毁哈希表
void destroy(struct Node **table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node *node = table[i];
        while (node != NULL) {
            struct Node *temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
        table[i] = NULL;
    }
}

// 示例用法
int main() {
    struct Node *table[TABLE_SIZE] = {NULL};
    insert(table, "foo", 42);
    insert(table, "bar", 23);
    printf("foo = %d\n", lookup(table, "foo"));
    printf("bar = %d\n", lookup(table, "bar"));
    destroy(table);
    return 0;
}
