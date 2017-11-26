#include "GraphicLib.hpp"
#include <cmath>

namespace PointsAndLines
{
Point2D::Point2D(float xCoord, float yCoord)
   :x(xCoord), y(yCoord)
{
}

Point3D::Point3D(float xCoord, float yCoord, float zCoord)
   : x(xCoord), y(yCoord), z(zCoord)
{
}

float calculateSlope(const Point2D p, const Point2D q)
{
   return (p.y - q.y) / (p.x - q.x);
}

float perpSlope(float slope)
{
   return (-1) / slope;
}

bool arePerp(float slope1, float slope2)
{
   bool result = false;

   if (slope1 * slope2 == -1)
   {
      result = true;
   }

   return result;
}

Point2D lineIntersectPoint(Point2D L1Point, float L1Slope, Point2D L2Point, float L2Slope)
{
   // A temp array for holding our answer
   Point2D temp(0, 0);
   // Solve for our x value of the solution
   temp.x = (L1Slope * L1Point.x - L2Slope * L2Point.x + L2Point.y - L1Point.y) / (L1Slope - L2Slope);
   // Use our new-found value to solve for our y value
   temp.y = L1Slope * (temp.x - L1Point.x) + L1Point.y;

   return temp;
}

float distanceBetweenPoints2D(Point2D& P1, Point2D& P2)
{
   return sqrtf(powf(P2.x - P1.x, 2) + powf(P2.y - P1.y, 2));
}

float distanceBetweenPoints2DOptimized(Point2D& P1, Point2D& P2)
{
   return powf(P2.x - P1.x, 2) + powf(P2.y - P1.y, 2);
}

const Point2D findMidPoint2D(Point2D& P1, Point2D& P2)
{
   // Allocate enough memory to our pointer
   Point2D temp(0, 0);
   // Calculate our midpoint
   temp.x = (P1.x + P2.x) / 2.0f;
   temp.y = (P1.y + P2.y) / 2.0f;
   // Return our answer
   return temp;
}
}

namespace CircleAndSphere
{
Circle::Circle(const PointsAndLines::Point2D& pt, const float rad)
   : center(pt)
   , radius(rad)
{
}

Sphere::Sphere(const PointsAndLines::Point3D& pt, const float rad)
   : center(pt)
   , radius(rad)
{
}

bool isCircleCollided(Circle& circleA, Circle& circleB)
{
   return (PointsAndLines::distanceBetweenPoints2DOptimized(circleB.center, circleA.center)) <= powf(circleA.radius + circleB.radius, 2);
}

}

namespace Trigonometry
{
std::array<float, 360> TrigonometryTables::sinTable;

void cacheSineTable()
{
   for (int degree = 0; degree < 360; ++degree)
   {
      // Remember our DegToRad #define from before, PI / 180
      TrigonometryTables::sinTable[degree] = sin(convertToRadian(degree));
   }
}

float convertToRadian(const int degree)
{
   return degree * DegToRad;
}

float convertToDegree(const float radian)
{
   return radian * RadToDeg;
}

float getSinusValue(const int angle)
{
   return TrigonometryTables::sinTable[abs(angle) % 360];
}
}
