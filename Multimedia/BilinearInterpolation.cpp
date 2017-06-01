/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat BilinearInterpolation(const Mat image, const double scale) {
	int x1, x2, y1, y2;
	double rx, ry, s1, s2;
	double srcX = 1 / scale, srcY = 1 / scale;

	Vec3b r1, r2;
	Mat mine((int)(image.size().height * scale + 0.5), (int)(image.size().width * scale + 0.5), CV_8UC3);

	for (int y = 0; y < mine.size().height; y++)
		for (int x = 0; x < mine.size().width; x++) {
			rx = srcX * x;
			ry = srcY * y;
			x1 = (int)floor(rx);
			y1 = (int)floor(ry);
			x2 = x1 + 1;
			y2 = y1 + 1;
			s1 = rx - x1;
			s2 = ry - y1;

			if (x2 == image.size().width)
				x2 = x1;
			if (y2 == image.size().height)
				y2 = y1;

			for (int i = 0; i < 3; i++) {
				r1[i] = saturate_cast<uchar>((1 - s1) * image.at<Vec3b>(y1, x1)[i] + s1 * image.at<Vec3b>(y1, x2)[i] + 0.5);
				r2[i] = saturate_cast<uchar>((1 - s1) * image.at<Vec3b>(y2, x1)[i] + s1 * image.at<Vec3b>(y2, x2)[i] + 0.5);
				mine.at<Vec3b>(y, x)[i] = saturate_cast<uchar>((1 - s2) * r1[i] + s2 * r2[i] + 0.5);
			}
		}

	return mine;
}

int main(int argc, char** argv) {
	String imageName("Lenna.png"); // by default
	Mat image, notMine;
	double scale = 2;

	if (argc > 1)
		imageName = argv[1];

	image = imread(imageName, IMREAD_COLOR); // Read the file

	if (image.empty()) {                     // Check for invalid input
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	resize(image, notMine, Size(), 1, 1, CV_INTER_NN);
	namedWindow("Display notMine", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display notMine", notMine);              // Show our image inside it.

	namedWindow("Display mine", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display mine", BilinearInterpolation(image, scale));

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}*/