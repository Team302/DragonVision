
#pragma once

//C++ Includes
#include <memory>

//OpenCV Includes
#include <opencv2/opencv.hpp>

//NetworkTables Includes
#include <networktables/NetworkTableInstance.h>

//FRC Includes
#include <vision/VisionPipeline.h>

using namespace cv;



class CellPipeline : public frc::VisionPipeline  {
    public:
    CellPipeline();
    
    Mat hsvThresholdOutput = Mat();
    Mat hsv_image;

    Mat drawnFrame;

    void Process(cv::Mat& mat) override;

    ~CellPipeline();
};