#include <opencv2/opencv.hpp>

int main() {
    IplImage *src = cvLoadImage("c:\\temp\\lena.jpg");
    IplImage *dst = cvCreateImage(cvGetSize(src), 8, 3);

    int width = src->width;
    int height = src->height;

    float freq = 1/ (float)src->height;
    float amp = src->width / 4.0f;
    const double pi = 3.14f;

    for (int y = 0; y < src->height; y++) {
        for (int x = 0; x < src->width; x++) {
            CvScalar f = cvGet2D(src, y, x);
            CvScalar g;
            
            int x1 = x + amp * sin(2 * CV_PI * y * freq);

            if (x1 >= 0 && x1 < src->width)
                cvSet2D(dst, y, x1, f);
        }
    }

    //cvShowImage("src", src);
    cvShowImage("dst", dst);
    cvWaitKey();
    return 0;
}