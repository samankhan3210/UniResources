#include<iostream>
#include<fstream>

using namespace std;

class SubSet
{
    int arr[50], size;
    public:
    SubSet(int *arr, int size)
    {
        this->size=size;
        for(int i=0; i<size; i++)
        {
            this->arr[i]=arr[i];
        }
    }
    bool Func(int s, int t)
    {
        if(t==0)
        {
            return true;
        }
        else if(t<0)
        {
            return false;
        }
        else
        {
            for(int k=s; k>=0; k--)
            {
                if(t-arr[k] >= 0)
                {
                    return (Func(s-1,t-arr[k]));
                    t=t+arr[k];
                }
            }
            return false;
        }
    }
};

int main()
{
    int array[50], target, n;
    ofstream of("Q3Input.txt",ios::out);
    cout<<"How many numbers do you want to enter in the array : ";
    cin>>n;
    of<<"Size of the array : "<<n<<endl<<"\nArray : \n";
    cout<<"Enter "<<n<<" elements : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>array[i];
        of<<array[i]<<endl;
    }
	cout<<"Enter Target value: " <<endl;
	cin>>target;
    of<<"Target Value : "<<target<<endl;
    of.close();
    ofstream of2("Q3Output.txt",ios::out);
    SubSet ob(array,n);
    bool ss=ob.Func(n,target);
    if(ss==true)
    {
        of2<<"YES!";
        cout<<"yes";
    }
    else
    {
        of2<<"NO!";
        cout<<"no";
    }
    of2.close();
}