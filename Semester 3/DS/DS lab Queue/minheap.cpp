#include<iostream>
using namespace std;

class MinHeap
{
	int *array;
	int cap;
	int size;
	public:
	MinHeap(int cap)
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
		return array[size-1];
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
		if(array[PI]>array[i])
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
		int minI = i;
		if(array[left] < array[i])
		{
			minI = left;
		}
		if(!isleaf(right) && (array[right] < array[minI]))
		{
			minI = right;
		}
		if(minI != i)
		{
			int temp = array[i];
			array[i] = array[minI];
			array[minI] = temp;
			shiftdown(minI);
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
	int extractMin()
	{
		int min = array[0];
		array[0] = array[size - 1];
		size--;
		shiftdown(0);
		return min;
	}
	int removeAt(int K)
	{
		int right = array[K];
		array[K] = array[size -1];
		size-- ;
		int p = getparent(K);
		if(K == 0 || array[K] > array[p])
			shiftdown(K);
		else
			shiftup(K);
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
	MinHeap ob(n);
	for(int i=0; i<n; i++)
	{
		ob.insert(arr[i]);
	}
	cout<<"Min Heap : ";
	ob.Display();
}

