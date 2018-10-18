//
//  func2-3.c
//  线性表
//
//  Created by chilim on 2018/10/11.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "func2-3.h"

// 判断是否相等的函数
Status equal(ElemType c1, ElemType c2){
    if (c1 == c2) {
        return TRUE;
    }else{
        return FALSE;
    }
}

// 根据a<、=或>b，分别返回-1、0或1
int comp(ElemType a, ElemType b){
    if (a == b) {
        return 0;
    }else{
        return (a-b)/abs(a-b);
    }
}

void print(ElemType c)
{
    printf("%d ",c);
}

void print2(ElemType c)
{
    printf("%c ",c);
}

void print1(ElemType *c)
{
    printf("%d ",*c);
}
