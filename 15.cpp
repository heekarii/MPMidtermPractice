#include <opencv2/opencv.hpp>

int main() {
    IplImage *src = cvLoadImage("c:\\temp\\lena.jpg");
    IplImage *dst = cvCreateImage(cvGetSize(src), 8, 3);

    int k = src->height / 32;
    for (int y = 0; y < src->height; y += 2 * k) {
        for (int x = 0; x < src->width; x +=  2 * k ) {
            CvScalar g = cvScalar(0, 0, 0);
            
            int x1 = x;
            int x2 = x + 2 * k;
            int y1 = y;
            int y2 = y + 2 * k;

            if (x1 < 0) x1 = 0;
            if (x2 > src->width) x2 = src->width;
            if (y1 < 0) y1 = 0;
            if (y2 > src->height) y2 = src->height;

            int size = (x2 - x1) * (y2 - y1);

            for (int u = y1; u < y2; u++) {
                for (int v = x1; v < x2; v++) {
                    CvScalar f = cvGet2D(src, u, v);    
                    g.val[0] += f.val[0];
                    g.val[1] += f.val[1];
                    g.val[2] += f.val[2];
                }
            }
            for (int k = 0; k < 3; k++) {
                g.val[k] /= size;
            }

            for (int u = y1; u < y2; u++) {
                for (int v = x1; v < x2; v++) {
                    cvSet2D(dst, u, v, g);
                }
            }
            
        }
    }

    //cvShowImage("src", src);
    cvShowImage("dst", dst);
    cvWaitKey();
    return 0;
}
