#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QThread>
#include <QQmlContext>
#ifdef ANDROID
#include <QtAndroidExtras/QAndroidJniObject>
#include <QAndroidJniEnvironment>
#include <jni.h>
#endif
#include "interface.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("Interface", Interface::getInstance());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QObject * stack = engine.rootObjects().first()->findChild<QObject*>("stack");
    QObject::connect(Interface::getInstance(),SIGNAL(backPress()), stack, SLOT(backHome()));

#ifdef ANDROID

    bool success = Interface::getInstance()->registerNativeMethods();
    if(success)
        Interface::getInstance()->printVLog("register success");
    else
        Interface::getInstance()->printVLog("register failed");
#if 0
    //返回String类型
    QAndroidJniObject str = QAndroidJniObject::callStaticObjectMethod("com/simon/ExtendsQtWithJava", "printVLog","(Ljava/lang/String;)Ljava/lang/String;", "log start!");
    QAndroidJniObject::callStaticObjectMethod("com/simon/ExtendsQtWithJava", "setPageIdx","(I)V;");
    QAndroidJniObject thread = QAndroidJniObject::callStaticObjectMethod("java/lang/Thread", "currentThread", "()Ljava/lang/Thread;");
    QAndroidJniObject threadId = thread.callObjectMethod("java/lang/Thread","getName","()Ljava/lang/String");

    qDebug() << "return:" << str.toString();
    qDebug() << "current thread:" << thread.toString();
    qDebug() << "current thread:" << threadId.toString();
    qDebug() << "main thread:" << QThread::currentThreadId();

    QList<QObject*> objlist = engine.rootObjects();
    for(auto it : objlist)
    {
        qDebug() << it->objectName() << "," << it->metaObject()->className();
        if(it->objectName() == "winapp")
        {
            QObject * obj = nullptr;
            obj = it->findChild<QObject*>("rect");
            obj->setProperty("radius", 25);
        }
    }
    QList<QObject*> objlist2 = engine.rootObjects().first()->children();

    for(auto it : objlist2)
    {
        qDebug() << it->objectName() << "," << it->metaObject()->className();
        if(it->objectName() == "rect")
        {
            //利用Jni接口返回的数据设置属性
            it->setProperty("color", str.toString());
        }
    }
#endif
#endif
    int ret = app.exec();
    return ret;
}
