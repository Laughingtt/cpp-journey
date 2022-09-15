#include <iostream>
#include "Shape.h"

using namespace std;

int main()
{
    Shape *rect =new Rectangle(3,4);
    cout <<rect->GetPircumference()<<endl;
//    Shape *cirle =new Circle(5);
//    cout <<cirle->GetPircumference()<<endl;
    return 0;
}