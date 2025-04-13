#include<opencv2/opencv.hpp>

int main() {
	IplImage *src = cvLoadImage("c:\\temp\\lena.jpg");
	IplImage *dst = cvCreateImage(cvGetSize(src), 8, 3);

	for (int y = 0; y < src->height; y++) 
		for (int x = 0; x < src->width; x++) {
			CvScalar f = cvGet2D(src, y, x);
			

			float y1 = y < dst->height / 2 ? (float)y : dst->height - (float)y;
			float x1 = x < dst->width / 2 ? (float)x : dst->width - (float)x;

			float dy = (float)y1 / (dst->height / 2);
			float dx = (float)x1 / (dst->width / 2);

			CvScalar grey = {
				(f.val[0] + f.val[1] + f.val[2]) / 3,
				(f.val[0] + f.val[1] + f.val[2]) / 3,
				(f.val[0] + f.val[1] + f.val[2]) / 3
			};

			float dist = sqrt(dx * dx + dy * dy);

			if (dist >= 1)
				cvSet2D(dst, y, x, grey);
			else
				cvSet2D(dst, y, x, f);

			
			

		}

	//cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();

	return 0;
}