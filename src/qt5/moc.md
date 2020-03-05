# Qt 5 MetaObjectの使い方

## 入力コード

```c++
#include <QApplication>
#include <QMetaObject>
#include <QPushButton>
#include <QDebug>
#include <QMetaMethod>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // QObjectを自作のものに変えればclass infoあたりの出力を得られるかも。
    QPushButton * button1 = new QPushButton();
    auto meta = button1->metaObject();

    // 参考URL
    // https://doc.qt.io/qt-5/metaobjects.html

    // meta objectから同種のclassを生成する
    auto newButton = meta->newInstance();

    // class情報の取得
    qDebug() << "QPushButtonのclass情報一覧";
    for(int i = 0; i < meta->classInfoCount(); ++i){
        qDebug() << "\t" <<meta->classInfo(i).name() << meta->classInfo(i).value();
    }

    // propertyの一覧取得
    // USER flagがonの一覧はuserPropertyを使う。
    qDebug() << "QPushButtonのproperty一覧";
    for(int i = 0; i < meta->propertyCount(); ++i){
        qDebug() << "\t" <<meta->property(i).name();
    }

    // class名の取得
    qDebug() << "class name: " << meta->className();

    // constructorのMetaMethodの取得
    qDebug() << "constructorのMetaMethodの情報一覧";
    for(int i = 0; i < meta->constructorCount(); ++i){
        qDebug() << "\t" <<meta->constructor(i).name();
    }

    // method一覧の取得
    int numMethod = meta->methodCount();
    qDebug() << "QPushButtonのmethod一覧";
    for(int i = 0; i < numMethod; ++i){
        qDebug() << "\t" <<meta->method(i).name();// << endl;
    }

    // 継承の有無の確認
    qDebug() << "QPushButtonは何かを継承している：" << meta->inherits(meta);

    // スーパークラス情報の取得
    auto super = meta->superClass();

    qDebug() << "super class name: " << super->className();

    return a.exec();
}
```

## 出力結果

```bash
QPushButtonのclass情報一覧
QPushButtonのproperty一覧
	 objectName
	 modal
	 windowModality
	 enabled
	 geometry
	 frameGeometry
	 normalGeometry
	 x
	 y
	 pos
	 frameSize
	 size
	 width
	 height
	 rect
	 childrenRect
	 childrenRegion
	 sizePolicy
	 minimumSize
	 maximumSize
	 minimumWidth
	 minimumHeight
	 maximumWidth
	 maximumHeight
	 sizeIncrement
	 baseSize
	 palette
	 font
	 cursor
	 mouseTracking
	 tabletTracking
	 isActiveWindow
	 focusPolicy
	 focus
	 contextMenuPolicy
	 updatesEnabled
	 visible
	 minimized
	 maximized
	 fullScreen
	 sizeHint
	 minimumSizeHint
	 acceptDrops
	 windowTitle
	 windowIcon
	 windowIconText
	 windowOpacity
	 windowModified
	 toolTip
	 toolTipDuration
	 statusTip
	 whatsThis
	 accessibleName
	 accessibleDescription
	 layoutDirection
	 autoFillBackground
	 styleSheet
	 locale
	 windowFilePath
	 inputMethodHints
	 text
	 icon
	 iconSize
	 shortcut
	 checkable
	 checked
	 autoRepeat
	 autoExclusive
	 autoRepeatDelay
	 autoRepeatInterval
	 down
	 autoDefault
	 default
	 flat
class name:  QPushButton
constructorのMetaMethodの情報一覧
QPushButtonのmethod一覧
	 "destroyed"
	 "destroyed"
	 "objectNameChanged"
	 "deleteLater"
	 "_q_reregisterTimers"
	 "windowTitleChanged"
	 "windowIconChanged"
	 "windowIconTextChanged"
	 "customContextMenuRequested"
	 "setEnabled"
	 "setDisabled"
	 "setWindowModified"
	 "setWindowTitle"
	 "setStyleSheet"
	 "setFocus"
	 "update"
	 "repaint"
	 "setVisible"
	 "setHidden"
	 "show"
	 "hide"
	 "showMinimized"
	 "showMaximized"
	 "showFullScreen"
	 "showNormal"
	 "close"
	 "raise"
	 "lower"
	 "updateMicroFocus"
	 "_q_showIfNotHidden"
	 "grab"
	 "grab"
	 "pressed"
	 "released"
	 "clicked"
	 "clicked"
	 "toggled"
	 "setIconSize"
	 "animateClick"
	 "animateClick"
	 "click"
	 "toggle"
	 "setChecked"
	 "showMenu"
	 "_q_popupPressed"
QPushButtonは何かを継承している： true
super class name:  QAbstractButton
```
