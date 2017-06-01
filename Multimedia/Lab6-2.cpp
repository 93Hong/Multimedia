/*
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace cv;
using namespace std;

Mat image, image2;
int bSize = 16, sRange = 15;
int maps[606][606];

int main(int argc, char** argv) {



	String imageName("caltrain000.png"); // by default
	String imageName2("caltrain001.png"); // by default

	image = imread(imageName, IMREAD_GRAYSCALE); // Read the file
	image2 = imread(imageName2, IMREAD_GRAYSCALE); // Read the file

	if (image.empty()) {                     // Check for invalid input
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	if (image2.empty()) {                     // Check for invalid input
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	
	for (int y = 0; y < image.size().height; y += bSize) {
		for (int x = 0; x < image.size().width; x += bSize) {
			int mad = 10000000, mag;

			for (int k = -sRange; k <= sRange; k++) {
				for (int l = -sRange; l <= sRange; l++) {

					int tmp = 0;
					for (int i = 0; i < bSize; i++) {
						if ((y < 0 || y >= image.size().height) || (x + i < 0 || x + i >= image.size().width) || (y + k < 0 || y + k >= image.size().height) || (x + i + l < 0 || x + i + l >= image.size().width))
							break;
						for (int j = 0; j < bSize; j++) {
							if ((y + j < 0 || y + j >= image.size().height) || (x + i < 0 || x + i >= image.size().width) || (y + j + k < 0 || y + j + k >= image.size().height) || (x + i + l < 0 || x + i + l >= image.size().width))
								break;
							tmp += abs(image.at<uchar>(y + j, x + i) - image2.at<uchar>(max(y + j + k, 0), max(x + i + l, 0)));
						}
					}
					if (mad > tmp) {
						mad = tmp;
						mag = sqrt(k*k + l*l);
					}
				}
			}

			maps[y][x] = mag;
		}
	}

	for (int y = 0; y < image.size().height; y += bSize) { // 25
		for (int x = 0; x < image.size().width; x += bSize) // 32
			printf("%d ", maps[y][x] * 17);
		printf("\n");
	}
	return 0;
}
*/

/*
for (int y = 1; y < image.size().height; y += bSize) {
for (int x = 1; x < image.size().width; x += bSize) {
int tmp = maps[y][x] * 17;
for (int i = 0; i < bSize; i++) {
for (int j = 0; j < bSize; j++) {
if (y + j >= image.size().height || x + i >= image.size().width)
continue;
image.at<uchar>(y + j, x + i) = saturate_cast<uchar>(tmp);
}
}
}
}

namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
imshow("Display window", image);                // Show our image inside it.
waitKey(0); // Wait for a keystroke in the window
*/