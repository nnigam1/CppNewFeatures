#include<iostream>
using namespace std;

// constexpr : is not only telling the compiler that function is const ,
// but it actually make execution faster , How?
// constexpr : compiler know that function is constant , so now whenever in your 
// code you are calling it , it will store the value at compile time.
// and not just display in runtime.
constexpr int cubed(int x) {
	return x*x*x;
};

int main()
{

	int y = cubed(3); // this is computed at compile time only , because compiler knows the cubed is constant.
	cout << y << endl;
	system("pause");
	return 0;
}