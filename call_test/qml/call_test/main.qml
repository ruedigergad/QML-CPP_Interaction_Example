/*
 * Copyright 2012, Ruediger Gad <r.c.g@gmx.de>
 *
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/
 * or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 *
 */

import QtQuick 1.0
import test 1.0

Rectangle {
    width: 360
    height: 360
    Text {
        id: textField
        text: qsTr("Click me.")
        anchors.centerIn: parent
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            textField.text = "Clicked..."

            // Passing objects from QML to C++
            b.doA(aa)
            b.doC(c)

            // Setting a property works as expected as well.
            aa.test = "foobar"
            b.doA(aa)
            b.doC(c)

            // Dynamic object creation in QML
            var newA = Qt.createQmlObject('import QtQuick 1.0; import test 1.0; A {test: "foo"}', parent)
            b.doA(newA)

            // Object creation in C++ and passing to QML
            var anotherA = b.makeA()
            console.log(anotherA.test)

            // Using the in C++ created object in QML
            c.a = anotherA
            b.doC(c)

            // Using QML lists
            console.log("")
            d.doVl()
            console.log("")
            b.doVl(d.vl)

            // It is also possible to pass dynamically created lists.
            console.log("")
            b.doVl(["j1", 2, 3, "j4"])

            // See the code of b.h to see how to access the objects in the list from C++.
            console.log("")
            b.doAlist([aa, aaa])

            // Create a list of objects in C++ and use it in QML.
            console.log("")
            d.vl = b.makeAList()
            console.log(d.vl[0].test)
            console.log(d.vl[1].test)

            // When properties are set via C++, notification via sinals works as well.
            // Note that for the sake of simplicity we trigger the change from the QML side.
            console.log("")
            aa.changeViaCpp("Called via QML but set in C++");

            Qt.quit()
        }
    }
    A{id: aa; test: "bar"
      onTestChanged: console.log("QML got notfied of change to test: " + test)}
    A{id: aaa; test: "blah"}
    B{id: b}
    C{id: c; a: aa}
    D{id: d;  vl: ["i1", "i2", 3, 4, aa]}
}
