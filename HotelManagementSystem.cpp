//project name: hotel managment system
#include <iostream>
#include <string> 
using namespace std;
//implementation of linklist:
struct resUnit {
    string type;
    int id;
    string status;
    resUnit *next;
};

class floorManagment {
public:
    resUnit *head;
    resUnit *tail;
    int floorno;
    int roomsperfloor;

    floorManagment(int fno, int rno) {
        floorno = fno;
        roomsperfloor = rno;
        head = NULL;
        tail = NULL;
    }

    void insertunit(string rtype, string rstatus, int roomno) {
        resUnit *newroom = new resUnit;
        newroom->type = rtype;
        newroom->id = roomno;
        newroom->status = rstatus;
        newroom->next = NULL;

        if (head == NULL) {
            head = newroom;
            tail = newroom;
        } else {
            tail->next = newroom;
            tail = newroom;
        }
    }

    void displayunits() {
        resUnit *temp = head;
        while (temp != NULL) {
            cout << "Room number: " << temp->id << endl;
            cout << "Room type: " << temp->type << endl;
            cout << "Room status: " << temp->status << endl;
            cout << "------------------------------------------------" << endl;
            temp = temp->next;
        }
    }

    bool assignRoom(string request, int &assignedRoom) {
        resUnit *temp = head;
        while (temp != NULL) {
            if (temp->status == "available" && temp->type == request) {
                temp->status = "booked";
                assignedRoom = temp->id;
                return true;
            }
            temp = temp->next;
        }
        return false; // No available room matching the request
    }

    void search(string searchtype) {
        resUnit *temp = head;
         if(searchtype=="single" || searchtype=="double" || searchtype=="suite"){ 
        while (temp != NULL) {
           
            if (temp->type == searchtype) {
                cout << "Room number: " << temp->id << endl;
                cout << "Room type: " << temp->type << endl;
                cout << "Room status: " << temp->status << endl;
            }
            temp = temp->next;
        }}
        else{cout<<"we either dont have the room you want or you didnt enter it the correct way. \n ";
        }
    }
};
//circular,priority queue implementation for processing requests:
class Queue {
private:
    int front;
    int rear;
    int capacity;
    string *queue;

public:
    Queue(int size) {
        capacity = size;
        queue = new string[capacity];
        front = -1;
        rear = -1;
    }

    ~Queue() {
        delete[] queue;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % capacity == front);
    }

    void enqueue(string request,string name,int nights, bool priority) {
        if (isFull()) {
            cout << "Queue is full. Cannot process more booking requests." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
            queue[rear] = request;
        } else if (priority) {
            // Handle high-priority request: Insert at the front
            front = (front - 1 + capacity) % capacity;
            queue[front] = request;
            
        } else {
            // Regular request: Insert at the rear
            rear = (rear + 1) % capacity;
            queue[rear] = request;
            
        }

        cout << "Booking request added: " <<endl;
        cout<<request <<"  "<<name<<"  "<<nights<<" nights "<< endl;
    }

    string dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No booking requests to process." << endl;
            return "";
        }

        string processedRequest = queue[front];
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
           
           front++ ;
        }

        return processedRequest;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Current booking requests: ";
        int i = front;
        while (true) {
            cout << queue[i];
            if (i == rear) break;
            cout << " -> ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};
//stack implementation for history preservation:
class Stack {
private:
    int top;
    int capacity;
    string *stack;

public:
    Stack(int size) {
        capacity = size;
        stack = new string[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] stack;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == capacity - 1);
    }

    void push(string request, int assignedRoom,int nights) {
        if (isFull()) {
            cout << "Stack is full. Cannot add more booking history." << endl;
            return;
        }
       string roomno= to_string(assignedRoom);
       stack[++top] = request + " (Room: " + roomno + ")"  + "nights: "+ to_string(nights);
      
        cout << "Booking added to history: " << stack[top] << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. No booking history to remove." << endl;
            return;
        }

        cout << "Removing booking from history: " << stack[top--] << endl;
    }

    void displayStack() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Booking history: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    }
};

//tree implementation to display the default floor plan of the hotel:
class node{
public:
string type;
    int id;
    string status;
    node *left;
    node *right;

    node(){
        left=right=NULL;
    }

node(string t, int i, string s){
left=right=NULL;
type=t;
id=i;
status=s;}


};

class tree{
public:
node* root;
tree(){
root=NULL;
}
node* insertion(string type, int id, string status,node* root){
if(root==NULL){
node* n=new node(type,id,status);
return n;}

else if(type < root->type){
root->left = insertion(type, id, status, root->left);}

else{ root->right = insertion(type, id, status, root->right);}
return root;

}

void simpledisplay(node* root){
    if(root!=NULL){
        cout<<"room no: "<<root->id<<endl;
    cout<<"room type: "<<root->type<<endl;
    cout<<"room availability status: "<<root->status<<endl;
    simpledisplay(root->left);
    simpledisplay(root->right);
    }
}
void inorderdisplay(node* root){
if(root!=NULL){
    inorderdisplay(root->left);
    cout<<"room no: "<<root->id<<endl;
    cout<<"room type: "<<root->type<<endl;
    cout<<"room availability status: "<<root->status<<endl;
    inorderdisplay(root->right);
}}

void preorderdisplay(node* root){
if(root!=NULL){
    cout<<"room no: "<<root->id<<endl;
    cout<<"room type: "<<root->type<<endl;
    cout<<"room availability status: "<<root->status<<endl;
    preorderdisplay(root->left);

    preorderdisplay(root->right);
}
}

void postorderdisplay(node* root){
if(root!=NULL){

    postorderdisplay(root->left);
    postorderdisplay(root->right);
    cout<<"room no: "<<root->id<<endl;
    cout<<"room type: "<<root->type<<endl;
    cout<<"room availability status: "<<root->status<<endl;
}
}

};

int main() {
    int floors = 2;
    int rooms_on_each = 5;
    floorManagment obj(floors, rooms_on_each);
    Queue bookingQueue(10);
    Stack bookingHistory(10);
    tree bst;
    // Insert rooms into floor management linklist (same as before)
    for (int i = 1; i <= floors; i++) {
        int startingno = i * 100;

        for (int j = 1; j <= rooms_on_each; j++) {
            obj.insertunit("single", "available", startingno);
            bst.root = bst.insertion("single", startingno, "available", bst.root);
            startingno++;
            obj.insertunit("double", "available", startingno);
            bst.root = bst.insertion("double", startingno, "available", bst.root);
            startingno++;
            obj.insertunit("suite", "available", startingno);
             bst.root = bst.insertion("suite", startingno, "available", bst.root);
            startingno++;
        }
    }
    int choice;
    string searchtype;
menu:
    cout << "------------------------- MENU -----------------------------" << endl;
    cout << " ~ press 1 to display the room layout \n";
    cout << " ~ press 2 to add booking requests \n";
    cout << " ~ press 3 to display the current queue \n";
    cout << " ~ press 4 to process the queue \n";
    cout << " ~ press 5 to view booking history \n";
    cout << " ~ press 6 to remove the most recent booking from history \n";
    cout << " ~ press 7 to view hotel's default floor plan via tree \n";
    cout << " ~ press 8 if you want to search the rooms with specific type \n";
    cout << " ~ press 0 to exit \n";
    cout << " Your choice: ";
    cin >> choice;

string request,name;
int nights;
bool priority;

    switch (choice) {
        case 1:
            obj.displayunits();
            goto menu;
            break;
        case 2: {
            int numRequests;
            requests_again:
            cout << "Enter the number of booking requests to add (max 10 requests at a time): ";
            cin >> numRequests;
            if(numRequests>10){cout<<"you can book 10 requests maxmimum at a time! enter again please\n";
            goto requests_again;}
            cout << "------------------------------------------------" << endl;
 
            cin.ignore();

            for (int i = 0; i < numRequests; i++) {
            cout << "------------------------------------------------" << endl;
            cout<<" REQUEST NUMBER "<<i+1<<endl;
            cout << "------------------------------------------------" << endl;

            cout << "Enter booking request for the type of room you would like (enter all lowercase please)\n choose from: single, double, suite:  ";
                cin>>request;
            cout << "------------------------------------------------" << endl;

            cout<<"your name: ";
                cin.ignore();
               getline(cin,name);
            cout << "------------------------------------------------" << endl;

                nights_again:
            cout<<" how many nights would you like to stay:";
                cin>>nights;
                if(nights>30){cout<<"please choose a stay within 30 days!! ";
                goto nights_again;}
            cout << "------------------------------------------------" << endl;

                cout << "Is this a high-priority request? (1 for Yes, 0 for No): ";
                cin >> priority;
                cin.ignore();
            cout << "------------------------------------------------" << endl;

                bookingQueue.enqueue(request,name,nights,priority);
            }
            goto menu;
        }
        case 3:
            bookingQueue.displayQueue();
            goto menu;
            break;
        case 4: {
            string processed = bookingQueue.dequeue();
            int assignedRoom;
            if (!processed.empty()) {
                if (obj.assignRoom(processed, assignedRoom)) {
                    cout << "Room assigned: " << assignedRoom << " for request: " << processed;
                    cout <<" "<<name<<"  "<<nights<<" nights "<< endl;
                    bookingHistory.push(processed, assignedRoom,nights);
                } else {
                    cout << "No rooms available matching the request: " << processed << endl;
                }
            }
            goto menu;
        }
        case 5:
            bookingHistory.displayStack();
            goto menu;
            break;
        case 6:
            bookingHistory.pop();
            goto menu;
            break;
        case 7:
            bst.simpledisplay(bst.root);
            goto menu;
            break;
        case 8:
            cout<<"enter the type of rooms you're looking for (all lowercase): ";
            cin>>searchtype;
            obj.search(searchtype);
            goto menu;
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            goto menu;
    }

    return 0;
}

