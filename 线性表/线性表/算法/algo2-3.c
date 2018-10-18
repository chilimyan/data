//
//  algo2-3.c
//  线性表
//
//  Created by chilim on 2018/10/13.
//  Copyright © 2018年 chilim. All rights reserved.
//

#include "algo2-3.h"

// 已知顺序线性表La和Lb的元素按值非递减排列。
// 归并La和Lb得到新的顺序线性表Lc,Lc的元素也按值非递减排列
void MergeList23(PSqlist La, PSqlist Lb, PSqlist Lc){
    ElemType *pa, *pa_last, *pb, *pb_last, *pc;
    pa = La->elem;
    pb = Lb->elem;
    // 不用InitList()创建空表Lc
    Lc->listsize = Lc->length = La->length + Lb->length;
    pc = Lc->elem = (ElemType *)malloc(Lc->listsize * sizeof(ElemType));
    if (!Lc->elem) {// 存储分配失败
        exit(OVERFLOW);
    }
    pa_last = La->elem + La->length -1;
    pb_last = Lb->elem + Lb->length -1;
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb) {
            *pc++ = *pa++;// 将pa所指单元的值赋给pc所指单元后，pa和pc分别+1(指向下一个单元)
        }else{
            *pc++ = *pb++;// 将pb所指单元的值赋给pc所指单元后，pa和pc分别+1(指向下一个单元)
        }
    }
    while (pa <= pa_last) {
        *pc++ = *pa++;
    }
    while (pb <= pb_last) {
        *pc++ = *pb++;
    }
}

void main24(){
    struct SqList La,Lb,Lc;
    int j;
    InitList(&La);// 创建空表La
    for (j = 1; j <= 5; j++) {// 在表La中插入5个元素，依次为1、2、3、4、5
        ListInsert(&La, j, j);
    }
    printf("La= "); // 输出表La的内容
    ListTraverse(&La, print1);
    InitList(&Lb);//// 创建空表Lb
    for (j = 1; j <= 5; j ++) {
        ListInsert(&Lb, j, 2*j);
    }
    printf("Lb= "); // 输出表Lb的内容
    ListTraverse(&Lb, print1);
    MergeList23(&La, &Lb, &Lc);
    printf("Lc= "); // 输出表Lc的内容
    ListTraverse(&Lc, print1);
}
