// DesignPatterns.cpp : Factory Design Pattern

#include <iostream>
using namespace std;

class vehicle{
public:
    virtual void printvehicle() = 0;
};

class twowheler : public vehicle {
    void printvehicle() {
        cout << "Hi from Twowheler class" << endl;
    }
};

class threewheler : public vehicle {
    void printvehicle() {
        cout << "Hi from Three wheler class" << endl;
    }
};

class createvehicle{
public:
    createvehicle(int i) {
        switch (i)
        {
            case 1 : 
                pvehicle = new twowheler();
                break;
            case 2 :
                pvehicle = new threewheler();
                break;
        }
    }

    ~createvehicle() {
        cout << "Bye from destrucor";
        delete(pvehicle);
        pvehicle = NULL;
    }
    
    vehicle* getVehicle() { return pvehicle; }

private:
    vehicle* pvehicle = NULL;
};

int main()
{
    //createvehicle create(1); //Object Creation this way also Works
    createvehicle *create = new createvehicle(2);
    vehicle *pvehi = create->getVehicle();
    pvehi->printvehicle();
    return 0;
}