#include<iostream>
using namespace std;

class MaxHeap
{
	int *array;
	int cap;
	int size;
	public:
	MaxHeap(int cap)
	{
		array = new int[cap];
		this->cap = cap;
		this->size = 0;
	}
	int getSize()
	{
		return size;
	}
	int getparent(int child)
	{
		if(child%2==0)
		{
			return (child/2)-1;
		}
		else
		{
			return (child/2);
		}
	}
	int getleft(int parent)
	{
		return (2*parent+1);
	}
	int getright(int parent)
	{
		return (2*parent+2);
	}
	int getMax()
	{
		for(int i = 0;i<size;i++)
		{
			cout<<array[i]<<" ";
		}
		cout<<endl;
		return array[0];
	}
	bool isleaf(int i)
	{
		if(i>=size)
		{
			return true;
		}
		return false;
	}
	void shiftup(int i)
	{
		if(i == 0)
		{
			return;
		}
		int PI = getparent(i);
		if(array[PI]<array[i])
		{
			int temp = array[PI];
			array[PI] = array[i];
			array[i] = temp;
			shiftup(PI);
		}
	}
	void shiftdown(int i)
	{
		int left = getleft(i);
		int right = getright(i);
		if(isleaf(left))
		{
			return;
		}
		int maxI = i;
		if(array[left] > array[i])
		{
			maxI = left;
		}
		if(!isleaf(right) && (array[right] > array[maxI]))
		{
			maxI = right;
		}
		if(maxI != i)
		{
			int temp = array[i];
			array[i] = array[maxI];
			array[maxI] = temp;
			shiftdown(maxI);
		}
	}	
	void insert(int k)
	{
		array[size] = k;
		shiftup(size);
		size++;
		for(int i = 0;i<size;i++)	
		{
			cout<<array[i]<<" ";
		}
		cout<<endl;
	}
	int extractM()
	{
		int max = array[0];
		array[0] = array[size - 1];
		size--;
		shiftdown(0);
		return max;
	}
	int remove(int d)
	{
		int right = array[d];
		array[d] = array[size-1];
		size-- ;
		int p = getparent(d);
		if(d == 0 || array[d] < array[p])
		{
			shiftdown(d);
		}
		else
		{
			shiftup(d);
		}
		return right;
	}
	void heapify(int *array, int l)
	{
		size = l;
		array = array;
		for(int i=size-1; i>=0; --i)
		{
			shiftdown(i);
		}
	}
	void Display()
	{
		for(int i=0; i<cap; i++)
		{
			cout<<array[i]<<" ";
		}
	}
};
int main()
{
	int n, arr[100];
	cout<<"Enter the number of elements you want to enter : ";
	cin>>n;
	cout<<"Enter "<<n<<" elements : ";
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	MaxHeap ob(n);
	for(int i=0; i<n; i++)
	{
		ob.insert(arr[i]);
	}
	cout<<"Max Heap : ";
	ob.Display();
}

