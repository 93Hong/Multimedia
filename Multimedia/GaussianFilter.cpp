/*
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

#define M_PI 3.14159265358979323846

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

	double sigma;
	int N;
	double sum = 0.0, r;
	double **kernel;
	
	printf("Enter N : ");
	cin >> N;
	printf("Enter sigma : ");
	cin >> sigma;

	kernel = new double*[N];
	for (int i = 0; i < N; i++)
		kernel[i] = new double[N];

	int n = N / 2;

	for (int x = -n; x <= n; x++) {
		for (int y = -n; y <= n; y++) {
			r = sqrt(x*x + y*y);
			kernel[x + n][y + n] = (exp(-(r*r) / 2.0 * sigma * sigma)) / (M_PI * 2.0 * sigma * sigma);
			sum +=  kernel[x + n][y + n];
		}
	}

	

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			kernel[i][j] /= sum;

	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display window", image);                // Show our image inside it.

	for (int y = n; y < image.size().height - n; y++)
		for (int x = n; x < image.size().width - n; x++) {
			double tmp = 0;
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++) {
					tmp += kernel[i][j] * image.at<uchar>(y - n + j, x - n + i);
				}
			image2.at<uchar>(y, x) = tmp;
		}

	imshow("Display window2", image2);
	waitKey(0); // Wait for a keystroke in the window

	for (int i = 0; i < N; i++)
		delete[] kernel;
	delete[] kernel;
	return 0;
}
*/