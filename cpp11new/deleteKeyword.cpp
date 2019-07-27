#include<iostream>
using namespace std;

class Dog
{
public:
	int age;
	Dog(int age) : age(age) {};

	// you can delete the functions like this , so that no one use in an inappropriate form.
	Dog(double age) = delete;
};

int main()
{
	Dog* d1 = new Dog(3);
	//Dog d2(3.0);

	cout << "Dog age is:" << endl;
	cout << d1->age << endl;
	//cout << d2.age << endl;
	system("pause");
	return 0;
}