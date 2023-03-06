//LAB 1 QUESTION#04
#include<iomanip>
#include<iostream>
#include<string>
using namespace std;
struct menuitemType //structutre declaration
{
    string MI; //menu items, variable to store all the item names
    double MP; //menu prices, variable to store all the item prices
}menuList[8]; //array
int main()
{
    int choice,i; 
    char another;
    float sum=0, tax, AM;
    menuList[0].MI="Plain Egg"; //entering the data
    menuList[0].MP=1.45;
    menuList[1].MI="Bacon and Egg";
    menuList[1].MP=2.45;
    menuList[2].MI="Muffin";
    menuList[2].MP=0.99;
    menuList[3].MI="French Toast";
    menuList[3].MP=1.99;
    menuList[4].MI="Fruit Basket";
    menuList[4].MP=2.49;
    menuList[5].MI="Cereal";
    menuList[5].MP=.69;
    menuList[6].MI="Coffee";
    menuList[6].MP=0.50;
    menuList[7].MI="Tea";
    menuList[7].MP=0.75;
    while(1)
	{
		       
        cout<<"\t\t\tWELCOME TO EVERGREEN CAFE"<<endl;
        for(i=0;i<8;i++) //loop for printing the menu
        {
		cout<<i+1<<". "<<menuList[i].MI<<"\t\t$"<<menuList[i].MP<<endl;
	    }
        cout<<"Enter the number of item you wanna choose (for eg 1,2 etc) or press 0 if you wanna exit: ";
        cin>>choice;
        if(choice==1)
        	   {
				    sum=sum+1.45;
			    }
		else if(choice==2)
				{
					sum=sum+2.45;
				}
		else if(choice==3)
			    {
			    	sum=sum+0.99;
				}
		else if(choice==4)
			    {
			    	sum=sum+1.99;
				}
		else if(choice==5)
			    {
			    	sum=sum+2.49;
				}
		else if(choice==6)
			    {
			    	sum=sum+0.69;
				}
		else if(choice==7)
			    {
			    	sum=sum+0.50;
				}	
		else if(choice==8)
			    {
			    	sum=sum+0.75;
				}
		else if(choice==0)	
		        {
			        break;
		        }
				
      }
        tax=sum*0.05; //calculating tax
        AM=sum+tax;
        cout<<"\t\t BILL"<<endl; //printing the bill
        cout<<"Tax"<<"\t\t$"<<fixed<<setprecision(2)<<tax<<endl;
        cout<<"Amount Due"<<"\t$"<<fixed<<setprecision(2)<<AM<<endl;
        
}

