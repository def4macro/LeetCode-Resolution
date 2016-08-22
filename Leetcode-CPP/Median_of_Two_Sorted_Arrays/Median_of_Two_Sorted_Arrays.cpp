// Median_of_Two_Sorted_Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

class MyClass
{
public:
	MyClass();
	~MyClass();

	/*Time Complexity O(log(m + n)), Space Complexity O(log(m + n))*/
	double findMedianSortedArrays(const vector<int>& A, const vector<int>& B);

private:
	static int find_kth(vector<int>::const_iterator A, int m, vector<int>::const_iterator B, int n, int k);
};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

double MyClass::findMedianSortedArrays(const vector<int>& A, const vector<int>& B)
{
	const int m = A.size();
	const int n = B.size();
	int total = m + n;

	/*if total is odd*/
	if (total & 0x1)
	{
		return find_kth(A.begin(), m, B.begin(), n, total / 2 + 1);
	}
	else
	{
		return (find_kth(A.begin(), m, B.begin(), n, total / 2)
			+ find_kth(A.begin(), m, B.begin(), n, total / 2 + 1)) / 2.0;
	}
}

int MyClass::find_kth(vector<int>::const_iterator A, int m, vector<int>::const_iterator B, int n, int k)
{
	/*always assume that m is equal or smaller than n*/
	if (m > n)
	{
		return find_kth(B, n, A, m, k);
	}
	if (m == 0)
	{
		return *(B + k - 1);
	}
	if (k == 1)
	{
		return min(*A, *B);
	}

	/*Divide k into two parts*/
	int ia = min(k / 2, m), ib = k - ia;
	if (*(A + ia -1) < *(B + ib -1))
	{
		return find_kth(A + ia, m - ia, B, n, k - ia);
	}
	else if (*(A + ia - 1) > *(B + ib - 1))
	{
		return find_kth(A, m, B + ib, n - ib, k - ib);
	}
	else
	{
		return A[ia - 1];
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

