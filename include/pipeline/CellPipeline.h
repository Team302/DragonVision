
#pragma once

//C++ Includes
#include <memory>

//OpenCV Includes
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

//NetworkTables Includes
#include <networktables/NetworkTableInstance.h>

//FRC Includes
#include <vision/VisionPipeline.h>



class CellPipeline : public frc::VisionPipeline  {

    private:
    cv::Mat blurOutput = new Mat();
};