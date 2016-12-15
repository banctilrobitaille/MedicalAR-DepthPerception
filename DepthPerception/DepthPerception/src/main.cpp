
#include "main.h";

int main()
{	
	typedef std::map<int, std::pair<float, float>>::iterator it_type;
    // Read joint data (change path to file if necessary)
    // See: https://msdn.microsoft.com/en-us/library/microsoft.kinect.jointtype.aspx
    // for information about the mapping between joints and indices. 
    std::ifstream ifs(DATA_DIRECTORY + JOINTS_DATA_FILE);
    std::map<int, std::pair<float, float>> joints;
    int n;
    float a, b;
    while (ifs >> n >> a >> b)
    {
        std::pair<int, std::pair<float, float>> p = std::make_pair(n, std::make_pair(a, b));
        joints.insert(p);
    }
	
	cv::Mat colorImage = cv::imread(DATA_DIRECTORY + COLOR_IMAGE_PATH);
	cv::Mat skeletonImage = cv::imread(DATA_DIRECTORY + SKELETON_IMAGE);

	for (it_type iterator = joints.begin(); iterator != joints.end(); iterator++){
		cv::Point point = cv::Point(iterator->second.first, iterator->second.first);
		cv::circle(colorImage, cv::Point(iterator->second.first, iterator->second.second), 8, cv::Scalar(255, 0, 0), 3);
	}

	int channel = skeletonImage.channels();
	cv::Size imageSize = colorImage.size();
	for (int row = 0; row < imageSize.height; row++){
		for (int col = 0; col < imageSize.width; col++){
			if (!isBlack(skeletonImage.at<cv::Vec3b>(row, col))){
				colorImage.at<cv::Vec3b>(row, col) = skeletonImage.at<cv::Vec3b>(row, col);
			}
		}
	}

	while (true)
	{
		int key = 0;
		cv::imshow("Joints identification", colorImage);
		key = cv::waitKey(1);
		if (key == ESCAPE){
			break;
		}
	}
	return 0;
}

bool isBlack(cv::Vec3b pixel){
	return pixel[R_CHANNEL] == BLACK || pixel[G_CHANNEL] == BLACK || pixel[B_CHANNEL] == BLACK;
}