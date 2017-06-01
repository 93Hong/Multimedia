/*
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

Mat src, dst;
Mat b_hist, g_hist, r_hist;
vector<Mat> bgr_planes;

float maxFloat = 0;
int maxFloatIndex = 0;

int r, g, b;

void getMaxHist() {
	float tmp;

	for (int i = 1; i < 256; i++) {
		tmp = g_hist.at<float>(i - 1);
		if (maxFloat < tmp) {
			maxFloat = tmp;
			maxFloatIndex = i - 1;
		}
	}
	printf("%f\n", maxFloat);

	printf("%d %d %d", cvRound(r_hist.at<float>(maxFloatIndex)), cvRound(g_hist.at<float>(maxFloatIndex)), cvRound(b_hist.at<float>(maxFloatIndex)));
	r = cvRound(r_hist.at<float>(maxFloatIndex));
	g = cvRound(g_hist.at<float>(maxFloatIndex));
	b = cvRound(b_hist.at<float>(maxFloatIndex));
}

int main(int argc, char** argv) {

	String imageName("Girl_in_front_of_a_green_background.jpg"); // by default // horse

	/// Load image
	src = imread(imageName, IMREAD_COLOR);

	if (!src.data) {
		return -1;
	}

	/// Separate the image in 3 places ( B, G and R )

	split(src, bgr_planes);

	/// Establish the number of bins
	int histSize = 256;

	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 256 };
	const float* histRange = { range };

	bool uniform = true; bool accumulate = false;



	/// Compute the histograms:
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

	// Draw the histograms for B, G and R
	int hist_w = 512; int hist_h = 256;
	int bin_w = cvRound((double)hist_w / histSize);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

	/// Normalize the result to [ 0, histImage.rows ]
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	/// Draw for each channel
	for (int i = 1; i < histSize; i++) {
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
			Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
			Scalar(0, 0, 255), 2, 8, 0);
	}

	getMaxHist();

	/// Display
	namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE);
	imshow("calcHist Demo", histImage);


	Mat image, image2;


	String image2Name("Girl_in_front_of_a_green_background.jpg"); // by default
	String image3Name("background.jpg"); // by default

	image = imread(image2Name, IMREAD_COLOR); // Read the file
	image2 = imread(image3Name, IMREAD_COLOR); // Read the file

	Mat image3 = Mat(image.size().height, image.size().width, CV_8UC3);

	if (image.empty()) {                     // Check for invalid input
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	if (image2.empty()) {                     // Check for invalid input
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	int threshHold = 75;
	r = 110;
	g = 220;
	b = 80;

	int a = 0;

	for (int y = 0; y < image.size().height; y++) {
		for (int x = 0; x < image.size().width; x++) {
			//printf("%d %d %d \n", image.at<Vec3b>(y, x)[0], image.at<Vec3b>(y, x)[1], image.at<Vec3b>(y, x)[2]);
			if ((saturate_cast<uchar>(image.at<Vec3b>(y, x)[1] + threshHold) >= g && saturate_cast<uchar>(image.at<Vec3b>(y, x)[1] - threshHold) <= g)
				&& (saturate_cast<uchar>(image.at<Vec3b>(y, x)[0] + threshHold) >= r && saturate_cast<uchar>(image.at<Vec3b>(y, x)[0] - threshHold) <= r)
				&& (saturate_cast<uchar>(image.at<Vec3b>(y, x)[2] + threshHold) >= b && saturate_cast<uchar>(image.at<Vec3b>(y, x)[2] - threshHold) <= b)) {
				//

				a = 1;

				for (int i = 0; i < 3; i++) {
					image3.at<Vec3b>(y, x)[i] = saturate_cast<uchar>(image.at<Vec3b>(y, x)[i]) * a + image2.at<Vec3b>(y, x)[i];
				}
			}
			else {
				for (int i = 0; i < 3; i++) {
					a = 1;
					image3.at<Vec3b>(y, x)[i] = saturate_cast<uchar>(image.at<Vec3b>(y, x)[i]) * a;
				}
			}
		}
	}

	/// Display
	namedWindow("calcHist", CV_WINDOW_AUTOSIZE);
	imshow("calcHist", image3);

	waitKey(0);

	return 0;
}*/