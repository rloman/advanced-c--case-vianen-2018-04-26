#include <map>
#include <cassert>
#include <iostream>
#include <bitset>
#include <queue>

using namespace std;

enum TypeOfPerson { Guest, Employee, Owner };

struct Person {
	Person() {};
	Person(string name, TypeOfPerson type, bitset<9> appreciation) { m_name = name; m_type = type; m_appreciation = appreciation; }
	string m_name;
	bitset<9> m_appreciation;
	TypeOfPerson m_type;
};

struct Owner : public Person {};
struct Employee : public Person {};
struct Guest : public Person {};

class Hotel {

private:
	map<string, Person> m_guests;
	bitset<9> m_appreciation;
	queue<Person> m_hungryGuests;

public:
	Hotel() { 
		m_guests.clear();
		m_appreciation = bitset<9>(std::string("000000000"));
	}

	void addGuest(Person p) {
		m_guests.insert(pair<string, Person> (p.m_name, p));
		m_appreciation |= p.m_appreciation;
	}

	Person& getGuest(string name) {
		auto search = m_guests.find(name);
		if(search != m_guests.end())
		{
			return m_guests.at(name);
		}
		return Person();	// default person object
	}

	bool isGreatHotel() {
		return m_appreciation.all();
	}

	bool isBadHotel() {
		return m_appreciation.none();
	}

	int getHotelRanking() {
		return m_appreciation.count();
	}

	map<string, Person>& allGuests() {
		return m_guests;
	}

	void addHungryGuest(Person person) {
		m_hungryGuests.push(person);
	}

	void serviceHungryGuest() {
		m_hungryGuests.pop();
	}
};

int main() {
	Person g1{ "Guest1" , TypeOfPerson::Guest, bitset<9>(std::string("000000010")) };
	Person g2{ "Guest2" , TypeOfPerson::Guest, bitset<9>(std::string("000000001")) };
	Person e1{ "Emp1" , TypeOfPerson::Employee, bitset<9>(std::string("000100000")) };
	Person e2{ "Emp2" , TypeOfPerson::Employee, bitset<9>(std::string("000010000")) };
	Person o1{ "Owner" , TypeOfPerson::Owner, bitset<9>(std::string("100000000")) };

	Hotel h;

	h.addGuest(g1);
	h.addGuest(g2);
	h.addGuest(e1);
	h.addGuest(e2);
	h.addGuest(o1);

	for (map<string, Person>::iterator it = h.allGuests().begin(); it != h.allGuests().end(); ++it) {
		cout << (it->second).m_name << "-" << (it->first) << endl;
	}

	assert(h.getGuest("Guest1").m_name == "Guest1");
	assert(h.getGuest("Guest2").m_name == "Guest2");

	h.isGreatHotel() ? cout << "Great" << endl : cout << "Not great" << endl;
	h.isBadHotel() ? cout << "Bad" << endl : cout << "Not bad" << endl;
	cout << h.getHotelRanking() << endl;
	return 0;
}
