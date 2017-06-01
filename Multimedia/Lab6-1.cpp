/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(int, char**) {
	VideoCapture cap(0);
	if (!cap.isOpened()) return -1;
	Mat edges;
	namedWindow("edges", 1);

	while (true) {
		Mat frame;
		cap >> frame;

		cvtColor(frame, edges, COLOR_BGR2GRAY);
		GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
		Canny(edges, edges, 0, 30, 3);

		//
		Point2f srcTri[3];
		Point2f dstTri[3];
		Mat warp_mat(2, 3, CV_32FC1);
		Mat src, warp_dst, end;

		src = edges;
		warp_dst = Mat::zeros(src.rows, src.cols, src.type());

		srcTri[0] = Point2f(0, 0);
		srcTri[1] = Point2f(src.cols - 1, 0);
		srcTri[2] = Point2f(0, src.rows - 1);
		dstTri[0] = Point2f(src.cols*0.0, src.rows*0.33);
		dstTri[1] = Point2f(src.cols*0.85, src.rows*0.25);
		dstTri[2] = Point2f(src.cols*0.15, src.rows*0.7);
		warp_mat = getAffineTransform(srcTri, dstTri);

		warpAffine(src, warp_dst, warp_mat, warp_dst.size());

		imshow("edges", edges);
		imshow("src", warp_dst);
		if (waitKey(30) >= 0) break;
	}
	waitKey(0);
	return 1;
}*/