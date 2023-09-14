#include "opencv_process.h"
#include "esp_log.h"

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"

static const char *TAG = "opencv_proccess";

using namespace cv;

int img_process(int height, int width, void *pBuf, char ucMode)
{
    ESP_LOGI(TAG, "img_process running");

    Mat inputImage(height, width, CV_8UC2, pBuf); // rgb565 is 2 channels of 8-bit unsigned
    static Mat imageCopy;

    if (inputImage.empty())
    {
        ESP_LOGW(TAG, "Can't display empty image");
        return 0;
    }

    if (ucMode == 0)
    {
    }
    else if (ucMode == 1)
    {
        cvtColor(inputImage, inputImage, COLOR_BGR5652GRAY);
    }
    else if (ucMode == 2)
    {
        cvtColor(inputImage, inputImage, COLOR_BGR5652GRAY);
        threshold(inputImage, inputImage, 128, 255, THRESH_BINARY);
    }
    else if (ucMode == 3)
    {
        cvtColor(inputImage, inputImage, COLOR_BGR5652GRAY);
        // Reduce noise with a kernel 3x3
        blur(inputImage, inputImage, Size(3, 3));
        /** Apply the canny edges detector with:
         * - low threshold = 50
         * - high threshold = 4x low
         * - sobel kernel size = 3x3
         */
        int lowThresh = 40;
        int kernSize = 3;
        Canny(inputImage, inputImage, lowThresh, 4 * lowThresh, kernSize);
    }

    if (inputImage.type() == CV_8UC1)
    { // grayscale image
        cvtColor(inputImage, imageCopy, COLOR_GRAY2BGR565, 1);
    }
    else if (inputImage.type() == CV_8UC3)
    { // BGR888 image
        cvtColor(inputImage, imageCopy, COLOR_BGR2BGR565, 1);
    }
    else if (inputImage.type() == CV_8UC2)
    { // BGR565 image
        inputImage.copyTo(imageCopy);
    }

    return (uint32_t)(imageCopy.ptr<uchar>(0));
}