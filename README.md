#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义图书结构体
typedef struct Book {
    char title[100];
    char author[100];
    int id;
    struct Book* next;
} Book;

// 全局变量，指向图书链表的头节点
Book* head = NULL;

// 添加图书
void addBook(char title[], char author[], int id) {
    // 创建新的图书节点
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->id = id;
    newBook->next = NULL;

    if (head == NULL) {
        // 如果链表为空，将新节点设为头节点
        head = newBook;
    } else {
        // 否则找到链表尾部，将新节点链接到尾部
        Book* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBook;
    }

    printf("添加成功！\n");
}

// 借阅图书
void borrowBook(int id) {
    Book* current = head;

    while (current != NULL) {
        if (current->id == id) {
            if (current->next == NULL) {
                // 如果要借阅的图书是最后一本，直接将头节点置为空
                head = NULL;
            } else {
                // 否则将当前节点的下一个节点作为新的头节点
                head = current->next;
            }
            free(current);
            printf("借阅成功！\n");
            return;
        }
        current = current->next;
    }

    printf("找不到该图书！\n");
}

// 归还图书
void returnBook(char title[]) {
    Book* current = head;

    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("归还成功！\n");
            return;
        }
        current = current->next;
    }

    printf("找不到该图书！\n");
}

// 查询图书
void searchBook(char title[]) {
    Book* current = head;

    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("查询结果：\n");
            printf("书名：%s\n", current->title);
            printf("作者：%s\n", current->author);
            printf("ID：%d\n", current->id);
            return;
        }
        current = current->next;
    }

    printf("找不到该图书！\n");
}

// 打印所有图书
void printAllBooks() {
    Book* current = head;

    if (current == NULL) {
        printf("没有图书！\n");
        return;
    }

    printf("所有图书：\n");
    while (current != NULL) {
        printf("书名：%s\n", current->title);
        printf("作者：%s\n", current->author);
        printf("ID：%d\n", current->id);
        printf("\n");
        current = current->next;
    }
}

int main() {
    int choice;
    char title[100], author[100];
    int id;

    do {
        printf("\n图书管理系统\n");
        printf("1. 添加图书\n");
        printf("2. 借阅图书\n");
        printf("3. 归还图书\n");
        printf("4. 查询图书\n");
        printf("5. 打印所有图书\n");
        printf("0. 退出\n");
        printf("请输入你的选择：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("请输入要添加的图书信息：\n");
                printf("书名：");
                scanf("%s", title);
                printf("作者：");
                scanf("%s", author);
                printf("ID：");
                scanf("%d", &id);
                addBook(title, author, id);
                break;
            case 2:
                printf("请输入要借阅的图书ID：");
                scanf("%d", &id);
                borrowBook(id);
                break;
            case 3:
                printf("请输入要归还的图书名称：");
                scanf("%s", title);
                returnBook(title);
                break;
            case 4:
                printf("请输入要查询的图书名称：");
                scanf("%s", title);
                searchBook(title);
                break;
            case 5:
                printAllBooks();
                break;
            case 0:
                printf("谢谢使用，再见！\n");
                break;
            default:
                printf("无效的选择！\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
