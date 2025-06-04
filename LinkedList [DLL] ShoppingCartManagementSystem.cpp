# include <iostream>
# include <string>
using namespace std;
int listSize=0; //global variable for O(1) time complexity
struct Node
{
    Node *prev;
    int productID;
    string productName;
    int quantity;
    double pricePerUnit;
    Node *next;
} *head=nullptr, *rear=nullptr; // init pointers to nullptr
void createNode (int i, string s, int q, double p)
{
    Node *temp=new Node ();
    temp->prev=nullptr;
    temp->productID=i;
    temp->productName=s;
    temp->quantity=q;
    temp->pricePerUnit=p;
    temp->next=nullptr;
    if (head==nullptr)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
    listSize++;
    cout<<"\nCreated product with required data at position : "<<listSize<<endl;
}
void displayCartForward ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Cart is empty\nNothing to display\n";
    }
    else
    {
        cout<<"\nDisplaying Cart (Forward) : ";
        Node *temp=head;
        while (temp!=nullptr)
        {
            cout<<"[ "<<temp->productID<<", "<<temp->productName<<", "<<temp->quantity<<", "<<temp->pricePerUnit<<" Rs. ] -> ";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
}
void displayCartBackward ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Cart is empty!\nNothing to display\n";
    }
    else
    {
        cout<<"\nDisplaying Cart (Backward) : ";
        Node *temp=rear;
        while (temp!=nullptr)
        {
            cout<<"[ "<<temp->productID<<", "<<temp->productName<<", "<<temp->quantity<<", "<<temp->pricePerUnit<<" Rs. ] -> ";
            temp=temp->prev;
        }
        cout<<"NULL\n";
    }
}
void insert_first (int id, string s, int q, double p)
{
    Node *temp=new Node ();
    temp->prev=nullptr;
    temp->productID=id;
    temp->productName=s;
    temp->quantity=q;
    temp->pricePerUnit=p;
    temp->next=nullptr;
    if (head==nullptr)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    listSize++;
    cout<<"\nInserted product with required data at start..\n";
}
void insert_last (int id, string s, int q, double p)
{
    Node *temp=new Node ();
    temp->prev=nullptr;
    temp->productID=id;
    temp->productName=s;
    temp->quantity=q;
    temp->pricePerUnit=p;
    temp->next=nullptr;
    if (head==nullptr)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
    listSize++;
    cout<<"\nInserted product with required data at end..\n";
}
void insert_specified (int pos, int id, string s, int q, double price)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user for insertion of product!\n";
    }
    else
    {
        if (pos==1)
        {
            insert_first (id, s, q, price);
        }
        else
        {
            int num=listSize;
            if (pos>1 && pos<=num)
            {
                Node *temp=new Node (), *n=head->next, *p=head;
                int i=1;
                while (i<pos-1 && n!=nullptr)
                {
                    p=n;
                    n=n->next;
                    i++;
                }
                p->next=temp;
                temp->prev=p;
                temp->next=n;
                n->prev=temp;
                temp->productID=id;
                temp->productName=s;
                temp->quantity=q;
                temp->pricePerUnit=price; //151st line
                listSize++;
                cout<<"\nInserted product with required data at position : "<<pos<<" in the cart"<<endl;
            }
            else if (pos==num+1)
            {
                insert_last (id, s, q, price);
            }
            else
            {
                cout<<"\nERROR : Position out of range!\n";
            }
        }
    }
}
void delete_first ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Cart is empty!\nNothing to delete\n";
    }
    else if (head->next==nullptr)
    {
        delete head;
        cout<<"\nDeleted head node!\n";
        head=nullptr;
        rear=nullptr;
        listSize--;
    }
    else
    {
        Node *temp=head;
        head=head->next;
        head->prev=nullptr;
        delete temp;
        temp=nullptr;
        cout<<"\nDeleted first product!\n";
        listSize--;
    }
}
void delete_last ()
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Cart is empty!\nNothing to delete\n";
    }
    else if (head->next==nullptr)
    {
        delete head;
        cout<<"\nDeleted head node!\n";
        head=nullptr;
        rear=nullptr;
        listSize--;
    }
    else
    {
        Node *temp=rear;
        rear=rear->prev;
        rear->next=nullptr;
        delete temp;
        temp=nullptr;
        listSize--;
        cout<<"\nDeleted last product!\n\n";
    }
}
void delete_specified (int pos)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user for deletion of product!\n";
    }
    else
    {
        if (pos==1)
        {
            delete_first ();
        }
        else
        {
            int num=listSize;
            if (pos>1 && pos<listSize)
            {
                Node *temp, *n=head->next, *p=head;
                int i=1;
                while (i<pos-1)
                {
                    p=n;
                    n=n->next;
                    i++;
                }
                temp=p->next;
                p->next=temp->next;
                temp->next->prev=p;
                delete temp;
                temp=nullptr;
                listSize--;
                cout<<"\nDeleted product at position : "<<pos<<" from the cart"<<endl;
            }
            else if (pos==num)
            {
                delete_last ();
            }
            else
            {
                cout<<"\nERROR : Position out of range!\n";
            }
        }
    }
}
void searchProductByID (int id)
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Cart is empty!\nNothing to search for\n";
    }
    else
    {
        Node *temp=head;
        int i=0;
        bool flag=0;
        while (temp!=nullptr)
        {
            i++;
            if (temp->productID==id)
            {
                flag=1;
                cout<<"\nProduct with ID : "<<id<<" found at position : "<<i<<endl;
                break;
            }
            temp=temp->next;
        }
        if (!flag)
        {
            cout<<"\nProduct NOT found!\n";
        }
    }
}
void searchProductByPosition (int pos)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user for deletion of product!\n";
    }
    else
    {
        if (head==nullptr)
        {
            cout<<"\nALERT : Cart is empty!\nNothing to search for\n";
        }
        else
        {
            Node *temp=head;
            int i=0;
            bool flag=0;
            while (temp!=nullptr)
            {
                i++;
                if (i==pos)
                {
                    flag=1;
                    cout<<"\nProduct with ID : "<<temp->productID<<" found at position : "<<pos<<endl;
                    break;
                }
                temp=temp->next;
            }
            if (!flag)
            {
                cout<<"\nProduct NOT found!\n";
            }
        }
    }
}
void deleteProductByID (int id)
{
    if (head==nullptr)
    {
        cout<<"\nALERT : Cart is empty!\nNothing to delete for\n";
    }
    else
    {
        Node *temp=head;
        int i=0;
        bool flag=0;
        while (temp!=nullptr)
        {
            i++;
            if (temp->productID==id)
            {
                flag=1;
                delete_specified (i);
                break;
            }
            temp=temp->next;
        }
        if (!flag)
        {
            cout<<"\nProduct NOT found!\n";
        }
    }
}
void viewTotalBill ()
{
    cout<<"\n==================[ Total Bill ]================== \n";
    Node *temp=head;
    while (temp!=nullptr)
    {
        cout<<"\nID : "<<temp->productID<<", Name : "<<temp->productName<<", Qty : "<<temp->quantity<<", Total Price : "<<(temp->quantity)*(temp->pricePerUnit)<<" Rs."<<endl;
        temp=temp->next;
    }
    cout<<"\n";
}
void displayMenu ()
{
    cout<<"\n==================================== [ Shopping Cart ] ==================================== \n";
    cout<<"1.Create product\t     2.Display Cart (Forward)\t 3.Display Cart (Backward)\n";
    cout<<"4.Insert product at first    5.Insert product at last\t 6.Insert product at specified pos\n";
    cout<<"7.Delete first product\t     8.Delete last product\t 9.Delete pos specified product\n";
    cout<<"10.Count products in Cart    11.Search product by ID\t";
    cout<<" 12.Search product by position\n13.Delete product by ID\t     ";
    cout<<"14.View Total Bill\t         15.Checkout and empty Cart\n";
    cout<<"\nInput choice : ";
}
int main (void)
{
    int ch, ID, qty, pos;
    string s;
    double p;
    do
    {
        displayMenu ();
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\nInput product ID : ";
            cin>>ID;
            cout<<"\nInput product name : ";
            cin.ignore (); //clears input buffer
            getline (cin, s);
            cout<<"\nInput quantity : ";
            cin>>qty;
            cout<<"\nInput pricePerUnit (Rs.) : ";
            cin>>p;
            createNode (ID, s, qty, p);
            break;
        case 2:
            displayCartForward ();
            break;
        case 3:
            displayCartBackward ();
            break;
        case 4:
            cout<<"\nInput product ID : ";
            cin>>ID;
            cout<<"\nInput product name : ";
            cin.ignore ();
            getline (cin, s); //clears input buffer
            cout<<"\nInput quantity : ";
            cin>>qty;
            cout<<"\nInput pricePerUnit (Rs.) : ";
            cin>>p;
            insert_first (ID, s, qty, p);
            break;
        case 5:
            cout<<"\nInput product ID : ";
            cin>>ID;
            cout<<"\nInput product name : ";
            cin.ignore (); //clears input buffer
            getline (cin, s);
            cout<<"\nInput quantity : ";
            cin>>qty;
            cout<<"\nInput pricePerUnit (Rs.) : ";
            cin>>p;
            insert_last (ID, s, qty, p);
            break;
        case 6:
            cout<<"\nInput position at which product needs to be inserted : ";
            cin>>pos;
            cout<<"\nInput product ID : ";
            cin>>ID;
            cout<<"\nInput product name : ";
            cin.ignore ();
            getline (cin, s);
            cout<<"\nInput quantity : ";
            cin>>qty;
            cout<<"\nInput pricePerUnit (Rs.) : ";
            cin>>p;
            insert_specified (pos, ID, s, qty, p);
            break;
        case 7:
            delete_first ();
            break;
        case 8:
            delete_last ();
            break;
        case 9:
            cout<<"\nInput position at which product is to be deleted : ";
            cin>>pos;
            delete_specified (pos);
            break;
        case 10:
            cout<<"\nNo. of products in Cart : "<<listSize<<endl;
            break;
        case 11:
            cout<<"\nInput ID of product to be searched : ";
            cin>>ID;
            searchProductByID (ID);
            break;
        case 12:
            cout<<"\nInput position of product to be searched : ";
            cin>>pos;
            searchProductByPosition (pos);
            break;
        case 13:
            cout<<"\nInput ID of product to be deleted : ";
            cin>>ID;
            deleteProductByID (ID);
            break;
        case 14:
            viewTotalBill ();
            break;
        case 15:
        {
            if (head==nullptr)
            {
                cout<<"\nCart is already empty!\n";
            }
            else
            {
                Node *temp=head;
                while (temp!=nullptr)
                {
                    Node *nxt=temp->next;
                    delete temp;
                    temp=nxt;
                }
                head=rear=nullptr;
                cout<<"\nAll products deleted\n";
                listSize=0;
            }
            cout<<"\n======[Exiting the program...]======\n";
            exit (0);
            break;
        }
        default:
            cout<<"\nInput valid choice!\n";
        }
    }
    while (ch!=15);
    return 0;
}
