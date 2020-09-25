#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//计算原物体真正的尺寸是一个问题，如何选择合适的大小

int main()
{
    Mat src = imread("F:/3.jpg");
    imshow("src", src);

    Mat result;
    Point2f input[] = { Point2f(23,513) ,Point2f(351,221) ,Point2f(955,902) ,Point2f(1050,443) };
    Point2f output[] = { Point2f(0,0) ,Point2f(500,0) ,Point2f(0,800) ,Point2f(500,800) };
    Mat m=getPerspectiveTransform(input,output);

    warpPerspective(src, result, m, Size(500, 800));
    imshow("result", result);

    waitKey(0);
    return 0;
}


