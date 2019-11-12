//
//  main.c
//  securityProject
//
//  Created by HyunJin Kim on 2019/11/09.
//  Copyright © 2019 HyunJin Kim. All rights reserved.
//

#include <stdio.h>
#include "func.h"
#include "struct.h"

int main(void) {
    List *files = NULL;
    List *encrypted = NULL;
    List *not_encrypted = NULL;
    
    char * home = get_home_enviroment();
    char * desktop = get_desktop_enviroment(home);
    char * username = get_username();
    //아래는 다 비슷한 내용일듯 싶고 실제 구현할 필요는 없어보여 일단 생략함. 
//    char * trash = get_trash_path(home);
//    char * media = get_media_path(username);
    
    return 0;
}
