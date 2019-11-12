//
//  struct.h
//  securityProject
//
//  Created by HyunJin Kim on 2019/11/09.
//  Copyright © 2019 HyunJin Kim. All rights reserved.
//

#ifndef struct_h
#define struct_h

typedef struct node{
    struct node *prox;
    char *ino[3];
    int size;
}List;
#endif /* struct_h */
