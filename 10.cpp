#include<opencv2/opencv.hpp>

int main() {
	IplImage *src = cvLoadImage("c:\\temp\\lena.jpg");
	IplImage *dst = cvCreateImage(cvGetSize(src), 8, 3);

	for (int y = 0; y < src->height; y++) 
		for (int x = 0; x < src->width; x++) {
			CvScalar f = cvGet2D(src, y, x);
			CvScalar g = cvScalar(0, 0, 0);
		
			if (y < dst->height / 3)
				g.val[2] = f.val[2];
			else if (y < dst->height / 3 * 2)
				g.val[0] = f.val[0];
			else
				g.val[1] = f.val[1];

			cvSet2D(dst, y, x, g);
		}

	//cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();

	return 0;
}