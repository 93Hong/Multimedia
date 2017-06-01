/*
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <math.h>

#define M_PI 3.14159265358979323846

using namespace cv;
using namespace std;

void rgb2hsi(Mat& RGB_image, Mat& HSI_image) {
	vector<Mat> RGB_image_components, HSI_image_components;
	for (int i = 0; i < 3; i++) {
		HSI_image_components.push_back(Mat(RGB_image.size(), CV_8UC1));
	}
	split(RGB_image, RGB_image_components);

	for (int i = 0; i < RGB_image.rows; i++) {
		for (int j = 0; j < RGB_image.cols; j++) {
			float r = RGB_image_components[2].at<uchar>(i, j);
			float g = RGB_image_components[1].at<uchar>(i, j);
			float b = RGB_image_components[0].at<uchar>(i, j);
			float hue, saturation, intensity, min_val;

			intensity = (r + g + b) / (3.0);
			min_val = min(r, min(g, b));
			if (intensity > 0.0)
				saturation = 1 - (min_val / intensity);
			if (saturation < 0.00001) {
				saturation = 0;
			}
			else if (saturation > 0.99999) {
				saturation = 1;
			}
			if (saturation > 0) {
				hue = (0.5 * ((r - g) + (r - b))) / sqrt(((r - g) * (r - g)) + ((r - b) * (g - b)));
				hue = acos(hue);
				if (b > g) {
					hue = ((360 * M_PI) / 180.0) - hue;
				}
			}
			else {
				hue = 0;
			}
			HSI_image_components[2].at<uchar>(i, j) = intensity;
			HSI_image_components[1].at<uchar>(i, j) = saturation * 100;
			HSI_image_components[0].at<uchar>(i, j) = (hue * 180) / M_PI;
		}
	}
	merge(HSI_image_components, HSI_image);
}

void rgb2hsv(Mat& RGB_image, Mat& HSV_image) {
	vector<Mat> RGB_image_components, HSI_image_components;
	for (int i = 0; i < 3; i++) {
		HSI_image_components.push_back(Mat(RGB_image.size(), CV_8UC1));
	}
	split(RGB_image, RGB_image_components);

	for (int i = 0; i < RGB_image.rows; i++) {
		for (int j = 0; j < RGB_image.cols; j++) {
			float r = RGB_image_components[2].at<uchar>(i, j);
			float g = RGB_image_components[1].at<uchar>(i, j);
			float b = RGB_image_components[0].at<uchar>(i, j);
			float hue, saturation, intensity, min_val;

			intensity = max(r, max(g, b));
			min_val = min(r, min(g, b));
			if (intensity > 0.0)
				saturation = 1 - (min_val / intensity);
			if (saturation < 0.00001) {
				saturation = 0;
			}
			else if (saturation > 0.99999) {
				saturation = 1;
			}
			if (saturation > 0) {
				hue = (0.5 * ((r - g) + (r - b))) / sqrt(((r - g) * (r - g)) + ((r - b) * (g - b)));
				hue = acos(hue);
				if (b > g) {
					hue = ((360 * M_PI) / 180.0) - hue;
				}
			}
			else {
				hue = 0;
			}
			HSI_image_components[2].at<uchar>(i, j) = intensity;
			HSI_image_components[1].at<uchar>(i, j) = saturation * 100;
			HSI_image_components[0].at<uchar>(i, j) = (hue * 180) / M_PI;
		}
	}
	merge(HSI_image_components, HSV_image);
}

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

	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display window", image);                // Show our image inside it.

	Mat RGB(image.size().height, image.size().width, CV_8UC3);
	for (int y = 0; y < image.size().height; y++) {
		for (int x = 0; x < image.size().width; x++) {
			for (int i = 0; i < 3; i++)
				RGB.at<Vec3b>(y, x)[i] = saturate_cast<uchar>(image.at<Vec3b>(y, x)[i] * 0.7);
		}
	}
	imshow("Display RGB", RGB);


	Mat YCbCr(image.size().height, image.size().width, CV_8UC3);
	Mat YCbCr2(image.size().height, image.size().width, CV_8UC3);
	cvtColor(image, YCbCr, CV_BGR2YCrCb);
	for (int y = 0; y < image.size().height; y++) {
		for (int x = 0; x < image.size().width; x++) {
			YCbCr.at<Vec3b>(y, x)[0] = saturate_cast<uchar>(YCbCr.at<Vec3b>(y, x)[0]*0.7);
		}
	}
	cvtColor(YCbCr, YCbCr2, CV_YCrCb2BGR);
	imshow("Display YCbCr", YCbCr2);

	Mat CMY(image.size().height, image.size().width, CV_8UC3);
	Mat CMY2(image.size().height, image.size().width, CV_8UC3);
	for (int y = 0; y < image.size().height; y++) {
		for (int x = 0; x < image.size().width; x++) {
			for (int i = 0; i < 3; i++)
				CMY.at<Vec3b>(y, x)[i] = saturate_cast<uchar>(255 - image.at<Vec3b>(y, x)[i]);
		}
	}
	for (int y = 0; y < image.size().height; y++) {
		for (int x = 0; x < image.size().width; x++) {
			for (int i = 0; i < 3; i++)
				CMY.at<Vec3b>(y, x)[i] = saturate_cast<uchar>(CMY.at<Vec3b>(y, x)[i] * 0.7 + (1-0.7)*255);
		}
	}
	for (int y = 0; y < image.size().height; y++) {
		for (int x = 0; x < image.size().width; x++) {
			for (int i = 0; i < 3; i++)
				CMY2.at<Vec3b>(y, x)[i] = saturate_cast<uchar>(255 - CMY.at<Vec3b>(y, x)[i]);
		}
	}
	imshow("Display CMY", CMY2);

	Mat HSV(image.size().height, image.size().width, CV_8UC3);
	Mat HSV2(image.size().height, image.size().width, CV_8UC3);
	cvtColor(image, HSV, CV_BGR2HSV);
	for (int y = 0; y < image.size().height; y++) {
		for (int x = 0; x < image.size().width; x++) {
			HSV.at<Vec3b>(y, x)[2] = saturate_cast<uchar>(HSV.at<Vec3b>(y, x)[2]*0.7);
		}
	}
	cvtColor(HSV, HSV2, CV_HSV2BGR);
	imshow("Display HSV", HSV2);

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}*/