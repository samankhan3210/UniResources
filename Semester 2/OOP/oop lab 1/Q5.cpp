//LAB 1 QUESTION#05
#include <iostream>
#include <iomanip>
#include<string>
using namespace std;
struct BaseballPlayer //name of the structure
{
    string n; //variable for storing name
    int HR; //variable for storing home runs
    int h; //variable for storing hits
}players[3]; //array declaration of structure
int main()
{
    string name, name2;
    int i, ch;
    for (i=0;i<3;i++) //loop for entering data of 3 players
    {
    	fflush(stdin);
        cout<<"Enter the name of player "<<i+1<<": ";
        getline(cin,players[i].n);
        cout<<endl;
        cout<<"Enter the number of home runs: ";
        cin>>players[i].HR;
        cout<<endl;
        cout<<"Enter number of hits: ";
        cin>>players[i].h;
    }
    while(1)
    {
        cout<<"\t\t\tPLAYERS INFORMATION"<<endl;
		cout<<"1.Check Player"<<endl;
		cout<<"2.Update Player's Data"<<endl;
		cout<<"3.Display Player's Data"<<endl;
		cout<<"Enter your choice or enter 0 if you wanna exit: ";
        cin>>ch;
        if(ch==1)
        	{
        		fflush(stdin);
        		cout<<"Enter the name of the player you wanna check: ";
       			getline(cin,name);
       			for(i=0;i<3;i++)
        		{
        			if(name.compare(players[i].n)==0) //codition to check whether the name entered is equal to the name of the player if yes then it'll orint all the info of that player
        	        {
						cout<<"Name: "<<players[i].n<<endl;
						cout<<"Home Runs: "<<players[i].HR<<endl;
						cout<<"Hits: "<<players[i].h<<endl;
					}
			    }
				    
            }
        else if(ch==2)
            {
            	fflush(stdin);
			    cout<<"Enter the name of the player you wanna update: ";
       			getline(cin,name2);
       			for(i=0;i<3;i++)
       			{
       			if(name2.compare(players[i].n)==0)//same condition as above
       	           {
						cout<<"Enter new name: ";
						cin>>players[i].n;
						cout<<"Enter new number of home runs: ";
						cin>>players[i].HR;
						cout<<"Enter new number of hits: ";
						cin>>players[i].h;
					}
				}       		
			}
		else if(ch==3)
			{
				for (i=0;i<3;i++) //loop for printing information of all the players
                    {
                    	cout<<"\t\tPlayer's "<<i+1<<" Information"<<endl;
                        cout<<"Name: "<<players[i].n<<endl;
						cout<<"Home Runs: "<<players[i].HR<<endl;
						cout<<"Hits: "<<players[i].h<<endl;
                    }
			}
		else if(ch==0)
			{
				break;
			}
    }
}
  
