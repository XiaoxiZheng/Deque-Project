#include"sDeque.h"
#include <iostream>


using namespace std;
int main(int argc, char **argv) {
	int op=0;
	std::string input;
	Deque *DQ = new Deque();

	while (op<6)
	{
        cout << "\n Welcome to the program, " << endl;
        cout << "\n Please enter your option" << endl;
        cout << " || 0--push_front || 1--push back || 2--pop front || 3--pop back || "<< endl;
        cout << " || 4--toStr() method|| 5--print your final queue ||" << endl;
        cout<<endl;
		std::cin>> op;
		switch(op) {
		case 0:
			std::cin>>input;
			DQ->push_front(input);
			break;
		case 1:
			std::cin>>input;
			DQ->push_back(input);
			break;
		case 2:
			DQ->pop_front();
			break;
		case 3:
			DQ->pop_back();
			break;
		case 4:
            DQ->toStr();

		case 5:
            cout <<"\n\n\nYour Final queue looks like: " << endl;
			DQ->print_queue();
			break;
		}

	}
    DQ -> ~Deque();
	return 0;

}
/*
    d->print_queue();
    for(int i = 0; i  < 40;  i++) {
        d->pop_back();
        d->pop_front();
    }
*/
