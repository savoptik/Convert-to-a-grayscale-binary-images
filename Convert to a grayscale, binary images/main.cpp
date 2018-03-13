//
//  main.cpp
//  Convert to a grayscale, binary images
//
//  Created by Артём Семёнов on 13.03.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include <iostream>
#include "grayScale.hpp"

int main(int argc, const char * argv[]) {
    grayScale pic("/Users/artemsemenov/Documents/projects/xcode/Convert to a grayscale, binary images/images/апельсин.png");
    pic.showGrayImage();
    return 0;
}
