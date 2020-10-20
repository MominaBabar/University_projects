#include<iomanip>
#include<iostream>
#include <string> 
#include <sstream>
#include <stdlib.h>
#include <ctime>
using namespace std;
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
int rno = 1;
int tno = 1;
const char* aco = "10023";
int incre = 0;
struct transaction    //trasaction details (maxheap priority on amount)
{
	double amount;
	int tran_id;
	char type;
	string date;
};
class trie         //to store account no. (trie)
{
	public:
	trie* child[10]; 
    bool exist;
    public:
    trie()   
    {  
       exist = false; 
       for (int i = 0; i<10; i++)
       {
       	   child[i] = NULL; 
	   }
    } 
};
struct reciept               //reciept details (linked list)
{
	int receiptno;
	transaction* t; 
	reciept* next;
};
struct transactionsheap    // (maxheap)
{
	transaction* array[10];
	int front;
	int rear;
	int size;
	  public:
		transactionsheap()
		{
			front = rear = -1;
			size = 10;
			for(int i = 0; i<10; i++)
			{
				array[i] = NULL;
			}
		}
		void enqueue(transaction* x)
		{
			if (!isfull())
			{
				if(front==-1)
				{
					front=rear=0;
					array[front]=x;
				}
				else
				{
					rear++;
					array[rear]=x; 
					transaction* temp = NULL;
					int i=rear;
					int parent=(rear-1)/2;
					while(array[parent]->amount<array[i]->amount && parent>=0){
						temp=array[parent];
						array[parent]=array[i];
						array[i]=temp;
						i=parent;
						parent=(parent-1)/2;
					}
				}
			
		    }
    }
	transaction* dequeue()
	{
		transaction* x;
		if (!isempty())
		{
			if(rear==front)
			{
				x=array[front];
				front=rear=-1;
			}
			else
			{
				x=array[front]; 
				transaction* temp;
				array[front] = array[rear]; 
				rear--;
				int i=front; 
				while(((2*i+1)<=rear ||(2*i+2)<=rear) && (array[2*i+1]>array[i] || array[2*i+2]>array[i]) ){
					if(array[2*i+1]<array[2*i+2])
					{
						temp=array[i];
						array[i]=array[(2*i+1)];
						array[(2*i+1)]=temp;
						i=(2*i+1);
					}
					else
					{
						temp=array[i];
						array[i]=array[(2*i+2)];
						array[(2*i+2)]=temp;
						i=(2*i+2);
					}	
				}
			}
			return x;
		}
		else
		{
			cout << "\nno transactions made yet.\n";
			return NULL;
		}
    }
	transaction* Front()   //maximum value
	{
		return array[front];
	}
	bool isfull()
	{
		if(rear==size-1 and front == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isempty()
	{
		if(rear == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void displayalltransac()
	{
		cout<<"\nthe recent transactions are: \n";
		if (!isempty())
		{
			int i=front;
			while(i <=rear)
			{
				cout<<"\ntransaction amount:\n"<<array[i]->amount;
				cout<<"\ntransaction id:\n"<<array[i]->tran_id;
				cout<<"\ntransaction type:\n"<<array[i]->type;
				cout<<"\ntransaction date:\n"<<array[i]->date;
				cout<<"\n";
				i++;
			}
			cout<<"\ncompeleted.\n";
		}
		else
		{
			cout << "\nno recent transactions done.\n";
		}
	}
	void display_specifictran(transaction* t)
	{
		if(t!=NULL)
		{
			cout<<"\ntransaction amount:\n"<<t->amount;
		    cout<<"\ntransaction id:\n"<<t->tran_id;
		    cout<<"\ntransaction type:\n"<<t->type;
		    cout<<"\ntransaction date:\n"<<t->date;
		    cout<<"\n";	
		}
		else
		{
			cout<<"\nsuch a transaction does not exist.\n";
		}
		
	}
	transaction* searchtran()
	{
		cout<<"\nenter transaction id of trnasaction you want to view.\n";
		int x;
		cin>>x;
		for(int i = front; i<=rear; i++)
		{
			if(x==array[i]->tran_id)
			{
				return array[i];
			}
		}
		return NULL;
	}
};

class account    //accounts of customers (hashtable)
{
	public:
	string accountno;
	string password;
	string accountholder;
	long phone;
	long cnic;
	double balance;
	string type;
	reciept* first = NULL;
	reciept* last = NULL;
    transactionsheap history;
    account* next;
    public:
    void insertreciept(transaction* curr)
    {
    	reciept* r = new reciept();
    	rno++;
    	r->receiptno = rno;
    	r->t = curr;
    	r->next = NULL;
    	if(first==NULL)
    	{
    		first = r;
			last = r;
		}
		else
		{
			last->next = r;
    	    last = r;
		}
    }
    void delete_start()
    {
	   reciept* curr = first;
	   if(first->next==NULL)
	   {
		 first = NULL;
		 last = NULL;
		 delete curr;
		 cout<<"\nreciept list is empty now.\n";
	   }
	   else
	   {
		 first = first->next;
	     delete curr;
	   }
	
    }
    void delete_end()
    {
	  reciept *curr = first;
	  if(curr==last&& curr==first)
	  {
		first = NULL;
		last = NULL;
		delete curr;
		cout<<"\ndeleted. no reciepts left.\n";
	  }
	  else
	  {
	    while(curr->next!=last)
		{
			curr = curr->next;	
		}
	    delete last;
	    last = curr;
	    curr->next = NULL;
      } 
    }
    reciept* search()
    {
	   int value;
	   cout<<"\nenter reciept no. to be searched. \n";
	   cin>>value;
	   reciept* curr = first;
	   if(first==NULL)
	   {
		  cout<<"\nnoreciepts made. cannot search. \n";
		  return NULL;
	   }
	   else
	   {
	      bool p = false;
	      while(curr!=NULL)
	      {
		     if(curr->receiptno==value)
		     {
		 	    p = true;
		 	    break;
		     }
		     else
		     {
		 	    curr = curr->next;
		     }
	      }
	   
	   if(p)
	   {
	   	  cout<<"\nreciept found.\n\n";
	   	  return curr;
	   }
	   else
	   {
	   	  cout<<"\nreciept not found.\n\n";
	   	  return NULL;
	   }
    }
    }
void delete_specific(reciept* curr)
{
		reciept* temp = first;
		if(curr==first && first==last)
		{
			first = NULL;
			last = NULL;
			delete curr;
			cout<<"\ndeleted the receipt.\nreciept list now empty.\n";
		}
		else if(curr==first)
		{
			delete_start();
		}
		else if(curr==last)
		{
			delete_end();
		}
		else
		{
				while(temp->next!=curr)
	           {
	                 temp = temp->next;	
	           }
	
		       temp->next = curr->next;
		       delete curr;
	    }
	    cout<<"\nreceipt deleted.\n";
	
}
  
void displayallrec()
{
    if(first==NULL)
    {
    	cout<<"\nreciepts are made after transactions heap becomes full(greater than 10).\n your trnasactions are less so no reciepts exist currently.\n";
	}
    reciept* temp = first;
    int i = 1;
    while(temp!=NULL)
    {
    	cout<<"for recipt"<<i;
    	cout<<"\ntransaction amount:\n"<<temp->t->amount;
		cout<<"\ntransaction id:\n"<<temp->t->tran_id;
		cout<<"\ntransaction type:\n"<<temp->t->type;
		cout<<"\ntransaction date:\n"<<temp->t->date;
		cout<<"\n";
		i++;
		temp = temp->next;
	}
    cout<<"\ncompleted.\n";
}
void display_specific(reciept* temp)
{
  
   if(temp==NULL)
   {
   	 cout<<"\nreciept not found.\n";
   }
   else
   {
   	  
		cout<<"\n";
		cout<<"\ntransaction amount:\n"<<temp->t->amount;
		cout<<"\ntransaction id:\n"<<temp->t->tran_id;
		cout<<"\ntransaction type:\n"<<temp->t->type;
		cout<<"\ntransaction date:\n"<<temp->t->date;
		cout<<"\n";
   }
}
};

class bank     //main class
{
	public:
	account* accounts[10];                    //hashtable for accounts
	trie* accountnos = new trie();            //trie of account no.
   
   public:
account* createaccount()       //create new account
{
	account* a = new account();
	int b = atoi(aco)+ incre;
	string k = patch::to_string(b);
	a->accountno = k;
	incre++;
	cout<<"\nEnter The account password.: (a 4 digit combo)\n";
	cin>>a->password;
	cout<<"\nEnter The name of account holder. :\n";
	cin>>a->accountholder;
	cout<<"\nEnter The cnic of account holder :\n";
	cin>>a->cnic;
	cout<<"\nEnter The phone No. :\n";
	cin>>a->phone;
	cout<<"\nAsssigning complimentary balance of 100 to new account.\n";
	a->balance = 100;
	cout<<"\nEnter The type of account. (real, personal or nominal) :\n";
	cin>>a->type;
	a->history = transactionsheap();
	a->first = NULL;
	a->last = NULL;
	cout<<"\n\n\nAccount Created..\n";
	return a;
}
void displayaccount(account* a)  //display account
{
	if(a!=NULL)
	{
		  cout<<"\n////////////////////////////////////////////////////////\n";
	      cout<<"\n****Account No. :  "<<a->accountno<<"\n";
	      cout<<"\n****Name of account holder. :  "<<a->accountholder<<"\n";
	      cout<<"\n****Cnic of account holder :  "<<a->cnic<<"\n";
	      cout<<"\n****Phone No. :  "<<a->phone<<"\n";
	      cout<<"\n****Balance of account."<<a->balance<<"\n";
	      cout<<"\n****Type of account. :"<<a->type<<"\n";
	      cout<<"\n////////////////////////////////////////////////////////\n";
	}
	else
	{
		  cout<<"\naccount not found. try again later.\n";	
	}
		
	
}
void modify(account* a)   //modify account details
{
	if(a!=NULL)
	{
	   int res;
	   do
	   {
			
		
		cout<<"\npress 1 to modify name.\npress 2 to modify phone.\npress 3 to modify cnic.\npress 0 to exit.";
		
		cin>>res;
		switch(res)
		{
			case 1:
				cout<<"\nenter new account holder name.\n";
				cin>>a->accountholder;
				cout<<"\nmodified\n";
				break;
			case 2:
				cout<<"\nenter new phone no.\n";
				cin>>a->phone;
				cout<<"\nmodified\n";
				break;
			case 3:
				cout<<"\nenter new account holder cnic.\n";
				cin>>a->cnic;
				cout<<"\nmodified\n";
				break;
			case 0:
				cout<<"\nexiting\n";
				break;
			default:
				cout<<"\ninvalid choice.\n";
		}
	    }while(res!=0);
	}
	else
	{
		    cout<<"\naccount not found. try again later.\n";
		      
	}
}
void storeaccount(account* a)     //function to store record in hashtable
{
	int c = atoi(a->accountno.c_str()); 
	int index = c%10;
	//stroing account record
	if(accounts[index]==NULL) //first  value
	{
		accounts[index] = a;
	}
	else
	{
		account* temp = accounts[index];
		account* prev = NULL;
		while(temp!=NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = a;
	}
	cout<<"\naccount stored in database.\n";
	//storing accountno.
    newaccountno(a->accountno);  
	cout<<"\naccount no stored in database.\n";
}
void newaccountno(string x)      //insert
{
  	    trie* p = accountnos; 
        for (int i = 0; i < x.length(); i++) 
        { 
           int index = x[i] - '0'; 
           if (p->child[index]==NULL)
		   {
			  p->child[index] = new trie(); 
		   } 
           p = p->child[index]; 
        } 
        p->exist = true; 
}	        
void deleteaccount(account* a)       //function to delete account
{
	int r = atoi(a->accountno.c_str());
	int index1 = r%10;
	if(accounts[index1]==NULL) 
	{
		cout<<"\naccount not found.\n cannot remove.\n";
	}
	else
	{
		account* temp = accounts[index1];
		if(temp->accountno==a->accountno)
		{
			
			deleteaccountno(a->accountno);
			cout<<"\naccount no removed from database.\n";
			accounts[index1] = accounts[index1]->next;
			delete temp;
			cout<<"\naccount removed from database.\n";
			//delete accountno
		    
			
		}
		else
		{
			account* prev = NULL;
		    while(temp!=NULL && temp->accountno!=a->accountno)
		    {
			    prev = temp;
			    temp = temp->next;
		    }
		    if(temp==NULL)
		    {
		    	cout<<"\naccount does not exist.\ncannot remove.\n";
			}
			else
			{
				//delete accountno
		        deleteaccountno(a->accountno);
				cout<<"\naccount removed from database.\n";
				prev->next = temp->next;
				delete temp;
				cout<<"\naccount removed from database.\n";
				
				
			}
		    
		 }
		
	}
}
void showaccountnos(trie* r, char x[], int level) 
{ 
    if (r->exist==true)  
    { 
        x[level] = '\0'; 
        cout<<"account no: "<<x<<"\n"; 
    } 
    int i; 
    for (i = 0; i < 10; i++)  
    { 
        if (r->child[i]!=NULL)  
        { 
            x[level] = i + '0';
            showaccountnos(r->child[i], x, level + 1); 
        } 
    } 
} 
void deleteaccountno(string key) 
{ 
    trie* p = accountnos;
    for(int i = 0; i< key.length(); i++)
    {
     	p = p->child[key[i]-'0'];
	}
	p->exist = false;
} 
bool isEmpty(trie* root) 
{ 
    for (int i = 0; i < 10; i++)
    {
    	if (root->child[i]!=NULL)
        {
        	return false; 
		} 
	}
	return true;
           
}
account* login()
{
	cout<<"\n---LOGIN---\n";
	cout<<"\nenter account no of account you want to login to.\n";
	string x;
	cin>>x;
	account* a = searchaccount(x);
	if(a!=NULL)
	{
		cout<<"\naccount found. enter 4 digit pin.\n";
		string x;
		cin>>x;
		if(x==a->password)
		{
			return a;
		}
		else
		{
			cout<<"\ninvalid pin.\n could not log in.\n";
			return NULL;
		}
	}
	else
	{
		cout<<"\naccount does not exist. make account by \"creating account \"\n";
		return NULL;
	}
}	
account* searchaccount(string x)
{
	if(isEmpty(accountnos))
	{
		cout<<"\nno accounts to search from.\n";
		return NULL;
	}
	else
	{
		
	if(accountexists(x))
	{
		int y = atoi(x.c_str());
		int index = y%10;
	    account* temp = accounts[index];
	    while(temp!=NULL && temp->accountno!=x)
	    {
		   temp = temp->next;
	    }
	    return temp;
	}
	else
	{
		return NULL;
	}
    }
	
}
bool accountexists(string x)  //search
{
	trie* p = accountnos; 
    for (int i = 0; i < x.length(); i++) 
    { 
        int index = x[i] - '0'; 
        if (p->child[index]==NULL)
		{
			return false;
		} 
        p = p->child[index]; 
    } 
    if(p != NULL && p->exist)
    {
    	return true;
	}
	else
	{
		return false;
	}
	
} 
void displayall()   //function to display all account details
{
	account* a;
	if(isEmpty(accountnos))
	{
		cout<<"\nno accounts to display.\n";
	}
	else
	{
		for(int i = 0; i<10; i++)
	   {
		a = accounts[i];
	    while(a!=NULL)
	    {
	      cout<<"\n////////////////////////////////////////////////////////\n";
	      cout<<"\nAccount No. :  "<<a->accountno<<"\n";
	      cout<<"\nName of account holder. :  "<<a->accountholder<<"\n";
	      cout<<"\nCnic of account holder :  "<<a->cnic<<"\n";
	      cout<<"\nPhone No. :  "<<a->phone<<"\n";
	      cout<<"\nBalance of account."<<a->balance<<"\n";
	      cout<<"\nType of account. :"<<a->type<<"\n";
		  a = a->next;
	    }
	   }
	   cout<<"\n////////////////////////////////////////////////////////\n";
	   cout<<"\nall accounts displayed.\n";
	}
	
    
}	       
};

void accountsmenu();
void transactionsmenu();
void recieptsmenu();
bank* b = new bank();
int main()
{
	int ch;
	cout<<"\n-----BANK MANAGEMENT SYSTEM-----\n";
	cout<<"\n\nMADE BY :\n\nMomina Babar SP17-BCS-085\n";
	cout<<"\nNeelam Waqar SP17-BCS-091\n";
	cout<<"\n\nwelcome!\n\n";
	do
	{
		
		
		cout<<"\n----MAIN MENU-----\n";
		cout<<"\npress 1 for accounts menu.\n";
		cout<<"\npress 2 to make a transaction.\n";
		cout<<"\npress 3 to get receipts of any transaction.\n";
		cout<<"\npress 4 to exit.\n";
		cout<<"\nSelect Your Option (1-4)\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			accountsmenu();
			break;
		case 2:
			transactionsmenu();
			break;
		case 3:
			recieptsmenu();
			break;
		case 4:
		    cout<<"\n----exiting system.----\n"; 
			break;
		 default :
		    cout<<"\\invalid option selection.\ntryagain.\n\n";
		}
	}while(ch!=4);
	return 0;
}
void accountsmenu()
{
	int res;
	account* a;
	char x[10];
	do
	{
	    cout<<"----ACCOUNTS MENU----\n";
	    cout<<"\npress 1 to create new account.\n";
	    cout<<"\npress 2 to modify already existing account.\n";
	    cout<<"\npress 3 to delete your account.\n";
	    cout<<"\npress 4 to display your acccount details.\n";
	    cout<<"\npress 5 to display all account details.\n";
	    cout<<"\npress 6 to display all valid account no.s\n";
		cout<<"\npress 7 to go back to main menu.\n";
		cin>>res;
		switch(res)
		{
		case 1:
			a = b->createaccount();
			b->storeaccount(a);
			cout<<"\nACCOUNT DETAILS:\n";
			b->displayaccount(a);
			break;
		case 2:
			cout<<"\nlogin to account you want to modify.\n";
			a = b->login();
			if(a==NULL)
			{
				cout<<"\naccount does not exist or invalid login.\n";
			}
			else
			{
				b->modify(a);
			}
			break;
		case 3:
			cout<<"\nlogin to account you want to delete.\n";
			a = b->login();
			if(a==NULL)
			{
				cout<<"\naccount does not exist or invalid login.\n";
			}
			else
			{
				b->deleteaccount(a);
			}
			break;
		
		case 4:
			cout<<"\nlogin to account you want to view.\n";
			a = b->login();
			if(a==NULL)
			{
				cout<<"\naccount does not exist or invalid login.\n";
			}
			else
			{
				b->displayaccount(a);
			}
			
			break;
		case 5:
			b->displayall();
			break;
		case 6:
			if(b->isEmpty(b->accountnos))
			{
				cout<<"\nno accounts exist currently.\n";
			}
			else
			{
				b->showaccountnos(b->accountnos,x,0);
			}
			
			break;
		case 7:
		    cout<<"\n----going back to main menu.----\n"; 
			break;
		 default :
		    cout<<"\\invalid option selection.\ntryagain.\n\n";
		}
	}while(res!=7);
	
}
void transactionsmenu()
{
	int res;
	transaction* t;
	double j = 1;
	transaction* temp;
	cout<<"\n----TRANSACTION MENU----\n";
	cout<<"\nlogin to you account to make transactions\n";
	account* a = b->login();
	if(a!=NULL)
	{
		cout<<"\nlogged in.\n";
		for(int i = 0; i<18; i++)
		{
			temp = new transaction();
			temp->tran_id = tno;
			tno++;
			temp->amount = j;
		    if(j<=10)
		  {
			j = j+10;
			temp->type = 'c';
			temp->date = "11-12-2019";
			a->balance = a->balance+temp->amount;
		  }
		  else
		  {
			j = j+4;
			temp->type = 'c';
			temp->date = "05-04-2017";
			a->balance = a->balance+temp->amount;
		  }
		  a->history.enqueue(temp);
		}
	do
	{
		
	    cout<<"----MENU----\n";
	    cout<<"\npress 1 to make new transaction.\n";
	    cout<<"\npress 2 to view all recent transactions.\n";
		cout<<"\npress 3 to view last transaction.\n";
		cout<<"\npress 4 to view any recent transaction.\n";
		cout<<"\npress 5 to go back to main menu.\n";
		cin>>res;
		switch(res)
		{
		    case 1:
		    	while(true)
		    	{
		    		if(!a->history.isfull())
		    	{
		    		t = new transaction();
		    		cout<<"\nenter transaction amount:\n";
					cin>>t->amount;
		            cout<<"\ntransaction id:\n";
					t->tran_id = tno;
					tno++;
					cout<<t->tran_id;
					cout<<"\ntransaction date:\n";
					t->date = "14-01-2019";
					cout<<t->date;
					int p = 0;
					while(true)
					{
						cout<<"\nenter transaction type: (type w for withdrawing and c for crediting amount)\n";
					    cin>>t->type;
		    		    if(t->type=='w' || t->type=='W')
		    		    {
		    			   p = 1;
		    			   break;
					    }
					    else if(t->type=='c' || t->type=='C')
		    		    {
		    			  p = 2;
		    			  break;
					    }
					    else
					    {
						  cout<<"\ninvalid type enter again.\n";
					    }
					}
					if(p==1)
					{
						while(t->amount>a->balance)
						{
							cout<<"\ncannot withdraw.\nbalance is: "<<a->balance<<"\nrequired amount is: "<<t->amount<<"\n\ninvalid. enter a valid amount.\n";
		                    cin>>t->amount;
						}
					}
		            a->history.enqueue(t);
		            cout<<"\ntransaction successful\n";
		            cout<<"\nnew balance is: "<<a->balance<<" .\n";
		    		break;
				}
				else
		        {
			         while(!a->history.isempty())
			         {
				        t = a->history.dequeue();
				        a->insertreciept(t);
				        
			         }
			         cout<<"\n***************************************************************************\n";
			         cout<<"\nTransaction history was full. therefore, they have been made into reciepts.\n";
			         cout<<"\ncurrent balance is: "<<a->balance<<" .\n";
			         cout<<"\n***************************************************************************\n";
		        }
				}
		    	
			   break;
		    case 2:
			   a->history.displayalltransac();
			   break;
		    case 3:
			   a->history.display_specifictran(a->history.Front());
			   break;
			case 4:
			   t = a->history.searchtran();
			   a->history.display_specifictran(t);
			   break;
		    case 5:
		       cout<<"\n----going back to main menu.----\n"; 
			   break;
		    default :
		       cout<<"\\invalid option selection.\ntryagain.\n\n";
		}
	}while(res!=5);
	}
	else
	{
		cout<<"\ninvalid account.\ngoing back to main menu...\n";
	}
	
}
void recieptsmenu()
{
	int res;
	reciept* r1;
	reciept* r2;
	cout<<"\n----RECIPT MENU----\n";
	cout<<"\nlogin to you account to get reciepts\n";
	account* a = b->login();
	if(a!=NULL)
	{
		cout<<"\nlogged in.\n";
	do
	{
	    cout<<"\n----MENU----\n";
	    cout<<"\npress 1 to get reciept of last transaction.\n";
	    cout<<"\npress 2 to get reciepts of all transactions.\n";
	    cout<<"\npress 3 to display specific reciept.\n";
		cout<<"\npress 4 to delete a specific reciept.\n";
		cout<<"\npress 5 to go back to main menu.\n";
		cin>>res;
		switch(res)
		{
		    case 1:
			   a->display_specific(a->last);
			   break;
		    case 2:
			   a->displayallrec();
			   break;
			case 3:
			    r1 = a->search();
		    	if(r1==NULL)
		    	{
		    		cout<<"\ncannot delete.\n";
				}
				else
				{
					a->display_specific(r1);
				}
			   break;
		    case 4:
		    	r2 = a->search();
		    	if(r2==NULL)
		    	{
		    		cout<<"\ncannot delete.\n";
				}
				else
				{
					a->delete_specific(r2);
				}
			   
			   break;
		    case 5:
		       cout<<"\n----going back to main menu.----\n"; 
			   break;
		    default :
		       cout<<"\\invalid option selection.\ntryagain.\n\n";
		}
	}while(res!=5);
	}
	else
	{
		cout<<"\ninvalid account.\ngoing back to main menu...\n";
	}
	
}





  
//***************************************************************
//    			END OF PROJECT
//***************************************************************
