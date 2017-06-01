/*
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	String imageName("Lenna.png"); // by default

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

	int mask[5][5];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			mask[i][j] = 1;

	for (int y = 2; y < image.size().height - 2; y++)
		for (int x = 2; x < image.size().width - 2; x++) {
			double tmp = 0;
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					tmp += mask[i][j] * image.at<uchar>(y - 2 + j, x - 2 + i);
			image2.at<uchar>(y, x) = tmp / 25;
		}

	imshow("Display window2", image2);
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}*/