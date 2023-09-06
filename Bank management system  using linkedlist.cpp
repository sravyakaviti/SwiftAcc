#include <iostream>
#include <string>
using namespace std;
int length;
class node
{
public:
    float val;
    float cash;
    float phn;
    string email;
    string name;
    string lname;
    int id;

    node *next;
};

class bank //new class
{
private:
    node *head; //first node

public:
    bank()
    {
        head = NULL; //initial address of first node
    }

    void openAccount();
    void displayDetails();
    void insertData();
    void deleteAccount();
    void deposit(int);
    void withdrawal(int);
    void update();
    void search();
    void listing();
};

void bank::openAccount()
{
    node *temp = NULL;
    node *p = NULL;
    float no, ca, ph;
    int ch1 = 1, ID;
    string na;
    string lna;
    string em;
    while (ch1 == 1)
    {
        cout << "\nEnter index= ";
        cin >> no;
        cout << "\nEnter name= ";
        cin >> na;
        cout << "\nEnter last name= ";
        cin >> lna;
        cout << "\nEnter phone number= ";
        cin >> ph;
        cout << "\nEnter email id= ";
        cin >> em;
        cout << "\nEnter account id= ";
        cin >> ID;
        cout << "\nEnter expected cash(in Rupees)= ";
        cin >> ca;
        if (head == NULL)
        {
            head = new node;
            head->val = no;
            head->cash = ca;
            head->name = na;
            head->lname = lna;
            head->id = ID;
            head->phn = ph;
            head->email = em;
            head->next = NULL;
            p = head;
        }
        else
        {
            temp = new node;
            temp->val = no;
            temp->cash = ca;
            temp->name = na;
            temp->lname = lna;
            temp->phn = ph;
            temp->id = ID;
            temp->email = em;
            temp->next = NULL;
            p->next = temp;
            p = temp;
        }
        length++;
        cout << "Press 1 to enter again= ";
        cin >> ch1;
    }
}

void bank::displayDetails()
{
    node *p = head;
    if (head == NULL)
    {
        cout << "\nThere is no data found!!";
    }
    else
    {
        cout << "\nBank Account Management System\n";
        while (p != NULL)
        {
            cout << "AccountHolder " << p->val << endl;
                cout  << "Lname: " << p->lname << endl;
                cout << "Name: " << p->name << endl;
                cout << "Phone number: " << p->phn << endl;
                cout << "Account id: " << p->id << endl;
                cout << "Email id: " << p->email << endl;
                cout << "Cash in account: Rs. " << p->cash << "\n";
            p = p->next;
        }
        cout << "\nTotal AccountHolders= " << length<<endl;
    }
}

void bank::insertData()
{
    float no, ca, ph;
    int id;
    string na, em, lna;
    node *temp = new node;
    cout << "\nEnter index = ";
    cin >> no;
    cout << "\nEnter name= ";
    cin >> na;
    cout << "\nEnter last name= ";
    cin >> lna;
    cout << "\nEnter phone number= ";
    cin >> ph;
    cout << "\nEnter email id= ";
    cin >> em;
    cout << "\nEnter account id= ";
    cin >> id;
    cout << "\nEnter your cash(in Rupees)= ";
    cin >> ca;
    temp->val = no;
    temp->cash = ca;
    temp->name = na;
    temp->lname = lna;
    temp->phn = ph;
    temp->email = em;
    temp->id = id;
    temp->next = head;
    head = temp;
    length++;
}

void bank::deposit(int id)
{
    node *current = head;
    int amt;
    bool found = false;

    if (head == NULL)
    {
        cout << "Data is not found" << endl;
        return;
    }

    cout << "Enter account id: ";
    cin >> id;

    while (current != NULL)
    {
        if (current->id == id)
        {
            found = true;
            break;
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "Account not found." << endl;
        return;
    }

    cout << "Enter amount you want to deposit: ";
    cin >> amt;

    if (amt <= 0)
    {
        cout << "Invalid deposit amount." << endl;
        return;
    }

    current->cash += amt;
    cout << "After deposit, your total amount in account is " << current->cash << endl;
}


void bank::withdrawal(int id)
{
    node *current = head;
    int amt;
    bool found = false;

    if (head == NULL)
    {
        cout << "Data is not found" << endl;
        return;
    }

    cout << "Enter account id: ";
    cin >> id;

    while (current != NULL)
    {
        if (current->id == id)
        {
            found = true;
            break;
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "Account not found." << endl;
        return;
    }

    cout << "Enter amount you want to withdraw: ";
    cin >> amt;

    if (amt <= 0 || amt > current->cash)
    {
        cout << "Invalid withdrawal amount or insufficient balance." << endl;
        return;
    }

    current->cash =  current->cash - amt;
    cout << "After withdrawal, your total amount in account is " << current->cash << endl;
}

void bank::deleteAccount()
{
    if (head == NULL)
    {
        cout << "\nNo account to delete." << endl;
        return;
    }

    int id;
    cout << "\nEnter the account id to delete: ";
    cin >> id;

    if (id <= 0)
    {
        cout << "Invalid account id." << endl;
        return;
    }

    node *p = head;
    node *prev = nullptr;

    while (p != nullptr && p->id != id)
    {
        prev = p;
        p = p->next;
    }

    if (p == nullptr)
    {
        cout << "\nAccount not found." << endl;
        return;
    }

    if (prev == nullptr)
    {
        head = head->next;
        delete p;
    }
    else
    {
        prev->next = p->next;
        delete p;
    }

    cout << "\nAccount deleted successfully!!" << endl;
}

void bank::update()
{
    int new_id;
    float new_no, new_ca, new_ph;
    string new_na;
    string new_lna;
    string new_em;
    int i, pos;
    string new_name;
    node *p = head;
    node *temp = new node;
    cout << "Enter the position after which you want to update the Details of your account: ";
    cin >> pos;

    if (pos > length)
    {
        cout << "\nWRONG POSITION ENTERED!!";
    }
    else if (pos == length)
    {
        cout << "\nNO NODE IS PRESENT AFTER THE POSITION YOU ENTERED!!";
    }
    else
    {
        for (i = 1; i < pos - 1; i++)
        {
            p = p->next;
        }
        cout << "\nEnter index = ";
        cin >> new_no;
        cout << "\nEnter name= ";
        cin >> new_na;
        cout << "\nEnter last name= ";
        cin >> new_lna;
        cout << "\nEnter phone number= ";
        cin >> new_ph;
        cout << "\nEnter email id= ";
        cin >> new_em;
        cout << "\nEnter account id= ";
        cin >> new_id;
        cout << "\nEnter cash in account(in Rupees)= ";
        cin >> new_ca;

        temp->val = new_no;
        temp->cash = new_ca;
        temp->name = new_na;
        temp->lname = new_lna;
        temp->phn = new_ph;
        temp->email = new_em;
        temp->id = new_id;
        temp->next = p->next;
        p->next = temp;

        cout << "\nACCOUNT UPDATED SUCCESSFULLY!!!";
        cout << "\n\n UPDATED DETAILS \n";
    }
}

void bank::search()
{
    int id;
    int flag = 0;
    node *p = head;
    cout << "Enter the id you want to search = ";
    cin >> id;

    while (p != NULL)
    {
        if (p->id == id)
        {
            flag = 1;
            break;
        }
        p = p->next;
    }

    if (flag == 0)
    {
        cout << "\nID NOT FOUND!!!" << endl;
    }
    else
    {
        cout << "\n-------------DETAILS OF THE ACCOUNT HOLDER \n";
        cout << "\n";
             
              cout << "AccountHolder " << p->val << endl;
                cout  << "Lname: " << p->lname << endl;
                cout << "Name: " << p->name << endl;
                cout << "Phone number: " << p->phn << endl;
                cout << "Account id: " << p->id << endl;
                cout << "Email id: " << p->email << endl;
                cout << "Cash in account: Rs. " << p->cash << "\n";
    }
}

void bank::listing()
{
    int arr1[100000];
    int arr2[100000];
    string arr3[100000];
    string arr4[100000];
    float arr5[100000];
    string arr6[100000];
    int arr7[100000];
    int i = 0;
    node *p = head;

    while (p != NULL)
    {
        arr1[i] = p->val;
        arr2[i] = p->cash;
        arr3[i] = p->name;
        arr4[i] = p->lname;
        arr5[i] = p->phn;
        arr6[i] = p->email;
        arr7[i] = p->id;

        p = p->next;
        i++;
    }

    for (i = 0; i < length; i++)
    {
        cout << "AccountHolder " << arr1[i] << arr2[i] << "\tEmail: "
             << " \tName: " << arr3[i] << "\tLast name " << arr4[i]
             << " \tPhone number: " << arr5[i] << "\tCash in account= Rs. " << arr6[i]
             << "\tAccount id: " << arr7[i] << endl;
    }

    cout << "\nTotal account holders are= " << length;
}

int main()
{
    bank l1;
    int ch, no, choice, m, n;
    cout << "\n BANK MANAGEMENT SYSTEM ";
    cout << "\nPress 1 to start= ";
    cin >> ch;

    while (ch == 1)
    {
        cout << "\n MENU ";
        cout << "\n1. Open Account\n2. Display Details\n3. Insert Data\n4. Deposit\n5. Withdrawal\n6. Delete Account\n7. Update\n8. Search\n9. Listing\n";
        cout << "\nEnter your choice= ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            l1.openAccount();
            break;
        case 2:
            l1.displayDetails();
            break;
        case 3:
            cout << "\nInsert your data here.";
            l1.insertData();
            l1.displayDetails();
            break;
        case 4:
            int id;
            l1.deposit(id);
            break;
        case 5:
            l1.withdrawal(id);
            break;
        case 6:
            cout << "\nDelete an Account\n" << endl;
            l1.deleteAccount();
            l1.displayDetails();
            break;
        case 7:
            l1.update();
            break;
        case 8:
            l1.search();
            break;
        case 9:
            l1.listing();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Press 1 to continue or any other key to exit: ";
        cin >> ch;
    }

    return 0;
}

	
