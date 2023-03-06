#include<iostream>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include<string.h>

using namespace std;

class homepage
{
	protected:
		char key;
		int count;
		int ascii;
		string name;
		string question;
		string answer;
		
	public:
		homepage():key('a'),count(0),ascii(0),name(""),question(""),answer("")
		{
			
	}
};

class Admin
{
	string jumbleword;
	string password;
	string user;
	string pass;
	int count;
	int count1;
	int ascii;
	string name;
	string name1;
	int flag;
	string question;
	string answer;
	char key;
	
	public:
		
		bool load()
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
		 	
		 	bool ret1=login();
		 	if(ret1==false)
		 	{
		 		return false;
			}
			return true;
		}
		
		bool login()
		{
			count =0;
			string line;
			ifstream myfile("pass.txt");//from here we get a pass
			if(myfile.is_open())
			{
				while ( getline (myfile,line) )
				{
					if(count==0)
					{
						name=line;
					}
					else if(count == 1)
					{
						password=line;
					}
					count++;
				}
				myfile.close();
			}
			
			do
			{
				system("cls");
				
				std::cout<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
				std::cout<<"\n\t*****************************************\n";
				std::cout<<"\tLOGIN PAGE\n";
				std::cout<<"\t*****************************************\n\n";
				
			
				std::cout<<"\n\n\tUsername : ";
				key=getch();
				ascii=key;
				if(ascii==27)
				{
					exit(0);
				}
				std::cin>>user;
				std::cout<<"\n\tPassword : ";
				std::cin>>pass;
			}
			
			while(user!=name || pass!=password);
			{
				bool ret=mainMenu();
				if(ret==false)
				{
					return false;
				}
			}
			return true;
		}
		
        void DeleteQuestion(const char *str)
        {
            int num;
            string  data;
            char op, ch, s[100];
            do
            {
                ofstream temp("temp.txt",ios::app);
                fstream of1(str,ios::in|ios::out);
                int i=1, line=0;
                cin.ignore();
                while(of1.getline(s,100))
                {
                    cout<<i<<". "<<s<<endl;
                    i++;
                }
                if(i==2)
                {
                    cout<<"Only one question in the file so you cannot delete it."<<endl;
                    break;
                }
                else
                {
                    cout<<"Enter the line number which you wish to delete from the file : ";
                    cin>>num;
                    of1.clear();
                    of1.seekg(0, ios::beg);
                    cin.ignore();
                    while(getline(of1,data))
                    {
                        ++line;
                        if(line!=num)
                        {
                            temp<<data<<endl;
                        }            
                    }
                    temp.close();
                    of1.close();
                    remove(str);
                    rename("temp.txt",str);
                    cout<<"Do you want to delete another question? Y/N ";
                    cin>>op;
                }
            }
            while(op=='Y' || op=='y');
        }

        void AddQuestion(const char *s)
        {
            string ques;
            char op;
            do
            {
                fstream of1(s,ios::out|ios::app);
                of1.clear();
                of1.seekg(0, ios::beg);
                cin.ignore();
                cout<<"Enter the question you wish to store in the file : ";
                getline(cin,ques);
                of1<<ques<<endl;
                cout<<"Do you wish to enter another question? Y/N ";
                cin>>op;
                of1.close();
            }
            while(op=='Y' || op=='y');
        }

        void EditQuestion(const char *str)
        {
            char op;
            do
            {
                string ques, data;
                int num;
                char ch, s[100];
                fstream temp("temp.txt",ios::app);
                fstream of1(str,ios::in|ios::out);
                int i=1, line=0;
                cin.ignore();
                while(of1.getline(s,100))
                {
                    cout<<i<<". "<<s<<endl;
                    i++;
                }
                cout<<"Enter the line number you want to edit : ";
                cin>>num;
                cout<<"Enter the new question : ";
                of1.clear();
                of1.seekg(0, ios::beg);
                cin.ignore();
                while(getline(of1,data))
                {
                    ++line;
                    if(line!=num)
                    {
                        temp<<data<<endl;
                    }
                    else
                    {
                        cin.ignore();
                        getline(cin,ques);
                        temp<<ques<<endl;
                    }
                                
                }
                temp.close();
                of1.close();
                remove(str);
                rename("temp.txt",str);
                cout<<"Do you want to edit another question? Y/N ";
                cin>>op;
            }
            while(op=='Y' || op=='y');
        }

        void ListQ(const char *s)
        {
            string ques;
            int i=1;
            ifstream of1(s);
            of1.clear();
            of1.seekg(0, ios::beg);
            cin.ignore();
            while(getline(of1,ques))
            {
                cout<<"Q"<<i<<". "<<ques<<endl;
                i++;
            }
            of1.close();
        }

		bool mainMenu()
		{
			system("cls");
			cout<<("\n\n\n\t*********************************\n");
			cout<<("\t*                               *\n");
			cout<<("\t*\t\tMenu\t\t*\n");
			cout<<("\t*                               *\n");
			cout<<("\t*********************************\n");
		 	cout<<("\n\n");

		 	cout<<("\t|\t a)List of questions\n\n");
		 	cout<<("\t|\t b)Add question\n\n");
			cout<<"\t|\t c)Edit question\n\n";
			cout<<"\t|\t d)Delete question\n\n";
			cout<<"\t|\t e)Exit\n";
			
			cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout<<"\tPress button of your choice..... "<<endl;
			key=getch();
			ascii=key;
            string str[8]={"extrovert.txt","introvert.txt","judging.txt","feeling.txt","intuitive.txt","perceiving.txt","sensing.txt","thinking.txt"};
            string arr1[8]={"extrovert","introvert","judging","feeling","intuitive","perceiving","sensing","thinking"};
            int op;
			if(ascii==97 || ascii==65)
			{
				cout<<"\tWhich file do you want to view?";
                for(int i=0; i<8; i++)
                {
                    cout<<"\t"<<endl<<i+1<<". "<<arr1[i];
                }
                cout<<endl<<"Enter your choice : ";
                cin>>op;
                const char *c=str[op-1].c_str();
                ListQ(c);
			}
			else if(ascii==98 || ascii==66)
			{
				cout<<"\tWhich file do you want to edit?";
                for(int i=0; i<8; i++)
                {
                    cout<<"\t"<<endl<<i+1<<". "<<arr1[i];
                }
                cout<<endl<<"Enter your choice : ";
                cin>>op;
                const char *c=str[op-1].c_str();
                AddQuestion(c);
			}
		
			else if(ascii==99)
			{
                cout<<"\tWhich file do you want to edit?";
                for(int i=0; i<8; i++)
                {
                    cout<<endl<<i+1<<". "<<arr1[i];
                }
                cout<<"\t"<<endl<<"Enter your choice : ";
                cin>>op;
                const char *c=str[op-1].c_str();
                EditQuestion(c);
			}
			else if(ascii==100)
			{
                cout<<"\tWhich file do you want to edit?";
                for(int i=0; i<8; i++)
                {
                    cout<<"\t\t\t\t\t\t\t"<<endl<<i+1<<". "<<arr1[i];
                }
                cout<<endl<<"Enter your choice : ";
                cin>>op;
                const char *c=str[op-1].c_str();
				DeleteQuestion(c);
			}
			else if(ascii==101)
			{
				return false;
			}
			else
			{
				system("cls");
				std::cout<<"\n\n\n\n\n\n\tNOTE:Input correct word";
				Sleep(2000);
				mainMenu();
			}
			return true;
		}
};
