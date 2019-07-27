#include<iostream>
#include<vector>
using namespace std;

// Let's understand basic Functional programming !!!

template<typename func>
void filter(func f, vector<int> v)
{
	for (auto i : v)
	{
		if (f(i))
		{
			cout << i << " ";
		}
	}
	cout << endl;
}

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9 };

	filter([](int x) {return x > 5;}, v);
	
	system("pause");
	return 0;
}