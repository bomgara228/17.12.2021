#include <iostream>
using namespace std;
/*class Color {
private:
	unsigned short int m_red;
	unsigned short int m_blue;
	unsigned short int m_green;
public:
	unsigned short int get_red() { return m_red; }
	unsigned short int get_blue() { return m_blue; }
	unsigned short int get_green() { return m_green; }
	void set_red(unsigned short int red) { m_red = red; }
	void set_red(unsigned short int blue) { m_blue = blue; }
	void set_red(unsigned short int green) { m_green = green; }

	
	Color(unsigned short int red=0, unsigned short  int blue=0, unsigned short int green=0):
		m_red{ red },
		m_blue{ blue },
		m_green{ green}
		 {}
	
	Color(unsigned short int red) { 
		m_red = red; 
		m_green = 0;
		m_blue =0;
	}
	Color(unsigned short int red, unsigned short  int blue) {
		m_red = red;
		m_green = 0;
		m_blue = blue;
	}
	Color(unsigned short int green) { m_green = green; }
	void print() {
		cout << m_red << ' ' << m_green << ' ' << m_blue << endl;
	}
};*/

class Weapon {
protected:
	string m_name;
	int m_damage;
	double m_distance;
public:
	Weapon(string name = "", int damage = 0, double distance = 0.0):
		m_name{ name }, m_damage{ damage }, m_distance{ distance } 
	{}
	void set_name(string name) { m_name = name; }
	void set_damage(int damage) { m_damage = damage; }
	void set_distance(double distance) { m_distance = distance; }
	string get_name() { return m_name; }
	int get_damage() { return m_damage; }
	double get_distance() { return  m_distance; }
	void print() {
		cout << "ima " << m_name << " damage " << m_damage << " distance " << m_distance << endl;
	}
};

class Grenade : public Weapon {
private:
	double m_radius;
public:
	Grenade(string name = "", int damage = 0, double distance = 0.0, double radius = 0.0):
		Weapon(name,damage,distance), m_radius{radius}
	{}
	void set_radius(int radius) { m_radius = radius; }
	double get_radius() { return m_radius; }
	void print() {
		Weapon::print();
		cout << " radius " << m_radius << endl;

	}
	void blow_up() {
		cout << "Grenade babaxnyla" << endl;
	}
};

class Pistol : public Weapon {
private:
	const int ammo_in_aboyma = 15;
	int m_ammo;
public:
	Pistol(string name = "", int damage = 0, double distance = 0.0, int ammo = 0):
	Weapon(name,damage,distance), m_ammo{ammo}
	{}
	void set_ammo(int ammo) { m_ammo = ammo; }
	int get_ammo() { return m_ammo; }
	bool have_ammo() { return m_ammo > 0; }
	void fire() {
		if (have_ammo()) {
			cout << "Fire!\n";
			m_ammo--;
		}
		else cout << "net patronov\n";
	}
	void reload() {
		m_ammo = ammo_in_aboyma;
	}
	void print() {
		Weapon::print();
		cout << " ammo " << m_ammo << endl;

	}
};

int main() {
	Grenade he("F1", 100, 20, 200);
	he.print();
	he.blow_up();
	Pistol p1("deagle", 10, 50, 15);
	while (p1.have_ammo()) {
		p1.fire();
	}
	p1.fire();
	p1.reload();
	p1.print();
}