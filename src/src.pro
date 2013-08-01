TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = util \
        crypto \
        encoding \
        processing_pipes


crypto.depends = util
encoding.depends = util crypto
processing_pipes.depends = util crypto encoding
