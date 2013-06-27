TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = util \
          encoding \
#         security 


encoding.depends = util
