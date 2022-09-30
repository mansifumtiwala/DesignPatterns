#include <iostream>

class Settings {
	static Settings*  _instance; // Singleton Instance kept Static
	int volume;
	int brightness;

	Settings() : volume(100), brightness(50) {} // private Constructor

public :
	static Settings* createInstance() {
		if (NULL == _instance) {
			_instance = new Settings();
		}
		return _instance;
	}

	void setvolume(int vol) { volume = vol; }
	void setbrightness(int x) { brightness = x; }
	int getvolume() { return volume; }
	int getbrightness() { return brightness; }

	void printSettings() {
		std::cout << "Volume ::" << volume << std::endl;
		std::cout << "Brightness ::" << brightness << std::endl;
	}
};

Settings* Settings::_instance;


void somefunction()
{
	Settings* set = Settings::createInstance();
	set->printSettings();
}

int main()
{
	Settings* set = Settings::createInstance();
	set->printSettings();
	set->setbrightness(40);
	set->setvolume(98);
	somefunction();
	return 0;
}