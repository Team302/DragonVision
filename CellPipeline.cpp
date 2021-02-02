
#include <pipeline/CellPipeline.h>
#include <opencv2/opencv.hpp>
#include <networktables/NetworkTableInstance.h>
#include <vision/VisionPipeline.h>
#include <memory>
#include <cameraserver/CameraServer.h>

CellPipeline::CellPipeline()
{
auto ntinst = nt::NetworkTableInstance::GetDefault();
auto table = ntinst.GetTable("visionTable");
auto CellRunnerEntry = ntinst.GetEntry("CellVisionRunner");
// cs::CvSource outputStream("Threshold", , )
// cs::MjpegServer mjpegServer2("serve_Threshold",);
}

void Process(cv::Mat& mat)
{
 
    // Step 1: HSV Thresholding
    Mat hsvThresholdInput = mat;
    Mat hsv_image;
    Mat hsvThresholdOutput;
    //Convert RGB image into HSV image
    cvtColor(hsvThresholdInput, hsv_image, COLOR_BGR2HSV);

    //Threshold image into binary image
    //TODO:implement a way to change HSV values on the fly through network tables
    Mat binary_img;

    inRange(hsv_image, Scalar(8.093525179856115, 94.01978417266191, 0.0), Scalar(34.09556313993174, 255.0, 255.0), hsvThresholdOutput);
    // cs::CvSource 
}