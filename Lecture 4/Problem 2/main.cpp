#include <iostream>

using namespace std;

class Node
{
    Node(string data) : data(data) { ; };
    const string data;

    Node* next = NULL;

    friend struct List;
};

struct List
{
    List(string data = ""):head(new Node(data)) { ; };

    void addNode(string data = "") {
        auto old_head = head;
        head = new Node(data);
        head->next = old_head;
    }

    string getFirst() {
        return head->data;
    }

    string getElement(int element) {
        auto current = head;

        for (int i = 0; i < element; i++)
        {
            if (current->next) current = current->next;
            else return current->data;
        }

        return current->data;
    }

    int findMiddle() {
        auto current = head;
        int position = 0;

        while (true)
        {
            if (current->next) {
                current = current->next;
                position++;
            }
            else break;
        }
        return position / 2;
    }

private:
    Node* head;
};

int main()
{
    List list("Test");
    list.addNode("Another test1");
    list.addNode("Another test2");
    list.addNode("Another test3");
    list.addNode("Another test4");
    list.addNode("Another test5");
    list.addNode("Another test6");
    cout << "First element: " << list.getFirst() << endl;
    cout << "3rd element: " << list.getElement(2) << endl;
    cout << list.findMiddle();
}