#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> v = { 11,2,3,44,5,16,12,89,9,10 } , v1;
	auto lambda = [](int a, int b) {
		return a < b;
	};
	v1 = v;
	partial_sort(begin(v), v.begin() + 4, end(v), lambda);

	//cout << "min element is : " << v[0] << endl;
	for each(int i in v)
	{
		cout << i << " ";
	}
	cout << endl;

	sort(v1.begin(), v1.begin() + 4 , lambda);

	for each(int i in v1)
	{
		cout << i << " ";
	}
	
	cout << endl;
	system("pause");
	return 0;
}