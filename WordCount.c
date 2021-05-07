#include "stdio.h"
#include "string.h"

int CharCount(char *tx)     //统计字符数
{
    int count=0;      //计数，初始值为0
    for(int i=0;i<strlen(tx);i++)    //遍历字符数组，当字符为字母、空格、水平制表符、换行符时计数加1
    { 
        if(tx[i]>='a' && tx[i]<='z' || tx[i]>='A' && tx[i]<='Z' || tx[i]==' ' || tx[i]=='\t' || tx[i]=='\n')
            count++;
    }
    return count;
}

int WordCount(char *tx)   //统计单词数
{
    int count=0;
    int flag=0;      //标志位，=0时在空格或逗号处，=1时在单词处
    for(int i=0;i<strlen(tx);i++)
    { 
        if(tx[i]==' ' || tx[i]==',')
            flag=0;
        else 
        {
            if(flag==0)
            {
                flag=1;
                count++;
            }
        }    
    }
    return count;
}

int main(int argc, char *argv[])  
{
    int count=0;
    int i;
    char tx[4000];       //将文件内容存入此数组
    FILE *fp;//文件指针
    if((fp = fopen(*(argv+2), "r")) == NULL)  //判断打开文件是否出错
    {
        printf("打开文件出错");
        return -1;
    } 
    while(fscanf(fp, "%c", &tx[i]) != EOF)       //格式化读取数据到数组，直到文件结尾(返回EOF)
    i++;
    fclose(fp);         //关闭文件
    if(strcmp(*(argv+1),"-c")==0)
    {
        count=CharCount(tx);
        printf("字符数：%d ", count);
    }
    if(strcmp(*(argv+1),"-w")==0)
    {
        count=WordCount(tx);
        printf("单词数：%d ", count);
    }
return 0;
}
