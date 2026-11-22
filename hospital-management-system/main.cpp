#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int    id;
    string name, disease, doctor;
    Patient* next;

    Patient(int i, string n, string d, string doc)
        : id(i), name(n), disease(d), doctor(doc), next(NULL) {}

    void display() const {
        cout << "\n  ID      : " << id
             << "\n  Name    : " << name
             << "\n  Disease : " << disease
             << "\n  Doctor  : " << doctor
             << "\n  --------------------\n";
    }
};

class PatientList {
    Patient* head;

public:
    PatientList() : head(NULL) {}

    ~PatientList() {
        while (head) {
            Patient* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    Patient* find(int id) {
        for (Patient* curr = head; curr; curr = curr->next)
            if (curr->id == id) return curr;
        return NULL;
    }

    bool add(int id, string n, string d, string doc) {
        if (find(id)) { cout << "  ! ID already exists\n"; return false; }

        Patient* p = new Patient(id, n, d, doc);
        if (!head) { head = p; }
        else {
            Patient* curr = head;
            while (curr->next) curr = curr->next;
            curr->next = p;
        }
        cout << "  Patient added successfully\n";
        return true;
    }

    void update(int id, string n, string d, string doc) {
        Patient* p = find(id);
        if (!p) { cout << "  ! Patient not found\n"; return; }
        p->name = n;  p->disease = d;  p->doctor = doc;
        cout << "  Patient updated successfully\n";
    }

    void remove(int id) {
        if (!head) { cout << "  ! List is empty\n"; return; }

        if (head->id == id) {
            Patient* tmp = head;
            head = head->next;
            delete tmp;
            cout << "  Patient deleted successfully\n";
            return;
        }

        Patient* curr = head;
        while (curr->next && curr->next->id != id)
            curr = curr->next;

        if (!curr->next) { cout << "  ! Patient not found\n"; return; }

        Patient* tmp = curr->next;
        curr->next = tmp->next;
        delete tmp;
        cout << "  Patient deleted successfully\n";
    }

    void displayAll() {
        if (!head) { cout << "  No patients found\n"; return; }
        for (Patient* curr = head; curr; curr = curr->next)
            curr->display();
    }
};

class Queue {
    struct Node {
        int id;
        Node* next;
        Node(int i) : id(i), next(NULL) {}
    };
    Node* front;
    Node* rear;

public:
    Queue() : front(NULL), rear(NULL) {}

    ~Queue() {
        while (front) {
            Node* tmp = front;
            front = front->next;
            delete tmp;
        }
    }

    void enqueue(int id) {
        Node* n = new Node(id);
        if (!rear) { front = rear = n; return; }
        rear->next = n;
        rear = n;
    }

    int dequeue() {
        if (!front) { cout << "  ! Queue is empty\n"; return -1; }
        int id    = front->id;
        Node* tmp = front;
        front     = front->next;
        if (!front) rear = NULL;
        delete tmp;
        return id;
    }

    void display() {
        if (!front) { cout << "  Queue is empty\n"; return; }
        cout << "  Queue: ";
        for (Node* curr = front; curr; curr = curr->next)
            cout << "[" << curr->id << "]" << (curr->next ? " -> " : "\n");
    }

    void peek() {
        if (!front) cout << "  Queue is empty\n";
        else        cout << "  First in queue: ID " << front->id << "\n";
    }
};

void readPatientData(int& id, string& n, string& d, string& doc) {
    cout << "  ID      : "; cin >> id;      cin.ignore();
    cout << "  Name    : "; getline(cin, n);
    cout << "  Disease : "; getline(cin, d);
    cout << "  Doctor  : "; getline(cin, doc);
}

int main() {
    PatientList list;
    Queue       queue;
    int         choice;

    do {
        cout << "\n============================\n"
                "  Hospital Management System\n"
                "============================\n"
                "  1. Add Patient\n"
                "  2. Display All\n"
                "  3. Search\n"
                "  4. Update\n"
                "  5. Delete\n"
                "  6. Show Queue\n"
                "  7. Serve Next Patient\n"
                "  0. Exit\n"
                "  Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            int id; string n, d, doc;
            readPatientData(id, n, d, doc);
            if (list.add(id, n, d, doc))
                queue.enqueue(id);

        } else if (choice == 2) {
            list.displayAll();

        } else if (choice == 3) {
            int id; cout << "  ID: "; cin >> id;
            Patient* p = list.find(id);
            if (p) p->display(); else cout << "  ! Patient not found\n";

        } else if (choice == 4) {
            int id; string n, d, doc;
            readPatientData(id, n, d, doc);
            list.update(id, n, d, doc);

        } else if (choice == 5) {
            int id; cout << "  ID: "; cin >> id;
            list.remove(id);

        } else if (choice == 6) {
            queue.display();
            queue.peek();

        } else if (choice == 7) {
            int id = queue.dequeue();
            if (id != -1) {
                Patient* p = list.find(id);
                if (p) { cout << "  Now serving:\n"; p->display(); }
                list.remove(id);
            }

        } else if (choice == 0) {
            cout << "  Goodbye!\n";

        } else {
            cout << "  ! Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}