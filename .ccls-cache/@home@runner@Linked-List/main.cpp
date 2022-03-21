// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;


struct Node{
    //data
    int data;
    //pointer
    Node* next;
    Node* previous;
};

class LinkedList {
    
    public:
    
    Node *head;
    Node *tail;
    int length = 0;
    
    LinkedList(){
        head = NULL;
        tail = NULL;
    };
    
    void prepend(int value) {
        Node* new_node = new Node;
        new_node->data = value;
        new_node->next = NULL;
        new_node->previous = NULL;
        
        //If the head pointer is NULL
        if(head == NULL) {
            //set the head pointer equal to our new node pointer
            head = new_node;
            tail = head;
            length++;
        }
        
        else {
            //If the head is not empty, make the new_node point to the old head (inserting from front)
            new_node->next = head;
            head->previous = new_node;
            //Then make the new node the head
            head = new_node;
            length++;
        }
    }
    
    void append(int value) {
        Node* new_node = new Node;
        new_node->data = value;
        new_node->next = NULL;
        
        if(head == NULL) {
            head = new_node;
            tail = head;
            length++;
        }
        
        else{
            Node* prev = new Node;
            prev = tail;
            
            tail = new_node;
            prev->next = tail;
            tail->previous = prev;
            length++;
            
            
        }
    }
    
    void insert(int index, int value) {
        
        if(index == 0) {
            this->prepend(value);
            length++;
        }
        else{
                    Node* new_node = new Node;
        new_node->data = value;
        Node* temp = head;
        
        int i = 0;
        
        while(i < index-1) {
            temp = temp->next;
            i++;
        }
        
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->previous = temp;
        length++;
        }
  
    }

    void remove(int index) {
      Node* temp = head;
      int i = 0;

      if(index == 0) {
        temp = temp->next;
        head = temp;
        head->previous = NULL;
      }

      else if(index >= length-1) {
        while(i < length-2) {
          temp = temp->next;
          i++;
        }

        temp->next = NULL;
        tail = temp;
      }

      

      else {
        while(i < index-1) {
        temp = temp->next;
        i++;
      }

      Node* prevNode = temp;

      temp = temp->next;
      temp = temp->next;

      prevNode->next = temp;
      temp->previous = prevNode;
      }


      length--;


    }




  /*void reverse() {
    Node* prev = NULL;
    Node* curr = this->head;
    this->tail = this->head;
    Node* next = NULL;

    while(curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    this->head = prev;
  }*/

  void reverse() {
    if(!this->head->next) {
      this->head = head;
    }
    Node* first = this->head;
    this->tail = this->head;
    Node* second = first->next;
    int i = 0;
    while(i < 2) {
      Node* temp = second->next;
      second->next = first;
      first = second;
      second = temp;
      i++;
    }
    this->head->next = NULL;
    this->head = first;
  }


    
    void display() {
        cout << "Head: " << head->data << endl;
        cout << "Tail: " << tail->data << endl;
        cout << "\nLength: " << length << "\n" << endl;
        
        Node* temp = head;
        
        while(temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
            
        }
    }
};





int main() {
    // Write C++ code here
    LinkedList obj;
    
    obj.prepend(1);
    obj.prepend(5);
    obj.prepend(6);
    obj.prepend(3);
    obj.prepend(9);
    obj.append(25);
    obj.append(27);
    
    obj.insert(2,100);
    obj.insert(1,200);

    obj.remove(2);
    obj.remove(1);
    obj.remove(0);
    obj.remove(5);
    obj.remove(5);

    obj.append(233);
    obj.prepend(25678);

    obj.remove(0);
    obj.remove(1000);

    obj.prepend(200);

    obj.reverse();

    
    obj.display();
    

    return 0;
}