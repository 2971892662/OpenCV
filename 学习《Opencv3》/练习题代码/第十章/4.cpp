#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
    Mat src1 = imread("F:/5.jpg");
    Mat src2 = imread("F:/6.jpg");
    Mat diff12 = src1 - src2;
    Mat cleandiff, dirtydiff;
    imshow("diff12", diff12);
    morphologyEx(diff12, cleandiff, MORPH_OPEN, Mat());
    morphologyEx(diff12, dirtydiff, MORPH_CLOSE, Mat());
    imshow("开", cleandiff);
    imshow("闭", dirtydiff);
    waitKey(0);
    return 0;
}
