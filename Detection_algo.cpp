#include <iostream>

using namespace std;

int n,m;
bool allfinished(bool f[]);

int main()
{
	cout<<"\n------DETECTION ALGORITHM------\n";
	cout<<"\nenter no. of processses: ";
	cin>>n;
	cout<<"\nenter no. of types of resources: ";
	cin>>m;
	
	int allocated[n][m]; // = {{0,1,0},{2,0,0},{3,0,3},{2,1,1},{0,0,2}};
	int max[n][m];// = {{0,1,0}, {4,0,2},{3,0,4},{3,1,1},{0,0,4}};
	int instance[m];// = {7,2,6};
	int available[m];
	int need[n][m];
	int safeseq[n];
	bool finished[n];
	for(int i = 0; i<n; i++)
	{
		finished[i] = false;
	}
	cout<<"\nenter maximum instances of each resource type: \n";
	for(int i = 0; i<m; i++)
	{
		cout<<"\nfor resource type "<<i+1<<": ";
		cin>>instance[i];
	}
	cout<<"\nenter maximum demand of each process: \n";
	for(int i = 0; i<n; i++)
	{
		cout<<"\nfor process no.: "<<i+1<<"\n";
		for(int j = 0; j<m; j++)
		{
			cout<<"\nenter maximum demand of resource type "<<j+1<<": "; 
			cin>>max[i][j];
		}
	}
	cout<<"\nenter allocated resources for each process: \n";
	for(int i = 0; i<n; i++)
	{
		cout<<"'nfor process no.: "<<i+1<<"\n";
		for(int j = 0; j<m; j++)
		{
			cout<<"\nenter no. of allocated resources of resource type "<<j+1<<": "; 
			cin>>allocated[i][j];
		}
	}
	cout<<"MAX DEMAND: \n";
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{ 
			cout<<max[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"ALLOCATED: \n";
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{ 
			cout<<allocated[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\ncalculating need of each process: \n";
	cout<<"NEED: \n";
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{ 
			need[i][j] = max[i][j] - allocated[i][j];
			cout<<need[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\nfinding available resources of each resource type...\n";
	int used[m];
	int sum;
	for(int i = 0; i<m; i++)
	{
		sum = 0;
		for(int j = 0; j<n; j++)
		{ 
			sum+=allocated[j][i];
		}
		used[i] = sum;
		cout<<used[i]<<" ";
	}
	cout<<"\n";
	cout<<"AVAILABLE: \n";
	for(int j = 0; j<m; j++)
    { 
	   available[j] = instance[j] - used[j];
	   
	   cout<<available[j]<<"\n";
    }
    int work[m];
    for(int i = 0; i<m; i++)
    {
    	work[i] = available[i];
	}
	int i = 0;
	int iter = 0; 
	int  j = 0;
	bool check = false;
	int ss = 0;
	while(!allfinished(finished))
	{
		check = false;
		if(finished[i]==false)
		{
			for(int j = 0; j<m; j++)
		{
				if(need[i][j]>work[j])
				{
					cout<<"\ncannot be statisfy need. move to next.\n";
					check = false;
					break;
				}
				else
				{
					check = true;
				}
		}
		if(check)
		{
			   finished[i] = true;
			   iter = 0;
			   cout<<"P"<<i+1<<"executed.\n";
			   safeseq[ss] = i;
			   ss++;
			   cout<<"\ntaking allocated resources back...\n";
			   for(int l = 0; l<m; l++)
			   {
			   	 cout<<allocated[i][l]<<" ";
			   }
			   cout<<"\n";
			   for(int l = 0; l<m; l++)
			   {
			   	 cout<<work[l]<<" ";
			   }
			   cout<<"\n";
			   cout<<"--------\n";
			   for(int l = 0; l<m; l++)
			   {
				 work[l] = work[l]+allocated[i][l];
				 allocated[i][l] = 0;
				 cout<<work[l]<<" ";
			   }
			   cout<<"\n";
		}
		
	   }
	   iter++;
	   if(iter==n)
	   {
		  cout<<"\nprocesses are in deadlock.\n";
		  break;
	   }
	   i = (i+1)%n;
	}
	if(allfinished(finished))
	{
		cout<<"\nThe processes can execute in safe state.\nThe safe sequence is: \n";
		for(int i = 0; i<n; i++)
	    {
	    	cout<<"<P"<<safeseq[i]+1<<"> ";
	    }
		cout<<"\n";	
	}
	else
	{
		cout<<"\nthe processes: ";
		for(int i = 0; i<n;i++)
		{
			if(finished[i]==false)
			{
				cout<<"<P"<<i+1<<"> ";
			}
		}
		cout<<" are in deadlock.\n";
		cout<<"\napplying recovery scheme.....\n";
		cout<<"\n ending all processes....\n";
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<m; j++)
			{
				allocated[i][j] = 0;
			}
		}
		cout<<"the processes: ";
		for(int i = 0; i<n;i++)
		{
			if(finished[i])
			{
				cout<<"<P"<<i+1<<"> ";
			}
		}
		cout<<"completed safely. the rest are terminated.\n";
	}
	cout<<"\n\n------end of program-----\n\n";
}
bool allfinished(bool f[])
{
	for(int i = 0; i<n; i++)
	{
		if(f[i]==false)
		{
			return false;
		}
	}
	return true;
}
