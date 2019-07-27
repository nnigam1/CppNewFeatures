#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<algorithm>
using namespace std;

void printResult(vector<int> v)
{
	for_each(begin(v), end(v), [](int i) {
		cout << i << " ";
	});
	cout << endl;
}

void copyBucketIntoVector(map<int, list<int>> bucket, vector<int> &v)
{
	int index = 0;
	map<int, list<int>>::iterator itr = begin(bucket);
	while (itr != end(bucket))
	{
		list<int>::iterator itr2 = begin(itr->second);
		while (itr2 != end(itr->second))
		{
			if (index < v.size())
			{
				v[index] = *itr2;
				index++;
				itr2++;
			}
		}
		itr++;
	}
	printResult(v);
}

void radixSort(vector<int> &v, int maxDigit)
{
	// use a map to store the values as int and list to maintain the insertion order.
	// int will be used to store the index of an array and list to be store the elements at that index after processing.
	map<int, list<int>> bucket;
	// traverse from 10^1 , 10^2..... 10^d
	// Sorting from 1st digit to d digits.
	for (int digit = 1; digit <= maxDigit; digit++)
	{
		bucket.clear();
		for (int i = 0; i < v.size(); i++)
		{
			int value = pow(10, digit);
			int num = v[i] % value;

			num = num / pow(10, digit - 1);

			bucket[num].push_back(v[i]);
		}
		copyBucketIntoVector(bucket, v);
	}
}


int main()
{
	vector<int> v = { 170 , 45, 24, 36 , 75 , 820, 87 , 63 };
	int maxDigit = 3;

	radixSort(v, maxDigit);

	printResult(v);

	system("pause");
	return 0;
}