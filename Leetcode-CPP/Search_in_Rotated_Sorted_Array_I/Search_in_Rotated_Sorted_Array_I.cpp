// Search_in_Rotated_Sorted_Array_I.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>


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

		if (nums[first] <= nums[mid])
		{
			if (nums[first] <= target && target < nums[mid])
			{
				last = mid;
			}
			else
			{
				first = mid + 1;
			}
		}
		else
		{
			/*The if-else condition of rotation.*/
			if (nums[mid] < target && target <= nums[last - 1])
			{
				first = mid + 1;
			}
			else
			{
				last = mid;
			}
		}
	}

	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> numbers = { 0, 1, 2, 3, 4, 5, 6, 7 };
	const int target = 3;
	MyClass solution = MyClass();
	if (solution.search(numbers, target) != -1)
	{
		cout << "Find " << target << endl;
	}
	else
	{
		cout << "Cannot find " << target << endl;
	}

	/*Rotation situation.*/
	numbers = { 4, 5, 6, 7, 0, 1, 2, 3 };
	if (solution.search(numbers, target))
	{
		cout << "Find " << target << endl;
	}
	else
	{
		cout << "Cannot find " << target << endl;
	}

	/*Cannot find duplicates 1, solution is next project(Search in Rotated Sorted Array II).*/
	numbers = { 1, 3, 1, 1, 1 };
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

