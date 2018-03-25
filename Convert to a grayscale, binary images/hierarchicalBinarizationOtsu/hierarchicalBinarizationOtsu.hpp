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
#include "binaryConversions.hpp"

class hierarchicalBinarizationOtsu: binaryConversions {
public:
    virtual void showCurrentVersion();
};

#endif /* hierarchicalBinarizationOtsu_hpp */
