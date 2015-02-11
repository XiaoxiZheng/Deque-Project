#include"sDeque.h"
#include <iostream>
#include"time.h"


double elapsed_time;
using namespace std;


int main(int argc, char **argv) {
   // clock_t start
    /*
    clock_t start = clock();

    int op = 0;
    string input, line, str;
    Deque *DQ = new Deque();
    cout << "What is the name of the file you would like to read in?" << endl;
    cin >> input;
    ifstream file; //the file that will be read throughout the program
    file.open(input.c_str()); // open the file
    try {
        while (op < 5){
                getline(file, line); // Saves the line in number of computers as a string.
                op = atoi(line.c_str());
                switch (op) {
                case 0:
                        getline(file, str); // Saves the line in number of computers as a string.
                        DQ->push_front(str);
                        break;
                case 1:
                        getline(file, str); // Saves the line in number of computers as a string.
                        DQ->push_back(str);
                        break;
                case 2:
                        DQ->pop_front();
                        break;
                case 3:
                        DQ->pop_back();
                        break;
                case 4:
                        //DQ -> print_queue();
                        cout << DQ->toStr();
                        break;
                }
        }
    }
    catch (exception& e){
        cout << e.what() << '\n';
    }
    DQ -> ~Deque();
    clock_t finish = clock();
    //finish = clock - start();
    double interval = finish-start/ (double)CLOCKS_PER_SEC;
    cout<<"clock cycles: "<<finish<<endl;
    cout<<"seconds elapsed: "<<interval<<endl;
    return 0;
}
    */

    //for(int i = 0; i < )    cout << d -> empty() << endl;

    clock_t start = clock();
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
            break;

		case 5:
            cout <<"\n\n\nPrint what your Final queue really looks like: " << endl;
			DQ->print_queue();
			break;
		}
	}

    DQ -> ~Deque();

    clock_t finish = clock();
    //finish = clock - start();
    double interval = finish-start/ (double)CLOCKS_PER_SEC;
    cout<<"clock cycles: "<<finish<<endl;
    cout<<"seconds elapsed: "<<interval<<endl;

    return 0;
}


