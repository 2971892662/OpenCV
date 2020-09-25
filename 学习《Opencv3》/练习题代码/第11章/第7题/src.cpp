#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//不知道题里的圆圈是什么，题有问题。

int main()
{
    Mat src = imread("F:/20.png",0);
    imshow("src", src);

    Mat result;
    equalizeHist(src, result);
    imshow("result", result);

    waitKey(0);
    return 0;
}


