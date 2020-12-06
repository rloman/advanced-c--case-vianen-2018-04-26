#include <map>
#include <cassert>
#include <iostream>

using namespace std;

struct Person {

	string name;

	Person() {

	}

	Person(string name) {
		this->name = name;
	}
};

struct Guest : Person {

		Guest() {

		}

		Guest(string name): Person(name) {

		}
};

struct Hotel {

private:


public:
	void addGuest(Guest p) {
	}

	Guest& getGuest(string name) {
	}
};

int main() {

	Guest g1 {"Jan"};
	Guest g2 {"Mike"};

	Hotel h;

// 	h.addGuest ... 
//	h.addGuest ...


	assert(h.getGuest("Jan").name == "Jan");
	assert(h.getGuest("Mike").name == "Mike");

	cout << "End of adding and validating Hotel map" << endl;

};
