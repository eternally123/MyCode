#include <iostream>
#include <string>

#include <curl/curl.h>
#include <curl/easy.h>

#include <stdlib.h>
#include <string.h>
using namespace std;

struct MemoryStruct
{
    char *memory;
    size_t size;
    MemoryStruct()
    {
        memory = (char *)malloc(1);
        size = 0;
    }
    ~MemoryStruct()
    {
        free(memory);
        memory = NULL;
        size = 0;
    }
};

size_t WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, void *data)
{
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)data;

    mem->memory = (char *)realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory)
    {
        memcpy(&(mem->memory[mem->size]), ptr, realsize);
        mem->size += realsize;
        mem->memory[mem->size] = 0;
    }
    return realsize;
}

int main()
{
    CURLcode res = curl_global_init(CURL_GLOBAL_ALL);
    if (CURLE_OK != res)
    {
        cout << "curl init failed" << endl;
        return 1;
    }

    CURL *pCurl = NULL;
    pCurl = curl_easy_init();

    if (NULL == pCurl)
    {
        cout << "Init CURL failed..." << endl;
        return -1;
    }

    string url = "http://www.baidu.com"; //待请求的页面
    string filename = "dfshealth.html";  //正确响应后，请请求转写成本地文件的文件名即路径，此处表示当前目录下

    curl_easy_setopt(pCurl, CURLOPT_TIMEOUT, 3L);                        //请求超时时长
    curl_easy_setopt(pCurl, CURLOPT_CONNECTTIMEOUT, 10L);                //连接超时时长
    curl_easy_setopt(pCurl, CURLOPT_FOLLOWLOCATION, 1L);                 //允许重定向
    curl_easy_setopt(pCurl, CURLOPT_HEADER, 0L);                         //若启用，会将头文件的信息作为数据流输出
    curl_easy_setopt(pCurl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback); //得到请求结果后的回调函数

    MemoryStruct oDataChunk; //请求结果的保存格式
    curl_easy_setopt(pCurl, CURLOPT_WRITEDATA, &oDataChunk);

    curl_easy_setopt(pCurl, CURLOPT_NOSIGNAL, 1L);     //关闭中断信号响应
    curl_easy_setopt(pCurl, CURLOPT_VERBOSE, 1L);      //启用时会汇报所有的信息
    curl_easy_setopt(pCurl, CURLOPT_URL, url.c_str()); //需要获取的URL地址

    curl_slist *pList = NULL;
    pList = curl_slist_append(pList, "Accept-Encoding:gzip, deflate, sdch");
    pList = curl_slist_append(pList, "Accept-Language:zh-CN,zh;q=0.8");
    pList = curl_slist_append(pList, "Connection:keep-alive");
    curl_easy_setopt(pCurl, CURLOPT_HTTPHEADER, pList);

    res = curl_easy_perform(pCurl); //执行请求

    long res_code = 0;
    res = curl_easy_getinfo(pCurl, CURLINFO_RESPONSE_CODE, &res_code);

    //正确响应后，请请求转写成本地文件的文件
    if ((res == CURLE_OK) && (res_code == 200 || res_code == 201))
    {
        FILE *fTmpMem = (FILE *)oDataChunk.memory;
        if (!fTmpMem)
        {
        }

        FILE *fp = fopen(filename.c_str(), "wb");
        if (!fp)
        {
            cout << "open file failed";
            return -1;
        }

        fwrite(fTmpMem, 1, oDataChunk.size, fp);
        fclose(fp);
        return true;
    }
    curl_slist_free_all(pList);
    curl_easy_cleanup(pCurl);
    curl_global_cleanup();

    return 0;
}
