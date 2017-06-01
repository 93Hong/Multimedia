/*
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int mask1[3][3] = { {0, 1, 0}, {1, -4, 1}, {0, 1, 0} };
int mask2[3][3] = { { 1, 2, 1 },{ 1, -8, 1 },{ 1, 1, 1 } };
int mask3[3][3] = { { 0, -1, 0 },{ -1, 4, -1 },{ 0, -1, 0 } };
int mask4[3][3] = { { -1, -1, -1 },{ -1, 8, -1 },{ -1, -1, -1 } };
int mask5[3][3] = { { -3, -3, -3 },{ -3, 24, -3 },{ -3, -3, -3 } };

int main(int argc, char** argv) {
	String imageName("Riper.jpg"); // by default

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
	Mat image3(image.size().height, image.size().width, CV_8U);

	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display window", image);                // Show our image inside it.

	int mask[3][3];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			mask[i][j] = 1;

	for (int y = 1; y < image.size().height - 1; y++)
		for (int x = 1; x < image.size().width - 1; x++) {
			double tmp = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					tmp += mask[i][j] * image.at<uchar>(y - 1 + j, x - 1 + i);
			image2.at<uchar>(y, x) = tmp / 9;
		}

	for (int y = 1; y < image.size().height - 1; y++)
		for (int x = 1; x < image.size().width - 1; x++) {
			double tmp = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					tmp = tmp + mask5[i][j] * image2.at<uchar>(y - 1 + j, x - 1 + i);
			image3.at<uchar>(y, x) = saturate_cast<uchar>(tmp + image2.at<uchar>(y, x));
		}


	imshow("Display window2", image2);
	imshow("Display window3", image3);
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}*/