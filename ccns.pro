TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS =  src/util \
           src/encoding
#          src\security

src/encoding.depends = src/util
