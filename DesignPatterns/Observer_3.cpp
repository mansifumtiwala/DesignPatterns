#include <iostream>
#include <list>
#include <string>

using namespace std;

class Iobserver {
public:
	virtual void Update(string msg) = 0;
};

class AudioObserver : public Iobserver {
	void Update(string msg) {
		cout << "AudioObserver :: " << msg << endl;
	}
};

class DisplayObserver : public Iobserver {
	void Update(string msg) {
		cout << "DisplayObserver :: " << msg << endl;
	}
};

class subject {
	list<Iobserver*> observerlist;

public :
	void notifyAll(int battery) {
		for (auto itr = observerlist.begin(); itr != observerlist.end(); itr++) {
			string message = "Low Power " + std::to_string(battery);
			(* itr)->Update(message);
		}
	}

	void resisterObserver(Iobserver* observer) {
		observerlist.push_back(observer);
	}

	void unregisterObserver(Iobserver* observer) {
		observerlist.remove(observer);
	}

	void checkBatteryLevel(int battery) {
		if (battery < 40) {
			notifyAll(battery);
		}
	}
};



int main()
{
	subject* sub = new subject();

	AudioObserver *audio = new AudioObserver();
	DisplayObserver *display = new DisplayObserver();

	sub->resisterObserver(audio);
	sub->resisterObserver(display);
	sub->checkBatteryLevel(39);
	sub->unregisterObserver(display);
	sub->checkBatteryLevel(32);
}