import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Menu")
                onTriggered: {
                    mainMenu.focus = true;
                    mainMenu.opacity = 1;
                    mainfield.opacity = 0;
                    // Timer stop
                }
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }


        }
    }


    Rectangle{
        id: levelMenu
        anchors.fill: parent
        opacity: 0
        color: "#79b446";
        Repeater{
            model: bgn.levelCount();

            Button{
                width: {
                    if(levelMenu.width <= levelMenu.height)
                        levelMenu.width;
                    else
                        levelMenu.height;
                }
                height: {
                    if(levelMenu.width <= levelMenu.height)
                        levelMenu.width;
                    else
                        levelMenu.height;
                }
                text: index+1;

                onClicked: {
                    field.focus = true;
                    opacity = 0;
                    mainfield.opacity = 1;
                }
            }
        }
    }
    Rectangle{
        id: mainMenu
        anchors.fill: parent;
        color: "#79b446";
        focus: true;
        Column{
            anchors.fill: parent
            Button{
                id: startGame;

                width: parent.width/4*3
                height: mainMenu.height/8
                text: "Start Game"
                onClicked:{
                    levelMenu.focus = true;
                    levelMenu.opacity = 1;
                    mainMenu.opacity = 0;


                }

            }
            Button{
                id: exit;
                width: parent.width/4*3
                height: mainMenu.height/8

                text: "Exit"
                onClicked: Qt.quit();

            }
        }
    }

    Rectangle{
    id: mainfield
    anchors.fill: parent;
    opacity: 0
        Rectangle{
            id: field
            width: {
                if(parent.width < parent.height)
                    parent.width;
                else
                    parent.height;
            }
            height: width
            x:0
            y:0
            color: "#79b446"

            Repeater{
                id: rep;
                model: bgn.size()*bgn.size()
                Rectangle{
                    id: cell
                    x: bgn.getXCell(index, field.width);
                    y: bgn.getYCell(index, field.width);
                    width: field.width/bgn.size();
                    height: width
                    border.width: 1
                    color: {
                        if(bgn.getCell(index))
                             "#d5ab35";
                        else
                             "#79b446";
                    }
                    radius: {
                        if(bgn.getCell(index))
                             width/10;
                        else
                             0;
                    }

                }
            }


            Rectangle{
                id: player;
                x: bgn.playerX()*(field.width/bgn.size());
                y: bgn.playerY()*(field.width/bgn.size());
                width: field.width/bgn.size();
                height: field.width/bgn.size();
                radius: field.width/bgn.size();
                color: "darkRed";
                onWidthChanged: {
                    x = bgn.playerX()*(field.width/bgn.size());
                    y = bgn.playerY()*(field.width/bgn.size());
                }

            }
            Keys.onPressed: {
                if (event.key == Qt.Key_Left) {
                    bgn.stepLeft();
                    event.accepted = true;
                }
                if (event.key == Qt.Key_Right) {
                    bgn.stepRight();
                    event.accepted = true;
                }
                if (event.key == Qt.Key_Up) {
                    bgn.stepUp();
                    event.accepted = true;
                }
                if (event.key == Qt.Key_Down) {
                    bgn.stepDown();
                    event.accepted = true;
                }

                if(event.key == Qt.Key_Plus) {
                    bgn.duskUp();
                    event.accepted = true;
                }
                if(event.key == Qt.Key_Minus) {
                    bgn.duskDown();
                    event.accepted = true;
                }

                rep.model = 1;
                rep.model = bgn.size()*bgn.size();
                player.x = bgn.playerX()*(field.width/bgn.size());
                player.y = bgn.playerY()*(field.width/bgn.size());



            }
        }

        Rectangle{
            id: info;
            anchors.bottom: mainfield.bottom;
            anchors.right: mainfield.right;
            width: {
                if(parent.width < parent.height)
                    parent.width;
                else
                    parent.width-parent.height;
            }
            height:{
                if(parent.width < parent.height)
                    parent.height-parent.width;
                else
                    parent.width;
            }


            Repeater{
                model: 7;
                Rectangle{
                    id: container;
                    width:{
                        if(mainfield.width < mainfield.height)
                           info.width/7;
                        else
                            info.width;
                    }
                    height:{
                        if(mainfield.width < mainfield.height)
                            info.height;
                        else
                            info.height/7;
                    }

                    Text{
                        id: dusknum;
                        verticalAlignment: parent.verticalCenter;
                        horizontalAlignment: parent.horizontalCenter;

                        text: index+1;

                    }

                }

            }
        }
    }

}
