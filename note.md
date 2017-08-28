fgets(s, 100, stdin) 读取的时候会读进来\n

scanf 读取字符串的时候以空格为界

最大值，最小值
#include <limits>
int imin = std::numeric_limits<int>::min();
int imax = std::numeric_limits<int>::max();
float fmin = std::numeric_limits<float>::min();
float fmax = std::numeric_limits<float>::max();

#include <limits.h>
then use
int imin = INT_MIN; // minimum value
int imax = INT_MAX;
#include <float.h>
float fmin = FLT_MIN;  // minimum positive value
double dmin = DBL_MIN; // minimum positive value
float fmax = FLT_MAX;
double dmax = DBL_MAX;




