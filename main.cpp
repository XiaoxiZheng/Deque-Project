#include"tDeque.h"
using namespace std;

double elapsed_time;
using namespace std;


int main(int argc, char **argv) {
	int op=0;
	//std::string input;
   // std::int input;
      string input;
      Deque<string> *DQ = new Deque<string>();
    //Deque<int> DQ;
	//Deque *DQ = new T();
	while (op<7)
	{

        cout << "\n Welcome to the program, " << endl;
        cout << "\n Please enter your option" << endl;
        cout << " || 0--push_front || 1--push back || 2--pop front || 3--pop back || "<< endl;
        cout << " || 4--toStr() method|| 5--array size || 6---if queue is empty" << endl;
        cout<<endl;

		std::cin>> op;
		switch(op) {

		case 0:
			std::cin>>input;
			try {
				DQ->push_front(input);
			} catch (exception e) {
				cout<<"Out of Memory Exception!"<<endl;
			}
			break;
		case 1:
            std::cin>>input;
			try{
				DQ->push_back(input);
			} catch (exception e) {
				cout<<"Out of Memory Exception!"<<endl;
			}
			break;
		case 2:
			try{
				std::cout<<DQ->pop_front()<<std::endl;
			} catch (exception e) {
				cout<<"Caught Exception for empty stack!"<<endl;
			}
			break;
		case 3:
			try{
				std::cout<<DQ->pop_back()<<std::endl;
			} catch (exception e) {
				cout<<"Caught Exception for empty stack!"<<endl;
			}
			break;
		case 4:
            cout<<DQ->toStr()<<endl;
            break;
        case 5:
           std::cout<<DQ->size()<<std::endl;
            break;
        case 6:
            std::cout<<DQ->empty()<<std::endl;
            break;
		}

	}

    // DQ -> ~Deque();
   DQ ->~Deque();
    return 0;
}


