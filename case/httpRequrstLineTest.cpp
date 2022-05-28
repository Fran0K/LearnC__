//
// Created by Frank Lin on 21/1/22.
//
#include <string>
using namespace std;
void checkRequest(char *text){
    char *m_url = strpbrk(text, " \t");
    *m_url++ = '\0';

    char *method = text;
    int m_method = 0;
    if (strcasecmp(method, "GET") == 0)
        m_method = 0;
    else if (strcasecmp(method, "POST") == 0)
    {
        m_method = 1;
    }
    m_url += strspn(m_url, " \t");
    //使用与判断请求方式的相同逻辑，判断HTTP版本号
    char *m_version = strpbrk(m_url, " \t");
    *m_version++ = '\0';
    m_version += strspn(m_version, " \t");



}


int main(){
    char *s = "GET \t\\ \tHTTP\\1.1 \t";
    checkRequest(s);
    return 0;
}