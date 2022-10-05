
#include <iostream>

using namespace std;
                    //utilizing binary search to guess the number from 1 to 1,000,000 in 20 tries or less
int main()
{
    int halfer=500000,guess=halfer;  //halfer is used to determine by how much to increase/decrease the number
    char answer;

    for(int i=0;i<20;i++){
        halfer=(halfer+1)/2;
        cout<<i+1<<". is your number: "<<guess<<" ?[s/b/y]:\n";
        cin>>answer;
        switch (answer){
        case 'y':
            i=21;       //getting the iterator over the limit to break out of the loop
            cout<<"\nyour number is: "<<guess;
        case 's':
            guess-=halfer;
            break;
        case 'b':
            guess+=halfer;
            break;
        default:
            cout<<"type:\n"
            <<"s-smaller\n"
            <<"b-bigger\n"
            <<"y-that's the one\n";
            break;
        }
    }
    return 0;
}

