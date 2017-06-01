/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	String imageName("Lenna.png"); // by default

	Point2f srcTri[3];
	Point2f dstTri[3];
	Mat warp_mat(2, 3, CV_32FC1);
	Mat src, warp_dst, end;
	/// Load the image
	src = imread(imageName, IMREAD_COLOR);
	/// Set the dstimage the same type and size as src
	warp_dst = Mat::zeros(src.rows, src.cols, src.type());

	/// Set your 3 points to calculate the Affine Transform
	srcTri[0] = Point2f(0, 0);
	srcTri[1] = Point2f(src.cols - 1, 0);
	srcTri[2] = Point2f(0, src.rows - 1);

	dstTri[0] = Point2f(src.cols * 0.0, src.rows * 0.33);
	dstTri[1] = Point2f(src.cols * 0.85, src.rows * 0.25);
	dstTri[2] = Point2f(src.cols * 0.15, src.rows * 0.7);
	/// Get the Affine Transform
	warp_mat = getAffineTransform(srcTri, dstTri);

	/// Apply the Affine Transform just found to the srcimage
	warpAffine(src, warp_dst, warp_mat, warp_dst.size());

	namedWindow("Display", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display", src);                // Show our image inside it.

	namedWindow("Display 5-4", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display 5-4", warp_dst);                // Show our image inside it.

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}*/