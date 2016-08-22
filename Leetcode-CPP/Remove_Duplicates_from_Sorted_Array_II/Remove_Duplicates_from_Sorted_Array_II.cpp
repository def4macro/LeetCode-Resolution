// Remove_Duplicates_from_Sorted_Array_II.cpp : Defines the entry point for the console application.
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

	int removeDuplicates(vector<int>& nums)
	{
		if (nums.size() <= 2)
		{
			return nums.size();
		}

		int index = 2;
		for (int i = 2; i < nums.size(); i++)
		{
			if (nums[i] != nums[index - 2])
			{
				nums[index++] = nums[i];
			}
		}

		return index;
	}

	int removeDuplicatesExtend(vector<int>& nums)
	{
		const int n = nums.size();
		int index = 0;
		for (int i = 0; i < n; ++i)
		{
			if (i > 0 && i < n - 1 && nums[i] == nums[i - 1] && nums[i] == nums[i + 1])
			{
				continue;
			}

			nums[index++] = nums[i];
		}

		return index;
	}

private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> numbers = { 0, 1, 1, 1, 2, 2, 3 };
	MyClass solution = MyClass();
	int length = solution.removeDuplicates(numbers);
	cout << length << endl;
	for (int i = 0; i < length; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;

	numbers = { 0, 1, 1, 1, 2, 2, 3 };
	length = solution.removeDuplicatesExtend(numbers);
	for (int i = 0; i < length; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;

	return 0;
}

