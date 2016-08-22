// Search_in_Rotated_Sorted_Array_II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>


using namespace std;

class MyClass
{
public:
	MyClass();
	~MyClass();

	bool search(const vector<int>& nums, int target);

private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

bool MyClass::search(const vector<int>& nums, int target)
{
	int first = 0, last = nums.size();
	while (first != last)
	{
		const int mid = first + (last - first) / 2;
		if (nums[mid] == target)
		{
			return true;
		}

		if (nums[first] < nums[mid])
		{
			if (nums[first] <= target && target <= nums[mid])
			{
				last = mid;
			}
			else
			{
				first = mid + 1;
			}
		}
		else if (nums[first] > nums[mid])
		{
			if (nums[mid] < target && target < nums[last - 1])
			{
				first = mid + 1;
			}
			else
			{
				last = mid;
			}
		}
		else
		{
			first++;
		}
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> numbers = { 1, 3, 1, 1, 1 };
	MyClass solution = MyClass();
	const int target = 3;

	if (solution.search(numbers, target))
	{
		cout << "Find " << target << endl;
	}
	else
	{
		cout << "Cannot find " << target << endl;
	}
	return 0;
}

