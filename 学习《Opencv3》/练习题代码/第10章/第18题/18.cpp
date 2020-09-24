#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
    Mat src = imread("F:/3.png",0);
    imshow("原图像", src);
    //y方向
    Mat result1,result2,result3;
    Sobel(src, result1, CV_8U, 0, 1, 3);
    Sobel(src, result2, CV_8U, 0, 1, 5);
    Sobel(src, result3, CV_8U, 0, 1, 9);
    imshow("y-3乘3", result1);
    imshow("y-5乘5", result2);
    imshow("y-9乘9", result3);
    //x方向
    Mat result4, result5, result6;
    Sobel(src, result4, CV_8U, 1,0, 3);
    Sobel(src, result5, CV_8U, 1,0, 5);
    Sobel(src, result6, CV_8U, 1,0, 9);
    imshow("x-3乘3", result4);
    imshow("x-5乘5", result5);
    imshow("x-9乘9", result6);
    waitKey(0);
    return 0;
}


