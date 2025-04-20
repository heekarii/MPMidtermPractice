#include<opencv2/opencv.hpp>

int main() {
	IplImage *src = cvLoadImage("c:\\temp\\sejong_small.jpg");
	IplImage *dst = cvCreateImage(cvGetSize(src), 8, 3);
	cvSet(dst, cvScalar(0, 0, 0));

	for (int y = 0; y < src->height; y++) {
		for (int x = 0; x < src->width; x++) {
			CvScalar f = cvGet2D(src, y, x);

			float dx = src->width / 16.0f;

			int cx = x / dx;

			int y1 = y + (src->width / 4.0f) * sin(2 * 3.14f * cx / 15.0f);

			if (y1 >= 0 && y1 < src->height) {
				cvSet2D(dst, y1, x, f);
			}

		}
	}
	cvShowImage("dst", dst);
	cvWaitKey();

	return 0;
}