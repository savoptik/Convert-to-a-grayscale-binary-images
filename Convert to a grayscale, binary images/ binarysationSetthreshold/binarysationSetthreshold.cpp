//
//  binarysationSetthreshold.cpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 14.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "binarysationSetthreshold.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

binarysationSetthreshold::binarysationSetthreshold(std::string filePash, ushort threshold) {
    image = imread(filePash); // чтение.
    conversionTOGrayScale(); // преобразование к полутоноовму.
    conversionToBinary(threshold); // преобразование к чёрнобелому с заданным порогом.
}

binarysationSetthreshold:: ~binarysationSetthreshold() {
    image.deallocate(); // освобождение памяти.
}

void binarysationSetthreshold::showCurrentVersion() {
    imshow("Binary version", image); // отображение изображения.
    waitKey(); // ожидание нажатия клавиши.
    destroyWindow("Binary version"); // уничтожение окна.
}

void binarysationSetthreshold::conversionToBinary(ushort threshold) {
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            // если значение байта меньше заданного, байт зануляется, иначе получает значение 255.
            image.at<Vec3b>(i, j)[0] = image.at<Vec3b>(i, j)[0] < threshold? 0: 255;
            image.at<Vec3b>(i, j)[1] = image.at<Vec3b>(i, j)[1] < threshold? 0: 255;
            image.at<Vec3b>(i, j)[2] = image.at<Vec3b>(i, j)[2] < threshold? 0: 255;
        }
    }
}
