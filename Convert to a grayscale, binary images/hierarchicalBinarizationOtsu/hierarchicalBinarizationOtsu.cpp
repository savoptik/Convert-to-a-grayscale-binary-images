//
//  hierarchicalBinarizationOtsu.cpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 25.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "hierarchicalBinarizationOtsu.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include "binarisationofWotso.hpp"
using namespace cv;

void hierarchicalBinarizationOtsu::showCurrentVersion() { 
    imshow("Hierarchical binarization Otsu", image);
    waitKey();
    destroyWindow("Hierarchical binarization Otsu");
}

hierarchicalBinarizationOtsu::~hierarchicalBinarizationOtsu() { 
    image.deallocate(); // Уничтожение изображения.
    masks.clear(); // уничтожение вектора масок.
}

std::vector<int> hierarchicalBinarizationOtsu::plotingHist(cv::Mat &mask, int activPiks) {
    std::vector<int> hist(256); // Гистограма
    for (int i = 0; i < image.rows; i++) {
        for (int j =0; j < image.cols; j++) {
            if (mask.at<Vec3b>(i, j)[0] == activPiks) { // Если пиксель относится к интересующей облости
                hist[image.at<Vec3b>(i, j)[0]]++; // строим гистограмму.
            }
        }
    }
}

ushort hierarchicalBinarizationOtsu::findThreshold(std::vector<int>& hist) {
    ushort t = 0;
    double q = 0.0, q1 = 0.0, q2 = 0.0, mu = 0.0, mu1 = 0.0, mu2 = 0.0, mu1next = 0.0, mu2next = 0.0, sigmaT = 0.0;
    // соберём всю сумму.
    for (int i = 0; i < 255; i++) {
        q += hist[i];
    }
    for (int i = 0; i < 255; i++) {
        q1 += hist[i]; // находим q1.
        q2 = q - q1; // найдём q2.
        mu = q1*mu1 + q2*mu2; // mu(t) = q1(t)*mu1(t) + q2(t)*mu2(t)
        if ((q1 + hist[i+1]) != 0) {
            mu1next = (q1 * mu1 + (i+1)* hist[i+1]) / (q1 + hist[i+1]); // mu1(t+1) = (q1(t) * mu1(t) + (t+1)*p(t+1))/(q1(t+1))
        }
        if ((1 - q1 + hist[i+1]) != 0) {
            mu2next = (mu - (q1 + hist[i+1])*mu1next) / (1 - (q1 + hist[i+1])); // mu2(t+1) = (mu(t) -q1(t+1)*mu1(t+1))/(1-q1(t+1))
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

cv::Mat hierarchicalBinarizationOtsu::generaitMask(ushort threshold) { 
    auto mask = image; // Маска.
    for (int i = 0; i < mask.rows; i++) {
        for (int j = 0; j < mask.cols; j++) {
            mask.at<Vec3b>(i, j)[0] = mask.at<Vec3b>(i, j)[0] > threshold? 255: 0;
            mask.at<Vec3b>(i, j)[1] = mask.at<Vec3b>(i, j)[1] > threshold? 255: 0;
            mask.at<Vec3b>(i, j)[2] = mask.at<Vec3b>(i, j)[2] > threshold? 255: 0;
        }
    }
}

void hierarchicalBinarizationOtsu::binarisationHO(cv::Mat &mask, int numIt) { 
    std::vector<int> histNull = plotingHist(mask, 0); // построение гистограммы при активных нулях.
    std::vector<int> histUnit = plotingHist(mask, 255); // построение гистограммы для области активных единиц.
    ushort tNul = findThreshold(histNull); // поиск порога для бинаризации области активных нулей.
    ushort tUnit = findThreshold(histUnit); // поиск порога для бинаризации области активных единиц.
    Mat maskNul = generaitMask(tNul); // генерация маски.
    Mat maskUnit = generaitMask(tUnit);
    if ((numIt-1) != 0) { // Если количество доступных итераций позволяет
        binarisationHO(maskNul, numIt-1); // рекурсивно вызываем этот же метод с нулевой маской и уменьшеным количеством итераций.
        binarisationHO(maskUnit, numIt-1); // вызываем тот же метод с активными единицами и уменьшеным количеством итераций.
    } else { // иначе значит что перамида рекурсии дошла до дна, и можно собирать маски с нижнего уровня.
        masks.push_back(maskNul);
        masks.push_back(maskUnit);
    }
}

hierarchicalBinarizationOtsu::hierarchicalBinarizationOtsu(std::string filepash, int iterations) { 
    image = imread(filepash); // чтение файла.
    conversionTOGrayScale(); // приведение изображение к полутоновому.
    binarisationofWotso globalMask(image); // создание маски.
    binarisationHO(globalMask.getImageMatrix(), iterations); // запуск рекурсивного создания масок.
    imageAssembly(); // сборка изображения из масок.
}

void hierarchicalBinarizationOtsu::imageAssembly() { 
    for (int i = 0; i < masks.size(); i+=2) {
        imageAssemblyNull(masks[i]); // собираем маску нулей.
        imageAssemblyUnit(masks[i+1]); // собираем маску единиц.
    }
}
