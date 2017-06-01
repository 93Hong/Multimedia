/*
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	String imageName("Riper.jpg"); // Lenna.png

	if (argc > 1) {
		imageName = argv[1];
	}

	Mat image;
	image = imread(imageName, IMREAD_GRAYSCALE); // Read the file

	if (image.empty()) {                     // Check for invalid input
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	Mat image2(image.size().height, image.size().width, CV_8U);

	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display window", image);                // Show our image inside it.

	int mask[3][3] = { {1, 0, -1}, {2, 0, -2}, {1, 0, -1} };
	int mask2[3][3] = { { 1, 2, 1 },{ 0, 0, 0 },{ -1, -2, -1 } };

	for (int y = 1; y < image.size().height - 2; y++)
		for (int x = 1; x < image.size().width - 2; x++) {
			double tmp1 = 0, tmp2 = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++) {
					tmp1 += mask[i][j] * image.at<uchar>(y - 1 + j, x - 1 + i);
					tmp2 += mask2[i][j] * image.at<uchar>(y - 1 + j, x - 1 + i);
				}
			image2.at<uchar>(y, x) = saturate_cast<uchar>(sqrt((tmp1)*(tmp1)+(tmp2)*(tmp2)));
		}

	imshow("Display window2", image2);
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}*/