//
// Created by Frank Lin on 3/11/21.
//

#include <cmath>
#include <iostream>
//using namespace std;
//
//struct polar{
//    double distance;
//    double angle;
//};
//
//
//struct rect{
//    double x;
//    double y;
//};
//
//polar rect2polar1(rect xypos){
//    polar po;
//    po.distance = sqrt(xypos.x*xypos.x + xypos.y*xypos.y);
//    po.angle= atan2(xypos.y, xypos.x);
//    return po;
//}
//void rect2polar(const rect *xypos, polar *ans){
//    ans->distance = sqrt(xypos->x * xypos->x + xypos->y * xypos->y);
//    ans->angle= atan2(xypos->y, xypos->x);
//}
#include <ostream>
typedef unsigned char BYTE;
int int_to_card16(BYTE ** p, unsigned int v)
{
if (v > 0xFFFF)
return -1;

(*p)[0] = (v >> 8) & 0xFF;
(*p)[1] = (v & 0xFF);

*p += 2;

return v;
}

int main() {
    char str[6] = "abcde";
    char t[2*6] = { 0 };
    int i;

    for (i = 0; i <= 5; ++i)
    {
        snprintf(t+2*i, sizeof(t)-2*(i), "%02x", str[i]);
    }
    printf("\t%s",t);
    return 0;
}