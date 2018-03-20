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
}

void binarisationofWotso::showCurrantStat() { 
    <#code#>;
}

binarisationofWotso::~binarisationofWotso() { 
    image.delocate(); // освобождение памяти.
}

int binarisationofWotso::findThreshold() { 
    <#code#>;
}

void binarisationofWotso::conversionToBinaryOfVocoGlobale() { 
    <#code#>;
}

