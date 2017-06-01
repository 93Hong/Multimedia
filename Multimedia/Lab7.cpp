/*
#pragma warning(disable : 4819)

#include <opencv2\opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

	Mat input = imread("left.png", IMREAD_COLOR);
	Mat input2 = imread("right.png", IMREAD_COLOR);

	if (input.empty() || input2.empty()) {
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	cvtColor(input, input, CV_BGR2GRAY);
	cvtColor(input2, input2, CV_BGR2GRAY);
	Mat output = Mat::zeros(input.rows, input.cols, input.type());

	int col = input.cols;
	int row = input.rows;

	float sum = 0.f;
	float minsum = 1000000000;
	int minindex = -1;

	for (int i = 4; i < col - 4; i++) {
		for (int j = 4; j < row - 4; j++) {
			for (int k = 0; k < 16; k++) {
				sum = 0;
				if (i + k >= col) {
					continue;
				}
				else {
					for (int a = -4; a < 3; a++) {
						for (int b = -4; b < 3; b++) {
							if (i + k + a >= col) {
								continue;
							}
							else {
								float tmp = (input.at<uchar>(j + b, i + a + k) - input2.at<uchar>(j + b, i + a));
								sum += tmp*tmp;
							}
						}
					}
				}
				if (minsum > sum) {
					minsum = sum;
					minindex = k;
					//printf("%d /", minindex);
				}
			}
			output.at<uchar>(j, i) = minindex * 16;
			minsum = 1000000000;
		}
	}

	namedWindow("Input", WINDOW_AUTOSIZE);
	imshow("Input", input);
	namedWindow("Output", WINDOW_AUTOSIZE);
	imshow("Output", output);
	waitKey(0);
	return 0;
}*/