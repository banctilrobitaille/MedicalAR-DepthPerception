#ifndef __MAIN_H
#define __MAIN_H

#include <string>
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <cstdint>
#include "opencv2/opencv.hpp"
#include <map>
#include <fstream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

const std::string DATA_DIRECTORY = ".\\data\\";
const std::string COLOR_IMAGE_PATH = "img.png";
const std::string SKELETON_IMAGE = "vr.png";
const std::string JOINTS_DATA_FILE = "joints.txt";
const int ESCAPE = 27;
const int BLACK = 0;
const int R_CHANNEL = 0;
const int G_CHANNEL = 1;
const int B_CHANNEL = 2;

bool isBlack(cv::Vec3b pixel);
#endif