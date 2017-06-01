/*
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	String imageName("C:/Users/hong/Desktop/Lenna.png"); // by default
	
	if (argc > 1) 	{
		imageName = argv[1];
	}
	
	Mat image, image2;
	image = imread(imageName, IMREAD_COLOR); // Read the file

	if (image.empty()) {                     // Check for invalid input
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	resize(image, image2, image.size(), 0, 0, CV_INTER_CUBIC);

	float a;
	int b;

	cin >> a;
	cin >> b;

	for (int x = 0; x < image.size().height; x++)
		for (int y = 0; y < image.size().width; y++)
			for (int i = 0; i < 3; i++)
				image2.at<Vec3b>(y, x)[i] = saturate_cast<uchar>(a * image.at<Vec3b>(y, x)[i] + b);

	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display window", image2);                // Show our image inside it.
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}*/