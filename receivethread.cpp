#include "receivethread.h"

ReceiveThread::ReceiveThread(QObject *parent) :
    QThread(parent)
{
}

ReceiveThread::~ReceiveThread() {
}



void ReceiveThread::run() {

    VoiceOutput output;
    output.start();

     //This puts the thread in an event loop, will continue until exit is calld.
    exec();

    output.stop();
    qDebug() << "Finished ouput";
}

void ReceiveThread::listen() {
    start();
}
