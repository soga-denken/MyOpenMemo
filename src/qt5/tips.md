# Qt の小技などの情報集積

- [Qt 定番小ワザ集](http://mf-atelier.sakura.ne.jp/mf-atelier/modules/tips/program/Qt/qt_tips.html)

## 基礎的なもの

- [qobject_cast](https://doc.qt.io/qt-5/qobject.html#qobject_cast)
  - [What is qobject_cast?](https://stackoverflow.com/questions/43994584/what-is-qobject-cast)

## イベント関連

- [イベントのお話](http://vivi.dyndns.org/vivi/docs/Qt/event.html)

## （個人的に）有用な例

- [Basic Drawing Example](https://doc.qt.io/qt-5/qtwidgets-painting-basicdrawing-example.html)
- [Draggable Icons Example](https://doc.qt.io/qt-5/qtwidgets-draganddrop-draggableicons-example.html)
- [Styles Example](https://doc.qt.io/qt-5/qtwidgets-widgets-styles-example.html)
- [Style Sheet Example](https://doc.qt.io/qt-5/qtwidgets-widgets-stylesheet-example.html)
- [Dock Widgets Example](https://doc.qt.io/qt-5/qtwidgets-mainwindows-dockwidgets-example.html)
- [Custom Sort/Filter Model Example](https://doc.qt.io/qt-5/qtwidgets-itemviews-customsortfiltermodel-example.html)
- [Tool Tips Example](https://doc.qt.io/qt-5/qtwidgets-widgets-tooltips-example.html)
- [Spin Box Delegate Example](https://doc.qt.io/qt-5/qtwidgets-itemviews-spinboxdelegate-example.html)

## レイアウト関連

- [Stretch Factor](https://doc.qt.io/qt-5/layout.html#stretch-factors): addStreach が複数あったとき、広がる大きさの比率を与える方法。
- デフォルトでは 0 らしい？

## ビルドフォルダをきれいにする

- [リンク](http://louis-needless.hatenablog.com/entry/gloomy-build-directory)

## スクロールバー（Area）の使い方

- [リンク](http://qt-log.open-memo.net/sub/scroll-area--usage-of-scrollarea.html)
- [リンク](http://qt-log.open-memo.net/sub/layout__custom_scroll_bar.html)

## JSON 関連

- [QJsonDocument と QJsonObject を使って、JSON 形式で読み書きする方法](https://qiita.com/tatsuteb/items/f7137a21b4daddfed18e)
- [JSON Support in Qt](https://doc.qt.io/qt-5/json.html)

## Undo/Redo

- [Qt の Undo Framework で、Undo/Redo を実装する方法](https://qiita.com/tatsuteb/items/ed862e6552988595cbe6)

## シグナルをブロックする方法

- [Qt でシグナルをブロックする方法](https://qiita.com/tatsuteb/items/abbb098be78cef178ffc)

## デフォルトの role name 一覧

- [default role names set by Qt](https://doc.qt.io/qt-5/qabstractitemmodel.html#roleNames)
- role name を追加する場合は roleNames を再実装する。

## AbstractItemModel 関連

- [QAbstractItemModel を実装してツリービューを作る(Read Only 編)](https://qiita.com/tetsurom/items/acef221a06a2421e33d8)

## コンテナ化

- [Qt ビルド環境のコンテナ化](https://qiita.com/tetsurom/items/a591b8f3d2dfe144178f)
- [Visual C++開発環境をコンテナ化する](https://qiita.com/tetsurom/items/d2aac2e56f024b3178fb)

## FontMetrics とタブの扱い

- [Qt で文字列の画面上の幅を求める際のタブの扱い](https://qiita.com/tetsurom/items/c331ffccb998e9c88938)

## オブジェクトのクラス名を表示するためのデバッグ支援

- [QWidget の階層構造を可視化するデバッグ支援ツール](https://qiita.com/tetsurom/items/b0a38735fdd9ef174ce5)

## tableWidget 関連

- [https://wiki.qt.io/How_to_Use_QTableWidget](https://wiki.qt.io/How_to_Use_QTableWidget)
- [テーブルウィジェット](http://mf-atelier.sakura.ne.jp/mf-atelier/modules/tips/program/Qt/qt_tips.html)

## QRegExp の使い方

- [Qt の正規表現の使い方まとめ](http://qwertyfk.blog16.fc2.com/blog-entry-84.html)

## Q_PROPERTY

- [Qt のプロパティシステム](https://qt-labs.jp/2013/04/qt-property.html)

## Qt WidgetAttribute の一覧

- [enum Qt::WidgetAttribute](https://doc.qt.io/qt-5/qt.html#WidgetAttribute-enum)

## QSizePolicy

- [ウィジェットのサイズ調整](http://qt-log.open-memo.net/sub/layout__how_to_use_size_policy.html)
- [QSizePolicy Class](https://doc.qt.io/qt-5/qsizepolicy.html)

## 描写関連

- [How to Bring the Widget Bring to front in Qt?](https://stackoverflow.com/questions/3821743/how-to-bring-the-widget-bring-to-front-in-qt)
- [Animating Pixmap](https://stackoverflow.com/questions/50550089/qt-animating-qpixmap)
- [QPolygonF Class](https://doc.qt.io/qt-5/qpolygonf.html)と drawPolyline で線が引ける。→ オブジェクトを線で繋げるときに有効。
- [Customizing qtreeview](https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qtreeview)
  - treeview でアイテム間で線を引きたい時に使える。
- QPainter で描写したものは次回 update()時に消える仕様。前回の描写を残したい場合は QPicture を使う。
- QPainter は widget に描写する場合は,paintevent 内または painterevent 内で呼ばれた関数からのみ描写可能。
- [scroll](https://doc.qt.io/qt-5/qwidget.html#scroll):描写を左右上下に移動させるときに効率的。
- [QPalette::ColorRole](https://doc-snapshots.qt.io/qt5-dev/qpalette.html#ColorRole-enum)
  - foreground(WindowText)は Window 上に表示される文字の一般的な色。
- 4K モニターなどの DPI スケーリングが有効になっている場合は`QApplication`の前に`QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);`を入れるとフォントサイズ等がおかしくならないて済む。
  - [High DPI Displays](https://doc.qt.io/qt-5/highdpi.html)
  - [improper scaling of Qt Desktop application in windows 10](https://stackoverflow.com/questions/35816944/improper-scaling-of-qt-desktop-application-in-windows-10)
  - モニターが DPI scaling を有効にしているか検知する方法はあるのか？
- [How can I crop an image in Qt?](https://stackoverflow.com/questions/7010611/how-can-i-crop-an-image-in-qt)

## イベントフィルター関連

- [Event Filters](https://doc.qt.io/qt-5/eventsandfilters.html#event-filters)
- [イベントを受け取る](http://qt-log.open-memo.net/sub/event__catch_event.html)
- [Qt に関する覚え書き［イベント全般］](http://dorafop.my.coocan.jp/Qt/Qt104.html)
- [Qt のイベント処理メモ](http://see-ku.com/wiki/wiki.cgi?page=Qt%A4%CE%A5%A4%A5%D9%A5%F3%A5%C8%BD%E8%CD%FD%A5%E1%A5%E2)
- [eventFilter を使ってみた](http://nonspam.blog.shinobi.jp/qt-windows%E3%83%A1%E3%83%A2/eventfilter%E3%82%92%E4%BD%BF%E3%81%A3%E3%81%A6%E3%81%BF%E3%81%9F)
- [Working With Qt Events : A Comprehensive Guide](https://www.learnqt.guide/events/working-with-events/)
- [Custom events in Qt](https://stackoverflow.com/questions/12656646/custom-events-in-qt)
- [Qt: Defining a custom event type](https://stackoverflow.com/questions/2248009/qt-defining-a-custom-event-type)
- [Qt で Ctrl+C などのショートカットを上書きする方法](https://qiita.com/zerorogue/items/e3694adcc7a35ecff271)

## プラグイン関係

- [how to create plugins (Qt 5.2.0)](https://stackoverflow.com/questions/22394477/how-to-create-plugins-qt-5-2-0)

## QStyle 関連

- [QStyle::ComplexControl](https://doc.qt.io/qt-5/qstyle.html#ComplexControl-enum)
- [QStyle::ContentsType](https://doc.qt.io/qt-5/qstyle.html#ContentsType-enum)
- [QStyle::ControlElement](https://doc.qt.io/qt-5/qstyle.html#ControlElement-enum)
- [QStyle::PrimitiveElement](https://doc.qt.io/qt-5/qstyle.html#PrimitiveElement-enum)
- [QStyle::StandardPixmap](https://doc.qt.io/qt-5/qstyle.html#StandardPixmap-enum)
- Qt でデフォルトで使える icon 一覧

## .pro 関連

- [What does CONFIG -= app_bundle do?](https://forum.qt.io/topic/100530/what-does-config-app_bundle-do)

## マウスカーソルの変更方法

- [cursor : QCursor](https://doc.qt.io/qt-5/qwidget.html#cursor-prop)
- [Qt::CursorShape](https://doc.qt.io/qt-5/qt.html#CursorShape-enum)

## 起動時の画面表示

- [QSplashScreen](https://doc.qt.io/qt-5/qsplashscreen.html)
- [How to show splash activity in fullscreen with transparent status bar](https://stackoverflow.com/questions/46002530/how-to-show-splash-activity-in-fullscreen-with-transparent-status-bar/46002944)
- [Full screen QSplashScreen on mobile](https://forum.qt.io/topic/8558/solved-full-screen-qsplashscreen-on-mobile/2)

## 起動時に dialog を表示

- [Show dialog before main window](https://stackoverflow.com/questions/16398639/show-dialog-before-main-window)
- [Qt Login Dialog Box before Main Window](https://stackoverflow.com/questions/24520430/qt-login-dialog-box-before-main-window)
- [show login dialog before mainwindow and hide mainwindow button](https://stackoverflow.com/questions/51646723/show-login-dialog-before-mainwindow-and-hide-mainwindow-button)
- [Adding a form that appears before the main window](https://forum.qt.io/topic/17563/adding-a-form-that-appears-before-the-main-window)
- [Showing a dialog at application startup](https://www.qtcentre.org/threads/12804-Showing-a-dialog-at-application-startup)

## QLabel のショートカット

- [setBuddy メンバー関数で指定](https://doc.qt.io/qt-5/qlabel.html#setBuddy)

## QLabel まわり

- [setFrameShape](https://doc.qt.io/qt-5/qframe.html#frameShape-prop): QFrame から継承。
  - [QFrame::Shape](https://doc.qt.io/qt-5/qframe.html#Shape-enum)：利用可能なフレーム一覧
- [setFrameShadow](https://doc.qt.io/qt-5/qframe.html#frameShadow-prop):フレームの影の指定
  - [QFrameShadow](https://doc.qt.io/qt-5/qframe.html#Shadow-enum):利用可能な影のイフェクト一覧
- [QLabel に画像を貼り付ける](http://louis-needless.hatenablog.com/entry/how-to-paste-image-to-qlabel)
- setPixmap で label に表示できる。

## QDialog 案連

- [QDialog を閉じるときの処理の流れメモ](http://see-ku.com/wiki/wiki.cgi?page=QDialog%A4%F2%CA%C4%A4%B8%A4%EB%A4%C8%A4%AD%A4%CE%BD%E8%CD%FD%A4%CE%CE%AE%A4%EC%A5%E1%A5%E2)
- [done(int r)](https://doc.qt.io/qt-5/qdialog.html#done)

## QDialogButtonBox 関連

- [Reordering OK and Cancel](https://doc.qt.io/archives/qq/qq19-buttons.html)
- [QButtonBox set default button](https://stackoverflow.com/questions/24556831/qbuttonbox-set-default-button)
- Escape はデフォルトのメンバー関数では定義できない？
- [向きの変更](https://doc.qt.io/qt-5/qdialogbuttonbox.html#orientation-prop)

## QMessageBox 関連

- [Default and Escape Keys](https://doc.qt.io/qt-5/qmessagebox.html#default-and-escape-keys)
- [QMessageBox::ButtonRole](https://doc.qt.io/qt-5/qmessagebox.html#ButtonRole-enum)
- [QMessageBox::StandardButton](https://doc.qt.io/qt-5/qmessagebox.html#ButtonRole-enum)

## QSplitter

- [childrenCollapsible](https://doc.qt.io/qt-5/qsplitter.html#childrenCollapsible-prop)
- 小さくした時に collapse(非表示)にするかどうかを決定
- [setCollapsible](https://doc.qt.io/qt-5/qsplitter.html#setCollapsible)
- 特定の widget のみ非表示/表示できるようにしたい場合
- [setSizes](https://doc.qt.io/qt-5/qsplitter.html#setSizes)
- 大きさを 0 にすることで collapse させることができる。
- 確認：大きさを変更したとき、全体の和が同じようにする必要がある？
- 順番を入れ替えたい場合、
- If a widget is already inside a QSplitter when insertWidget() or addWidget() is called, it will move to the new position. This can be used to reorder widgets in the splitter later. You can use indexOf(), widget(), and count() to get access to the widgets inside the splitter.

## DockWidget 関連

- [PySide で QDockWidget の不便なところを解消する](https://qiita.com/pashango2/items/7770a27e86d739186ed3)
- [QDockWidget のマージンの調節方法](http://qt-log.open-memo.net/sub/layout__set_dock_widget_margin.html)
- [How can I insert QDockWidget as tab](https://stackoverflow.com/questions/19465812/how-can-i-insert-qdockwidget-as-tab)
- [Qt padding & margins in dockable windows](https://stackoverflow.com/questions/40594721/qt-padding-margins-in-dockable-windows)
- 調べる：QDockWidget と layout の使い方

## QWorkspace/QArea

- [QMdiArea Class](https://doc.qt.io/qt-5/qmdiarea.html)
- [QMdiSubWindow](https://doc.qt.io/qt-5/qmdisubwindow.html): mdi 内部のウィンドウクラス。QWidget の代わりにこちらも呼べる。
- [QWorkspace][https://doc.qt.io/archives/qt-4.8/qworkspace.html]: deprecated

## テキスト関連

- [QTextCursor](https://doc.qt.io/qt-5/qtextcursor.html)
- [エディターで行・列にジャンプする方法](http://qt-log.open-memo.net/sub/text_edit__jump_to_row_column.html) -[ブロック単位でテキスト選択する方法](http://qt-log.open-memo.net/sub/text_edit__select_text_block.html)

## QWidget 関連

- [enum Qt::WidgetAttribute](https://doc.qt.io/qt-5/qt.html#WidgetAttribute-enum)
- [windowModified : bool](https://doc.qt.io/qt-5/qwidget.html#windowModified-prop)
- ファイルが変更された時に\*を表示するための機構。有効にするにはタイトルに[*]を追加すること。false の場合は[*]は自動で削除される。
- 親が変更された場合は子も変更されるが、子が true になっても親は true にならない。
- (focusNextChild())[https://doc.qt.io/qt-5/qwidget.html#focusNextChild]: tab と同じ挙動。
  - tab の順番を設定する場合は(setTabOrder)[https://doc.qt.io/qt-5/qwidget.html#setTabOrder]
- (processEvents)[https://doc.qt.io/qt-5/qcoreapplication.html#processEvents]: 重い処理中に GUI が止まらないようにする方法
  - 第一引数：(QEventLoop::ProcessEventsFlag)[https://doc.qt.io/qt-5/qeventloop.html#ProcessEventsFlag-enum]
- (setRenderHint)[https://doc.qt.io/qt-5/qpainter.html#setRenderHint]
  - (第一引数)[https://doc.qt.io/qt-5/qpainter.html#RenderHint-enum]
- setPen:ペンの指定((QPen)[https://doc.qt.io/qt-5/qpen.html])
  - [Pen Style](https://doc.qt.io/qt-5/qpen.html#pen-style)
  - [QBrush](https://doc.qt.io/qt-5/qbrush.html)
- 背景モード([Qt::BGMode](https://doc.qt.io/archives/qt-4.8/qt.html#BGMode-enum))
  - OpaqueMode を指定すれば、背景をバックグラウンドブラシで塗りつぶせる
- [setClipRegion](https://doc.qt.io/qt-5/qpainter.html#setClipRegion):クリップ領域（描写される領域）の指定。それ以外は描写されなくなる。
- [autoFillBackground](https://doc.qt.io/qt-5/qwidget.html#autoFillBackground-prop)
  - よく忘れるやつ。

## QAction

- [setShortcut](https://doc.qt.io/qt-5/qaction.html#shortcut-prop)
  - QAction を使ってショートカットキーを作成。この方法だとイベントの再実装が不要になる.
- [enum Qt::ShortcutContext](https://doc.qt.io/qt-5/qt.html#ShortcutContext-enum)
  - Qt::WidgetShortcut: 親 widget が active な時
  - Qt::WidgetWithChildrenShortcut: 親または子供のいずれかが active なとき。
  - Qt::ApplicationShortcut: アプリケーションウィンドウのいずれかが active なとき
  - Qt::WindowShortcut: ?

## QFontMetrics

- [size](https://doc.qt.io/qt-5/qfontmetrics.html#size)
  - 最初の引数は次のフラグの bitwise OR
    - Qt::TextSingleLine ignores newline characters.
    - Qt::TextExpandTabs expands tabs
    - Qt::TextShowMnemonic interprets "&x" as x; i.e., underlined.
    - Qt::TextWordWrap breaks the text to fit the rectangle.

## 座標系

- [Coordinate System](https://doc.qt.io/qt-5/coordsys.html)
- [Coordinate Transformations](https://doc.qt.io/qt-5/qpainter.html#coordinate-transformations)

## Qt 印刷関連

- [Printer and Printing APIs](https://doc.qt.io/qt-5/printing.html)
- [印刷ダイアログの表示](http://qt-log.open-memo.net/sub/dialog__print_document.html)
- [印刷プレビューの表示](http://qt-log.open-memo.net/sub/dialog--show-print-preview-dialog.html)
- [What's painter.setViewport exactly do?](https://stackoverflow.com/questions/19160030/whats-painter-setviewport-exactly-do)
- Widget を印刷する場合は[ウィジェット印刷](http://dorafop.my.coocan.jp/Qt/Qt108.html)が参考になる。
  Qprinter

## Drag/Drop 関連

- [QMimeData Class](https://doc.qt.io/qt-5/qmimedata.html#details)
- [QDrag Class](https://doc.qt.io/qt-5/qdrag.html#details)
- [Qt::DropAction](https://doc.qt.io/qt-5/qt.html#DropAction-enum)
- [カスタムドラッグタイプを使用する ①](http://memotiyou.blogspot.com/2012/02/qt-c_4767.html)
- [ドラッグ・ドロップイベントの受け取り](http://qt-log.open-memo.net/sub/event__use_drag_drop.html)

## Office 関連

- [Handling Microsoft Excel file format](https://wiki.qt.io/Handling_Microsoft_Excel_file_format)

## クリックボード関連

- [QClickboard](https://doc.qt.io/qt-5/qclipboard.html#details)
  [Selected Rows in QTableView, copy to QClipboard](https://stackoverflow.com/questions/1230222/selected-rows-in-qtableview-copy-to-qclipboard)
- [クリップボードを使用する](http://memotiyou.blogspot.com/2012/02/qt-c_9117.html)

## Model/View 関連

- [Model/View Tutorial](https://doc.qt.io/qt-5/modelview.html)
  - 途中に TableView の中に Tree を表示する方法が記載されている。
- [Qt の MVC 系アーキテクチャ モデル/ビューアーキテクチャ 初めの１歩](https://qiita.com/argama147/items/79db67c058560909ec1c)
- [QHeaderView::ResizeMode](https://doc.qt.io/qt-5/qheaderview.html#ResizeMode-enum)
- [invisibleRootItem](https://doc.qt.io/qt-5/qstandarditemmodel.html#invisibleRootItem)
- [showSortIndicator](https://doc.qt.io/qt-5/qheaderview.html#showSortIndicator-prop)
  - [Custom Sort/Filter Model Example](https://doc.qt.io/qt-5/qtwidgets-itemviews-customsortfiltermodel-example.html)
- [setAlternatingRowColors](https://doc.qt.io/qt-5/qabstractitemview.html#alternatingRowColors-prop)
  - [リストビューの背景色を交互に変更する](http://cococoron964.blog9.fc2.com/blog-entry-40.html)
- [setCellWidget](https://doc.qt.io/qt-5/qtablewidget.html#setCellWidget)
  - テーブルに widget を表示する場合に使う。
- [QTableWidget で複数行のテキスト入力](https://www.off-soft.net/ja/develop/qt/qtb2.html)
- [createEditor](https://doc.qt.io/qt-5/qabstractitemdelegate.html#createEditor)

  - 編集画面を変更する場合に用いる。

## comboBox 関連

- [itemData](https://doc.qt.io/qt-5/qcombobox.html#itemData)

## 国際化関連

- [How to automatically detect cut-off (too long) strings in localized Qt applications?](https://stackoverflow.com/questions/47133428/how-to-automatically-detect-cut-off-too-long-strings-in-localized-qt-applicati)
- [Unicode in Qt](https://doc.qt.io/qt-5/unicode.html)

## 保障型

- [型一覧(Qt)](https://doc.qt.io/qt-5/qtglobal.html#types)
- [C++](https://cpprefjp.github.io/reference/cstdint.html)

## Json 関連

- [JSON Support in Qt](https://doc.qt.io/qt-5/json.html)
- [Qt で JSON 形式の文字列をパース＆読み込み](http://kconcon3.hatenablog.com/entry/2017/12/06/133051)
- [Qt で JSON を使ったデータの保存！](https://qiita.com/PlanetMeron/items/73b1376eb29d418c21c8)
- [QJasonObject](https://doc.qt.io/qt-5/qjsonobject.html#details)
  - key 一覧は keys で取得。
- json の key は一意（同じ値があってはならない）
- [QJsonDocument と QJsonObject を使って、JSON 形式で読み書きする方法](https://qiita.com/tatsuteb/items/f7137a21b4daddfed18e)

## リソース関連

- [The Qt Resource System](https://doc.qt.io/qt-5/resources.html)
  - [External Binary Resources](https://doc.qt.io/qt-5/resources.html#external-binary-resources)
    - リソースファイルのバイナリ化
  - [Using Resources in a Library](https://doc.qt.io/qt-5/resources.html#using-resources-in-a-library)

## Markdown 関連

- [WebEngine Markdown Editor Example](https://doc.qt.io/qt-5/qtwebengine-webenginewidgets-markdowneditor-example.html)

## メニュ関連

- [Set position (to right) of Qt QPushButton popup menu](https://stackoverflow.com/questions/31668623/set-position-to-right-of-qt-qpushbutton-popup-menu)

## Qt Test 関連

- [Qt Test Tutorial](https://doc.qt.io/qt-5/qtest-tutorial.html)
  - QVERIFY(bool): bool が真であれば続行、偽であれば中止
  - QCOMPARE(A, B): A と B が同じか比較
  - QFETCH(type, name): ローカル変数を作成するマクロ。変数の中身はテストデータテーブルから読み込む。
    - 同じようなデータでテストを繰り返す場合に用いる。
  - QTest::addColumn<T>(): テストデータテーブルに新しい変数を入れる。
  - QTest::newRow(): 新しいデータセットを入れる。
  - QTest::keyClicks: widget が focus している状態でキーを押した状態をシミュレーションする機能
    - 他にも QTest::keyClick(), QTest::keyPress(), QTest::keyRelease(), QTest::mouseClick(), QTest::mouseDClick(), QTest::mouseMove(), QTest::mousePress() and QTest::mouseRelease()
- [Qt Test Overview](https://doc.qt.io/qt-5/qtest-overview.html)
