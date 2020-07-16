#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>

#ifdef ANDROID
#include <QtAndroidExtras/QAndroidJniObject>
#include <QAndroidJniEnvironment>
#endif

class Interface : public QObject
{
    Q_OBJECT
private:
    static Interface* instance;
    explicit Interface(QObject *parent = nullptr);

public:

    static Interface *getInstance();
    static jstring getQtVersion(JNIEnv* env, jobject thiz);
    static void backKeyPress(JNIEnv* env, jobject thiz);
    bool registerNativeMethods();
    void printVLog(QString log);

signals:
    void backPress();
public slots:
    void callJavaNativeChangeIndex(int idx);
    void qmlChangeIndex(int idx);
};

#endif // INTERFACE_H
