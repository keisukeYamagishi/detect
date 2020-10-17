//
//  option.h
//  detect
//
//  Created by keisukeYamagishi on 2017/01/30.
//  Copyright © 2017年 keisukeYamagishi. All rights reserved.
//

#ifndef option_h
#define option_h

#include <stdio.h>
#include <string>

using namespace std;

namespace Detect {
    class option{
    public:
        
        struct option_model{
            string search;
            string option_c;
        };
        struct option_model options;
        void setOption(int argc, const char* argv[]);
    };
}

#endif