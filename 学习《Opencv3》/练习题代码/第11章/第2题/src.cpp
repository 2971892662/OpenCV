#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//不知道题里的圆圈是什么，题有问题。

int main()
{
    Mat src = imread("F:/10.png");
    imshow("src", src);

    //a.top left
    Mat a;
    logPolar(src, a, Point2f(173,87),40,INTER_LINEAR|WARP_FILL_OUTLIERS);
    imshow("a", a);

    //b.center
    Mat b;
    logPolar(src, b, Point2f(321,234), 40, INTER_LINEAR | WARP_FILL_OUTLIERS);
    imshow("b", b);
    /*不知道那条黑线是怎么来的*/


    waitKey(0);
    return 0;
}


