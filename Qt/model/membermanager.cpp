// membermanager.cpp

#include "membermanager.h"
#include <QDebug>
#include <QObject>

MemberManager& MemberManager::getInstance() {
    static MemberManager instance;
    return instance;
}

MemberManager::MemberManager() {
    qDebug() << QObject::tr("MemberManager created.");
}

MemberManager::~MemberManager() {
    for (auto it = membersByID.begin(); it != membersByID.end(); ++it) {
        QString memberID = it.key();
        Member* member_ptr = it.value();
        qDebug() << QObject::tr("Deleting member: %1 %2").arg(member_ptr->getMemberName()).arg(memberID);
        delete member_ptr; // Member 객체의 메모리 해제
    }
    membersByID.clear(); // 맵 비우기
    qDebug() << QObject::tr("MemberManager destroyed.");
}

bool MemberManager::registerMember(Member* member, const QString& id) {
    if (membersByID.count(id)) {
        qDebug() << QObject::tr("Error: Already exist ID");
        return false;
    }
    membersByID[id] = member;
    qDebug() << QObject::tr("Member registered: %1 %2").arg(member->getMemberName()).arg(id);
    return true;
}

Member* MemberManager::findMemberByID(const QString& memberID) {
    auto it = membersByID.find(memberID);
    if (it != membersByID.end()) {
        return it.value();
    }
    return nullptr;
}

bool MemberManager::removeMember(const QString& memberID) {
    // 맵에서 ID로 회원 찾기
    auto it = membersByID.find(memberID);
    if (it == membersByID.end()) {
        qDebug() << QObject::tr("Error: Member with ID %1").arg(memberID) << " not found for removal.";
        return false; // 회원이 없으면 탈퇴 실패
    }

    // 찾은 Member 객체의 메모리 해제
    delete it.value();

    // 맵에서 해당 항목 제거
    membersByID.erase(it);
    qDebug() << QObject::tr("Member removed: %1").arg(memberID);
    return true; // 탈퇴 성공
}

const QMap<QString, Member*>& MemberManager::getMemberMap() const {
    return membersByID;
}

const QMap<QString, Member*>& MemberManager::getLoggedinMember() const {
    return loggedInMember;
}

QMap<QString, Member*>& MemberManager::setLoggedInMember(QMap<QString, Member*> loginMember) {
    loggedInMember = loginMember;
    return loggedInMember;
}
