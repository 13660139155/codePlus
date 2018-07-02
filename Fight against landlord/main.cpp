#include <iostream>
#include "LandOwner.h"

using namespace std;

int main()
{
    LandOwner* landowner1 = new LandOwner();
    LandOwner* landowner2 = new LandOwner("´óµØÖ÷","Ë§¸ç");

    landowner1->ShowInfo();
    cout << endl;
    landowner2->ShowInfo();
    cout << endl;
    landowner2->TouchCards(20);

    delete landowner1;
    delete landowner2;
    return 0;
}
