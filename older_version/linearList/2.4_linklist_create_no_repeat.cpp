// 键入 (int)n, n为需要键入字符的个数
// 键入 ch1 ch2 ch3 ... chn
// 通过输入数据建立一个数据不重复的单链表

#include <iostream>
using namespace std;

typedef struct LinkNode {
    char data;
    struct LinkNode* next;
} LinkNode;
typedef LinkNode* LinkList;

void printLinkList(const LinkList& head) {
    LinkNode* p = head->next;
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}

/*
 * FunctionName : find()
 * Called By : createLinkList()
 */
bool find(const LinkList& head, const char& ch) {
    LinkNode* p = head->next;
    while (p != nullptr) {
        if (p->data == ch) {
            return true;
        }
        p = p->next;
    }
    return false;
}

/*
 * FunctionName : createLinkList()
 * Calls : find()
 */
void createLinkList(LinkList& head) {
    head = new LinkNode;
    head->next = nullptr;
    LinkNode* r = head;     // 维护尾节点
    LinkNode* p = nullptr;  // 维护创建需要加入单链表的节点
    int num;
    char ch;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cin >> ch;
        if (!find(head, ch)) {
            p = new LinkNode;
            p->data = ch;
            p->next = nullptr;
            r->next = p;
            r = p;
        }
    }
}

void test_1(void) {
    LinkList head;
    createLinkList(head);
    cout << "finish create" << endl;
    printLinkList(head);
}

int main(void) {
    test_1();
    return EXIT_SUCCESS;
}