#include <iostream>

using namespace std;

class car {
public:
	virtual void printCardetails() = 0;
};

class toyotoCar : public car {
	void printCardetails() {
		cout << "This is Toyoto Car" << endl;
	}
};

class HyndaiCar : public car {
	void printCardetails() {
		cout << "This is Hyndai Car" << endl;
	}
};

class Bike {
public :
	virtual void printBikeDetails() = 0;
};

class toyotoBike : public Bike {
	void printBikeDetails() {
		cout << "This is Toyoto Bike" << endl;
	}
};

class HyndaiBike : public Bike {
	void printBikeDetails() {
		cout << "This is Hyndai Bike" << endl;
	}
};

class Ifactory {
public :
	virtual car* createCar() = 0;
	virtual Bike* createBike() = 0;
};

class toyotoFactory : public Ifactory {
	car* createCar() {
		return new toyotoCar();
	}

	Bike* createBike() {
		return new toyotoBike();
	}
};

class hyndaiFactory : public Ifactory {
	car* createCar() {
		return new HyndaiCar();
	}

	Bike* createBike() {
		return new HyndaiBike();
	}
};

class VehicleFactory {
public:
	static Ifactory* createfcatory(int type);
};

Ifactory* VehicleFactory::createfcatory(int type) {
	switch (type)
	{
		case 1:
			return new toyotoFactory();
		case 2 : 
			return new hyndaiFactory();
		default:
			break;
	}
}

int main() {
	car* car;
	Bike* bike;
	VehicleFactory* vfact;

	Ifactory* myfact = vfact->createfcatory(2);
	
	car = myfact->createCar();
	bike = myfact->createBike();

	car->printCardetails();
	bike->printBikeDetails();
	return 0;
}