#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;
};

class LinkedList
{
private:
    node* head;
    node* tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void Display()
    {
        if (head == NULL)
        {
            cout << "The list is empty!\n";
            return;
        }
        node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void AddNodeStart(int value)
    {
        node* temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL)
        {
            temp->prev = NULL;
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void AddNodeEnd(int value)
    {
        node* temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL)
        {
            temp->prev = NULL;
            head = temp;
            tail = temp;
        }
        else
        {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    void InsertNode(int value, int position)
    {
        if (position == 1)
        {
            AddNodeStart(value);
        }
        else
        {
            node* temp = new node;
            temp->next = NULL;
            temp->prev = NULL;
            temp->data = value;

            node* cur = head;
            for (int i = 2; i < position; i++)
            {
                if (cur == tail)
                {
                    AddNodeEnd(value);
                    return;
                }
                cur = cur->next;
            }

            temp->next = cur->next;
            temp->prev = cur;
            cur->next = temp;
        }
    }

    void DeleteNodeStart()
    {
        node* temp = head;
        if (head == tail)
        {
            tail = NULL;
            head = NULL;
            delete temp;
            cout << "The node has been deleted!\n";
        }
        else
        {
            temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            cout << "The node has been deleted!\n";
        }
    }

    void DeleteNodeEnd()
    {
        if (head == tail)
        {
            node* temp = head;
            head = NULL;
            tail = NULL;
            delete temp;
            cout << "The node has been deleted!\n";
        }
        else
        {
            node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
            cout << "The node has been deleted!\n";
        }
    }

    void DeleteNodeInside(int position)
    {
        if (position == 1)
        {
            DeleteNodeStart();
        }
        else
        {
            node* cur = head;
            node* pre = NULL;
            node* temp = NULL;
            for (int i = 2; i <= position; i++)
            {
                pre = cur;
                cur = cur->next;
                if (cur == tail)
                {
                    DeleteNodeEnd();
                    return;
                }
            }
            pre->next = cur->next;
            temp = cur->next;
            temp->prev = cur->prev;
            delete cur;
        }
    }

    void Search(int value)
    {
        if (head == NULL)
        {
            cout << "The list is empty!" << endl;
            return;
        }

        node* temp = head;

        int pos = 1;

        while (temp->data != value && temp->next != NULL)
        {
            pos++;
            temp = temp->next;
        }

        if (temp->data != value)
        {
            cout << "Element not found!" << endl;
            return;
        }

        cout << "Element at position " << pos << endl;
    }

    bool IsEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }

    void Reverse()
    {
        if (head == NULL)
        {
            cout << "The list is empty!\n";
            return;
        }
        node* temp = NULL;
        node* cur = head;
        tail = head;

        while (cur != NULL)
        {
            temp = cur->prev;
            cur->prev = cur->next;
            cur->next = temp;
            cur = cur->prev;
        }

        if (temp != NULL)
        {
            head = temp->prev;
            tail->next = NULL;
            head->prev = NULL;
        }
    }
    void DeleteAll()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head == tail)
        {
            node* temp = head;
            head = NULL;
            tail = NULL;
            delete temp;
        }
        else
        {
            node* temp = head;
            node* cur = NULL;
            head = NULL;
            while (temp != NULL)
            {
                cur = temp->next;
                delete temp;
                temp = cur;
            }
            delete cur;
            tail = NULL;
        }
    }
};

void MenuText()
{
    system("CLS");
    cout << "Options list: \n";
    cout << "\n";
    cout << "1 - Add node to start\n";
    cout << "2 - Add node to end\n";
    cout << "3 - Add node at the given index\n";
    cout << "4 - Delete node at the start\n";
    cout << "5 - Delete node at the end\n";
    cout << "6 - Delete node at the given index\n";
    cout << "7 - Search for an element\n";
    cout << "8 - Check if the list is empty\n";
    cout << "9 - Display the list\n";
    cout << "10 - Reverse the list\n";
    cout << "0 - Exit\n";
}

int main()
{
    LinkedList list;

    int n;

    while (true)
    {
        MenuText();

        cout << "\nEnter your choice: ";
        cin >> n;

        system("CLS");
        switch (n)
        {
        case 1:
        {
            cout << "Enter the value: ";
            int value;
            cin >> value;

            list.AddNodeStart(value);
            break;
        }
        case 2:
        {
            cout << "Enter the value: ";
            int value;
            cin >> value;

            list.AddNodeEnd(value);
            break;
        }
        case 3:
        {
            cout << "Enter the value: ";
            int value;
            cin >> value;
            cout << "Enter the position: ";
            int position;
            cin >> position;

            list.InsertNode(value, position);
            break;
        }
        case 4:
        {
            if (list.IsEmpty())
            {
                cout << "List is already empty!";
            }
            else
                list.DeleteNodeStart();
            break;
        }
        case 5:
        {
            if (list.IsEmpty())
            {
                cout << "List is already empty!";
            }
            else
                list.DeleteNodeEnd();
            break;
        }
        case 6:
        {
            if (list.IsEmpty())
            {
                cout << "List is already empty!";
            }
            else
            {
                cout << "Enter the position: ";
                int position;
                cin >> position;
                list.DeleteNodeInside(position);
            }
            break;
        }
        case 7:
        {
            cout << "Enter the element value: ";
            int value;
            cin >> value;
            list.Search(value);
            break;
        }
        case 8:
        {
            if (list.IsEmpty())
            {
                cout << "List is empty!";
            }
            else
            {
                cout << "List is not empty!";
            }
            break;
        }
        case 9:
        {
            list.Display();
            break;
        }
        case 10:
        {
            list.Reverse();
            break;
        }
        case 0:
        {
            list.DeleteAll();
            cout << "Bye have a great day!\n";
            return 0;
        }
        default:
        {
            cout << "Invalid input!";
            break;
        }
        }
        cout << endl;
        system("pause");
    }
    return 0;
}