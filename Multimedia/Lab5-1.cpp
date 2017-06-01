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
	image = imread(imageName, IMREAD_COLOR); // Read the file

	if (image.empty()) {                     // Check for invalid input
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	Mat notMine;
	resize(image, notMine, Size(), 1.5, 1.5, CV_INTER_NN);
	namedWindow("Display notMine", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display notMine", notMine);                // Show our image inside it.
	float scale = 2;
	Mat mine(image.size().height * scale, image.size().width * scale, CV_8UC3);

	for (int y = 0; y < image.size().height; y++)
		for (int x = 0; x < image.size().width; x++)
			for (int i = 0; i < 3; i++)
				mine.at<Vec3b>(y * scale, x * scale)[i] = saturate_cast<uchar>(image.at<Vec3b>(y, x)[i]);

	for (int y = 1; y < mine.size().height; y++) {
		for (int x = 1; x < mine.size().width; x++) {
			for (int i = 0; i < 3; i++) {
				if (mine.at<Vec3b>(y, x)[i] == 205) {
					int a = floor(y + 0.5) / scale;
					int b = floor(x + 0.5) / scale;
					mine.at<Vec3b>(y, x)[i] = mine.at<Vec3b>(scale * a, scale * b)[i];
				}
			}
		}
	}

	namedWindow("Display mine", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display mine", mine);                // Show our image inside it.

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}*/