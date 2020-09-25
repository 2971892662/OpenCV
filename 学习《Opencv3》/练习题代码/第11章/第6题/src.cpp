#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/photo/photo.hpp"

#include <iostream>

using namespace cv;
using namespace std;

Mat img, inpaintMask;
Point prevPt(-1, -1);

//参考：https://www.cnblogs.com/hellowooorld/p/7048614.html
//边缘无法恢复
//获得掩码挺麻烦的

static void onMouse(int event, int x, int y, int flags, void*)
{
    if (event ==EVENT_LBUTTONUP || !(flags & EVENT_FLAG_LBUTTON))
        prevPt = Point(-1, -1);
    else if (event == EVENT_LBUTTONDOWN)
        prevPt = Point(x, y);
    else if (event == EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON))
    {
        Point pt(x, y);
        if (prevPt.x < 0)
            prevPt = pt;
        line(inpaintMask, prevPt, pt, Scalar::all(255), 5, 8, 0);//mask
        line(img, prevPt, pt, Scalar::all(255), 5, 8, 0);
        prevPt = pt;
        imshow("image", img);
    }
}


int main(int argc, char** argv)
{

    Mat img0 = imread("F:/6.jpg");

    namedWindow("image", 1);

    img = img0.clone();
    inpaintMask = Mat::zeros(img.size(), CV_8U);//mask

    imshow("image", img);
    setMouseCallback("image", onMouse, 0);

    for (;;)
    {
        char c = (char)waitKey();

        if (c == 27)
            break;

        if (c == 'r')
        {
            inpaintMask = Scalar::all(0);
            img0.copyTo(img);
            imshow("image", img);
        }

        if (c == 'i' || c == ' ')
        {
            Mat inpainted;
            //inpaint(img, inpaintMask, inpainted, 3, CV_INPAINT_TELEA);//CV_INPAINT_NS
            inpaint(img, inpaintMask, inpainted, 3, INPAINT_TELEA);
            imshow("inpainted image", inpainted);
        }
    }

    return 0;
}

