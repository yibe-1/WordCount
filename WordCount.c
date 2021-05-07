#include "stdio.h"
#include "string.h"

int CharCount(char *tx)     //ͳ���ַ���
{
    int count=0;      //��������ʼֵΪ0
    for(int i=0;i<strlen(tx);i++)    //�����ַ����飬���ַ�Ϊ��ĸ���ո�ˮƽ�Ʊ�������з�ʱ������1
    { 
        if(tx[i]>='a' && tx[i]<='z' || tx[i]>='A' && tx[i]<='Z' || tx[i]==' ' || tx[i]=='\t' || tx[i]=='\n')
            count++;
    }
    return count;
}

int WordCount(char *tx)   //ͳ�Ƶ�����
{
    int count=0;
    int flag=0;      //��־λ��=0ʱ�ڿո�򶺺Ŵ���=1ʱ�ڵ��ʴ�
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
    char tx[4000];       //���ļ����ݴ��������
    FILE *fp;//�ļ�ָ��
    if((fp = fopen(*(argv+2), "r")) == NULL)  //�жϴ��ļ��Ƿ����
    {
        printf("���ļ�����");
        return -1;
    } 
    while(fscanf(fp, "%c", &tx[i]) != EOF)       //��ʽ����ȡ���ݵ����飬ֱ���ļ���β(����EOF)
    i++;
    fclose(fp);         //�ر��ļ�
    if(strcmp(*(argv+1),"-c")==0)
    {
        count=CharCount(tx);
        printf("�ַ�����%d ", count);
    }
    if(strcmp(*(argv+1),"-w")==0)
    {
        count=WordCount(tx);
        printf("��������%d ", count);
    }
return 0;
}
