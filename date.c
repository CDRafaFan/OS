#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <libgen.h>
#include <time.h>
int main(int argc,char* argv[])
{
    char* arr1[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    char* arr2[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
    char* arr3[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    char* arr4[7]={"Sun","Mon","Tue","Wed","Thur","Fri","Sat"};
    int len=0;
    int cap=16;
    char **tok=malloc(16*sizeof(char *));
    char *delim=" \t\r\n";
    char *token=strtok(argv[1],delim);
    while(token!=NULL)
    {
        tok[len]=token;
        len++;
        if(len>=cap)
        {
            cap=(int)(cap*1.5);
            tok=realloc(tok,cap*sizeof(char*));
        }
        token=strtok(NULL,delim);
    }
    tok[len]=NULL;
    //bigArrayD[currtime.tm_wday],currtime.tm_mday,bigarrayM[currtime.tm_mon],(currtime.tm_year+1900),((currtime.tm_hour>=12?currtime.tm_hour-12:currtime.tm_hour)),currtime.tm_min,currtime.tm_sec,((currtime.tm_hour>=12?"PM":"AM")));
    if(tok[0]==NULL || strcmp(tok[0],"-u")==0 || strcmp(tok[0],"--utc")==0 || strcmp(tok[0],"--universal")==0)
    {
        time_t rawtime=time(NULL);
        struct tm * timeinfo;
        timeinfo = localtime(&rawtime);
        int tnet;int mflag=0;int sflag=0;int hflag=0;
        if(timeinfo->tm_hour>=12)
        tnet=timeinfo->tm_hour-12;
        else
        tnet=timeinfo->tm_hour;
        if(timeinfo->tm_min<10)
        mflag=1;
        if(timeinfo->tm_sec<10)
        sflag=1;
        if(tnet<10)
        hflag=1;
        if(mflag==0 && sflag==0 && hflag==0)
        printf("%s %d %s %d %d:%d:%d %s UTC\n",arr3[timeinfo->tm_wday],timeinfo->tm_mday,arr1[timeinfo->tm_mon],(timeinfo->tm_year+1900),tnet,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_hour>=12?"PM":"AM");
        else
        if(mflag==1 && sflag==1 && hflag==1)
        printf("%s %d %s %d 0%d:0%d:0%d %s UTC\n",arr3[timeinfo->tm_wday],timeinfo->tm_mday,arr1[timeinfo->tm_mon],(timeinfo->tm_year+1900),tnet,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_hour>=12?"PM":"AM");
        else
        if(mflag==0 && sflag==1 && hflag==1)
        printf("%s %d %s %d 0%d:%d:0%d %s UTC\n",arr3[timeinfo->tm_wday],timeinfo->tm_mday,arr1[timeinfo->tm_mon],(timeinfo->tm_year+1900),tnet,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_hour>=12?"PM":"AM");
        else
        if(mflag==0 && sflag==0 && hflag==1)
        printf("%s %d %s %d 0%d:%d:%d %s UTC\n",arr3[timeinfo->tm_wday],timeinfo->tm_mday,arr1[timeinfo->tm_mon],(timeinfo->tm_year+1900),tnet,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_hour>=12?"PM":"AM");
        else
        if(mflag==1 && sflag==1 && hflag==0)
        printf("%s %d %s %d %d:0%d:0%d %s UTC\n",arr3[timeinfo->tm_wday],timeinfo->tm_mday,arr1[timeinfo->tm_mon],(timeinfo->tm_year+1900),tnet,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_hour>=12?"PM":"AM");
        else
        if(mflag==1 && sflag==0 && hflag==1)
        printf("%s %d %s %d 0%d:0%d:%d %s UTC\n",arr3[timeinfo->tm_wday],timeinfo->tm_mday,arr1[timeinfo->tm_mon],(timeinfo->tm_year+1900),tnet,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_hour>=12?"PM":"AM");
        else
        if(mflag==1 && sflag==0 && hflag==0)
        printf("%s %d %s %d %d:0%d:%d %s UTC\n",arr3[timeinfo->tm_wday],timeinfo->tm_mday,arr1[timeinfo->tm_mon],(timeinfo->tm_year+1900),tnet,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_hour>=12?"PM":"AM");
        else
        if(mflag==0 && sflag==1 && hflag==0)
        printf("%s %d %s %d %d:%d:0%d %s UTC\n",arr3[timeinfo->tm_wday],timeinfo->tm_mday,arr1[timeinfo->tm_mon],(timeinfo->tm_year+1900),tnet,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_hour>=12?"PM":"AM");
    }
    else
    if(strcmp(tok[0],"-R")==0 || strcmp(tok[0],"--rfc-email")==0)
    {
        time_t rawtime=time(NULL);
        struct tm * timeinfo;
        timeinfo = localtime(&rawtime);
        int mflag=0;int sflag=0;int hflag=0;
        if(timeinfo->tm_min<10)
        mflag=1;
        if(timeinfo->tm_min<10)
        mflag=1;
        if(timeinfo->tm_sec<10)
        sflag=1;
        if(timeinfo->tm_hour<10)
        hflag=1;
        if(mflag==0 && sflag==0 && hflag==0)
        printf("%s, %d %s %d %d:%d:%d +%ld\n",arr4[timeinfo->tm_wday],timeinfo->tm_mday,arr2[timeinfo->tm_mon],(timeinfo->tm_year+1900),timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_gmtoff);
        else
        if(mflag==1 && sflag==1 && hflag==1)
        printf("%s, %d %s %d 0%d:0%d:0%d +%ld\n",arr4[timeinfo->tm_wday],timeinfo->tm_mday,arr2[timeinfo->tm_mon],(timeinfo->tm_year+1900),timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_gmtoff);
        else
        if(mflag==0 && sflag==1 && hflag==1)
        printf("%s, %d %s %d 0%d:%d:0%d +%ld\n",arr4[timeinfo->tm_wday],timeinfo->tm_mday,arr2[timeinfo->tm_mon],(timeinfo->tm_year+1900),timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_gmtoff);
        else
        if(mflag==0 && sflag==0 && hflag==1)
        printf("%s, %d %s %d 0%d:%d:%d +%ld\n",arr4[timeinfo->tm_wday],timeinfo->tm_mday,arr2[timeinfo->tm_mon],(timeinfo->tm_year+1900),timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_gmtoff);
        else
        if(mflag==1 && sflag==1 && hflag==0)
        printf("%s, %d %s %d %d:0%d:0%d +%ld\n",arr4[timeinfo->tm_wday],timeinfo->tm_mday,arr2[timeinfo->tm_mon],(timeinfo->tm_year+1900),timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_gmtoff);
        else
        if(mflag==1 && sflag==0 && hflag==1)
        printf("%s, %d %s %d 0%d:0%d:%d +%ld\n",arr4[timeinfo->tm_wday],timeinfo->tm_mday,arr2[timeinfo->tm_mon],(timeinfo->tm_year+1900),timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_gmtoff);
        else
        if(mflag==1 && sflag==0 && hflag==0)
        printf("%s, %d %s %d %d:0%d:%d +%ld\n",arr4[timeinfo->tm_wday],timeinfo->tm_mday,arr2[timeinfo->tm_mon],(timeinfo->tm_year+1900),timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_gmtoff);
        else
        if(mflag==0 && sflag==1 && hflag==0)
        printf("%s, %d %s %d %d:%d:0%d +%ld\n",arr4[timeinfo->tm_wday],timeinfo->tm_mday,arr2[timeinfo->tm_mon],(timeinfo->tm_year+1900),timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_gmtoff);
    }
}
