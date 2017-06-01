/*
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	String imageName("C:/Users/hong/Desktop/Lenna.png"); // by default
	String imageName2("C:/Users/hong/Desktop/google.png"); // by default

	if (argc > 1) {
		imageName = argv[1];
	}

	Mat image, image2, image3;
	image = imread(imageName, IMREAD_COLOR); // Read the file
	image2 = imread(imageName2, IMREAD_COLOR); // Read the file
	resize(image2, image2, image.size(), 0, 0, CV_INTER_CUBIC);
	resize(image, image3, image.size(), 0, 0, CV_INTER_CUBIC);

	if (image.empty()) {                     // Check for invalid input
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	if (image2.empty()) {                     // Check for invalid input
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	double alpha = 0.3, beta;


	//for (float alpha = 0; alpha < 1; alpha + 0.1)
	beta = 1 - alpha;
	for (int x = 0; x < image.size().height; x++)
		for (int y = 0; y < image.size().width; y++)
			for (int i = 0; i < 3; i++)
				image3.at<Vec3b>(y, x)[i] = saturate_cast<uchar>(alpha * image.at<Vec3b>(y, x)[i] + beta * image2.at<Vec3b>(y, x)[i]);

	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display window", image3);                // Show our image inside it.
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}*/