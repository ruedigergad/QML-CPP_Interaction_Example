/*
 * Copyright 2012, Ruediger Gad <r.c.g@gmx.de>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/
 * or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 *
 */

#ifndef D_H
#define D_H

#include <QDebug>
#include <QObject>
#include <QVariantList>

class D : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList vl READ vl WRITE setVl NOTIFY vlChanged)

public:
    explicit D(QObject *parent = 0) : QObject(parent){}

    QVariantList vl(){return myVl;}

    void setVl(QVariantList vl){
        myVl = vl;
        vlChanged(myVl);
    }

    Q_INVOKABLE void doVl(){
        qDebug() << "Size of myVl: " << myVl.size();
        for(int i = 0; i < myVl.size(); i++){
            qDebug() << "myVl.at(" << i << "): " << myVl.at(i);
        }
    }

signals:
    void vlChanged(QVariantList);

private:
    QVariantList myVl;

};

#endif // D_H
