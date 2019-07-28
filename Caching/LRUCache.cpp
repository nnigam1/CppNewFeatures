#include<iostream>
#include<map>
#include<list>
#include<algorithm>
using namespace std;

class LRUCache
{
	list<int> order;
	map<int, pair<string , list<int>::iterator>> cacheMap;
	int capacity;
public:

	LRUCache(int csize) : capacity(csize) {
	}
	map<int, pair<string, list<int>::iterator>> getMap()
	{
		return cacheMap;
	}
	void refer(int x , string value);
	void display(map<int, pair<string, list<int>::iterator>> ma);
	void getValue(int x);
};

// Refer : to put the key in the cacheMap.
void LRUCache::refer(int x , string value)
{
	// if key is not available in map.
	if (cacheMap.find(x) == cacheMap.end())
	{
		// if the size is already full then remove the least recently used.
		if ( capacity == order.size())
		{
			int temp = order.back();
			cacheMap.erase(temp);
			order.pop_back();
		}		
	}
	else
	{
		// delete the entry from list so that we can add it in front.
		// to mark it as most recently used.
		order.erase(cacheMap[x].second);
	}

	order.push_front(x);
	cacheMap[x] = make_pair(value, begin(order));
}

void LRUCache::display(map<int, pair<string, list<int>::iterator>> ma)
{
	for_each(begin(order), end(order), [&ma](int x) {
		cout << ma[x].first.c_str() << endl;
	});
}

void LRUCache::getValue(int x)
{
	if (cacheMap.find(x) != cacheMap.end())
	{
		cout << "value is at get:" << " ";
		cout << cacheMap[x].first.c_str();
	}
	else
	{
		cout << "value Not present" << endl;
	}
}

// Driver Code 
int main()
{
	LRUCache ca(4);

	ca.refer(1, "cpp");
	ca.refer(2 , "java");
	ca.refer(3 , "go");
	ca.refer(1 , "react");
	ca.refer(4 , "python");
	ca.refer(5 , "dotnet");
	ca.display(ca.getMap());
	ca.getValue(2);
	system("pause");
	return 0;
}
