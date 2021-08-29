
#include <iostream>
#include <vector>

using namespace std;

// Find Min Swaps to sort an array
// Array is 2 5 3 1 4
// Swap 1: 1 5 3 2 4
// Swap 2: 1 2 3 5 4
// Swap 3: 1 2 3 4 5
// Result= 3
// Compare with sorted array and find the min swaps to sort array
	
int main(int argc, char *argv[])
{
	int i,no_of_swaps=0;
	vector<int> v={2,5,1,3,4};
	vector<int> v_org=v;
	int n=v.size();
	int idx;
	int temp;
	sort(v.begin(),v.end());
	
	vector<int>::iterator itr;
	for(i=0;i<n;i++)
	{
		if(v[i]!=v_org[i])
		{
			itr=find(v_org.begin(),v_org.end(),v[i]);
			idx=itr-v_org.begin();
			
			// swap vector at index i and idx 
			temp=v_org[i];
			v_org[i]=v_org[idx];
			v_org[idx]=temp;
			
			no_of_swaps++;
		}
	}
	
	cout << "Result=" << no_of_swaps << endl;
	return 0;	
}
