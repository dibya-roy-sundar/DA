#include <iostream>
using namespace std;
class node
{
public:
  int data;
  node *prev;
  node *next;
  node(int x)
  {
    data = x;
    prev = NULL;
    next = NULL;
  }
};
class LL
{
  node *head;
  node *end;
  int count;

public:
  LL()
  {
    head = NULL;
    end = NULL;
    count = 0;
  }
  void displayLL()
  {
    node *n = head;
    while (n != NULL)
    {
      cout << n->data;
      n = n->next;
    }
    cout << endl;
  }
  int getlength()
  {
    int len = 0;
    node *n = head;
    while (n != NULL)
    {
      len++;
      n = n->next;
    }
    return len;
  }
  void insertnodeatbeg(int newdata)
  {
    node *n = new node(newdata);
    if (count == 0)
    {
      head = n;
      end = n;
    }
    else
    {
      head->prev = n;
      n->next = head;
      head = n;
    }
    count++;
  }
  void insertnodeatend(int newdata)
  {
    node *n = new node(newdata);
    if (count == 0)
    {
      head = n;
      end = n;
    }
    else
    {
      end->next = n;
      n->prev = end;
      end = n;
    }
    count++;
  }
  void addafternode(int afterwhat, int newdata)
  {
    node *n = new node(newdata);
    node *temp = head;
    while (temp->data != afterwhat)
    {
      temp = temp->next;
    }
    n->next = temp->next;
    n->prev = temp;
    temp->next->prev = n;
    temp->next = n;

    count++;
  }
  void addbeforenode(int beforewhat, int newdata)
  {
    node *n = new node(newdata);
    node *temp = head;
    while (temp->data != beforewhat)
    {
      temp = temp->next;
    }
    n->next = temp;
    n->prev = temp->prev;
    temp->prev->next = n;
    temp->prev = n;

    count++;
  }
  void deletenodeatbeg()
  {
    node *temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    delete (temp);
    count--;
  }
  void deletenodeatend()
  {
    node *temp = end;
    temp->prev->next = NULL;
    end = temp->prev;
    delete (temp);
    count--;
  }
  void deletebeforenode(int beforewhat)
  {
    node *temp = head;
    while (temp->data != beforewhat)
    {
      temp = temp->next;
    }
    node *temp1 = temp->prev;
    temp1->prev->next = temp;
    temp->prev = temp1->prev;
    delete (temp1);
    count--;
  }
  void deleteafternode(int afterwhat)
  {
    node *temp = head;
    while (temp->data != afterwhat)
    {
      temp = temp->next;
    }
    node *temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next->prev = temp1->prev;
    delete (temp1);
    count--;
  }
  void deletenodeforwhatvalue(int value)
  {
    node *temp = head;
    while (temp->data != value)
    {
      temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete (temp);
    count--;
  }
};

int main()
{
  LL *l = new LL();
}