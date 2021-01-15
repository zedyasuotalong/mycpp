#include <iostream>
#include <string>
#include <cstring>
//#include <cmath>
using namespace std;
#if 1
template <typename Type>
class Stack
{
	private:
		enum { MAX = 10};
		Type items[MAX];
		int top;
	public:
		Stack();
		bool isempty();
		bool isfull();
		bool push(const Type & item);
		bool pop(Type & item);
};
template <typename Type>
Stack<Type>::Stack()
{
	top = 0;
}
template <typename Type>
bool Stack<Type>::isempty()
{
	return top==0;
}
template <typename Type>
bool Stack<Type>::isfull()
{
	return top==MAX;
}
template <typename Type>
bool Stack<Type>::push(const Type & item)
{
	if (top >= MAX)
		return false;
	items[top++] = item;
	return true;
}
template <typename Type>
bool Stack<Type>::pop(Type & item)
{
	if (top <= 0)
		return false;
	item = items[--top];
	return true;
}
int main()
{
	Stack<int> balls;
	Stack<string> strings;

	strings.push("zed");
	strings.push("yasuo");
	strings.push("talong");
	return 0;
}
#endif
