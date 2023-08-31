#include <iostream>
#include <map>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int x)
    {
        data = x;
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
    node *gethead()
    {
        return head;
    }
    node *getend()
    {
        return end;
    }
    void setdata()
    {
        int check;
        cout << "enter 1 to insert node and 0 to exit" << endl;
        cin >> check;
        if (check)
        {
            int val;
            cout << "enter data" << endl;
            cin >> val;
            node *temp = new node(val);
            insertnodeatbeg(temp);
            setdata();
        }
        else
        {
            return;
        }
    }
    void displayLL(node *head1)
    {
        node *n = head1;
        while (n != NULL)
        {
            cout << n->data;
            n = n->next;
        }
    }
    void insertnodeatbeg(node *n)
    {
        if (count == 0)
        {
            head = n;
            end = n;
        }
        else
        {

            n->next = head;
            head = n;
        }
        count++;
    }
    void addnodeatbeg(int newdata)
    {
        node *n = new node(newdata);
        if (count == 0)
        {
            head = n;
            end = n;
        }
        else
        {

            n->next = head;
            head = n;
        }
        count++;
    }
    void addnodeatend(int newdata)
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
            end = n;
        }
        count++;
    }
    void addafternode(int afterwhat, int newdata)
    {
        node *temp = head;
        node *n = new node(newdata);
        while (temp->data != afterwhat)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;

        count++;
    }
    void deletenodeatbeg()
    {
        node *temp = head;
        head = temp->next;
        delete (temp);
        count--;
    }
    void deletenodeatend()
    {
        node *temp = head;
        while (temp->next != end)
        {
            temp = temp->next;
        }
        node *temp1 = temp->next;
        temp->next = NULL;
        end = temp;
        delete (temp1);
        count--;
    }
    void deletenodeforwhatvalue(int value)
    {
        node *prev = head;
        node *curr = prev->next;
        if (prev->data == value)
        // delete beggining node
        {
            node *temp = prev;
            head = temp->next;
            temp->next = NULL;
            delete (temp);
        }
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete (curr);
    }

    void reverseLL()
    {
        node *prev = NULL;
        node *curr = head;
        node *forward = curr->next;
        while (curr->next != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = forward;
            forward = forward->next;
        }
        curr->next = prev;
        head = curr;
    }
    void findmiddlenode()
    {
        // in case of 5 return 3 and in case of 6 return 4
        node *slow = head;
        node *fast = head->next;
        if (count == 0)
        {
            cout << "Empty list";
        }
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
        }
        cout << "Middle element is " << slow->data;
    }

    void findnthnodefromend(int n)
    {
        // cout<<count;
        if (n > count)
        {
            cout << "that's simply not possible because it's goes beyond the linkedlist";
        }
        else
        {
            node *slow = head;
            node *fast = head;
            int newcount = 0;
            while (newcount < n)
            {
                fast = fast->next;
                newcount++;
            }
            while (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next; // this will be the nth from end.
                // difference between slow and fast will remain same
            }
            cout << n << " Nth Element From End :" << slow->data;
        }
    }

    bool checkcircularllornot()
    {
        node *temp = head->next;
        while (temp != NULL && temp != head)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "not a circulr list";
            return 0;
        }
        if (temp == head)
        {
            cout << "it's  a circular list ";
            return 1;
        }
    }

    node *kreverse(node *headreverse, int k)
    {
        node *prev = NULL;
        node *curr = headreverse;
        node *forward = NULL;
        int thiscount = 0;
        while (thiscount < k)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            thiscount++;
        }
        if (forward != NULL)
        {
            headreverse->next = kreverse(curr, k);
        }
        return prev;
    }

    bool loopdetection()
    {
        // space complexity=o(n)
        // time =o(n)
        // if we visit one node at at a time we marked visited as true so if we visit the node second time we will know that it previously visited
        if (head == NULL)
        {
            cout << "empty list";
            return 0;
        }
        node *temp = head;
        map<node *, bool> visited;
        while (temp != NULL)
        {
            if (visited[temp] == true)
            {
                cout << "loop start at " << temp->data << endl;
                return 1;
            }
            visited[temp] = true;
            temp = temp->next;
        }
        return 0;
    }

    node *floydloopdetection()
    {
        // tc=o(n)
        // sc=o(1)
        node *slow = head;
        node *fast = head;
        while (slow != NULL && fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
            // distance between slow and fast decreses by 1 anticlockwise  in every iteration
            if (fast == slow)
            {
                node *intersection = fast;
                slow = head;
                // // post addition to find start element of loop
                while (slow != intersection)
                {
                    slow = slow->next;
                    intersection = intersection->next;
                }
                cout << "loop starts at " << slow->data << endl;
                return slow;
            }
        }
        return NULL;
    }

    void removeloop(node *loophead)
    {
        node *temp = loophead;
        while (temp->next != loophead)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        cout << "we break the loop" << endl;
    }

    void sort012()
    {
        // data replacement not allowed
        // create 3 dummy node
        node *zerohead = new node(-1);
        node *zerotail = zerohead;
        node *onehead = new node(-1);
        node *onetail = onehead;
        node *twohead = new node(-1);
        node *twotail = twohead;
        node *curr = head;
        while (curr)
        {
            // cur!=NULL
            int val = curr->data;
            // create  3 seperate list
            if (val == 0)
            {
                zerotail->next = curr;
                zerotail = curr;
            }
            else if (val == 1)
            {
                onetail->next = curr;
                onetail = curr;
            }
            else if (val == 2)
            {
                twotail->next = curr;
                twotail = curr;
            }
            curr = curr->next;
        }
        //  merge 3 list
        if (onehead->next)
        {
            // onehead->next!=NULL
            // if no one in the linkedlist
            zerotail->next = onehead->next;
            onetail->next = twohead->next;
        }
        else
        {
            zerotail->next = twohead->next;
        }
        twotail->next = NULL;
        // update head and end
        head = zerohead->next;
        end = twotail;
        // delete three dummy nodes
        delete (onehead);
        delete (twohead);
        delete (zerohead);
    }

    node *solvemerge2sort(node *first, node *second)
    {
        node *curr1 = first;
        node *curr2 = second;
        node *next1 = curr1->next;
        node *next2 = curr2->next;
        // if only one node in 1st ll
        if (next1 == NULL)
        {
            curr1->next = curr2;
            return first;
        }
        while (next1 != NULL && curr2 != NULL)
        {
            if (curr2->data >= curr1->data && curr2->data <= next1->data)
            {
                // insertion of node
                curr1->next = curr2;
                curr2->next = next1;
                // update  after insertion
                curr1 = curr2;
                curr2 = next2;
                if (next2)
                {
                    next2 = next2->next;
                }
            }
            else
            {
                curr1 = next1;
                next1 = next1->next;
            }
            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
        return first;
    }

    node *merge2sort(node *head1, node *head2)
    {
        if (head1 == NULL && head2 != NULL)
        {
            return head2;
        }
        if (head2 == NULL && head1 != NULL)
        {
            return head1;
        }
        if (head1 == NULL && head2 == NULL)
        {
            return NULL;
        }
        if (head1->data <= head2->data)
        {
            return solvemerge2sort(head1, head2);
        }
        else
        {
            return solvemerge2sort(head2, head1);
        }
    }

    node *getmid()
    {
        node *slow = head;
        node *fast = head->next;
        if (count == 0)
        {
            cout << "Empty list";
            return head;
        }
        if (count == 1)
        {
            return head;
        }
        while (fast->next != NULL)
        {
            fast = fast->next;
            if (fast->next != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }

    node *reverse(node *headrev)
    {
        node *prev = NULL;
        node *curr = headrev;
        node *frwd = NULL;
        while (curr != NULL)
        {
            frwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frwd;
        }
        return prev;
    }
    bool checkpalindrome()
    {
        // find middle
        node *mid = getmid();
        // reverse LL after mid
        node *temp1 = mid->next;
        mid->next = reverse(temp1);
        // compare both half
        node *head1 = head;
        node *head2 = mid->next;
        while (head2 != NULL)
        {
            if (head1->data != head2->data)
            {
                return 0;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        // reverse again to not manipulate original ll
        node *temp2 = mid->next;
        mid->next = reverse(temp2);
        // return true if palindrome
        return 1;
    }

    node *reverse(node *head)
    {
        node *prev = NULL;
        node *curr = head;
        node *frwd = NULL;
        while (curr)
        {
            frwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frwd;
        }
        return prev;
    }

    node *add(node *head1, node *head2)
    {
        node *first = head1;
        node *second = head2;
        node *dummyHead = new node(0);
        node *tail = dummyHead;
        int carry = 0;
        while (first != NULL || second != NULL || carry != 0)
        {
            int val1 = 0;
            if (first)
            {
                val1 = first->data;
            }
            int val2 = 0;
            if (second)
            {
                val2 = second->data;
            }
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            node *n = new node(digit);
            tail->next = n;
            tail = tail->next;
            carry = sum / 10;
            if (first != NULL)
            {
                first = first->next;
            }
            if (second != NULL)
            {
                second = second->next;
            }
        }
        node *result = dummyHead->next;
        delete dummyHead;
        return result;
    }
    node *addTwoNumbers(node *l1, node *l2)
    {
        // reverse list
        node *first = reverse(l1);
        node *second = reverse(l2);
        // add
        node *anshead = add(first, second);
        // reverse ans
        anshead = reverse(anshead);
        // return ans head
        return anshead;
    }

    void insertattail(node *&head, node *&tail, int data)
    {
        // pass by reference
        node *n = new node(data);
        if (head == NULL && tail == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
    }
    node *copyRandomList(node *head)
    {
        // create a clone with next pointer
        node *temp = head;
        node *clonehead = NULL;
        node *clonetail = NULL;
        while (temp)
        {
            insertattail(clonehead, clonetail, temp->data);
            temp = temp->next;
        }
        // changing links
        node *originalhead = head;
        node *clnhead = clonehead;
        while (originalhead != NULL && clnhead != NULL)
        {
            node *orgnxt = originalhead->next;
            originalhead->next = clnhead;
            originalhead = orgnxt;
            node *clonenxt = clnhead->next;
            clnhead->next = originalhead;
            clnhead = clonenxt;
        }
        // connects random
        originalhead = head;
        while (originalhead)
        {
            if (originalhead->next)
            {
                // originalhead->next->random = originalhead->random ? originalhead->random->next : originalhead->random;
                //     if(originalhead->random){
                // originalhead->next->random=originalhead->random->next;
                // }else{
                //      originalhead->next->random=originalhead->random;
                // }
                originalhead = originalhead->next->next;
            }
        }
        // reverse back step2 and connects previos link
        originalhead = head;
        clnhead = clonehead;
        while (originalhead != NULL && clnhead != NULL)
        {
            originalhead->next = clnhead->next;
            originalhead = originalhead->next;
            if (originalhead)
            {
                clnhead->next = originalhead->next;
            }
            clnhead = clnhead->next;
        }
        // return ans
        return clonehead;
    }
};

int main()
{
    LL *l = new LL();
    // l->addnodeatbeg(1);
    // l->addnodeatbeg(3);
    // l->addnodeatbeg(3);
    // // l->addnodeatbeg(4);
    // l->addnodeatbeg(2);
    // l->addnodeatbeg(1);
    // l->  addnodeatbeg(1);
    // l->  addnodeatbeg(0);
    l->setdata();
    cout << endl;
    l->displayLL(l->gethead());
    cout << endl;
    // l->reverseLL();
    // cout<<endl;
    // l->displayLL();
    // cout<<endl;
    // l->findmiddlenode();
    // cout<<endl;
    // l->findnthnodefromend(7);
    // cout<<endl;
    // l->findnthnodefromend(8);
    // cout<<endl;
    // l->checkcircularllornot();
    // cout<<endl;
    // node *head1 = l->kreverse(l->gethead(), 2);
    // l->displayLL(head1);
    // cout<<endl;
    // node* head2=l->gethead();
    // node* end1=l->getend();
    // end1->next=head2->next->next;
    // if(l->loopdetection()){
    // cout<<"cycle/loop exists"<<endl;
    // }else{
    // cout<<"no cycle "<<endl;
    // }
    // if(l->floydloopdetection()!=NULL){
    // cout<<"cycle/loop exists"<<endl;
    // }else{
    // cout<<"no cycle "<<endl;
    // }
    // cout<<endl;
    // l->removeloop(l->floydloopdetection());
    // l->displayLL(l->gethead());
    // l->sort012();
    // cout<<endl;
    // l->displayLL(l->gethead());
    cout << endl;
    if (l->checkpalindrome())
    {
        cout << "this ll is palindrome" << endl;
    }
    else
    {
        cout << "not palindrome" << endl;
    }
}