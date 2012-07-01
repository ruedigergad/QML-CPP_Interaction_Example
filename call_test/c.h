/*
 * Copyright 2012, Ruediger Gad <r.c.g@gmx.de>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/
 * or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 *
 */

#ifndef C_H
#define C_H

#include <QDebug>
#include <QVariantList>
#include <QObject>
#include <a.h>

class C : public QObject
{
    Q_OBJECT
    Q_PROPERTY(A* a READ a WRITE setA NOTIFY aChanged)
public:
    explicit C(QObject *parent = 0) : QObject(parent){}

    A* a(){return myA;}

    void setA(A *a){
        myA = a;
        aChanged(myA);
    }

signals:
    void aChanged(A*);

private:
    A *myA;
};

#endif // C_H
