//
//  grayScale.hpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 13.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef grayScale_hpp
#define grayScale_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <string>

class grayScale {
public:
    grayScale(std::string); // конструктор.
    ~grayScale(); // диструктор.
    void showGrayImage(); // отображатель текущего состояния картинки.
    
protected:
    cv::Mat image; // хранилище изображения.
    
private:
    void conversionTOGrayScale(); // метод преобразует изображение к полутоновому.
    
};

#endif /* grayScale_hpp */
