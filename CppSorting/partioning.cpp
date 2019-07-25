#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v = { 1,2,3,4,-9,-7,5,-4,-3,6 };

	auto lambda = [](int x) {
		return x > 0;
	};

	// To add 1 in each element in vector.
	//transform(begin(v), end(v), v.begin(), [](int x) {
	//	return x + 1;
	//});

	cout << is_partitioned(begin(v), end(v), lambda) << endl;

	// order will maintain
	stable_partition(begin(v), end(v), lambda);

	for each(int i in v)
	{
		cout << i << " ";
	}
	cout << endl;

	auto it = partition_point(begin(v), end(v), lambda);
	cout << *it << endl;

	system("pause");
	return 0;

}