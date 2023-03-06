#include<iostream>
#include<string.h>
#include<fstream>
#include"project.cpp"
#include"queue.cpp"
#include"admin.cpp"

using namespace std;

class HashMap
{
	private:
	
		int H_Size; 
	    linked_list *table; 
    
	public: 
	
	    HashMap()
	    {
		    this->H_Size = 9; 
		    table = new linked_list[H_Size]; 	
		}
	    
		void insertItem(string s, int index)
		{
		    table[index].add_node(s);
		}
	    
		int *displayHash()
		{
			int *points=new int [8];
			int score, ch, count=0;
			for(int i=0; i<H_Size; i++)
			{
				score=0;
				node *n = table[i].head;
				bool done=false;
				while(n!=NULL)
				{	
					cout<<"Q"<<++count<<" . ";
					cout<<n->data<<endl;
					while(!done)
					{
						cout<<"1. Agree     2. Neutral     3. Disagree"<<endl;
						cin>>ch;
						if(ch==1)
						{
							score=score+2;
							done=true;
						}
						else if(ch==2)
						{
							score++;
							done=true;
						}
						else if(ch==3)
						{
							done=true;
						}
						else if(ch>=1 && ch<=3)
						{
							cout<<"inavlid choice, enter your choice again\n\n";
						}
					}		
					n=n->next;
					done=false;		
				}
				points[i]=score;
			}
			return points;	
		} 
};

int main()
{
	bool done=false;
	while(done==false)
	{
		Admin a;
		char key;
		int ascii=0;
	
		system("cls");
		system("color 0B");
		cout<<("\n\n\n\n\n\t*******************************************\n");
		cout<<("\t*                                         *\n");
		cout<<("\t*\t   PERSONALITY ANALYSIS TEST\t  *\n");
		cout<<("\t*                                         *\n");
		cout<<("\t*******************************************\n");
		cout<<"\n\t1)Admin \n ";
		cout<<"\t2)Test \n";
		cout<<"\n\tPress button of your choice...\n";
		
		key=getch();
		ascii=key;
		
		if(ascii == 49)
		{
			bool ret_m= a.load();
			if(ret_m!=false)
			{
				done=true;
			}
		}
		
		else if(ascii==50)
		{
		    system("cls");
			system("color 0B");
		 	cout<<"\n\t   Please wait while loading...\n\n";
		 	char a=177, b=219;
		 	cout<<"\t";
		 	
			for (int i=0;i<=15;i++)
			{
		 		cout<<a;
		    }
		    
		 	cout<<"\r";
		 	cout<<"\t";
		 	
		 	for (int i=0;i<=15;i++)
		 	{
		  		std::cout<<b;
		  		Sleep(250); 
		 	}
		 	
		 	cout<<endl<<endl;
				
			HashMap ob;
			string s;
		    string str[8]={"extrovert.txt","introvert.txt","judging.txt","feeling.txt","intuitive.txt","perceiving.txt","sensing.txt","thinking.txt"};
		    string file_names[8]={"Extrovert","Introvert","Judging","Feeling","Intuitive","Perceiving","Sensing","Thinking"};
		    int j=0, *array;
		    
		    for(int i=0; i<8; i++)
			{
				ifstream of1(str[i].c_str());
				
				while(getline(of1, s))
				{
					ob.insertItem(s,j);
				}
				j++;
			}
		    array=ob.displayHash();
		    Queue Q;
		    float sum;
		    for(int i=0;i<8;i++)
		    {
		    	sum = sum+array[i];
		    	Q.enQueue(file_names[i],array[i]);
			}
			for(int i=0; i<8; i++)
			{
				Q.SortScores();
			}
			Q.calculate_percentage(sum);
			Q.display();
			done=true;
			
		}	
		else
		{
			system("cls");
			std::cout<<"\n\n\n\n\n\n\tNOTE:Input correct word";
			Sleep(2000);
			main();
		}
	}
	return 0;
}
