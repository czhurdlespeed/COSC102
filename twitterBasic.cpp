#include <vector>
#include <iostream>
using namespace std;

class User {
    private:
        string username;
        vector <User *> following;
    public:
        User(string name);
        void follow(User* newFollow);
        void printWhoIFollow() const;
        void setUsername(string newName);
};

User::User(string name) {
    username = name;
}

void User::follow(User *newFollow) {
    following.push_back(newFollow); // The "following" vector hold User*'s ... so we must also pb User*'s
}

void User::printWhoIFollow() const {
    cout << username << " follows these users: " << endl;
    for (int i = 0; i < following.size(); i++) {
        cout << "  " << following[i]->username << endl; /* B/c following[i] is a USER*, it's an addr. Instead of a dot op, I use -> */
    }
}

void User::setUsername(string newName) {
    username = newName;
}

int main() {
    /* Create objects in memory using pointers */
    User *me = new User("ccrumpto");
    User *ls = new User("lukeskywalker");
    User *ts = new User("taylorswift");
    User *pm = new User("peytonmanning");
    database <User *> allTwitterUsers;
    

    /* I'm going to follow Luke, Taylor, and Peyton. */
    me->follow(ls);
    me->follow(ts);
    me->follow(pm);

    /* Let's see if following these users worked. */
    me->printWhoIFollow();

    /* Let's say Peyton decides to change his username */
    pm->setUsername("peytonOfficial");

    me->printWhoIFollow();

}