#include <opencv2/opencv.hpp>

int main() {
    IplImage *src = cvLoadImage("c:\\temp\\lena.jpg");
    IplImage *dst = cvCreateImage(cvGetSize(src), 8, 3);

    int width = src->width;
    int height = src->height;

    int cx = width / 4;
    int cy = height / 4;

    float L = height / width;

    for (int y = 0; y < src->height; y++) {
        for (int x = 0; x < src->width; x++) {
            CvScalar f = cvGet2D(src, y, x);
            CvScalar g;
            
            for (int k = 0; k < 3; k++)
                g.val[k] = f.val[k] / 2;

            int x1 = x / cx;
            int y1 = y / cy;
            int x2 = x - (x1 * cx) - (cx / 2);
            int y2 = y - (y1 * cy) - (cy / 2);
            
            if (x2 < 0) x2 = -x2;
            if (y2 < 0) y2 = -y2;

            float a = cx / 2.0f;
            float b = cy / 2.0f;

            if (x2 / a + y2 / b < L)
                cvSet2D(dst, y, x, f);
            else
                cvSet2D(dst, y, x, g);                       
        }
    }

    //cvShowImage("src", src);
    cvShowImage("dst", dst);
    cvWaitKey();
    return 0;
}