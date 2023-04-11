#include <iostream>
#include <exception>

using namespace std;

class BaseException : public exception {
public:
	virtual const char* what() const throw() {
		return "Base exception";
	}
};

class DerivedException : public BaseException {
public:
	virtual const char* what() const throw() {
		return "Derived exception";
	}
};

int main() {
	try {
		// code that might throw exceptions
		throw DerivedException();
	} catch (BaseException& e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	return 0;
}
