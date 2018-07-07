//
//  main.c
//  GPS sort
//
//  Created by qiuyu on 18/7/6.
//  Copyright © 2018年 qiuyu. All rights reserved.
//

#include <stdio.h>

int main()

{
    FILE *fp1,*fp2;
    char str1[65];
    char str2[65];
    char lat[9];
    char lon[10];
    char time1[3];
    char time2[5];
    char date[7];
    char speed[6];
    char height[5];
    int i;
    fp1=fopen("//Users//qiuyu//Desktop//GPS sort//GPS170510.log","r");
    fp2=fopen("//Users//qiuyu//Desktop//GPS dort//out.csv","w");
    while(fscanf(fp1,"%s%s",str1,str2)!=EOF)
    {
        printf("结果:%s\n%s\n",str1,str2);
        for(i=0;i<2;i++)
        {
            time1[i]=str1[i+7];
            time1[2]='\0';
        }
        for(i=0;i<4;i++)
            {
                time2[i]=str1[i+9];
                time2[4]='\0';
            }
        for(i=0;i<8;i++)
        {
            lat[i]=str1[i+16];
            lat[8]='\0';
        }
        for(i=0;i<9;i++)
        {
            lon[i]=str1[i+27];
            lon[9]='\0';
        }
        for(i=0;i<6;i++)
        {
            date[i]=str1[i+5];
            date[6]='\0';
        }
        for(i=0;i<5;i++)
        {
            speed[i]=str1[i+51];
            speed[5]='\0';
        }
        for(i=0;i<4;i++)
        {
            height[i]=str2[i+39];
            height[4]='\0';
        }
        printf("UTC日月年:%s\n",date);
        printf("UTC小时:%s\n",time1);
        printf("UTC分秒:%s\n",time2);
        printf("纬度:%s\n",lat);
        printf("经度:%s\n",lon);
        printf("速率:%s\n",speed);
        printf("海拔:%s米\n",height);
        fprintf(fp1,"UTC日月年:%s,",date);
        fprintf(fp1,"UTC小时:%s,",time1);
        fprintf(fp1,"UTC分秒:%s,",time2);
        fprintf(fp1,"纬度:%s,",lat);
        fprintf(fp1,"经度:%s,",lon);
        fprintf(fp1,"速率:%s",speed);
        fprintf(fp1,"海拔:%s米,\n",height);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
