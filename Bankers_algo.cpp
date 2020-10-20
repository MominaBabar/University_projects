#include<iostream>
using namespace std;

int m,n; //n is no of processes, m is no of resources


int main()
{
    cout<<"\nEnter no of processes \n";
    cin>>n;
    cout<<"\nEnter no of resources \n";
    cin>>m;
	int instance[m];
    int allocation[n][m];
  	int max[n][m];
  	int need[n][m];
    int available[m];
    int request[m];
    int finish[n];
    bool check=0;
    bool check2=0;
	int index=0;
    int process=0;
	int sequence[n];
	int seq=0;
	int count=0;
    for(int p=0; p<m; p++)
    {
        cout<<"\nEnter instance of resource type "<<p<<"  ";
        cin>>instance[p];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<"\nEnter allocated resources for process P"<<i<<" of resource type "<<j<<"    ";
            cin>>allocation[i][j];
            
        }
    }
    for(int s=0; s<n; s++)
    {
    	sequence[s]=-1;
    }
    for(int s=0; s<n; s++)
    {
    	cout<<"P"<<s<<"  ";
    	for(int q=0; q<m; q++)
    	{
    		 cout<<allocation[s][q];
		}
		cout<<"\n";
	}
    for(int b=0; b<m; b++)
    {
    	int sum=0;
    	for(int i=0; i<n; i++)
    	{
    		sum=sum+allocation[i][b];
		}
		cout<<"\nsum is "<<sum;
    	available[b]=instance[b]-sum;
        
    }
    for(int c=0; c<n; c++)
    {
        finish[c]=0;
    }
    for(int i=0; i<m; i++)
    {
        cout<<"\navailable resources are "<<available[i];
    }
    for(int k=0; k<n; k++)
    {
        for(int l=0; l<m; l++)
        {
            cout<<"\nEnter max resources for process P"<<k<<" of resource type "<<l<<"    ";
            cin>>max[k][l];
        }
    }
    
    for(int s=0; s<n; s++)
    {
    	cout<<"P"<<s<<"  ";
    	for(int q=0; q<m; q++)
    	{
    		 cout<<max[s][q];
		}
		cout<<"\n";
	}
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
            
        }
    }
    for(int i=0; i<n; i++)
    {
    	cout<<"\n Need of process P"<<i<<" is ";
    	for(int j=0; j<m; j++)
        {
        	cout<<need[i][j];
		}
		cout<<"\n";
    }
    cout<<"\n Enter process no which made request\n";
    cin>>process;
    for(int i=0; i<m; i++)
    {
        cout<<"\n Enter request of process P"<<process<<" of instance "<<i<<" ";
        cin>>request[i];
    }
    
    for(int j=0; j<m; j++)
    {
    	if((request[j]<need[process][j] ||  request[j]==need[process][j]) && (request[j]<available[j] ||  request[j]==available[j]))
    	{
    		check=1;
		}
		else
		{
			check=0;
			break;
		}
    }
    if(check==1)
	{
		for(int i=0; i<m; i++)
    	{
    		available[i]=available[i]-request[i];
    		allocation[process][i]=allocation[process][i]+request[i];
    		need[process][i]=need[process][i]-request[i];
    	}
		
	}
	
	
	cout<<"\n Request fulfill. Now check if system is in safe state or not\n";
	CHECK_SAFE:for(int i=0; i<n; i++)
			    {
			    	if(finish[i]==0)
			    		{
					    	for(int j=0; j<m; j++)
					    	{
					    		
					    			if(need[i][j]<available[j] || need[i][j]==available[j])
						    		{
						    			check2=1;
									}
						    		else
						    		{
						    			
						    			check2=0;
						    			break;
									}
								
					    	}
					    	if(check2==1)
					    	{
					    		finish[i]=1;
					    		sequence[seq]=i;
					    		seq++;
					    		for(int k=0; k<m; k++)
					    		{
					    			available[k]=available[k]-need[i][k];
					    			available[k]=available[k]+max[i][k];
					    		}
					    		
							}
							
								
						}
			    }
			    goto END;
	END: for(int i=0; i<n; i++)
			{
				if(finish[i]==0)
				{
					count++;
					if(count<3)
					{
						goto CHECK_SAFE;
						break;
					}
					
				}
			}
		    for(int i=0; i<n; i++)
			{
				if(finish[i]==0)
				{
					index=1;
					cout<<"\n System is not in safe state\n";
					break;
				}
				else
				{
					index=0;
				}
			}
			if(index==0)
			{
				cout<<"\n System is in safe state and sequence is \n";
				for(int i=0; i<n; i++)
				{
					cout<<"P"<<sequence[i]<<" ";
				}
			}
}

