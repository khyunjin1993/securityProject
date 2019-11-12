//
//  func.h
//  securityProject
//
//  Created by HyunJin Kim on 2019/11/09.
//  Copyright © 2019 HyunJin Kim. All rights reserved.
//

#ifndef func_h
#define func_h

#include <stdio.h>
#include "struct.h"
#include <stdbool.h>    // to use bool function
void find_files(List **files, char* start_path);
bool is_path(char *path);
#endif /* func_h */
