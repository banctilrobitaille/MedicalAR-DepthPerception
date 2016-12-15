#include <map>
#include <fstream>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
    // Read joint data (change path to file if necessary)
    // See: https://msdn.microsoft.com/en-us/library/microsoft.kinect.jointtype.aspx
    // for information about the mapping between joints and indices. 
    std::ifstream ifs("joints.txt");
    std::map<int, std::pair<float, float>> joints;
    int n;
    float a, b;
    while (ifs >> n >> a >> b)
    {
        std::pair<int, std::pair<float, float>> p = std::make_pair(n, std::make_pair(a, b));
        joints.insert(p);
    }

    // Read images
    // ...
}