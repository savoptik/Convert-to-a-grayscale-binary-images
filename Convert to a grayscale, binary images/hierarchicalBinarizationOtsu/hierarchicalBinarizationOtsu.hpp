//
//  hierarchicalBinarizationOtsu.hpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 25.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef hierarchicalBinarizationOtsu_hpp
#define hierarchicalBinarizationOtsu_hpp

#include <stdio.h>
#include <vector>
#include "binaryConversions.hpp"
#include <map>

class hierarchicalBinarizationOtsu: binaryConversions {
public:
    hierarchicalBinarizationOtsu(std::string filepash, int iterations); // конструктор загрузит изображение  и запустит преобразования.
    ~hierarchicalBinarizationOtsu(); // деструктор освободит память.
    virtual void showCurrentVersion(); // вывод изображения.
private:
    std::vector<cv::Mat> masks; // вектор хранит маски.
    std::vector<int> plotingHist(cv::Mat& mask, int activPiks); // построение гистограммы по маске.
    void binarisationHO(cv::Mat& mask, int numIt); // выполнение иерархической бинаризации.
    cv::Mat generaitMask(ushort threshold); // создание новой маски по гистограмме.
    ushort findThreshold(std::vector<int>& hist); // вычисление порога.
    void imageAssembly();
};

#endif /* hierarchicalBinarizationOtsu_hpp */
