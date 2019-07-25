#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v = { 2,4,6,8,10  };
	auto lambda = [](int x) {
		return x % 2 != 0;
	};

	cout << none_of(begin(v), end(v), lambda) << endl;

	system("pause");
	return 0;
}