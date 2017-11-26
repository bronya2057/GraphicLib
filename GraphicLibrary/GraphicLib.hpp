#ifndef GRAPHICLIB_HPP
#define GRAPHICLIB_HPP
#include <ostream>
#include <array>

/****************************************************
*
*                 COMMON DEFINES
*
***************************************************/
namespace CommonDefines
{
   //Radians * RadToDeg = Degrees
#define RadToDeg  57.29577951f
#define DegToRad  0.017453293f
#define PI        3.14159265
#define InversePI 0.31830989 //1/PI
}

/****************************************************
*
*                POINTS AND LINES
*
***************************************************/
namespace PointsAndLines
{
struct Point2D
{
   Point2D(float xCoord, float yCoord);
   float x;
   float y;

   Point2D operator+ (const Point2D& otherPoint) const
   {
      return Point2D(this->x + otherPoint.x, this->y + otherPoint.y);
   }

   friend std::ostream& operator<<(std::ostream &out, const Point2D& point)
   {
      out <<"POINT X:" <<point.x <<" Y:"<< point.y<<"\n";
      return out;
   }
};

struct Point3D
{
   Point3D(float xCoord, float yCoord, float zCoord);
   float x;
   float y;
   float z;
};


// Calculate the slope of a line given 2 points
float calculateSlope(const Point2D p, const Point2D q);

// Determine the slope of the line perpendicular to ourselves
float perpSlope(float slope);

// purpose: to determine whether two lines are perpendicular
// output: true if the lines are perpendicular, else false
bool arePerp(float slope1, float slope2);

// purpose: find the point of intersection between two lines
// input 2points(x,y) and 2slopes (m)
// output: point of intersection
//y – y1 = m1(x – x1)
//y – y2 = m2(x – x2)
// x = (m1x1 – m2x2 + y2 – y1) / (m1 – m2)
Point2D lineIntersectPoint(Point2D L1Point, float L1Slope, Point2D L2Point, float L2Slope);

// purpose: to calculate the distance between two points
// input: P1- an array of 2 floats representing point 1
//        P2- an array of 2 floats representing point 2
// output: the distance between the two points
float distanceBetweenPoints2D(Point2D& P1, Point2D& P2);

// purpose: calculate the midpoint of a line segment
// output: the midpoint between the two points
const Point2D findMidPoint2D(Point2D& P1, Point2D& P2);
}

/****************************************************
*
*                 CIRCLE AND SPHERE
*
***************************************************/

namespace CircleAndSphere
{
struct Circle
{
   Circle(const PointsAndLines::Point2D& pt, const float rad);
   PointsAndLines::Point2D center;
   float radius;
};
struct Sphere
{
   Sphere(const PointsAndLines::Point3D& pt, const float rad);
   PointsAndLines::Point3D center;
   float radius;
};
bool isCircleCollided(Circle& circleA, Circle& circleB);
}

/****************************************************
 *
 *                   TRIGONOMETRY
 *
 ***************************************************/
namespace Trigonometry
{
struct TrigonometryTables
{
   static std::array<float, 360> sinTable;
};

void cacheSineTable();

float convertToRadian(const int degree);
float convertToDegree(const float radian);
float getSinusValue(const int angle);

}

/****************************************************
*
*                     VECTORS
*
***************************************************/
namespace Vectors
{
   struct Vector2D
   {
      float x;
      float y;
   };

   struct Vector3D
   {
      float x;
      float y;
      float z;
   };
}
#endif GRAPHICLIB_HPP