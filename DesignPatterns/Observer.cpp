#include <iostream>
#include <list>
#include <string>

using namespace std;

class ISubscriber
{
public :
	virtual void notify(string msg) = 0;
};

class User : public ISubscriber //observer 
{
	private:
		int userId;
	public:
		User(int _userId = 0) : userId(_userId){}
		void notify(string msg) {
			cout << userId << " got notification, Message ::" << msg << endl;
		}	
};

class Group {
	list<ISubscriber*> users; //list of observers
public :
	void subscribe(ISubscriber* user) { // Subscriber
		users.push_back(user);
	}
	void unsubscribe(ISubscriber* user) { // unsubcribe
		users.remove(user);
	}
	void notify(string msg) { // 
		for (auto user : users) 
		{
			user->notify(msg);
		}
	}
}; //Subject


int main()
{
	Group* group = new Group();

	User* user1 = new User(1);
	User* user2 = new User(2);
	User* user3 = new User(3);

	group->subscribe(user1);
	group->subscribe(user2);
	group->subscribe(user3);

	group->notify("new Notification");
	group->unsubscribe(user1);
	group->notify("latest Notification");

	return 0;
}

