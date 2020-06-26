# 遭遇したエラーおよびその対処

## 'QApplication' file not found

原因：Qt creator でコンソールアプリケーションに Widget を追加しようとしたときに発生する。

対処：QT -= gui をコメントアウトし、QT += widgets を追加する。

## Qt の更新

Qt Maintenance Tool から更新する。
Menu bar に登録されていないようなので C:\Qt から開く。

## Non-portable path to <Qdialog>

Qdialog の名前が正しくない。正しくは QDialog.
