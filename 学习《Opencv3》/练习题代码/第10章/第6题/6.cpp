#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/*自适应滤波器的一个例子*/
int main()
{
    Mat src = imread("F:/1.png",0);
    imshow("原图像", src);
    Mat result;
    adaptiveThreshold(src, result, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 2);
    imshow("result", result);
    waitKey(0);
    return 0;
}


