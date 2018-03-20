//
//  binaryConversions.hpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 14.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef binaryConversions_hpp
#define binaryConversions_hpp

#include <stdio.h>
#include <opencv2/opencv.hpp>

class binaryConversions {
public:
    virtual void showCurrentVersion() {} // отображатель текущего состояния картинки.
    cv::Mat& getImageMatrix(){return image;} // просто возврат ссылки на картинку. мало ли что?
    
protected:
    cv::Mat image; // хранилище изображения.
    int max;
    void conversionTOGrayScale(); // метод преобразует изображение к полутоновому.
};

#endif /* binaryConversions_hpp */
