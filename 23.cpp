#include <opencv2/opencv.hpp>

int main() {
    IplImage *src = cvLoadImage("c:\\temp\\lena.jpg");
    IplImage *dst = cvCreateImage(cvGetSize(src), 8, 3);

    int width = src->width;
    int height = src->height;

    float freq = 1/ (float)src->width;
    float amp = src->height / 4.0f;

    for (int y = 0; y < src->height; y++) {
        for (int x = 0; x < src->width; x++) {
            CvScalar f = cvGet2D(src, y, x);
            CvScalar g;
            
            int y1 = y + amp * sin(2 * CV_PI * x * freq);

            if (y1 >= 0 && y1 < src->height)
                cvSet2D(dst, y1, x, f);
        }
    }

    //cvShowImage("src", src);
    cvShowImage("dst", dst);
    cvWaitKey();
    return 0;
}