#include <opencv2/opencv.hpp>

int main() {
    IplImage *src = cvLoadImage("c:\\temp\\lena.jpg");
    IplImage *dst = cvCreateImage(cvGetSize(src), 8, 3);

    int width = src->width;
    int height = src->height;
    float cx = width / 8.0;
    float cy = height / 8.0;
    float oval[16];
    for (int y = 0; y < src->height; y++) {
        for (int x = 0; x < src->width; x++) {
            CvScalar f = cvGet2D(src, y, x);
            CvScalar g = cvScalar(0, 0, 0);
            
            for (int k = 0; k < 3; k++) {
                if (f.val[k] < 255 / 2) {
                    g.val[k] = 2 * f.val[k];
                }
                else {
                    g.val[k] = 255 - 2 * (f.val[k] - 255 / 2);
                }
            }
            cvSet2D(dst, y, x, g);
        }
    }

    //cvShowImage("src", src);
    cvShowImage("dst", dst);
    cvWaitKey();
    return 0;
}