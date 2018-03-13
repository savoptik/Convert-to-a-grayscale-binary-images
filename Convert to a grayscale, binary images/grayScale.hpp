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
    grayScale(std::string);
    ~grayScale();
    void showGrayImage();
    
protected:
    cv::Mat image; // хранилище изображения.
    
private:
    void conversionTOGrayScale();
    
};

#endif /* grayScale_hpp */
