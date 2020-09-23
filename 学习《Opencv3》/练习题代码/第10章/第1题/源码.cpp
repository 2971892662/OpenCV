#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
    Mat src = imread("F:/1314.jpg");
    Mat mat1, mat2, mat3, mat4, mat5;
    GaussianBlur(src, mat1, Size(3 , 3), 0, 0);
    GaussianBlur(src, mat2, Size(5,5), 0, 0);
    GaussianBlur(src, mat3, Size(9,9), 0, 0);
    GaussianBlur(src, mat4, Size(11,11), 0, 0);
    GaussianBlur(mat2, mat5, Size(3, 3), 0, 0);
    imshow("原图",src);
    imshow("3*3", mat1);
    imshow("5*5", mat2);
    imshow("9*9", mat3);
    imshow("11*11", mat4);
    imshow("两次5*5", mat5);
    waitKey(0);
    return 0;
}


