#include <iostream>

using namespace std;

/*Interface*/
class vehicle{
	public:
	virtual void printvehicle() = 0;
	static vehicle* createvehicle(int type);
};

/*Interface */
class threewheel : public vehicle {
	void printvehicle() {
		cout << "Three Wheeler";
	}
};

class Fourwheel : public vehicle {
	void printvehicle() {
		cout << "Four Wheeler";
	}
};

/*Factory Method*/
vehicle* vehicle::createvehicle(int type)
{
	vehicle* v;
	switch (type)
	{
		case 1:  v = new threewheel();			
		case 2:  v = new Fourwheel();
		return v;
	}
	
}

class Client {
public :
	Client() {
		int vehicleType = 2;
		vehi = vehicle::createvehicle(vehicleType);
	}
	~Client() {
		delete(vehi);
		vehi = NULL;
	}
	vehicle* getvehicle()
	{
		return vehi;
	}
private:
	vehicle* vehi;
};

int main() {
	Client cli;
	vehicle* v = cli.getvehicle();
	v->printvehicle();
	return 0;
}