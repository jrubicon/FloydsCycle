#include<iostream>
using namespace std;

struct Node {
int data;
Node * next;
Node(int val): data(val), next(NULL){}
};

class SLL {
  private:
    Node * head;
    int size;
  public:

      SLL(){
        head = NULL;
        size = 0;
      }

      bool insertfront(int temp){
        Node *ptr = new Node(temp);
          if(head == NULL){
            head = ptr;
            size++;
            return true;
          }
          else {
            ptr->next = head;
            head = ptr;
            size++;
            return true;
          }
      }

      void print(){
        Node *ptr = head;
        cout << "LIST SIZE: " << size << "\n";
        if(ptr->next != NULL){
          while (ptr->next != NULL){
            cout << ptr->data;
            ptr = ptr->next;
          }
          if(ptr->next == NULL){
            cout << ptr->data;
            return;
          }
        }
        else {
          cout << "LIST IS EMPTY!";
          return;
        }
        return;
      }

      bool setcycle(){
        Node *ptr = head;
        if(ptr->next == NULL){
            cout << "TOO SHORT TO CYCLE";
            return false;
          }
        else{
          while (ptr->next != NULL){
            if(ptr->next->next->next->next->next->next->next == NULL){
              ptr->next->next->next->next->next->next->next = ptr;
              return true;
            }
            ptr = ptr->next;
          }
        }
        return false;
      }

      void printexamplecycle(){
        Node *ptr = head;
        int counter = 0;
        cout <<"PRINTING CYCLE EXAMPLE\n";
        while(ptr->next != NULL && counter != 100){
          cout << ptr->data;
          ptr = ptr->next;
          counter++;
        }
      }

      bool checkcycle(){
        Node *slow = head;
        Node *fast = head;
        cout << "\n\nRUNNING checkcycle";
        while (slow && fast && fast->next != NULL){
          slow = slow->next;
          fast = fast->next->next;
          if(slow == fast){
            cout << "\nLOOP DETECTED AT DATASET { " << slow->data << " }"
                 <<" USING Floyd's Cycle\n\n";
            return true;
          }
        }
        cout << "\nNO CYCLE DETECTED\n";
        return false;
      }
};

int main(){

  SLL list;

  list.insertfront(25);
  list.insertfront(24);
  list.insertfront(23);
  list.insertfront(22);
  list.insertfront(21);
  list.insertfront(20);
  list.insertfront(19);
  list.insertfront(18);
  list.insertfront(17);
  list.insertfront(16);
  list.insertfront(15);
  list.insertfront(14);
  list.insertfront(13);
  list.insertfront(12);
  list.insertfront(11);
  list.insertfront(10);
  list.insertfront(9);
  list.insertfront(8);
  list.insertfront(7);
  list.insertfront(6);
  list.insertfront(5);
  list.insertfront(4);
  list.insertfront(3);
  list.insertfront(2);
  list.insertfront(1);

  list.print();
  list.checkcycle();

  if(list.setcycle())
    cout << "\n\nSETTING Cycle...\n";

 list.printexamplecycle();
 list.checkcycle();

  return 0;
}
