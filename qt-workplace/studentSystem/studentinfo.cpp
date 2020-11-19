#include "studentinfo.h"

StudentInfo::StudentInfo()
{

}

StudentInfo::StudentInfo(QString name,int id,int math,int english,int languagec)
{
    this->m_Name = name;
    m_id =id;
    m_Math = math;
    m_English=english;
    m_LanguageC=languagec;
}

//私有成员变量对外接口
int StudentInfo::getId(){
    return m_id;
}

int StudentInfo::getMath()
{
    return m_Math;
}

int StudentInfo::getEnglish(){
    return m_English;
}

int StudentInfo::getLanguageC(){
    return m_LanguageC;
}

double StudentInfo::getAverage(){
    return m_Average;
}

//设置私有成员变量
void StudentInfo::setId(int id){
    m_id = id;
}

void StudentInfo::setName(QString name){
    m_Name = name;
}

void StudentInfo::setMath(int math){
    m_Math=math;
    calculateAverage();
}

void StudentInfo::setEnglish(int english){
    m_English=english;
    calculateAverage();
}

void StudentInfo::setLanguageC(int languageC){
    m_LanguageC=languageC;
    calculateAverage();
}

//计算平均成绩
double StudentInfo::calculateAverage(){
    m_Average = (m_Math + m_English+m_LanguageC) / 3.0;
}
