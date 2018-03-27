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
    hierarchicalBinarizationOtsu(std:: filepash, int iterations); // конструктор загрузит изображение, запишет количество итераций и запустит преобразования.
    ~hierarchicalBinarizationOtsu(); // деструктор освободит память.
    virtual void showCurrentVersion(); // вывод изображения.
private:
    cv::Mat maskBO; // маска бинаризованная глобальным Отсу.
    std::vector<cv::Mat> masks; // вектор хранит маски.
    int numIterations; // количество итераций.
    std::vector<int> plotingHistZero(cv::Mat& mask); // построение гистограммы по маске.
    std::vector<int> plotingHistUnit(cv::Mat& mask); // построение гистограммы по маске.
    void binarisationHO(cv::Mat& mask); // выполнение иерархической бинаризации.
    cv::Mat generaitMask(std::vector<int>& hist); // создание новой маски по гистограмме.
};

#endif /* hierarchicalBinarizationOtsu_hpp */
