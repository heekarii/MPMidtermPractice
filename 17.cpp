#include<opencv2/opencv.hpp>

int main() {
	IplImage *src = cvLoadImage("c:\\temp\\lena.jpg");
	IplImage *dst = cvCreateImage(cvGetSize(src), 8, 3);


	for (int y = 0; y < src->height; y++)
		for (int x = 0; x < src->width; x++) {

			CvScalar f = cvGet2D(src, y, x);
			CvScalar g = cvScalar(0, 0, 0);

			float dx = (float)x / (src->width - 1);
			float dy = (float)y / (src->height - 1);

			if (((int)(dx * 8) % 2 == 0 && (int)(dy * 8) % 2 != 0) || ((int)(dx * 8) % 2 != 0 && (int)(dy * 8) % 2 == 0)) { 
				cvSet2D(dst, y, x, cvScalar(0, 0, 0));
			}
			else {
				cvSet2D(dst, y, x, f);
			}
		}


	//cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();

	return 0;
}