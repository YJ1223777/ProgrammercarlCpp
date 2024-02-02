#include <iostream>
#include <vector>
#include<string>

using namespace std;

struct inflatable
{
    string name;
    float volume;
    double price;
};

static int *getNum() {
    int num = 10;
    int *b = &num;
    return b;
}

int main() {
    inflatable guest1 ={"Glorious Gloria",1.88,29.99};
    inflatable guest2 ={};

    int* num = getNum();
    cout << num << endl;
    cout << *num << endl;

    return 0;
}
