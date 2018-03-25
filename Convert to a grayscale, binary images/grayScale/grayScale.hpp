//
//  grayScale.hpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 13.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#ifndef grayScale_hpp
#define grayScale_hpp

#include "binaryConversions.hpp"
#include <stdio.h>

class grayScale: binaryConversions {
public:
    grayScale(std::string); // конструктор принимает имя файла, читает файл и преобразует изображение к полутоновому.
    ~grayScale(); // Деструктор освобождает память.
    virtual void showCurrentVersion(); // отображает изменённую картинку.
};

#endif /* grayScale_hpp */
