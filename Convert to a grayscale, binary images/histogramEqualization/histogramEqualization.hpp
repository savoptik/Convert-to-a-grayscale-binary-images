//
//  histogramEqualization.hpp
//  Luminance_conversion
//
//  Created by Артём Семёнов on 17.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef histogramEqualization_hpp
#define histogramEqualization_hpp

#include <stdio.h>
#include <string>
#include "binaryConversions.hpp"

class histogramEqualization: binaryConversions {
public:
    virtual void showCurrantStat(); // вывод результата.
protectit:
    cv::Mat bHist; // матрица для гистограммы синего цвета.
    void plottingHistogram(); // построение гистограммы.
    void normalizationHistogram(); // нормализация гистограммы.
    void buildingStackedHistogram(); // построение гистограммы с накоплением.
    void uniformDistributionValues(); // ровномерное распределение значений.
};

#endif /* histogramEqualization_hpp */
