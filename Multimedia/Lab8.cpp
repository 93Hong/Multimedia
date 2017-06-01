/*
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace cv;
using namespace std;

Mat image, image2;
int mostColor[1][1];

int main(int argc, char** argv) {

	String imageName("horse.jpg"); // by default
	String image2Name("background.jpg"); // by default

	image = imread(imageName, IMREAD_COLOR); // Read the file
	image2 = imread(image2Name, IMREAD_COLOR); // Read the file

	if (image.empty()) {                     // Check for invalid input
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	if (image2.empty()) {                     // Check for invalid input
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	Mat image3 = Mat(image.size().height, image.size().width, CV_8UC3);

	for (int y = 0; y < image.size().height; y++) {
		for (int x = 0; x < image.size().width; x++) {
			if (image.at<Vec3b>(y, x)[1] > 250
				&& image.at<Vec3b>(y, x)[0] < 30
				&& image.at<Vec3b>(y, x)[2] < 30) {

				for (int i = 0; i < 3; i++) {
					image3.at<Vec3b>(y, x)[i] = saturate_cast<uchar>(image2.at<Vec3b>(y, x)[i]);
				}
			}
			else {
				
				for (int i = 0; i < 3; i++) {
					image3.at<Vec3b>(y, x)[i] = saturate_cast<uchar>(image.at<Vec3b>(y, x)[i]);
				}
			}
		}
	}


	namedWindow("image", WINDOW_AUTOSIZE);
	imshow("image", image3);
	waitKey(0);


	return 0;
}*/