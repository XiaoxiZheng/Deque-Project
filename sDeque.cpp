#include "sDeque.h"

Deque::Deque(){//default constructor
    queue = new string[9];//the array with the minimal (8) element but with actually 9 containers(including 0)since I decided to use index0 as an "imaginary" pointer position for head;
    size_of_queue = 8;//The capacity of the queue by default is 8
    minSize = 8;
    num_elements = 0;//The # of elements in the array initially is 0
    head = 0; //
    tail = size_of_queue+1; //an imaginary indexing that represents the end of an array(not utilized, and can't be utilized);
    previousHead=0;
    previousTail=0;
}
Deque::~Deque(){
    delete [] queue;
} //Destructor

void Deque::grow(int initiSize, string temp[]){//called when the "old array" is fulled.
    //int size = 2*initiSize;
    queue = new string[initiSize+1];
    cout<<"initialized new array with x2 the space"<<endl;
    //size_of_queue=size;
    //head = size_of_queue/2; //after expansion, the index for new head is at 1/2 of the entire new array
    //tail = size_of_queue+1; // this is an imaginary index that's after the space reserved for the last element
    for(int i=0; i<=num_elements; i++){
        queue[i] = temp[i];
    }



    /*
    queue = new string[size];
    start = size/4; //a temp head that is 1/4 into the array.
    for(int i=0; i< num_elements; i++){ // copying stuff from old array to new array.
        queue[start] = temp[i];
        start++;
    }*/
}

void Deque::shrink(int initiSize, string temp[]){ //called when the array is only 1/4 full, and shrinks the size of array to 1/2 of previous
    //size_of_queue = initiSize/2;
    cout<<"shrink the array to 1/2 of previous size(because of the # of elements presented)"<<endl;
    queue = new string[initiSize+1];


   //going to write a long if/else statement to create this stupid new array..
  /* if(tail<size_of_queue+1){
     for(i=tail+1;i<size_of_queue+1；i++){
        j=1;
        queue[j]=temp[i];
        tail++;
     }
   if(tail==size_of_queue+1){
    tail=0;
   }
    if(tail=0){

    }

   }*/
    /*
    for(int i=0; i<=num_elements; i++){
        queue[i] = temp[i];             //this method of copying array doesn't always work bc it doesn't account
                                        //what happens if the array was initially expanded with empty spaces in the middle
    }
    */
    int j=1;
    for(int i=tail;j<=head;i++){
        queue[j]=temp[i];
        j++;
    }
}
void Deque::push_front(string element){
    if(num_elements==size_of_queue){
        cout<<"realizes its full"<<endl;//if that happens the current array is fulled...need to resize
        grow(size_of_queue*2, queue);//calls grow helper method, which x2 the size of array.
        cout<<"successfully called grow"<<endl;
        size_of_queue=size_of_queue*2;
        head = size_of_queue/2;
        tail = size_of_queue+1; //+1;
        queue[++head] = element;
        num_elements++;
         //head = head+1;
    }
    else{
       queue[++head] = element;
       // head = head%size_of_queue;
        num_elements++;

    }

}
void Deque::push_back(string element ){
    if(num_elements==size_of_queue){//if the array is  full, do the following
        cout<<"realizes its full"<<endl;//if that happens the current array is fulled...need to resize
        grow(size_of_queue*2, queue);//calls grow helper method, which x2 the size of array.
        cout<<"successfully called grow"<<endl;
        size_of_queue=size_of_queue*2;
        head = size_of_queue/2;
        tail = size_of_queue+1; ////tail is always the size of queue+1(an imaginary position for pointer purposes
        queue[--tail] = element;
        num_elements++;
    }
    // NOTE: head++ == tails when the array is either full or empty...I need to consider all cases!!!!

    else{
        queue[--tail] = element;
       // head = head%size_of_queue;
        num_elements++;

    }
}
string Deque::pop_front(){
    string remove;//a local temp variable that saves the string to be removed
    if((num_elements<= (size_of_queue/4))&& (size_of_queue > minSize)){ //always check if num_of_elements reached below the 1/4 line
        shrink(size_of_queue/2, queue);//if it does, then call the shrink helper method
        cout<<"shrinks successfully"<<endl;
        size_of_queue = size_of_queue/2;
        int previousHead = head; //the previous head before the new pointers gets new locations.


        head=size_of_queue/2;
        tail=size_of_queue+1;

        remove = queue[previousHead];//again head is a pointer that is always +1 then the actual element, so set the element to be removed.
        string temp = queue[previousHead];
        queue[previousHead]="";//after set it to remove, replace whatever element that was in there previously with an empty string
        //head-- ; //decrement head
        num_elements--; //subtract the num of elements inside the array.
        cout<<"You just removed: " << temp <<endl;

    }
    else if(head==0){ // if the head reaches 0, the array has reached the leftMost end of the array.
        //I'm not sure if we should implement poping from tail from this point on....(like a ciruclar-loop)
        cout<<"leftMost of the array reached"<<endl;
        head = size_of_queue+1;//wrap around and set the new position of head to the end of the array+1(or the initial tail position)
        int x = head--; //bc head[0] && head[size_of_queue+1] both doesn't contain any elements..
        remove = queue[x];
        string temp = queue[x];
        queue[x] ="";
        num_elements--;
        cout<<"You just removed: " << temp <<endl;
    }
    else if((head+1)==tail){
        //if somehow I implemented the above, this can happen during poping...        cout<<"You have poped everything out of your array!!consider pushing in some new stuff"<<endl;
    }
    else{
        int x = head--;
        remove = queue[x];//
        string temp = queue[x];
        queue[x]="";//after set it to remove, replace whatever element that was in there previously with an empty string
        //head-- ; //decrement head
        num_elements--; //subtract the num of elements inside the array.
        cout<<"You just removed: " << temp <<endl;
    }
    return remove;
}
string Deque::pop_back(){
    string remove;//a local temp variable that saves the string to be removed
    if((num_elements<= (size_of_queue/4))&& (size_of_queue > minSize)){ //always check if num_of_elements reached below the 1/4 line
        shrink(size_of_queue, queue);//if it does, then call the shrink helper method
        int previousTail = tail;//stores previous tail before tail changes.
        size_of_queue = size_of_queue/2;
        tail=size_of_queue+1;
        head=size_of_queue/2;//new head is @ the new size/2
        remove = queue[previousTail];//again head is a pointer that is always +1 then the actual element, so set the element to be removed.
        queue[previousTail]="";//after set it to remove, replace whatever element that was in there previously with an empty string
        num_elements--; //subtract the num of elements inside the array.
    }
    else if(tail==(size_of_queue+1)){ // if the head reaches sizeOfQueue +1(the initial tail position), the array has reached the rightMost end of the array.
        cout<<"rightMost of the array"<<endl;
        tail = 1; //turn the tail pointer around to point to 1, and pop it.
        int x = tail++;
        remove = queue[x];
        string temp = queue[x];
        queue[x] ="";
        num_elements--;
        cout<<"You just removed: " << temp <<endl;
    }
    else if(tail==head+1){ //if some-how I implemented the else if statement above, happens when it popped everything from both ends...
        cout<<"You have poped everything out of this queue...considering pushing in something?"<<endl;
    }
    else{
        int x = tail++;
        remove = queue[x];//again head is a pointer that is always +1 then the actual element, so set the element to be removed.
        string temp = queue[x];
        queue[x]="";//after set it to remove, replace whatever element that was in there previously with an empty string
        //head-- ; //decrement head
        num_elements--; //subtract the num of elements inside the array.
        cout<<"You just removed: " << temp <<endl;
    }
    return remove;

}
int Deque::size(){
    return num_elements;
}
bool Deque::empty(){
    return (num_elements ==0);
}

string Deque::toStr(){
	string output = "";
	stringstream ss;
	for(int i = 0; i < size_of_queue+1; i++) {
		string temp = queue[i];
		if(temp == "") {
			ss << i;
		    output = output + "Index position " + ss.str() +  " is empty.\n";
		}
		else {
			ss << i;
		    output = output + "The content at index position " + ss.str() + " is: " + temp + "\n";
		}
	}
   return output;
}

void Deque::print_queue(){
    cout << "\n\n\nThe size_of_queue size of the queue is: " << size_of_queue<< endl;
    cout << "There are " << num_elements << " elements in the array" << endl;
    for(int i = 1; i <size_of_queue +1; i++) {
        string temp = queue[i];
        if(temp == "") {
            cout << "Index position " << i << " is empty." << endl;
        }
        else {
            cout << "The content at the index position " << i << " is: " << temp << endl;
        }
    }
    cout << "\n\n\n" << endl;
}

