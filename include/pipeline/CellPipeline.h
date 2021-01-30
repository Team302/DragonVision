
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
    void processThreshold(Mat source0)
    {

        // Step 1: HSV Thresholding
        Mat hsvThresholdInput = source0;

        //Convert RGB image into HSV image
        cvtColor(hsvThresholdInput, hsv_image, COLOR_BGR2HSV);

        //Threshold image into binary image
        //TODO:implement a way to change HSV values on the fly through network tables
        Mat binary_img;
        // double hsvThresholdHue[2] = { 8.093525179856115, 34.09556313993174};
        // double hsvThresholdSat[2] = { 94.01978417266191, 255.0};
        // double hsvThresholdVal[2] = { 0.0, 255.0};

        inRange(hsv_image, Scalar(8.093525179856115, 94.01978417266191, 0.0), Scalar(34.09556313993174, 255.0, 255.0), hsvThresholdOutput);

    };

    ~CellPipeline();
    private:
    // Mat blurOutput;
};