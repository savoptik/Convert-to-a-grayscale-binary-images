//
//  binarisationofWotso.cpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 20.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "binarisationofWotso.hpp"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

binarisationofWotso::binarisationofWotso(std::string filePash) { 
    image = imread(filePash); // загрузка изображения.
    conversionTOGrayScale(); // преведение к полутоновому.
    plottingHistogram(); // построение гистограммы.
}

void binarisationofWotso::showCurrantStat() { 
    imshow("binarisation of Wotso", image); // вывод изображания
    waitKey(); // ожидание нажатия клавиши.
    destroyWindow("binarisation of Wotso"); // уничтожение окна.
}

binarisationofWotso::~binarisationofWotso() { 
    image.deallocate(); // освобождение памяти.
}

ushort binarisationofWotso::findThreshold() {
    ushort t = 0;
    double q = 0.0, q1 = 0.0, q2 = 0.0, mu = 0.0, mu1 = 0.0, mu2 = 0.0, mu1next = 0.0, mu2next = 0.0, sigmaT = 0.0;
    // соберём всю сумму.
    for (int i = 0; i < 255; i++) {
        q += bHist.at<float>(i);
    }
    for (int i = 0; i < 255; i++) {
        q1 += bHist.at<float>(i); // находим q1.
                 q2 = q - q1; // найдём q2.
        mu = q1*mu1 + q2*mu2; // mu(t) = q1(t)*mu1(t) + q2(t)*mu2(t)
        if ((q1 + bHist.at<float>(i+1)) != 0) {
            mu1next = (q1 * mu1 + (i+1)*bHist.at<float>(i+1)) / (q1 + bHist.at<float>(i+1)); // mu1(t+1) = (q1(t) * mu1(t) + (t+1)*p(t+1))/(q1(t+1))
        }
        if ((1 - q1 + bHist.at<float>(i+1)) != 0) {
            mu2next = (mu - (q1 + bHist.at<float>(i+1))*mu1next) / (1 - (q1 + bHist.at<float>(i+1))); // mu2(t+1) = (mu(t) -q1(t+1)*mu1(t+1))/(1-q1(t+1))
        }
        double sigmaI = q1 * (1 - q1) * (mu1 - mu2); // sigma^2 = q1(t)(1 - q1(t))(mu1(t) - mu2(t)^2
        sigmaI = sigmaI * sigmaI;
        mu1 = mu1next;
        mu2 = mu2next;
        if (sigmaI > sigmaT) {
            t = static_cast<ushort>(i);
            sigmaT = sigmaI;
        }
    }
    return t;
}

void binarisationofWotso::conversionToBinaryOfVocoGlobale() { 
    ushort Threshold = findThreshold(); // получение порога бинаризации.
    // выполнение бинаризации.
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            image.at<Vec3b>(i, j)[0] = image.at<Vec3b>(i, j)[0] > Threshold? 255: 0;
            image.at<Vec3b>(i, j)[1] = image.at<Vec3b>(i, j)[1] > Threshold? 255: 0;
            image.at<Vec3b>(i, j)[2] = image.at<Vec3b>(i, j)[2] > Threshold? 255: 0;
        }
    }
}

void binarisationofWotso::exportToDisk(std::string filePash) { 
    imwrite(filePash, image); // запись полученного изображения на диск по заданному пути.
}
