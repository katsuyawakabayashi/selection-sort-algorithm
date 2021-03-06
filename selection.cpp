#include <iostream>


template<class T>
void swap(T& a, T& b){  
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void selectionSort(T* array, int size){
    // target is the value to be campared with
    // minIndex is to be updated with the location of new smaller value
    int target, minIndex, location;

    for(target=0; target<size-1; target++){

        minIndex = target;  // initialize minIndex with target

        for(location=target+1; location<size-1; location++){
            // condition: if element smaller than current minIndex found
            if(array[minIndex]>array[location]){
                // update minIndex
                minIndex = location;
            }
        }
        swap(array[target], array[minIndex]);
    }
};

int main() {
    int size = 100;
    int array[size];
    int randomVal;
    srand(time(0));

    std::cout << "|Before Sort|" << std::endl;

    // generate randomized array and print
    for(int i; i<size; i++){
        randomVal = rand() % 100;
        array[i] = randomVal;
        std:: cout << array[i] << " ";
    }

    std::cout << "\n|After Sort|" << std::endl;

    // selection sort
    selectionSort(array, size);
    

    // print array
    for(int i: array){
        std::cout << i << " "; 
    }

    std::cout << "\nCompelete" << std::endl;
}