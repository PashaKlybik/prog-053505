#include <iostream>

using namespace std;

struct Stack
{
	int top = -1;
	int arr[32];

	void push(int inf)
	{
		if (top > 31) return;
		arr[++top] = inf;
	}

	int get()
	{
		if (top == -1) return 0;
		return arr[top--];
	}

	void show()
	{
		for (int i = top; i > -1; i--) cout << arr[i] << ' ';
	}
};

int main()
{
	// Stack 1:
	Stack s1;
	int n;
	cout << "Enter stack size: "; cin >> n;

	cout << "Enter stack: ";
	int inf;
	for (int i = 0; i < n; i++)
	{
		cin >> inf;
		s1.push(inf);
	}

	cout << endl << "Stack 1: ";
	s1.show();

	// Stack 2:
	Stack s2;
	for (int i = s1.top; i > -1; i--) s2.push(s1.get());

	cout << endl << "Stack 2: ";
	s2.show();

	return 0;
}