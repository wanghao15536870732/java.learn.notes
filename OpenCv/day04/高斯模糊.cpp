#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#define WINDOW_NAME "【程序窗口】"
#define PI 3.1415926

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    /*
	VideoCapture video(0);
	while (true)
	{
		Mat frame;//视频的每一帧
		video >> frame;  //将视频写入每一帧
		cvtColor(frame,frame,COLOR_RGB2GRAY);
		cvNamedWindow("frame", WINDOW_AUTOSIZE);
		imshow("frame",frame);

		waitKey(30); 
	}
	*/

    /*
	Mat srcImage = imread("D:\\Desktop\\lena.jpg", 1);  //读取图片
	cvtColor(srcImage, srcImage,COLOR_BGR2GRAY);  //转为灰度图像

	namedWindow("srcImage", WINDOW_AUTOSIZE);  //新建窗口
	imshow("srcImage", srcImage);  //显示图像
	//waitKey(0);  //图像显示为一帧

	//由于中型差分的原因，输出图像比原始图象少了两列
	Mat dImage = Mat(srcImage.rows,srcImage.cols - 2,CV_8UC1);

	//循环遍历整个图像
	for (int i = 0; i < srcImage.rows; i++)
	{
		for (int j = 1; j < srcImage.cols - 1; j++)
		{
			//对整型数据类型进行运算,进行中型差分
			dImage.at<uchar>(i, j - 1) = srcImage.at<uchar>(i, j + 1) - srcImage.at<uchar>(i, j - 1);
		}
	}
	namedWindow("dImage", WINDOW_AUTOSIZE);  //处理后图像窗口
	imshow("dImage", dImage);  //显示处理后的图像

	waitKey(0);  //图像显示为一帧
	*/

    Mat srcImage = imread("D:\\Desktop\\lena.jpg", 1); //读取图片
    cvtColor(srcImage, srcImage, COLOR_BGR2GRAY);      //转为灰度图像
    namedWindow("srcImage", WINDOW_AUTOSIZE);          //新建窗口
    imshow("srcImage", srcImage);                      //显示图像

    Mat dst = srcImage.clone();

    //一行代码高斯模糊
    GaussianBlur(srcImage, dst, Size(17, 17), 180);

    /*高斯模糊*/

    /*
	//5×5卷积模板
	Mat model = Mat(5, 5, CV_64FC1);
	double sigma = 80;  //超参数，根据经验所得
	for (int i = - 2; i <= 2 ; i++)  //进行遍历
	{
		for (int j = -2; j <= 2; j++)
		{
			//正态分布
			model.at<double>(i + 2, j + 2) =
				exp(-(i * i + j * j) / (2 * sigma * sigma)) /
				(2 * PI * sigma * sigma);
		}
	}

	//归一化
	double gaussSum = 0;
	gaussSum = sum(model).val[0];  //卷积盒求和
	for (int i = 0; i < model.rows; i++)
	{
		for (int j = 0; j < model.cols; j++)
		{
			model.at<double>(i, j) = model.at<double>(i, j) 
				/ gaussSum;
		}
	}

	Mat dst = Mat(srcImage.rows - 4,srcImage.cols - 4,CV_8UC1);

	for (int i = 2; i < srcImage.rows - 2; i++)
	{
		for (int j = 2; j < srcImage.cols - 2; j++)
		{
			double sum = 0;  //求和目标值
			for (int m = 0; m < model.rows; m++)
			{
				for (int n = 0; n < model.cols; n++)
				{
					sum += (double)srcImage.at<uchar>(i + m - 2, j + n - 2) * 
						model.at<double>(m,n);  //对整个卷积盒进行卷积
				}
			}
			dst.at<uchar>(i - 2, j - 2) = (uchar)sum;  //结果赋值到dst图像当中
		}
	}
	*/

    namedWindow("gaussBlur", WINDOW_AUTOSIZE);
    imshow("gaussBlur", dst);
    waitKey(0); //图像显示为一帧
    return 0;
}