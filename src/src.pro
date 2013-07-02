TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = util \
        crypto \
        encoding


crypto.depends = util
encoding.depends = util crypto
