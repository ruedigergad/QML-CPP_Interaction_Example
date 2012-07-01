/*
 * Copyright 2012, Ruediger Gad <r.c.g@gmx.de>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/
 * or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 *
 */

#ifndef A_H
#define A_H

#include <QObject>

class A : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString test READ test WRITE setTest NOTIFY testChanged)
public:
    explicit A(QObject *parent = 0) : QObject(parent){}

    QString test(){return myTest;}

    void setTest(QString t){
        myTest = t;
        testChanged(myTest);
    }

signals:
    void testChanged(QString t);

private:
    QString myTest;
};

#endif // A_H
