#include <iostream>
using namespace std;

namespace name {
	char firstname[] = "John";
}


int main() {
	using namespace name;


	cout << firstname;
}
