#include<opencv2/opencv.hpp>

int main() {
	IplImage *src = cvLoadImage("c:\\temp\\lena.jpg");
	IplImage *dst = cvCreateImage(cvGetSize(src), 8, 3);

	for (int y = 0; y < src->height; y++) 
		for (int x = 0; x < src->width; x++) {
			CvScalar f = cvGet2D(src, y, x);
			
			if (y < (dst->height - 1) / 2) {
				if (x < (dst->width - 1) / 2)
					cvSet2D(dst, (dst->height - 1) / 2 - y, (dst->width / 2) - x - 1, f);
				else
					cvSet2D(dst, (dst->height - 1) / 2 - y, (dst->width / 2 - 1) + (dst->width - x) - 1, f);
			}
		}
			else {
				if (x < (dst->width - 1) / 2)
					cvSet2D(dst, (dst->height / 2 - 1) + (dst->width - y) - 1, (dst->width / 2) - x - 1, f);
				else
					cvSet2D(dst, (dst->height / 2 - 1) + (dst->width - y) - 1, (dst->width / 2 - 1) + (dst->width - x) - 1, f);

			}
		}

	cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();

	return 0;
}