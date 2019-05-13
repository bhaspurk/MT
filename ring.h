#include <vector>

class Ring
{
public:
	Ring(int n);
	~Ring();
	int AddToRing(int val);
	int DeleteFromRing(int &val);
	int Traverse();
	//int NumElements();
	//bool IsFull();
	//bool IsEmpty();

private:
	std::vector<int> buffer;
	int head, tail, size;
	bool full;
	
};
