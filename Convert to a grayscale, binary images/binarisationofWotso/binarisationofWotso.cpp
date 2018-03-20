//
//  binarisationofWotso.cpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 20.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "binarisationofWotso.hpp"
#include <opencv2/opencv.hpp>
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
    int t, sigmaT = 0;
    float q=0, q1=0, mu, mu1 = 0, mu2 = 0, mu1next = 0, mu2next = 0;
    // соберём всю сумму.
    for (int i = 0; i < 255; i++) {
        q += bHist.at<float>(i);
    }
    for (int i = 0; i < 255; i++) {
        q1 += + bHist.at<float>(i); // находим q1.
        int q2 = q - q1; // найдём q2.
        mu = q1*mu1 + q2*mu2; // находим mu
        mu1next = (q1 * mu1 + (i+1)*bHist.at<float>(i+1)) / (q1 + bHist.at<float>(i+1));
        mu2next = (mu - (q1 + bHist.at<float>(i+1))*mu1next) / (1 - (q1 + bHist.at<float>(i+1)));
        int sigmaI = q1 * (1 - q1) * (mu1 - mu2) * (mu1 - mu2);
        mu1 = mu1next;
        mu2 = mu2next;
        if (sigmaI > sigmaT) {
            t = i;
            sigmaT = sigmaI;
        }
    }
    return t;
}

void binarisationofWotso::conversionToBinaryOfVocoGlobale() { 
    ushort Threshold = findThreshold(); // получение порога бинаризации.
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            image.at<Vec3b>(i, j)[0] = image.at<Vec3b>(i, j)[0] > Threshold? 255: 0;
            image.at<Vec3b>(i, j)[1] = image.at<Vec3b>(i, j)[1] > Threshold? 255: 0;
            image.at<Vec3b>(i, j)[2] = image.at<Vec3b>(i, j)[2] > Threshold? 255: 0;
        }
    }
}

