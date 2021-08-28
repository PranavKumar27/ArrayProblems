
#include <iostream>
#include <vector>

using namespace std;

// 1 2 3 4 5 8 6 7 9 10 11
// Find shortest subarray to sort the array.

int main(int argc, char *argv[])
{
	int i,j;
	vector<int>v={1,2,3,4,5,9,6,7,8,10,11};
	int st_index=0;
	int end_index=0;
	int prev=v[0];
	for(i=1;i<v.size();i++)
	{
		if(prev<v[i] && v[st_index]>v[i])
		{
			prev=v[i];
			end_index=i;
		}
		else if(prev<v[i] && v[st_index]<v[i])
		{
			prev=v[i];
		}
		else
		{
			st_index=i-1;
			prev=v[i];
		}
			
	}
	
	cout << "Result=" << " st_index=" << st_index << " end_index=" << end_index << endl;
	
	return 0;
	
}
