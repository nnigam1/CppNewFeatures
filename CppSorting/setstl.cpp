#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int main()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 4,5,6,7,8 };
	vector<int> results;

	//set_union(begin(v1), end(v1), begin(v2), end(v2), back_inserter(results));

	//set_difference(begin(v1), end(v1), begin(v2), end(v2), back_inserter(results));

	merge(begin(v1), end(v1), begin(v2), end(v2), back_inserter(results));
	
	for each(int i in results)
	{
		cout << i << " ";
	}
	
	cout << endl;
	system("pause");
	return 0;
}
