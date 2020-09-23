#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture capture("./videos/Tunak.mp4");
    double width = capture.get(CAP_PROP_FRAME_WIDTH);
    double height = capture.get(CAP_PROP_FRAME_HEIGHT);
    Mat show(height,width*3,CV_8UC3);
    Rect rect1(0, 0,width, height);
    Rect rect2(width, 0, width, height);
    Rect rect3(width*2, 0, width, height);
    Mat mat1 = show(rect1);
    Mat mat2 = show(rect2);
    Mat mat3 = show(rect3);
    int frameCount=capture.get(CAP_PROP_FRAME_COUNT);
    namedWindow("show", WINDOW_NORMAL);
    Point origin(15, 15);
    Scalar color(0, 0, 255);
    for (int i = 0; i < frameCount; i++) {
        Mat temp;
        capture >>temp;
        temp.copyTo(mat1);
        cvtColor(temp, temp, COLOR_RGB2GRAY);
        cvtColor(temp, temp, COLOR_GRAY2RGB);
        temp.copyTo(mat2);
        Canny(mat1, temp, 10, 100, 3, true);
        cvtColor(temp, temp, COLOR_GRAY2RGB);
        temp.copyTo(mat3);
        putText(mat3, "CANNY", origin, FONT_HERSHEY_COMPLEX_SMALL, 1.0, color, 2, 8, false);
        imshow("show", show);
        waitKey(33);
    }
    return 0;
}
