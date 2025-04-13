#include<opencv2/opencv.hpp>

int main() {
	IplImage *src = cvLoadImage("c:\\temp\\lena.jpg");
	IplImage *dst = cvCreateImage(cvGetSize(src), 8, 3);

	for (int y = 0; y < src->height; y++) 
		for (int x = 0; x < src->width; x++) {
			CvScalar f = cvGet2D(src, y, x);
			
			cvSet2D(dst, dst->height - y - 1, x, f);
		}

	cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();

	return 0;
}