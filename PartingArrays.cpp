#include <iostream>
#include <string>
#include <ctime>
#include <utility>

//Written by: Maks Spisjak s25303

template <typename T, typename FUN>
size_t part(T* arr, size_t size, FUN f) {	//the function "parts" any given array with all of it's elements
	size_t leftIndex=0;						//checking true with the f Function on the left, leaving all
	for(size_t i=0;i<size;i++)				//non-f-true elements on the right side of the array.
		if(f(arr[i])){
			std::swap(arr[i],arr[leftIndex]);
			leftIndex++;
		}
			
	return leftIndex;
}

template <typename T>
void printTab(const T* t, size_t size) {	//simple function to print any given array in a line with brackets.

	using std::cout,std::endl;
	cout<<"[ ";
    
	for(size_t i=0;i<size;i++)
		cout<<t[i]<<" ";

	cout<<"]";

}

bool isEven(int e) { return e%2 == 0; }

int main() {
    size_t ind = 0;

    int a1[] = {1,2,3,4,5,6};
    ind = part(a1,6,isEven);
    std::cout << "\nind = " << ind << " ";
    printTab(a1,6);

    int a2[] = {1,2,3,4,5,6};
    auto isOdd=[](int e){return e%2==1;};
    ind = part(a2, std::size(a2), isOdd);
    std::cout << "\nind = " << ind << " ";
	printTab(a2,std::size(a2));

     std::string a3[] = {"Ala", "Ula", "Ela", "Ola", "Maja"};
     std::string mn = "Bea";
     std::string mx = "Sue";
    auto isInRange=[mn,mx](std::string e){return e>mn&&e<mx;};
     ind = part(a3, std::size(a3), isInRange);
     std::cout << "\nind = " << ind << " ";
     printTab(a3,std::size(a3));

     constexpr size_t DIM = 500000;	//used to get 500000 random numbers from 1 to 21
     int* a4 = new int[DIM];
     srand(unsigned(time(0)));
     for (size_t i = 0; i < DIM; ++i) a4[i] = rand()%21+1;
     auto isDivisibleBySeven=[](int e){return e%7==0;};
     ind = part(a4, DIM, isDivisibleBySeven);
     std::cout << "\nind = " << ind<<std::endl;
     delete [] a4;
}