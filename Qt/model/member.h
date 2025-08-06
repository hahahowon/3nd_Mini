#ifndef MEMBER_H
#define MEMBER_H

#include <QString>
#include <QJsonObject>

class Member {
public:
    Member(QString memberID, QString memberName, QString memberPW);
    ~Member();
    QString getMemberID();
    QString getMemberName();
    QString getMemberPW();
    bool isManager();
    void setManager(bool m_Flag);
    QJsonObject toJson() const;

private:
    QString m_memberName;
    QString m_memberID;
    QString m_memberPW;
    bool managerFlag;
};


#endif // MEMBER_H
