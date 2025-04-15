#include<opencv2/opencv.hpp>

int main() {
	IplImage *src = cvLoadImage("c:\\temp\\lena.jpg");
	IplImage *dst = cvCreateImage(cvGetSize(src), 8, 3);


	for (int y = 0; y < src->height; y++)
		for (int x = 0; x < src->width; x++) {

			CvScalar f = cvGet2D(src, y, x);
			CvScalar g = cvScalar(0, 0, 0);
			for (int i = 1; i < 8; i++) {
				if (y >= i * src->height / 8 && y < (i + 1)*src->height / 8) {
					g.val[0] = f.val[0] + 32 * i;
					g.val[1] = f.val[1] + 32 * i;
					g.val[2] = f.val[2] + 32 * i;
				}
			}

			if (y < src->height / 8) {
				g.val[0] = f.val[0] + 255 * (1 / 8);
				g.val[1] = f.val[1] + 255 * (1 / 8);
				g.val[2] = f.val[2] + 255 * (1 / 8);
			}

			cvSet2D(dst, y, x, g);
		}


	//cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();

	return 0;
}