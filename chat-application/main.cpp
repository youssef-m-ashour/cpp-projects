#include <iostream>
#include <string>
using namespace std;

// ======================================================
//                      Node
// ======================================================

struct Node {
    int    id;
    string text;
    Node*  next;

    Node(int i, string t) {
        id   = i;
        text = t;
        next = nullptr;
    }
};

// ======================================================
//                 Queue — Inbox (FIFO)
// ======================================================

class Queue {
private:
    Node* front;
    Node* rear;
    int   size;

public:
    Queue() {
        front = rear = nullptr;
        size  = 0;
    }

    void enqueue(int id, string text) {
        Node* n = new Node(id, text);

        if (rear == nullptr) {
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }

        size++;
    }

    Node* dequeue() {
        if (isEmpty()) return nullptr;

        Node* temp = front;
        front = front->next;

        if (front == nullptr) rear = nullptr;

        size--;
        return temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "  Inbox is empty.\n";
            return;
        }

        Node* temp = front;
        cout << "\n  ===== Inbox =====\n";

        while (temp != nullptr) {
            cout << "  [" << temp->id << "] " << temp->text << "\n";
            temp = temp->next;
        }

        cout << "  =================\n";
    }

    bool isEmpty() { return front == nullptr; }
    int  getSize() { return size; }

    ~Queue() {
        while (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// ======================================================
//                 Stack — Undo (LIFO)
// ======================================================

class Stack {
private:
    Node* top;
    int   size;

public:
    Stack() {
        top  = nullptr;
        size = 0;
    }

    void push(Node* n) {
        n->next = top;
        top = n;
        size++;
    }

    Node* pop() {
        if (isEmpty()) return nullptr;

        Node* temp = top;
        top = top->next;
        size--;
        return temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "  No deleted messages.\n";
            return;
        }

        Node* temp = top;
        cout << "\n  === Deleted ===\n";

        while (temp != nullptr) {
            cout << "  [" << temp->id << "] " << temp->text << "\n";
            temp = temp->next;
        }

        cout << "  ===============\n";
    }

    bool isEmpty() { return top == nullptr; }
    int  getSize() { return size; }

    ~Stack() {
        while (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

// ======================================================
//                    Chat App
// ======================================================

class ChatApp {
private:
    Queue inbox;
    Stack deleted;
    int   nextId;

public:
    ChatApp() { nextId = 1; }

    void sendMessage(string text) {
        inbox.enqueue(nextId++, text);
        cout << "  [✓] Message sent!\n";
    }

    void deleteMessage() {
        if (inbox.isEmpty()) {
            cout << "  [!] No messages to delete!\n";
            return;
        }

        Node* removed = inbox.dequeue();
        deleted.push(removed);
        cout << "  [✓] Deleted: \"" << removed->text << "\"\n";
    }

    void undoDelete() {
        if (deleted.isEmpty()) {
            cout << "  [!] Nothing to undo!\n";
            return;
        }

        Node* restored = deleted.pop();
        inbox.enqueue(restored->id, restored->text);
        delete restored;
        cout << "  [✓] Restored successfully!\n";
    }

    void showStatus() {
        cout << "\n  Inbox   : " << inbox.getSize()   << " message(s)\n";
        cout << "  Deleted : " << deleted.getSize() << " message(s)\n";
    }

    void showInbox()   { inbox.display();   }
    void showDeleted() { deleted.display(); }
};

// ======================================================
//                      Main
// ======================================================

int main() {

    ChatApp app;
    int     choice;
    string  text;

    cout << "\n  ╔══════════════════════════╗\n";
    cout << "  ║     Chat Application     ║\n";
    cout << "  ║    Queue + Stack         ║\n";
    cout << "  ╚══════════════════════════╝\n";

    do {
        cout << "\n  1. Send Message\n";
        cout << "  2. Show Inbox\n";
        cout << "  3. Delete Message\n";
        cout << "  4. Undo Delete\n";
        cout << "  5. Show Deleted\n";
        cout << "  6. Show Status\n";
        cout << "  0. Exit\n";
        cout << "\n  Choice: ";

        cin >> choice;
        cin.ignore();
        cout << "\n";

        switch (choice) {

        case 1:
            cout << "  Enter message: ";
            getline(cin, text);
            app.sendMessage(text);
            break;

        case 2:
            app.showInbox();
            break;

        case 3:
            app.deleteMessage();
            break;

        case 4:
            app.undoDelete();
            break;

        case 5:
            app.showDeleted();
            break;

        case 6:
            app.showStatus();
            break;

        case 0:
            cout << "  Goodbye!\n\n";
            break;

        default:
            cout << "  [!] Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}