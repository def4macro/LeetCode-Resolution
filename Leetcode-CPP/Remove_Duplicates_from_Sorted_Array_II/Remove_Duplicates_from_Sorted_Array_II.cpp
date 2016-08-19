// Remove_Duplicates_from_Sorted_Array_II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

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
	return 0;
}

