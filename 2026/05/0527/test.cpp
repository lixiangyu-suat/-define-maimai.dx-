#include <iostream>

void foo(){
    int i;
    std::cout << i;
    i = 6666;
}

int main(){
    foo();
    foo();
    return 0;
}