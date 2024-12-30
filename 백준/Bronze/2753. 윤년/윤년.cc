#include <iostream>
using namespace std;
int leapyear(int y){
    if(y % 4 == 0){
        if(y%100 == 0){
            if(y%400 == 0)
                return 1;
            else
                return 0;
        }
        return 1;
    }
    return 0;
}
int main(){
    int n;
    cin >> n;
    cout << leapyear(n);
}