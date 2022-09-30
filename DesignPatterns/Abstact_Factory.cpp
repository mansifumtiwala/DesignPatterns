#include <iostream>
using namespace std;

class Button {
public:
	virtual void printButtondetails() = 0;
};

class MacButton : public Button {
public:
	void printButtondetails() {
		cout << "Mac Button\n";
	}
};

class WindowsButton : public Button {
public:
	void printButtondetails() {
		cout << "windows Button\n";
	}
};

class textbox {
public:
	virtual void printtextboxdetails() = 0;
};

class Mactextbox : public textbox {
public:
	void printtextboxdetails() {
		cout << "Mac textBox\n";
	}
};

class Windowstextbox : public textbox {
public:
	void printtextboxdetails() {
		cout << "windows Textbox\n";
	}
};


class Ifactory
{
	public : 
		virtual Button* createButton() = 0;
		virtual textbox* createtextbox() = 0;

};

class MacFactory : public Ifactory{
	public:
		Button* createButton() {
			return new MacButton;
		}
		
		textbox* createtextbox() {
			return new Mactextbox;
		}
};

class WinFactory : public Ifactory{
public:
	Button* createButton() {
		return new WindowsButton();
	}

	textbox* createtextbox() {
		return new Windowstextbox();
	}
};

class GuiFactory
{
public :
	static Ifactory* createFactory(string osType);
};

Ifactory* GuiFactory::createFactory(string osType) {
	if (osType.compare("windows") == 0) {
		return new WinFactory();
	}

	else if (osType.compare("mac") == 0) {
		return new MacFactory();
	}
}

int main() {
	string osType;
	cout << "Enter Os Type";
	cin >> osType;
	
	Ifactory* ifact = GuiFactory::createFactory(osType);
	Button* ibtn = ifact->createButton();
	ibtn->printButtondetails();

	textbox* itxt = ifact->createtextbox();
	itxt->printtextboxdetails();
	return 0;
}