#ifndef PEER_H
#define PEER_H

#include <QObject>
#include <QHostAddress>
#include <QTime>
#include <QHash>
#include <QStringList>

class Peer : public QObject
{
    Q_OBJECT
public:
    explicit Peer(QObject *parent = 0);
    explicit Peer(QObject*,QString*, QHostAddress*, quint16);
    ~Peer();

    static QStringList getPeersNameList(const QList<Peer*> &peerList);

    //This does not get called by Set "contains"...for whatever reason.
    bool operator==(const Peer &peer);

   // friend bool operator==(Peer *p1, Peer *p2);

signals:
    void responseReceived();

private:
    QString * m_username;
    QHostAddress* m_address;
    quint16 m_udpPort;
    QTime time;

public:
    QString getName() const { return *m_username;}
    QTime getTime() { return time;}
    QHostAddress* getAddress() { return m_address;}
    void updateTime();

};


inline uint qHash(const Peer *peer) {
    uint hash = qHash(peer->getName());
    return hash;
}

inline  bool operator==(const Peer &peer, const Peer &peer2) {
    return peer.getName() == peer2.getName();
}


#endif // PEER_H