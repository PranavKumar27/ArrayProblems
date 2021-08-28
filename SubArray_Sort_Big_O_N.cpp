#include <iostream>
#include <vector>

using namespace std;

// Sort Sub array: 1 2 3 4 5 8 6 7 9 10 11
// Find the left element to start with
// Find the right element to start with
// Find the correct position of left and right,
// The correct positions will give the answer
// of the sub array to eb sorted.

bool OutOfOrder(vector<int> v1, int idx)
{
	int sz = v1.size() - 1;
	if (v1[0] > v1[1])
		return true;
	else if (v1[sz - 1] < v1[sz - 2])
		return true;
	else if (idx != sz && v1[idx] > v1[idx + 1])
		return true;
	else if (idx == sz && v1[idx - 1] > v1[idx])
		return true;
	else if (idx != 0 && v1[idx - 1] > v1[idx])
		return true;
	else if (idx == 0 && v1[idx + 1] < v1[idx])
		return true;

	else
		return false;
}
int main(int argc, char *argv[])
{
	vector<int> v = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};

	int n = v.size() - 1;
	int i;
	int start_idx, end_idx;
	start_idx = end_idx = -1;

	for (i = 0; i <= n; i++)
	{
		if (OutOfOrder(v, i) && start_idx == -1)
		{
			cout << " start i=" << i << endl;
			start_idx = i;
		}
		if (OutOfOrder(v, n - i ) && end_idx == -1)
		{
			cout << " End n-i= " << n-i << endl;
			end_idx = n - i;
		}
	}

	cout << "start_idx=" << start_idx << endl;
	cout << "end_idx=" << end_idx << endl;

	int small = v[start_idx];
	int large = v[end_idx];

	if (small > large)
	{
		int temp = large;
		large = small;
		small = temp;
	}

	cout << "small=" << small << " large=" << large << endl;
	start_idx=end_idx=-1;
	n = v.size() - 1;
	for (i = 0; i <= n ; i++)
	{
		if (v[i] <= small)
		{
			// All fine
		}
		else if(start_idx==-1)
		{
			//cout << "start_idx=" << i << endl;
			start_idx = i ;
		}

		if (v[n - i] >=large)
		{
			// All good
		}
		else if(end_idx==-1)
		{
			//cout << "end_idx=" << n-i << endl;
			end_idx = n - i;
		}
	}
	cout << "start_idx=" << start_idx << endl;
	cout << "end_idx=" << end_idx << endl;
	return 0;
}
