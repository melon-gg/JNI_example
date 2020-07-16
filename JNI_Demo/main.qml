import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2

Window {
    title: "StackViewDemo";
    width: 480;
    height: 320;
    visible: true;
    id: app
    StackView {
        objectName: "stack"
        id: stack;
        anchors.fill: parent;

        function backHome() {
            console.log("qml receive back home signal")
            if(stack.depth > 0)
                stack.clear()
            Interface.qmlChangeIndex(0)
        }
        /*
        onBusyChanged: {
            console.log("busy - " + stack.busy);
        }
        */

        Text {
            text: "Click to create first page";
            font.pointSize: 14;
            font.bold: true;
            color: "blue";
            anchors.centerIn: parent;

            MouseArea {
                anchors.fill: parent;
                onClicked: {

                    if(stack.depth == 0)
                        stack.push(page1);
                    Interface.qmlChangeIndex(1)
                }
            }
        }
    }

    Button {
        objectName: "b1"
        visible: stack.depth > 0
        text: "back home"
        onClicked: {
            if(stack.depth > 0)
                stack.clear()
            Interface.qmlChangeIndex(0)
        }
    }

    Component {
        id: page1;
        Stack1  {
            objectName: "c1"
            MouseArea {
                anchors.fill: parent
                onClicked: {

                    if(stack.depth > 0)
                        stack.pop()
                    stack.push(page2)
                    Interface.qmlChangeIndex(2)
                }
            }
        }
    }
    Component {
        id: page2;
        Stack2  {
            objectName: "c2"
            MouseArea {
                anchors.fill: parent
                onClicked: {

                    if(stack.depth > 0)
                        stack.pop()
                    stack.push(page1)
                    Interface.qmlChangeIndex(1)
                }
            }
        }
    }
}
