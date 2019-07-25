#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v1 = { 1,2,3,4,5,6,7 };
	int x = 3;
	auto addElement = ([&v1 ,x]() {
		for (auto& key : v1)
		{
			key += x;
		}
	});

	auto printElement = ( [&v1]() {
		for (int key : v1)
		{
			cout << key << " ";
		}
		cout << endl;
	});

	addElement();

	printElement();

	for_each(begin(v1), end(v1), [](int y) { 
		cout << y << " ";
	});
	cout << endl;
	system("pause");
	return 0;
}