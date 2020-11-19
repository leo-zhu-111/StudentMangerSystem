#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include<QString>
class StudentInfo
{
public:
    StudentInfo();
    //有参构造函数
    StudentInfo(QString name,int id,int math,int english,int languagec);

    //私有成员变量对外接口
    int getId();
    int getMath();
    int getEnglish();
    int getLanguageC();
    double getAverage();
    //设置私有成员变量
    void setId(int id);
    void setName(QString name);
    void setMath(int math);
    void setEnglish(int english);
    void setLanguageC(int languageC);

    //计算平均成绩
    double calculateAverage();

private:
    //成员变量 姓名，id，各科成绩，平均成绩
    QString m_Name;
    int m_id,m_Math,m_English,m_LanguageC;
    double m_Average;
};

#endif // STUDENTINFO_H
