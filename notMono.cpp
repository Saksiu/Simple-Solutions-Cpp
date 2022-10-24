
#include <iostream>



size_t monot(const int a[], size_t size, size_t& len) {

    int index = 0;                          //used to mark the index of the beggining of the current biggest monotonic row
    bool increasing;                        //used to know wether the current row of numbers is monotonically increasing or not
    bool first=true;                        
    int maxlen = 0;
    len = 0;                                //reset for every array

    for (int i = 1; i < size; i++) {

        len++;
        
        if (a[i - 1] > a[i]) {              //if  the numbers are getting smaller
            if (first) {                    //if its the first time the numbers are increasing, mark it so
                increasing = false;
                first = false;
            }
                
            if (increasing) {               //if the numbers were getting bigger
                increasing = false;

                if (len > maxlen) {
                    
                    index = i-len;
                    maxlen = len;
                }
                len = 1;
            }
        }
        else if (a[i-1]<a[i]) {             //if the numbers are getting bigger
            if (first) {                    //same as above, but in the event the numbers are decreasing the first time
                increasing = true;
                first = false;
            }
            if (!increasing) {              //if the numbers were getting smaller
                increasing = true;
                if (len > maxlen) {
                    index = i-len;
                    maxlen = len;
                }   
                len = 1;
            }
        }                       
    }

    if (((increasing && (a[size - 1] > a[size - 2]))        //If the last number in the last monotonical row is also monotonical 
        ||(!increasing && (a[size - 1] < a[size - 2]))      //(i.e. also decreasing, increasing, or staying constant)
        || (a[size - 1] == a[size - 2]))                    //check if its bigger than the previous biggest row. If so, mark it as the answer
                                                        
        &&(len + 1 > maxlen)) {                             //done this way because the program checks if the row is the answer only when numbers are changing course
        maxlen = len + 1;                                   //that's why it will only check the last number only if its bigger or smaller than the previous one
        index = size - maxlen;                              //this snippet fixes that
    }

    len = maxlen;
    return index;

}

void printResult(const int a[], size_t size, size_t ind, size_t len) {
    using std::cout;

    cout << "In array [ ";
    for (size_t i = 0; i < size; ++i) 
        cout << a[i] << " ";

    cout << "]\nthe first longest ""monotonic sequence is\n[ ";

    for (size_t i = ind; i < ind + len; ++i)
        cout << a[i] << " ";

    cout << "] starting at index " << ind << " and of length " << len << "\n\n";
}

int main()
{
    size_t len = 0, ind = 0, size = 0;
    int a1[] = { 4,4,5,4,4 };
    size = sizeof(a1) / sizeof(*a1);
    ind = monot(a1, size, len);
    printResult(a1, size, ind, len);


    int a2[] = { 4,4,5,4,4,4 };
    size = sizeof(a2) / sizeof(*a2);
    ind = monot(a2, size, len);
    printResult(a2, size, ind, len);


    int a3[] = { 4,5,4,4,5 };
    size = sizeof(a3) / sizeof(*a3);
    ind = monot(a3, size, len);
    printResult(a3, size, ind, len);

}
