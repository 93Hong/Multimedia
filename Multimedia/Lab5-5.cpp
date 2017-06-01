/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	String imageName("Lenna.png"); // by default

	// Inputpoints
	Point2f inputQuad[4];
	// Corresponding points
	Point2f outputQuad[4];

	Mat warp_mat(2, 4, CV_32FC1);
	Mat src, warp_dst;

	/// Load the image
	src = imread(imageName, IMREAD_COLOR);

	// Setthelambdamatrixthesametypeand sizeasinput
	warp_dst = Mat::zeros(src.rows, src.cols, src.type());
	
	// Thesefourptsarethesidesof therectboxusedasinput(from top-left in clockwise order)
	inputQuad[0] = Point2f(-30, -60);
	inputQuad[1] = Point2f(src.cols + 50, -50);
	inputQuad[2] = Point2f(src.cols + 100, src.rows + 50);
	inputQuad[3] = Point2f(-50, src.rows + 50);
	
	// The 4 pointswherethemappingistobedone, fromtop-leftinclockwiseorder
	outputQuad[0] = Point2f(0, 0);
	outputQuad[1] = Point2f(src.cols - 1, 0);
	outputQuad[2] = Point2f(src.cols - 1, src.rows - 1);
	outputQuad[3] = Point2f(0, src.rows - 1);

	// GetthePerspectiveTransformMatrixi.e. lambda
	warp_mat = getPerspectiveTransform(inputQuad, outputQuad);
	// ApplythePerspectiveTransformjustfoundtothesrcimage
	warpPerspective(src, warp_dst, warp_mat, warp_dst.size());

	namedWindow("Original", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Original", src);                // Show our image inside it.

	namedWindow("Display 5-5", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display 5-5", warp_dst);                // Show our image inside it.

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}*/