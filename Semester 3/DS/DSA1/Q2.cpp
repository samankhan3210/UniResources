#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

class Palindrome
{
    int a[50], s;
    public:
    Palindrome(int *a, int s)
    {
        this->s=s;
        for(int i=0; i<s; i++)
        {
            this->a[i]=a[i];
        }
    }
    void Function()
    {
        ofstream of2("Q2Output.txt",ios::out);
        ostringstream os, os2;
        int count=0;
        if(s%2==0)
        {
            for(int i=0; i<(s/2); i++)
            {
		        os<<a[i];
                os2<<a[(s/2)+i];
	        }
        string str1(os.str());
        string newstr1;
        for(int n = str1.length()-1; n >= 0; n--)
        {
            newstr1.push_back(str1[n]);
        }
        string str2(os2.str());
        int compare = str2.compare(newstr1);
        if(compare==0)
            {
                cout<<"YES, array is a palindrome! "<<endl;
                of2<<"YES array is a palindrome! "<<endl;
            }
        else
            {
                cout<<"NO, array is not a palindrome! "<<endl;
                of2<<"NO, array is not a palindrome! "<<endl;
            }
        }
        else if(s%2!=0)
        {
            for(int i=0; i<((s/2)); i++)
            {
		        os<<a[i];
                os2<<a[(s/2)+i+1];
    	    }
            string st1(os.str());
            string newst1;
            for(int n = st1.length()-1; n >= 0; n--)
            {
                newst1.push_back(st1[n]);
            }
            string st2(os2.str());
            int comp=st2.compare(newst1);
            if(comp==0)
            {
                cout<<"YES, array is a palindrome! "<<endl;
                of2<<"YES array is a palindrome! "<<endl;
            }
            else
            {
                cout<<"NO, array is not a palindrome! "<<endl;
                of2<<"NO, array is not a palindrome! "<<endl;
            }
        }
    }
};

int main()
{
    int n,i;
    int arr[100];
    cout<<"How many numbers do you want to enter in the array : ";
    cin>>n;
    ofstream of("Q2Input.txt",ios::out);
    of<<"Size of the array : "<<n<<endl<<"\nArray : \n";
    cout<<"Enter "<<n<<" elements : "<<endl;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
        of<<arr[i]<<" \n";
    }
    of.close();
    Palindrome ob(arr, n);
    ob.Function();
}