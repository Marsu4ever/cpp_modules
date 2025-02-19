#include <iostream>
#include <stack>

class MutantStack : public std::stack
{
	private:

	public:

};

int main(void)
{
	std::stack<int> A;

	A.push(10);
	A.push(20);
	std::cout << "A.top(): " << A.top() << std::endl;
	A.push(30);
	std::cout << "A.top(): " << A.top() << std::endl;
	A.pop();
	std::cout << "A.top(): " << A.top() << std::endl;

	std::cout << "Stack size: " << A.size() << std::endl;
	return (0);
}

// #include <iostream>
// #include <stack>

// int main() {
//     std::stack<int> s;

//     // Push elements into the stack
//     s.push(10);
//     s.push(20);
//     s.push(30);

//     std::cout << "Top element: " << s.top() << std::endl; // 30

//     // Pop an element
//     s.pop();  // Removes 30

//     std::cout << "New top: " << s.top() << std::endl; // 20

//     // Stack size
//     std::cout << "Stack size: " << s.size() << std::endl; // 2

//     return 0;
// }

// #include <iostream>
// #include <stack>

// template<typename T, typename D = std::deque<T>>
// class MutantStack : public std::stack<T, D>
// {
//     private:
//         using std::stack<T>::c;
//     public:
//         typedef typename D::iterator iterator;
//         iterator    begin()
//         {
//             return (c.begin());
//         }

//         iterator    end()
//         {
//             return (c.end());
//         }
// };

// #pragma once
// #include <iostream>
// #include <stack>
// #include <list>

// template<typename T, typename D = std::deque<T>>
// class MutantStack : public std::stack<T, D>
// {
//     private:
//         using std::stack<T>::c;
//     public:
//         typedef typename D::iterator iterator;
//         iterator    begin()
//         {
//             return (c.begin());
//         }

//         iterator    end()
//         {
//             return (c.end());
//         }
// };