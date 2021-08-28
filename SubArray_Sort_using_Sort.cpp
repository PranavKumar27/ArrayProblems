#include <iostream>
#include <vector>

using namespace std;

// Sub array sort 1 2 3 4 5 8 6 7 9 10 11
// Sort and then compare
// to find correct position

int main(int argc, char *argv[])
{
	int start_idx,end_idx;
	int i;
	start_idx=-1;
	end_idx=-1;
	vector<int> v={1,2,3,4,5,8,6,7,9,10,11};
	vector<int>v_org=v;
	
	sort(v.begin(),v.end());
	int n=v.size()-1;
	for(i=0;i<v.size();i++)
	{
		if(v[i] != v_org[i] && start_idx==-1)
		{
			start_idx=i;
		}
		else if(v[n-i] != v_org[n-i] && end_idx==-1)
		{
			end_idx=n-i;
		}
	}
	
	cout << "start_idx=" << start_idx << endl;
	cout << "end_idx="  << end_idx << endl;
	return 0;	
}
