// Remove_Duplicates_from_Sorted_Array_I.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class MyClass
{
public:
	MyClass();
	~MyClass();

	int removeDuplicates_use_for(vector<int>& nums);
	int removeDuplicates_use_stl(vector<int>& nums);

	int removeDuplicates_use_template(vector<int>& nums);
	template<typename InIt, typename OutIt>
	OutIt removeDuplicates_use_template(InIt first, InIt last, OutIt output)
	{
		while (first != last)
		{
			*output++ = *first;
			first = upper_bound(first, last, *first);
		}

		return output;
	}

private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int MyClass::removeDuplicates_use_for(vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}

	int index = 0;
	for (size_t i = 1; i < nums.size(); i++)
	{
		if (nums[index] != nums[i])
		{
			nums[++index] = nums[i];
		}
	}

	return index + 1;
}

int MyClass::removeDuplicates_use_stl(vector<int>& nums)
{
	return distance(nums.begin(), unique(nums.begin(), nums.end()));
}

int MyClass::removeDuplicates_use_template(vector<int>& nums)
{
	return distance(nums.begin(), removeDuplicates_use_template(nums.begin(), nums.end(), nums.begin()));
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> numbers = { 1, 2, 2, 3, 4, 4, 5 };
	MyClass solution = MyClass();

	int length = solution.removeDuplicates_use_for(numbers);
	for (int i = 0; i < length; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;

	numbers = { 1, 2, 2, 3, 4, 4, 5 };
	length = solution.removeDuplicates_use_stl(numbers);
	for (int i = 0; i < length; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;

	numbers = { 1, 2, 2, 3, 4, 4, 5 };
	length = solution.removeDuplicates_use_template(numbers);
	for (int i = 0; i < length; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
	return 0;
}

