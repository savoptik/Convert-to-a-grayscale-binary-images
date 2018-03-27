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
    hierarchicalBinarizationOtsu(std:: filepash, int iterations);
    ~hierarchicalBinarizationOtsu()
    virtual void showCurrentVersion();
private:
    cv::Mat maskBO; // маска бинаризованная глобальным Отсу.
    std::vector<c> masks; // вектор хранит маски.
    std::vector<int> histogram; // ручная гистограмма.
    int numIterations;
    void plotingHist();
    void binarisationHO(cv::Mat& mask);
};

#endif /* hierarchicalBinarizationOtsu_hpp */
