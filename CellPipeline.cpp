
#include <pipeline/CellPipeline.h>
#include <opencv2/opencv.hpp>
#include <networktables/NetworkTableInstance.h>
#include <vision/VisionPipeline.h>
#include <memory>
#include <cameraserver/CameraServer.h>

CellPipeline::CellPipeline()
{
    //Create network tables
    // auto ntinst = nt::NetworkTableInstance::GetDefault();
    // auto table = ntinst.GetTable("visionTable");
    // auto CellRunnerEntry = ntinst.GetEntry("CellVisionRunner");
    //create cameraserver source and jpeg server to take thresholded output to be displayed
    
}



void CellPipeline::Process(cv::Mat& mat)
{
    cs::CvSource outputStream = frc::CameraServer::GetInstance()->PutVideo("Processed", 160, 120);
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
    outputStream.PutFrame(hsvThresholdOutput);
}