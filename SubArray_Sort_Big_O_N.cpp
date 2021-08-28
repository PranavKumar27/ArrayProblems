
#include <iostream>
#include <vector>

using namespace std;

// Sort Sub array: 1 2 3 4 5 8 6 7 9 10 11
// Find the left element to start with
// Find the right element to start with
// Find the correct position of left and right,
// The correct positions will give the answer
// of the sub array to eb sorted.

int main(int argc, char *argv[])
{
	vector<int> v = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};

	int n = v.size() - 1;
	int i;
	int start_idx, end_idx;
	start_idx = end_idx = -1;

	if (v[0] > v[1] || v[n - 1] < v[n - 2])
	{
		// Edge Case sort complete array
		start_idx = 0;
		end_idx = n - 1;
	}
	else
	{
		for (i = 1; i <= n - 1; i++)
		{
			if (start_idx == -1)
			{
				if (v[i] > v[i - 1] && v[i] < v[i + 1])
				{
					// All good
					;
					//cout << "i=" << i << endl;
				}
				else
				{
					start_idx = i;
					//cout << "inside else i=" << i << endl;
				}
			}
			if (end_idx == -1)
			{
				if (v[n - i] > v[n - i - 1] && v[n - i] < v[n - i + 1])
				{
					// All good
					;
				}
				else
				{
					end_idx = n - i;
				}
			}
		}

		int small = v[start_idx];
		int large = v[end_idx];

		if (small > large)
		{
			int temp = large;
			large = small;
			small = temp;
		}

		n = v.size() - 1;
		for (i = 1; i <= n - 1; i++)
		{
			if (v[i] < small && v[i + 1] > small)
			{
				start_idx = i + 1;
			}

			if (v[n - i] < large && v[n - i + 1] > large)
			{
				end_idx = n - i;
			}
		}
	}
	cout << "start_idx=" << start_idx << endl;
	cout << "end_idx=" << end_idx << endl;
	return 0;
}
