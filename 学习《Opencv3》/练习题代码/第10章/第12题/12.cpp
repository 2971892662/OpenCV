#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
    Mat src = imread("F:/2.png");
    Mat down;
    pyrDown(src,down, Size(src.cols / 2, src.rows / 2));
    pyrDown(down, down, Size(down.cols / 2, down.rows / 2));
    pyrDown(down, down, Size(down.cols / 2, down.rows / 2));
    imshow("降采样", down);

    Mat re;
    resize(src, re, Size(src.cols / 2, src.rows / 2));
    resize(re, re, Size(re.cols / 2, re.rows / 2));
    resize(re, re, Size(re.cols / 2, re.rows / 2));
    imshow("resize", re);

    waitKey(0);
    return 0;
}


