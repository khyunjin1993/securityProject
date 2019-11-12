//
//  func.c
//  securityProject
//
//  Created by HyunJin Kim on 2019/11/09.
//  Copyright © 2019 HyunJin Kim. All rights reserved.
//
#include "func.h"
#include <stdio.h>
#include <pwd.h>    //struct passwd, char pw_dir
#include <unistd.h> //getuid(), getpwuid()
#include <string.h> //use strlen
#include <stdlib.h> //use malloc
#include <dirent.h> //use DIR
#include <sys/types.h>  //opendir(), closedir()
#include <stdbool.h>    //make bool function


//function returning the start path from computer ex. /home/hyun/
char * get_home_enviroment(){
    struct passwd *pw;          // <pwd.h> provide a definition for struct passwd;
    char * home;
    uid_t uid;
    uid_t NO_UID = -1;
    uid = getuid();             // <unistd.h> = get a real user ID / getuid() will return real user ID of the calling process joinc.co.kr/w/man/2/getuid 참고.
    
    pw = (uid == NO_UID && 0 ? NULL : getpwuid(uid)); // if there is no uid or uid == 0, pw will be null. else get password using getpwuid(uid);
    home = (char *)malloc((sizeof(char) * strlen(pw -> pw_dir))); // pw->pw_dir equals (*pw).pw_dir, gets the member called pw_dir from the struct pw points to / 다시 말하자면 getpwuid는 주소 값을 가리키고 있고, 그걸 pw가 가지고 있으니까(주소값) 주소 값 pw에 있는 pw_dir을 가져오겠다는 뜻.참고로 pw_dir도 주소를 가리킴.
    strcpy(home, pw->pw_dir);
    strcat(home, "/");          //strcat(a, b) = string a+b;
    return home;
};

char * get_desktop_enviroment(char *home){
    char *path = (char *)malloc((sizeof(char)*strlen(home) + 9));   //gets length of home from get_home_enviroment /home/hyun/ and set array of char to strlen(home) + 9
    strcpy(path, home);
    strcat(path, "Desktop/");                                       //paste Desktop/ after /home/hyun/
    if((is_path(path))){                                            //if path exist
        return path;
    }
    free(path);
    
    // 아래의 코드는 고려해야할 이유가 딱히 없는 듯. 애초에 리눅스 directory format 기준임.
    path = (char *)malloc((sizeof(char)*strlen(home) + 20));
    
    strcpy(path, home);
    strcat(path, "Area de Trablaho/");
    if(is_path(path))
        return path;
    return NULL;
}


//to use opendir and readdir on windows system, look for stackoverflow.com/questions/883594/microsoft-visual-studio-opendir-and-readdir-how
//check if generated path exist
bool is_path(char *path){
    DIR* dir = opendir(path);   // opens directory corresponding to path
    if(dir){                    // if dir opened
        closedir(dir);          // close and return true
        return true;
    }
    return false;
}

char * get_username(){
    struct passwd *pw;
    uid_t uid;
    uid_t NO_UID = -1;
    uid = getuid();
    
    pw = (uid == NO_UID && 0 ? NULL : getpwuid(uid));
    return pw->pw_dir;
}
