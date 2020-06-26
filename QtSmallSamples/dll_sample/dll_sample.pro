TEMPLATE = subdirs

SUBDIRS += \
    myDialog \
    simple

# プロジェクト間の従属関係を定義する
simple.depends = myDialog
