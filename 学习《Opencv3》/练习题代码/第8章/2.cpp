#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class Para{
public:
    Mat dest;
};

void TestCallBack(int event, int x, int y, int flags, void* param);

int main()
{
    Mat img = imread("./videos/1.jpg");
    Para param;
    img.copyTo(param.dest);
    namedWindow("show", WINDOW_AUTOSIZE);
    imshow("show", img);
    setMouseCallback("show", TestCallBack, &param);
    waitKey(0);
    destroyWindow("show");
    return 0;
}

void TestCallBack(int event,int x,int y,int flags, void* param) {
    Para* p = (Para*)param;
    String s;

    if (event == EVENT_LBUTTONDOWN) {
        s.append("P:("); s.append(to_string(x)); s.append(","); s.append(to_string(y)); s.append(")"); s.append(" C:");
        s.append("("); s.append(to_string(p->dest.at<Vec3b>(y, x)[0])); s.append(","); s.append(to_string(p->dest.at<Vec3b>(y, x)[1])); s.append(",");
        s.append(to_string(p->dest.at<Vec3b>(y, x)[2])); s.append(")");
       putText(p->dest,s , Point(x,y), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(0, 0, 255), 2, 8, false);
       imshow("show", p->dest);
    }
}
