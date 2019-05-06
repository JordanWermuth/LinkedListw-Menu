#include <iostream>
using namespace std;

struct node{
    int number;
    node *next;
};

bool isEmpty(node *head){  //to check of the list is empty?
    if(head == NULL)
        return true;
    else
        return false;
}
char menu(){
    char choice;
    cout << "Menu" << endl;
    cout << "1. Add an item" << endl;
    cout << "2. Remove an item" << endl;
    cout << "3. Show the list" << endl;
    cout << "4. Show every other node in reverse" << endl;
    cout << "5. Show in Reversed" << endl;
    cout << "6. Add at position" << endl;
    cout << "7. Exit." << endl;

    cin >> choice;
    return choice;     //why do i need to return choice?

}
void insertFirstElement(node *&head,node *&last, int number){
    node *temp = new node;    //creates a new temporary node
    temp -> number = number;  //dereference the number, assigns number variable to the nodes number part
    temp -> next = NULL;      //
    head = temp;              //first value in the list set to temp
    last = temp;              //sets both to temp because only one thing is in the list
}
void insert(node *&head,node *&last, int number){    //
    if(isEmpty(head))
        insertFirstElement(head, last, number);
    else{
        node *temp = new node;
        temp -> number = number;
        temp -> next = NULL;
        last -> next = temp;
        last = temp;
    }
    /*cout << "enter what position to add at: " << endl;
    cin >> p >> endl;
    int p;
    node* current = head;
    next = current -> next;
    if (p==0){
        return insertFirstElement(number)
    }
    for (int i = 1; i < p && next != NULL; ++i) {
        current = next;
        next = current-> next;
    }
    node * v = new node(number, next);
    current-> next;*/




}
void remove(node *&head,node *&last){
    if(isEmpty(head))
        cout << "the list is already empty!" << endl;
    else if (head == last)
        {
            delete head;
            head == NULL;
            last == NULL;
        }
    else{
        node *temp = head;
        head = head ->next;
        delete temp;
    }

}
void showList(node *current){
    if(isEmpty(current))
        cout << " The list is empty!" << endl;
    else{
        cout << "the list contains: " << endl;
        while(current != NULL){
            cout << current -> number << endl;
            current = current -> next;
        }
    }

}

void printEveryOtherReversed(node *head){           // this doesn't work
    if (head == NULL)
        return;

    if (head -> next != NULL)
        printEveryOtherReversed(head ->next->next);
    cout << head -> number << " " << endl;


}
void printReversed(node *head){
    if (head == NULL)
        return;
    printReversed(head->next);
    cout << head -> number << " ";
}

void AddatPosition(node *head, node *last, int number, int position){
    cout << "Please enter the position you will add at: " << endl;
    cin >> position;

    node *current = head;
    node *next = current->next;
    if(isEmpty(head))
        insertFirstElement(head, last, number);
    else
        for (int i = 1; i < position && next != NULL; i++){
            current = next;
            next = current ->next;
        }
    node *temp = new node;
    current->next = temp;
}




int main() {
    node *head = NULL;   //initialized to null because nothing in the list
    node *last = NULL;
    int position;
    char choice;
    int number;

    do {
        choice = menu();
        switch (choice) {
            case '1':
                cout << "Please enter a number: ";
                cin >> number;
                insert(head, last, number);
                break;
            case '2':
                remove(head, last);
                break;
            case '3':
                showList(head);
                break;
            case '4':
                printEveryOtherReversed(head);
            case '5':
                printReversed(head);
            case '6':
                AddatPosition(head, last, number, position);
                default:
                cout << "System exit now";

        }


    }while (choice != '7');


}