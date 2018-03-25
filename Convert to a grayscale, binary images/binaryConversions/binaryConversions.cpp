//
//  binaryConversions.cpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 14.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "binaryConversions.hpp"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

void binaryConversions::conversionTOGrayScale() {
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            auto buf = image.at<Vec3b>(i, j); // получаем пиксель, разложенный на каналы.
            int mid = (buf[0] + buf[1] + buf[2])/3; // вычисляем среднее.
            // записываем среднее в каналы.
            image.at<Vec3b>(i, j)[0] = mid;
            image.at<Vec3b>(i, j)[1] = mid;
            image.at<Vec3b>(i, j)[2] = mid;
        }
    }
}

void binaryConversions::exportToDisk(std::string filePash) {
    imwrite(filePash, image); // запись полученного изображения на диск по заданному пути.
}
