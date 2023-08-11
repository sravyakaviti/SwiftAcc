#include<iostream>
#include<string>

using namespace std;
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
		
		node * next;
};

class bank //new class
{
	private:
		node * head; //first node
	public:
		int length = 0;
		bank()
	{
	head = NULL; //initial address of first node
	}
void openAccount();
void displayDetails();
void insertData();
void deleteAccount();
void deposite(int );
void withdrawal(int );
void update();
void search();
void listing();

};
void bank::openAccount() 
{
	node*temp = NULL;
	node*p = NULL;
	float no,ca,ph;
	int ch1=1,ID;
	string na;
	string lna;
	string em;
	while(ch1==1)
	{
	cout<<"\nEnter index= ";
	cin>>no;
	cout<<"\nEnter name= ";
	cin>>na;
	cout<<"\nEnter last name= ";
	cin>>lna;
	cout<<"\nEnter phone number= ";
	cin>>ph;
	cout<<"\nEnter email id= ";
	cin>>em;
	cout<<"\nEnter account id= ";
	cin>>ID; 
	cout<<"\nEnter expected cash(in Rupees)= ";
	cin>>ca;
	if(head==NULL)
	{
	head = new(node);
	head ->val = no;
	head -> cash=ca;
	head -> name= na;
	head -> lname= lna;
	head -> id= ID;
	head ->phn=ph;
	head ->email=em;
	head -> next = NULL;
	p = head;
	length++;
	}
else
{
	temp = new(node);
	temp -> val = no;
	temp -> cash=ca;
	temp -> name= na;
	temp -> lname= lna;
	temp -> phn=ph;
	temp -> id= ID;
	temp ->email=em;
	temp -> next = NULL;
	p -> next = temp;
	p = temp; length++;
}
cout<<"Press 1 to enter again= "; cin>>ch1;
}//while closed
}//function closed

void bank::displayDetails() //to display linked list
{
	node *p = NULL; p=head;
	if(head==NULL) //condition to check if list is empty or not
{
	cout<<"\nThere is no data found!!";
}
else
{
	cout<<"\nBank Acoount Management System\n";
	while(p!=NULL)
{
	cout<<"AccountHolder "<<p->val<<" -> "<<"Lname: "<<p->lname<<"->"<<"Name: "<<p->name<<" -> "<<"Phone number: "<<p->phn<<" -> "<<"Account id: "<<p->id<<"->"<<"Email id: "<<p->email<<" -> "<<"Cash in account: Rs. "<<p -> cash<<"\n";
	p=p->next;
}//while closed
	cout<<"\nTotal AccountHolders= "<<length;
}//else closed
}//function closed
void bank::insertData() 
{
	int id;
	float no,ca,ph;
	string na; string em; string lna;
	node *temp = NULL;
	temp = new(node);
	cout<<"\nEnter index = "; cin>>no;
	cout<<"\nEnter name= "; cin>>na;
		cout<<"\nEnter last name= "; cin>>lna;
	cout<<"\nEnter phone number= "; cin>>ph;
	cout<<"\nEnter email id= "; cin>>em;
	cout<<"\nEnter account id= "; cin>>id;
	cout<<"\nEnter your cash(in Rupees)= "; cin>>ca;
	temp -> val = no;
	temp -> cash=ca;
	temp -> name= na;
	temp -> lname= lna;
	temp -> phn=ph;
	temp ->email=em;
	temp ->id=id;
	temp->next=NULL;
	temp->next=head;
	head=temp;
	length++;
	cout<<"\nNEW ACCOUNT CREATED SUCCESFULLY";
}//function closed
void bank::deposite(int id)
{
	node*current=head;
	int amt;
	bool found=false;
	
	if(head==NULL)
	{
		cout<<"Data is not found"<<endl;
	}
	else{
		while(current!=NULL)
		{
			int nid;
			cout<<"Enter account id"<<endl;
			cin>>nid;
			if(current->id==nid)
			{
				found=true;
				break;
			}
			current=current->next;
			
		}
	}
	if(found)
	{
		cout<<"Enter amount you want to deposite"<<endl;
		cin>>amt;
		int total=current->cash+amt;
		cout<<"After deposition your total amount in account is "<<total<<endl;
	}
}
void bank::withdrawal(int id)
{
	node*current=head;
	int amt;
	bool found=false;
	
	if(head==NULL)
	{
		cout<<"Data is not found"<<endl;
	}
	else{
		while(current!=NULL)
		{
			int nid;
			cout<<"Enter account id"<<endl;
			cin>>nid;
			if(current->id==nid)
			{
				found=true;
				break;
			}
			current=current->next;
			
		}
	}
	if(found)
	{
		cout<<"Enter amount you want to withdraw"<<endl;
		cin>>amt;
		int total=current->cash-amt;
		cout<<"After withdrawal your total amount in account is "<<total<<endl;
	}
}
void bank::deleteAccount() 
{
	node *p=NULL;
	p=head;
	head=head->next;
	delete(p);
	length--;
	cout<<"\n	Account is deleted successfully!!!\n";
}//function closed

void bank::update() 
{
	int new_id;
	float new_no,new_ca,new_ph;
	string new_na;
	string new_lna;
	string new_em;
	int i,pos;
	string new_name;
	node *p = NULL;
	p = head;
	node *temp = NULL;
	temp = new(node);
		cout<<"Enter the position after which you want to update the Details of your = ";
	cin>>pos;
	if(pos>length)
	{
		cout<<"\nWRONG POSITION ENTERED!!";
	}
	else if(pos==length)
	{
		cout<<"\nNO NODE IS PRESENT AFTER THE POSITION YOU ENTERED!!";
	}
	else
	{
	for(i=1;i<pos-1;i++)
	{
		p = p->next;
	}
		cout<<"\nEnter index = ";
		cin>>new_no; cout<<"\nEnter name= ";
		cin>>new_na;
		cin>>new_no; cout<<"\nEnter last name= ";
		cin>>new_lna;
		cout<<"\nEnter phone number= ";
		cin>>new_ph;
		cout<<"\nEnter email id= ";
		cin>>new_em;
		cout<<"\nEnter account id= ";
		cin>>new_id;
		cout<<"\nEnter  cash in account(in Rupees)= ";
		cin>>new_ca;
		temp->val=new_no;
		temp -> cash=new_ca;
		temp -> name= new_na;
		temp -> lname= new_lna;
		temp -> phn=new_ph;
		temp->email=new_em;
		temp->id=new_id;
		temp -> next = NULL;
		p -> next = temp;
		p = temp;
		cout<<"\nACCOUNT  UPDATED SUCCESSFULLY!!!";
		cout<<"\n\n UDPATED DETAILS \n";
	}
}//function closed
void bank::search() 
{
	int id; string na; string lna;
	int flag=0;
	node *p= NULL;
	p =head;
	cout<<"Enter the id you want to search = ";
	cin>>id;
	while(p!=NULL)
	{
	if(p->val==id)
	{
	flag=1;
	break;
	}
	p=p->next;
	}
	if(flag==0)
	{
	cout<<"\nID NOT FOUND!!!\n";
	}
	else
	{
	cout<<"\n-------------DETAILS OF THE ACCOUNT HOLDER \n";
	cout<<"\n"<<"AccountHolder "<<p->val<<" -> "<<"Lname: "<<p->lname<<" ->"<<"Name: "<<p->name<<" ->"<<"Phone number: "<<p->phn<<" -> "<<"Account id: "<<p->id<<" ->"<<"Email id: "<<p->email<<" -> "<<"Cash in account: Rs. "<<p -> cash<<"\n";
	}
}//function closed
void bank::listing() //converting the list into an array
{
int arr1[length];
int arr2[length];
string arr3[length];
string arr4[length];
float arr5[length];
string arr6[length];
int arr7[length];
int i=0; node*p=head; 
while(p!=NULL)
{
arr1[i]=p->val;
arr2[i]=p->cash;
arr3[i]=p->name;
arr4[i]=p->lname;
arr5[i]=p->phn;
arr6[i]=p->email;
arr7[i]=p->id;

p=p->next;
i++;
}
for(i=0;i<length;i++)
{
cout<<"AccountHolder "<<arr1[i]<<arr2[i]<<"\tEmail: "<<" \tName: "<<arr3[i]<<"\tLast name "<<arr4[i]<<" \tPhone number: "<<arr5[i]<<"\tCash in account= Rs. "<<arr6[i]<<"\tAccount id"<<arr7[i]<<endl;
}
cout<<"\nTotal account holder are= "<<length;
}//function closed
 
int main()
{
bank l1;
//object is declared
int ch,no,choice,m,n;
cout<<"\n BANK MANAGEMENT SYSTEM ";
cout<<"\nPress 1 to start= ";
cin>>ch;
while(ch==1)
{
cout<<"\n MENU ";
cout<<"\n1.openAccount\n2.DisplayDetails\n3.InsertData\n4.Deposite\n5.withdrawal \n6.DeleteAccount\n7.Update\n8.Search\n9.Listing\n";
cout<<"\nEnter your choice= ";
cin>>choice;
switch(choice) //switch case
{
case 1:
l1.openAccount(); //createlist function is called
break;
case 2:
l1.displayDetails(); //display function is called break;
case 3:
cout<<"\n insert your data here."; 


l1.insertData();

 l1.displayDetails();

 break;
 case 4:

int id;
 l1.deposite(id); 

 break;
 
  case 5:

 l1.withdrawal(id);

 break;


case 6:

cout<<"\nDelete an Account\n"<<endl;

l1.deleteAccount(); //deletefirst is called
l1.displayDetails();
break;
case 7:
l1.update(); 
break;
case 8:
l1.search(); //search function is called
break;
case 9: l1.listing(); //listing function is called
break;
}//switch closed
}
while(choice<=10); //do-while closed
return 0;
}

	
