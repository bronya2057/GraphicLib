#include <iostream>
////VC++Directories EXECUTABLE DIRECTORY
//#include "GraphicLibrary/GraphicLib.hpp"
//#include "GraphicLibraryDLL/GraphicLibDll.hpp"
#include "GraphicLibrary/GraphicLib.hpp"
using namespace PointsAndLines;

int main()
{
   
   //PointsAndLines::Point2D a(1.0, 5.0);
   //Point2D b(-2, 0);
   //float slope = calculateSlope(a,b);
   //std::cout << slope;
   //float perpendicularSlope = perpSlope(21.0);
   //std::cout << perpendicularSlope;
   //bool isPerpendicular = arePerp(slope, calculateSlope(Point2D(1.0, 10.0), Point2D(-2, 0)));
   //std::cout << isPerpendicular;
   //std::cout<<MathLibrary::Functions::Add(2.3, 3.2);

   CircleAndSphere::Circle a1(PointsAndLines::Point2D(70, 20), 400);
   CircleAndSphere::Circle b1(PointsAndLines::Point2D(50, 60), 16);
   std::cout<<CircleAndSphere::isCircleCollided(a1, b1);

   CircleAndSphere::Circle a2(PointsAndLines::Point2D(30, 20), 400);
   CircleAndSphere::Circle b2(PointsAndLines::Point2D(40, 50), 2500);
   std::cout << CircleAndSphere::isCircleCollided(a2, b2);

   Point2D aa(3, 4);
   Point2D bb(43, 4);

   Point2D cc = aa + bb;
   std::cout << cc;

   //std::cout << Trigonometry::convertToRadian(90);
   Trigonometry::TrigonometryTables tables;
   Trigonometry::cacheSineTable();
   std::cout<<tables.sinTable[90];
   

   // Calculate the sine of any angle
   const float value = Trigonometry::getSinusValue(67);

   std::cout <<"\nValue of sinus = "<<value;
}
