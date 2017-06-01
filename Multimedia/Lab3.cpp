/*
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	String imageName("C:/Users/hong/Desktop/Lenna.png"); // by default

	if (argc > 1) {
		imageName = argv[1];
	}

	Mat image;
	image = imread(imageName, IMREAD_COLOR); // Read the file
	
	if (image.empty()) {                     // Check for invalid input
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	Mat image2(image.size().height, image.size().width, CV_8UC3);

	cvtColor(image, image, CV_BGR2GRAY);
	equalizeHist(image, image2);

	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display window", image);                // Show our image inside it.
	imshow("Display window2", image2);
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}*/