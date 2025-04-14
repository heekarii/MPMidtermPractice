#include<opencv2/opencv.hpp>

int main() {
	IplImage *src = cvLoadImage("c:\\temp\\lena.jpg");
	IplImage *dst = cvCreateImage(cvGetSize(src), 8, 3);

	for (int y = 0; y < src->height; y++)
		for (int x = 0; x < src->width; x++) {
			CvScalar f = cvGet2D(src, y, x);
			CvScalar g = cvScalar(0, 0, 0);
		
			float dx = (float)x / (dst->width - 1);
			float dy = (float)y / (dst->height - 1);

			for (int i = 0; i < 3; i++)
				g.val[i] = f.val[i] + 255 * dx;
				

			cvSet2D(dst, y, x, g);
		}

	//cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();

	return 0;
}