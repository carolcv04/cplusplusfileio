#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//determines the maximum value in the array
void maxval(int* x, int size){
    int maxval = x[0];
    int *p = &x[0];
    
    for(int i=0; i < size ; i++){
        if(maxval < *p){
            maxval = x[i];
        }
        p++;
    }

    cout << "Maximum Value: " << maxval << endl;
}
//determined the mininmu avlue in the arrray
void minval(int* x, int size){
    int minval = x[0];
    int *p = &x[0];

    for(int i=0; i < size ; i++){
        if(minval > *p){
            minval = x[i];
        }
        p++;
    }

    cout << "Minimum Value: " << minval << endl;
}
//reverses the array
void rev_array(int* x, int size){
    cout << "Reversed Array: " << endl; 
    int *p = &x[size-1];
    for (int i = 0; i < size; i++){
        cout << *p << " ";
        p--;
    }
    cout << endl;
}
//sums up all the array elements
void sum_array(int* x, int size){
    int sum = 0;
    int *p = &x[0];

    for(int i=0; i < size; i++){
        sum += *p;
        p++;
    }
    cout << "Sum of Array Elements: " << sum << endl;
}

int main(int argc, char *argv[]){
    int value,size;
    //array size w command line number, reference from online
    size = std::atoi(argv[1]);
    
    cout << "Your array size is " << size << "." << endl;
    int* array = new int[size];

    cout << "Enter " << size << " integer values." << endl;
    //adds all the values to the array
    for(int i=0; i < size; i++){
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        array[i] = value;
    }
    cout << endl;

    int *p = &array[0];
    cout << "Original Array: " << endl;
    //prints out the original array
    for(int i = 0; i < size; i++){
        cout << *p << " ";
        p++;
    }
    cout << endl;
    cout << endl;
    //calls all the fuctions
    sum_array(array, size);
    maxval(array, size);
    minval(array, size);
    cout << endl;
    rev_array(array, size);

    delete [] array;

    return 0;

}
