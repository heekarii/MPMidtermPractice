#include <opencv2/opencv.hpp>

int main() {
    IplImage *src = cvLoadImage("c:\\temp\\lena.jpg");
    IplImage *dst = cvCreateImage(cvGetSize(src), 8, 3);

    int width = src->width;
    int height = src->height;

    const float pi = 3.14f;
    float freq = 1.0f;
    float amp = 0.5f;

    for (int y = 0; y < src->height; y++) {
        for (int x = 0; x < src->width; x++) {
            CvScalar f = cvGet2D(src, y, x);
            CvScalar g = cvScalar(0, 0, 0);
            
            float dx = 2 * (float)x / (src->width - 1) - 1;
            float dy = 2 * (float)y / (src->height - 1) - 1;

            float shifted = dy + amp * sin(freq * CV_PI * dx);

            if (shifted + 1.0f < 0) shifted -= 1.0f;

            if ((int)((shifted + 1.0f) * 10 / 2.0f) % 2 == 0) {
                cvSet2D(dst, y, x, f);
            }
            else
                cvSet2D(dst, y, x, g);

        }
    }

    //cvShowImage("src", src);
    cvShowImage("dst", dst);
    cvWaitKey();
    return 0;
}